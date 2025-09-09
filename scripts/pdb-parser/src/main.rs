#![feature(str_as_str)]
#![expect(clippy::len_without_is_empty)]

//! Builds a project structure out of the provided PDB file.
//!
//! Hardcoded to work only with `survarium.pdb`, though this can be improved later on.
//! (See constants in `run` module)
//!
//! Execute from the root of the workspace like so (assuming `vostok-structure` repo is cloned in
//! the same folder `srp` was):
//!
//! ```ignore
//! cargo run --bin pdb-parser --release -- --pdb_path="D:/Projects/Survarium/binaries/win32/survarium.pdb" --output_path="../vostok-structure"
//! ```
//!
//! The values are hardocded for ease of use by me, so if your paths are the same as in the example
//! above, you can simply run:
//!
//! ```ignore
//! cargo run --bin pdb-parser --release
//! ```

// @TODO: `FILE_PREFIX_BASE` shouldn't be hardcoded.
// @TODO: Would be nice to write breakpoints with the source code.

pub mod addr2line;
pub mod error;
pub mod utils;

pub mod dump_pdb;
pub mod gen_headers;
pub mod gen_sources;

pub use error::{Error, Result};

use clap::Parser;

#[derive(clap::Parser)]
pub struct Cli {
    #[arg(
        short,
        long,
        value_hint = clap::ValueHint::FilePath,
        default_value = "D:\\Projects\\Survarium\\binaries\\win32\\survarium.pdb",
    )]
    pdb_path: std::path::PathBuf,

    #[arg(
        short,
        long,
        value_hint = clap::ValueHint::FilePath,
        default_value = "..\\vostok-structure",
    )]
    output_path: std::path::PathBuf,

    // cargo run --bin pdb-parser --release -- --test-run > ./target/survarium.txt ; if ($?) { nvim ./target/survarium.txt }
    #[arg(long, action)]
    test_run: bool,

    #[arg(long, action)]
    as_base: bool,
}

bitflags::bitflags! {
    #[derive(Default, Copy, Clone)]
    pub struct GenFlags: u32 {
        /// Do not generate file structure.
        /// Print to `stdout` source file for `TEST_MODULE` instead.
        const TEST_RUN  = 0b0000_0001;

        /// Generating for `BASE`.
        /// i.e. the stub is generated for the `xray` code being modified
        /// as opposed to `TARGET`, to which the code is being matched.
        ///
        /// This will cause comments to be slightly different with another prefix used for files.
        const AS_BASE = 0b0000_0010;
    }
}

pub const TEST_MODULE: &str = "bullet_manager.obj";

fn main() {
    let Cli {
        pdb_path,
        output_path,
        test_run,
        as_base,
    } = Cli::parse();

    let mut flags = GenFlags::empty();
    if test_run {
        flags |= GenFlags::TEST_RUN;
    }
    if as_base {
        flags |= GenFlags::AS_BASE;
    }

    if let Err(error) = dump_pdb::dump_pdb(&pdb_path, &output_path, flags) {
        eprintln!("{error}");
        std::process::exit(1);
    }
}
