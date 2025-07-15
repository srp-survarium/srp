void __cdecl handler_base(const char *reason_string)
{
  bool v1; // [esp+3h] [ebp-1h] BYREF

  if ( !debug_macro_helper_ignore_always_39 )
  {
    v1 = 0;
    vostok::debug::on_error(
      &v1,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      ".\\initialize_win_xbox360.cpp",
      "handler_base",
      (const char *)0x27,
      "error handler is invoked: %s",
      reason_string);
    if ( vostok::debug::is_debugger_present() || v1 )
      __debugbreak();
  }
}
