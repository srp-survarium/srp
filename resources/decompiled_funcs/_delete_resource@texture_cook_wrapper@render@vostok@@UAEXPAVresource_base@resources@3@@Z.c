void __userpurge vostok::render::texture_cook_wrapper::delete_resource(
        vostok::render::texture_cook_wrapper *this@<ecx>,
        unsigned int a2@<ebx>,
        vostok::resources::resource_base *__formal)
{
  unsigned int v3; // eax
  bool do_debug_break; // [esp+1h] [ebp-1h] BYREF

  do_debug_break = HIBYTE(this);
  if ( !debug_macro_helper_ignore_always_25 )
  {
    v3 = occurances_left_25;
    if ( occurances_left_25 == -1 )
      v3 = 10;
    occurances_left_25 = v3 - 1;
    if ( v3 )
    {
      do_debug_break = 0;
      vostok::debug::on_error(
        a2,
        &do_debug_break,
        process_error_false,
        &debug_macro_helper_ignore_always_25,
        assert_untyped,
        "assertion_failed",
        "identity(false)",
        ".\\texture_cook_wrapper.cpp",
        "vostok::render::texture_cook_wrapper::delete_resource",
        0x145u);
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
  }
}
