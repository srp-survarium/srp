void __thiscall vostok::render::texture_cook_wrapper::delete_resource(
        vostok::render::texture_cook_wrapper *this,
        vostok::resources::resource_base *__formal)
{
  unsigned int v2; // eax
  bool v3; // [esp+1h] [ebp-1h] BYREF

  v3 = HIBYTE(this);
  if ( !debug_macro_helper_ignore_always_60 )
  {
    v2 = occurances_left_29;
    if ( occurances_left_29 == -1 )
      v2 = 10;
    occurances_left_29 = v2 - 1;
    if ( v2 )
    {
      v3 = 0;
      vostok::debug::on_error(
        &v3,
        process_error_false,
        (bool *)"identity(false)",
        ".\\texture_cook_wrapper.cpp",
        "vostok::render::texture_cook_wrapper::delete_resource",
        (const char *)0x14F);
      if ( vostok::debug::is_debugger_present() || v3 )
        __debugbreak();
    }
  }
}
