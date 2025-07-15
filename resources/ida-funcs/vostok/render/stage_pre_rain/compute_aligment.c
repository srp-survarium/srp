vostok::render::stage_pre_rain *__userpurge vostok::render::stage_pre_rain::compute_aligment@<eax>(
        const vostok::math::float3 *lightXZshift@<eax>,
        float a2@<xmm3>,
        vostok::render::stage_pre_rain *this)
{
  float v3; // xmm1_4
  const vostok::math::float4x4 *v4; // edx
  float *v5; // edx
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm7_4
  __m128 v11; // xmm3
  __m128 v12; // xmm6
  __m128 v13; // xmm5
  __m128 v14; // xmm2
  __m128 v15; // xmm6
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  float v19; // xmm1_4
  vostok::render::stage_pre_rain *result; // eax
  vostok::math::float4x4 v21; // [esp+0h] [ebp-E4h] BYREF
  vostok::math::float4x4 v22; // [esp+40h] [ebp-A4h] BYREF
  int v23; // [esp+84h] [ebp-60h]
  float v24; // [esp+88h] [ebp-5Ch]
  int v25; // [esp+8Ch] [ebp-58h]
  int v26; // [esp+90h] [ebp-54h]
  float v27; // [esp+94h] [ebp-50h]
  int v28; // [esp+98h] [ebp-4Ch]
  int v29; // [esp+9Ch] [ebp-48h]
  int v30; // [esp+A0h] [ebp-44h]
  float v31; // [esp+A4h] [ebp-40h]
  float v32; // [esp+A8h] [ebp-3Ch]
  int v33; // [esp+ACh] [ebp-38h]
  float v34; // [esp+B0h] [ebp-34h]
  int v35; // [esp+B8h] [ebp-2Ch]
  int v36; // [esp+BCh] [ebp-28h]
  float v37; // [esp+C0h] [ebp-24h]
  int v38; // [esp+C4h] [ebp-20h]
  float v39; // [esp+C8h] [ebp-1Ch]
  float v40; // [esp+D0h] [ebp-14h]
  float v41; // [esp+D4h] [ebp-10h]
  float v42; // [esp+D8h] [ebp-Ch]

  LODWORD(v40) = LODWORD(lightXZshift->x) ^ _mask__NegFloat_;
  LODWORD(v41) = LODWORD(lightXZshift->y) ^ _mask__NegFloat_;
  LODWORD(v3) = LODWORD(lightXZshift->z) ^ _mask__NegFloat_;
  v27 = a2 * 0.5;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v22.i.x = a2 * 0.5;
  memset(&v22.e01, 0, 16);
  v23 = 0;
  v24 = a2 * -0.5;
  v25 = 0;
  v26 = 0;
  v22.j.y = a2 * -0.5;
  memset(&v22.lines[1].elements[2], 0, 16);
  v35 = 0;
  v36 = 0;
  v38 = 0;
  v42 = v3;
  v37 = s_bm_current_air_resistance;
  *(_QWORD *)&v22.lines[2].elements[2] = LODWORD(s_bm_current_air_resistance);
  v31 = a2 * 0.5;
  v32 = a2 * 0.5;
  v33 = 0;
  v34 = s_bm_current_air_resistance;
  v22.c.x = a2 * 0.5;
  v22.c.y = a2 * 0.5;
  v22.c.z = 0.0;
  v22.c.w = s_bm_current_air_resistance;
  vostok::math::invert4x3(&v22, &v21);
  vostok::math::invert4x3(v4, &v22);
  v6 = (float)((float)((float)(v5[7] * v41) + (float)(v5[11] * v42)) + (float)(v5[3] * v40)) + v5[15];
  v7 = (float)(s_bm_current_air_resistance / v6)
     * (float)((float)((float)((float)(v5[4] * v41) + (float)(v5[8] * v42)) + (float)(*v5 * v40)) + v5[12]);
  v8 = (float)(s_bm_current_air_resistance / v6)
     * (float)((float)((float)((float)(v5[5] * v41) + (float)(v5[9] * v42)) + (float)(v5[1] * v40)) + v5[13]);
  v9 = (float)(s_bm_current_air_resistance / v6)
     * (float)((float)((float)((float)(v5[6] * v41) + (float)(v5[10] * v42)) + (float)(v5[2] * v40)) + v5[14]);
  v10 = (float)(s_bm_current_air_resistance / v6) * v6;
  v11 = (__m128)LODWORD(v27);
  v39 = (float)(v8 * 0.0) + (float)(v9 * 0.0);
  v11.m128_f32[0] = (float)((float)(v27 * v7) + (float)(v31 * v10)) + v39;
  v12 = v11;
  v12.m128_f32[0] = v11.m128_f32[0] * 0.25;
  v40 = (float)((float)((float)(v24 * v8) + (float)(v32 * v10)) + (float)(v7 * 0.0)) + (float)(v9 * 0.0);
  v13.m128_i32[0] = LODWORD(FLOAT_N0_0) & COERCE_UNSIGNED_INT(v11.m128_f32[0] * 0.25);
  v14 = v12;
  v14.m128_f32[0] = (float)(v12.m128_f32[0]
                          + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) | LODWORD(FLOAT_N0_0) & v12.m128_i32[0]))
                  - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) | LODWORD(FLOAT_N0_0) & v12.m128_i32[0]);
  v15 = v14;
  v15.m128_f32[0] = v14.m128_f32[0] - (float)(v11.m128_f32[0] * 0.25);
  v13.m128_f32[0] = (float)(v11.m128_f32[0] * 0.25)
                  - (float)(v14.m128_f32[0]
                          - COERCE_FLOAT(_mm_cmpgt_ss(v15, v13).m128_u32[0] & LODWORD(s_bm_current_air_resistance)));
  v16 = (__m128)LODWORD(v40);
  v16.m128_f32[0] = v40 * 0.25;
  v15.m128_i32[0] = LODWORD(FLOAT_N0_0) & COERCE_UNSIGNED_INT(v40 * 0.25);
  v17 = v16;
  v17.m128_f32[0] = (float)((float)(v40 * 0.25) + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) | v15.m128_i32[0]))
                  - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) | v15.m128_i32[0]);
  v18 = v17;
  v18.m128_f32[0] = v17.m128_f32[0] - (float)(v40 * 0.25);
  v13.m128_f32[0] = v13.m128_f32[0] * 4.0;
  v18.m128_f32[0] = (float)((float)(v40 * 0.25)
                          - (float)(v17.m128_f32[0]
                                  - COERCE_FLOAT(_mm_cmpgt_ss(v18, v15).m128_u32[0] & LODWORD(s_bm_current_air_resistance))))
                  * 4.0;
  v19 = (float)((float)(v21.j.x * v18.m128_f32[0]) + (float)(v21.i.x * v13.m128_f32[0])) + (float)(v21.k.x * 0.0);
  v16.m128_f32[0] = (float)((float)(v21.j.y * v18.m128_f32[0]) + (float)(v21.i.y * v13.m128_f32[0]))
                  + (float)(v21.k.y * 0.0);
  v17.m128_f32[0] = (float)((float)(v21.j.z * v18.m128_f32[0]) + (float)(v21.i.z * v13.m128_f32[0]))
                  + (float)(v21.k.z * 0.0);
  v40 = (float)((float)(v22.i.x * v19) + (float)(v22.k.x * v17.m128_f32[0])) + (float)(v22.j.x * v16.m128_f32[0]);
  v41 = (float)((float)(v22.i.y * v19) + (float)(v22.k.y * v17.m128_f32[0])) + (float)(v22.j.y * v16.m128_f32[0]);
  v42 = (float)((float)(v22.i.z * v19) + (float)(v22.k.z * v17.m128_f32[0])) + (float)(v22.j.z * v16.m128_f32[0]);
  result = this;
  *(float *)&this->__vftable = v40;
  *(float *)&this->m_context = v41;
  *(float *)&this->m_renderer = v42;
  return result;
}
