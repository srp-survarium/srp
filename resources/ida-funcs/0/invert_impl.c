vostok::math::float4x4 *__usercall invert_impl@<eax>(
        const vostok::math::float4x4 *other@<ecx>,
        vostok::math::float4x4 *result@<eax>,
        const float determinant)
{
  float z; // xmm3_4
  float v4; // xmm6_4
  float y; // xmm5_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm5_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  float v13; // xmm6_4
  unsigned int v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // [esp+0h] [ebp-28h]
  float v19; // [esp+4h] [ebp-24h]
  float v20; // [esp+8h] [ebp-20h]
  float v21; // [esp+Ch] [ebp-1Ch]
  float v22; // [esp+Ch] [ebp-1Ch]
  float v23; // [esp+10h] [ebp-18h]
  float v24; // [esp+14h] [ebp-14h]
  float v25; // [esp+18h] [ebp-10h]
  float v26; // [esp+1Ch] [ebp-Ch]
  float x; // [esp+20h] [ebp-8h]
  float v28; // [esp+24h] [ebp-4h]
  float v29; // [esp+24h] [ebp-4h]
  float v30; // [esp+30h] [ebp+8h]

  z = other->j.z;
  v4 = other->k.z;
  y = other->j.y;
  v6 = s_bm_current_air_resistance / determinant;
  v23 = other->i.y;
  v25 = other->k.y;
  v20 = (float)((float)(y * v4) - (float)(z * v25)) * (float)(s_bm_current_air_resistance / determinant);
  result->i.x = v20;
  v28 = other->i.z;
  v24 = y;
  v7 = (float)(v23 * z) - (float)(v28 * y);
  x = other->k.x;
  v26 = other->j.x;
  v8 = (float)(v26 * v4) - (float)(x * z);
  v21 = z;
  v9 = other->i.x;
  v19 = (float)((float)(other->i.x * v4) - (float)(x * v28)) * v6;
  result->j.y = v19;
  v10 = (float)(v23 * v4) - (float)(v28 * v25);
  LODWORD(v29) = COERCE_UNSIGNED_INT((float)((float)(v9 * v21) - (float)(v26 * v28)) * v6) ^ _mask__NegFloat_;
  result->j.z = v29;
  v18 = v7 * v6;
  result->i.z = v7 * v6;
  LODWORD(v11) = COERCE_UNSIGNED_INT(v10 * v6) ^ _mask__NegFloat_;
  LODWORD(v12) = COERCE_UNSIGNED_INT(v8 * v6) ^ _mask__NegFloat_;
  v22 = (float)((float)(v26 * v25) - (float)(x * v24)) * v6;
  result->k.x = v22;
  result->i.y = v11;
  result->i.w = 0.0;
  result->j.x = v12;
  result->j.w = 0.0;
  LODWORD(v30) = COERCE_UNSIGNED_INT((float)((float)(v9 * v25) - (float)(x * v23)) * v6) ^ _mask__NegFloat_;
  result->k.y = v30;
  v13 = other->c.x;
  *(float *)&v14 = (float)((float)(v9 * v24) - (float)(v26 * v23)) * v6;
  v15 = other->c.y;
  *(_QWORD *)&result->lines[2].elements[2] = v14;
  v16 = other->c.z;
  LODWORD(result->c.x) = COERCE_UNSIGNED_INT((float)((float)(v16 * v22) + (float)(v15 * v12)) + (float)(v13 * v20))
                       ^ _mask__NegFloat_;
  v17 = s_bm_current_air_resistance;
  LODWORD(result->c.y) = COERCE_UNSIGNED_INT((float)((float)(v16 * v30) + (float)(v15 * v19)) + (float)(v13 * v11))
                       ^ _mask__NegFloat_;
  LODWORD(result->c.z) = COERCE_UNSIGNED_INT((float)((float)(v16 * *(float *)&v14) + (float)(v15 * v29)) + (float)(v13 * v18))
                       ^ _mask__NegFloat_;
  result->c.w = v17;
  return result;
}
