char __usercall vostok::variant<32>::try_get<survarium::player_initial_info>@<al>(
        vostok::variant<32> *this@<esi>,
        survarium::player_initial_info *out_value@<edi>,
        int a3@<ecx>)
{
  unsigned int v3; // eax
  bool do_debug_break; // [esp+1h] [ebp-1h] BYREF

  do_debug_break = HIBYTE(a3);
  if ( `vostok::variant<32>::try_get<survarium::player_initial_info>'::`5'::debug_macro_helper_ignore_always
    || this->m_type_id == vostok::detail::type_to_int<survarium::player_initial_info>::get() )
  {
    *out_value = *(survarium::player_initial_info *)this->m_storage;
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<survarium::player_initial_info>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<survarium::player_initial_info>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<survarium::player_initial_info>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<survarium::player_initial_info>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::variant<32>::try_get<survarium::player_initial_info>'::`5'::debug_macro_helper_ignore_always,
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
