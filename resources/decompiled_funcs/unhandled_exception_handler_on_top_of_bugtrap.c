void __stdcall __noreturn unhandled_exception_handler_on_top_of_bugtrap(
        _EXCEPTION_POINTERS *const exception_information)
{
  prologue(exception_information);
  if ( vostok::debug::is_debugger_present() )
    __debugbreak();
  epilogue(exception_information);
}
