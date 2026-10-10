#![feature(str_as_str)]
// SPDX-License-Identifier: GPL-3.0-or-later

//! Builds a project structure out of the provided PDB file.
//!
//! Hardcoded to work only with `survarium.pdb`, though this can be improved later on.
//! (See constants in `run` module)
//!
//! Execute from the root of the workspace like so (assuming `vostok-structure` repo is cloned in
//! the same folder `srp` was):
//!
//! ```ignore
//! cargo run --bin pdb-parser --release -- --pdb_path="D:/Projects/Survarium/binaries/win32/survarium.pdb" --output_path="../vostok-structure/vostok"
//! ```
//!
//! The values are hardocded for ease of use by me, so if your paths are the same as in the example
//! above, you can simply run:
//!
//! ```ignore
//! cargo run --bin pdb-parser --release
//! ```

mod error;
mod run;

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
        default_value = "..\\vostok-structure\\vostok\\",
    )]
    output_path: std::path::PathBuf,

    // cargo run --bin pdb-parser --release -- --test-on-bullet > ./target/survarium.txt ; if ($?) { nvim ./target/survarium.txt }
    #[arg(long, action)]
    test_on_bullet: bool,
}

fn main() {
    let Cli {
        pdb_path,
        output_path,
        test_on_bullet,
    } = Cli::parse();
    run::run(pdb_path, output_path, test_on_bullet)
}
