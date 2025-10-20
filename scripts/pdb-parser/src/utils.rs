use pdb_addr2line::type_parser;
use pdb_addr2line::type_parser::AttributeFlags;
use pdb_addr2line::type_parser::ReturnType;

#[derive(Default, Debug, Clone, PartialEq, Eq, PartialOrd, Ord)]
pub struct Type(pub String);

impl std::fmt::Display for Type {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        self.0.fmt(f)
    }
}

impl Type {
    // TODO: Workspace replacements should be dynamic
    // * This also affects namespace creation for headers and sources
    // * This also affects dummy return types in sources
    #[rustfmt::skip]
    pub fn new(ty: &str) -> Self {
        let ty = ty
            //
            // Generic type replacements
            //
            .replace("stlp_std",     "std")
            .replace("char const*",  "pcstr")
            .replace("char const *", "pcstr")
            .replace("void const*",  "pcvoid")
            .replace("void const *", "pcvoid")

            .replace("u8 const *", "pcbyte")
            .replace("u8 const*",  "pcbyte")
            .replace("u8 *",       "pbyte")
            .replace("u8*",        "pbyte")

            //
            .replace("unsigned int",       "u32")
            .replace("unsigned short",     "u16")
            .replace("unsigned char",      "u8")
            //
            .replace("boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> >",     "boost::asio::ip::tcp::socket")
            .replace("boost::asio::ip::basic_endpoint<boost::asio::ip::tcp>",                                                                "boost::asio::ip::tcp::endpoint")
            .replace("boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp> >",       "boost::asio::ip::tcp::resolver")
            .replace("boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>",                                                       "boost::asio::ip::tcp::resolver::iterator")
            .replace("boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp>",                                                          "boost::asio::ip::tcp::resolver::query")

            .replace("boost::asio::basic_datagram_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> >", "boost::asio::ip::udp::socket")
            .replace("boost::asio::ip::basic_endpoint<boost::asio::ip::udp>",                                                                "boost::asio::ip::udp::endpoint")


            .replace("boost::asio::basic_streambuf<std::allocator<char> >",                  "boost::asio::streambuf")
            .replace("boost::noncopyable_::noncopyable",                                     "boost::noncopyable")
            .replace("std::basic_string<char,std::char_traits<char>,std::allocator<char> >", "std::string")
            .replace("std::basic_ostream<char,std::char_traits<char> >",                     "std::ostream")
            .replace("std::basic_istream<char,std::char_traits<char> >",                     "std::istream")


            .replace(" __cdecl(void)", "()")
            .replace(" __cdecl", "")


            // Replacements for `survarium` workspace
            // .replace("survarium::", "")


            // Replacements for workspace inside `vostok` namespace
            .replace("vostok::network_core::", "")
            // .replace("vostok::physics::", "")
            // .replace("vostok::collision::", "")

            // Replacements for `vostok` workspace
            .replace("vostok::math::", "")
            .replace("vostok::",       "")

            ;

        Self(ty)
    }

    pub fn len(&self) -> usize {
        self.0.len()
    }
}

//
//
//

pub fn write_fn_signature_with_args(
    fn_t: &type_parser::Function,
    args: &[(String, Type)],
    max_return_type_len: Option<usize>,
    max_method_name_len: Option<usize>,
    pad_args_len: Option<usize>,
    w: &mut impl std::fmt::Write,
) -> std::fmt::Result {
    let type_parser::Function {
        return_type, name, ..
    } = fn_t;

    write_return_type(return_type, max_return_type_len, w)?;

    write!(w, "{name}")?;

    if let Some(max_method_name_len) = max_method_name_len {
        pad_spaces_t(w, name.len(), max_method_name_len)?;
    }

    write!(w, "(")?;
    if args.len() < 4 {
        for (idx, (arg_name, arg_type)) in args.iter().enumerate() {
            let first = idx == 0;

            write!(w, "{n} {arg_type} ", n = if first { "" } else { "," })?;
            write!(w, "{arg_name}")?;
        }

        write!(w, " )")?;
    } else {
        writeln!(w)?;

        let len = args.len();

        let pad_space = args
            .iter()
            .map(|(_, arg_type)| arg_type.len())
            .max()
            .unwrap();

        for (idx, (arg_name, arg_type)) in args.into_iter().enumerate() {
            let last = idx == len - 1;

            if let Some(pad_args_len) = pad_args_len {
                pad_spaces_uncap(w, pad_args_len)?;
            }

            write!(w, "\t{arg_type}\t")?;

            pad_spaces_t(w, arg_type.len(), pad_space)?;
            match last {
                false => writeln!(w, "{arg_name},")?,
                true => writeln!(w, "{arg_name}")?,
            }

            if last {
                if let Some(pad_args_len) = pad_args_len {
                    pad_spaces_uncap(w, pad_args_len)?;
                }
                write!(w, ")")?;
            }
        }
    }

    if fn_t.attrs.contains(AttributeFlags::IS_CONST) {
        write!(w, " const")?;
    }

    Ok(())
}

pub fn write_fn_signature_unnamed_args(
    fn_t: &type_parser::Function,
    max_return_type_len: Option<usize>,
    max_method_name_len: Option<usize>,
    pad_args_len: Option<usize>,
    w: &mut impl std::fmt::Write,
) -> std::fmt::Result {
    let args = fn_t
        .arg_types
        .iter()
        .enumerate()
        .map(|(i, arg_type)| (format!("arg_{i}"), Type::new(arg_type)))
        .collect::<Vec<_>>();

    write_fn_signature_with_args(
        fn_t,
        &args,
        max_return_type_len,
        max_method_name_len,
        pad_args_len,
        w,
    )
}

pub fn write_return_type(
    return_type: &type_parser::ReturnType,
    max_return_type_len: Option<usize>,
    w: &mut impl std::fmt::Write,
) -> std::fmt::Result {
    let return_type_len = match return_type {
        ReturnType::Constructor | ReturnType::Destructor => 0,
        ReturnType::Type(type_) => {
            let return_type = Type::new(&type_);
            write!(w, "{return_type}")?;
            return_type.len()
        }
    };
    if let Some(max_return_type_len) = max_return_type_len {
        write!(w, "\t")?;
        pad_spaces_t(w, return_type_len, max_return_type_len)?;
    } else {
        write!(w, " ")?;
    }

    Ok(())
}

pub fn set_method_attributes(
    fn_t: &mut type_parser::Function,
    attrs: pdb::FieldAttributes,
    found_body: bool,
) {
    let attrs = method_attributes::MyFieldAttributes::extract(attrs);

    #[rustfmt::skip]
    {
        fn_t.attrs.set(AttributeFlags::IS_VIRTUAL,  attrs.is_virtual());
        fn_t.attrs.set(AttributeFlags::IS_OVERRIDE, attrs.is_override());
        fn_t.attrs.set(AttributeFlags::IS_PURE,     attrs.is_pure());
        fn_t.attrs.set(AttributeFlags::IS_FINAL,    attrs.is_final());

        // Method is considered to be inline if it isn't pure, it's body wasn't found (meaning it
        // was most likely inlined) and that the body wasn't generated by compiler
        fn_t.attrs.set(AttributeFlags::IS_INLINE,   !attrs.is_pure() && !found_body);
    };
}

//
//
//

pub fn write_fmt(
    w: &mut impl std::io::Write,
    cb: impl Fn(&mut String) -> std::fmt::Result,
) -> std::io::Result<()> {
    let mut result = String::new();
    cb(&mut result).unwrap();
    write!(w, "{result}")
}

/// Padding between a type and name. Used for arguments, constants & statics.
///
/// @TODO: Generate in format used by GSC.
pub const MAX_PAD_TABS: usize = 8;
pub const MAX_PAD_SPACE: usize = MAX_PAD_TABS * 4;

/// Pad a string given how much was already written
///
/// Use this function if you don't care about the size of the total padding.
pub fn pad_spaces(w: &mut impl std::fmt::Write, prefix_len: usize) -> std::fmt::Result {
    pad_spaces_t(w, prefix_len, MAX_PAD_SPACE)
}

/// Pad a string given how much was already written and how big the padding needs to be.
///
/// # Arguments
///
/// * `prefix_len` - How much bytes were already written
/// * `pad_space`  - Length of the paddding you want to achieve.
///         Note that it will be capped by `MAX_PAD_SPACE`.
pub fn pad_spaces_t(
    w: &mut impl std::fmt::Write,
    prefix_len: usize,
    pad_space: usize,
) -> std::fmt::Result {
    for _ in 0..pad_times(prefix_len, pad_space.min(MAX_PAD_SPACE)) {
        write!(w, "\t")?;
    }
    Ok(())
}

/// Pad a string to `pad_space` length.
///
/// # Arguments
///
/// * `pad_space`  - Length of the paddding you want to achieve.
///         Note that it will be capped by `MAX_PAD_SPACE`.
pub fn pad_spaces_uncap(w: &mut impl std::fmt::Write, pad_space: usize) -> std::fmt::Result {
    for _ in 0..pad_times(0, pad_space) {
        write!(w, "\t")?;
    }
    Ok(())
}

pub fn pad_times(prefix_len: usize, pad_space: usize) -> usize {
    //
    // my_type
    // <--><--><--><--><--><-
    //    ^                 ^
    //    already_tabbed    pad_space
    //     <--><--><--><--><-->
    //

    let pad_tabs = (pad_space % 4 != 0) as usize + pad_space / 4;

    let already_tabbed = prefix_len / 4;

    pad_tabs.saturating_sub(already_tabbed)
}

mod method_attributes {
    #[derive(Debug, Copy, Clone, PartialEq, Eq)]
    pub struct MyFieldAttributes(pub u16);

    impl MyFieldAttributes {
        pub fn extract(val: pdb::FieldAttributes) -> Self {
            let s = format!("{val:?}",);
            let s = s
                .trim_start_matches("FieldAttributes(")
                .trim_end_matches(')')
                .parse::<u16>()
                .unwrap();
            Self(s)
        }

        #[inline]
        #[must_use]
        fn method_properties(self) -> u8 {
            ((self.0 & 0x001c) >> 2) as u8
        }

        #[inline]
        #[must_use]
        pub fn is_pure(self) -> bool {
            matches!(self.method_properties(), 0x05 | 0x06)
        }

        #[inline]
        #[must_use]
        pub fn is_virtual(self) -> bool {
            matches!(self.method_properties(), 0x01 | 0x04 | 0x05 | 0x06)
        }

        #[inline]
        pub fn is_override(self) -> bool {
            matches!(self.method_properties(), 0x01 | 0x05)
        }

        #[inline]
        #[must_use]
        pub fn is_final(self) -> bool {
            self.0 & 0x0200 != 0
        }

        /*

        #[inline]
        #[must_use]
        pub fn noinherit(self) -> bool {
            self.0 & 0x0040 != 0
        }

        #[inline]
        #[must_use]
        pub fn noconstruct(self) -> bool {
            self.0 & 0x0080 != 0
        }

        */
    }
}
