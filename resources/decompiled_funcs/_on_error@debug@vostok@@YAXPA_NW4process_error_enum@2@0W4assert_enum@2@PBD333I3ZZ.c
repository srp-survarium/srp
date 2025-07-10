void __usercall vostok::debug::on_error(
        unsigned int a1@<ebx>,
        bool *do_debug_break,
        vostok::process_error_enum process_error,
        bool *ignore_always,
        vostok::assert_enum assert_type,
        char *reason,
        char *expression,
        char *file,
        char *function,
        unsigned int line,
        char *format,
        ...)
{
  char destination[4096]; // [esp+4h] [ebp-1000h] BYREF
  va_list va; // [esp+1034h] [ebp+30h] BYREF

  va_start(va, format);
  vostok::vsnprintf(format, va, destination, 0x1000u, 0xFFFu);
  process(
    a1,
    do_debug_break,
    process_error,
    ignore_always,
    assert_type,
    reason,
    expression,
    destination,
    file,
    function,
    line);
}
