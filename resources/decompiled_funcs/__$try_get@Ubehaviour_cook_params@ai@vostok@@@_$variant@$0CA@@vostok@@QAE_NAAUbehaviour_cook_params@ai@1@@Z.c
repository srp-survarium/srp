char __thiscall vostok::variant<32>::try_get<vostok::ai::behaviour_cook_params>(
        vostok::variant<32> *this,
        vostok::ai::behaviour_cook_params *out_value)
{
  _BYTE *v2; // eax
  survarium::game_camera *v3; // ecx
  _BYTE *v4; // eax
  bool do_debug_break; // [esp+7h] [ebp-1h] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( !*v2
    || LOBYTE(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_options[2])
    || (vostok::detail::type_to_int<vostok::ai::behaviour_cook_params>::get(),
        survarium::weapon_user_dead_state::finalize(v3),
        *v4) )
  {
    out_value->behaviour_config = *(const vostok::configs::binary_config_value **)this->m_storage;
    return 1;
  }
  else
  {
    if ( `vostok::variant<32>::try_get<vostok::ai::behaviour_cook_params>'::`8'::occurances_left == -1 )
      `vostok::variant<32>::try_get<vostok::ai::behaviour_cook_params>'::`8'::occurances_left = vostok::ui::ui_dialog::input_priority((survarium::game_world *)(unsigned __int8)*v4);
    if ( `vostok::variant<32>::try_get<vostok::ai::behaviour_cook_params>'::`8'::occurances_left-- )
    {
      if ( !LOBYTE(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_options[2]) )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_options[2],
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
