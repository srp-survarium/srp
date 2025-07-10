char __thiscall vostok::variant<32>::try_get<vostok::sound::sound_collection_cook_user_data>(
        vostok::variant<32> *this,
        vostok::sound::sound_collection_cook_user_data *out_value)
{
  vostok::configs::binary_config **v4; // eax
  vostok::configs::binary_config *v6; // [esp+18h] [ebp-1Ch]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> v7; // [esp+2Ch] [ebp-8h] BYREF
  bool v8; // [esp+31h] [ebp-3h]
  char v9; // [esp+32h] [ebp-2h]
  bool do_debug_break; // [esp+33h] [ebp-1h] BYREF

  v9 = 1;
  if ( `vostok::variant<32>::try_get<vostok::sound::sound_collection_cook_user_data>'::`5'::debug_macro_helper_ignore_always
    || (v8 = this->m_type_id == vostok::detail::type_to_int<vostok::sound::sound_collection_cook_user_data>::get()) )
  {
    out_value->val = *(const vostok::configs::binary_config_value **)this->m_storage;
    boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      &v7,
      (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&this->m_storage[4]);
    v6 = *v4;
    *v4 = out_value->cfg_ptr.m_object;
    out_value->cfg_ptr.m_object = v6;
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&v7);
    return 1;
  }
  else
  {
    if ( `vostok::variant<32>::try_get<vostok::sound::sound_collection_cook_user_data>'::`8'::occurances_left == -1 )
      `vostok::variant<32>::try_get<vostok::sound::sound_collection_cook_user_data>'::`8'::occurances_left = 10;
    if ( `vostok::variant<32>::try_get<vostok::sound::sound_collection_cook_user_data>'::`8'::occurances_left-- )
    {
      if ( !`vostok::variant<32>::try_get<vostok::sound::sound_collection_cook_user_data>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::variant<32>::try_get<vostok::sound::sound_collection_cook_user_data>'::`5'::debug_macro_helper_ignore_always,
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
