char __thiscall vostok::variant<32>::try_get<survarium::animation_analysis_result_cook_user_data>(
        vostok::variant<32> *this,
        survarium::animation_analysis_result_cook_user_data *out_value)
{
  _BYTE *v2; // eax
  survarium::game_camera *v3; // ecx
  _BYTE *v4; // eax
  bool do_debug_break; // [esp+1Bh] [ebp-1h] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( !*v2
    || `vostok::variant<32>::try_get<survarium::animation_analysis_result_cook_user_data>'::`5'::debug_macro_helper_ignore_always
    || (vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::get(),
        survarium::weapon_user_dead_state::finalize(v3),
        *v4) )
  {
    out_value->legs_count = *(_DWORD *)this->m_storage;
    out_value->legs = *(const survarium::leg_info **)&this->m_storage[4];
    out_value->skeleton = *(vostok::animation::skeleton **)&this->m_storage[8];
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
      &out_value->animation,
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&this->m_storage[12]);
    return 1;
  }
  else
  {
    if ( `vostok::variant<32>::try_get<survarium::animation_analysis_result_cook_user_data>'::`8'::occurances_left == -1 )
      `vostok::variant<32>::try_get<survarium::animation_analysis_result_cook_user_data>'::`8'::occurances_left = vostok::ui::ui_dialog::input_priority((survarium::game_world *)(unsigned __int8)*v4);
    if ( `vostok::variant<32>::try_get<survarium::animation_analysis_result_cook_user_data>'::`8'::occurances_left-- )
    {
      if ( !`vostok::variant<32>::try_get<survarium::animation_analysis_result_cook_user_data>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::variant<32>::try_get<survarium::animation_analysis_result_cook_user_data>'::`5'::debug_macro_helper_ignore_always,
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
