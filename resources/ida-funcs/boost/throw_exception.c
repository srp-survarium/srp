void __cdecl boost::throw_exception(const std::exception *exception)
{
  std::exception_vtbl *v1; // eax
  const char *v2; // eax
  bool do_debug_break; // [esp+7h] [ebp-1h] BYREF

  if ( !debug_macro_helper_ignore_always_38 )
  {
    v1 = exception->__vftable;
    do_debug_break = 0;
    v2 = v1->what(exception);
    vostok::debug::on_error(
      &do_debug_break,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      ".\\debug.cpp",
      "boost::throw_exception",
      (const char *)0x45,
      "boost::throw_exception: %s",
      v2);
    if ( vostok::debug::is_debugger_present() || do_debug_break )
      __debugbreak();
  }
}
