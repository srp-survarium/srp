vostok::math::float3 *__cdecl vostok::math::cross_product(
        vostok::math::float3 *result,
        const vostok::math::float3_pod *left,
        const vostok::math::float3_pod *right)
{
  float z; // xmm3_4
  float v4; // xmm4_4
  float y; // xmm5_4
  float v6; // xmm2_4
  vostok::math::float3 *v7; // eax
  float x; // xmm1_4
  float v9; // xmm0_4

  z = right->z;
  v4 = left->z;
  y = right->y;
  v6 = left->y;
  v7 = result;
  x = right->x;
  result->x = (float)(z * v6) - (float)(y * v4);
  v9 = (float)(left->x * y) - (float)(x * v6);
  result->y = (float)(x * v4) - (float)(left->x * z);
  result->z = v9;
  return v7;
}
