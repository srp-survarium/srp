void __userpurge vostok::render::decal_shader_constants_and_geometry::set(
        vostok::render::decal_shader_constants_and_geometry *this@<edi>,
        const vostok::math::float4x4 *world_to_decal_matrix@<eax>,
        vostok::render::renderer_context *context,
        const vostok::math::float4x4 *decal_tangent_to_view_space_matrix,
        float alpha_angle,
        float clip_angle,
        const vostok::math::float3 *decal_width_height_far_distance,
        const vostok::math::float4x4 *decal_transform)
{
  const vostok::math::float3 *v8; // eax
  const char *m_conflicted_key_name; // esi
  vostok::render::constants_handler<1> *v10; // ebx
  const vostok::math::float3 *v11; // eax
  vostok::render::shader_constant_host *m_decal_angle_parameters; // eax
  unsigned int v13; // ecx
  int m_buffer_index; // ecx
  char src_ptr[4]; // [esp+10h] [ebp-94h] BYREF
  float v16; // [esp+14h] [ebp-90h]
  int v17; // [esp+18h] [ebp-8Ch]
  int v18; // [esp+1Ch] [ebp-88h]
  vostok::math::float4x4 result; // [esp+20h] [ebp-84h] BYREF
  vostok::math::float4x4 v20; // [esp+60h] [ebp-44h] BYREF

  v8 = (const vostok::math::float3 *)vostok::math::transpose(&result, world_to_decal_matrix);
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v10 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                               + 1476);
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_world_to_decal_parameter,
    (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
  + 123,
    v8);
  ++*((_DWORD *)m_conflicted_key_name + 23);
  v11 = (const vostok::math::float3 *)vostok::math::transpose(&v20, decal_tangent_to_view_space_matrix);
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_decal_tangent_to_view_space_matrix_parameter,
    v10,
    v11);
  ++*((_DWORD *)m_conflicted_key_name + 23);
  m_decal_angle_parameters = this->m_decal_angle_parameters;
  v13 = m_decal_angle_parameters->m_update_markers[1];
  *(float *)src_ptr = alpha_angle;
  v16 = clip_angle;
  v17 = 0;
  v18 = 0;
  if ( v13 == *((_DWORD *)m_conflicted_key_name + 573) )
  {
    m_buffer_index = m_decal_angle_parameters->m_shader_slots[1].m_buffer_index;
    if ( m_buffer_index != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_decal_angle_parameters->m_shader_slots[1].m_slot_index,
        (unsigned __int8)m_decal_angle_parameters->m_shader_slots[1].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16)
                                                   + 4 * m_buffer_index),
        src_ptr);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_eye_ray_corner_parameter,
    v10,
    context->m_eye_rays);
  ++*((_DWORD *)m_conflicted_key_name + 23);
}
