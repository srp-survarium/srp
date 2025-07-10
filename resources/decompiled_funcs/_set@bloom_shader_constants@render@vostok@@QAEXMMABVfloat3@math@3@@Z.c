void __userpurge vostok::render::bloom_shader_constants::set(
        vostok::render::bloom_shader_constants *this@<ecx>,
        float a2@<xmm0>,
        vostok::render::bloom_shader_constants *const thisa,
        unsigned int bloom_max_color,
        const struct vostok::math::float3 *halo_color)
{
  vostok::render::shader_constant_host *m_bloom_parameters; // eax
  unsigned int v6; // ecx
  const char *m_conflicted_key_name; // esi
  int m_buffer_index; // ecx
  vostok::render::shader_constant_host *m_bloom_parameters1; // eax
  unsigned int v10; // ecx
  int v11; // ecx
  vostok::math::float4 bloom_parameters; // [esp+Ch] [ebp-10h] BYREF

  m_bloom_parameters = thisa->m_bloom_parameters;
  v6 = thisa->m_bloom_parameters->m_update_markers[1];
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  bloom_parameters.x = a2;
  *(_QWORD *)&bloom_parameters.elements[1] = bloom_max_color;
  bloom_parameters.w = 0.0;
  if ( v6 == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 573) )
  {
    m_buffer_index = m_bloom_parameters->m_shader_slots[1].m_buffer_index;
    if ( m_buffer_index != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_bloom_parameters->m_shader_slots[1].m_slot_index,
        (unsigned __int8)m_bloom_parameters->m_shader_slots[1].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 371)
                                                               + 16)
                                                   + 4 * m_buffer_index),
        (const char *)&bloom_parameters);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  m_bloom_parameters1 = thisa->m_bloom_parameters1;
  v10 = m_bloom_parameters1->m_update_markers[1];
  *(_QWORD *)&bloom_parameters.x = *(_QWORD *)&halo_color->x;
  bloom_parameters.z = halo_color->z;
  LODWORD(bloom_parameters.w) = clear_value;
  if ( v10 != *((_DWORD *)m_conflicted_key_name + 573)
    || (v11 = m_bloom_parameters1->m_shader_slots[1].m_buffer_index, v11 == 0xFFFF) )
  {
    ++*((_DWORD *)m_conflicted_key_name + 23);
  }
  else
  {
    vostok::render::shader_constant_buffer::set_memory(
      m_bloom_parameters1->m_shader_slots[1].m_slot_index,
      (unsigned __int8)m_bloom_parameters1->m_shader_slots[1].m_class_id,
      *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16) + 4 * v11),
      (const char *)&bloom_parameters);
    ++*((_DWORD *)m_conflicted_key_name + 23);
  }
}
