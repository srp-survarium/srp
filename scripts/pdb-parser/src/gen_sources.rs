use std::collections::BTreeMap;
use std::collections::BTreeSet;
use std::collections::HashMap;
use std::collections::HashSet;
use std::sync::LazyLock;

use pdb::ConstantSymbol;
use pdb::DataSymbol;
use pdb::ItemIndex;
use pdb::RegisterRelativeSymbol;
use pdb::RegisterVariableSymbol;
use pdb::{BasePointerRelativeSymbol, BlockSymbol, FallibleIterator, SymbolData};
use pdb_addr2line::type_parser;

use crate::addr2line::Formatter;
use crate::utils;
use crate::utils::Type;
use crate::GenFlags;
use crate::TEST_MODULE;

const GAME_IB: u32 = 0x10000;

#[derive(Clone)]
struct Function<'a> {
    module_id: usize,
    type_index: pdb::TypeIndex,

    flags: GenFlags,

    fn_t: pdb_addr2line::type_parser::Function,
    name_orig: String,

    args: Vec<(pdb::RawString<'a>, Type)>,
    locals: Vec<(pdb::RawString<'a>, Type, usize)>,

    proc_start: u32,
    proc_end: u32,
    statements: Vec<Statement>,

    constants: Vec<(pdb::RawString<'a>, Type, pdb::Variant)>,
    statics: Vec<(pdb::RawString<'a>, Type, pdb::Rva)>,

    blocks: Vec<(pdb::Rva, i32)>,
    typedefs: Vec<(Type, Type)>,
    symbols: Vec<pdb::SymbolData<'a>>,
}

#[derive(Debug, Clone)]
pub struct FunctionSignature {
    pub fn_t: type_parser::Function,
    pub args: Vec<(String, Type)>,
}

#[derive(Default, Clone)]
pub struct Statement {
    rva: pdb::Rva,
    line_start: u32,
    depth: i32,
}

/// Iterating through modules gives me names of the arguments.
/// But the class name IS NOT removed from the function name,
/// resulting in signatures like so:
/// `void survarium::bullet_manager::tick()`.
///
/// While when iterating through classes, argument names are not provided.
/// But the class name IS removed from the function name,
/// resulting in signatures like so:
/// `void tick()`.
///
/// So to properly find arguments in the cache (to generate headers with them).
/// I convert the function name from sources files to:
/// `void bullet_manager::tick()` (by removing `survarium::`)
///
/// While on the header size the class name is appended:
/// `void bullet_manager::tick()`
///
/// This allows me to match on a cache signatures and provide arguments in the header.
pub struct FunctionCache {
    // Original Name -> FunctionSignature
    cache: HashMap<String, FunctionSignature>,
}

//
//
//

pub fn dump_sources(
    pdb: &mut pdb::PDB<std::fs::File>,
    formatter: &Formatter,
    output_path: &std::path::Path,
    engine_path: &str,
    flags: GenFlags,
) -> crate::Result<FunctionCache> {
    let address_map = pdb.address_map()?;
    let string_table = pdb.string_table()?;

    let mut output_path = output_path.to_path_buf();
    output_path.push("sources");

    let dbi = pdb.debug_information()?;
    let mut modules = dbi.modules()?;
    let mut module_id: usize = usize::MAX;

    let mut cache = FunctionCache::new();

    while let Some(module) = modules.next()? {
        module_id = module_id.wrapping_add(1);

        if flags.contains(GenFlags::TEST_RUN) && !module.module_name().ends_with(TEST_MODULE) {
            continue;
        }

        if module.module_name().contains("\\scaleform\\") {
            continue;
        }

        let Some(module_info) = pdb.module_info(&module)? else {
            continue;
        };

        let module = Module::build(
            &module_info,
            module_id,
            formatter,
            &address_map,
            &string_table,
            flags,
        )?;

        module.update_cache(&mut cache, flags);
        module.write(&output_path, engine_path, flags)?;
    }

    Ok(cache)
}

struct Module<'a> {
    files: BTreeMap<String, BTreeMap<u32, Function<'a>>>,
    // typedef void* ptr;
    //         ^     ^
    //         type  name
    typedefs: BTreeSet<(Type, Type)>,
    //                  type  name
}

impl<'a> Module<'a> {
    // Returns a mapping for a module: filename -> proc_start -> Function
    fn build(
        module_info: &'a pdb::ModuleInfo,
        module_id: usize,

        formatter: &Formatter,
        address_map: &pdb::AddressMap,
        string_table: &pdb::StringTable,

        flags: GenFlags,
    ) -> crate::Result<Self> {
        let program = module_info.line_program()?;
        let mut symbols = module_info.symbols()?;

        let mut files: BTreeMap<String, BTreeMap<u32, Function>> = BTreeMap::new();

        let mut typedefs: BTreeSet<(Type, Type)> = BTreeSet::new();

        let mut filename: String = String::new();
        let mut function: Function = Function::new(flags);
        let mut depth: i32 = 0;

        while let Some(symbol) = symbols.next()? {
            match symbol.parse()? {
                // FunctionStart
                SymbolData::Procedure(proc) => {
                    assert_eq!(
                        depth, 0,
                        "Function cannot be defined inside another function"
                    );
                    depth += 1;

                    let mut m_proc_start = None;
                    let mut m_proc_end = None;

                    let mut m_file_name = None;

                    let mut breakpoints = Vec::new();

                    //
                    //
                    //

                    let mut lines = program.lines_for_symbol(proc.offset);
                    while let Some(line_info) = lines.next()? {
                        if m_proc_start.is_none() {
                            m_proc_start = Some(line_info.line_start);
                        }
                        m_proc_end = Some(line_info.line_start);

                        let file_name = {
                            let file_info = program.get_file_info(line_info.file_index)?;
                            file_info.name.to_string_lossy(string_table)?
                        };
                        match &m_file_name {
                            None => m_file_name = Some(file_name),
                            Some(m_file_name) => assert_eq!(*m_file_name, file_name),
                        }

                        let rva = line_info.offset.to_rva(address_map).expect("invalid rva");
                        breakpoints.push(Statement {
                            rva,
                            line_start: line_info.line_start,
                            depth: 0,
                        });
                    }

                    //
                    //
                    //

                    let Some(proc_start) = m_proc_start else {
                        continue;
                    };

                    let Some(proc_end) = m_proc_end else {
                        continue;
                    };

                    let Some(file_name) = m_file_name else {
                        continue;
                    };

                    filename = file_name.to_string();

                    let name_orig =
                        formatter.emit_function_orig(&proc.name, module_id, proc.type_index)?;

                    let fn_t = formatter.parse_function(&proc.name, module_id, proc.type_index)?;

                    function = Function {
                        module_id,
                        type_index: proc.type_index,
                        //
                        name_orig,
                        fn_t,
                        //
                        proc_start,
                        proc_end,
                        statements: breakpoints,
                        //
                        ..function
                    };
                }

                // FunctionEnd
                SymbolData::ScopeEnd if depth == 1 => {
                    let mut take_filename = String::new();
                    std::mem::swap(&mut take_filename, &mut filename);

                    let mut take_function = Function::new(function.flags);
                    std::mem::swap(&mut take_function, &mut function);

                    let args_count =
                        formatter.args_count(take_function.module_id, take_function.type_index)?;

                    let locals = take_function
                        .args
                        .split_off(args_count.min(take_function.args.len()))
                        .into_iter()
                        .map(|(local_name, local_type)| (local_name, local_type, 0));
                    take_function.locals.extend(locals);

                    files
                        .entry(take_filename)
                        .or_default()
                        .insert(take_function.proc_start, take_function);

                    depth -= 1;
                }

                // Arguments & Locals
                SymbolData::BasePointerRelative(BasePointerRelativeSymbol {
                    offset,
                    type_index,
                    name,
                    slot: _,
                }) if depth >= 1 => {
                    let local_name = name;
                    let local_type = formatter.emit_type(module_id, type_index)?;

                    // @TODO: This is incorrect in present of arguments passed by registers, which
                    // we do have thanks to linker optimizations
                    if function.locals.is_empty() && local_name.as_bytes() == b"this" {
                    } else if offset > 0 {
                        function.args.push((local_name, local_type));
                    } else {
                        function
                            .locals
                            .push((local_name, local_type, depth as usize - 1));
                    }
                }

                SymbolData::RegisterRelative(RegisterRelativeSymbol {
                    offset: _,
                    type_index,
                    register: _,
                    name,
                    slot: _,
                })
                | SymbolData::RegisterVariable(RegisterVariableSymbol {
                    type_index,
                    register: _,
                    name,
                    slot: _,
                }) if depth >= 1 => {
                    let local_name = name;
                    let local_type = formatter.emit_type(module_id, type_index)?;

                    if function.locals.is_empty() && local_name.as_bytes() == b"this" {
                    } else {
                        function.args.push((local_name, local_type));
                    }
                }

                SymbolData::Constant(ConstantSymbol {
                    managed: _,
                    type_index,
                    value,
                    name,
                }) if depth >= 1 => {
                    let const_name = name;
                    let const_type = formatter.emit_type(module_id, type_index)?;
                    let const_value = value;

                    function
                        .constants
                        .push((const_name, const_type, const_value));
                }

                SymbolData::Data(DataSymbol {
                    global: _,
                    managed: _,
                    type_index,
                    offset,
                    name,
                }) if depth >= 1 => {
                    let static_name = name;
                    let static_type = formatter.emit_type(module_id, type_index)?;
                    function.statics.push((
                        static_name,
                        static_type,
                        offset.to_rva(address_map).unwrap_or(pdb::Rva(0)),
                    ));
                }

                // Skip
                SymbolData::FrameProcedure(_) => (),

                // Blocks inside functions
                SymbolData::Block(BlockSymbol {
                    parent: _,
                    end: _,
                    len: _,
                    offset,
                    name: _,
                }) if depth >= 1 => {
                    let rva = offset.to_rva(address_map).expect("invalid rva");
                    if let Some(st) = function.statements.iter_mut().find(|st| st.rva == rva) {
                        st.depth = depth;
                    } else {
                        function.blocks.push((rva, depth));
                    }

                    depth += 1;
                }

                // Blocks end
                //
                // TODO: Not only functions and blocks can create scopes.
                // As a crutch, this can do, though some functions will be generated incorrectly.
                SymbolData::ScopeEnd => {
                    depth = (depth - 1).max(0);
                }

                // SymbolData::DefRangeRegisterRelative())
                SymbolData::UserDefinedType(udts) => {
                    static PREDEFINED_TYPEDEFS: LazyLock<HashSet<&[u8]>> = LazyLock::new(|| {
                        [
                            // boost
                            "this_type",
                            "self_type",
                            "unspecified_bool_type",
                            "unqualified_type",
                            "allocator_type",
                            // vostok
                            // ???
                            "vtable_type",
                            "functor_type",
                            "policy_type",
                            "base_type",
                            "callback_type",
                            "create_resource_if_no_file_delegate_type",
                            "first_type",
                            "graph_wrapper_type",
                            "implementation_type",
                            "invoker_type",
                            "is_POD_type",
                            "key_type",
                            "mapped_type",
                            "pod_type",
                            "point_ptr_type",
                            "point_type",
                            "pointer_type",
                            "result_type",
                            "reverse_iterator",
                            "service_impl_type",
                            "size_type",
                            "storage_type",
                            "subscribers_type",
                            "void_type",
                            "void_cv_type",
                            //
                            "value_type",
                            "object_type",
                        ]
                        .into_iter()
                        .map(|t| t.as_bytes())
                        .collect()
                    });

                    let name = udts.name.as_bytes();
                    let c = name[0];

                    if depth != 0 {
                        let udts_name = Type::new(&udts.name.to_string());
                        let udts_type = formatter.emit_type(module_id, udts.type_index)?;
                        function.typedefs.push((udts_type, udts_name));
                    } else {
                        // Most of the typedefs are completely useless, since they come from templates
                        // of different libraries and constantly repeat each other.
                        if !PREDEFINED_TYPEDEFS.contains(name)
                            && c != b'_'
                            && c.is_ascii_lowercase()
                            && name.ends_with(b"_type")
                        {
                            let udts_name = Type::new(&udts.name.to_string());
                            let udts_type = formatter.emit_type(module_id, udts.type_index)?;

                            typedefs.insert((udts_type, udts_name));
                        }
                    }
                }

                // Keep everything that we missed but is inside functions
                symbol if depth != 0 => {
                    function.symbols.push(symbol);
                }

                // Ignore everything outside function scope
                _symbol => (),
            }
        }

        Ok(Module { files, typedefs })
    }

    fn update_cache(&self, cache: &mut FunctionCache, flags: GenFlags) {
        if !flags.contains(GenFlags::NO_CACHE) {
            for funs in self.files.values() {
                for fun in funs.values() {
                    cache.insert_from_source(fun);
                }
            }
        }
    }
}

impl<'a> Function<'a> {
    pub fn new(flags: GenFlags) -> Self {
        Self {
            flags,

            module_id: Default::default(),
            type_index: Default::default(),

            name_orig: Default::default(),
            fn_t: type_parser::Function {
                return_type: type_parser::ReturnType::Constructor,
                name: Default::default(),
                arg_types: Default::default(),
                attrs: type_parser::AttributeFlags::empty(),
            },

            args: Default::default(),
            locals: Default::default(),

            proc_start: Default::default(),
            proc_end: Default::default(),
            statements: Default::default(),

            constants: Default::default(),
            statics: Default::default(),

            blocks: Default::default(),
            typedefs: Default::default(),
            symbols: Default::default(),
        }
    }
}

impl FunctionCache {
    pub fn new() -> Self {
        Self {
            cache: Default::default(),
        }
    }

    fn insert_from_source(&mut self, fun: &Function) {
        let Function {
            name_orig,
            fn_t,
            args,
            ..
        } = fun.clone();

        let cache_method_name = name_orig
            // .replace("survarium::", "")
            ;

        let args = args
            .into_iter()
            .map(|(t, n)| (t.to_string().to_string(), n))
            .collect::<Vec<_>>();

        self.cache
            .insert(cache_method_name, FunctionSignature { fn_t, args });
    }

    pub fn get_from_header(
        &self,
        class_name: &str,
        name: &pdb::RawString,
        formatter: &Formatter,
        type_index: pdb::TypeIndex,
    ) -> crate::Result<Option<FunctionSignature>> {
        assert!(!type_index.is_cross_module());

        let cache_method_name = {
            let name = format!("{class_name}::{}", name.to_string());
            let name = pdb::RawString::from(name.as_bytes());

            formatter.emit_function_orig(&name, 0, type_index)?
            // .replace("survarium::", "")
        };

        let mut signature = self.cache.get(&cache_method_name).cloned();
        if let Some(signature) = &mut signature {
            signature.fn_t.name = signature
                .fn_t
                .name
                .strip_prefix(class_name)
                .unwrap()
                .strip_prefix("::")
                .unwrap()
                .to_string();
        }

        Ok(signature)
    }
}

//
// Writing to disk
//

impl<'a> Module<'a> {
    fn write(
        self,
        output_path: &std::path::Path,
        engine_path: &str,
        flags: GenFlags,
    ) -> crate::Result<()> {
        for (file, funs) in self.files {
            let Some(path_to_file) = file.strip_prefix(engine_path) else {
                continue;
            };

            let mut source_path = output_path.to_path_buf();
            source_path.push(path_to_file);

            let mut file: Box<dyn std::io::Write> = match flags.contains(GenFlags::TEST_RUN) {
                false => {
                    std::fs::create_dir_all(source_path.parent().unwrap())?;

                    let file = std::fs::File::create(&source_path)?;
                    let file = std::io::BufWriter::new(file);

                    Box::new(file)
                }
                true => {
                    println!("\nFile: {source_path:?}\n");
                    Box::new(std::io::stdout())
                }
            };

            write_header(&mut file, &source_path)?;

            for function in funs.into_values() {
                function.write(&mut file)?;
            }

            if !self.typedefs.is_empty() {
                writeln!(file, "\t// TYPEDEFS")?;
                for (ty, name) in &self.typedefs {
                    writeln!(file, "\ttypedef")?;
                    writeln!(file, "\t\t{ty}")?;
                    writeln!(file, "\t\t{name};")?;
                    writeln!(file)?;
                }
                writeln!(file, "\t// ******\n")?;
            }

            write_footer(&mut file, &source_path)?;
        }

        Ok(())
    }
}

impl<'a> Function<'a> {
    pub fn write(self, mut w: impl std::io::Write) -> std::io::Result<()> {
        let Self {
            module_id: _,
            type_index: _,
            //
            flags,
            //
            fn_t,
            name_orig,
            //
            args,
            locals,
            //
            proc_start,
            proc_end,
            statements,
            //
            constants,
            statics,
            //
            blocks,
            typedefs,
            symbols,
        } = self;

        let args = args
            .into_iter()
            .map(|(name, type_)| (name.to_string().to_string(), type_))
            .collect::<Vec<_>>();
        match flags.contains(GenFlags::AS_BASE) {
            true => writeln!(w, "// STUB GENERATED FOR BASE CODE")?,
            false => writeln!(w, "// STATE[STUB]")?,
        }
        writeln!(w, "// {name_orig}")?;
        utils::write_fmt(&mut w, |w| {
            utils::write_fn_signature_with_args(&fn_t, &args, None, None, None, w)
        })?;

        writeln!(w, "\n{{")?;

        if !locals.is_empty() {
            writeln!(w, "\t// LOCALS")?;
            for (local_name, local_type, local_scope) in locals {
                let local_prefix_len = "// ".len() + local_type.len() + " ".len();

                write!(w, "\t// {local_type} ")?;
                utils::write_fmt(&mut w, |w| utils::pad_spaces(w, local_prefix_len))?;
                write!(w, "{local_name}")?;

                if local_scope != 0 {
                    write!(w, "<{local_scope}>")?;
                }
                writeln!(w)?;
            }
            writeln!(w, "\t// ******\n")?;
        }

        if !constants.is_empty() {
            writeln!(w, "\t// CONSTANTS")?;
            for (const_name, const_type, const_value) in constants {
                let const_prefix_len = "// const ".len() + const_type.len() + " ".len();

                write!(w, "\t// const {const_type} ")?;
                utils::write_fmt(&mut w, |w| utils::pad_spaces(w, const_prefix_len))?;
                writeln!(w, "{const_name} = {const_value};")?;
            }
            writeln!(w, "\t// ******\n")?;
        }

        if !statics.is_empty() {
            writeln!(w, "\t// STATICS")?;
            for (static_name, static_type, static_rva) in statics {
                let static_prefix_len = "// static ".len() + static_type.len() + " ".len();

                write!(w, "\t// static {static_type} ")?;
                utils::write_fmt(&mut w, |w| utils::pad_spaces(w, static_prefix_len))?;
                writeln!(
                    w,
                    "{static_name} = <{offset}>;",
                    offset = static_rva.saturating_add(GAME_IB),
                )?;
            }
            writeln!(w, "\t// ******\n")?;
        }

        if !blocks.is_empty() {
            writeln!(w, "\t// SKIPPED BLOCKS")?;
            for rva in blocks {
                writeln!(
                    w,
                    "\t// <{offset}><{depth}>",
                    offset = rva.0.saturating_add(GAME_IB),
                    depth = rva.1,
                )?;
            }
            writeln!(w, "\t// ******\n")?;
        }

        if !typedefs.is_empty() {
            writeln!(w, "\t// TYPEDEFS")?;
            for (ty, name) in typedefs {
                writeln!(w, "\t// typedef")?;
                writeln!(w, "\t// \t{ty}")?;
                writeln!(w, "\t// \t{name};")?;
                writeln!(w)?;
            }
            writeln!(w, "\t// ******\n")?;
        }

        if !symbols.is_empty() {
            writeln!(w, "\t// OTHER SYMBOLS")?;
            for symbol in symbols {
                writeln!(w, "\t// {symbol:?}")?;
            }
            writeln!(w, "\t// ******\n")?;
        }

        if let type_parser::ReturnType::Type(type_) = &fn_t.return_type {
            #[rustfmt::skip]
            match type_.as_str() {
                _ if type_.ends_with('*')    => writeln!(w, "\treturn NULL;")?,
                "pcstr"                      => writeln!(w, "\treturn NULL;")?,

                "vostok::math::aabb"         => writeln!(w, "\treturn vostok::math::aabb();")?,
                "vostok::math::color"        => writeln!(w, "\treturn vostok::math::color();")?,
                "vostok::math::frustum"      => writeln!(w, "\treturn vostok::math::frustum();")?,
                "vostok::math::intersection" => writeln!(w, "\treturn vostok::math::intersection();")?,
                "vostok::math::plane"        => writeln!(w, "\treturn vostok::math::plane()")?,
                "vostok::math::quaternion"   => writeln!(w, "\treturn vostok::math::quaternion()")?,

                "vostok::math::uint2"        => writeln!(w, "\treturn vostok::math::uint2(1, 1);")?,

                "vostok::math::float2"       => writeln!(w, "\treturn vostok::math::float2(1., 1.);")?,
                "vostok::math::float3"       => writeln!(w, "\treturn vostok::math::float3(1., 1., 1.);")?,
                "vostok::math::float4"       => writeln!(w, "\treturn vostok::math::float4(1., 1., 1., 1.);")?,

                "vostok::math::float3_pod"   => writeln!(w, "\treturn vostok::math::float3_pod();")?,
                "vostok::math::float4_pod"   => writeln!(w, "\treturn vostok::math::float4_pod();")?,
                "vostok::math::float4x4"     => writeln!(w, "\treturn vostok::math::float4x4();")?,

                // sad
                "aabb"         => writeln!(w, "\treturn aabb();")?,
                "color"        => writeln!(w, "\treturn color();")?,
                "frustum"      => writeln!(w, "\treturn frustum();")?,
                "intersection" => writeln!(w, "\treturn intersection();")?,
                "plane"        => writeln!(w, "\treturn plane()")?,
                "quaternion"   => writeln!(w, "\treturn quaternion()")?,

                "uint2"        => writeln!(w, "\treturn uint2(1, 1);")?,

                "float2"       => writeln!(w, "\treturn float2(1., 1.);")?,
                "float3"       => writeln!(w, "\treturn float3(1., 1., 1.);")?,
                "float4"       => writeln!(w, "\treturn float4(1., 1., 1., 1.);")?,

                "float3_pod"   => writeln!(w, "\treturn float3_pod();")?,
                "float4_pod"   => writeln!(w, "\treturn float4_pod();")?,
                "float4x4"     => writeln!(w, "\treturn float4x4();")?,
                // sad


                "u8" | "u16" | "u32" => writeln!(w, "\treturn 0;")?,
                "s8" | "s16" | "s32" => writeln!(w, "\treturn 0;")?,
                "float" | "double"   => writeln!(w, "\treturn 0.0f;")?,
                "bool"               => writeln!(w, "\treturn false;")?,
                "char"               => writeln!(w, "\treturn 'a';")?,

                "void" => (),
                _      => (),
            };
        }

        if proc_start + 1 < proc_end {
            writeln!(w, "\t// FUNCTION BODY")?;

            let n = |num: i32| match num >= 0 {
                true => format!("0x{num:03x}"),
                false => format!("-0x{num:03x}", num = num.abs()),
            };

            let mut first_statement_rva = None;
            let mut prev_statement_rva = None;
            let mut empty_line_no = 0;

            for i in proc_start + 1..proc_end {
                match statements.iter().find(|bp| bp.line_start == i) {
                    Some(Statement {
                        rva,
                        line_start,
                        depth,
                    }) => {
                        empty_line_no = 0;

                        let prev_statement_rva = match prev_statement_rva {
                            None => {
                                first_statement_rva = Some(rva);
                                prev_statement_rva = Some(rva);
                                rva
                            }
                            Some(prev_rva) => {
                                prev_statement_rva = Some(rva);
                                prev_rva
                            }
                        };
                        let first_statement_rva = first_statement_rva.unwrap();

                        let offset = rva.saturating_add(GAME_IB);

                        let diff_start = n(rva.0 as i32 - first_statement_rva.0 as i32);
                        let diff_prev = n(rva.0 as i32 - prev_statement_rva.0 as i32);

                        #[rustfmt::skip]
                        match depth {
                            0  => writeln!(w, "\t// <{offset}>|{diff_start}|{diff_prev}:'{line_start}'"),
                            _  => writeln!(w, "\t// <{offset}>|{diff_start}|{diff_prev}|[{depth}]:'{line_start}'"),
                        }?;
                    }

                    None => {
                        empty_line_no += 1;
                        writeln!(w, "\t// {empty_line_no}")?
                    }
                }
            }

            writeln!(w, "\t// ******")?;
        }

        writeln!(w, "}}")?;

        writeln!(w)?;

        Ok(())
    }
}

pub fn write_header(mut w: impl std::io::Write, path: &std::path::Path) -> crate::Result<()> {
    use chrono::Local;
    let day = Local::now().format("%d.%m.%Y").to_string();

    #[rustfmt::skip]
    {
        writeln!(w, "////////////////////////////////////////////////////////////////////////////")?;
        writeln!(w, "//	Created 	: {day}")?;
        writeln!(w, "////////////////////////////////////////////////////////////////////////////")?;
        writeln!(w)?;
    };

    let file_name = path
        .file_name()
        .expect("no filename")
        .to_string_lossy()
        .to_string();
    if let Some(module_name) = file_name.strip_suffix(".cpp") {
        writeln!(w, "#include \"pch.h\"")?;
        writeln!(w, "#include \"{module_name}.h\"")?;
        writeln!(w)?;
    } else if let Some(module_name) = file_name.strip_suffix(".h") {
        let ifdef = format!("{}_H_INCLUDED", module_name.to_uppercase());

        writeln!(w, "#ifndef {ifdef}")?;
        writeln!(w, "#define {ifdef}")?;
        writeln!(w)?;
    }

    #[rustfmt::skip]
    {
        writeln!(w, "namespace vostok {{")?;
        writeln!(w, "namespace network_core {{")?;

        // writeln!(w, "namespace survarium {{")?;
        writeln!(w)?;
    };
    Ok(())
}

pub fn write_footer(mut w: impl std::io::Write, path: &std::path::Path) -> crate::Result<()> {
    let file_name = path
        .file_name()
        .expect("no filename")
        .to_string_lossy()
        .to_string();

    #[rustfmt::skip]
    {
        // writeln!(w, "}} // namespace survarium")?;

        writeln!(w, "}} // namespace network_core")?;
        writeln!(w, "}} // namespace vostok")?;
    };

    if let Some(module_name) = file_name.strip_suffix(".h") {
        writeln!(w)?;

        let ifdef = format!("{}_H_INCLUDED", module_name.to_uppercase());

        writeln!(w, "#endif // #ifndef {ifdef}")?;
    }
    Ok(())
}
