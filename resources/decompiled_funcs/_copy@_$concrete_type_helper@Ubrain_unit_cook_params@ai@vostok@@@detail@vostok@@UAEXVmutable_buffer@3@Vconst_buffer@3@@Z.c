void __thiscall vostok::detail::concrete_type_helper<vostok::ai::brain_unit_cook_params>::copy(
        vostok::detail::concrete_type_helper<vostok::ai::brain_unit_cook_params> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *m_data; // esi
  const vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v4; // edi

  m_data = (vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    *(_DWORD *)dest_buffer.m_data = 0;
    *((_DWORD *)dest_buffer.m_data + 1) = 0;
    *((_DWORD *)dest_buffer.m_data + 2) = 0;
    m_data = (vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)dest_buffer.m_data;
  }
  v4 = (const vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_buffer);
  m_data->m_object = v4->m_object;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
    m_data + 1,
    v4 + 1);
  m_data[2].m_object = v4[2].m_object;
}
