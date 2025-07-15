vostok::math::float3 *__thiscall vostok::collision::sphere_geometry_instance::get_closest_point_to(
        vostok::collision::sphere_geometry_instance *this,
        vostok::math::float3 *result,
        vostok::math::float3 *point,
        const vostok::math::float4x4 *origin)
{
  vostok::math::float3 *v4; // esi
  vostok::math::float3 *v5; // eax
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm4_4
  float v9; // xmm7_4
  float v10; // xmm2_4
  vostok::math::float4x4 v11; // [esp+8h] [ebp-58h] BYREF
  float v12; // [esp+48h] [ebp-18h]
  float v13; // [esp+4Ch] [ebp-14h]
  float v14; // [esp+50h] [ebp-10h]
  float v15[3]; // [esp+54h] [ebp-Ch] BYREF

  vostok::math::mul4x3(&this->m_matrix, origin, &v11);
  v4 = point;
  v5 = result;
  v6 = point->y - v11.c.y;
  v7 = point->z - v11.c.z;
  v8 = point->x - v11.c.x;
  v9 = (float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(v8 * v8);
  if ( s_bm_current_air_resistance <= v9 )
  {
    v10 = s_bm_current_air_resistance / fsqrt(v9);
    v12 = v10 * v8;
    v13 = v6 * v10;
    v14 = v7 * v10;
    v15[0] = v11.c.x + (float)(v10 * v8);
    v15[1] = v11.c.y + (float)(v6 * v10);
    v15[2] = v11.c.z + (float)(v7 * v10);
    v4 = (vostok::math::float3 *)v15;
  }
  *result = *v4;
  return v5;
}
