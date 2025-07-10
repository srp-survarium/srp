void __userpurge vostok::render::stage_lights::make_plane_spot_light_shadowmap(
        vostok::render::light *l@<edi>,
        float a2@<esi>,
        vostok::render::stage_lights *this,
        unsigned int shadow_quality)
{
  float spot_umbra_angle; // xmm0_4
  float x; // xmm1_4
  float z; // xmm2_4
  long double v7; // st7
  float v8; // xmm6_4
  float y; // xmm7_4
  float v10; // xmm4_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // eax
  float v15; // xmm2_4
  __int64 v16; // xmm3_8
  float v17; // xmm0_4
  float v18; // xmm1_4
  float range; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  unsigned int shadow_map_size_index; // eax
  unsigned int v23; // eax
  const vostok::math::float4x4 *v24; // [esp+10h] [ebp-C8h]
  float inv_distance; // [esp+14h] [ebp-C4h]
  float inv_distanceb; // [esp+14h] [ebp-C4h]
  unsigned int inv_distancea; // [esp+14h] [ebp-C4h]
  float v28; // [esp+18h] [ebp-C0h]
  float v29; // [esp+18h] [ebp-C0h]
  float v30; // [esp+18h] [ebp-C0h]
  vostok::math::float3 at; // [esp+1Ch] [ebp-BCh] BYREF
  float max_angle; // [esp+28h] [ebp-B0h]
  float v33; // [esp+2Ch] [ebp-ACh]
  float v34; // [esp+30h] [ebp-A8h]
  float v35; // [esp+34h] [ebp-A4h]
  float v36; // [esp+38h] [ebp-A0h]
  float v37; // [esp+3Ch] [ebp-9Ch]
  vostok::math::float3 new_position; // [esp+40h] [ebp-98h] BYREF
  vostok::math::float3 up; // [esp+4Ch] [ebp-8Ch]
  vostok::math::float4x4 projection_matrix; // [esp+58h] [ebp-80h] BYREF
  vostok::math::float4x4 view_matrix; // [esp+98h] [ebp-40h] BYREF

  spot_umbra_angle = l->spot_umbra_angle;
  if ( spot_umbra_angle <= l->spot_penumbra_angle )
    spot_umbra_angle = l->spot_penumbra_angle;
  x = l->scale.x;
  z = l->scale.z;
  max_angle = spot_umbra_angle;
  if ( x <= z )
    inv_distance = z;
  else
    inv_distance = x;
  v7 = tanf(spot_umbra_angle * 0.5);
  v8 = l->direction.z;
  y = l->right.y;
  v10 = l->direction.y;
  v11 = l->direction.x;
  v12 = (float)(l->right.z * v10) - (float)(y * v8);
  v13 = l->right.x * v10;
  at.y = (float)(l->right.x * v8) - (float)(v11 * l->right.z);
  at.x = v12;
  at.z = (float)(v11 * y) - v13;
  inv_distanceb = inv_distance / v7;
  v28 = sqrtf((float)((float)(at.y * at.y) + (float)(at.z * at.z)) + (float)(v12 * v12));
  v14 = l->direction.z;
  v15 = -(float)((float)(*(float *)&clear_value / v28) * at.y);
  v16 = *(_QWORD *)&l->direction.x;
  v35 = -(float)((float)(*(float *)&clear_value / v28) * at.z);
  v17 = l->position.x;
  v36 = -(float)((float)(*(float *)&clear_value / v28) * at.x);
  *(_QWORD *)&up.x = v16;
  v18 = l->position.y;
  v29 = v17 - (float)(v36 * inv_distanceb);
  new_position.x = v29;
  range = l->range;
  v37 = v15;
  v20 = v18 - (float)(v15 * inv_distanceb);
  v21 = l->position.z;
  up.z = v14;
  v34 = v20;
  v33 = v21 - (float)(v35 * inv_distanceb);
  new_position.y = v20;
  new_position.z = v33;
  vostok::math::create_perspective_projection(
    COERCE_VOSTOK_MATH_(1.0),
    (struct vostok::math::float4x4 *)LODWORD(inv_distanceb),
    range + inv_distanceb,
    a2,
    inv_distanceb,
    v29);
  at.x = v30 + v36;
  at.y = v20 + v37;
  at.z = v33 + v35;
  vostok::math::create_camera_at(&new_position, &at, (const vostok::math::float3 *)&view_matrix);
  shadow_map_size_index = l->shadow_map_size_index;
  if ( shadow_map_size_index )
  {
    if ( shadow_map_size_index == 1 )
      v23 = 512;
    else
      v23 = 256;
  }
  else
  {
    v23 = 1024;
  }
  vostok::render::stage_lights::render_to_hw_shadowmap(
    v23,
    (vostok::render::backend *)this,
    this,
    l,
    l->shadow_z_bias,
    *(float *)&l->shadow_map_size_index,
    &view_matrix,
    (vostok::render::renderer_context *)&projection_matrix,
    v24,
    inv_distancea);
}
