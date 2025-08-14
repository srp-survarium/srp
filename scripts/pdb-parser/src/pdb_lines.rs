use std::io::Write;
use std::{collections::BTreeMap, env};

use getopts::Options;

use pdb::{
    BasePointerRelativeSymbol, BlockSymbol, FallibleIterator, LineInfoKind, MemberFunctionType,
    PrimitiveKind, PrimitiveType, ProcedureType, RawString, Rva, SymbolData, TypeData, TypeIndex,
    PDB,
};

pub fn main() {
    let args: Vec<String> = env::args().collect();

    let mut opts = Options::new();
    opts.optflag("h", "help", "print this help menu");
    let matches = match opts.parse(&args[1..]) {
        Ok(m) => m,
        Err(f) => panic!("{}", f.to_string()),
    };

    let filename = if matches.free.len() == 1 {
        &matches.free[0]
    } else {
        //print_usage(&program, opts);
        eprintln!("specify path to a PDB");
        return;
    };

    match dump_pdb(filename) {
        Ok(_) => {}
        Err(e) => {
            writeln!(&mut std::io::stderr(), "error dumping PDB: {}", e).expect("stderr write");
        }
    }
}

fn dump_pdb(filename: &str) -> crate::Result<()> {
    let file = std::fs::File::open(filename)?;
    let pdb = PDB::open(file)?;

    addr2line::with_formatter(filename, move |formatter, formatter_with_args| {
        format_functions(pdb, formatter, formatter_with_args)
    })
}

pub fn format_functions(
    mut pdb: pdb::PDB<std::fs::File>,
    formatter: pdb_addr2line::TypeFormatter,
    formatter_with_args: pdb_addr2line::TypeFormatter,
) -> crate::Result<()> {
    let address_map = pdb.address_map()?;
    let string_table = pdb.string_table()?;

    let type_information = pdb.type_information()?;
    let mut type_finder = type_information.finder();

    let mut type_iter = type_information.iter();
    while let Some(_) = type_iter.next()? {
        // keep building the index
        type_finder.update(&type_iter);
    }

    let dbi = pdb.debug_information()?;
    let mut modules = dbi.modules()?;
    let mut module_id: usize = usize::MAX;
    while let Some(module) = modules.next()? {
        module_id = module_id.wrapping_add(1);

        // if !module.module_name().ends_with("bullet.obj") {
        //     continue;
        // }

        if module.module_name().contains("\\scaleform\\") {
            continue;
        }

        let info = match pdb.module_info(&module)? {
            Some(info) => info,
            None => {
                continue;
            }
        };

        let program = info.line_program()?;
        let mut symbols = info.symbols()?;

        #[derive(Default)]
        struct Function<'a> {
            name_with_args: String,
            name: String,
            args: Vec<(String, String)>,
            locals: Vec<(String, String)>,

            proc_start: u32,
            proc_end: u32,
            statements: Vec<(Rva, u32, bool)>,

            symbols: Vec<SymbolData<'a>>,
            // constants, statics
        }

        // filename -> proc_start -> Function
        let mut files: BTreeMap<String, BTreeMap<u32, Function>> = BTreeMap::new();

        let mut filename: String = String::new();
        let mut function: Function = Function::default();
        let mut depth: i32 = 0;

        while let Some(symbol) = symbols.next()? {
            match symbol.parse() {
                // FunctionStart
                Ok(SymbolData::Procedure(proc)) => {
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
                        breakpoints.push((rva, line_info.line_start, false));
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

                    let mut name_with_args = String::new();
                    formatter_with_args.emit_function(
                        &mut name_with_args,
                        proc.name.to_string().as_str(),
                        module_id,
                        ti(proc.type_index),
                    )?;

                    let mut name = String::new();
                    formatter.emit_function(
                        &mut name,
                        proc.name.to_string().as_str(),
                        module_id,
                        ti(proc.type_index),
                    )?;

                    function.name_with_args = name_with_args;
                    function.name = name;
                    function.proc_start = proc_start;
                    function.proc_end = proc_end;
                    function.statements = breakpoints;
                }

                // FunctionEnd
                Ok(SymbolData::ScopeEnd) if depth == 1 => {
                    let mut take_filename = String::new();
                    std::mem::swap(&mut take_filename, &mut filename);

                    let mut take_function = Function::default();
                    std::mem::swap(&mut take_function, &mut function);

                    files
                        .entry(take_filename)
                        .or_insert_with(BTreeMap::new)
                        .insert(take_function.proc_start, take_function);

                    depth -= 1;
                }

                Ok(SymbolData::BasePointerRelative(BasePointerRelativeSymbol {
                    offset,
                    type_index,
                    name,
                    slot: _,
                })) => {
                    let local_name = name.to_string().to_string();

                    let mut local_type = String::new();

                    formatter.for_module(module_id, |tf| {
                        tf.emit_type_index(&mut local_type, ti(type_index))
                    })?;

                    // @TODO: This is incorrect in present of arguments passed by registers, which
                    // we do have thanks to linker optimizations
                    if function.locals.is_empty() && local_name == "this" {
                    } else if offset > 0 {
                        function.args.push((local_name, local_type));
                    } else {
                        function.locals.push((local_name, local_type));
                    }
                }

                // Skip
                Ok(SymbolData::FrameProcedure(_)) => (),

                Ok(
                    symbol @ SymbolData::Block(BlockSymbol {
                        parent: _,
                        end: _,
                        len: _,
                        offset,
                        name: _,
                    }),
                ) => {
                    let rva = offset.to_rva(&address_map).expect("invalid rva");
                    if let Some(st) = function.statements.iter_mut().find(|st| st.0 == rva) {
                        st.2 = true
                    } else {
                        function.symbols.push(symbol);
                    }

                    depth += 1;
                }
                Ok(SymbolData::ScopeEnd) => {
                    depth = (depth - 1).max(0);
                }

                Ok(symbol) if depth != 0 => {
                    function.symbols.push(symbol);
                }

                Err(error) => eprintln!("{error:?}"),
                _ => (),
            }
        }

        for (file, funs) in files {
            let Some(path_to_file) = file.strip_prefix("c:\\survarium\\sources\\vostok\\") else {
                continue;
            };

            let path_to_source = format!("./target/vostok/{path_to_file}");
            let path_to_source = std::path::Path::new(&path_to_source);

            std::fs::create_dir_all(path_to_source.parent().unwrap())?;

            let mut file = std::fs::File::create(path_to_source)?;

            for (
                fun_start,
                Function {
                    name_with_args,
                    name,
                    args,
                    locals,
                    proc_start: _,
                    proc_end,
                    statements,
                    symbols,
                },
            ) in funs
            {
                writeln!(file, "// {name_with_args}")?;
                write!(file, "{name}(")?;

                if !args.is_empty() {
                    writeln!(file,)?;

                    let len = args.len();
                    for (idx, (arg_name, arg_type)) in args.into_iter().enumerate() {
                        let last = idx == len - 1;

                        // '{arg_type} ' should always be 30 symbols or more
                        let spaces_len = 50_usize.saturating_sub(arg_type.len() + 1);

                        write!(file, "\t{arg_type} ")?;
                        for _ in 0..spaces_len {
                            write!(file, " ")?;
                        }

                        let n = if last { ")" } else { "," };
                        writeln!(file, "{arg_name}{n}")?;
                    }
                } else {
                    writeln!(file, " )")?;
                }

                writeln!(file, "{{")?;

                if !locals.is_empty() {
                    writeln!(file, "\t// LOCALS")?;
                    for (local_name, local_type) in locals {
                        // '{arg_type} ' should always be 30 symbols or more
                        let spaces_len = 50_usize.saturating_sub(local_type.len() + 1 + 3);

                        write!(file, "\t// {local_type} ")?;
                        for _ in 0..spaces_len {
                            write!(file, " ")?;
                        }

                        writeln!(file, "{local_name}")?;
                    }
                    writeln!(file, "\t// ******\n")?;
                }

                if !symbols.is_empty() {
                    writeln!(file, "\t// OTHER SYMBOLS")?;
                    for symbol in symbols {
                        writeln!(file, "\t// {symbol:?}")?;
                    }
                    writeln!(file, "\t// ******\n")?;
                }

                if fun_start + 1 < proc_end {
                    writeln!(file, "\t// FUNCTION BODY")?;

                    for i in fun_start + 1..proc_end {
                        match statements.iter().find(|bp| bp.1 == i) {
                            Some((rva, _, starts_block)) => writeln!(
                                file,
                                "\t// <{rva}>{}",
                                if *starts_block { " block_start >>" } else { "" },
                            )?,
                            None => writeln!(file,)?,
                        }
                    }

                    writeln!(file, "\t// ******")?;
                }

                writeln!(file, "}}")?;

                writeln!(file,)?;
            }

            writeln!(file,)?;
        }
    }

    Ok(())
}

mod addr2line {
    use pdb::{IdIndex, TypeIndex};
    use pdb_addr2line::{pdb, ContextPdbData, TypeFormatter, TypeFormatterFlags};
    use std::path::{Path, PathBuf};

    pub fn with_formatter(
        filename: &str,
        format: impl FnOnce(TypeFormatter, TypeFormatter) -> crate::Result<()>,
    ) -> crate::Result<()> {
        let file = std::fs::File::open(filename)?;
        let data = ContextPdbData::try_from_pdb(pdb::PDB::open(file)?)?;

        let formatter = data.make_type_formatter_with_flags(
            TypeFormatterFlags::SPACE_AFTER_COMMA
                | TypeFormatterFlags::NO_ARGUMENTS
                | TypeFormatterFlags::NAME_ONLY,
        )?;

        let formatter_with_args = data.make_type_formatter_with_flags(
            TypeFormatterFlags::SPACE_AFTER_COMMA
                // Arguments will be filled in by me
                // @TODO: Would be nice to have both versions, I think
                | TypeFormatterFlags::NAME_ONLY,
        )?;

        format(formatter, formatter_with_args)?;

        Ok(())
    }
}

fn ti(type_index: pdb::TypeIndex) -> pdb_addr2line::pdb::TypeIndex {
    pdb_addr2line::pdb::TypeIndex(type_index.0)
}

// let name = name
//     .replace("survarium", "stalker2")
//     .replace("vostok", "xray");
