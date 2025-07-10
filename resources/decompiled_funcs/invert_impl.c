vostok::math::float4x4 *__usercall invert_impl@<eax>(
        const vostok::math::float4x4 *other@<ecx>,
        vostok::math::float4x4 *result@<eax>,
        float determinant)
{
  float z; // xmm4_4
  float v4; // xmm5_4
  float y; // xmm3_4
  float v6; // xmm6_4
  float v7; // xmm7_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm2_4
  float x; // xmm6_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm7_4
  const vostok::math::float4x4 *v23; // xmm0_4
  float v24; // [esp+0h] [ebp-1Ch]
  float v25; // [esp+4h] [ebp-18h]
  float v26; // [esp+8h] [ebp-14h]
  float v27; // [esp+8h] [ebp-14h]
  float v28; // [esp+Ch] [ebp-10h]
  float v29; // [esp+10h] [ebp-Ch]
  float v30; // [esp+14h] [ebp-8h]
  float v31; // [esp+18h] [ebp-4h]
  float determinanta; // [esp+20h] [ebp+4h]

  z = other->j.z;
  v4 = other->k.z;
  y = other->j.y;
  v6 = other->k.y;
  v7 = other->i.z;
  v8 = *(float *)&clear_value / determinant;
  v9 = other->i.y;
  v29 = (float)((float)(y * v4) - (float)(z * v6)) * (float)(*(float *)&clear_value / determinant);
  result->i.x = v29;
  v25 = v9;
  v24 = v6;
  v10 = (float)(v9 * v4) - (float)(v7 * v6);
  x = other->k.x;
  v12 = (float)((float)(v25 * z) - (float)(v7 * y)) * v8;
  v26 = y;
  v13 = other->j.x;
  v31 = v12;
  result->i.z = v12;
  determinanta = v13;
  result->i.w = 0.0;
  v14 = other->i.x;
  v30 = (float)((float)(other->i.x * v4) - (float)(x * v7)) * v8;
  result->j.y = v30;
  result->j.w = 0.0;
  v28 = (float)((float)(v13 * v24) - (float)(x * v26)) * v8;
  result->k.x = v28;
  v15 = -(float)(v10 * v8);
  v16 = -(float)((float)((float)(v13 * v4) - (float)(x * z)) * v8);
  v17 = -(float)((float)((float)(v14 * z) - (float)(determinanta * v7)) * v8);
  result->i.y = v15;
  result->j.x = v16;
  result->j.z = v17;
  v18 = -(float)((float)((float)(v14 * v24) - (float)(x * v25)) * v8);
  v19 = other->c.y;
  v27 = (float)((float)(v14 * v26) - (float)(determinanta * v25)) * v8;
  result->k.z = v27;
  v20 = other->c.x;
  result->k.w = 0.0;
  v21 = other->c.z;
  result->c.x = -(float)((float)((float)(v21 * v28) + (float)(v19 * v16)) + (float)(v20 * v29));
  v22 = v21;
  result->k.y = v18;
  result->c.z = -(float)((float)((float)(v21 * v27) + (float)(v19 * v17)) + (float)(v20 * v31));
  v23 = clear_value;
  result->c.y = -(float)((float)((float)(v22 * v18) + (float)(v19 * v30)) + (float)(v20 * v15));
  LODWORD(result->c.w) = v23;
  return result;
}
