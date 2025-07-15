btMatrix3x3 *__usercall ImpulseMatrix_0@<eax>(
        const btVector3 *rb@<ecx>,
        const float *a2@<esi>,
        int ima,
        const btMatrix3x3 *iia,
        const btMatrix3x3 *ra,
        const btVector3 *imb,
        const btMatrix3x3 *iib,
        const btMatrix3x3 *a8)
{
  btMatrix3x3 *v8; // esi
  btMatrix3x3 *v9; // eax
  float *v10; // eax
  float v11; // xmm5_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm6_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm7_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm4_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm7_4
  float v28; // xmm5_4
  float v29; // xmm6_4
  float v30; // xmm5_4
  float v31; // xmm1_4
  float v32; // xmm6_4
  float v33; // xmm5_4
  float v34; // xmm3_4
  float v37; // [esp+10h] [ebp-C4h] BYREF
  float v38; // [esp+14h] [ebp-C0h] BYREF
  float v39; // [esp+18h] [ebp-BCh] BYREF
  float v40; // [esp+1Ch] [ebp-B8h] BYREF
  btMatrix3x3 v41; // [esp+20h] [ebp-B4h] BYREF
  _BYTE v42[48]; // [esp+74h] [ebp-60h] BYREF
  _BYTE v43[48]; // [esp+A4h] [ebp-30h] BYREF

  v8 = MassMatrix(a8, rb, COERCE_FLOAT(v42), (unsigned int)iib);
  v9 = MassMatrix(ra, imb, COERCE_FLOAT((btMatrix3x3 *)&v41.m_el[2].m_floats[1]), (unsigned int)iia);
  v10 = (float *)Add(v9, v8, (int)v43);
  v11 = v10[5];
  v12 = v10[10];
  v13 = v10[9];
  v14 = v10[4];
  v15 = (float)(v11 * v12) - (float)(v10[6] * v13);
  v16 = v10[8];
  v17 = v16 * v11;
  v18 = (float)(v16 * v10[6]) - (float)(v14 * v12);
  v19 = v14 * v13;
  v20 = *v10;
  v21 = v19 - v17;
  v22 = v10[1] * v18;
  v41.m_el[1].mVec128.m128_f32[2] = v18;
  v23 = (float)(v20 * v15) + v22;
  v24 = v10[1];
  v25 = s_bm_current_air_resistance / (float)(v23 + (float)(v21 * v10[2]));
  v26 = *v10;
  v27 = (float)(*v10 * v11) - (float)(v24 * v14);
  v28 = v10[8];
  v38 = v27 * v25;
  v29 = v24 * v28;
  v30 = v10[4];
  v41.m_el[0].mVec128.m128_f32[3] = (float)(v29 - (float)(v26 * v10[9])) * v25;
  v40 = v21 * v25;
  v31 = v10[2];
  v32 = v31 * v30;
  v33 = v10[10];
  v41.m_el[0].mVec128.m128_f32[2] = (float)(v32 - (float)(v26 * v10[6])) * v25;
  v41.m_el[0].mVec128.m128_f32[1] = (float)((float)(v26 * v33) - (float)(v31 * v10[8])) * v25;
  v41.m_el[1].mVec128.m128_f32[0] = v25 * v41.m_el[1].mVec128.m128_f32[2];
  v34 = v10[9];
  v37 = (float)((float)(v24 * v10[6]) - (float)(v31 * v10[5])) * v25;
  v39 = (float)((float)(v31 * v34) - (float)(v24 * v33)) * v25;
  v41.m_el[0].mVec128.m128_f32[0] = v15 * v25;
  btMatrix3x3::setValue(
    &v41,
    ima,
    &v39,
    &v37,
    v41.m_el[1].mVec128.m128_f32,
    &v41.m_el[0].mVec128.m128_f32[1],
    &v41.m_el[0].mVec128.m128_f32[2],
    &v40,
    &v41.m_el[0].mVec128.m128_f32[3],
    &v38,
    a2);
  return (btMatrix3x3 *)ima;
}
