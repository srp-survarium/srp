void __userpurge vostok::render::grass_world::set_wind_parameters(
        const vostok::math::float2 *dir@<eax>,
        vostok::render::grass_world *this,
        float strength)
{
  float y; // xmm0_4
  vostok::render::shader_constant_host *m_wind_info_parameters; // eax
  unsigned int v5; // ecx
  const char *m_conflicted_key_name; // esi
  int m_buffer_index; // ecx
  char src_ptr[4]; // [esp+0h] [ebp-Ch] BYREF
  float v9; // [esp+4h] [ebp-8h]
  float v10; // [esp+8h] [ebp-4h]

  *(float *)src_ptr = dir->x;
  y = dir->y;
  m_wind_info_parameters = this->m_wind_info_parameters;
  v5 = m_wind_info_parameters->m_update_markers[0];
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v9 = y;
  v10 = strength;
  if ( v5 == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 572) )
  {
    m_buffer_index = m_wind_info_parameters->m_shader_slots[0].m_buffer_index;
    if ( m_buffer_index != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_wind_info_parameters->m_shader_slots[0].m_slot_index,
        (unsigned __int8)m_wind_info_parameters->m_shader_slots[0].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 51)
                                                               + 16)
                                                   + 4 * m_buffer_index),
        src_ptr);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
}
