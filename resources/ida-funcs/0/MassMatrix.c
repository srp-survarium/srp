btMatrix3x3 *__usercall MassMatrix@<eax>(
        const btMatrix3x3 *iwi@<eax>,
        const btVector3 *r@<ecx>,
        float im,
        unsigned int a4)
{
  float v4; // xmm3_4
  int v5; // xmm1_4
  float v6; // xmm5_4
  float v7; // xmm6_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm7_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm5_4
  float v14; // xmm3_4
  float v15; // xmm5_4
  btMatrix3x3 *v16; // eax
  float *v17; // ecx
  float *v18; // eax
  int v19; // edx
  int v20; // ebx
  _DWORD *v21; // edi
  const float *v23; // [esp+0h] [ebp-E0h]
  const float *v24; // [esp+0h] [ebp-E0h]
  float v25; // [esp+Ch] [ebp-D4h] BYREF
  btMatrix3x3 v26; // [esp+10h] [ebp-D0h] BYREF
  float v27; // [esp+4Ch] [ebp-94h] BYREF
  float v28; // [esp+50h] [ebp-90h]
  float v29; // [esp+58h] [ebp-88h]
  float v30; // [esp+6Ch] [ebp-74h]
  float v31; // [esp+74h] [ebp-6Ch]
  float v32; // [esp+78h] [ebp-68h]
  float v33; // [esp+80h] [ebp-60h] BYREF
  float v34; // [esp+84h] [ebp-5Ch]
  float v35[2]; // [esp+88h] [ebp-58h] BYREF
  float v36; // [esp+90h] [ebp-50h]
  float v37; // [esp+94h] [ebp-4Ch]
  float v38; // [esp+98h] [ebp-48h]
  float v39; // [esp+A0h] [ebp-40h]
  float v40; // [esp+A4h] [ebp-3Ch]
  float v41; // [esp+A8h] [ebp-38h]
  btMatrix3x3 v42; // [esp+B0h] [ebp-30h] BYREF

  v4 = r->mVec128.m128_f32[0];
  v5 = r->mVec128.m128_i32[1];
  v6 = iwi->m_el[0].mVec128.m128_f32[1];
  v7 = iwi->m_el[0].mVec128.m128_f32[0];
  v28 = r->mVec128.m128_f32[2];
  v25 = v6;
  LODWORD(v29) = LODWORD(v4) ^ _mask__NegFloat_;
  v8 = iwi->m_el[0].mVec128.m128_f32[2];
  v26.m_el[2].mVec128.m128_f32[1] = v4;
  v32 = *(float *)&v5;
  v9 = iwi->m_el[1].mVec128.m128_f32[2];
  LODWORD(v10) = v5 ^ _mask__NegFloat_;
  v11 = iwi->m_el[2].mVec128.m128_f32[2];
  v26.m_el[0].mVec128.m128_f32[3] = v8;
  v30 = v9;
  v26.m_el[0].mVec128.m128_f32[0] = v7;
  v26.m_el[0].mVec128.m128_i32[2] = iwi->m_el[1].mVec128.m128_i32[1];
  v27 = (float)((float)(v8 * v10) + (float)(v9 * v4)) + (float)(v11 * 0.0);
  v12 = iwi->m_el[2].mVec128.m128_f32[1];
  v13 = (float)((float)(v6 * v10) + (float)(v26.m_el[0].mVec128.m128_f32[2] * v4)) + (float)(v12 * 0.0);
  v14 = iwi->m_el[2].mVec128.m128_f32[0];
  v26.m_el[1].mVec128.m128_f32[0] = v13;
  v26.m_el[0].mVec128.m128_i32[1] = iwi->m_el[1].mVec128.m128_i32[0];
  v26.m_el[1].mVec128.m128_f32[2] = (float)((float)(v7 * v10)
                                          + (float)(v26.m_el[0].mVec128.m128_f32[1] * v26.m_el[2].mVec128.m128_f32[1]))
                                  + (float)(v14 * 0.0);
  v26.m_el[1].mVec128.m128_f32[3] = (float)((float)(v26.m_el[0].mVec128.m128_f32[3] * v28) + (float)(v11 * v29))
                                  + (float)(v9 * 0.0);
  v26.m_el[1].mVec128.m128_f32[1] = (float)((float)(v25 * v28) + (float)(v12 * v29))
                                  + (float)(v26.m_el[0].mVec128.m128_f32[2] * 0.0);
  v15 = v26.m_el[0].mVec128.m128_f32[1];
  v26.m_el[2].mVec128.m128_f32[0] = v10;
  LODWORD(v31) = LODWORD(v28) ^ _mask__NegFloat_;
  v26.m_el[0].mVec128.m128_f32[1] = (float)((float)(v7 * v28) + (float)(v14 * v29))
                                  + (float)(v26.m_el[0].mVec128.m128_f32[1] * 0.0);
  v26.m_el[0].mVec128.m128_f32[3] = (float)((float)(v11 * v32)
                                          + (float)(v9 * COERCE_FLOAT(LODWORD(v28) ^ _mask__NegFloat_)))
                                  + (float)(v26.m_el[0].mVec128.m128_f32[3] * 0.0);
  v25 = (float)((float)(v12 * v32)
              + (float)(v26.m_el[0].mVec128.m128_f32[2] * COERCE_FLOAT(LODWORD(v28) ^ _mask__NegFloat_)))
      + (float)(v25 * 0.0);
  v26.m_el[0].mVec128.m128_f32[0] = (float)((float)(v14 * v32)
                                          + (float)(v15 * COERCE_FLOAT(LODWORD(v28) ^ _mask__NegFloat_)))
                                  + (float)(v7 * 0.0);
  btMatrix3x3::setValue(
    &v26,
    (int)&v33,
    &v25,
    &v26.m_el[0].mVec128.m128_f32[3],
    &v26.m_el[0].mVec128.m128_f32[1],
    &v26.m_el[1].mVec128.m128_f32[1],
    &v26.m_el[1].mVec128.m128_f32[3],
    &v26.m_el[1].mVec128.m128_f32[2],
    v26.m_el[1].mVec128.m128_f32,
    &v27,
    v23);
  v26.m_el[1].mVec128.m128_f32[1] = (float)((float)(v40 * v29) + (float)(v39 * v32)) + (float)(v41 * 0.0);
  v26.m_el[1].mVec128.m128_f32[3] = (float)((float)(v41 * v26.m_el[2].mVec128.m128_f32[1]) + (float)(v39 * v31))
                                  + (float)(v40 * 0.0);
  v26.m_el[1].mVec128.m128_f32[2] = (float)((float)(v41 * v26.m_el[2].mVec128.m128_f32[0]) + (float)(v40 * v28))
                                  + (float)(v39 * 0.0);
  v26.m_el[1].mVec128.m128_f32[0] = (float)((float)(v37 * v29) + (float)(v36 * v32)) + (float)(v38 * 0.0);
  v27 = (float)((float)(v38 * v26.m_el[2].mVec128.m128_f32[1]) + (float)(v36 * v31)) + (float)(v37 * 0.0);
  v26.m_el[0].mVec128.m128_f32[1] = (float)((float)(v38 * v26.m_el[2].mVec128.m128_f32[0]) + (float)(v37 * v28))
                                  + (float)(v36 * 0.0);
  v26.m_el[0].mVec128.m128_f32[0] = (float)((float)(v34 * v29) + (float)(v33 * v32)) + (float)(v35[0] * 0.0);
  v25 = (float)((float)(v35[0] * v26.m_el[2].mVec128.m128_f32[1]) + (float)(v33 * v31)) + (float)(v34 * 0.0);
  v26.m_el[0].mVec128.m128_f32[2] = (float)((float)(v35[0] * v26.m_el[2].mVec128.m128_f32[0]) + (float)(v34 * v28))
                                  + (float)(v33 * 0.0);
  btMatrix3x3::setValue(
    (btMatrix3x3 *)&v26.m_el[0].m_floats[2],
    (int)&v33,
    &v25,
    (float *)&v26,
    &v26.m_el[0].mVec128.m128_f32[1],
    &v27,
    v26.m_el[1].mVec128.m128_f32,
    &v26.m_el[1].mVec128.m128_f32[2],
    &v26.m_el[1].mVec128.m128_f32[3],
    &v26.m_el[1].mVec128.m128_f32[1],
    v24);
  v16 = Diagonal(&v42, a4);
  v17 = v35;
  v18 = &v16->m_el[0].mVec128.m128_f32[2];
  v26.m_el[2].mVec128.m128_i32[3] = 0;
  v19 = LODWORD(im) - (_DWORD)v35;
  v20 = 3;
  do
  {
    v26.m_el[2].mVec128.m128_f32[0] = *(v18 - 2) - *(v17 - 2);
    v26.m_el[2].mVec128.m128_f32[1] = *(v18 - 1) - *(v17 - 1);
    v26.m_el[2].mVec128.m128_f32[2] = *v18 - *v17;
    *(_QWORD *)((char *)v17 + v19) = v26.m_el[2].mVec128.m128_u64[0];
    *(float *)((char *)v17 + v19 + 8) = v26.m_el[2].mVec128.m128_f32[2];
    v21 = (_DWORD *)((char *)v17 + v19 + 12);
    v17 += 4;
    v18 += 4;
    --v20;
    *v21 = v26.m_el[2].mVec128.m128_i32[3];
  }
  while ( v20 );
  return (btMatrix3x3 *)LODWORD(im);
}
