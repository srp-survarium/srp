use pdb::PDB;

use crate::addr2line::Formatter;
use crate::GenFlags;
use crate::{gen_headers, gen_sources};

pub fn dump_pdb(
    pdb_path: &std::path::Path,
    output_path: &std::path::Path,
    engine_path: &str,
    flags: GenFlags,
) -> crate::Result<()> {
    Formatter::with(pdb_path, |formatter| {
        let file = std::fs::File::open(pdb_path)?;
        let pdb = PDB::open(file)?;
        dump_pdb_impl(pdb, formatter, output_path, engine_path, flags)
    })
}

pub fn dump_pdb_impl(
    mut pdb: pdb::PDB<std::fs::File>,
    formatter: Formatter,
    output_path: &std::path::Path,
    engine_path: &str,
    flags: GenFlags,
) -> crate::Result<()> {
    let function_sigs =
        gen_sources::dump_sources(&mut pdb, &formatter, output_path, engine_path, flags)?;
    gen_headers::dump_headers(&mut pdb, &formatter, function_sigs, output_path, flags)?;

    Ok(())
}
