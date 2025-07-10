void __cdecl vostok::debug::platform::prologue_dump_call_stack(_EXCEPTION_POINTERS *exception_information)
{
  if ( !vostok::debug::platform::error_after_dialog() )
    vostok::debug::dump_call_stack("debug", 1, 0, 0, exception_information, 0);
}
