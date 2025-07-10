void __thiscall vostok::detail::concrete_type_helper<vostok::animation::animation_collection_cook_user_data>::copy(
        vostok::detail::concrete_type_helper<vostok::animation::animation_collection_cook_user_data> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *m_data; // esi
  const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *v4; // eax

  m_data = (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    *((_DWORD *)dest_buffer.m_data + 1) = 0;
    m_data = (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)dest_buffer.m_data;
  }
  v4 = (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_buffer);
  m_data->m_object = v4->m_object;
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
    m_data + 1,
    v4 + 1);
}
