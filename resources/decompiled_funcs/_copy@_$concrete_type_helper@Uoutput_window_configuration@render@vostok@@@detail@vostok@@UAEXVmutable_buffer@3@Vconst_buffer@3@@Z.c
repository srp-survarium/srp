void __thiscall vostok::detail::concrete_type_helper<vostok::render::output_window_configuration>::copy(
        vostok::detail::concrete_type_helper<vostok::render::output_window_configuration> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  char *m_data; // eax
  char *v4; // esi
  vostok::sound::encoded_sound_interface *v5; // eax

  m_data = dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    *(_DWORD *)dest_buffer.m_data = 0;
    *((_DWORD *)dest_buffer.m_data + 1) = 0;
    *((_DWORD *)dest_buffer.m_data + 2) = 0;
    dest_buffer.m_data[12] = 0;
    dest_buffer.m_data[13] = 1;
    *((_DWORD *)dest_buffer.m_data + 4) = 0;
    m_data = dest_buffer.m_data;
  }
  v4 = m_data;
  v5 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_buffer);
  *(vostok::vfs::vfs_association *)v4 = v5->vostok::vfs::vfs_association;
  *((_QWORD *)v4 + 1) = *(_QWORD *)&v5->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  *((_DWORD *)v4 + 4) = v5->m_reconstruction_info_actuality_tick;
}
