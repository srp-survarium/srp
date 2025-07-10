void __userpurge vostok::render::stage_light_propagation_volumes::render_to_sun_rms(
        vostok::render::stage_light_propagation_volumes *this@<ecx>,
        float a2@<ebx>,
        float a3@<ebp>,
        float a4@<edi>,
        float a5@<esi>,
        vostok::render::stage_light_propagation_volumes *sun,
        vostok::render::light *cascade_index,
        vostok::render::vector<vostok::math::float4x4> transforms,
        int transforms_8)
{
  float m_scale; // xmm0_4
  vostok::render::renderer_context *m_context; // eax
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v14; // xmm5_4
  float v15; // xmm1_4
  float v16; // xmm6_4
  float v17; // xmm2_4
  float v18; // xmm7_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  const vostok::math::float4x4 *orthographic_projection; // eax
  double m_rsm_source_size; // st7
  vostok::math::float4x4 *v27; // eax
  vostok::math::float4x4 *M_finish; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::vector<vostok::math::float4x4> v30; // [esp+8h] [ebp-120h] BYREF
  vostok::math *v31; // [esp+14h] [ebp-114h]
  struct vostok::math::float4x4 *M_start; // [esp+18h] [ebp-110h]
  float v33; // [esp+1Ch] [ebp-10Ch]
  float v34; // [esp+20h] [ebp-108h]
  float v35; // [esp+24h] [ebp-104h]
  float v36; // [esp+28h] [ebp-100h]
  float max_scale; // [esp+30h] [ebp-F8h]
  vostok::math::float3 local_up_in_world_space; // [esp+34h] [ebp-F4h] BYREF
  vostok::math::float3 adjastment; // [esp+40h] [ebp-E8h] BYREF
  float v40; // [esp+4Ch] [ebp-DCh]
  float v41; // [esp+50h] [ebp-D8h]
  float v42; // [esp+54h] [ebp-D4h]
  vostok::math::float3 v43; // [esp+58h] [ebp-D0h] BYREF
  vostok::math::float4x4 view_matrix; // [esp+64h] [ebp-C4h] BYREF
  vostok::math::float4x4 projection_matrix; // [esp+A4h] [ebp-84h] BYREF
  vostok::math::float4x4 result; // [esp+E4h] [ebp-44h] BYREF

  v36 = a2;
  m_scale = sun->m_radiance_volume[(int)transforms._M_impl._M_start].m_scale;
  m_context = sun->m_context;
  v35 = a3;
  x = cascade_index->direction.x;
  y = cascade_index->direction.y;
  z = cascade_index->direction.z;
  v34 = a5;
  v33 = a4;
  v14 = (float)((float)(x * m_scale) * 1.41421) * 2.0;
  v15 = m_context->m_view_dir.x;
  v16 = (float)((float)(y * m_scale) * 1.41421) * 2.0;
  v17 = m_context->m_view_dir.y;
  v18 = (float)((float)(z * m_scale) * 1.41421) * 2.0;
  v19 = m_context->m_view_dir.z;
  max_scale = m_scale;
  v20 = (float)(v17 * 0.2) * m_scale;
  v21 = (float)(v19 * 0.2) * m_scale;
  v22 = m_context->m_view_pos.x + (float)((float)(v15 * 0.2) * m_scale);
  v23 = m_context->m_view_pos.y + v20;
  v24 = m_context->m_view_pos.z;
  v40 = v22 - v14;
  adjastment.x = v22 - v14;
  *(_QWORD *)&local_up_in_world_space.x = (unsigned int)clear_value;
  v42 = v23 - v16;
  v41 = (float)(v24 + v21) - v18;
  adjastment.y = v23 - v16;
  adjastment.z = v41;
  local_up_in_world_space.z = 0.0;
  vostok::math::create_camera_direction(&adjastment, &cascade_index->direction, &local_up_in_world_space);
  *(float *)&M_start = max_scale * 0.5;
  orthographic_projection = vostok::math::create_orthographic_projection(
                              (vostok::math *)M_start,
                              M_start,
                              a4,
                              a5,
                              a3,
                              a2);
  vostok::math::mul4x3(&result, &view_matrix, orthographic_projection);
  m_rsm_source_size = (double)sun->m_rsm_source_size;
  memset(&local_up_in_world_space, 0, sizeof(local_up_in_world_space));
  max_scale = m_rsm_source_size;
  vostok::render::compute_aligment(&local_up_in_world_space, (int)&adjastment, max_scale);
  *(_QWORD *)&v43.x = (unsigned int)clear_value;
  v43.z = 0.0;
  local_up_in_world_space.x = adjastment.x + v40;
  local_up_in_world_space.y = adjastment.y + v42;
  local_up_in_world_space.z = adjastment.z + v41;
  v27 = vostok::math::create_camera_direction(&local_up_in_world_space, &cascade_index->direction, &v43);
  M_start = transforms._M_impl._M_start;
  qmemcpy((void *)&view_matrix, v27, sizeof(view_matrix));
  stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>(
    0,
    (unsigned __int8 **)&v30._M_impl._M_finish,
    (const stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *)&transforms._M_impl._M_finish);
  v30._M_impl._M_start = &projection_matrix;
  vostok::render::stage_light_propagation_volumes::render_to_rms(
    (vostok::render::stage_light_propagation_volumes *)&projection_matrix,
    sun,
    &cascade_index->color,
    COERCE_VOSTOK_RENDER_RENDER_SURFACE_INSTANCE_(cascade_index->intensity),
    (vostok::render::renderer_context *)&view_matrix,
    v30,
    (const unsigned int)v31,
    (unsigned int)M_start);
  M_finish = transforms._M_impl._M_finish;
  if ( transforms._M_impl._M_finish )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, (void *)M_finish);
  }
}
