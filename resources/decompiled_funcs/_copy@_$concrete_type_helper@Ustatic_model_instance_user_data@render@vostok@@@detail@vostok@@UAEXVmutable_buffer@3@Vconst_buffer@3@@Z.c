void __thiscall vostok::detail::concrete_type_helper<vostok::render::static_model_instance_user_data>::copy(
        vostok::detail::concrete_type_helper<vostok::render::static_model_instance_user_data> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *m_data; // esi
  const vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v4; // eax

  m_data = (vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    *((_DWORD *)dest_buffer.m_data + 2) = 0;
    m_data = (vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)dest_buffer.m_data;
  }
  v4 = (const vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_buffer);
  m_data->m_object = v4->m_object;
  m_data[1].m_object = v4[1].m_object;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
    m_data + 2,
    v4 + 2);
}
