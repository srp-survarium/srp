fn main() {
    let from = "D:/Projects/decompiled_funcs/decompiled_funcs";
    let to = "D:/Projects/decompiled_funcs/engine";

    let dir = std::fs::read_dir(from).unwrap();
    for entry in dir {
        let entry = entry.unwrap();
        if !entry.metadata().unwrap().is_file() {
            continue;
        }

        let path = entry.path();
        let contents = std::fs::read_to_string(&path).unwrap();
        let line = contents.lines().next().unwrap();

        if line == "None" {
            // Decompilation failed
            continue;
        }

        // vostok::ai::movement_target **__cdecl stlp_std::priv::__median<vostok::ai::movement_target const *,vostok::ai::selectors::sort_by_distance_predicate>
        let line = split_line(line, "__cdecl ");
        let line = split_line(line, "__thiscall ");
        let line = split_line(line, "__usercall ");
        let line = split_line(line, "__fastcall ");
        let line = split_line(line, "__userpurge ");

        let Some((_, line)) = line.split_once("vostok::") else {
            continue;
        };

        let Some((line, _)) = line.split_once("(") else {
            continue;
        };

        let line = match line.split_once("@") {
            None => line,
            Some((line, _)) => line,
        };

        println!("vostok::{line}")
        // println!("{line}")
    }
}

fn split_line<'a>(line: &'a str, at: &str) -> &'a str {
    match line.split_once(at) {
        None => line,
        Some((_, line)) => line,
    }
}
