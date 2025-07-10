char __thiscall vostok::variant<32>::try_get<vostok::sound::sound_scene_creation_params>(
        vostok::variant<32> *this,
        vostok::sound::sound_scene_creation_params *out_value)
{
  bool do_debug_break; // [esp+7h] [ebp-1h] BYREF

  if ( `vostok::variant<32>::try_get<vostok::sound::sound_scene_creation_params>'::`5'::debug_macro_helper_ignore_always
    || this->m_type_id == vostok::detail::type_to_int<vostok::sound::sound_scene_creation_params>::get() )
  {
    *out_value = *(vostok::sound::sound_scene_creation_params *)this->m_storage;
    return 1;
  }
  else
  {
    if ( `vostok::variant<32>::try_get<vostok::sound::sound_scene_creation_params>'::`8'::occurances_left == -1 )
      `vostok::variant<32>::try_get<vostok::sound::sound_scene_creation_params>'::`8'::occurances_left = 10;
    if ( `vostok::variant<32>::try_get<vostok::sound::sound_scene_creation_params>'::`8'::occurances_left-- )
    {
      if ( !`vostok::variant<32>::try_get<vostok::sound::sound_scene_creation_params>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::variant<32>::try_get<vostok::sound::sound_scene_creation_params>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}
