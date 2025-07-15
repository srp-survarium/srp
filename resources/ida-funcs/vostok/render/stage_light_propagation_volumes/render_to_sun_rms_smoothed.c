void __userpurge vostok::render::stage_light_propagation_volumes::render_to_sun_rms_smoothed(
        vostok::render::stage_light_propagation_volumes *this@<ecx>,
        float a2@<ebx>,
        float a3@<ebp>,
        float a4@<edi>,
        float a5@<esi>,
        vostok::render::stage_light_propagation_volumes *sun,
        vostok::render::light *cascade_index,
        vostok::render::vector<vostok::math::float4x4> transforms,
        const unsigned int stage_render_index,
        vostok::math *num_render_stages,
        unsigned int num_render_stagesa)
{
  float m_scale; // xmm3_4
  float z; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  unsigned int v16; // xmm3_4
  unsigned int v17; // xmm0_4
  float v18; // xmm1_4
  char *v19; // eax
  double m_rsm_source_size; // st7
  vostok::math::float4x4 *v21; // eax
  vostok::math::float4x4 *M_finish; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::vector<vostok::math::float4x4> v24; // [esp+8h] [ebp-128h] BYREF
  unsigned int v25; // [esp+14h] [ebp-11Ch]
  vostok::math::float4x4 *M_start; // [esp+18h] [ebp-118h]
  vostok::math *v27; // [esp+1Ch] [ebp-114h]
  struct vostok::math::float4x4 *v28; // [esp+20h] [ebp-110h]
  float v29; // [esp+2Ch] [ebp-104h]
  float v30; // [esp+30h] [ebp-100h]
  float max_scale; // [esp+38h] [ebp-F8h]
  vostok::math::float3 local_up_in_world_space; // [esp+3Ch] [ebp-F4h] BYREF
  vostok::math::float3 adjastment; // [esp+48h] [ebp-E8h] BYREF
  float v34; // [esp+54h] [ebp-DCh]
  float v35; // [esp+58h] [ebp-D8h]
  float v36; // [esp+5Ch] [ebp-D4h]
  vostok::math::float3 v37; // [esp+60h] [ebp-D0h] BYREF
  vostok::math::float4x4 view_matrix; // [esp+6Ch] [ebp-C4h] BYREF
  vostok::math::float4x4 projection_matrix; // [esp+ACh] [ebp-84h] BYREF
  vostok::math::float4x4 result; // [esp+ECh] [ebp-44h] BYREF

  v30 = a2;
  m_scale = sun->m_radiance_volume[(int)transforms._M_impl._M_start].m_scale;
  v29 = a3;
  z = cascade_index->direction.z;
  v13 = (float)-cascade_index->direction.x * m_scale;
  v14 = (float)-cascade_index->direction.y * m_scale;
  max_scale = m_scale;
  v15 = (float)((float)((float)-z * m_scale) * 1.41421) * 2.0;
  *(float *)&v16 = sun->start_render_eye_position.x + (float)((float)(v13 * 1.41421) * 2.0);
  *(float *)&v17 = sun->start_render_eye_position.y + (float)((float)(v14 * 1.41421) * 2.0);
  v18 = sun->start_render_eye_position.z;
  v36 = *(float *)&v17;
  *(_QWORD *)&local_up_in_world_space.x = (unsigned int)clear_value;
  v34 = *(float *)&v16;
  v35 = v18 + v15;
  *(_QWORD *)&adjastment.x = __PAIR64__(v17, v16);
  adjastment.z = v18 + v15;
  local_up_in_world_space.z = 0.0;
  vostok::math::create_camera_direction(&adjastment, &cascade_index->direction, &local_up_in_world_space);
  vostok::math::create_orthographic_projection(
    (vostok::math *)LODWORD(max_scale),
    (struct vostok::math::float4x4 *)LODWORD(max_scale),
    a4,
    a5,
    a3,
    a2);
  if ( !num_render_stages )
  {
    v19 = (char *)sun + 64 * (int)transforms._M_impl._M_start;
    qmemcpy(v19 + 76, &view_matrix, 0x40u);
    qmemcpy(v19 + 332, &projection_matrix, 0x40u);
  }
  vostok::math::mul4x3(&result, &view_matrix, &projection_matrix);
  m_rsm_source_size = (double)sun->m_rsm_source_size;
  memset(&local_up_in_world_space, 0, sizeof(local_up_in_world_space));
  max_scale = m_rsm_source_size;
  vostok::render::compute_aligment(&local_up_in_world_space, (int)&adjastment, max_scale);
  *(_QWORD *)&v37.x = (unsigned int)clear_value;
  v37.z = 0.0;
  local_up_in_world_space.x = adjastment.x + v34;
  local_up_in_world_space.y = adjastment.y + v36;
  local_up_in_world_space.z = adjastment.z + v35;
  v21 = vostok::math::create_camera_direction(&local_up_in_world_space, &cascade_index->direction, &v37);
  v28 = (struct vostok::math::float4x4 *)num_render_stagesa;
  qmemcpy((void *)&view_matrix, v21, sizeof(view_matrix));
  v27 = num_render_stages;
  M_start = transforms._M_impl._M_start;
  stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>(
    (stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *)num_render_stages,
    (unsigned __int8 **)&v24._M_impl._M_finish,
    (const stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *)&transforms._M_impl._M_finish);
  v24._M_impl._M_start = &projection_matrix;
  vostok::render::stage_light_propagation_volumes::render_to_rms_smoothed2(
    (vostok::render::stage_light_propagation_volumes *)&projection_matrix,
    sun,
    (const char *)&cascade_index->color,
    COERCE_CONST_VOSTOK_MATH_FLOAT4X4_(cascade_index->intensity),
    (vostok::render::renderer_context *)&view_matrix,
    v24,
    v25,
    (unsigned int)M_start,
    (unsigned int)v27,
    (unsigned int)v28);
  M_finish = transforms._M_impl._M_finish;
  if ( transforms._M_impl._M_finish )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, (void *)M_finish);
  }
}
