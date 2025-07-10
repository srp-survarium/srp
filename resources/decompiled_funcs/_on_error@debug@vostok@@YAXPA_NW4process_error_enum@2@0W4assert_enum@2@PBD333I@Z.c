void __usercall vostok::debug::on_error(
        unsigned int a1@<ebx>,
        bool *do_debug_break,
        vostok::process_error_enum process_error,
        bool *ignore_always,
        vostok::assert_enum assert_type,
        const char *reason,
        const char *expression,
        const char *file,
        const char *function,
        unsigned int line)
{
  process(a1, do_debug_break, process_error, ignore_always, assert_type, reason, expression, 0, file, function, line);
}
