vostok::render::stage_shadow_direct *__userpurge vostok::render::stage_shadow_direct::compute_aligment@<eax>(
        const vostok::math::float3 *light_xz_shift@<eax>,
        float a2@<xmm3>,
        vostok::render::stage_shadow_direct *this,
        float *mult,
        vostok::math::float3 *gran)
{
  float v5; // xmm1_4
  const vostok::math::float4x4 *v6; // edx
  float *v7; // edx
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  signed int v12; // eax
  signed int v13; // eax
  signed int v14; // eax
  float v15; // xmm5_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm5_4
  float v22; // xmm4_4
  float x; // xmm3_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm4_4
  float v27; // xmm3_4
  float y; // xmm4_4
  vostok::render::stage_shadow_direct *result; // eax
  vostok::math::float4x4 v30; // [esp+Ch] [ebp-D8h] BYREF
  vostok::math::float4x4 v31; // [esp+4Ch] [ebp-98h] BYREF
  int v32; // [esp+8Ch] [ebp-58h]
  float v33; // [esp+90h] [ebp-54h]
  int v34; // [esp+94h] [ebp-50h]
  int v35; // [esp+98h] [ebp-4Ch]
  float v36; // [esp+9Ch] [ebp-48h]
  int v37; // [esp+A0h] [ebp-44h]
  int v38; // [esp+A4h] [ebp-40h]
  int v39; // [esp+A8h] [ebp-3Ch]
  float v40; // [esp+ACh] [ebp-38h]
  float v41; // [esp+B0h] [ebp-34h]
  int v42; // [esp+B4h] [ebp-30h]
  float v43; // [esp+B8h] [ebp-2Ch]
  float v44; // [esp+BCh] [ebp-28h]
  float v45; // [esp+C0h] [ebp-24h]
  float v46; // [esp+C4h] [ebp-20h]
  float v47; // [esp+C8h] [ebp-1Ch]
  float v48; // [esp+CCh] [ebp-18h]
  float v49; // [esp+D0h] [ebp-14h]
  float v50; // [esp+D4h] [ebp-10h]
  float v51; // [esp+D8h] [ebp-Ch]
  float v52; // [esp+DCh] [ebp-8h]
  float v53; // [esp+E0h] [ebp-4h]

  LODWORD(v50) = LODWORD(light_xz_shift->x) ^ _mask__NegFloat_;
  LODWORD(v51) = LODWORD(light_xz_shift->y) ^ _mask__NegFloat_;
  LODWORD(v5) = LODWORD(light_xz_shift->z) ^ _mask__NegFloat_;
  v36 = a2 * 0.5;
  v37 = 0;
  v38 = 0;
  v39 = 0;
  v31.i.x = a2 * 0.5;
  memset(&v31.e01, 0, 16);
  v32 = 0;
  v33 = a2 * -0.5;
  v34 = 0;
  v35 = 0;
  v31.j.y = a2 * -0.5;
  memset(&v31.lines[1].elements[2], 0, 16);
  v45 = 0.0;
  v46 = 0.0;
  v48 = 0.0;
  v52 = v5;
  v47 = s_bm_current_air_resistance;
  *(_QWORD *)&v31.lines[2].elements[2] = LODWORD(s_bm_current_air_resistance);
  v40 = a2 * 0.5;
  v41 = a2 * 0.5;
  v42 = 0;
  v43 = s_bm_current_air_resistance;
  v31.c.x = a2 * 0.5;
  v31.c.y = a2 * 0.5;
  v31.c.z = 0.0;
  v31.c.w = s_bm_current_air_resistance;
  vostok::math::invert4x3(&v31, &v30);
  vostok::math::invert4x3(v6, &v31);
  v8 = (float)((float)((float)(v7[7] * v51) + (float)(v7[11] * v52)) + (float)(v7[3] * v50)) + v7[15];
  v9 = (float)(s_bm_current_air_resistance / v8)
     * (float)((float)((float)((float)(v7[4] * v51) + (float)(v7[8] * v52)) + (float)(*v7 * v50)) + v7[12]);
  v10 = (float)(s_bm_current_air_resistance / v8)
      * (float)((float)((float)((float)(v7[5] * v51) + (float)(v7[9] * v52)) + (float)(v7[1] * v50)) + v7[13]);
  v11 = (float)(s_bm_current_air_resistance / v8)
      * (float)((float)((float)((float)(v7[6] * v51) + (float)(v7[10] * v52)) + (float)(v7[2] * v50)) + v7[14]);
  v52 = (float)(s_bm_current_air_resistance / v8) * v8;
  v44 = v10 * 0.0;
  v53 = (float)(v10 * 0.0) + (float)(v11 * 0.0);
  v46 = (float)((float)((float)(v33 * v10) + (float)(v41 * v52)) + (float)(v9 * 0.0)) + (float)(v11 * 0.0);
  v45 = (float)((float)(v36 * v9) + (float)(v40 * v52)) + v53;
  v48 = (float)((float)(v9 * 0.0) + v53) + v52;
  v47 = (float)((float)((float)(v52 * 0.0) + (float)(v9 * 0.0)) + (float)(v10 * 0.0)) + v11;
  v49 = v45;
  v50 = v46;
  v51 = v47;
  v53 = v45 * 0.125;
  v52 = v48;
  v12 = vostok::math::floor(v45 * 0.125);
  v49 = v53 - (float)v12;
  v53 = v50 * 0.125;
  v13 = vostok::math::floor(v50 * 0.125);
  v50 = v53 - (float)v13;
  v53 = v51 * 12.5;
  v14 = vostok::math::floor(v51 * 12.5);
  v15 = (float)(v53 - (float)v14) * 0.079999998;
  v16 = v30.j.y * (float)(v50 * gran1);
  v17 = (float)(v30.k.x * v15) + (float)(v30.j.x * (float)(v50 * gran1));
  v50 = v50 * gran1;
  v18 = v17 + (float)(v30.i.x * (float)(v49 * gran1));
  v49 = v49 * gran1;
  v19 = (float)((float)(v30.k.y * v15) + v16) + (float)(v30.i.y * v49);
  v51 = v15;
  v20 = v30.k.z * v15;
  v21 = v30.j.z * v50;
  v22 = v30.i.z * v49;
  x = v31.i.x;
  *mult = v49;
  v24 = (float)(v20 + v21) + v22;
  v25 = (float)(x * v18) + (float)(v31.k.x * v24);
  v26 = v31.j.x;
  mult[1] = v50;
  v27 = v25 + (float)(v26 * v19);
  y = v31.k.y;
  mult[2] = v51;
  result = this;
  v51 = (float)((float)(v31.i.y * v18) + (float)(y * v24)) + (float)(v31.j.y * v19);
  v52 = (float)((float)(v31.i.z * v18) + (float)(v31.k.z * v24)) + (float)(v31.j.z * v19);
  *(float *)&this->__vftable = v27;
  *(float *)&this->m_context = v51;
  *(float *)&this->m_renderer = v52;
  return result;
}
