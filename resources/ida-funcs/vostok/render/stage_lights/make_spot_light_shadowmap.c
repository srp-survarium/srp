void __userpurge vostok::render::stage_lights::make_spot_light_shadowmap(
        vostok::render::light *l@<edi>,
        float a2@<esi>,
        vostok::render::stage_lights *this,
        unsigned int shadow_quality)
{
  float z; // xmm6_4
  float y; // xmm4_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float x; // xmm6_4
  unsigned int v9; // xmm1_4
  unsigned int v10; // xmm2_4
  unsigned int shadow_map_size_index; // eax
  unsigned int v12; // eax
  const vostok::math::float4x4 *v13; // [esp+10h] [ebp-A0h]
  unsigned int marge; // [esp+14h] [ebp-9Ch]
  float v15; // [esp+18h] [ebp-98h]
  float v16; // [esp+20h] [ebp-90h]
  vostok::math::float3 at; // [esp+24h] [ebp-8Ch] BYREF
  vostok::math::float4x4 projection_matrix; // [esp+30h] [ebp-80h] BYREF
  vostok::math::float4x4 view_matrix; // [esp+70h] [ebp-40h] BYREF

  vostok::math::create_perspective_projection(
    COERCE_VOSTOK_MATH_(1.0),
    COERCE_STRUCT_VOSTOK_MATH_FLOAT4X4_(l->range * 0.001),
    l->range,
    a2,
    l->range,
    v15);
  z = l->direction.z;
  y = l->direction.y;
  v6 = l->right.x * z;
  v7 = (float)(l->right.z * y) - (float)(l->right.y * z);
  x = l->direction.x;
  v16 = (float)(x * l->right.y) - (float)(l->right.x * y);
  *(float *)&marge = sqrtf(
                       (float)((float)((float)(v6 - (float)(x * l->right.z)) * (float)(v6 - (float)(x * l->right.z)))
                             + (float)(v16 * v16))
                     + (float)(v7 * v7));
  *(float *)&v9 = l->position.y + l->direction.y;
  *(float *)&v10 = l->position.z + l->direction.z;
  at.x = l->position.x + l->direction.x;
  *(_QWORD *)&at.elements[1] = __PAIR64__(v10, v9);
  vostok::math::create_camera_at(&l->position, &at, (const vostok::math::float3 *)&view_matrix);
  shadow_map_size_index = l->shadow_map_size_index;
  if ( shadow_map_size_index )
  {
    if ( shadow_map_size_index == 1 )
      v12 = 512;
    else
      v12 = 256;
  }
  else
  {
    v12 = 1024;
  }
  vostok::render::stage_lights::render_to_hw_shadowmap(
    v12,
    (vostok::render::backend *)this,
    this,
    l,
    l->shadow_z_bias,
    *(float *)&l->shadow_map_size_index,
    &view_matrix,
    (vostok::render::renderer_context *)&projection_matrix,
    v13,
    marge);
}
