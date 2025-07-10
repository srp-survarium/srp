void __thiscall vostok::detail::concrete_type_helper<vostok::render::scene_configuration>::copy(
        vostok::detail::concrete_type_helper<vostok::render::scene_configuration> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  char *m_data; // eax

  m_data = dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    *dest_buffer.m_data &= 0x80u;
    m_data = dest_buffer.m_data;
  }
  *m_data = (char)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_buffer)->__vftable;
}
