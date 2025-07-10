vostok::math::float3 *__fastcall vostok::math::operator^(
        const vostok::math::float3_pod *right,
        const vostok::math::float3_pod *left,
        vostok::math::float3 *a3)
{
  float z; // xmm3_4
  float v4; // xmm4_4
  float y; // xmm5_4
  float v6; // xmm2_4
  vostok::math::float3 *result; // eax
  float x; // xmm1_4
  float v9; // xmm0_4

  z = right->z;
  v4 = left->z;
  y = right->y;
  v6 = left->y;
  result = a3;
  x = right->x;
  a3->x = (float)(z * v6) - (float)(y * v4);
  v9 = (float)(left->x * y) - (float)(x * v6);
  a3->y = (float)(x * v4) - (float)(left->x * z);
  a3->z = v9;
  return result;
}
