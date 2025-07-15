void __stdcall __noreturn unhandled_exception_handler(_EXCEPTION_POINTERS *exception_information)
{
  if ( !s_initialized_3 )
    vostok::debug::bugtrap::initialize();
  prologue(exception_information);
  epilogue(exception_information);
}
