void __thiscall vostok::detail::concrete_type_helper<vostok::configs::binary_config_value>::copy(
        vostok::detail::concrete_type_helper<vostok::configs::binary_config_value> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  char *m_data; // esi
  vostok::sound::encoded_sound_interface *v4; // eax

  m_data = dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    *(_DWORD *)dest_buffer.m_data = 0;
    *((_DWORD *)dest_buffer.m_data + 1) = 0;
    *(_DWORD *)dest_buffer.m_data = 0;
    vostok::platform_pointer_selector<char const,1>::helper::helper(
      (vostok::platform_pointer_selector<char const ,1>::helper *)dest_buffer.m_data + 1,
      0);
    *((_DWORD *)dest_buffer.m_data + 4) = 0;
    *((_WORD *)dest_buffer.m_data + 10) = 0;
    *((_WORD *)dest_buffer.m_data + 11) = 0;
    m_data = dest_buffer.m_data;
  }
  v4 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_buffer);
  *(_DWORD *)m_data = v4->__vftable;
  *((_DWORD *)m_data + 1) = v4->type;
  *((_DWORD *)m_data + 2) = v4->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  *((_DWORD *)m_data + 3) = *((_DWORD *)&v4->vostok::resources::resource_flags + 3);
  *((_DWORD *)m_data + 4) = v4->m_reconstruction_info_actuality_tick;
  *((_WORD *)m_data + 10) = WORD2(v4->m_reconstruction_info_actuality_tick);
  *((_WORD *)m_data + 11) = HIWORD(v4->m_reconstruction_info_actuality_tick);
}
