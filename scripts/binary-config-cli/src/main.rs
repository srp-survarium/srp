// SPDX-License-Identifier: GPL-3.0-or-later
mod skills_tree;
use skills_tree::Skills;

use clap::Parser;
use std::path::PathBuf;

#[derive(clap::Parser)]
pub struct Cli {
    #[arg(short, long)]
    pub verbose: bool,

    #[command(subcommand)]
    pub command: Command,
}

#[derive(clap::Subcommand)]
pub enum Command {
    FormatSkillsTree {
        #[arg(
            short,
            long,
            value_hint = clap::ValueHint::FilePath,
            default_value = "./resources/skills_tree.bin",
        )]
        output: PathBuf,
    },
    FormatJson {
        #[arg(
            short,
            long,
            value_hint = clap::ValueHint::FilePath,
        )]
        input: PathBuf,

        #[arg(
            short,
            long,
            value_hint = clap::ValueHint::FilePath,
        )]
        output: Option<PathBuf>,
    },
    PrintBinaryConfig {
        #[arg(
            short,
            long,
            value_hint = clap::ValueHint::FilePath,
        )]
        input: PathBuf,
    },
}

fn main() {
    let Cli { verbose, command } = Cli::parse();

    let (binary_config, output) = match command {
        Command::FormatSkillsTree { output } => {
            let skills_tree = Skills::build();
            let json = serde_json::to_value(skills_tree).unwrap();
            let binary_config = binary_config_parser::BinaryConfig::parse_json(&json);
            (binary_config, Some(output))
        }
        Command::FormatJson { input, output } => {
            let json = std::fs::read_to_string(input).unwrap();
            let json = serde_json::from_str(&json).unwrap();
            let binary_config = binary_config_parser::BinaryConfig::parse_json(&json);
            (binary_config, output)
        }
        Command::PrintBinaryConfig { input } => {
            let binary_config = std::fs::read(input).unwrap();
            let binary_config = binary_config_parser::BinaryConfig::new(&binary_config);
            (binary_config, None)
        }
    };
    if verbose || output.is_none() {
        binary_config.parse_n_print();
    }

    if let Some(output) = output {
        std::fs::write(output, binary_config.as_bytes()).unwrap();
    }
}
