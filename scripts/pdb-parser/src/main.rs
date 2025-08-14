#![allow(dead_code)]
#![allow(unused_imports)]
#![feature(str_as_str)]

use std::fs;
use std::process;

use pdb::FallibleIterator;
use pdb::IdData;
use pdb::TypeData;
use pdb::TypeInformation;
use pdb::{LineInfoKind, SymbolData, PDB};

mod error;

pub use error::{Error, Result};

mod pdb_lines;
mod pdb_symbols;
fn main() {
    pdb_lines::main()
}

// fn main() {
//     if let Err(error) = run() {
//         eprintln!("{error}");
//         process::exit(1);
//     }
// }

// fn get_file_name() -> String {
//     use getopts::Options;
//     use std::env;

//     let args: Vec<String> = env::args().collect();

//     let mut opts = Options::new();
//     opts.optflag("h", "help", "print this help menu");
//     let matches = match opts.parse(&args[1..]) {
//         Ok(m) => m,
//         Err(f) => panic!("{}", f.to_string()),
//     };

//     let filename = if matches.free.len() == 1 {
//         &matches.free[0]
//     } else {
//         panic!("specify path to a PDB");
//     };

//     filename.clone()
// }

// fn run() -> error::Result<()> {
//     // 1. `id_information` iterator is empty.
//     // 2. `type_information` is big and allows me to parse `TypeData`.
//     //     It doesn't seem to contain the paths though.

//     let pdb = get_file_name();
//     let pdb = fs::File::open(pdb)?;
//     let mut pdb = pdb::PDB::open(pdb)?;

//     let address_map = pdb.address_map()?;
//     let string_table = pdb.string_table()?;

//     println!("Module private symbols:");
//     let dbi = pdb.debug_information()?;
//     let mut modules = dbi.modules()?;
//     while let Some(module) = modules.next()? {
//         println!();
//         println!("Module: {}", module.module_name());

//         let info = match pdb.module_info(&module)? {
//             Some(info) => info,
//             None => {
//                 println!("  no module info");
//                 continue;
//             }
//         };

//         let program = info.line_program()?;
//         let mut symbols = info.symbols()?;

//         let mut lines = program.lines();

//         while let Some(line_info) = lines.next()? {
//             let rva = line_info.offset.to_rva(&address_map).expect("invalid rva");
//             let file_name = {
//                 let file_info = program.get_file_info(line_info.file_index)?;
//                 file_info.name.to_string_lossy(&string_table)?
//             };
//             println!(
//                 "  {} {}:{} <{}>",
//                 rva,
//                 file_name,
//                 line_info.line_start,
//                 line_info.length.expect("no length"),
//             );
//         }
//     }

//     Ok(())
// }

// // mod huh {

// //     use anyhow::Result;
// //     use pdb::{FallibleIterator, IdData, RawString, TypeData, TypeIndex};
// //     use std::{collections::HashSet, fs::File, io::BufReader, path::Path};

// //     fn raw_to_string(rs: &RawString) -> String {
// //         String::from_utf8_lossy(rs.as_bytes()).into_owned()
// //     }

// //     pub fn list_class_definition_paths(pdb_path: &Path) -> Result<()> {
// //         let f = File::open(pdb_path)?;
// //         let mut pdb = pdb::PDB::open(BufReader::new(f))?;

// //         // pdb.pdb_information();
// //         // pdb.type_information();  // TPI stream
// //         // pdb.id_information();    // IPI stream
// //         // pdb.debug_information(); // DBI stream
// //         // pdb.global_symbols();

// //         // Map: StringId -> path, and collect UDT->(string_id,line)
// //         let mut sid_to_path = std::collections::HashMap::<u32, String>::new();
// //         let mut udt_src = Vec::<(TypeIndex, u32 /*string id*/, u32 /*line*/)>::new();

// //         if let Ok(ids) = pdb.id_information() {
// //             let mut it = ids.iter();
// //             while let Some(rec) = it.next()? {
// //                 match rec.parse()? {
// //                     IdData::StringId(s) => {
// //                         sid_to_path.insert(s.id.0, s.string.to_string());
// //                     }
// //                     IdData::UserDefinedTypeSource(u) => {
// //                         // u.udt -> TypeIndex of the class/struct
// //                         // u.file -> StringId of path, u.line -> line number
// //                         udt_src.push((u.udt, u.source_file, u.line));
// //                     }
// //                     _ => {}
// //                 }
// //             }
// //         }

// //         // Identify which UDT TypeIndex are actually "class" (not struct/union)
// //         let mut classes = HashSet::<TypeIndex>::new();
// //         let type_info = pdb.type_information()?;
// //         let mut titer = type_info.iter();
// //         while let Some(typed) = titer.next()? {
// //             match typed.parse() {
// //                 Ok(TypeData::Class(c)) => {
// //                     // mark this type index as a class
// //                     classes.insert(typed.index());
// //                 }
// //                 _ => {}
// //             }
// //         }

// //         // Emit unique filesystem paths for class definitions
// //         let mut out = HashSet::<String>::new();
// //         for (ti, sid, _line) in udt_src {
// //             if classes.contains(&ti) {
// //                 if let Some(p) = sid_to_path.get(&sid) {
// //                     out.insert(p.clone());
// //                 }
// //             }
// //         }

// //         for p in out {
// //             println!("{p}");
// //         }
// //         Ok(())
// //     }
// // }
