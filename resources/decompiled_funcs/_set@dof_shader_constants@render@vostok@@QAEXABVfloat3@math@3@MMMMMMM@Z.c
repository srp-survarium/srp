void __userpurge vostok::render::dof_shader_constants::set(
        const vostok::math::float3 *blurriness_height_lights@<eax>,
        vostok::render::dof_shader_constants *this,
        unsigned int distance,
        unsigned int region,
        float power,
        unsigned int near_blur_amout,
        unsigned int far_blur_amout,
        unsigned int bokeh_dof_radius,
        unsigned int bokeh_dof_density)
{
  float z; // xmm0_4
  vostok::render::shader_constant_host *m_dof_height_lights; // eax
  unsigned int v11; // ecx
  const char *m_conflicted_key_name; // esi
  int m_buffer_index; // ecx
  vostok::render::shader_constant_host *m_dof_parameters; // eax
  unsigned int v15; // ecx
  int v16; // ecx
  vostok::render::shader_constant_host *m_blurriness_amount; // eax
  unsigned int v18; // ecx
  int v19; // ecx
  vostok::render::shader_constant_host *m_bokeh_dof_parameters; // eax
  unsigned int v21; // ecx
  int v22; // ecx
  unsigned __int64 src_ptr; // [esp+4h] [ebp-10h] BYREF
  float v24; // [esp+Ch] [ebp-8h]
  int v25; // [esp+10h] [ebp-4h]

  src_ptr = *(_QWORD *)&blurriness_height_lights->x;
  z = blurriness_height_lights->z;
  m_dof_height_lights = this->m_dof_height_lights;
  v11 = m_dof_height_lights->m_update_markers[1];
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v24 = z;
  v25 = 0;
  if ( v11 == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 573) )
  {
    m_buffer_index = m_dof_height_lights->m_shader_slots[1].m_buffer_index;
    if ( m_buffer_index != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_dof_height_lights->m_shader_slots[1].m_slot_index,
        (unsigned __int8)m_dof_height_lights->m_shader_slots[1].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 371)
                                                               + 16)
                                                   + 4 * m_buffer_index),
        (const char *)&src_ptr);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  m_dof_parameters = this->m_dof_parameters;
  v15 = this->m_dof_parameters->m_update_markers[1];
  src_ptr = __PAIR64__(region, distance);
  v24 = power;
  v25 = 0;
  if ( v15 == *((_DWORD *)m_conflicted_key_name + 573) )
  {
    v16 = m_dof_parameters->m_shader_slots[1].m_buffer_index;
    if ( v16 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_dof_parameters->m_shader_slots[1].m_slot_index,
        (unsigned __int8)m_dof_parameters->m_shader_slots[1].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16) + 4 * v16),
        (const char *)&src_ptr);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  m_blurriness_amount = this->m_blurriness_amount;
  v18 = m_blurriness_amount->m_update_markers[1];
  src_ptr = __PAIR64__(far_blur_amout, near_blur_amout);
  v24 = 0.0;
  v25 = 0;
  if ( v18 == *((_DWORD *)m_conflicted_key_name + 573) )
  {
    v19 = m_blurriness_amount->m_shader_slots[1].m_buffer_index;
    if ( v19 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_blurriness_amount->m_shader_slots[1].m_slot_index,
        (unsigned __int8)m_blurriness_amount->m_shader_slots[1].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16) + 4 * v19),
        (const char *)&src_ptr);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  m_bokeh_dof_parameters = this->m_bokeh_dof_parameters;
  v21 = m_bokeh_dof_parameters->m_update_markers[1];
  src_ptr = __PAIR64__(bokeh_dof_density, bokeh_dof_radius);
  v24 = 0.0;
  v25 = 0;
  if ( v21 != *((_DWORD *)m_conflicted_key_name + 573)
    || (v22 = m_bokeh_dof_parameters->m_shader_slots[1].m_buffer_index, v22 == 0xFFFF) )
  {
    ++*((_DWORD *)m_conflicted_key_name + 23);
  }
  else
  {
    vostok::render::shader_constant_buffer::set_memory(
      m_bokeh_dof_parameters->m_shader_slots[1].m_slot_index,
      (unsigned __int8)m_bokeh_dof_parameters->m_shader_slots[1].m_class_id,
      *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16) + 4 * v22),
      (const char *)&src_ptr);
    ++*((_DWORD *)m_conflicted_key_name + 23);
  }
}
