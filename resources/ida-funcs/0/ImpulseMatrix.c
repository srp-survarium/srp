btMatrix3x3 *__cdecl ImpulseMatrix(int dt, float ima, unsigned int imb, const btMatrix3x3 *iwi, const btMatrix3x3 *a5)
{
  const btVector3 *v5; // ecx
  btMatrix3x3 *v6; // eax
  const btMatrix3x3 *v7; // edx
  btMatrix3x3 *v8; // eax
  float v9; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm7_4
  float v13; // xmm6_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm4_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm4_4
  float v22; // xmm1_4
  float *v23; // eax
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  const float *v35; // [esp+4h] [ebp-130h]
  const float *v36; // [esp+4h] [ebp-130h]
  btMatrix3x3 v37; // [esp+Ch] [ebp-128h] BYREF
  float v38; // [esp+3Ch] [ebp-F8h]
  float v39; // [esp+44h] [ebp-F0h]
  float v40; // [esp+48h] [ebp-ECh]
  float v41; // [esp+4Ch] [ebp-E8h]
  float v42; // [esp+54h] [ebp-E0h]
  float v43; // [esp+58h] [ebp-DCh]
  float v44; // [esp+5Ch] [ebp-D8h]
  float v45; // [esp+68h] [ebp-CCh]
  btMatrix3x3 v46; // [esp+74h] [ebp-C0h] BYREF
  _BYTE v47[48]; // [esp+A4h] [ebp-90h] BYREF
  _BYTE v48[48]; // [esp+D4h] [ebp-60h] BYREF
  btMatrix3x3 v49; // [esp+104h] [ebp-30h] BYREF

  MassMatrix(a5, v5, COERCE_FLOAT(v48), (unsigned int)iwi);
  v6 = Diagonal(&v46, imb);
  v8 = Add(v6, v7, (int)v47);
  v9 = v8->m_el[1].mVec128.m128_f32[1];
  v10 = v8->m_el[2].mVec128.m128_f32[2];
  v11 = v8->m_el[2].mVec128.m128_f32[1];
  v12 = v8->m_el[2].mVec128.m128_f32[0];
  v13 = v8->m_el[1].mVec128.m128_f32[0];
  v14 = (float)(v9 * v10) - (float)(v8->m_el[1].mVec128.m128_f32[2] * v11);
  v37.m_el[1].mVec128.m128_i32[0] = v8->m_el[1].mVec128.m128_i32[2];
  v15 = (float)(v12 * v37.m_el[1].mVec128.m128_f32[0]) - (float)(v13 * v10);
  v16 = v8->m_el[0].mVec128.m128_f32[0];
  v37.m_el[1].mVec128.m128_f32[1] = v12;
  v37.m_el[0].mVec128.m128_u64[0] = __PAIR64__(LODWORD(v10), LODWORD(v11));
  v17 = (float)(v13 * v11) - (float)(v12 * v9);
  v18 = v8->m_el[0].mVec128.m128_f32[1] * v15;
  v37.m_el[0].mVec128.m128_u64[1] = __PAIR64__(LODWORD(v13), LODWORD(v9));
  v45 = v15;
  v19 = v8->m_el[0].mVec128.m128_f32[0];
  v20 = s_bm_current_air_resistance
      / (float)((float)((float)(v16 * v14) + v18) + (float)(v17 * v8->m_el[0].mVec128.m128_f32[2]));
  v21 = v8->m_el[0].mVec128.m128_f32[1];
  v37.m_el[1].mVec128.m128_f32[2] = (float)((float)(v21 * v12)
                                          - (float)(v8->m_el[0].mVec128.m128_f32[0] * v37.m_el[0].mVec128.m128_f32[0]))
                                  * v20;
  v37.m_el[1].mVec128.m128_f32[3] = v17 * v20;
  v22 = v8->m_el[0].mVec128.m128_f32[2];
  v37.m_el[2].mVec128.m128_f32[0] = (float)((float)(v19 * v9) - (float)(v21 * v13)) * v20;
  v37.m_el[0].mVec128.m128_f32[3] = (float)((float)(v22 * v13) - (float)(v19 * v37.m_el[1].mVec128.m128_f32[0])) * v20;
  v37.m_el[1].mVec128.m128_f32[1] = (float)((float)(v19 * v37.m_el[0].mVec128.m128_f32[1]) - (float)(v22 * v12)) * v20;
  v37.m_el[2].mVec128.m128_f32[1] = v20 * v45;
  v37.m_el[0].mVec128.m128_f32[2] = (float)((float)(v21 * v37.m_el[1].mVec128.m128_f32[0]) - (float)(v22 * v9)) * v20;
  v37.m_el[0].mVec128.m128_f32[1] = (float)((float)(v22 * v37.m_el[0].mVec128.m128_f32[0])
                                          - (float)(v21 * v37.m_el[0].mVec128.m128_f32[1]))
                                  * v20;
  v37.m_el[0].mVec128.m128_f32[0] = v14 * v20;
  btMatrix3x3::setValue(
    &v37,
    (int)&v37.m_el[2].mVec128.m128_i32[2],
    &v37.m_el[0].mVec128.m128_f32[1],
    &v37.m_el[0].mVec128.m128_f32[2],
    &v37.m_el[2].mVec128.m128_f32[1],
    &v37.m_el[1].mVec128.m128_f32[1],
    &v37.m_el[0].mVec128.m128_f32[3],
    &v37.m_el[1].mVec128.m128_f32[3],
    &v37.m_el[1].mVec128.m128_f32[2],
    v37.m_el[2].mVec128.m128_f32,
    v35);
  v23 = (float *)Diagonal(&v49, COERCE_UNSIGNED_INT(s_bm_current_air_resistance / ima));
  v24 = v23[10] * v43;
  v37.m_el[2].mVec128.m128_f32[1] = (float)((float)(v23[9] * v41) + (float)(v23[10] * v44)) + (float)(v23[8] * v38);
  v25 = (float)((float)(v23[9] * v40) + v24) + (float)(v23[8] * v37.m_el[2].mVec128.m128_f32[3]);
  v26 = v23[10] * v42;
  v37.m_el[1].mVec128.m128_f32[3] = v25;
  v27 = (float)((float)(v23[9] * v39) + v26) + (float)(v23[8] * v37.m_el[2].mVec128.m128_f32[2]);
  v28 = v23[6] * v44;
  v37.m_el[1].mVec128.m128_f32[2] = v27;
  v37.m_el[2].mVec128.m128_f32[0] = (float)((float)(v23[5] * v41) + v28) + (float)(v23[4] * v38);
  v29 = *v23;
  v30 = v23[6] * v42;
  v37.m_el[0].mVec128.m128_f32[2] = (float)((float)(v23[5] * v40) + (float)(v23[6] * v43))
                                  + (float)(v23[4] * v37.m_el[2].mVec128.m128_f32[3]);
  v31 = (float)((float)(v23[5] * v39) + v30) + (float)(v23[4] * v37.m_el[2].mVec128.m128_f32[2]);
  v32 = v23[1];
  v37.m_el[0].mVec128.m128_f32[3] = v31;
  v33 = v23[2];
  v37.m_el[0].mVec128.m128_f32[1] = (float)((float)(v29 * v38) + (float)(v33 * v44)) + (float)(v32 * v41);
  v37.m_el[0].mVec128.m128_f32[0] = (float)((float)(v33 * v43) + (float)(v32 * v40))
                                  + (float)(v29 * v37.m_el[2].mVec128.m128_f32[3]);
  v37.m_el[1].mVec128.m128_f32[0] = (float)((float)(v33 * v42) + (float)(v29 * v37.m_el[2].mVec128.m128_f32[2]))
                                  + (float)(v32 * v39);
  btMatrix3x3::setValue(
    (btMatrix3x3 *)&v37.m_el[1],
    dt,
    (float *)&v37,
    &v37.m_el[0].mVec128.m128_f32[1],
    &v37.m_el[0].mVec128.m128_f32[3],
    &v37.m_el[0].mVec128.m128_f32[2],
    v37.m_el[2].mVec128.m128_f32,
    &v37.m_el[1].mVec128.m128_f32[2],
    &v37.m_el[1].mVec128.m128_f32[3],
    &v37.m_el[2].mVec128.m128_f32[1],
    v36);
  return (btMatrix3x3 *)dt;
}
