char __thiscall vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>(
        vostok::variant<32> *this,
        vostok::render::static_model_instance_user_data *out_value)
{
  unsigned int v3; // eax
  vostok::render::static_model_instance_user_data *v5; // eax

  if ( `vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>'::`5'::debug_macro_helper_ignore_always
    || this->m_type_id == vostok::detail::type_to_int<vostok::render::static_model_instance_user_data>::get() )
  {
    v5 = out_value;
    out_value->config = *(const vostok::configs::binary_config_value **)this->m_storage;
    v5->sound_world = *(vostok::sound::world **)&this->m_storage[4];
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
      &v5->sound_scene,
      (const vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_storage[8]);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>'::`5'::debug_macro_helper_ignore_always )
      {
        LOBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value,
          process_error_false,
          &`vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>'::`5'::debug_macro_helper_ignore_always,
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
