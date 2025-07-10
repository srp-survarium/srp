//! ```no-run
//! cargo run --bin nasm-decompiler -- --patch-name udp parse-survarium --offset "0x00747787" --size 0x50
//! cargo run --bin nasm-decompiler -- --patch-name udp parse-patch
//! ```

use clap::Parser;
use iced_x86::{Decoder, DecoderOptions, Formatter, Instruction, NasmFormatter};

const FILEPATH: &str = "D:/Projects/Survarium/binaries/win32/survarium.exe";
const OUT_DIR: &str = "./resources/patches";
const NASM_OUTPUT_DIR: &str = "./target";
const BITNESS: u32 = 32;

#[derive(clap::Parser)]
struct Args {
    #[arg(long, default_value = NASM_OUTPUT_DIR)]
    nasm_out_dir: String,

    #[arg(long, env = "SURVARIUM_EXE", default_value = FILEPATH)]
    game_path: String,

    #[arg(long, default_value = OUT_DIR)]
    out_dir: String,

    #[arg(long)]
    patch_name: String,

    #[command(subcommand)]
    commands: Commands,
}

#[derive(clap::Subcommand)]
enum Commands {
    ParseSurvarium {
        #[arg(long, value_parser = parse_hex)]
        offset: usize,

        #[arg(long, value_parser = parse_hex, default_value = "0xFF")]
        size: usize,
    },

    ParsePatch,

    Match {
        #[arg(long)]
        binary: bool,
    },

    PatchSurvarium,
}

fn parse_hex(s: &str) -> Result<usize, std::num::ParseIntError> {
    usize::from_str_radix(s.trim_start_matches("0x"), 16)
}

fn parse_patch_rip(patch: &[u8]) -> u64 {
    let rip = patch.strip_prefix(b"; rip = 0x").unwrap();
    let rip = rip
        .iter()
        .take_while(|c| **c != b'\n')
        .map(|c| char::from_u32(*c as u32).unwrap())
        .collect::<String>();
    parse_hex(&rip).unwrap() as u64
}

fn build_asm(asm_file: &str, bin_file: &str) -> Vec<u8> {
    let mut command = std::process::Command::new("nasm.exe");
    let command = command
        .arg(asm_file)
        .arg("-o")
        .arg(bin_file)
        .spawn()
        .unwrap();
    let output = command.wait_with_output().unwrap();
    if !output.status.success() {
        eprintln!(
            "{stdout}\n",
            stdout = String::from_utf8_lossy(&output.stdout),
        );

        eprintln!(
            "{stderr}\n",
            stderr = String::from_utf8_lossy(&output.stderr),
        );
        panic!();
    } else {
        std::fs::read(bin_file).unwrap()
    }
}

fn main() {
    let Args {
        nasm_out_dir,
        game_path,
        out_dir,
        patch_name,
        commands,
    } = Args::parse();

    let og_asm = format!("{out_dir}/{patch_name}_og.asm");
    let patch_asm = format!("{out_dir}/{patch_name}_patch.asm");

    let og_bin = format!("{nasm_out_dir}/{patch_name}_og.bin");
    let patch_bin = format!("{nasm_out_dir}/{patch_name}_patch.bin");

    match commands {
        Commands::ParseSurvarium { offset, size } => {
            let bytes = std::fs::read(game_path).unwrap();
            let bytes = &bytes[offset..offset + size];

            let patch_file = build_patch(bytes, offset as u64);

            _ = remove_readonly(&og_asm);
            std::fs::write(&og_asm, &patch_file).unwrap();
            make_file_readonly(&og_asm).unwrap();

            std::fs::write(patch_asm, &patch_file).unwrap();
            print_disassemble(&bytes, offset as u64);
        }

        Commands::ParsePatch => {
            let rip = {
                let bytes = std::fs::read(&patch_asm).unwrap();
                parse_patch_rip(&bytes)
            };
            let bytes = build_asm(&patch_asm, &patch_bin);
            print_disassemble(&bytes, rip);
        }

        Commands::Match { binary } => {
            let rip = {
                let bytes = std::fs::read(&patch_asm).unwrap();
                parse_patch_rip(&bytes)
            };

            let og_bytes = build_asm(&og_asm, &og_bin);
            let patch_bytes = build_asm(&patch_asm, &patch_bin);

            if og_bytes.len() == patch_bytes.len() {
                println!("Original length matches patch length!\n")
            } else {
                println!("Original length DOES NOT match patch length!\n")
            }

            match binary {
                false => match functionally_same(&og_bytes, &patch_bytes, rip) {
                    None => println!("Equal!"),
                    Some(diff) => {
                        println!("{diff}\n");
                    }
                },
                true => match og_bytes == patch_bytes {
                    true => println!("Equal!"),
                    false => {
                        let mut diffs = vec![];

                        let mut in_diff = None;
                        for (idx, (og_byte, patch_byte)) in
                            og_bytes.iter().zip(patch_bytes.iter()).enumerate()
                        {
                            match in_diff {
                                None if og_byte != patch_byte => {
                                    in_diff = Some(idx);
                                }
                                Some(diff_idx) if og_byte == patch_byte => {
                                    diffs.push((diff_idx, idx));
                                    in_diff = None;
                                }
                                _ => (),
                            }
                        }
                        if let Some(diff_idx) = in_diff.take() {
                            diffs.push((diff_idx, patch_bytes.len()));
                        }

                        let mut diff_str = "    ".to_string();
                        let mut prev_end = 0;
                        for (start, end) in diffs {
                            let start = start * 4;
                            let end = end * 4;
                            diff_str.push_str(&" ".repeat(start - prev_end));
                            diff_str.push_str(&"^".repeat(end - start));
                            prev_end = end;
                        }

                        println!("gm {:02x?}", og_bytes);
                        println!("pc {:02x?}", patch_bytes);
                        println!("{diff_str}");

                        println!("ORIGINAL:");
                        print_disassemble(&og_bytes, rip);

                        println!("\nPATCH:");
                        print_disassemble(&patch_bytes, rip);
                    }
                },
            }
        }

        Commands::PatchSurvarium => {
            fn get_current_time() -> u64 {
                use std::time::{SystemTime, UNIX_EPOCH};
                let start = SystemTime::now();
                let since_the_epoch = start
                    .duration_since(UNIX_EPOCH)
                    .expect("time should go forward");
                since_the_epoch.as_secs()
            }

            let rip = {
                let bytes = std::fs::read(&patch_asm).unwrap();
                parse_patch_rip(&bytes)
            };
            let og_bytes = build_asm(&og_asm, &og_bin);
            let patch_bytes = build_asm(&patch_asm, &patch_bin);
            assert_eq!(og_bytes.len(), patch_bytes.len());

            let mut game_bytes = std::fs::read(&game_path).unwrap();
            std::fs::write(
                format!(
                    "{game_path}_{current_time}",
                    current_time = get_current_time(),
                ),
                &game_bytes,
            )
            .unwrap();

            let rip = rip as usize;
            game_bytes[rip..rip + patch_bytes.len()].copy_from_slice(&patch_bytes);

            std::fs::write(format!("{game_path}"), &game_bytes).unwrap();

            println!("DONE")
        }
    }
}

pub fn build_patch(bytes: &[u8], rip: u64) -> String {
    let mut patch = format!("; rip = 0x{rip:x}\n\nbits 32\n\n");

    let mut formatter = {
        let mut formatter = NasmFormatter::new();
        formatter.options_mut().set_digit_separator("");
        formatter.options_mut().set_first_operand_char_index(10);
        formatter
    };

    let mut decoder = Decoder::with_ip(BITNESS, bytes, rip, DecoderOptions::NONE);
    let mut instruction = Instruction::default();

    while decoder.can_decode() {
        decoder.decode_out(&mut instruction);

        formatter.format(&instruction, &mut patch);
        patch.push_str("\n");
    }

    patch
}

pub(crate) fn print_disassemble(bytes: &[u8], rip: u64) {
    let mut formatter = {
        let mut formatter = NasmFormatter::new();
        formatter.options_mut().set_digit_separator("");
        formatter.options_mut().set_first_operand_char_index(10);
        formatter
    };

    let mut decoder = Decoder::with_ip(BITNESS, bytes, rip, DecoderOptions::NONE);
    let mut instruction = Instruction::default();

    let mut buffer = String::new();
    while decoder.can_decode() {
        decoder.decode_out(&mut instruction);

        buffer.clear();
        formatter.format(&instruction, &mut buffer);

        print!("{:016X} ", instruction.ip());

        let start_index = (instruction.ip() - rip) as usize;
        let instr_bytes = &bytes[start_index..start_index + instruction.len()];
        for b in instr_bytes.iter() {
            print!("{:02X}", b);
        }
        if instr_bytes.len() < HEXBYTES_COLUMN_BYTE_LENGTH {
            for _ in 0..HEXBYTES_COLUMN_BYTE_LENGTH - instr_bytes.len() {
                print!("  ");
            }
        }
        print!(" {buffer}\n");
    }
}

const HEXBYTES_COLUMN_BYTE_LENGTH: usize = 10;

pub(crate) fn functionally_same(lhs: &[u8], rhs: &[u8], rip: u64) -> Option<String> {
    let mut formatter = {
        let mut formatter = NasmFormatter::new();
        formatter.options_mut().set_digit_separator("");
        formatter.options_mut().set_first_operand_char_index(10);
        formatter
    };

    let mut lhs = Decoder::with_ip(BITNESS, lhs, rip, DecoderOptions::NONE);
    let mut rhs = Decoder::with_ip(BITNESS, rhs, rip, DecoderOptions::NONE);

    let mut output = String::new();

    let mut lhs_instruction = Instruction::default();
    let mut rhs_instruction = Instruction::default();

    let mut differ: bool = false;
    while lhs.can_decode() {
        lhs.decode_out(&mut lhs_instruction);
        rhs.decode_out(&mut rhs_instruction);

        if lhs_instruction == rhs_instruction {
            formatter.format(&lhs_instruction, &mut output);
            output.push_str("\n");
        } else {
            output.push_str("\n>>> ");
            formatter.format(&lhs_instruction, &mut output);
            output.push_str("\n");

            output.push_str("<<< ");
            formatter.format(&rhs_instruction, &mut output);
            output.push_str("\n\n");

            differ = true;
        }
    }

    if differ {
        Some(output)
    } else {
        None
    }
}

fn make_file_readonly<P: AsRef<std::path::Path>>(path: P) -> std::io::Result<()> {
    let mut perms = std::fs::metadata(&path)?.permissions();
    perms.set_readonly(true);
    std::fs::set_permissions(&path, perms)
}

fn remove_readonly<P: AsRef<std::path::Path>>(path: P) -> std::io::Result<()> {
    let mut perms = std::fs::metadata(&path)?.permissions();
    perms.set_readonly(false);
    std::fs::set_permissions(&path, perms)
}
