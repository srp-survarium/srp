void __userpurge vostok::render::scene_shader_constants::set(
        vostok::render::scene_shader_constants *this@<edi>,
        const vostok::math::float3 *height_lights@<ecx>,
        const vostok::math::float3 *fade_color@<eax>,
        const vostok::math::float3 *context,
        const vostok::math::float3 *mid_tones,
        const vostok::math::float3 *shadows,
        float fade_amount,
        float gamma_correction_factor,
        const vostok::math::float3 *desaturation,
        const vostok::render::post_process_parameters *image_grain_parameters,
        const vostok::render::post_process_parameters *parameters)
{
  float z; // xmm0_4
  vostok::render::shader_constant_host *m_frame_height_lights_and_desaturation_parameters; // eax
  unsigned int v13; // ecx
  const vostok::math::float4 *v14; // ebx
  vostok::render::constants_handler<1> *m_conflicted_key_name; // esi
  int m_buffer_index; // ecx
  vostok::render::shader_constant_host *m_gamma_correction_factor; // eax
  int v18; // ecx
  vostok::render::shader_constant_host *m_scene_fade_parameters; // eax
  int v20; // ecx
  vostok::render::shader_constant_host *m_filmic_tonemap_packed_parameters_0; // eax
  unsigned int v22; // ecx
  int v23; // ecx
  vostok::render::shader_constant_host *m_filmic_tonemap_packed_parameters_1; // eax
  unsigned int v25; // ecx
  int v26; // ecx
  const vostok::math::float3 *v27; // edx
  vostok::math::float4 frame_height_lights_and_desaturation; // [esp+8h] [ebp-20h] BYREF
  vostok::math::float4 scene_fade; // [esp+18h] [ebp-10h] BYREF

  *(_QWORD *)&frame_height_lights_and_desaturation.x = *(_QWORD *)&height_lights->x;
  frame_height_lights_and_desaturation.z = height_lights->z;
  frame_height_lights_and_desaturation.w = gamma_correction_factor;
  *(_QWORD *)&scene_fade.x = *(_QWORD *)&fade_color->x;
  z = fade_color->z;
  m_frame_height_lights_and_desaturation_parameters = this->m_frame_height_lights_and_desaturation_parameters;
  v13 = this->m_frame_height_lights_and_desaturation_parameters->m_update_markers[1];
  v14 = (const vostok::math::float4 *)image_grain_parameters;
  m_conflicted_key_name = (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *(_QWORD *)&scene_fade.elements[2] = __PAIR64__((unsigned int)shadows, LODWORD(z));
  if ( v13 == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 573) )
  {
    m_buffer_index = m_frame_height_lights_and_desaturation_parameters->m_shader_slots[1].m_buffer_index;
    if ( m_buffer_index != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_frame_height_lights_and_desaturation_parameters->m_shader_slots[1].m_slot_index,
        (unsigned __int8)m_frame_height_lights_and_desaturation_parameters->m_shader_slots[1].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 371)
                                                               + 16)
                                                   + 4 * m_buffer_index),
        (const char *)&frame_height_lights_and_desaturation);
  }
  ++m_conflicted_key_name[7].m_current.m_object;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_scene_mid_tones_parameters,
    m_conflicted_key_name + 123,
    context);
  ++m_conflicted_key_name[7].m_current.m_object;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_scene_shadows_parameters,
    m_conflicted_key_name + 123,
    mid_tones);
  ++m_conflicted_key_name[7].m_current.m_object;
  m_gamma_correction_factor = this->m_gamma_correction_factor;
  if ( m_gamma_correction_factor->m_update_markers[1] == m_conflicted_key_name[191].m_diff_range_start )
  {
    v18 = m_gamma_correction_factor->m_shader_slots[1].m_buffer_index;
    if ( v18 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_gamma_correction_factor->m_shader_slots[1].m_slot_index,
        (unsigned __int8)m_gamma_correction_factor->m_shader_slots[1].m_class_id,
        m_conflicted_key_name[123].m_current.m_object->m_const_buffers._M_impl._M_start[v18].m_object,
        (const char *)&fade_amount);
  }
  ++m_conflicted_key_name[7].m_current.m_object;
  m_scene_fade_parameters = this->m_scene_fade_parameters;
  if ( m_scene_fade_parameters->m_update_markers[1] == m_conflicted_key_name[191].m_diff_range_start )
  {
    v20 = m_scene_fade_parameters->m_shader_slots[1].m_buffer_index;
    if ( v20 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_scene_fade_parameters->m_shader_slots[1].m_slot_index,
        (unsigned __int8)m_scene_fade_parameters->m_shader_slots[1].m_class_id,
        m_conflicted_key_name[123].m_current.m_object->m_const_buffers._M_impl._M_start[v20].m_object,
        (const char *)&scene_fade);
  }
  ++m_conflicted_key_name[7].m_current.m_object;
  m_filmic_tonemap_packed_parameters_0 = this->m_filmic_tonemap_packed_parameters_0;
  v22 = m_filmic_tonemap_packed_parameters_0->m_update_markers[1];
  scene_fade = *(const vostok::math::float4 *)((char *)v14 + 572);
  if ( v22 == m_conflicted_key_name[191].m_diff_range_start )
  {
    v23 = m_filmic_tonemap_packed_parameters_0->m_shader_slots[1].m_buffer_index;
    if ( v23 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_filmic_tonemap_packed_parameters_0->m_shader_slots[1].m_slot_index,
        (unsigned __int8)m_filmic_tonemap_packed_parameters_0->m_shader_slots[1].m_class_id,
        m_conflicted_key_name[123].m_current.m_object->m_const_buffers._M_impl._M_start[v23].m_object,
        (const char *)&scene_fade);
  }
  ++m_conflicted_key_name[7].m_current.m_object;
  m_filmic_tonemap_packed_parameters_1 = this->m_filmic_tonemap_packed_parameters_1;
  v25 = m_filmic_tonemap_packed_parameters_1->m_update_markers[1];
  *(_QWORD *)&scene_fade.x = *(_QWORD *)&v14[36].elements[3];
  scene_fade.z = v14[37].y;
  scene_fade.w = v14[4].y;
  if ( v25 == m_conflicted_key_name[191].m_diff_range_start )
  {
    v26 = m_filmic_tonemap_packed_parameters_1->m_shader_slots[1].m_buffer_index;
    if ( v26 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_filmic_tonemap_packed_parameters_1->m_shader_slots[1].m_slot_index,
        (unsigned __int8)m_filmic_tonemap_packed_parameters_1->m_shader_slots[1].m_class_id,
        m_conflicted_key_name[123].m_current.m_object->m_const_buffers._M_impl._M_start[v26].m_object,
        (const char *)&scene_fade);
  }
  v27 = desaturation;
  ++m_conflicted_key_name[7].m_current.m_object;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_image_grain_parameters,
    m_conflicted_key_name + 123,
    v27);
  ++m_conflicted_key_name[7].m_current.m_object;
}
