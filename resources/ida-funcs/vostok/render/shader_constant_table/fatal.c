void __thiscall vostok::render::shader_constant_table::fatal(vostok::render::shader_constant_table *this, char *msg)
{
  vostok::render::shader_constant_table *v2; // [esp-2h] [ebp-4h] BYREF

  v2 = this;
  if ( !`vostok::render::shader_constant_table::fatal'::`5'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v2) = 0;
    vostok::debug::on_error(
      (bool *)&v2 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      ".\\shader_constant_table.cpp",
      "vostok::render::shader_constant_table::fatal",
      (const char *)0x24,
      msg,
      (const char *)v2);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v2) )
      __debugbreak();
  }
}
