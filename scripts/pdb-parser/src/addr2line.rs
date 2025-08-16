use pdb_addr2line::{pdb::PDB as Pdb, ContextPdbData as Data, TypeFormatterFlags as Flags};
use pdb_addr2line_orig::{
    pdb::PDB as PdbOrig, ContextPdbData as DataOrig, TypeFormatterFlags as FlagsOrig,
};
use std::cell::RefCell;

/// Formatter for types and functions.
// A hacky way to store different types of formatters.
// This is bad, since this will keep 2 versions of the `pdb` file in memory.
// The proper solution would update `pdb_addr2line` crate to allow passing flags into functions
pub struct Formatter<'a, 's> {
    /// Updated formatter specifically for xray project.
    /// The differences are:
    /// * Prints `s8`, `s32`, `i8`, `i32` types instead of standard primitive types.
    /// * Skips `const` in function arguments for values.
    formatter: RefCell<pdb_addr2line::TypeFormatter<'a, 's>>,

    formatter_orig: pdb_addr2line_orig::TypeFormatter<'a, 's>,
}

impl<'a, 's> Formatter<'a, 's> {
    /// Run a closure with the formatter initialized.
    pub fn with(
        filename: &std::path::Path,
        format: impl for<'aa, 'ss> FnOnce(Formatter<'aa, 'ss>) -> crate::Result<()>,
    ) -> crate::Result<()> {
        let file = std::fs::File::open(filename)?;
        {
            let pdb = Pdb::open(&file)?;
            let data = Data::try_from_pdb(pdb)?;
            let formatter = data.make_type_formatter_with_flags(
                Flags::SPACE_AFTER_COMMA | Flags::NAME_ONLY | Flags::NO_ARGUMENTS,
            )?;

            let pdb_orig = PdbOrig::open(&file)?;
            let data_orig = DataOrig::try_from_pdb(pdb_orig)?;
            let formatter_orig = data_orig.make_type_formatter_with_flags(
                FlagsOrig::SPACE_AFTER_COMMA | FlagsOrig::NAME_ONLY,
            )?;

            format(Formatter {
                formatter: RefCell::new(formatter),
                formatter_orig,
            })?;
        }
        Ok(())
    }

    /// The name will have:
    /// * `survarium` replaced with `stalker2`.
    /// * `vostok` replaced with `xray`.
    /// * primitive types replaced to `s{n}` & `u{n}` .
    pub fn emit_function(
        &self,
        proc_name: &pdb::RawString,
        module_id: usize,
        type_index: pdb::TypeIndex,
    ) -> crate::Result<Type> {
        let mut name = String::new();
        self.formatter.borrow().emit_function(
            &mut name,
            proc_name.to_string().as_str(),
            module_id,
            ti(type_index),
        )?;
        Ok(Type::new(&name))
    }

    pub fn emit_function_with_args(
        &self,
        proc_name: &pdb::RawString,
        module_id: usize,
        type_index: pdb::TypeIndex,
    ) -> crate::Result<Type> {
        let flags = self.formatter.borrow().flags;

        self.formatter.borrow_mut().flags = flags & !Flags::NO_ARGUMENTS;

        let name = self.emit_function(proc_name, module_id, type_index)?;

        self.formatter.borrow_mut().flags = flags;

        Ok(name)
    }

    // @TODO: Get rid of module_id | add assert too
    pub fn emit_type(&self, module_id: usize, type_index: pdb::TypeIndex) -> crate::Result<Type> {
        let mut type_name = String::new();
        self.formatter.borrow().for_module(module_id, |tf| {
            tf.emit_type_index(&mut type_name, ti(type_index))
        })?;
        Ok(Type::new(&type_name))
    }

    pub fn emit_function_orig(
        &self,
        proc_name: &pdb::RawString,
        module_id: usize,
        type_index: pdb::TypeIndex,
    ) -> crate::Result<String> {
        let mut name = String::new();
        self.formatter_orig.emit_function(
            &mut name,
            proc_name.to_string().as_str(),
            module_id,
            ti(type_index),
        )?;
        Ok(name)
    }
}

fn ti(type_index: pdb::TypeIndex) -> pdb_addr2line::pdb::TypeIndex {
    pdb_addr2line::pdb::TypeIndex(type_index.0)
}

#[derive(Default, Debug, Clone, PartialEq, Eq, PartialOrd, Ord)]
pub struct Type(pub String);

impl std::fmt::Display for Type {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        self.0.fmt(f)
    }
}

impl Type {
    pub fn new(ty: &str) -> Self {
        let ty = ty
            .replace("survarium::", "")
            .replace("vostok", "xray")
            .replace("char const*", "pcstr")
            .replace("char const *", "pcstr")
            .replace("xray::math::", "")
            .replace("xray::resources::", "resources::")
            .replace("boost::noncopyable_::noncopyable", "boost::noncopyable")
            .replace("unsigned int", "u32")
            .replace("unsigned short", "u16")
            .replace("unsigned char", "u8");

        Self(ty)
    }

    pub fn len(&self) -> usize {
        self.0.len()
    }
}
