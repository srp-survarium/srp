BOOL __fastcall vostok::math::operator==(const vostok::math::float3_pod *right, const vostok::math::float3_pod *left)
{
  return left->x == right->x && left->y == right->y && left->z == right->z;
}


float *__usercall vostok::math::operator*@<eax>(float *result@<eax>, float *a2@<ecx>, float a3@<xmm0>)
{
  float v3; // xmm1_4
  float v4; // [esp+4h] [ebp-8h]
  float v5; // [esp+4h] [ebp-8h]
  float v6; // [esp+8h] [ebp-4h]
  float v7; // [esp+8h] [ebp-4h]

  v4 = a2[1] * a3;
  v6 = a2[2] * a3;
  v3 = a2[3];
  *result = *a2 * a3;
  result[1] = v4;
  result[2] = v6;
  v5 = a2[4] * a3;
  v7 = a2[5] * a3;
  result[3] = v3 * a3;
  result[4] = v5;
  result[5] = v7;
  return result;
}


vostok::math::float4x4 *__fastcall vostok::math::operator*(
        const vostok::math::float4x4 *right,
        const vostok::math::float4x4 *left,
        vostok::math::float4x4 *a3)
{
  vostok::math::mul4x3(right, left, a3);
  return a3;
}


vostok::math::quaternion *__fastcall vostok::math::operator*(
        const vostok::math::quaternion *right,
        const vostok::math::quaternion *left,
        vostok::math::quaternion *a3)
{
  float w; // xmm4_4
  float x; // xmm5_4
  float y; // xmm0_4
  float v6; // xmm1_4
  float z; // xmm3_4
  float v8; // xmm2_4
  vostok::math::quaternion *result; // eax
  float v10; // xmm6_4
  float v11; // xmm5_4
  float v12; // xmm7_4
  float v13; // xmm5_4

  w = left->w;
  x = left->x;
  y = right->y;
  v6 = left->y;
  z = right->z;
  v8 = left->z;
  result = a3;
  a3->w = (float)((float)((float)(right->w * w) - (float)(right->x * left->x)) - (float)(y * v6)) - (float)(z * v8);
  v10 = (float)((float)((float)(z * v6) + (float)(x * right->w)) + (float)(right->x * w)) - (float)(v8 * y);
  v11 = left->x;
  a3->x = v10;
  v12 = z * v11;
  v13 = right->w;
  a3->y = (float)((float)((float)(y * w) - v12) + (float)(v8 * right->x)) + (float)(v6 * v13);
  a3->z = (float)((float)((float)(y * left->x) + (float)(z * w)) - (float)(v6 * right->x)) + (float)(v8 * v13);
  return result;
}
