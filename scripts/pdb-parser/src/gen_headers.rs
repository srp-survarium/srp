use std::collections::BTreeSet;
use std::fmt;
use std::fs;
use std::io;
use std::io::Write;

use pdb::{FallibleIterator, ItemIndex};
use pdb_addr2line::type_parser;
use pdb_addr2line::type_parser::AttributeFlags;
use pdb_addr2line::type_parser::ReturnType;

use crate::addr2line::Formatter;
use crate::gen_sources;
use crate::gen_sources::FunctionCache;
use crate::gen_sources::FunctionSignature;
use crate::utils;
use crate::utils::Type;
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

        let Ok(header) = build_header(formatter, &cache, &type_finder, type_index.index()) else {
            continue;
        };

        let file = create_header_file(&class, header_path.clone(), flags)?;
        write_header_file(&class, header, file)?;
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

struct Data<'p> {
    forward_references: Vec<ForwardReference>,
    classes: Vec<Class<'p>>,
    enums: Vec<Enum<'p>>,
}

struct Class<'p> {
    kind: pdb::ClassKind,
    orig_name: String,
    name: Type,
    size: u64,
    base_classes: Vec<BaseClass>,
    fields: Vec<Field<'p>>,
    instance_methods: Vec<Method>,
    static_methods: Vec<Method>,
}

struct BaseClass {
    type_name: Type,
    offset: u32,
}

struct Field<'p> {
    type_name: Type,
    name: pdb::RawString<'p>,
    offset: u64,
}

enum Method {
    FromHeaderFile {
        fn_t: type_parser::Function,
    },
    FromSourceFile {
        fn_t: type_parser::Function,
        args: Vec<(String, Type)>,
    },
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
                    size: data.size,
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

            pdb::TypeData::Method(ref data) => self.add_method(
                formatter,
                cache,
                type_finder,
                data.name,
                data.attributes,
                data.method_type,
            )?,

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
                            self.add_method(
                                formatter,
                                cache,
                                type_finder,
                                data.name,
                                attributes,
                                method_type,
                            )?;
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

    fn add_method(
        &mut self,

        formatter: &Formatter,
        cache: &FunctionCache,
        type_finder: &pdb::TypeFinder<'p>,

        data_name: pdb::RawString,
        data_attributes: pdb::FieldAttributes,
        data_method_type: pdb::TypeIndex,
    ) -> crate::Result<()> {
        let method = Method::find(
            formatter,
            cache,
            type_finder,
            &self.orig_name,
            data_name,
            data_attributes,
            data_method_type,
        )?;

        let fn_t = method.fn_t();
        let copy_arg = |postfix: &str| {
            fn_t.arg_types[0].strip_suffix(postfix).unwrap_or_default() == &self.orig_name
        };

        match fn_t.name.as_str() {
            // Vector destructor generated by compiler
            "__vecDelDtor" => return Ok(()),

            // Copy assignment generated by compiler
            fn_name
                // Constructor doesn't have definition
                if matches!(method, Method::FromHeaderFile { .. })
                    // The constructor has a single argument only
                    && fn_t.arg_types.len() == 1
                    // Which is a reference to original type
                    && (copy_arg(" const&") || copy_arg("&"))
                    // Which is either constructor or assignment
                    && (fn_name == "operator="
                        || matches!(fn_t.return_type, ReturnType::Constructor)) =>
            {
                return Ok(());
            }

            _ => (),
        }

        if data_attributes.is_static() {
            self.static_methods.push(method);
        } else {
            self.instance_methods.push(method);
        }

        Ok(())
    }
}

impl Method {
    fn find(
        formatter: &Formatter,
        cache: &FunctionCache,
        type_finder: &pdb::TypeFinder,

        class_name: &str,
        name: pdb::RawString,
        attributes: pdb::FieldAttributes,
        type_index: pdb::TypeIndex,
    ) -> crate::Result<Method> {
        match type_finder.find(type_index)?.parse()? {
            pdb::TypeData::MemberFunction(_) => {
                assert!(!type_index.is_cross_module());

                let mut method = match cache
                    .get_from_header(class_name, &name, formatter, type_index)?
                {
                    None => Method::FromHeaderFile {
                        fn_t: formatter.parse_function(&name, 0, type_index)?,
                    },
                    Some(FunctionSignature { fn_t, args }) => Method::FromSourceFile { fn_t, args },
                };

                method.set_method_attributes(attributes);

                Ok(method)
            }

            other => {
                eprintln!("other: {other:?}");
                Err(pdb::Error::UnimplementedFeature("that").into())
            }
        }
    }

    fn set_method_attributes(&mut self, attrs: pdb::FieldAttributes) {
        match self {
            Self::FromHeaderFile { fn_t } => utils::set_method_attributes(fn_t, attrs, false),
            Self::FromSourceFile { fn_t, .. } => utils::set_method_attributes(fn_t, attrs, true),
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
            writeln!(f, "//////////////////////////")?;
            writeln!(f, "// FORWARD DECLARATIONS //")?;
            writeln!(f, "//////////////////////////")?;
            writeln!(f)?;

            for e in &self.forward_references {
                e.fmt(f)?;
            }
        }

        if self.classes.is_empty() {
            writeln!(f)?;
            writeln!(f, "//////////////////////////")?;
            writeln!(f, "//     DEFINITIONS      //")?;
            writeln!(f, "//////////////////////////")?;
        }

        for e in &self.enums {
            writeln!(f)?;
            e.fmt(f)?;
        }

        if !self.classes.is_empty() {
            writeln!(f)?;
            writeln!(f, "//////////////////////////")?;
            writeln!(f, "//     DEFINITIONS      //")?;
            writeln!(f, "//////////////////////////")?;
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
            pdb::ClassKind::Interface => "interface",
        };
        let name = &self.name;
        write!(f, "{kind} {name}")?;

        if !self.base_classes.is_empty() {
            for (i, base) in self.base_classes.iter().enumerate() {
                let prefix = match i {
                    0 => ":",
                    _ => ",",
                };
                write!(f, " public {} {}", prefix, base.type_name)?;
            }
        }

        writeln!(f, " {{")?;

        //
        // All methods are considered public
        //
        writeln!(f, "public:")?;

        let max_return_type_len = self.max_return_type_len();
        let max_method_name_len = self.max_method_name_len();

        if !self.instance_methods.is_empty() {
            let has_inline_methods = self.has_inline_methods();
            for method in &self.instance_methods {
                method.fmt(
                    f,
                    has_inline_methods,
                    max_return_type_len,
                    max_method_name_len,
                )?;
            }
        }

        if !self.static_methods.is_empty() {
            writeln!(f)?;

            for method in &self.static_methods {
                method.fmt(f, false, max_return_type_len, max_method_name_len)?;
            }
        }

        writeln!(f)?;

        //
        // All fields are considered public unless this is a struct
        //
        match self.kind {
            pdb::ClassKind::Class => writeln!(f, "private:")?,
            pdb::ClassKind::Interface => writeln!(f, "private:")?,
            pdb::ClassKind::Struct => writeln!(f, "public:")?,
        }

        for base in &self.base_classes {
            writeln!(f, "\t/* 0x{:04x} */\t/* {} */", base.offset, base.type_name)?;
        }

        let max_type_name_len = self
            .fields
            .iter()
            .map(|field| field.type_name.len())
            .max()
            .unwrap_or(0);

        for field in &self.fields {
            write!(f, "\t/* 0x{:04x} */\t{}", field.offset, field.type_name)?;
            utils::pad_spaces_t(f, field.type_name.len(), max_type_name_len)?;
            writeln!(f, "\t{};", field.name.to_string())?;
        }

        writeln!(f, "}}; // {kind} {name}")?;

        let size = self.size;
        writeln!(f)?;
        writeln!(f, "STATIC_SIZE_ASSERT({name}, 0x{size:X});")?;
        writeln!(f)?;

        Ok(())
    }
}

impl Class<'_> {
    fn has_inline_methods(&self) -> bool {
        self.instance_methods
            .iter()
            .any(|method| method.attrs().contains(AttributeFlags::IS_INLINE))
    }

    fn max_return_type_len(&self) -> usize {
        self.instance_methods
            .iter()
            .map(|method| match &method.fn_t().return_type {
                ReturnType::Constructor => 0,
                ReturnType::Destructor => 0,
                // @TODO: This is stupid!
                ReturnType::Type(type_) => Type::new(type_).len(),
            })
            .max()
            .unwrap_or_default()
    }

    fn max_method_name_len(&self) -> usize {
        self.instance_methods
            .iter()
            .map(|method| method.fn_t().name.len())
            .max()
            .unwrap_or_default()
    }
}

impl Method {
    fn fmt(
        &self,
        f: &mut fmt::Formatter<'_>,
        has_inline_methods: bool,
        max_return_type_len: usize,
        max_method_name_len: usize,
    ) -> fmt::Result {
        let attrs = self.attrs();

        let virtual_ = match attrs.contains(AttributeFlags::IS_VIRTUAL) {
            true => "virtual\t",
            false => "",
        };
        let (inline, body) = match attrs.contains(AttributeFlags::IS_INLINE) {
            true => ("inline\t", " { /* no source */ }"),
            false => ("", ";"),
        };
        let static_ = match attrs.contains(AttributeFlags::IS_STATIC) {
            true => "static\t",
            false => "",
        };

        let tab_prefix = match inline.is_empty()
            && virtual_.is_empty()
            && static_.is_empty()
            && has_inline_methods
        {
            true => "\t\t",
            false => "",
        };

        let override_ = match attrs.contains(AttributeFlags::IS_OVERRIDE) {
            true => " override",
            false => "",
        };
        let pure = match attrs.contains(AttributeFlags::IS_PURE) {
            true => " = 0",
            false => "",
        };
        let final_ = match attrs.contains(AttributeFlags::IS_FINAL) {
            true => " final",
            false => "",
        };

        let mut pad_args_len = 4; // \t
        if !(virtual_.is_empty()
            && inline.is_empty()
            && static_.is_empty()
            && tab_prefix.is_empty())
        {
            pad_args_len += 8; // \t\t
        }
        pad_args_len += utils::pad_times(0, max_return_type_len) * 4 + 4;
        // pad_args_len += utils::pad_times(0, max_method_name_len) * 4;

        write!(f, "\t{virtual_}{static_}{inline}{tab_prefix}")?;
        match self {
            Method::FromHeaderFile { fn_t } => {
                utils::write_fn_signature_unnamed_args(
                    fn_t,
                    Some(max_return_type_len),
                    Some(max_method_name_len),
                    Some(pad_args_len),
                    f,
                )?;
            }
            Method::FromSourceFile { fn_t, args } => {
                utils::write_fn_signature_with_args(
                    fn_t,
                    &args,
                    Some(max_return_type_len),
                    Some(max_method_name_len),
                    Some(pad_args_len),
                    f,
                )?;
            }
        }
        writeln!(f, "{override_}{pure}{final_}{body}\n")?;

        Ok(())
    }

    fn fn_t(&self) -> &type_parser::Function {
        match self {
            Method::FromHeaderFile { fn_t } => fn_t,
            Method::FromSourceFile { fn_t, .. } => fn_t,
        }
    }

    fn attrs(&self) -> AttributeFlags {
        self.fn_t().attrs
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

fn create_header_file(
    class: &pdb::ClassType,
    mut header_path: std::path::PathBuf,
    flags: GenFlags,
) -> crate::Result<std::fs::File> {
    const MAX_CLASS_LEN: usize = 140;

    let header_name = {
        let mut class_name = class.name.to_string().to_string();
        class_name.truncate(MAX_CLASS_LEN);
        class_name
    };

    let header_name = if let Some(class_name) = header_name.strip_prefix("vostok::") {
        header_path.push("vostok");
        class_name
    } else if let Some(class_name) = header_name.strip_prefix("survarium::") {
        header_path.push("survarium");
        class_name
    } else {
        header_path.push("others");
        &header_name
    };

    let header_name = match header_name.find("::") {
        None => header_name,
        Some(pos) => {
            let namespace = header_name.split_at(pos).0;

            match namespace.contains('<') {
                // That means the namespace is actually part of the name.
                // We don't want to split that.
                // ```
                //  network_core<survarium::udp_packet>
                //              ^         ^
                // ```
                true => header_name,
                false => {
                    let header_name = header_name.split_at(pos + "::".len()).1;

                    header_path.push(namespace);
                    header_name
                }
            }
        }
    };

    std::fs::create_dir_all(&header_path)?;

    let mut header_name = header_name
        .replace(":", "∶")
        .replace("*", "٭")
        .replace("<", "＜")
        .replace(">", "＞");
    let prefix_pos = header_name.len();

    if !flags.contains(GenFlags::NO_OVERWRITES) {
        header_path.push(format!("{header_name}.h"));
        let file = std::fs::File::create(&header_path)?;
        return Ok(file);
    }

    let mut i = 0;
    header_path.push("dummy"); // `set_file_name` cannot distinguish between file and folder names

    loop {
        if i != 0 {
            use std::fmt::Write;

            header_name.truncate(prefix_pos);
            write!(&mut header_name, "_{i}").unwrap();
        }

        header_path.set_file_name(&header_name);
        header_path.set_extension("h");

        match fs::OpenOptions::new()
            .write(true)
            .create_new(true)
            .open(&header_path)
        {
            Err(error) if error.kind() == io::ErrorKind::AlreadyExists => {
                i += 1;
            }
            Ok(file) => return Ok(file),
            Err(error) => return Err(error.into()),
        }
    }
}

fn write_header_file(
    class: &pdb::ClassType,
    header: Data,
    mut file: std::fs::File,
) -> crate::Result<()> {
    let class_name = class.name.to_string();
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
            .replace("::", "_")
    };
    let ifdef_name = std::path::Path::new(&ifdef_name);

    gen_sources::write_header(&mut file, ifdef_name)?;
    writeln!(&mut file, "/* {class_name} */")?;
    write!(&mut file, "{header}")?;
    gen_sources::write_footer(&mut file, ifdef_name)?;

    Ok(())
}
