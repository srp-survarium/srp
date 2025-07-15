int __usercall PolarDecompose@<eax>(const float *a1@<edi>, const btMatrix3x3 *m, btMatrix3x3 *q, btMatrix3x3 *s)
{
  btMatrix3x3 *v4; // eax
  float *v5; // ecx
  btMatrix3x3 *v6; // ecx
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm3_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm7_4
  float v18; // xmm4_4
  float v19; // xmm5_4
  btMatrix3x3 *v20; // eax
  btMatrix3x3 *v21; // eax
  float v22; // xmm1_4
  btMatrix3x3 *v23; // eax
  float v24; // xmm3_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  float v27; // xmm6_4
  float v28; // xmm0_4
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm0_4
  float v32; // xmm7_4
  float v33; // xmm5_4
  float v34; // xmm7_4
  float v35; // xmm6_4
  float v36; // xmm5_4
  float v37; // xmm7_4
  float v38; // xmm1_4
  float v39; // xmm6_4
  float v40; // xmm7_4
  float v41; // xmm4_4
  float v42; // xmm3_4
  const float *v43; // [esp+4h] [ebp-130h]
  float v44; // [esp+18h] [ebp-11Ch]
  float v45; // [esp+1Ch] [ebp-118h] BYREF
  int v46; // [esp+20h] [ebp-114h]
  float v47; // [esp+24h] [ebp-110h] BYREF
  float v48; // [esp+28h] [ebp-10Ch] BYREF
  float v49; // [esp+2Ch] [ebp-108h] BYREF
  float v50; // [esp+30h] [ebp-104h] BYREF
  float v51; // [esp+34h] [ebp-100h] BYREF
  float v52; // [esp+38h] [ebp-FCh] BYREF
  float v53; // [esp+3Ch] [ebp-F8h] BYREF
  float v54; // [esp+40h] [ebp-F4h] BYREF
  btMatrix3x3 v55; // [esp+44h] [ebp-F0h] BYREF
  btMatrix3x3 v56; // [esp+74h] [ebp-C0h] BYREF
  float v57[12]; // [esp+A4h] [ebp-90h] BYREF
  _BYTE v58[48]; // [esp+D4h] [ebp-60h] BYREF
  float var30[13]; // [esp+104h] [ebp-30h] BYREF

  v46 = 0;
  v43 = a1;
  v4 = Mul(
         m,
         (float *)&v56,
         s_bm_current_air_resistance
       / fsqrt(
           (float)((float)(m->m_el[2].mVec128.m128_f32[2] * m->m_el[2].mVec128.m128_f32[2])
                 + (float)(m->m_el[0].mVec128.m128_f32[0] * m->m_el[0].mVec128.m128_f32[0]))
         + (float)(m->m_el[1].mVec128.m128_f32[1] * m->m_el[1].mVec128.m128_f32[1])));
  v5 = (float *)q;
  *q = *v4;
  v44 = (float)((float)((float)((float)(q->m_el[1].mVec128.m128_f32[0] * q->m_el[2].mVec128.m128_f32[1])
                              - (float)(q->m_el[2].mVec128.m128_f32[0] * q->m_el[1].mVec128.m128_f32[1]))
                      * v5[2])
              + (float)((float)((float)(v5[8] * q->m_el[1].mVec128.m128_f32[2])
                              - (float)(q->m_el[1].mVec128.m128_f32[0] * q->m_el[2].mVec128.m128_f32[2]))
                      * v5[1]))
      + (float)((float)((float)(q->m_el[1].mVec128.m128_f32[1] * q->m_el[2].mVec128.m128_f32[2])
                      - (float)(q->m_el[1].mVec128.m128_f32[2] * q->m_el[2].mVec128.m128_f32[1]))
              * *v5);
  if ( COERCE_FLOAT(LODWORD(v44) & _mask__AbsFloat_) >= 0.00000011920929 )
  {
    while ( 1 )
    {
      v8 = *v5;
      v9 = v5[4];
      v10 = v5[5];
      v11 = v5[8];
      v12 = v5[1];
      v53 = (float)(*v5 * v10) - (float)(v12 * v9);
      v13 = (float)(v11 * v12) - (float)(v5[9] * v8);
      v14 = v5[2];
      v52 = (float)(v5[9] * v9) - (float)(v11 * v10);
      v49 = v13;
      v15 = v5[6];
      v50 = (float)(v14 * v9) - (float)(v15 * v8);
      v16 = v5[10];
      v17 = (float)(v16 * v8) - (float)(v14 * v11);
      v47 = (float)(v15 * v11) - (float)(v16 * v9);
      v18 = v5[1];
      v51 = (float)(v15 * v18) - (float)(v14 * v10);
      v19 = v5[9];
      v54 = v17;
      v48 = (float)(v14 * v19) - (float)(v16 * v18);
      v45 = (float)(v16 * v10) - (float)(v15 * v19);
      btMatrix3x3::setValue((btMatrix3x3 *)&v45, (int)&v55, &v48, &v51, &v47, &v54, &v50, &v52, &v49, &v53, v43);
      v20 = Mul(&v55, v57, s_bm_current_air_resistance / v44);
      btMatrix3x3::btMatrix3x3(
        v20,
        &v56,
        v20->m_el[1].mVec128.m128_f32,
        v20->m_el[2].mVec128.m128_f32,
        &v20->m_el[0].mVec128.m128_f32[1],
        &v20->m_el[1].mVec128.m128_f32[1],
        &v20->m_el[2].mVec128.m128_f32[1],
        &v20->m_el[0].mVec128.m128_f32[2],
        &v20->m_el[1].mVec128.m128_f32[2],
        &v20->m_el[2].mVec128.m128_f32[2]);
      v21 = Add(q, &v56, (int)v58);
      *q = *Mul(v21, var30, 0.5);
      v22 = (float)((float)((float)((float)(q->m_el[1].mVec128.m128_f32[1] * q->m_el[2].mVec128.m128_f32[2])
                                  - (float)(q->m_el[1].mVec128.m128_f32[2] * q->m_el[2].mVec128.m128_f32[1]))
                          * q->m_el[0].mVec128.m128_f32[0])
                  + (float)((float)((float)(q->m_el[2].mVec128.m128_f32[0] * q->m_el[1].mVec128.m128_f32[2])
                                  - (float)(q->m_el[2].mVec128.m128_f32[2] * q->m_el[1].mVec128.m128_f32[0]))
                          * q->m_el[0].mVec128.m128_f32[1]))
          + (float)((float)((float)(q->m_el[1].mVec128.m128_f32[0] * q->m_el[2].mVec128.m128_f32[1])
                          - (float)(q->m_el[1].mVec128.m128_f32[1] * q->m_el[2].mVec128.m128_f32[0]))
                  * q->m_el[0].mVec128.m128_f32[2]);
      if ( (float)((float)(v22 - v44) * (float)(v22 - v44)) <= 0.000099999997 )
        break;
      ++v46;
      v44 = v22;
      if ( v46 >= 16 )
        break;
      v5 = (float *)q;
    }
    Orthogonalize(q);
    btMatrix3x3::btMatrix3x3(
      v23,
      &v55,
      v23->m_el[1].mVec128.m128_f32,
      v23->m_el[2].mVec128.m128_f32,
      &v23->m_el[0].mVec128.m128_f32[1],
      &v23->m_el[1].mVec128.m128_f32[1],
      &v23->m_el[2].mVec128.m128_f32[1],
      &v23->m_el[0].mVec128.m128_f32[2],
      &v23->m_el[1].mVec128.m128_f32[2],
      &v23->m_el[2].mVec128.m128_f32[2]);
    v24 = m->m_el[2].mVec128.m128_f32[2];
    v25 = m->m_el[1].mVec128.m128_f32[2];
    v26 = m->m_el[0].mVec128.m128_f32[2];
    v27 = m->m_el[2].mVec128.m128_f32[1];
    v48 = (float)((float)(v55.m_el[2].mVec128.m128_f32[1] * v25) + (float)(v55.m_el[2].mVec128.m128_f32[2] * v24))
        + (float)(v55.m_el[2].mVec128.m128_f32[0] * v26);
    v28 = v55.m_el[2].mVec128.m128_f32[2] * v27;
    v29 = m->m_el[0].mVec128.m128_f32[1];
    v30 = (float)((float)(v55.m_el[2].mVec128.m128_f32[1] * m->m_el[1].mVec128.m128_f32[1]) + v28)
        + (float)(v55.m_el[2].mVec128.m128_f32[0] * v29);
    v31 = m->m_el[0].mVec128.m128_f32[0];
    v51 = v30;
    v47 = (float)((float)(v55.m_el[2].mVec128.m128_f32[1] * m->m_el[1].mVec128.m128_f32[0])
                + (float)(v55.m_el[2].mVec128.m128_f32[2] * m->m_el[2].mVec128.m128_f32[0]))
        + (float)(v31 * v55.m_el[2].mVec128.m128_f32[0]);
    v32 = (float)((float)(v55.m_el[1].mVec128.m128_f32[0] * v26) + (float)(v55.m_el[1].mVec128.m128_f32[1] * v25))
        + (float)(v55.m_el[1].mVec128.m128_f32[2] * v24);
    v33 = m->m_el[1].mVec128.m128_f32[1];
    v54 = v32;
    v34 = v55.m_el[1].mVec128.m128_f32[0] * v29;
    v35 = v55.m_el[1].mVec128.m128_f32[1] * v33;
    v36 = m->m_el[2].mVec128.m128_f32[1];
    v50 = (float)(v34 + v35) + (float)(v55.m_el[1].mVec128.m128_f32[2] * v36);
    v37 = (float)(v31 * v55.m_el[1].mVec128.m128_f32[0])
        + (float)(v55.m_el[1].mVec128.m128_f32[1] * m->m_el[1].mVec128.m128_f32[0]);
    v38 = m->m_el[0].mVec128.m128_f32[2];
    v45 = m->m_el[1].mVec128.m128_f32[0];
    v39 = m->m_el[2].mVec128.m128_f32[0];
    v52 = v37 + (float)(v55.m_el[1].mVec128.m128_f32[2] * v39);
    v40 = (float)((float)(v55.m_el[0].mVec128.m128_f32[0] * v38) + (float)(v55.m_el[0].mVec128.m128_f32[1] * v25))
        + (float)(v55.m_el[0].mVec128.m128_f32[2] * v24);
    v41 = v55.m_el[0].mVec128.m128_f32[0] * m->m_el[0].mVec128.m128_f32[1];
    v42 = m->m_el[1].mVec128.m128_f32[1];
    v49 = v40;
    v53 = (float)(v41 + (float)(v55.m_el[0].mVec128.m128_f32[1] * v42)) + (float)(v55.m_el[0].mVec128.m128_f32[2] * v36);
    v45 = (float)((float)(v31 * v55.m_el[0].mVec128.m128_f32[0]) + (float)(v55.m_el[0].mVec128.m128_f32[1] * v45))
        + (float)(v55.m_el[0].mVec128.m128_f32[2] * v39);
    btMatrix3x3::setValue((btMatrix3x3 *)&v45, (int)&v55, &v53, &v49, &v52, &v50, &v54, &v47, &v51, &v48, v43);
    *s = v55;
  }
  else
  {
    btMatrix3x3::setIdentity(q, (int)q);
    btMatrix3x3::setIdentity(v6, (int)s);
  }
  return v46;
}
