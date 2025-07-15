vostok::math::float4x4 *__fastcall vostok::math::create_matrix(
        const vostok::math::quaternion *q,
        const vostok::math::float3 *position,
        vostok::math::float4x4 *a3)
{
  vostok::math::float4x4 *result; // eax
  float x; // xmm4_4
  float y; // xmm6_4
  float z; // xmm7_4
  float v7; // xmm5_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm6_4
  float v11; // xmm3_4
  float v12; // xmm7_4
  float v13; // [esp+0h] [ebp-10h]
  float v14; // [esp+8h] [ebp-8h]
  float v15; // [esp+Ch] [ebp-4h]
  float v16; // [esp+18h] [ebp+8h]

  result = a3;
  x = q->x;
  a3->c.x = position->x;
  y = q->y;
  z = q->z;
  a3->c.y = position->y;
  a3->c.z = position->z;
  v16 = y * x;
  v14 = z * y;
  v7 = y * y;
  v8 = z * x;
  v9 = q->w * x;
  v15 = q->w * y;
  v10 = q->w * z;
  v13 = z * z;
  v11 = s_bm_current_air_resistance;
  v12 = s_bm_current_air_resistance - (float)((float)((float)(z * z) + v7) * 2.0);
  result->j.x = (float)(v10 + v16) * 2.0;
  result->i.x = v12;
  result->i.y = (float)(v16 - v10) * 2.0;
  result->i.z = (float)(v15 + v8) * 2.0;
  result->i.w = 0.0;
  result->j.y = v11 - (float)((float)(v13 + (float)(x * x)) * 2.0);
  result->j.z = (float)(v14 - v9) * 2.0;
  result->j.w = 0.0;
  result->k.x = (float)(v8 - v15) * 2.0;
  result->k.y = (float)(v9 + v14) * 2.0;
  result->k.z = v11 - (float)((float)(v7 + (float)(x * x)) * 2.0);
  result->k.w = 0.0;
  result->c.w = v11;
  return result;
}
