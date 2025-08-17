use std::collections::BTreeSet;
use std::fmt;
use std::io::Write;

use pdb::{FallibleIterator, ItemIndex};

use crate::addr2line::Formatter;
use crate::addr2line::Type;

use crate::gen_sources;
use crate::gen_sources::FunctionCache;
use crate::gen_sources::FunctionSignature;
use crate::gen_sources::PAD_LENGTH;
use crate::utils;
use crate::GenFlags;

pub fn dump_headers(
    pdb: &mut pdb::PDB<std::fs::File>,
    formatter: &Formatter,
    cache: FunctionCache,
    output_path: &std::path::Path,
    flags: GenFlags,
) -> crate::Result<()> {
    if flags.contains(GenFlags::TEST_RUN) {
        return Ok(());
    }

    let type_information = pdb.type_information()?;
    let type_finder = {
        let mut type_finder = type_information.finder();

        let mut type_iter = type_information.iter();
        while type_iter.next()?.is_some() {
            type_finder.update(&type_iter);
        }
        type_finder
    };

    let mut header_path = output_path.to_path_buf();
    header_path.push("headers");
    std::fs::create_dir_all(&header_path)?;

    for path in ["vostok", "survarium", "others"] {
        header_path.push(path);
        std::fs::create_dir_all(&header_path)?;
        header_path.pop();
    }

    let type_information = pdb.type_information()?;

    let mut type_iter = type_information.iter();
    while let Some(type_index) = type_iter.next()? {
        let Ok(pdb::TypeData::Class(class)) = type_index.parse() else {
            continue;
        };
        if class.properties.forward_reference() {
            continue;
        }
        let class_name = class.name.to_string().to_string();

        let Ok(header) = build_header(formatter, &cache, &type_finder, type_index.index()) else {
            continue;
        };

        const MAX_CLASS_LEN: usize = 180;

        let header_name = match class_name.len() > MAX_CLASS_LEN {
            false => class_name.clone(),
            true => {
                let mut class_name = class_name.clone();
                _ = class_name.split_off(MAX_CLASS_LEN);
                class_name
            }
        };

        let ifdef_name = {
            let mut depth = 0;

            let header_name = class_name.chars().filter(|c| match c {
                '<' => {
                    depth += 1;
                    false
                }
                '>' => {
                    depth -= 1;
                    false
                }
                _ => depth == 0,
            });

            "ignore/"
                .chars()
                .chain(header_name)
                .chain(".h".chars())
                .collect::<String>()
                .replace("survarium::", "")
                .replace("vostok::", "")
        };
        let ifdef_name = std::path::Path::new(&ifdef_name);

        let header_name_on_disk = header_name
            .replace(":", "∶")
            .replace("*", "٭")
            .replace("<", "＜")
            .replace(">", "＞");

        let mut header_path = header_path.clone();
        if class_name.starts_with("vostok") {
            header_path.push("vostok");
        } else if class_name.starts_with("survarium") {
            header_path.push("survarium");
        } else {
            header_path.push("others");
        }

        header_path.push(format!("{header_name_on_disk}.hpp"));

        let mut file = std::fs::File::create(&header_path)?;

        gen_sources::write_header(&mut file, ifdef_name)?;
        writeln!(&mut file, "/* {class_name} */")?;
        write!(&mut file, "{header}")?;
        gen_sources::write_footer(&mut file, ifdef_name)?;
    }

    Ok(())
}

fn build_header<'a>(
    formatter: &Formatter,
    cache: &FunctionCache,
    type_finder: &pdb::TypeFinder<'a>,
    class: pdb::TypeIndex,
) -> crate::Result<Data<'a>> {
    let mut needed_types = TypeSet::new();
    let mut data = Data::new();

    data.add(formatter, cache, type_finder, class, &mut needed_types)?;

    // add all the needed types iteratively until we're done
    while let Some(type_index) = needed_types.iter().next_back().copied() {
        // remove it
        needed_types.remove(&type_index);

        // add the type
        data.add(formatter, cache, type_finder, type_index, &mut needed_types)?;
    }

    Ok(data)
}

//
//
//

type TypeSet = BTreeSet<pdb::TypeIndex>;

#[derive(Debug, Clone, PartialEq, Eq)]
struct Data<'p> {
    forward_references: Vec<ForwardReference>,
    classes: Vec<Class<'p>>,
    enums: Vec<Enum<'p>>,
}

#[derive(Debug, Clone, PartialEq, Eq)]
struct Class<'p> {
    kind: pdb::ClassKind,
    orig_name: String,
    name: Type,
    base_classes: Vec<BaseClass>,
    fields: Vec<Field<'p>>,
    instance_methods: Vec<Method>,
    static_methods: Vec<Method>,
}

#[derive(Debug, Clone, PartialEq, Eq)]
struct BaseClass {
    type_name: Type,
    offset: u32,
}

#[derive(Debug, Clone, PartialEq, Eq)]
struct Field<'p> {
    type_name: Type,
    name: pdb::RawString<'p>,
    offset: u64,
}

#[derive(Debug, Clone, PartialEq, Eq)]
struct Method {
    kind: MethodKind,
    attributes: pdb::FieldAttributes,
}

#[derive(Debug, Clone, PartialEq, Eq)]
enum MethodKind {
    NoArgNames { signature: Type },
    FromSourceFile { signature: FunctionSignature },
}

#[derive(Debug, Clone, PartialEq, Eq)]
struct Enum<'p> {
    name: pdb::RawString<'p>,
    underlying_type_name: Type,
    values: Vec<EnumValue<'p>>,
}

#[derive(Debug, Clone, PartialEq, Eq)]
struct EnumValue<'p> {
    name: pdb::RawString<'p>,
    value: pdb::Variant,
}

#[derive(Debug, Clone, PartialEq, Eq)]
struct ForwardReference {
    kind: pdb::ClassKind,
    name: Type,
}

//
//
//

impl<'p> Data<'p> {
    fn new() -> Data<'p> {
        Data {
            forward_references: Vec::new(),
            classes: Vec::new(),
            enums: Vec::new(),
        }
    }

    fn add(
        &mut self,
        formatter: &Formatter,
        cache: &FunctionCache,
        type_finder: &pdb::TypeFinder<'p>,
        type_index: pdb::TypeIndex,
        needed_types: &mut TypeSet,
    ) -> crate::Result<()> {
        match type_finder.find(type_index)?.parse()? {
            pdb::TypeData::Class(data) => {
                if data.properties.forward_reference() {
                    self.forward_references.push(ForwardReference {
                        kind: data.kind,
                        name: Type::new(&data.name.to_string()),
                    });

                    return Ok(());
                }

                let mut class = Class {
                    kind: data.kind,
                    name: Type::new(&data.name.to_string()),
                    orig_name: data.name.to_string().to_string(),
                    fields: Vec::new(),
                    base_classes: Vec::new(),
                    instance_methods: Vec::new(),
                    static_methods: Vec::new(),
                };

                if let Some(fields) = data.fields {
                    class.add_fields(formatter, cache, type_finder, fields, needed_types)?;
                }

                self.classes.insert(0, class);
            }

            pdb::TypeData::Enumeration(data) => {
                let mut e = Enum {
                    name: data.name,
                    underlying_type_name: type_name(
                        formatter,
                        type_finder,
                        data.underlying_type,
                        needed_types,
                    )?,
                    values: Vec::new(),
                };

                e.add_fields(type_finder, data.fields, needed_types)?;

                self.enums.insert(0, e);
            }

            pdb::TypeData::Union(_) => (/* TODO */),

            // ignore
            other => eprintln!("warning: don't know how to add {other:?}"),
        }

        Ok(())
    }
}

impl<'p> Class<'p> {
    fn add_fields(
        &mut self,
        formatter: &Formatter,
        cache: &FunctionCache,
        type_finder: &pdb::TypeFinder<'p>,
        type_index: pdb::TypeIndex,
        needed_types: &mut TypeSet,
    ) -> crate::Result<()> {
        match type_finder.find(type_index)?.parse()? {
            pdb::TypeData::FieldList(data) => {
                for field in &data.fields {
                    self.add_field(formatter, cache, type_finder, field, needed_types)?;
                }

                if let Some(continuation) = data.continuation {
                    // recurse
                    self.add_fields(formatter, cache, type_finder, continuation, needed_types)?;
                }
            }
            other => {
                eprintln!("trying to Class::add_fields() got {type_index} -> {other:?}");
                panic!("unexpected type in Class::add_fields()");
            }
        }

        Ok(())
    }

    fn add_field(
        &mut self,
        formatter: &Formatter,
        cache: &FunctionCache,
        type_finder: &pdb::TypeFinder<'p>,
        field: &pdb::TypeData<'p>,
        needed_types: &mut TypeSet,
    ) -> crate::Result<()> {
        match *field {
            pdb::TypeData::Member(ref data) => {
                // TODO: attributes (static, virtual, etc.)
                self.fields.push(Field {
                    type_name: type_name(formatter, type_finder, data.field_type, needed_types)?,
                    name: data.name,
                    offset: data.offset,
                });
            }

            pdb::TypeData::Method(ref data) => {
                let method = Method::find(
                    &self.orig_name,
                    data.name,
                    data.attributes,
                    formatter,
                    cache,
                    type_finder,
                    data.method_type,
                )?;
                if data.attributes.is_static() {
                    self.static_methods.push(method);
                } else {
                    self.instance_methods.push(method);
                }
            }

            pdb::TypeData::OverloadedMethod(ref data) => {
                // this just means we have more than one method with the same name
                // find the method list
                match type_finder.find(data.method_list)?.parse()? {
                    pdb::TypeData::MethodList(method_list) => {
                        for pdb::MethodListEntry {
                            attributes,
                            method_type,
                            ..
                        } in method_list.methods
                        {
                            // hooray
                            let method = Method::find(
                                &self.orig_name,
                                data.name,
                                attributes,
                                formatter,
                                cache,
                                type_finder,
                                method_type,
                            )?;

                            if attributes.is_static() {
                                self.static_methods.push(method);
                            } else {
                                self.instance_methods.push(method);
                            }
                        }
                    }
                    other => {
                        eprintln!(
                            "processing OverloadedMethod, expected MethodList, got {} -> {other:?}",
                            data.method_list,
                        );
                        panic!("unexpected type in Class::add_field()");
                    }
                }
            }

            pdb::TypeData::BaseClass(ref data) => self.base_classes.push(BaseClass {
                type_name: type_name(formatter, type_finder, data.base_class, needed_types)?,
                offset: data.offset,
            }),

            pdb::TypeData::VirtualBaseClass(ref data) => self.base_classes.push(BaseClass {
                type_name: type_name(formatter, type_finder, data.base_class, needed_types)?,
                offset: data.base_pointer_offset,
            }),

            _ => {
                // ignore everything else even though that's sad
            }
        }

        Ok(())
    }
}

impl Method {
    fn find(
        class_name: &str,
        name: pdb::RawString,
        attributes: pdb::FieldAttributes,
        formatter: &Formatter,
        cache: &FunctionCache,
        type_finder: &pdb::TypeFinder,
        type_index: pdb::TypeIndex,
    ) -> crate::Result<Method> {
        match type_finder.find(type_index)?.parse()? {
            pdb::TypeData::MemberFunction(_) => {
                assert!(!type_index.is_cross_module());

                let kind = match cache.get_from_header(class_name, &name, formatter, type_index)? {
                    None => MethodKind::NoArgNames {
                        signature: formatter.emit_function_with_args(&name, 0, type_index)?,
                    },
                    Some(function_sig) => MethodKind::FromSourceFile {
                        signature: function_sig.clone(),
                    },
                };

                Ok(Self { kind, attributes })
            }

            other => {
                eprintln!("other: {other:?}");
                Err(pdb::Error::UnimplementedFeature("that").into())
            }
        }
    }
}

impl<'p> Enum<'p> {
    fn add_fields(
        &mut self,
        type_finder: &pdb::TypeFinder<'p>,
        type_index: pdb::TypeIndex,
        needed_types: &mut TypeSet,
    ) -> crate::Result<()> {
        match type_finder.find(type_index)?.parse()? {
            pdb::TypeData::FieldList(data) => {
                for field in &data.fields {
                    self.add_field(type_finder, field, needed_types);
                }

                if let Some(continuation) = data.continuation {
                    // recurse
                    self.add_fields(type_finder, continuation, needed_types)?;
                }
            }

            pdb::TypeData::Primitive(pdb::PrimitiveType {
                kind: pdb::PrimitiveKind::NoType,
                ..
            }) => (),

            other => {
                println!("trying to Enum::add_fields() got {type_index} -> {other:?}");
                panic!("unexpected type in Enum::add_fields()");
            }
        }

        Ok(())
    }

    fn add_field(&mut self, _: &pdb::TypeFinder<'p>, field: &pdb::TypeData<'p>, _: &mut TypeSet) {
        // ignore everything else even though that's sad
        if let pdb::TypeData::Enumerate(data) = &field {
            self.values.push(EnumValue {
                name: data.name,
                value: data.value,
            });
        }
    }
}

//
//
//

pub fn type_name(
    formatter: &Formatter,
    type_finder: &pdb::TypeFinder<'_>,
    type_index: pdb::TypeIndex,
    needed_types: &mut TypeSet,
) -> crate::Result<Type> {
    update_referenced_types(type_finder, type_index, needed_types)?;

    // Make sure that index is not cross module.
    // That means it can be easily resolved.
    assert!(!type_index.is_cross_module());
    formatter.emit_type(0, type_index)
}

pub fn update_referenced_types(
    type_finder: &pdb::TypeFinder<'_>,
    type_index: pdb::TypeIndex,
    needed_types: &mut TypeSet,
) -> crate::Result<()> {
    match type_finder.find(type_index)?.parse()? {
        pdb::TypeData::Class(_) => {
            needed_types.insert(type_index);
        }

        pdb::TypeData::Enumeration(_) => {
            needed_types.insert(type_index);
        }

        pdb::TypeData::Union(_) => {
            needed_types.insert(type_index);
        }

        pdb::TypeData::Pointer(data) => {
            update_referenced_types(type_finder, data.underlying_type, needed_types)?
        }

        pdb::TypeData::Modifier(data) => {
            update_referenced_types(type_finder, data.underlying_type, needed_types)?
        }

        pdb::TypeData::Array(data) => {
            update_referenced_types(type_finder, data.element_type, needed_types)?
        }

        _ => (),
    }

    Ok(())
}

//
// Display
//

impl fmt::Display for Data<'_> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        if !self.forward_references.is_empty() {
            writeln!(f)?;
            for e in &self.forward_references {
                e.fmt(f)?;
            }
        }

        for e in &self.enums {
            writeln!(f)?;
            e.fmt(f)?;
        }

        for class in &self.classes {
            writeln!(f)?;
            class.fmt(f)?;
        }

        Ok(())
    }
}

impl fmt::Display for Class<'_> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let kind = match self.kind {
            pdb::ClassKind::Class => "class",
            pdb::ClassKind::Struct => "struct",
            pdb::ClassKind::Interface => "interface", // when can this happen?
        };
        let name = &self.name;
        write!(f, "{kind} {name} ")?;

        if !self.base_classes.is_empty() {
            for (i, base) in self.base_classes.iter().enumerate() {
                let prefix = match i {
                    0 => ":",
                    _ => ",",
                };
                write!(f, "{} {}", prefix, base.type_name)?;
            }
        }

        writeln!(f, " {{")?;

        writeln!(f, "public:")?;

        if !self.instance_methods.is_empty() {
            for method in &self.instance_methods {
                writeln!(f, "{method}",)?;
            }
        }

        if !self.static_methods.is_empty() {
            writeln!(f)?;

            for method in &self.static_methods {
                writeln!(f, "{method}")?;
            }
        }

        writeln!(f)?;
        writeln!(f, "private:")?;

        for base in &self.base_classes {
            writeln!(
                f,
                "\t/* offset 0x{:04x} */ /* fields for {} */",
                base.offset, base.type_name
            )?;
        }

        for field in &self.fields {
            write!(
                f,
                "\t/* offset 0x{:04x} */ {} ",
                field.offset, field.type_name,
            )?;

            pad_spaces(f, field.type_name.len() + 1)?;
            writeln!(f, " {};", field.name.to_string())?;
        }

        writeln!(f, "}}; // {kind} {name}")?;

        Ok(())
    }
}

impl fmt::Display for Method {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let Self { kind, attributes } = self;
        let attributes = utils::MyFieldAttributes::extract(*attributes);

        let specifier = match () {
            () if attributes.is_static() => "static ",
            () if attributes.is_virtual() => "virtual ",
            () => "",
        };
        let overrid = match () {
            () if attributes.is_override() => " override",
            () => "",
        };
        let pure = match () {
            () if attributes.is_pure() => " = 0",
            () if attributes.sealed() => " final",
            () => "",
        };

        writeln!(f, "\t{specifier}{kind}{overrid}{pure};")
    }
}

impl fmt::Display for MethodKind {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::NoArgNames { signature } => write!(f, "{signature} /* no source */"),
            Self::FromSourceFile { signature } => write!(f, "{signature}"),
        }
    }
}

impl fmt::Display for FunctionSignature {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let Self { name, args } = self;
        write!(f, "{name}(")?;

        if !args.is_empty() {
            writeln!(f)?;

            let len = args.len();
            for (idx, (arg_name, arg_type)) in args.iter().enumerate() {
                let last = idx == len - 1;

                let arg_prefix_len = arg_type.len() + " ".len();

                write!(f, "\t\t{arg_type} ")?;
                pad_spaces(f, arg_prefix_len)?;
                write!(f, "{arg_name}{n}", n = if last { ")" } else { ",\n" })?;
            }
        } else {
            write!(f, " )")?;
        }

        Ok(())
    }
}

impl fmt::Display for Enum<'_> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        writeln!(
            f,
            "enum {} /* stored as {} */ {{",
            self.name.to_string(),
            self.underlying_type_name
        )?;

        for value in &self.values {
            writeln!(
                f,
                "\t{} = {},",
                value.name.to_string(),
                match value.value {
                    pdb::Variant::U8(v) => format!("0x{v:02x}"),
                    pdb::Variant::U16(v) => format!("0x{v:04x}"),
                    pdb::Variant::U32(v) => format!("0x{v:08x}"),
                    pdb::Variant::U64(v) => format!("0x{v:16x}"),
                    pdb::Variant::I8(v) => format!("{v}"),
                    pdb::Variant::I16(v) => format!("{v}"),
                    pdb::Variant::I32(v) => format!("{v}"),
                    pdb::Variant::I64(v) => format!("{v}"),
                }
            )?;
        }
        writeln!(f, "}}")?;

        Ok(())
    }
}

impl fmt::Display for ForwardReference {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        writeln!(
            f,
            "{} {};",
            match self.kind {
                pdb::ClassKind::Class => "class",
                pdb::ClassKind::Struct => "struct",
                pdb::ClassKind::Interface => "interface", // when can this happen?
            },
            self.name,
        )
    }
}

//
// Helpers
//

pub fn pad_spaces(w: &mut fmt::Formatter, prefix_len: usize) -> std::fmt::Result {
    let no = PAD_LENGTH.saturating_sub(prefix_len);
    for _ in 0..no {
        write!(w, " ")?;
    }
    Ok(())
}
