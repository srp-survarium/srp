void __thiscall btSoftBody::updatePose(btSoftBody *this, int a2)
{
  int v2; // esi
  float *v3; // ecx
  float *v4; // edx
  float *v5; // eax
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm5_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm5_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  const btMatrix3x3 *v27; // eax
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm4_4
  float v31; // xmm2_4
  float v32; // xmm5_4
  float v33; // xmm1_4
  float v34; // xmm3_4
  float v35; // xmm7_4
  float v36; // xmm1_4
  btMatrix3x3 *v37; // eax
  btVector3 *v38; // ecx
  _DWORD *v39; // edi
  const float *v40; // [esp+4h] [ebp-F0h]
  const float *v41; // [esp+4h] [ebp-F0h]
  const float *v42; // [esp+4h] [ebp-F0h]
  btMatrix3x3 v43; // [esp+18h] [ebp-DCh] BYREF
  float v44; // [esp+48h] [ebp-ACh]
  float v45; // [esp+4Ch] [ebp-A8h]
  int v46; // [esp+50h] [ebp-A4h]
  float v47; // [esp+5Ch] [ebp-98h] BYREF
  float v48; // [esp+60h] [ebp-94h] BYREF
  float v49; // [esp+64h] [ebp-90h] BYREF
  float v50; // [esp+68h] [ebp-8Ch] BYREF
  float v51; // [esp+6Ch] [ebp-88h] BYREF
  float v52[3]; // [esp+70h] [ebp-84h] BYREF
  float v53; // [esp+7Ch] [ebp-78h]
  int v54; // [esp+80h] [ebp-74h]
  btMatrix3x3 v55; // [esp+84h] [ebp-70h] BYREF
  btMatrix3x3 v56; // [esp+B4h] [ebp-40h] BYREF
  btVector3 v57; // [esp+E4h] [ebp-10h] BYREF

  if ( *(_BYTE *)(a2 + 481) )
  {
    *(btVector3 *)(a2 + 528) = (btVector3)btSoftBody::evaluateCom((btSoftBody *)a2, &v57)->mVec128;
    v52[1] = 0.0;
    v52[2] = 0.0;
    v53 = 0.0;
    v54 = 0;
    v44 = 0.0;
    v45 = 0.0;
    v46 = 0;
    memset(&v43.m_el[2], 0, sizeof(v43.m_el[2]));
    memset(&v43.m_el[0].m_floats[3], 0, 20);
    v2 = *(_DWORD *)(a2 + 720);
    v43.m_el[0].mVec128.m128_f32[3] = FLOAT_1_1920929eN7;
    v43.m_el[2].mVec128.m128_f32[0] = FLOAT_2_3841858eN7;
    v45 = FLOAT_3_5762787eN7;
    if ( v2 > 0 )
    {
      v3 = *(float **)(a2 + 500);
      v4 = *(float **)(a2 + 520);
      v5 = (float *)(*(_DWORD *)(a2 + 728) + 24);
      do
      {
        v6 = *(v5 - 2) - v57.mVec128.m128_f32[0];
        v7 = *(v5 - 1) - v57.mVec128.m128_f32[1];
        v8 = *v4;
        v9 = v3[2];
        v53 = *v4 * (float)(*v5 - v57.mVec128.m128_f32[2]);
        v10 = v8 * v6;
        v11 = *v3;
        v12 = v8 * v7;
        v13 = v3[1];
        v43.m_el[0].mVec128.m128_f32[3] = v43.m_el[0].mVec128.m128_f32[3] + (float)(*v3 * v10);
        v43.m_el[1].mVec128.m128_f32[0] = v43.m_el[1].mVec128.m128_f32[0] + (float)(v13 * v10);
        v43.m_el[1].mVec128.m128_f32[1] = v43.m_el[1].mVec128.m128_f32[1] + (float)(v9 * v10);
        v43.m_el[2].mVec128.m128_f32[0] = v43.m_el[2].mVec128.m128_f32[0] + (float)(v13 * v12);
        v43.m_el[2].mVec128.m128_f32[1] = v43.m_el[2].mVec128.m128_f32[1] + (float)(v9 * v12);
        v43.m_el[2].mVec128.m128_f32[3] = v43.m_el[2].mVec128.m128_f32[3] + (float)(v11 * v53);
        v44 = v44 + (float)(v13 * v53);
        v5 += 28;
        ++v4;
        v3 += 4;
        --v2;
        v43.m_el[1].mVec128.m128_f32[3] = v43.m_el[1].mVec128.m128_f32[3] + (float)(v11 * v12);
        v45 = v45 + (float)(v9 * v53);
      }
      while ( v2 );
    }
    PolarDecompose(&v43.m_el[1].mVec128.m128_f32[3], (btMatrix3x3 *)&v43.m_el[0].m_floats[3], &v56, &v55);
    *(btMatrix3x3 *)(a2 + 544) = v56;
    btMatrix3x3::setValue(
      &v56,
      (int)&v55,
      v56.m_el[1].mVec128.m128_f32,
      v56.m_el[2].mVec128.m128_f32,
      &v56.m_el[0].mVec128.m128_f32[1],
      &v56.m_el[1].mVec128.m128_f32[1],
      &v56.m_el[2].mVec128.m128_f32[1],
      &v56.m_el[0].mVec128.m128_f32[2],
      &v56.m_el[1].mVec128.m128_f32[2],
      &v56.m_el[2].mVec128.m128_f32[2],
      v40);
    v14 = *(float *)(a2 + 680) * v55.m_el[2].mVec128.m128_f32[1];
    v43.m_el[0].mVec128.m128_f32[0] = (float)((float)(*(float *)(a2 + 676) * v55.m_el[1].mVec128.m128_f32[2])
                                            + (float)(*(float *)(a2 + 680) * v55.m_el[2].mVec128.m128_f32[2]))
                                    + (float)(*(float *)(a2 + 672) * v55.m_el[0].mVec128.m128_f32[2]);
    v15 = (float)((float)(*(float *)(a2 + 676) * v55.m_el[1].mVec128.m128_f32[1]) + v14)
        + (float)(v55.m_el[0].mVec128.m128_f32[1] * *(float *)(a2 + 672));
    v16 = *(float *)(a2 + 680) * v55.m_el[2].mVec128.m128_f32[0];
    v51 = v15;
    v17 = (float)((float)(*(float *)(a2 + 676) * v55.m_el[1].mVec128.m128_f32[0]) + v16)
        + (float)(*(float *)(a2 + 672) * v55.m_el[0].mVec128.m128_f32[0]);
    v18 = *(float *)(a2 + 664) * v55.m_el[2].mVec128.m128_f32[2];
    v48 = v17;
    v19 = (float)((float)(*(float *)(a2 + 660) * v55.m_el[1].mVec128.m128_f32[2]) + v18)
        + (float)(*(float *)(a2 + 656) * v55.m_el[0].mVec128.m128_f32[2]);
    v20 = *(float *)(a2 + 664) * v55.m_el[2].mVec128.m128_f32[1];
    v21 = *(float *)(a2 + 648);
    v50 = v19;
    v22 = (float)((float)(*(float *)(a2 + 660) * v55.m_el[1].mVec128.m128_f32[1]) + v20)
        + (float)(*(float *)(a2 + 656) * v55.m_el[0].mVec128.m128_f32[1]);
    v23 = *(float *)(a2 + 664) * v55.m_el[2].mVec128.m128_f32[0];
    v49 = v22;
    v24 = (float)((float)(*(float *)(a2 + 660) * v55.m_el[1].mVec128.m128_f32[0]) + v23)
        + (float)(*(float *)(a2 + 656) * v55.m_el[0].mVec128.m128_f32[0]);
    v25 = *(float *)(a2 + 644);
    v52[0] = v24;
    v26 = *(float *)(a2 + 640);
    v47 = (float)((float)(v21 * v55.m_el[2].mVec128.m128_f32[2]) + (float)(v25 * v55.m_el[1].mVec128.m128_f32[2]))
        + (float)(v26 * v55.m_el[0].mVec128.m128_f32[2]);
    v43.m_el[0].mVec128.m128_f32[1] = (float)((float)(v21 * v55.m_el[2].mVec128.m128_f32[1])
                                            + (float)(v25 * v55.m_el[1].mVec128.m128_f32[1]))
                                    + (float)(v26 * v55.m_el[0].mVec128.m128_f32[1]);
    v43.m_el[0].mVec128.m128_f32[2] = (float)((float)(v26 * v55.m_el[0].mVec128.m128_f32[0])
                                            + (float)(v21 * v55.m_el[2].mVec128.m128_f32[0]))
                                    + (float)(v25 * v55.m_el[1].mVec128.m128_f32[0]);
    btMatrix3x3::setValue(
      (btMatrix3x3 *)&v43.m_el[0].m_floats[2],
      (int)&v56,
      &v43.m_el[0].mVec128.m128_f32[1],
      &v47,
      v52,
      &v49,
      &v50,
      &v48,
      &v51,
      (const float *)&v43,
      v41);
    v43.m_el[0].mVec128.m128_f32[2] = (float)((float)(v56.m_el[2].mVec128.m128_f32[1] * v43.m_el[2].mVec128.m128_f32[1])
                                            + (float)(v56.m_el[2].mVec128.m128_f32[2] * v45))
                                    + (float)(v56.m_el[2].mVec128.m128_f32[0] * v43.m_el[1].mVec128.m128_f32[1]);
    v43.m_el[0].mVec128.m128_f32[1] = (float)((float)(v56.m_el[2].mVec128.m128_f32[2] * v44)
                                            + (float)(v56.m_el[2].mVec128.m128_f32[1] * v43.m_el[2].mVec128.m128_f32[0]))
                                    + (float)(v56.m_el[2].mVec128.m128_f32[0] * v43.m_el[1].mVec128.m128_f32[0]);
    v47 = (float)((float)(v56.m_el[2].mVec128.m128_f32[1] * v43.m_el[1].mVec128.m128_f32[3])
                + (float)(v56.m_el[2].mVec128.m128_f32[2] * v43.m_el[2].mVec128.m128_f32[3]))
        + (float)(v56.m_el[2].mVec128.m128_f32[0] * v43.m_el[0].mVec128.m128_f32[3]);
    v52[0] = (float)((float)(v56.m_el[1].mVec128.m128_f32[1] * v43.m_el[2].mVec128.m128_f32[1])
                   + (float)(v56.m_el[1].mVec128.m128_f32[2] * v45))
           + (float)(v56.m_el[1].mVec128.m128_f32[0] * v43.m_el[1].mVec128.m128_f32[1]);
    v49 = (float)((float)(v56.m_el[1].mVec128.m128_f32[2] * v44)
                + (float)(v56.m_el[1].mVec128.m128_f32[1] * v43.m_el[2].mVec128.m128_f32[0]))
        + (float)(v56.m_el[1].mVec128.m128_f32[0] * v43.m_el[1].mVec128.m128_f32[0]);
    v50 = (float)((float)(v56.m_el[1].mVec128.m128_f32[1] * v43.m_el[1].mVec128.m128_f32[3])
                + (float)(v56.m_el[1].mVec128.m128_f32[2] * v43.m_el[2].mVec128.m128_f32[3]))
        + (float)(v56.m_el[1].mVec128.m128_f32[0] * v43.m_el[0].mVec128.m128_f32[3]);
    v48 = (float)((float)(v56.m_el[0].mVec128.m128_f32[1] * v43.m_el[2].mVec128.m128_f32[1])
                + (float)(v56.m_el[0].mVec128.m128_f32[2] * v45))
        + (float)(v56.m_el[0].mVec128.m128_f32[0] * v43.m_el[1].mVec128.m128_f32[1]);
    v51 = (float)((float)(v56.m_el[0].mVec128.m128_f32[2] * v44)
                + (float)(v56.m_el[0].mVec128.m128_f32[1] * v43.m_el[2].mVec128.m128_f32[0]))
        + (float)(v56.m_el[0].mVec128.m128_f32[0] * v43.m_el[1].mVec128.m128_f32[0]);
    v43.m_el[0].mVec128.m128_f32[0] = (float)((float)(v56.m_el[0].mVec128.m128_f32[1] * v43.m_el[1].mVec128.m128_f32[3])
                                            + (float)(v56.m_el[0].mVec128.m128_f32[2] * v43.m_el[2].mVec128.m128_f32[3]))
                                    + (float)(v56.m_el[0].mVec128.m128_f32[0] * v43.m_el[0].mVec128.m128_f32[3]);
    btMatrix3x3::setValue(
      &v43,
      (int)&v56,
      &v51,
      &v48,
      &v50,
      &v49,
      v52,
      &v47,
      &v43.m_el[0].mVec128.m128_f32[1],
      &v43.m_el[0].mVec128.m128_f32[2],
      v42);
    v27 = (const btMatrix3x3 *)(a2 + 592);
    *(_QWORD *)(a2 + 592) = v56.m_el[0].mVec128.m128_u64[0];
    *(_QWORD *)(a2 + 600) = v56.m_el[0].mVec128.m128_u64[1];
    *(_QWORD *)(a2 + 608) = v56.m_el[1].mVec128.m128_u64[0];
    v28 = s_bm_current_air_resistance;
    *(_QWORD *)(a2 + 616) = v56.m_el[1].mVec128.m128_u64[1];
    *(btVector3 *)(a2 + 624) = v56.m_el[2];
    v29 = *(float *)(a2 + 372);
    v43.m_el[0].mVec128.m128_i32[1] = a2 + 592;
    if ( v29 > v28 )
    {
      v30 = *(float *)(a2 + 608);
      v31 = *(float *)(a2 + 624);
      v32 = *(float *)(a2 + 632);
      v33 = *(float *)(a2 + 612);
      v34 = *(float *)(a2 + 616);
      v43.m_el[0].mVec128.m128_i32[2] = *(_DWORD *)(a2 + 628);
      v35 = (float)((float)((float)((float)(v30 * v43.m_el[0].mVec128.m128_f32[2]) - (float)(v31 * v33))
                          * *(float *)(a2 + 600))
                  + (float)((float)((float)(v31 * v34) - (float)(v30 * v32)) * *(float *)(a2 + 596)))
          + (float)((float)((float)(v33 * v32) - (float)(v34 * v43.m_el[0].mVec128.m128_f32[2]))
                  * v27->m_el[0].mVec128.m128_f32[0]);
      v36 = v28 / v35;
      if ( v28 <= (float)(v28 / v35) && (v28 = *(float *)(a2 + 372), v36 <= v28) )
        v43.m_el[0].mVec128.m128_f32[0] = v36;
      else
        v43.m_el[0].mVec128.m128_f32[0] = v28;
      v37 = Mul(v27, (float *)&v56, v43.m_el[0].mVec128.m128_f32[0]);
      v38 = (btVector3 *)v43.m_el[0].mVec128.m128_i32[1];
      v39 = (_DWORD *)v43.m_el[0].mVec128.m128_i32[1];
      *(_DWORD *)v43.m_el[0].mVec128.m128_i32[1] = v37->m_el[0].mVec128.m128_i32[0];
      *++v39 = v37->m_el[0].mVec128.m128_i32[1];
      *++v39 = v37->m_el[0].mVec128.m128_i32[2];
      v39[1] = v37->m_el[0].mVec128.m128_i32[3];
      v38[1] = v37->m_el[1];
      v38[2] = v37->m_el[2];
    }
  }
}
