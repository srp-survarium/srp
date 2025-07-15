char __stdcall out_of_memory(void *const space, const void *const parameter, const int first_time)
{
  const char *v4; // [esp+0h] [ebp-4h]

  if ( first_time )
    return 1;
  if ( !debug_macro_helper_ignore_always_20 )
  {
    HIBYTE(first_time) = 0;
    vostok::debug::on_error(
      (bool *)&first_time + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      ".\\memory_pthreads3_allocator.cpp",
      "out_of_memory",
      (const char *)0x1A,
      "not enough memory for arena [global mt allocator]",
      v4);
    if ( vostok::debug::is_debugger_present() || HIBYTE(first_time) )
      __debugbreak();
  }
  return 0;
}
