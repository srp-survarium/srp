void __cdecl __noreturn epilogue(_EXCEPTION_POINTERS *const exception_information)
{
  vostok::debug::call_stack::finalize_symbols();
  if ( s_previous_handler )
    s_previous_handler(exception_information);
  vostok::debug::platform::terminate((const char *)&buf, 2);
}
