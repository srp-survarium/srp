vostok::math::float3 *__usercall vostok::render::compute_aligment@<eax>(
        const vostok::math::float3 *lightXZshift@<eax>,
        int a2@<esi>,
        float a3@<xmm2>)
{
  float v5; // xmm0_4
  float v6; // xmm0_4
  const vostok::math::float4x4 *v7; // edx
  float z; // xmm2_4
  float v9; // xmm5_4
  float y; // xmm3_4
  float v11; // xmm4_4
  float x; // xmm1_4
  float *v13; // edx
  float v14; // xmm1_4
  float v15; // xmm6_4
  float v16; // xmm5_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  __m128 v19; // xmm2
  __m128 v20; // xmm7
  float v21; // xmm5_4
  __m128 v22; // xmm0
  __m128 v23; // xmm3
  __m128 v24; // xmm4
  __m128 v25; // xmm2
  __m128 v26; // xmm5
  __m128 v27; // xmm0
  __m128 v28; // xmm6
  float v29; // xmm1_4
  float v31; // [esp+2F8h] [ebp-E4h]
  float v32; // [esp+2FCh] [ebp-E0h]
  __int64 v33; // [esp+300h] [ebp-DCh]
  float v34; // [esp+308h] [ebp-D4h]
  __m128i v35; // [esp+30Ch] [ebp-D0h] BYREF
  float v36; // [esp+328h] [ebp-B4h]
  vostok::math::float4_pod v37; // [esp+32Ch] [ebp-B0h]
  __int64 v38; // [esp+33Ch] [ebp-A0h]
  __int64 v39; // [esp+344h] [ebp-98h]
  __int64 v40; // [esp+34Ch] [ebp-90h]
  __int64 v41; // [esp+354h] [ebp-88h]
  vostok::math::float4x4 other; // [esp+35Ch] [ebp-80h] BYREF
  float v43; // [esp+39Ch] [ebp-40h]
  float v44; // [esp+3A0h] [ebp-3Ch]
  float v45; // [esp+3A4h] [ebp-38h]
  float v46; // [esp+3ACh] [ebp-30h]
  float v47; // [esp+3B0h] [ebp-2Ch]
  float v48; // [esp+3B4h] [ebp-28h]
  float v49; // [esp+3BCh] [ebp-20h]
  float v50; // [esp+3C0h] [ebp-1Ch]
  float v51; // [esp+3C4h] [ebp-18h]

  *(float *)&v33 = -lightXZshift->x;
  v5 = -lightXZshift->y;
  LODWORD(v37.w) = clear_value;
  v35.m128i_i64[1] = (unsigned int)clear_value;
  *((float *)&v33 + 1) = v5;
  v6 = -lightXZshift->z;
  v38 = COERCE_UNSIGNED_INT(a3 * 0.5);
  v34 = v6;
  *(_QWORD *)&other.i.x = v38;
  v39 = 0;
  *(_QWORD *)&other.lines[0].elements[2] = 0;
  LODWORD(v40) = 0;
  *((float *)&v40 + 1) = a3 * -0.5;
  *(_QWORD *)&other.lines[1].x = v40;
  v41 = 0;
  memset(&other.lines[1].elements[2], 0, 16);
  v35.m128i_i64[0] = 0;
  v37.x = a3 * 0.5;
  v37.y = a3 * 0.5;
  *(_QWORD *)&other.lines[2].elements[2] = (unsigned int)clear_value;
  v37.z = 0.0;
  other.c = v37;
  invert_impl(
    &other,
    (float)((float)(a3 * -0.5) * (float)(a3 * 0.5)) + (float)((float)((float)(a3 * -0.5) * -0.0) * 0.0));
  z = v7->k.z;
  v9 = v7->j.z;
  y = v7->j.y;
  v11 = v7->k.y;
  x = v7->k.x;
  v32 = v7->i.y;
  v31 = v7->i.z;
  v36 = v7->i.x;
  invert_impl(
    v7,
    (float)((float)((float)((float)(y * z) - (float)(v9 * v11)) * v36)
          - (float)((float)((float)(v7->j.x * z) - (float)(x * v9)) * v32))
  + (float)((float)((float)(v7->j.x * v11) - (float)(x * y)) * v31));
  v14 = (float)((float)((float)(v13[11] * v6) + (float)(v13[7] * *((float *)&v33 + 1)))
              + (float)(v13[3] * *(float *)&v33))
      + v13[15];
  v15 = (float)(*(float *)&clear_value / v14)
      * (float)((float)((float)((float)(v13[9] * v6) + (float)(v32 * *(float *)&v33))
                      + (float)(v13[5] * *((float *)&v33 + 1)))
              + v13[13]);
  v16 = (float)(*(float *)&clear_value / v14)
      * (float)((float)((float)((float)(v13[8] * v6) + (float)(v13[4] * *((float *)&v33 + 1)))
                      + (float)(v36 * *(float *)&v33))
              + v13[12]);
  v17 = (float)(*(float *)&clear_value / v14)
      * (float)((float)((float)((float)(v13[10] * v6) + (float)(v13[6] * *((float *)&v33 + 1)))
                      + (float)(v31 * *(float *)&v33))
              + v13[14]);
  v18 = (float)(*(float *)&clear_value / v14) * v14;
  v31 = (float)(v17 * 0.0) + (float)(v15 * 0.0);
  v19 = (__m128)(unsigned int)v38;
  v19.m128_f32[0] = (float)((float)(*(float *)&v38 * v16) + (float)(v37.x * v18)) + v31;
  v20 = v19;
  *(float *)v35.m128i_i32 = v19.m128_f32[0];
  v21 = v16 * 0.0;
  *(float *)&v35.m128i_i32[1] = (float)((float)((float)(*((float *)&v40 + 1) * v15) + (float)(v37.y * v18)) + v21)
                              + (float)(v17 * 0.0);
  *(float *)&v35.m128i_i32[2] = (float)((float)((float)(v18 * 0.0) + v21) + (float)(v15 * 0.0)) + v17;
  *(float *)&v35.m128i_i32[3] = (float)(v21 + v31) + v18;
  v35 = _mm_load_si128(&v35);
  v20.m128_f32[0] = v19.m128_f32[0] * 0.25;
  v22 = v20;
  v23.m128_i32[0] = COERCE_UNSIGNED_INT(v19.m128_f32[0] * 0.25) & 0x80000000;
  v22.m128_f32[0] = (float)(v20.m128_f32[0] + COERCE_FLOAT(v20.m128_i32[0] & 0x80000000 | 0x4B000000))
                  - COERCE_FLOAT(v20.m128_i32[0] & 0x80000000 | 0x4B000000);
  v24 = v22;
  v24.m128_f32[0] = v22.m128_f32[0] - (float)(v19.m128_f32[0] * 0.25);
  v23.m128_f32[0] = (float)(v19.m128_f32[0] * 0.25)
                  - (float)(v22.m128_f32[0]
                          - COERCE_FLOAT(_mm_cmpgt_ss(v24, v23).m128_u32[0] & (unsigned int)clear_value));
  v25 = (__m128)v35.m128i_u32[1];
  v25.m128_f32[0] = *(float *)&v35.m128i_i32[1] * 0.25;
  v26.m128_i32[0] = COERCE_UNSIGNED_INT(*(float *)&v35.m128i_i32[1] * 0.25) & 0x80000000;
  v27 = v25;
  v27.m128_f32[0] = (float)((float)(*(float *)&v35.m128i_i32[1] * 0.25) + COERCE_FLOAT(v26.m128_i32[0] | 0x4B000000))
                  - COERCE_FLOAT(v26.m128_i32[0] | 0x4B000000);
  v28 = v27;
  v28.m128_f32[0] = v27.m128_f32[0] - (float)(*(float *)&v35.m128i_i32[1] * 0.25);
  v26.m128_f32[0] = (float)((float)(*(float *)&v35.m128i_i32[1] * 0.25)
                          - (float)(v27.m128_f32[0]
                                  - COERCE_FLOAT(_mm_cmpgt_ss(v28, v26).m128_u32[0] & (unsigned int)clear_value)))
                  * 4.0;
  v27.m128_f32[0] = (float)((float)(v46 * v26.m128_f32[0]) + (float)(v43 * (float)(v23.m128_f32[0] * 4.0)))
                  + (float)(v49 * 0.0);
  v25.m128_f32[0] = (float)((float)(v47 * v26.m128_f32[0]) + (float)(v44 * (float)(v23.m128_f32[0] * 4.0)))
                  + (float)(v50 * 0.0);
  v23.m128_f32[0] = (float)((float)(v48 * v26.m128_f32[0]) + (float)(v45 * (float)(v23.m128_f32[0] * 4.0)))
                  + (float)(v51 * 0.0);
  *(float *)&v33 = (float)((float)(other.i.x * v27.m128_f32[0]) + (float)(other.k.x * v23.m128_f32[0]))
                 + (float)(other.j.x * v25.m128_f32[0]);
  *((float *)&v33 + 1) = (float)((float)(other.i.y * v27.m128_f32[0]) + (float)(other.k.y * v23.m128_f32[0]))
                       + (float)(other.j.y * v25.m128_f32[0]);
  v29 = (float)((float)(other.i.z * v27.m128_f32[0]) + (float)(other.k.z * v23.m128_f32[0]))
      + (float)(other.j.z * v25.m128_f32[0]);
  *(_QWORD *)a2 = v33;
  *(float *)(a2 + 8) = v29;
  return (vostok::math::float3 *)a2;
}
