vostok::math::float3 *__userpurge vostok::render::stage_shadow_direct::compute_aligment@<eax>(
        const vostok::math::float3 *lightXZshift@<eax>,
        vostok::math::float3 *gran@<edi>,
        int a3@<esi>,
        vostok::render::stage_shadow_direct *this,
        float smap_res,
        float mult)
{
  float v7; // xmm0_4
  float v8; // xmm0_4
  const vostok::math::float4x4 *v9; // edx
  float *v10; // edx
  float v11; // xmm1_4
  float v12; // xmm5_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm5_4
  int v19; // xmm1_4
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  __m128 v22; // xmm5
  __m128 v23; // xmm1
  __m128 v24; // xmm6
  __m128 v25; // xmm1
  __m128 v26; // xmm6
  unsigned int v27; // xmm4_4
  float v28; // ecx
  float z; // [esp+2F8h] [ebp-E4h]
  float y; // [esp+2FCh] [ebp-E0h]
  float v32; // [esp+300h] [ebp-DCh]
  __int64 v33; // [esp+300h] [ebp-DCh]
  float v34; // [esp+304h] [ebp-D8h]
  __int64 v35; // [esp+30Ch] [ebp-D0h]
  float x; // [esp+328h] [ebp-B4h]
  __m128i v37; // [esp+32Ch] [ebp-B0h] BYREF
  vostok::math::float4_pod v38; // [esp+33Ch] [ebp-A0h]
  float v39; // [esp+34Ch] [ebp-90h]
  int v40; // [esp+350h] [ebp-8Ch]
  __int64 v41; // [esp+354h] [ebp-88h]
  vostok::math::float4x4 other; // [esp+35Ch] [ebp-80h] BYREF
  float v43; // [esp+39Ch] [ebp-40h]
  int v44; // [esp+3A0h] [ebp-3Ch]
  float v45; // [esp+3A4h] [ebp-38h]
  float v46; // [esp+3ACh] [ebp-30h]
  float v47; // [esp+3B0h] [ebp-2Ch]
  int v48; // [esp+3B4h] [ebp-28h]
  float v49; // [esp+3BCh] [ebp-20h]
  float v50; // [esp+3C0h] [ebp-1Ch]
  float v51; // [esp+3C4h] [ebp-18h]

  v32 = -lightXZshift->x;
  v7 = -lightXZshift->y;
  LODWORD(v38.w) = clear_value;
  v37.m128i_i64[1] = (unsigned int)clear_value;
  v34 = v7;
  v8 = -lightXZshift->z;
  v39 = *(float *)&this * 0.5;
  v40 = 0;
  *(_QWORD *)&other.i.x = COERCE_UNSIGNED_INT(*(float *)&this * 0.5);
  v41 = 0;
  *(_QWORD *)&other.lines[0].elements[2] = 0;
  LODWORD(v35) = 0;
  *((float *)&v35 + 1) = *(float *)&this * -0.5;
  *(_QWORD *)&other.lines[1].x = v35;
  memset(&other.lines[1].elements[2], 0, 16);
  v37.m128i_i64[0] = 0;
  v38.x = *(float *)&this * 0.5;
  v38.y = *(float *)&this * 0.5;
  *(_QWORD *)&other.lines[2].elements[2] = (unsigned int)clear_value;
  v38.z = 0.0;
  other.c = v38;
  invert_impl(
    &other,
    (float)((float)(*(float *)&this * -0.5) * (float)(*(float *)&this * 0.5))
  + (float)((float)((float)(*(float *)&this * -0.5) * -0.0) * 0.0));
  y = v9->i.y;
  z = v9->i.z;
  x = v9->i.x;
  invert_impl(
    v9,
    (float)((float)((float)((float)(v9->j.y * v9->k.z) - (float)(v9->j.z * v9->k.y)) * v9->i.x)
          - (float)((float)((float)(v9->j.x * v9->k.z) - (float)(v9->k.x * v9->j.z)) * y))
  + (float)((float)((float)(v9->j.x * v9->k.y) - (float)(v9->k.x * v9->j.y)) * z));
  v11 = (float)((float)((float)(v10[11] * v8) + (float)(v10[7] * v34)) + (float)(v10[3] * v32)) + v10[15];
  v12 = (float)(*(float *)&clear_value / v11)
      * (float)((float)((float)((float)(v10[8] * v8) + (float)(v10[4] * v34)) + (float)(x * v32)) + v10[12]);
  v13 = (float)(*(float *)&clear_value / v11)
      * (float)((float)((float)((float)(v10[9] * v8) + (float)(y * v32)) + (float)(v10[5] * v34)) + v10[13]);
  v14 = (float)(*(float *)&clear_value / v11)
      * (float)((float)((float)((float)(v10[10] * v8) + (float)(v10[6] * v34)) + (float)(z * v32)) + v10[14]);
  v15 = (float)(*(float *)&clear_value / v11) * v11;
  v16 = v13 * 0.0;
  v17 = (float)(v14 * 0.0) + (float)(v13 * 0.0);
  *(float *)v37.m128i_i32 = (float)((float)((float)(*(float *)&this * 0.5) * v12)
                                  + (float)((float)(*(float *)&this * 0.5) * v15))
                          + v17;
  v18 = v12 * 0.0;
  *(float *)&v19 = (float)((float)((float)((float)(*(float *)&this * -0.5) * v13)
                                 + (float)((float)(*(float *)&this * 0.5) * v15))
                         + v18)
                 + (float)(v14 * 0.0);
  v20 = (__m128)(unsigned int)clear_value;
  v37.m128i_i32[1] = v19;
  *(float *)&v37.m128i_i32[2] = (float)((float)((float)(v15 * 0.0) + v18) + v16) + v14;
  v20.m128_f32[0] = *(float *)&clear_value / (float)(smap_res * 4.0);
  v21 = v20;
  v21.m128_f32[0] = v20.m128_f32[0] * *(float *)v37.m128i_i32;
  *(float *)&v37.m128i_i32[3] = (float)(v18 + v17) + v15;
  v20.m128_f32[0] = v20.m128_f32[0] * COERCE_FLOAT(_mm_load_si128(&v37).m128i_i32[1]);
  v22.m128_i32[0] = v21.m128_i32[0] & 0x80000000;
  v23 = v21;
  v23.m128_f32[0] = (float)(v21.m128_f32[0] + COERCE_FLOAT(v21.m128_i32[0] & 0x80000000 | 0x4B000000))
                  - COERCE_FLOAT(v21.m128_i32[0] & 0x80000000 | 0x4B000000);
  v24 = v23;
  v24.m128_f32[0] = v23.m128_f32[0] - v21.m128_f32[0];
  v21.m128_f32[0] = v21.m128_f32[0]
                  - (float)(v23.m128_f32[0]
                          - COERCE_FLOAT(_mm_cmpgt_ss(v24, v22).m128_u32[0] & (unsigned int)clear_value));
  v22.m128_i32[0] = v20.m128_i32[0] & 0x80000000;
  v25 = v20;
  v25.m128_f32[0] = (float)(v20.m128_f32[0] + COERCE_FLOAT(v20.m128_i32[0] & 0x80000000 | 0x4B000000))
                  - COERCE_FLOAT(v20.m128_i32[0] & 0x80000000 | 0x4B000000);
  v26 = v25;
  v26.m128_f32[0] = v25.m128_f32[0] - v20.m128_f32[0];
  v26.m128_f32[0] = _mm_cmpgt_ss(v26, v22).m128_f32[0];
  v22.m128_f32[0] = v21.m128_f32[0] * (float)(smap_res * 4.0);
  v21.m128_i32[0] = v44;
  *(float *)&v27 = (float)(v20.m128_f32[0]
                         - (float)(v25.m128_f32[0] - COERCE_FLOAT(v26.m128_i32[0] & (unsigned int)clear_value)))
                 * (float)(smap_res * 4.0);
  v20.m128_f32[0] = v43 * v22.m128_f32[0];
  *(_QWORD *)&gran->x = __PAIR64__(v27, v22.m128_u32[0]);
  v25.m128_f32[0] = (float)((float)(v46 * *(float *)&v27) + v20.m128_f32[0]) + (float)(v49 * 0.0);
  v20.m128_f32[0] = (float)((float)(v47 * *(float *)&v27) + (float)(v21.m128_f32[0] * v22.m128_f32[0]))
                  + (float)(v50 * 0.0);
  v21.m128_i32[0] = v48;
  gran->z = 0.0;
  v21.m128_f32[0] = (float)((float)(v21.m128_f32[0] * *(float *)&v27) + (float)(v45 * v22.m128_f32[0]))
                  + (float)(v51 * 0.0);
  *(float *)&v33 = (float)((float)(other.i.x * v25.m128_f32[0]) + (float)(other.k.x * v21.m128_f32[0]))
                 + (float)(other.j.x * v20.m128_f32[0]);
  *((float *)&v33 + 1) = (float)((float)(other.i.y * v25.m128_f32[0]) + (float)(other.k.y * v21.m128_f32[0]))
                       + (float)(other.j.y * v20.m128_f32[0]);
  v28 = (float)((float)(other.i.z * v25.m128_f32[0]) + (float)(other.k.z * v21.m128_f32[0]))
      + (float)(other.j.z * v20.m128_f32[0]);
  *(_QWORD *)a3 = v33;
  *(float *)(a3 + 8) = v28;
  return (vostok::math::float3 *)a3;
}
