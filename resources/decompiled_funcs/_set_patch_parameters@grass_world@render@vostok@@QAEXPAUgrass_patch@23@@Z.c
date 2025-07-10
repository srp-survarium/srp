void __userpurge vostok::render::grass_world::set_patch_parameters(
        vostok::render::grass_patch *patch@<eax>,
        vostok::render::grass_world *this)
{
  float z; // xmm0_4
  vostok::render::shader_constant_host *m_patch_parameters; // eax
  unsigned int v4; // ecx
  const char *m_conflicted_key_name; // esi
  int m_buffer_index; // ecx
  __int64 src_ptr; // [esp+0h] [ebp-10h] BYREF
  float v8; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]

  src_ptr = *(_QWORD *)&patch->m_origin.x;
  z = patch->m_origin.z;
  m_patch_parameters = this->m_patch_parameters;
  v4 = m_patch_parameters->m_update_markers[0];
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v8 = z;
  v9 = 1098907648;
  if ( v4 == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 572) )
  {
    m_buffer_index = m_patch_parameters->m_shader_slots[0].m_buffer_index;
    if ( m_buffer_index != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_patch_parameters->m_shader_slots[0].m_slot_index,
        (unsigned __int8)m_patch_parameters->m_shader_slots[0].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 51)
                                                               + 16)
                                                   + 4 * m_buffer_index),
        (const char *)&src_ptr);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
}
