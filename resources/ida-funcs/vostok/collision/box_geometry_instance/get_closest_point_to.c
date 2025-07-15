vostok::math::float3 *__thiscall vostok::collision::box_geometry_instance::get_closest_point_to(
        vostok::collision::box_geometry_instance *this,
        vostok::math::float3 *result,
        const vostok::math::float3 *source,
        const vostok::math::float4x4 *origin)
{
  float v4; // xmm0_4
  float v5; // xmm0_4
  float x; // xmm5_4
  float y; // xmm6_4
  float z; // xmm7_4
  int v9; // ecx
  vostok::math::float4x4 *v10; // eax
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm4_4
  float v18; // xmm4_4
  float v20; // [esp+10h] [ebp-60h]
  float v21; // [esp+18h] [ebp-58h]
  float v22; // [esp+1Ch] [ebp-54h]
  float v23; // [esp+20h] [ebp-50h]
  vostok::math::float3 v24; // [esp+24h] [ebp-4Ch] BYREF
  vostok::math::float4x4 v25; // [esp+30h] [ebp-40h] BYREF

  vostok::math::mul4x3(&this->m_matrix, origin, &v25);
  v4 = source->x - v25.c.x;
  result->x = v25.c.x;
  v21 = v4;
  v5 = source->y - v25.c.y;
  result->y = v25.c.y;
  v22 = v5;
  v23 = source->z - v25.c.z;
  result->z = v25.c.z;
  vostok::math::float4x4::get_scale(&v25, &v24);
  x = result->x;
  y = result->y;
  z = result->z;
  v9 = 0;
  v10 = &v25;
  do
  {
    v20 = v10->i.y;
    v11 = v10->i.z;
    v12 = s_bm_current_air_resistance
        / fsqrt((float)((float)(v11 * v11) + (float)(v20 * v20)) + (float)(v10->i.x * v10->i.x));
    v13 = v20 * v12;
    v14 = v12 * v10->i.x;
    v15 = v11 * v12;
    v16 = (float)((float)(v15 * v23) + (float)((float)(v20 * v12) * v22)) + (float)(v14 * v21);
    v17 = *(&v24.x + v9);
    if ( v16 > v17 )
      v16 = *(&v24.x + v9);
    LODWORD(v18) = LODWORD(v17) ^ _mask__NegFloat_;
    if ( v18 > v16 )
      v16 = v18;
    ++v9;
    v10 = (vostok::math::float4x4 *)((char *)v10 + 16);
    x = x + (float)(v14 * v16);
    y = y + (float)(v13 * v16);
    z = z + (float)(v15 * v16);
  }
  while ( v9 < 3 );
  result->x = x;
  result->y = y;
  result->z = z;
  return result;
}
