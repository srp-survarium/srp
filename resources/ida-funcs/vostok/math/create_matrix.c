vostok::math::float4x4 *__fastcall vostok::math::create_matrix(
        const vostok::math::quaternion *q,
        const vostok::math::float3 *position,
        vostok::math::float4x4 *wy)
{
  vostok::math::float4x4 *result; // eax
  float y; // xmm5_4
  float z; // xmm6_4
  float x; // xmm0_4
  float w; // xmm7_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm7_4
  float v13; // xmm1_4
  const vostok::math::float4x4 *v14; // xmm5_4
  float xx; // [esp+0h] [ebp-Ch]
  float xy; // [esp+4h] [ebp-8h]
  float yz; // [esp+8h] [ebp-4h]
  float wya; // [esp+10h] [ebp+4h]

  result = wy;
  y = q->y;
  wy->c.x = position->x;
  z = q->z;
  x = q->x;
  wy->c.y = position->y;
  w = q->w;
  wy->c.z = position->z;
  v8 = x * x;
  xy = y * x;
  v9 = z * x;
  yz = z * y;
  v10 = w * x;
  v11 = w;
  v12 = w * z;
  xx = v8;
  wya = v11 * y;
  v13 = (float)(y * y) + v8;
  result->i.x = *(float *)&clear_value - (float)((float)((float)(z * z) + (float)(y * y)) * 2.0);
  v14 = clear_value;
  result->j.x = (float)(v12 + xy) * 2.0;
  result->i.y = (float)(xy - v12) * 2.0;
  result->j.y = *(float *)&v14 - (float)((float)((float)(z * z) + xx) * 2.0);
  result->i.z = (float)(wya + v9) * 2.0;
  result->i.w = 0.0;
  result->j.z = (float)(yz - v10) * 2.0;
  result->j.w = 0.0;
  result->k.x = (float)(v9 - wya) * 2.0;
  result->k.y = (float)(v10 + yz) * 2.0;
  result->k.z = *(float *)&v14 - (float)(v13 * 2.0);
  result->k.w = 0.0;
  result->c.w = *(float *)&v14;
  return result;
}
