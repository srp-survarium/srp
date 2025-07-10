void __thiscall vostok::detail::concrete_type_helper<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::copy(
        vostok::detail::concrete_type_helper<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  char *m_data; // eax
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *v4; // esi
  const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *v5; // eax

  m_data = dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    *(_DWORD *)dest_buffer.m_data = 0;
    m_data = dest_buffer.m_data;
  }
  v4 = (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)m_data;
  v5 = (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_buffer);
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
    v4,
    v5);
}
