char __userpurge vostok::variant<32>::try_get<survarium::base_game_scene *>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<esi>,
        survarium::base_game_scene **out_value)
{
  unsigned int v3; // eax

  if ( `vostok::variant<32>::try_get<survarium::base_game_scene *>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<survarium::base_game_scene *>::get() )
  {
    *out_value = *(survarium::base_game_scene **)(a2 + 8);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<survarium::base_game_scene *>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<survarium::base_game_scene *>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<survarium::base_game_scene *>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<survarium::base_game_scene *>'::`5'::debug_macro_helper_ignore_always )
      {
        LOBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value,
          process_error_false,
          &`vostok::variant<32>::try_get<survarium::base_game_scene *>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || (_BYTE)out_value )
          __debugbreak();
      }
    }
    return 0;
  }
}
