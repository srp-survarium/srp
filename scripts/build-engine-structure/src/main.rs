//! The idea behind this script is to build a structure out of decompiled function names.
//! It didn't pan out, since it is hard to parse C++ function names (with generics and all).
//! Plus many types have generics inside.

fn main() {
    let from = "D:/Projects/decompiled_funcs/decompiled_funcs";
    // let to = "D:/Projects/decompiled_funcs/engine";

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

        // stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > >
        //  *__usercall
        //  stlp_std
        //      ::map<unsigned int,survarium::base_point_stats,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::base_point_stats>>>
        //      ::operator[]<unsigned int>
        //      @<eax>
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
