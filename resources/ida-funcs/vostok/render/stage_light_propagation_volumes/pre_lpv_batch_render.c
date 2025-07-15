void __thiscall vostok::render::stage_light_propagation_volumes::pre_lpv_batch_render(
        vostok::render::stage_light_propagation_volumes *this,
        const vostok::math::float3 *light_color,
        float light_intensity,
        const vostok::render::geometry_batch *batch)
{
  vostok::render::res_effect *m_object; // eax
  int v6; // ecx
  const vostok::math::float4x4 *v7; // eax
  const char *m_conflicted_key_name; // esi
  vostok::render::shader_constant_host *m_c_light_intensity; // eax
  int m_buffer_index; // ecx
  unsigned int v11; // [esp+0h] [ebp-50h]
  vostok::math::float4x4 v12; // [esp+10h] [ebp-40h] BYREF

  m_object = this->m_fill_rsm_effect[1].m_object;
  v6 = m_object->m_techniques._M_impl._M_finish - m_object->m_techniques._M_impl._M_start;
  if ( v6 )
  {
    m_object->m_cur_technique = 0;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v6, v11);
  }
  v7 = vostok::math::float4x4::identity(&v12);
  vostok::render::renderer_context::set_w(this->m_context, v7);
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_c_light_color,
    (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
  + 123,
    light_color);
  ++*((_DWORD *)m_conflicted_key_name + 23);
  m_c_light_intensity = this->m_c_light_intensity;
  if ( m_c_light_intensity->m_update_markers[1] == *((_DWORD *)m_conflicted_key_name + 573) )
  {
    m_buffer_index = m_c_light_intensity->m_shader_slots[1].m_buffer_index;
    if ( m_buffer_index != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_c_light_intensity->m_shader_slots[1].m_slot_index,
        (unsigned __int8)m_c_light_intensity->m_shader_slots[1].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16)
                                                   + 4 * m_buffer_index),
        (const char *)&light_intensity);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
}
