use std::collections::BTreeMap;

use pdb::ConstantSymbol;
use pdb::DataSymbol;
use pdb::{BasePointerRelativeSymbol, BlockSymbol, FallibleIterator, SymbolData, PDB};

use crate::addr2line::Formatter;
use crate::addr2line::Type;
use crate::gen_headers;

const FILE_PREFIX: &str = "c:\\survarium\\sources\\vostok\\";
const GAME_IB: u32 = 0x10000;

/// Padding between a type and name. Used for arguments, constants & statics.
///
/// @TODO: Generate in format used by GSC.
pub const PAD_LENGTH: usize = 35;

pub fn run(pdb_path: std::path::PathBuf, output_path: std::path::PathBuf, test_on_bullet: bool) {
    if let Err(error) = dump_pdb(&pdb_path, &output_path, test_on_bullet) {
        eprintln!("{error}");
        std::process::exit(1);
    }
}

fn dump_pdb(
    pdb_path: &std::path::Path,
    output_path: &std::path::Path,
    test_on_bullet: bool, // @TODO: Use flags
) -> crate::Result<()> {
    Formatter::with(pdb_path, |formatter| {
        let file = std::fs::File::open(pdb_path)?;
        let pdb = PDB::open(file)?;
        format_functions(pdb, formatter, output_path, test_on_bullet)
    })
}

pub fn format_functions(
    mut pdb: pdb::PDB<std::fs::File>,
    formatter: Formatter,
    output_path: &std::path::Path,
    test_on_bullet: bool,
) -> crate::Result<()> {
    let address_map = pdb.address_map()?;
    let string_table = pdb.string_table()?;

    let type_information = pdb.type_information()?;

    let type_finder = {
        let mut type_finder = type_information.finder();

        let mut type_iter = type_information.iter();
        while type_iter.next()?.is_some() {
            type_finder.update(&type_iter);
        }
        type_finder
    };

    if !test_on_bullet {
        gen_headers::write_classes(&mut pdb, &formatter, &type_finder, output_path)?;
    }

    let mut output_path = output_path.to_path_buf();
    output_path.push("sources");

    let dbi = pdb.debug_information()?;
    let mut modules = dbi.modules()?;
    let mut module_id: usize = usize::MAX;
    while let Some(module) = modules.next()? {
        module_id = module_id.wrapping_add(1);

        if test_on_bullet && !module.module_name().ends_with("damage_model.obj") {
            continue;
        }

        if module.module_name().contains("\\scaleform\\") {
            continue;
        }

        let Some(info) = pdb.module_info(&module)? else {
            continue;
        };

        let program = info.line_program()?;
        let mut symbols = info.symbols()?;

        // filename -> proc_start -> Function
        let mut files: BTreeMap<String, BTreeMap<u32, Function>> = BTreeMap::new();

        let mut filename: String = String::new();
        let mut function: Function = Function::default();
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
                            file_info.name.to_string_lossy(&string_table)?
                        };
                        match &m_file_name {
                            None => m_file_name = Some(file_name),
                            Some(m_file_name) => assert_eq!(*m_file_name, file_name),
                        }

                        let rva = line_info.offset.to_rva(&address_map).expect("invalid rva");
                        breakpoints.push((rva, line_info.line_start, 0));
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

                    let name = formatter.emit_function(&proc.name, module_id, proc.type_index)?;

                    function = Function {
                        name,
                        name_orig,
                        proc_start,
                        proc_end,
                        statements: breakpoints,
                        ..function
                    };
                }

                // FunctionEnd
                SymbolData::ScopeEnd if depth == 1 => {
                    let mut take_filename = String::new();
                    std::mem::swap(&mut take_filename, &mut filename);

                    let mut take_function = Function::default();
                    std::mem::swap(&mut take_function, &mut function);

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
                        offset.to_rva(&address_map).unwrap_or(pdb::Rva(0)),
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
                    let rva = offset.to_rva(&address_map).expect("invalid rva");
                    if let Some(st) = function.statements.iter_mut().find(|st| st.0 == rva) {
                        st.2 = depth;
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

                // Keep everything that we missed but is inside functions
                symbol if depth != 0 => {
                    function.symbols.push(symbol);
                }

                // Ignore everything outside function scope
                _ => (),
            }
        }

        for (file, funs) in files {
            let Some(path_to_file) = file.strip_prefix(FILE_PREFIX) else {
                continue;
            };

            let mut source_path = output_path.to_path_buf();
            source_path.push(path_to_file);

            let mut file: Box<dyn std::io::Write> = match test_on_bullet {
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

            write_footer(&mut file, &source_path)?;
        }
    }

    Ok(())
}

#[derive(Default)]
struct Function<'a> {
    name_orig: String,
    name: Type,

    args: Vec<(pdb::RawString<'a>, Type)>,
    locals: Vec<(pdb::RawString<'a>, Type, usize)>,

    proc_start: u32,
    proc_end: u32,
    statements: Vec<(pdb::Rva, u32, i32)>,

    constants: Vec<(pdb::RawString<'a>, Type, pdb::Variant)>,
    statics: Vec<(pdb::RawString<'a>, Type, pdb::Rva)>,

    blocks: Vec<(pdb::Rva, i32)>,
    symbols: Vec<pdb::SymbolData<'a>>,
}

impl<'a> Function<'a> {
    pub fn write(self, mut w: impl std::io::Write) -> crate::Result<()> {
        let Self {
            name_orig,
            name,
            args,
            locals,
            proc_start,
            proc_end,
            statements,
            constants,
            statics,
            blocks,
            symbols,
        } = self;

        writeln!(w, "// {name_orig}")?;
        write!(w, "{name}(")?;

        if !args.is_empty() {
            writeln!(w)?;

            let len = args.len();
            for (idx, (arg_name, arg_type)) in args.into_iter().enumerate() {
                let last = idx == len - 1;

                let arg_prefix_len = arg_type.len() + " ".len();

                write!(w, "\t{arg_type} ")?;
                pad_spaces(&mut w, arg_prefix_len)?;
                writeln!(w, "{arg_name}{n}", n = if last { ")" } else { "," })?;
            }
        } else {
            writeln!(w, " )")?;
        }

        writeln!(w, "{{")?;

        if !locals.is_empty() {
            writeln!(w, "\t// LOCALS")?;
            for (local_name, local_type, local_scope) in locals {
                let local_prefix_len = "// ".len() + local_type.len() + " ".len();

                write!(w, "\t// {local_type} ")?;
                pad_spaces(&mut w, local_prefix_len)?;
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
                pad_spaces(&mut w, const_prefix_len)?;
                writeln!(w, "{const_name} = {const_value};")?;
            }
            writeln!(w, "\t// ******\n")?;
        }

        if !statics.is_empty() {
            writeln!(w, "\t// STATICS")?;
            for (static_name, static_type, static_rva) in statics {
                let static_prefix_len = "// static ".len() + static_type.len() + " ".len();

                write!(w, "\t// static {static_type} ")?;
                pad_spaces(&mut w, static_prefix_len)?;
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

        if !symbols.is_empty() {
            writeln!(w, "\t// OTHER SYMBOLS")?;
            for symbol in symbols {
                writeln!(w, "\t// {symbol:?}")?;
            }
            writeln!(w, "\t// ******\n")?;
        }

        if proc_start + 1 < proc_end {
            writeln!(w, "\t// FUNCTION BODY")?;

            for i in proc_start + 1..proc_end {
                match statements.iter().find(|bp| bp.1 == i) {
                    Some((rva, _, starts_block)) => writeln!(
                        w,
                        "\t// <{offset}>{block}",
                        offset = rva.saturating_add(GAME_IB),
                        block = if *starts_block != 0 {
                            format!(" <block><{starts_block}>")
                        } else {
                            String::new()
                        },
                    )?,
                    None => writeln!(w,)?,
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
    #[rustfmt::skip]
    {
        writeln!(w, "////////////////////////////////////////////////////////////////////////////")?;
        writeln!(w, "//	Created 	: 14.08.2025")?;
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
        writeln!(w, "namespace stalker2 {{")?;
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
        writeln!(w, "}} // namespace stalker2")?;
        writeln!(w)?;
    };

    if let Some(module_name) = file_name.strip_suffix(".h") {
        let ifdef = format!("{}_H_INCLUDED", module_name.to_uppercase());

        writeln!(w, "#endif // #ifndef {ifdef}")?;
    }
    Ok(())
}

pub fn pad_spaces(mut w: impl std::io::Write, prefix_len: usize) -> std::io::Result<()> {
    let no = PAD_LENGTH.saturating_sub(prefix_len);
    for _ in 0..no {
        write!(w, " ")?;
    }
    Ok(())
}
