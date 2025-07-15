void __userpurge vostok::render::stage_light_propagation_volumes::set_rsm_contants(
        vostok::render::stage_light_propagation_volumes *this@<edi>,
        const vostok::math::float3 *grid_origin@<eax>,
        const vostok::math::float3 *light_direction,
        float grid_scale)
{
  const char *m_conflicted_key_name; // esi
  vostok::render::constants_handler<1> *v5; // ebp
  vostok::render::shader_constant_host *m_c_grid_cell_size; // eax
  unsigned int v7; // edx
  int m_buffer_index; // ecx
  vostok::render::shader_constant_host *m_c_invert_rsm_size; // eax
  unsigned int v10; // ecx
  int v11; // ecx

  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v5 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                              + 1476);
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_c_grid_origin,
    (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
  + 123,
    grid_origin);
  ++*((_DWORD *)m_conflicted_key_name + 23);
  m_c_grid_cell_size = this->m_c_grid_cell_size;
  v7 = m_c_grid_cell_size->m_update_markers[1];
  grid_scale = grid_scale / (double)this->m_grid_size;
  if ( v7 == *((_DWORD *)m_conflicted_key_name + 573) )
  {
    m_buffer_index = m_c_grid_cell_size->m_shader_slots[1].m_buffer_index;
    if ( m_buffer_index != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_c_grid_cell_size->m_shader_slots[1].m_slot_index,
        (unsigned __int8)m_c_grid_cell_size->m_shader_slots[1].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16)
                                                   + 4 * m_buffer_index),
        (const char *)&grid_scale);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  m_c_invert_rsm_size = this->m_c_invert_rsm_size;
  v10 = m_c_invert_rsm_size->m_update_markers[1];
  grid_scale = 1.0 / (double)this->m_rsm_downsampled_size;
  if ( v10 == *((_DWORD *)m_conflicted_key_name + 573) )
  {
    v11 = m_c_invert_rsm_size->m_shader_slots[1].m_buffer_index;
    if ( v11 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_c_invert_rsm_size->m_shader_slots[1].m_slot_index,
        (unsigned __int8)m_c_invert_rsm_size->m_shader_slots[1].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16) + 4 * v11),
        (const char *)&grid_scale);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_c_light_direction,
    v5,
    light_direction);
  ++*((_DWORD *)m_conflicted_key_name + 23);
}
