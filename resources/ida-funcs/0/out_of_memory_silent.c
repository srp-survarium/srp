char __thiscall out_of_memory_silent(
        vostok::command_line::key *this,
        void *const space,
        _DWORD *parameter,
        const int first_time)
{
  const char *v5; // [esp-4h] [ebp-8h]

  if ( first_time )
    return 0;
  vostok::memory::monitor::finalize(this);
  vostok::memory::dump_statistics(0);
  if ( !debug_macro_helper_ignore_always_17 )
  {
    v5 = (const char *)parameter[3];
    HIBYTE(first_time) = 0;
    vostok::debug::on_error(
      (bool *)&first_time + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      ".\\memory_doug_lea_allocator.cpp",
      "out_of_memory_silent",
      (const char *)0x44,
      "not enough memory for arena [%s]",
      v5);
    if ( vostok::debug::is_debugger_present() || HIBYTE(first_time) )
      __debugbreak();
  }
  return 1;
}
