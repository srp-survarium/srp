void __userpurge vostok::render::stage_light_propagation_volumes::render_to_sky_rms(
        vostok::render::stage_light_propagation_volumes *this@<ecx>,
        float a2@<edi>,
        float a3@<esi>,
        vostok::render::stage_light_propagation_volumes *sun,
        unsigned int face_index,
        float cascade_index,
        vostok::render::vector<vostok::math::float4x4> transforms)
{
  float v7; // ebx
  __int64 v8; // xmm0_8
  float v9; // eax
  float x; // xmm2_4
  float z; // xmm1_4
  vostok::math::float4x4 *v12; // eax
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  unsigned int v16; // xmm2_4
  unsigned int v17; // xmm4_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm7_4
  float v21; // xmm2_4
  unsigned int v22; // xmm1_4
  float v23; // xmm2_4
  const vostok::math::float4x4 *orthographic_projection; // eax
  double m_rsm_source_size; // st7
  vostok::math::float4x4 *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::vector<vostok::math::float4x4> v28; // [esp+8h] [ebp-138h] BYREF
  vostok::math *v29; // [esp+14h] [ebp-12Ch]
  float _X; // [esp+18h] [ebp-128h]
  float v31; // [esp+1Ch] [ebp-124h]
  float v32; // [esp+20h] [ebp-120h]
  float v33; // [esp+24h] [ebp-11Ch]
  float v34; // [esp+28h] [ebp-118h]
  vostok::math::float3 up; // [esp+2Ch] [ebp-114h] BYREF
  float v36; // [esp+38h] [ebp-108h]
  float v37; // [esp+3Ch] [ebp-104h]
  unsigned int v38; // [esp+40h] [ebp-100h]
  float v39; // [esp+44h] [ebp-FCh]
  float max_scale; // [esp+48h] [ebp-F8h]
  vostok::math::float3 direction; // [esp+4Ch] [ebp-F4h] BYREF
  vostok::math::float3 sky_position; // [esp+58h] [ebp-E8h] BYREF
  vostok::math::float3 adjastment; // [esp+64h] [ebp-DCh] BYREF
  vostok::math::float3 light_color; // [esp+70h] [ebp-D0h] BYREF
  vostok::math::float4x4 sun_rotation; // [esp+7Ch] [ebp-C4h] BYREF
  vostok::math::float4x4 projection_matrix; // [esp+BCh] [ebp-84h] BYREF
  vostok::math::float4x4 result; // [esp+FCh] [ebp-44h] BYREF

  v7 = *(float *)&sun->m_context;
  v8 = *(_QWORD *)(16 * face_index + *(_DWORD *)(LODWORD(v7) + 12392) + 664);
  light_color.z = *(float *)(16 * face_index + *(_DWORD *)(LODWORD(v7) + 12392) + 672);
  v9 = *(float *)&sun->m_radiance_volume;
  *(_QWORD *)&light_color.x = v8;
  LODWORD(v8) = *(_DWORD *)(476 * LODWORD(cascade_index) + LODWORD(v9) + 192);
  v32 = a3;
  max_scale = *(float *)&v8;
  v31 = a2;
  if ( this )
  {
    x = this->m_previous_view_matrix[1].k.x;
    *(_QWORD *)&direction.elements[1] = (unsigned int)clear_value;
    z = this->m_previous_view_matrix[1].j.z;
    direction.x = 0.0;
    *(_QWORD *)&up.x = LODWORD(z);
    up.z = x;
    v12 = vostok::math::create_rotation(&up, &direction, &result);
  }
  else
  {
    v12 = vostok::math::float4x4::identity(&projection_matrix);
  }
  v13 = *(&sky_light_matrix_parameters[0][1].z + 9 * face_index);
  v14 = *(&sky_light_matrix_parameters[0][1].y + 9 * face_index);
  v15 = sky_light_matrix_parameters[face_index][1].x;
  qmemcpy((void *)&sun_rotation, v12, sizeof(sun_rotation));
  up.z = (float)((float)(sun_rotation.i.z * v15) + (float)(sun_rotation.j.z * v14)) + (float)(sun_rotation.k.z * v13);
  up.y = (float)((float)(sun_rotation.k.y * v13) + (float)(sun_rotation.i.y * v15)) + (float)(sun_rotation.j.y * v14);
  up.x = (float)((float)(sun_rotation.k.x * v13) + (float)(sun_rotation.j.x * v14)) + (float)(sun_rotation.i.x * v15);
  v36 = sqrtf((float)((float)(up.z * up.z) + (float)(up.y * up.y)) + (float)(up.x * up.x));
  *(float *)&v16 = up.x * (float)(*(float *)&clear_value / v36);
  *(float *)&v17 = up.y * (float)(*(float *)&clear_value / v36);
  v38 = v17;
  v36 = up.z * (float)(*(float *)&clear_value / v36);
  direction.z = v36;
  up.x = *(float *)&v17 - v36;
  v39 = *(float *)&v16;
  *(_QWORD *)&direction.x = __PAIR64__(v17, v16);
  up.y = v36 - *(float *)&v16;
  up.z = *(float *)&v16 - *(float *)&v17;
  v37 = sqrtf(
          (float)((float)((float)(*(float *)&v17 - v36) * (float)(*(float *)&v17 - v36)) + (float)(up.z * up.z))
        + (float)(up.y * up.y));
  v18 = up.y * (float)(*(float *)&clear_value / v37);
  v19 = (float)(v18 * v36) - (float)((float)(up.z * (float)(*(float *)&clear_value / v37)) * *(float *)&v38);
  v20 = up.x * (float)(*(float *)&clear_value / v37);
  up.x = v19;
  v21 = (float)((float)(up.z * (float)(*(float *)&clear_value / v37)) * v39) - (float)(v20 * v36);
  up.y = v21;
  up.z = (float)(v20 * *(float *)&v38) - (float)(v18 * v39);
  v37 = sqrtf((float)((float)(v19 * v19) + (float)(up.z * up.z)) + (float)(v21 * v21));
  up.x = up.x * (float)(*(float *)&clear_value / v37);
  up.y = up.y * (float)(*(float *)&clear_value / v37);
  up.z = up.z * (float)(*(float *)&clear_value / v37);
  *(float *)&v22 = *(float *)(LODWORD(v7) + 16904)
                 - (float)((float)((float)(*(float *)&v38 * max_scale) * 1.41421) * 2.0);
  v23 = *(float *)(LODWORD(v7) + 16908) - (float)((float)((float)(v36 * max_scale) * 1.41421) * 2.0);
  v36 = *(float *)(LODWORD(v7) + 16900) - (float)((float)((float)(v39 * max_scale) * 1.41421) * 2.0);
  v38 = v22;
  v39 = v23;
  *(_QWORD *)&sky_position.x = __PAIR64__(v22, LODWORD(v36));
  sky_position.z = v23;
  vostok::math::create_camera_direction(&sky_position, &direction, &up);
  _X = max_scale * 1.41421;
  orthographic_projection = vostok::math::create_orthographic_projection(
                              (vostok::math *)LODWORD(_X),
                              (struct vostok::math::float4x4 *)LODWORD(_X),
                              v31,
                              v32,
                              v33,
                              v34);
  vostok::math::mul4x3(&result, &sun_rotation, orthographic_projection);
  m_rsm_source_size = (double)sun->m_rsm_source_size;
  memset(&sky_position, 0, sizeof(sky_position));
  v37 = m_rsm_source_size;
  vostok::render::compute_aligment(&sky_position, (int)&adjastment, v37);
  adjastment.x = v36 + adjastment.x;
  adjastment.y = adjastment.y + *(float *)&v38;
  adjastment.z = adjastment.z + v39;
  qmemcpy(
    (void *)&sun_rotation,
    vostok::math::create_camera_direction(&adjastment, &direction, &up),
    sizeof(sun_rotation));
  _X = cascade_index;
  stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>(
    (stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *)LODWORD(cascade_index),
    (unsigned __int8 **)&v28._M_impl._M_finish,
    &transforms._M_impl);
  v28._M_impl._M_start = &projection_matrix;
  vostok::render::stage_light_propagation_volumes::render_to_rms(
    (vostok::render::stage_light_propagation_volumes *)&sun_rotation,
    sun,
    &light_color,
    COERCE_VOSTOK_RENDER_RENDER_SURFACE_INSTANCE_(1.0),
    (vostok::render::renderer_context *)&sun_rotation,
    v28,
    (const unsigned int)v29,
    LODWORD(_X));
  M_start = transforms._M_impl._M_start;
  if ( transforms._M_impl._M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, (void *)M_start);
  }
}
