void __usercall btTransformUtil::calculateDiffAxisAngle(
        const btTransform *transform0@<eax>,
        const btTransform *transform1@<ecx>,
        btVector3 *axis,
        float *angle)
{
  float v5; // xmm5_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm7_4
  float v9; // xmm6_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm7_4
  float v15; // xmm4_4
  float v16; // xmm3_4
  float v17; // xmm7_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm6_4
  float v21; // xmm2_4
  unsigned int v22; // xmm2_4
  unsigned int v23; // xmm3_4
  float v24; // xmm6_4
  float v25; // xmm3_4
  float v26; // xmm6_4
  float v27; // xmm7_4
  float v28; // xmm6_4
  float v29; // xmm3_4
  float v30; // xmm6_4
  float v31; // xmm3_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm1_4
  float v35; // xmm4_4
  float v36; // xmm0_4
  const float *v37; // [esp+0h] [ebp-90h]
  const float *v38; // [esp+0h] [ebp-90h]
  float v39; // [esp+14h] [ebp-7Ch]
  float v40; // [esp+18h] [ebp-78h] BYREF
  float v41; // [esp+1Ch] [ebp-74h] BYREF
  btMatrix3x3 v42; // [esp+20h] [ebp-70h] BYREF
  _BYTE v43[12]; // [esp+50h] [ebp-40h]
  int v44; // [esp+5Ch] [ebp-34h]
  btMatrix3x3 v45; // [esp+60h] [ebp-30h] BYREF

  v5 = transform0->m_basis.m_el[1].mVec128.m128_f32[1];
  v6 = transform0->m_basis.m_el[2].mVec128.m128_f32[2];
  v7 = transform0->m_basis.m_el[2].mVec128.m128_f32[1];
  v8 = transform0->m_basis.m_el[2].mVec128.m128_f32[0];
  v9 = transform0->m_basis.m_el[1].mVec128.m128_f32[0];
  v10 = transform0->m_basis.m_el[1].mVec128.m128_f32[2] * v7;
  v41 = transform0->m_basis.m_el[1].mVec128.m128_f32[2];
  v11 = (float)(v5 * v6) - v10;
  v42.m_el[0].mVec128.m128_u64[0] = __PAIR64__(LODWORD(v6), LODWORD(v7));
  v40 = v8;
  v12 = (float)(v8 * v41) - (float)(v9 * v6);
  v13 = (float)(v9 * v7) - (float)(v8 * v5);
  v14 = transform0->m_basis.m_el[0].mVec128.m128_f32[1];
  v15 = s_bm_current_air_resistance
      / (float)((float)((float)(transform0->m_basis.m_el[0].mVec128.m128_f32[0] * v11) + (float)(v14 * v12))
              + (float)(v13 * transform0->m_basis.m_el[0].mVec128.m128_f32[2]));
  v16 = transform0->m_basis.m_el[0].mVec128.m128_f32[0];
  v39 = v14;
  v17 = (float)(transform0->m_basis.m_el[0].mVec128.m128_f32[0] * v5) - (float)(v14 * v9);
  v42.m_el[0].mVec128.m128_u64[1] = __PAIR64__(LODWORD(v5), LODWORD(v9));
  v42.m_el[1].mVec128.m128_f32[1] = (float)((float)(v39 * v40) - (float)(v16 * v42.m_el[0].mVec128.m128_f32[0])) * v15;
  v42.m_el[1].mVec128.m128_f32[2] = v13 * v15;
  v18 = transform0->m_basis.m_el[0].mVec128.m128_f32[2];
  v42.m_el[0].mVec128.m128_f32[2] = (float)((float)(v18 * v9) - (float)(v16 * v41)) * v15;
  v40 = (float)((float)(v16 * v42.m_el[0].mVec128.m128_f32[1]) - (float)(v18 * v40)) * v15;
  v42.m_el[1].mVec128.m128_f32[3] = v12 * v15;
  v42.m_el[1].mVec128.m128_f32[0] = v17 * v15;
  v42.m_el[0].mVec128.m128_f32[3] = (float)((float)(v39 * v41) - (float)(v18 * v5)) * v15;
  v42.m_el[0].mVec128.m128_f32[1] = (float)((float)(v18 * v42.m_el[0].mVec128.m128_f32[0])
                                          - (float)(v39 * v42.m_el[0].mVec128.m128_f32[1]))
                                  * v15;
  v42.m_el[0].mVec128.m128_f32[0] = v11 * v15;
  btMatrix3x3::setValue(
    &v42,
    (int)&v45,
    &v42.m_el[0].mVec128.m128_f32[1],
    &v42.m_el[0].mVec128.m128_f32[3],
    &v42.m_el[1].mVec128.m128_f32[3],
    &v40,
    &v42.m_el[0].mVec128.m128_f32[2],
    &v42.m_el[1].mVec128.m128_f32[2],
    &v42.m_el[1].mVec128.m128_f32[1],
    v42.m_el[1].mVec128.m128_f32,
    v37);
  v19 = transform1->m_basis.m_el[2].mVec128.m128_f32[0];
  v20 = transform1->m_basis.m_el[2].mVec128.m128_f32[2];
  v21 = transform1->m_basis.m_el[2].mVec128.m128_f32[1];
  v42.m_el[1].mVec128.m128_f32[3] = (float)((float)(v21 * v45.m_el[1].mVec128.m128_f32[2])
                                          + (float)(v20 * v45.m_el[2].mVec128.m128_f32[2]))
                                  + (float)(v19 * v45.m_el[0].mVec128.m128_f32[2]);
  *(float *)&v22 = (float)((float)(v21 * v45.m_el[1].mVec128.m128_f32[1])
                         + (float)(transform1->m_basis.m_el[2].mVec128.m128_f32[2] * v45.m_el[2].mVec128.m128_f32[1]))
                 + (float)(v19 * v45.m_el[0].mVec128.m128_f32[1]);
  *(float *)&v23 = (float)((float)(transform1->m_basis.m_el[2].mVec128.m128_f32[1] * v45.m_el[1].mVec128.m128_f32[0])
                         + (float)(v20 * v45.m_el[2].mVec128.m128_f32[0]))
                 + (float)(v45.m_el[0].mVec128.m128_f32[0] * transform1->m_basis.m_el[2].mVec128.m128_f32[0]);
  v24 = transform1->m_basis.m_el[1].mVec128.m128_f32[2];
  *(unsigned __int64 *)((char *)v42.m_el[1].mVec128.m128_u64 + 4) = __PAIR64__(v22, v23);
  v25 = (float)((float)(transform1->m_basis.m_el[1].mVec128.m128_f32[1] * v45.m_el[1].mVec128.m128_f32[2])
              + (float)(v24 * v45.m_el[2].mVec128.m128_f32[2]))
      + (float)(v45.m_el[0].mVec128.m128_f32[2] * transform1->m_basis.m_el[1].mVec128.m128_f32[0]);
  v26 = transform1->m_basis.m_el[1].mVec128.m128_f32[2] * v45.m_el[2].mVec128.m128_f32[1];
  v42.m_el[1].mVec128.m128_f32[0] = v25;
  v42.m_el[0].mVec128.m128_f32[3] = (float)((float)(transform1->m_basis.m_el[1].mVec128.m128_f32[1]
                                                  * v45.m_el[1].mVec128.m128_f32[1])
                                          + v26)
                                  + (float)(transform1->m_basis.m_el[1].mVec128.m128_f32[0]
                                          * v45.m_el[0].mVec128.m128_f32[1]);
  v27 = transform1->m_basis.m_el[0].mVec128.m128_f32[2];
  v28 = transform1->m_basis.m_el[0].mVec128.m128_f32[1];
  v42.m_el[0].mVec128.m128_f32[2] = (float)((float)(transform1->m_basis.m_el[1].mVec128.m128_f32[1]
                                                  * v45.m_el[1].mVec128.m128_f32[0])
                                          + (float)(transform1->m_basis.m_el[1].mVec128.m128_f32[2]
                                                  * v45.m_el[2].mVec128.m128_f32[0]))
                                  + (float)(transform1->m_basis.m_el[1].mVec128.m128_f32[0]
                                          * v45.m_el[0].mVec128.m128_f32[0]);
  v29 = transform1->m_basis.m_el[0].mVec128.m128_f32[0];
  v42.m_el[0].mVec128.m128_f32[1] = (float)((float)(v45.m_el[2].mVec128.m128_f32[2] * v27)
                                          + (float)(v45.m_el[1].mVec128.m128_f32[2] * v28))
                                  + (float)(transform1->m_basis.m_el[0].mVec128.m128_f32[0]
                                          * v45.m_el[0].mVec128.m128_f32[2]);
  v42.m_el[0].mVec128.m128_f32[0] = (float)((float)(v45.m_el[0].mVec128.m128_f32[1] * v29)
                                          + (float)(v45.m_el[2].mVec128.m128_f32[1] * v27))
                                  + (float)(v45.m_el[1].mVec128.m128_f32[1] * v28);
  v41 = (float)((float)(v45.m_el[2].mVec128.m128_f32[0] * v27) + (float)(v45.m_el[1].mVec128.m128_f32[0] * v28))
      + (float)(v29 * v45.m_el[0].mVec128.m128_f32[0]);
  btMatrix3x3::setValue(
    (btMatrix3x3 *)&v41,
    (int)&v45,
    (float *)&v42,
    &v42.m_el[0].mVec128.m128_f32[1],
    &v42.m_el[0].mVec128.m128_f32[2],
    &v42.m_el[0].mVec128.m128_f32[3],
    v42.m_el[1].mVec128.m128_f32,
    &v42.m_el[1].mVec128.m128_f32[1],
    &v42.m_el[1].mVec128.m128_f32[2],
    &v42.m_el[1].mVec128.m128_f32[3],
    v38);
  btMatrix3x3::getRotation(&v45, (btQuaternion *)&v42.m_el[2]);
  v30 = fsqrt(
          (float)((float)((float)(v42.m_el[2].mVec128.m128_f32[1] * v42.m_el[2].mVec128.m128_f32[1])
                        + (float)(v42.m_el[2].mVec128.m128_f32[2] * v42.m_el[2].mVec128.m128_f32[2]))
                + (float)(v42.m_el[2].mVec128.m128_f32[3] * v42.m_el[2].mVec128.m128_f32[3]))
        + (float)(v42.m_el[2].mVec128.m128_f32[0] * v42.m_el[2].mVec128.m128_f32[0]));
  v31 = v42.m_el[2].mVec128.m128_f32[3] * (float)(s_bm_current_air_resistance / v30);
  v42.m_el[2].mVec128.m128_f32[0] = v42.m_el[2].mVec128.m128_f32[0] * (float)(s_bm_current_air_resistance / v30);
  v42.m_el[2].mVec128.m128_f32[1] = v42.m_el[2].mVec128.m128_f32[1] * (float)(s_bm_current_air_resistance / v30);
  v42.m_el[2].mVec128.m128_f32[2] = v42.m_el[2].mVec128.m128_f32[2] * (float)(s_bm_current_air_resistance / v30);
  if ( v31 < -1.0 )
    v31 = FLOAT_N1_0;
  if ( v31 > s_bm_current_air_resistance )
    v31 = s_bm_current_air_resistance;
  __libm_sse2_acos();
  *angle = v31 * 2.0;
  *(_QWORD *)v43 = v42.m_el[2].mVec128.m128_u64[0];
  *(_DWORD *)&v43[8] = v42.m_el[2].mVec128.m128_i32[2];
  v44 = 0;
  axis->mVec128.m128_i32[0] = v42.m_el[2].mVec128.m128_i32[0];
  *(unsigned __int64 *)((char *)axis->mVec128.m128_u64 + 4) = *(_QWORD *)&v43[4];
  axis->mVec128.m128_i32[3] = v44;
  v32 = axis->mVec128.m128_f32[1];
  v33 = axis->mVec128.m128_f32[0];
  v34 = axis->mVec128.m128_f32[2];
  v35 = (float)((float)(v33 * v33) + (float)(v32 * v32)) + (float)(v34 * v34);
  axis->mVec128.m128_i32[3] = 0;
  if ( v35 >= 1.4210855e-14 )
  {
    v36 = s_bm_current_air_resistance / fsqrt(v35);
    axis->mVec128.m128_f32[0] = v33 * v36;
    axis->mVec128.m128_f32[1] = v32 * v36;
    axis->mVec128.m128_f32[2] = v34 * v36;
  }
  else
  {
    *(float *)v43 = s_bm_current_air_resistance;
    *(_QWORD *)&v43[4] = 0;
    v44 = 0;
    axis->mVec128.m128_f32[0] = s_bm_current_air_resistance;
    *(unsigned __int64 *)((char *)axis->mVec128.m128_u64 + 4) = *(_QWORD *)&v43[4];
    axis->mVec128.m128_i32[3] = v44;
  }
}
