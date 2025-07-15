vostok::math::float3 *__usercall vostok::collision::octant_vector@<eax>(
        vostok::math::float3 *a1@<eax>,
        vostok::math::float3 *result)
{
  float v2; // xmm0_4
  float v3; // xmm3_4
  float v4; // xmm1_4

  v2 = -1.0;
  if ( ((unsigned __int8)result & 4) != 0 )
    v3 = *(float *)&clear_value;
  else
    v3 = -1.0;
  if ( ((unsigned __int8)result & 2) != 0 )
    v4 = *(float *)&clear_value;
  else
    v4 = -1.0;
  if ( ((unsigned __int8)result & 1) != 0 )
    v2 = *(float *)&clear_value;
  a1->x = v2;
  a1->y = v4;
  a1->z = v3;
  return a1;
}
