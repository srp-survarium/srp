vostok::math::float3 *__usercall vostok::collision::closest_point_on_segment@<eax>(
        const vostok::math::float3 *point@<esi>,
        const vostok::math::float3 *segment_origin@<edx>,
        const vostok::math::float3 *segment_displacement@<ecx>,
        vostok::math::float3 *a4)
{
  vostok::math::float3 *result; // eax
  float x; // xmm1_4
  float z; // xmm6_4
  float y; // xmm4_4
  const vostok::math::float4x4 *v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // [esp+0h] [ebp-4h]
  float v11; // [esp+8h] [ebp+4h]

  result = a4;
  x = segment_displacement->x;
  z = segment_origin->z;
  y = segment_origin->y;
  v11 = segment_displacement->y;
  v10 = segment_displacement->z;
  v8 = 0;
  v9 = (float)((float)((float)(x * (float)(point->x - segment_origin->x)) + (float)(v10 * (float)(point->z - z)))
             + (float)(v11 * (float)(point->y - y)))
     / (float)((float)((float)(v10 * v10) + (float)(v11 * v11)) + (float)(x * x));
  if ( v9 <= 0.0 || (v8 = clear_value, *(float *)&clear_value < v9) )
    v9 = *(float *)&v8;
  result->x = segment_origin->x + (float)(x * v9);
  result->y = y + (float)(v11 * v9);
  result->z = z + (float)(v10 * v9);
  return result;
}
