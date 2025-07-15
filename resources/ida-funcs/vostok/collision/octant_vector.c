vostok::math::float3 *__usercall vostok::collision::octant_vector@<eax>(
        vostok::math::float3 *a1@<eax>,
        vostok::math::float3 *result)
{
  float v2; // xmm0_4
  float v3; // xmm3_4
  float v4; // xmm2_4

  v2 = FLOAT_N1_0;
  if ( ((unsigned __int8)result & 4) != 0 )
    v3 = s_bm_current_air_resistance;
  else
    v3 = FLOAT_N1_0;
  if ( ((unsigned __int8)result & 2) != 0 )
    v4 = s_bm_current_air_resistance;
  else
    v4 = FLOAT_N1_0;
  if ( ((unsigned __int8)result & 1) != 0 )
    v2 = s_bm_current_air_resistance;
  a1->x = v2;
  a1->y = v4;
  a1->z = v3;
  return a1;
}
