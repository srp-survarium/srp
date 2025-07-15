vostok::math::float3 *__usercall vostok::render::stage_pre_rain::compute_aligment@<eax>(
        const vostok::math::float3 *lightXZshift@<eax>,
        int a2@<esi>,
        float a3@<xmm2>,
        vostok::render::stage_pre_rain *this)
{
  float v6; // xmm0_4
  float v7; // xmm0_4
  const vostok::math::float4x4 *v8; // edx
  float z; // xmm2_4
  float v10; // xmm5_4
  float y; // xmm3_4
  float v12; // xmm4_4
  float x; // xmm1_4
  float *v14; // edx
  float v15; // xmm1_4
  float v16; // xmm6_4
  float v17; // xmm5_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  __m128 v20; // xmm2
  __m128 v21; // xmm7
  float v22; // xmm5_4
  __m128 v23; // xmm0
  __m128 v24; // xmm3
  __m128 v25; // xmm4
  __m128 v26; // xmm2
  __m128 v27; // xmm5
  __m128 v28; // xmm0
  __m128 v29; // xmm6
  float v30; // xmm1_4
  float v32; // [esp+2F8h] [ebp-E4h]
  float v33; // [esp+2FCh] [ebp-E0h]
  __int64 v34; // [esp+300h] [ebp-DCh]
  float v35; // [esp+308h] [ebp-D4h]
  __m128i v36; // [esp+30Ch] [ebp-D0h] BYREF
  float v37; // [esp+328h] [ebp-B4h]
  vostok::math::float4_pod v38; // [esp+32Ch] [ebp-B0h]
  __int64 v39; // [esp+33Ch] [ebp-A0h]
  __int64 v40; // [esp+344h] [ebp-98h]
  __int64 v41; // [esp+34Ch] [ebp-90h]
  __int64 v42; // [esp+354h] [ebp-88h]
  vostok::math::float4x4 other; // [esp+35Ch] [ebp-80h] BYREF
  float v44; // [esp+39Ch] [ebp-40h]
  float v45; // [esp+3A0h] [ebp-3Ch]
  float v46; // [esp+3A4h] [ebp-38h]
  float v47; // [esp+3ACh] [ebp-30h]
  float v48; // [esp+3B0h] [ebp-2Ch]
  float v49; // [esp+3B4h] [ebp-28h]
  float v50; // [esp+3BCh] [ebp-20h]
  float v51; // [esp+3C0h] [ebp-1Ch]
  float v52; // [esp+3C4h] [ebp-18h]

  *(float *)&v34 = -lightXZshift->x;
  v6 = -lightXZshift->y;
  LODWORD(v38.w) = clear_value;
  v36.m128i_i64[1] = (unsigned int)clear_value;
  *((float *)&v34 + 1) = v6;
  v7 = -lightXZshift->z;
  v39 = COERCE_UNSIGNED_INT(a3 * 0.5);
  v35 = v7;
  *(_QWORD *)&other.i.x = v39;
  v40 = 0;
  *(_QWORD *)&other.lines[0].elements[2] = 0;
  LODWORD(v41) = 0;
  *((float *)&v41 + 1) = a3 * -0.5;
  *(_QWORD *)&other.lines[1].x = v41;
  v42 = 0;
  memset(&other.lines[1].elements[2], 0, 16);
  v36.m128i_i64[0] = 0;
  v38.x = a3 * 0.5;
  v38.y = a3 * 0.5;
  *(_QWORD *)&other.lines[2].elements[2] = (unsigned int)clear_value;
  v38.z = 0.0;
  other.c = v38;
  invert_impl(
    &other,
    (float)((float)(a3 * -0.5) * (float)(a3 * 0.5)) + (float)((float)((float)(a3 * -0.5) * -0.0) * 0.0));
  z = v8->k.z;
  v10 = v8->j.z;
  y = v8->j.y;
  v12 = v8->k.y;
  x = v8->k.x;
  v33 = v8->i.y;
  v32 = v8->i.z;
  v37 = v8->i.x;
  invert_impl(
    v8,
    (float)((float)((float)((float)(y * z) - (float)(v10 * v12)) * v37)
          - (float)((float)((float)(v8->j.x * z) - (float)(x * v10)) * v33))
  + (float)((float)((float)(v8->j.x * v12) - (float)(x * y)) * v32));
  v15 = (float)((float)((float)(v14[7] * *((float *)&v34 + 1)) + (float)(v14[11] * v7))
              + (float)(v14[3] * *(float *)&v34))
      + v14[15];
  v16 = (float)(*(float *)&clear_value / v15)
      * (float)((float)((float)((float)(v14[9] * v7) + (float)(v33 * *(float *)&v34))
                      + (float)(v14[5] * *((float *)&v34 + 1)))
              + v14[13]);
  v17 = (float)(*(float *)&clear_value / v15)
      * (float)((float)((float)((float)(v14[4] * *((float *)&v34 + 1)) + (float)(v14[8] * v7))
                      + (float)(v37 * *(float *)&v34))
              + v14[12]);
  v18 = (float)(*(float *)&clear_value / v15)
      * (float)((float)((float)((float)(v14[6] * *((float *)&v34 + 1)) + (float)(v14[10] * v7))
                      + (float)(v32 * *(float *)&v34))
              + v14[14]);
  v19 = (float)(*(float *)&clear_value / v15) * v15;
  v32 = (float)(v18 * 0.0) + (float)(v16 * 0.0);
  v20 = (__m128)(unsigned int)v39;
  v20.m128_f32[0] = (float)((float)(*(float *)&v39 * v17) + (float)(v38.x * v19)) + v32;
  v21 = v20;
  *(float *)v36.m128i_i32 = v20.m128_f32[0];
  v22 = v17 * 0.0;
  *(float *)&v36.m128i_i32[1] = (float)((float)((float)(*((float *)&v41 + 1) * v16) + (float)(v38.y * v19)) + v22)
                              + (float)(v18 * 0.0);
  *(float *)&v36.m128i_i32[2] = (float)((float)((float)(v19 * 0.0) + v22) + (float)(v16 * 0.0)) + v18;
  *(float *)&v36.m128i_i32[3] = (float)(v22 + v32) + v19;
  v36 = _mm_load_si128(&v36);
  v21.m128_f32[0] = v20.m128_f32[0] * 0.25;
  v23 = v21;
  v24.m128_i32[0] = COERCE_UNSIGNED_INT(v20.m128_f32[0] * 0.25) & 0x80000000;
  v23.m128_f32[0] = (float)(v21.m128_f32[0] + COERCE_FLOAT(v21.m128_i32[0] & 0x80000000 | 0x4B000000))
                  - COERCE_FLOAT(v21.m128_i32[0] & 0x80000000 | 0x4B000000);
  v25 = v23;
  v25.m128_f32[0] = v23.m128_f32[0] - (float)(v20.m128_f32[0] * 0.25);
  v24.m128_f32[0] = (float)(v20.m128_f32[0] * 0.25)
                  - (float)(v23.m128_f32[0]
                          - COERCE_FLOAT(_mm_cmpgt_ss(v25, v24).m128_u32[0] & (unsigned int)clear_value));
  v26 = (__m128)v36.m128i_u32[1];
  v26.m128_f32[0] = *(float *)&v36.m128i_i32[1] * 0.25;
  v27.m128_i32[0] = COERCE_UNSIGNED_INT(*(float *)&v36.m128i_i32[1] * 0.25) & 0x80000000;
  v28 = v26;
  v28.m128_f32[0] = (float)((float)(*(float *)&v36.m128i_i32[1] * 0.25) + COERCE_FLOAT(v27.m128_i32[0] | 0x4B000000))
                  - COERCE_FLOAT(v27.m128_i32[0] | 0x4B000000);
  v29 = v28;
  v29.m128_f32[0] = v28.m128_f32[0] - (float)(*(float *)&v36.m128i_i32[1] * 0.25);
  v27.m128_f32[0] = (float)((float)(*(float *)&v36.m128i_i32[1] * 0.25)
                          - (float)(v28.m128_f32[0]
                                  - COERCE_FLOAT(_mm_cmpgt_ss(v29, v27).m128_u32[0] & (unsigned int)clear_value)))
                  * 4.0;
  v28.m128_f32[0] = (float)((float)(v47 * v27.m128_f32[0]) + (float)(v44 * (float)(v24.m128_f32[0] * 4.0)))
                  + (float)(v50 * 0.0);
  v26.m128_f32[0] = (float)((float)(v48 * v27.m128_f32[0]) + (float)(v45 * (float)(v24.m128_f32[0] * 4.0)))
                  + (float)(v51 * 0.0);
  v24.m128_f32[0] = (float)((float)(v49 * v27.m128_f32[0]) + (float)(v46 * (float)(v24.m128_f32[0] * 4.0)))
                  + (float)(v52 * 0.0);
  *(float *)&v34 = (float)((float)(other.i.x * v28.m128_f32[0]) + (float)(other.k.x * v24.m128_f32[0]))
                 + (float)(other.j.x * v26.m128_f32[0]);
  *((float *)&v34 + 1) = (float)((float)(other.i.y * v28.m128_f32[0]) + (float)(other.k.y * v24.m128_f32[0]))
                       + (float)(other.j.y * v26.m128_f32[0]);
  v30 = (float)((float)(other.i.z * v28.m128_f32[0]) + (float)(other.k.z * v24.m128_f32[0]))
      + (float)(other.j.z * v26.m128_f32[0]);
  *(_QWORD *)a2 = v34;
  *(float *)(a2 + 8) = v30;
  return (vostok::math::float3 *)a2;
}
