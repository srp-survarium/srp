int __usercall PolarDecompose@<eax>(btMatrix3x3 *m@<edi>, btMatrix3x3 *q@<eax>, btMatrix3x3 *s)
{
  float v4; // xmm4_4
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm5_4
  float v8; // xmm2_4
  float v9; // xmm7_4
  float v10; // xmm1_4
  unsigned int v11; // xmm2_4
  unsigned int v12; // xmm3_4
  float v13; // xmm6_4
  float v14; // xmm7_4
  int *v15; // eax
  btMatrix3x3 *v16; // eax
  unsigned __int64 *v17; // eax
  float v18; // xmm0_4
  bool v19; // cc
  float v20; // xmm5_4
  float v21; // xmm4_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm6_4
  float v27; // xmm7_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  float v30; // xmm7_4
  float v31; // xmm5_4
  float v32; // xmm7_4
  float v33; // xmm2_4
  int result; // eax
  float v35; // xmm4_4
  float v36; // xmm1_4
  float v37; // xmm1_4
  float v38; // xmm1_4
  const vostok::math::float4x4 *v39; // xmm1_4
  float _X; // [esp+25Ch] [ebp-130h]
  float v41; // [esp+25Ch] [ebp-130h]
  float v42; // [esp+260h] [ebp-12Ch]
  float v43; // [esp+260h] [ebp-12Ch]
  unsigned int v44; // [esp+264h] [ebp-128h]
  float v45; // [esp+264h] [ebp-128h]
  unsigned int v46; // [esp+264h] [ebp-128h]
  int v47; // [esp+268h] [ebp-124h]
  unsigned int v48; // [esp+26Ch] [ebp-120h]
  float v49; // [esp+26Ch] [ebp-120h]
  unsigned int v50; // [esp+270h] [ebp-11Ch]
  float v51; // [esp+270h] [ebp-11Ch]
  unsigned int v52; // [esp+274h] [ebp-118h]
  float v53; // [esp+274h] [ebp-118h]
  unsigned int v54; // [esp+278h] [ebp-114h]
  float v55; // [esp+278h] [ebp-114h]
  unsigned __int64 v56; // [esp+27Ch] [ebp-110h] BYREF
  unsigned __int64 v57; // [esp+284h] [ebp-108h]
  unsigned __int64 v58; // [esp+28Ch] [ebp-100h]
  unsigned __int64 v59; // [esp+294h] [ebp-F8h]
  unsigned __int64 v60; // [esp+29Ch] [ebp-F0h]
  unsigned __int64 v61; // [esp+2A4h] [ebp-E8h]
  float v62; // [esp+2B4h] [ebp-D8h]
  float v63; // [esp+2B8h] [ebp-D4h]
  float v64; // [esp+2BCh] [ebp-D0h]
  float v65; // [esp+2C0h] [ebp-CCh]
  float v66; // [esp+2C4h] [ebp-C8h]
  float v67; // [esp+2C8h] [ebp-C4h]
  btMatrix3x3 b; // [esp+2CCh] [ebp-C0h] BYREF
  _BYTE v69[48]; // [esp+2FCh] [ebp-90h] BYREF
  _QWORD v70[6]; // [esp+32Ch] [ebp-60h] BYREF
  _QWORD v71[6]; // [esp+35Ch] [ebp-30h] BYREF

  v47 = 0;
  v42 = 1.0
      / sqrtf(
          (float)((float)(m->m_el[2].mVec128.m128_f32[2] * m->m_el[2].mVec128.m128_f32[2])
                + (float)(m->m_el[0].mVec128.m128_f32[0] * m->m_el[0].mVec128.m128_f32[0]))
        + (float)(m->m_el[1].mVec128.m128_f32[1] * m->m_el[1].mVec128.m128_f32[1]));
  *q = *(btMatrix3x3 *)Mul(&b, (float *)m, v42);
  _X = (float)((float)((float)((float)(q->m_el[1].mVec128.m128_f32[0] * q->m_el[2].mVec128.m128_f32[1])
                             - (float)(q->m_el[2].mVec128.m128_f32[0] * q->m_el[1].mVec128.m128_f32[1]))
                     * q->m_el[0].mVec128.m128_f32[2])
             + (float)((float)((float)(q->m_el[2].mVec128.m128_f32[0] * q->m_el[1].mVec128.m128_f32[2])
                             - (float)(q->m_el[1].mVec128.m128_f32[0] * q->m_el[2].mVec128.m128_f32[2]))
                     * q->m_el[0].mVec128.m128_f32[1]))
     + (float)((float)((float)(q->m_el[1].mVec128.m128_f32[1] * q->m_el[2].mVec128.m128_f32[2])
                     - (float)(q->m_el[1].mVec128.m128_f32[2] * q->m_el[2].mVec128.m128_f32[1]))
             * q->m_el[0].mVec128.m128_f32[0]);
  if ( fabsf(_X) < 0.00000011920929 )
  {
    v39 = clear_value;
    result = 0;
    q->m_el[0].mVec128.m128_i32[0] = (int)clear_value;
    q->m_el[0].mVec128.m128_i32[1] = 0;
    q->m_el[0].mVec128.m128_i32[2] = 0;
    q->m_el[0].mVec128.m128_i32[3] = 0;
    q->m_el[1].mVec128.m128_i32[0] = 0;
    q->m_el[1].mVec128.m128_i32[1] = (int)v39;
    q->m_el[1].mVec128.m128_i32[2] = 0;
    q->m_el[1].mVec128.m128_i32[3] = 0;
    q->m_el[2].mVec128.m128_i32[0] = 0;
    q->m_el[2].mVec128.m128_i32[1] = 0;
    q->m_el[2].mVec128.m128_i32[2] = (int)v39;
    q->m_el[2].mVec128.m128_i32[3] = 0;
    s->m_el[0].mVec128.m128_u64[0] = (unsigned int)v39;
    s->m_el[0].mVec128.m128_u64[1] = 0;
    s->m_el[1].mVec128.m128_i32[0] = 0;
    *(unsigned __int64 *)((char *)s->m_el[1].mVec128.m128_u64 + 4) = (unsigned int)v39;
    s->m_el[1].mVec128.m128_i32[3] = 0;
    s->m_el[2].mVec128.m128_u64[0] = 0;
    s->m_el[2].mVec128.m128_u64[1] = (unsigned int)v39;
  }
  else
  {
    do
    {
      v4 = q->m_el[0].mVec128.m128_f32[1];
      v5 = q->m_el[1].mVec128.m128_f32[1];
      v6 = q->m_el[1].mVec128.m128_f32[0];
      v7 = q->m_el[2].mVec128.m128_f32[1];
      *(float *)&v44 = (float)(q->m_el[0].mVec128.m128_f32[0] * v5) - (float)(v4 * v6);
      v8 = q->m_el[2].mVec128.m128_f32[0];
      *(float *)&v50 = (float)(v8 * v4) - (float)(v7 * q->m_el[0].mVec128.m128_f32[0]);
      *(float *)&v54 = (float)(v7 * v6) - (float)(v8 * v5);
      v9 = q->m_el[0].mVec128.m128_f32[2];
      *(float *)&v48 = (float)(v6 * v9) - (float)(q->m_el[0].mVec128.m128_f32[0] * q->m_el[1].mVec128.m128_f32[2]);
      *(float *)&v52 = (float)(q->m_el[0].mVec128.m128_f32[0] * q->m_el[2].mVec128.m128_f32[2]) - (float)(v8 * v9);
      v10 = q->m_el[1].mVec128.m128_f32[2];
      *(float *)&v11 = (float)(v8 * v10) - (float)(v6 * q->m_el[2].mVec128.m128_f32[2]);
      *(float *)&v12 = (float)(v4 * v10) - (float)(v5 * v9);
      v13 = v7 * v9;
      v14 = q->m_el[2].mVec128.m128_f32[2];
      *(float *)&v56 = (float)(v5 * v14) - (float)(v7 * v10);
      v59 = v48;
      v60 = __PAIR64__(v50, v54);
      v61 = v44;
      v57 = v12;
      *((float *)&v56 + 1) = v13 - (float)(v4 * v14);
      v58 = __PAIR64__(v52, v11);
      v15 = (int *)Mul(v70, (float *)&v56, *(float *)&clear_value / _X);
      b.m_el[0].mVec128.m128_i32[0] = *v15;
      b.m_el[0].mVec128.m128_i32[1] = v15[4];
      b.m_el[0].mVec128.m128_u64[1] = (unsigned int)v15[8];
      b.m_el[1].mVec128.m128_i32[0] = v15[1];
      b.m_el[1].mVec128.m128_i32[1] = v15[5];
      b.m_el[1].mVec128.m128_u64[1] = (unsigned int)v15[9];
      b.m_el[2].mVec128.m128_i32[0] = v15[2];
      b.m_el[2].mVec128.m128_i32[1] = v15[6];
      b.m_el[2].mVec128.m128_u64[1] = (unsigned int)v15[10];
      v16 = Add(&b, q, (int)v69);
      v17 = Mul(v71, (float *)v16, 0.5);
      q->m_el[0].mVec128.m128_u64[0] = *v17;
      q->m_el[0].mVec128.m128_u64[1] = v17[1];
      q->m_el[1].mVec128.m128_u64[0] = v17[2];
      q->m_el[1].mVec128.m128_u64[1] = v17[3];
      q->m_el[2].mVec128.m128_u64[0] = v17[4];
      q->m_el[2].mVec128.m128_u64[1] = v17[5];
      v18 = (float)((float)((float)((float)(q->m_el[1].mVec128.m128_f32[0] * q->m_el[2].mVec128.m128_f32[1])
                                  - (float)(q->m_el[2].mVec128.m128_f32[0] * q->m_el[1].mVec128.m128_f32[1]))
                          * q->m_el[0].mVec128.m128_f32[2])
                  + (float)((float)((float)(q->m_el[2].mVec128.m128_f32[0] * q->m_el[1].mVec128.m128_f32[2])
                                  - (float)(q->m_el[1].mVec128.m128_f32[0] * q->m_el[2].mVec128.m128_f32[2]))
                          * q->m_el[0].mVec128.m128_f32[1]))
          + (float)((float)((float)(q->m_el[1].mVec128.m128_f32[1] * q->m_el[2].mVec128.m128_f32[2])
                          - (float)(q->m_el[1].mVec128.m128_f32[2] * q->m_el[2].mVec128.m128_f32[1]))
                  * q->m_el[0].mVec128.m128_f32[0]);
      if ( (float)((float)(v18 - _X) * (float)(v18 - _X)) <= 0.000099999997 )
        break;
      v19 = v47 + 1 < 16;
      _X = (float)((float)((float)((float)(q->m_el[1].mVec128.m128_f32[0] * q->m_el[2].mVec128.m128_f32[1])
                                 - (float)(q->m_el[2].mVec128.m128_f32[0] * q->m_el[1].mVec128.m128_f32[1]))
                         * q->m_el[0].mVec128.m128_f32[2])
                 + (float)((float)((float)(q->m_el[2].mVec128.m128_f32[0] * q->m_el[1].mVec128.m128_f32[2])
                                 - (float)(q->m_el[1].mVec128.m128_f32[0] * q->m_el[2].mVec128.m128_f32[2]))
                         * q->m_el[0].mVec128.m128_f32[1]))
         + (float)((float)((float)(q->m_el[1].mVec128.m128_f32[1] * q->m_el[2].mVec128.m128_f32[2])
                         - (float)(q->m_el[1].mVec128.m128_f32[2] * q->m_el[2].mVec128.m128_f32[1]))
                 * q->m_el[0].mVec128.m128_f32[0]);
      ++v47;
    }
    while ( v19 );
    Orthogonalize(q);
    v20 = q->m_el[2].mVec128.m128_f32[2];
    v21 = q->m_el[1].mVec128.m128_f32[2];
    v22 = q->m_el[1].mVec128.m128_f32[1];
    v65 = (float)((float)(v20 * m->m_el[2].mVec128.m128_f32[2])
                + (float)(q->m_el[0].mVec128.m128_f32[2] * m->m_el[0].mVec128.m128_f32[2]))
        + (float)(v21 * m->m_el[1].mVec128.m128_f32[2]);
    v23 = q->m_el[2].mVec128.m128_f32[1];
    v24 = q->m_el[1].mVec128.m128_f32[0];
    v25 = q->m_el[2].mVec128.m128_f32[0];
    v45 = m->m_el[0].mVec128.m128_f32[0];
    v66 = (float)((float)(v20 * m->m_el[2].mVec128.m128_f32[1])
                + (float)(q->m_el[0].mVec128.m128_f32[2] * m->m_el[0].mVec128.m128_f32[1]))
        + (float)(v21 * m->m_el[1].mVec128.m128_f32[1]);
    v26 = m->m_el[2].mVec128.m128_f32[0];
    v27 = (float)((float)(v45 * q->m_el[0].mVec128.m128_f32[2]) + (float)(v20 * v26))
        + (float)(v21 * m->m_el[1].mVec128.m128_f32[0]);
    v28 = q->m_el[0].mVec128.m128_f32[1];
    v43 = m->m_el[1].mVec128.m128_f32[0];
    v29 = m->m_el[0].mVec128.m128_f32[2];
    v67 = v27;
    v55 = v29;
    v51 = m->m_el[1].mVec128.m128_f32[2];
    v49 = m->m_el[2].mVec128.m128_f32[2];
    v64 = (float)((float)(v28 * v29) + (float)(v22 * v51)) + (float)(v23 * v49);
    v30 = v28 * m->m_el[0].mVec128.m128_f32[1];
    v63 = m->m_el[0].mVec128.m128_f32[1];
    v53 = m->m_el[1].mVec128.m128_f32[1];
    v62 = m->m_el[2].mVec128.m128_f32[1];
    v41 = (float)(v30 + (float)(v22 * v53)) + (float)(v23 * v62);
    v31 = v45;
    v32 = (float)(v45 * v28) + (float)(v22 * v43);
    v33 = q->m_el[0].mVec128.m128_f32[0];
    result = v47;
    *(float *)&v46 = (float)((float)(v24 * v51) + (float)(q->m_el[0].mVec128.m128_f32[0] * v55)) + (float)(v25 * v49);
    v35 = v25 * v62;
    *(float *)&v56 = (float)((float)(v24 * v43) + (float)(v25 * v26)) + (float)(v31 * q->m_el[0].mVec128.m128_f32[0]);
    v57 = v46;
    HIDWORD(v59) = 0;
    HIDWORD(v61) = 0;
    *((float *)&v58 + 1) = v41;
    v36 = v64;
    *((float *)&v56 + 1) = (float)((float)(v24 * v53) + (float)(v33 * v63)) + v35;
    s->m_el[0].mVec128.m128_u64[0] = v56;
    *(float *)&v59 = v36;
    v37 = v67;
    s->m_el[0].mVec128.m128_u64[1] = v57;
    *(float *)&v58 = v32 + (float)(v23 * v26);
    s->m_el[1].mVec128.m128_u64[0] = v58;
    v60 = __PAIR64__(LODWORD(v66), LODWORD(v37));
    v38 = v65;
    s->m_el[1].mVec128.m128_u64[1] = v59;
    s->m_el[2].mVec128.m128_u64[0] = v60;
    *(float *)&v61 = v38;
    s->m_el[2].mVec128.m128_u64[1] = v61;
  }
  return result;
}
