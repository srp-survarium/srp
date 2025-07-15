void __userpurge vostok::render::stage_lights::make_plane_spot_light_shadowmap(
        vostok::render::stage_lights *this@<ecx>,
        long double a2@<esi:edi>,
        vostok::render::light *shadow_quality,
        vostok::render::light *l)
{
  float v4; // xmm4_4
  float x; // xmm3_4
  float y; // xmm5_4
  float v7; // xmm7_4
  float v8; // xmm2_4
  float v9; // xmm5_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float range; // xmm0_4
  long double v18; // rdi
  unsigned int v19; // [esp+18h] [ebp-D0h]
  float z; // [esp+30h] [ebp-B8h]
  float spot_penumbra_angle; // [esp+34h] [ebp-B4h]
  vostok::math::float3 v22; // [esp+38h] [ebp-B0h] BYREF
  int v23; // [esp+44h] [ebp-A4h]
  int v24; // [esp+48h] [ebp-A0h]
  float v25; // [esp+4Ch] [ebp-9Ch]
  vostok::math::float3 v26; // [esp+50h] [ebp-98h] BYREF
  vostok::math::float3 v27; // [esp+5Ch] [ebp-8Ch] BYREF
  vostok::math::float4x4 projection_matrix; // [esp+68h] [ebp-80h] BYREF
  vostok::math::float4x4 view_matrix; // [esp+A8h] [ebp-40h] BYREF

  if ( l->spot_umbra_angle <= l->spot_penumbra_angle )
    spot_penumbra_angle = l->spot_penumbra_angle;
  else
    spot_penumbra_angle = l->spot_umbra_angle;
  if ( l->scale.x <= l->scale.z )
    z = l->scale.z;
  else
    z = l->scale.x;
  __libm_sse2_tan(a2);
  v4 = z / (float)(spot_penumbra_angle * 0.5);
  x = l->right.x;
  y = l->direction.y;
  v7 = l->direction.z;
  v8 = (float)(l->right.z * y) - (float)(l->right.y * v7);
  v9 = (float)(l->direction.x * l->right.y) - (float)(x * y);
  v10 = (float)(x * v7) - (float)(l->direction.x * l->right.z);
  v11 = s_bm_current_air_resistance / fsqrt((float)((float)(v9 * v9) + (float)(v10 * v10)) + (float)(v8 * v8));
  v12 = v11 * v8;
  v13 = v11 * v10;
  LODWORD(v25) = COERCE_UNSIGNED_INT(v11 * v9) ^ _mask__NegFloat_;
  v14 = l->position.x;
  v23 = LODWORD(v12) ^ _mask__NegFloat_;
  v22.x = v14 - (float)(COERCE_FLOAT(LODWORD(v12) ^ _mask__NegFloat_) * v4);
  v15 = l->position.y;
  v24 = LODWORD(v13) ^ _mask__NegFloat_;
  v22.y = v15 - (float)(COERCE_FLOAT(LODWORD(v13) ^ _mask__NegFloat_) * v4);
  v16 = l->position.z;
  v27.x = l->direction.x;
  v22.z = v16 - (float)(v25 * v4);
  range = l->range;
  *(_QWORD *)&v27.elements[1] = *(_QWORD *)&l->direction.elements[1];
  HIDWORD(v18) = &l->previous_direction;
  LODWORD(v18) = &projection_matrix;
  vostok::math::create_perspective_projection(
    v18,
    spot_penumbra_angle,
    (vostok::math *)&projection_matrix,
    COERCE_STRUCT_VOSTOK_MATH_FLOAT4X4_(1.0),
    v4,
    range + v4);
  v26.x = v22.x + COERCE_FLOAT(LODWORD(v12) ^ _mask__NegFloat_);
  v26.y = v22.y + COERCE_FLOAT(LODWORD(v13) ^ _mask__NegFloat_);
  v26.z = v22.z + v25;
  vostok::math::create_camera_at(&v22, &v26, &view_matrix, &v27);
  vostok::render::stage_lights::render_to_hw_shadowmap(
    (vostok::render::stage_lights *)l->m_quality_shadow_map_size_index,
    shadow_quality,
    (unsigned int)l,
    l->shadow_z_bias,
    (const vostok::math::float4x4 *)(1024 >> l->m_quality_shadow_map_size_index),
    (vostok::render::render_surface_instance **)l->m_quality_shadow_map_size_index,
    &view_matrix,
    &projection_matrix,
    0,
    v19);
}
