void __thiscall vostok::detail::concrete_type_helper<vostok::ai::behaviour_cook_params>::copy(
        vostok::detail::concrete_type_helper<vostok::ai::behaviour_cook_params> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  char *m_data; // eax

  m_data = dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    *(_DWORD *)dest_buffer.m_data = 0;
    m_data = dest_buffer.m_data;
  }
  *(_DWORD *)m_data = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_buffer)->__vftable;
}
