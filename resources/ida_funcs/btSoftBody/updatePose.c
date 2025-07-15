void __thiscall btSoftBody::updatePose(btSoftBody *this, btVector3 *thisa)
{
  float v2; // xmm6_4
  __int128 v3; // xmm2
  int v4; // edi
  signed int v5; // ecx
  int v6; // eax
  float *v7; // ecx
  float *v8; // esi
  float *v9; // eax
  float *v10; // edx
  unsigned int v11; // edi
  float v12; // xmm3_4
  float v13; // xmm7_4
  float v14; // xmm5_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm2_4
  float v18; // xmm6_4
  float v19; // xmm5_4
  float v20; // xmm1_4
  float v21; // xmm4_4
  float v22; // xmm5_4
  float v23; // xmm0_4
  float v24; // xmm7_4
  float v25; // xmm3_4
  float v26; // xmm6_4
  float v27; // xmm2_4
  float v28; // xmm0_4
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm0_4
  float v32; // xmm7_4
  float v33; // xmm0_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  float v36; // xmm7_4
  float v37; // xmm0_4
  float v38; // xmm5_4
  float v39; // xmm7_4
  float v40; // xmm1_4
  unsigned int v41; // xmm6_4
  float v42; // xmm7_4
  float v43; // xmm4_4
  float v44; // xmm6_4
  float v45; // xmm0_4
  float v46; // xmm7_4
  float v47; // xmm3_4
  float v48; // xmm6_4
  float v49; // xmm3_4
  float v50; // xmm0_4
  float v51; // xmm3_4
  float v52; // xmm7_4
  float v53; // xmm4_4
  float v54; // xmm6_4
  float v55; // xmm5_4
  float v56; // xmm1_4
  float v57; // xmm2_4
  float v58; // xmm6_4
  float v59; // xmm1_4
  float v60; // xmm3_4
  float v61; // xmm0_4
  float v62; // xmm1_4
  float v63; // xmm7_4
  float v64; // xmm2_4
  float v65; // xmm0_4
  int v66; // xmm1_4
  float v67; // xmm0_4
  float v68; // xmm7_4
  float v69; // xmm0_4
  float v70; // xmm2_4
  float v71; // xmm0_4
  float v72; // xmm1_4
  float v73; // xmm0_4
  float v74; // xmm7_4
  float v75; // xmm5_4
  float v76; // xmm4_4
  float v77; // xmm7_4
  float v78; // xmm5_4
  float v79; // xmm3_4
  float v80; // xmm4_4
  float *v81; // edx
  float *v82; // eax
  unsigned int v83; // edi
  float *v84; // ecx
  float v85; // xmm0_4
  float v86; // xmm4_4
  float v87; // xmm5_4
  float v88; // xmm7_4
  float v89; // xmm1_4
  float v90; // xmm0_4
  unsigned int v91; // xmm4_4
  unsigned int v92; // xmm1_4
  __int128 v93; // xmm0
  float v94; // xmm4_4
  float v95; // xmm5_4
  float v96; // xmm6_4
  float v97; // xmm0_4
  float v98; // xmm1_4
  float v99; // xmm2_4
  float v100; // xmm3_4
  float v101; // xmm7_4
  float v102; // xmm4_4
  float v103; // xmm5_4
  unsigned int v104; // xmm2_4
  float v105; // xmm7_4
  float *m128_f32; // ecx
  unsigned int v107; // xmm1_4
  const vostok::math::float4x4 *v108; // xmm2_4
  int v109; // xmm1_4
  int v110; // xmm1_4
  float v111; // xmm5_4
  float v112; // xmm0_4
  float v113; // xmm1_4
  float v114; // xmm4_4
  float v115; // xmm3_4
  float v116; // xmm7_4
  float v117; // xmm0_4
  _QWORD *v118; // eax
  _QWORD *v119; // ecx
  unsigned int v120; // [esp+5B4h] [ebp-130h]
  float v121; // [esp+5B4h] [ebp-130h]
  float v122; // [esp+5B8h] [ebp-12Ch]
  float v123; // [esp+5BCh] [ebp-128h]
  float v124; // [esp+5BCh] [ebp-128h]
  int v125; // [esp+5C0h] [ebp-124h]
  float v126; // [esp+5C0h] [ebp-124h]
  float v127; // [esp+5C0h] [ebp-124h]
  btMatrix3x3 m; // [esp+5C4h] [ebp-120h] BYREF
  float v129; // [esp+600h] [ebp-E4h]
  float v130; // [esp+604h] [ebp-E0h]
  float v131; // [esp+608h] [ebp-DCh]
  float v132; // [esp+60Ch] [ebp-D8h]
  btVector3 result; // [esp+614h] [ebp-D0h] BYREF
  btMatrix3x3 q; // [esp+624h] [ebp-C0h] BYREF
  float v135; // [esp+660h] [ebp-84h]
  __m128i v136; // [esp+664h] [ebp-80h] BYREF
  float v137; // [esp+674h] [ebp-70h]
  float v138; // [esp+67Ch] [ebp-68h]
  float v139; // [esp+690h] [ebp-54h]
  float v140; // [esp+694h] [ebp-50h]
  float v141; // [esp+698h] [ebp-4Ch]
  float v142; // [esp+69Ch] [ebp-48h]
  float v143; // [esp+6A4h] [ebp-40h]
  btMatrix3x3 v144; // [esp+6B4h] [ebp-30h] BYREF

  if ( thisa[30].mVec128.m128_i8[1] )
  {
    btSoftBody::evaluateCom(this, (int)thisa, &result);
    v2 = 0.00000023841858;
    v3 = 0x34C00000u;
    thisa[33] = (btVector3)result.mVec128;
    v4 = thisa[45].mVec128.m128_i32[0];
    memset(&v136, 0, sizeof(v136));
    m.m_el[2] = (btVector3)_mm_load_si128(&v136);
    m.m_el[1] = m.m_el[2];
    m.m_el[0] = m.m_el[2];
    v5 = 0;
    m.m_el[0].mVec128.m128_i32[0] = 872415232;
    m.m_el[1].mVec128.m128_i32[1] = 880803840;
    m.m_el[2].mVec128.m128_i32[2] = 884998144;
    v120 = 0;
    v125 = v4;
    if ( v4 < 4 )
    {
      v79 = m.m_el[1].mVec128.m128_f32[0];
    }
    else
    {
      v6 = thisa[31].mVec128.m128_i32[1];
      v7 = (float *)(v6 + 8);
      v8 = (float *)(thisa[32].mVec128.m128_i32[2] + 8);
      v9 = (float *)(v6 + 24);
      v10 = (float *)(thisa[45].mVec128.m128_i32[2] + 24);
      v120 = 4 * (((unsigned int)(v4 - 4) >> 2) + 1);
      v11 = ((unsigned int)(v4 - 4) >> 2) + 1;
      do
      {
        v12 = *(v10 - 1) - result.mVec128.m128_f32[1];
        v13 = *(v7 - 2);
        v14 = *(v7 - 1);
        v15 = *(v8 - 2) * (float)(*(v10 - 2) - result.mVec128.m128_f32[0]);
        v16 = *(v8 - 2);
        v138 = v16 * (float)(*v10 - result.mVec128.m128_f32[2]);
        v17 = v16 * v12;
        v18 = *v7 * v15;
        v19 = v14 * v15;
        v20 = m.m_el[0].mVec128.m128_f32[0] + (float)(v13 * v15);
        v21 = m.m_el[0].mVec128.m128_f32[1] + v19;
        v22 = m.m_el[0].mVec128.m128_f32[2] + v18;
        v23 = v17 * v13;
        v24 = v17 * *(v7 - 1);
        v25 = *v7 * v138;
        v26 = *v7 * v17;
        v27 = m.m_el[1].mVec128.m128_f32[0] + v23;
        v142 = v26;
        v28 = m.m_el[1].mVec128.m128_f32[2] + v26;
        v29 = m.m_el[1].mVec128.m128_f32[1] + v24;
        v30 = *(v7 - 2);
        m.m_el[1].mVec128.m128_f32[2] = v28;
        v31 = v138 * v30;
        v32 = *(v7 - 1);
        v143 = v31;
        m.m_el[2].mVec128.m128_f32[0] = m.m_el[2].mVec128.m128_f32[0] + v31;
        v33 = m.m_el[2].mVec128.m128_f32[2] + v25;
        *(float *)&v136.m128i_i32[1] = v10[27] - result.mVec128.m128_f32[1];
        v34 = v10[28] - result.mVec128.m128_f32[2];
        m.m_el[2].mVec128.m128_f32[2] = v33;
        v35 = v10[26] - result.mVec128.m128_f32[0];
        m.m_el[2].mVec128.m128_f32[1] = m.m_el[2].mVec128.m128_f32[1] + (float)(v138 * v32);
        v36 = *(v8 - 1) * v35;
        v37 = *(v8 - 1) * *(float *)&v136.m128i_i32[1];
        v137 = v36;
        v138 = v34 * *(v8 - 1);
        v130 = v7[2] * v36;
        v131 = *(v9 - 1) * v36;
        v38 = v22 + (float)(*v9 * v36);
        v39 = *(v9 - 1);
        v140 = v37 * v7[2];
        v40 = v20 + v130;
        *(float *)&v41 = v29 + (float)(v37 * v39);
        v42 = *(v9 - 1);
        *(unsigned __int64 *)((char *)m.m_el[1].mVec128.m128_u64 + 4) = __PAIR64__(
                                                                          m.m_el[1].mVec128.m128_f32[2]
                                                                        + (float)(v37 * *v9),
                                                                          v41);
        v43 = v21 + v131;
        v44 = v138 * v42;
        v45 = v138 * *v9;
        v46 = m.m_el[2].mVec128.m128_f32[0] + (float)(v138 * v7[2]);
        v47 = m.m_el[2].mVec128.m128_f32[1] + v44;
        v48 = *v8;
        m.m_el[2].mVec128.m128_f32[1] = v47;
        v49 = m.m_el[2].mVec128.m128_f32[2] + v45;
        v50 = (float)(v10[54] - result.mVec128.m128_f32[0]) * v48;
        m.m_el[2].mVec128.m128_f32[2] = v49;
        v51 = (float)(v10[55] - result.mVec128.m128_f32[1]) * v48;
        m.m_el[2].mVec128.m128_f32[0] = v46;
        v52 = (float)(v10[56] - result.mVec128.m128_f32[2]) * v48;
        v130 = v7[6] * v50;
        v131 = v9[3] * v50;
        v53 = v43 + v131;
        v54 = v9[4] * v50;
        m.m_el[0].mVec128.m128_f32[0] = v40 + v130;
        v55 = v38 + v54;
        v56 = v51 * v9[3];
        v57 = (float)(v27 + v140) + (float)(v51 * v7[6]);
        v142 = v51 * v9[4];
        v58 = m.m_el[1].mVec128.m128_f32[1] + v56;
        v59 = v7[6];
        m.m_el[1].mVec128.m128_f32[2] = m.m_el[1].mVec128.m128_f32[2] + v142;
        v60 = v57;
        v61 = v52 * v59;
        v62 = v52 * v9[3];
        v63 = v52 * v9[4];
        v64 = m.m_el[2].mVec128.m128_f32[0] + v61;
        v65 = m.m_el[2].mVec128.m128_f32[1] + v62;
        *(float *)&v66 = v10[84] - result.mVec128.m128_f32[2];
        m.m_el[2].mVec128.m128_f32[1] = v65;
        v67 = m.m_el[2].mVec128.m128_f32[2] + v63;
        v68 = v10[83] - result.mVec128.m128_f32[1];
        m.m_el[2].mVec128.m128_f32[0] = v64;
        m.m_el[2].mVec128.m128_f32[2] = v67;
        v69 = v10[82] - result.mVec128.m128_f32[0];
        v136.m128i_i32[2] = v66;
        v70 = v8[1] * v69;
        v71 = v8[1];
        v72 = v71 * *(float *)&v66;
        v73 = v71 * v68;
        v130 = v7[10] * v70;
        v131 = v9[7] * v70;
        v74 = v9[8] * v70;
        m.m_el[0].mVec128.m128_f32[0] = m.m_el[0].mVec128.m128_f32[0] + v130;
        m.m_el[0].mVec128.m128_f32[1] = v53 + v131;
        v75 = v55 + v74;
        v132 = v74;
        v76 = v73 * v9[7];
        v77 = v9[8];
        m.m_el[0].mVec128.m128_f32[2] = v75;
        v78 = v7[10];
        v79 = v60 + (float)(v73 * v78);
        v2 = v58 + v76;
        v80 = v9[7];
        m.m_el[1].mVec128.m128_f32[2] = m.m_el[1].mVec128.m128_f32[2] + (float)(v73 * v77);
        v3 = m.m_el[2].mVec128.m128_u32[2];
        v8 += 4;
        v7 += 16;
        v9 += 16;
        v10 += 112;
        --v11;
        *(float *)&v3 = m.m_el[2].mVec128.m128_f32[2] + (float)(v72 * v77);
        m.m_el[1].mVec128.m128_u64[0] = __PAIR64__(LODWORD(v2), LODWORD(v79));
        m.m_el[2].mVec128.m128_f32[0] = m.m_el[2].mVec128.m128_f32[0] + (float)(v72 * v78);
        m.m_el[2].mVec128.m128_f32[1] = m.m_el[2].mVec128.m128_f32[1] + (float)(v72 * v80);
        m.m_el[2].mVec128.m128_f32[2] = *(float *)&v3;
      }
      while ( v11 );
      v4 = v125;
      v5 = v120;
    }
    if ( v5 < v4 )
    {
      v81 = (float *)(thisa[32].mVec128.m128_i32[2] + 4 * v5);
      v82 = (float *)(thisa[31].mVec128.m128_i32[1] + 16 * v5);
      v83 = v4 - v120;
      v84 = (float *)(thisa[45].mVec128.m128_i32[2] + 112 * v5 + 24);
      do
      {
        v85 = *(v84 - 2) - result.mVec128.m128_f32[0];
        v86 = *(v84 - 1) - result.mVec128.m128_f32[1];
        *(float *)&v136.m128i_i32[2] = *v84 - result.mVec128.m128_f32[2];
        v87 = *v81 * v85;
        v88 = *v81 * v86;
        v138 = *v81 * *(float *)&v136.m128i_i32[2];
        v89 = *v82;
        v130 = *v82 * v87;
        v90 = v82[1];
        v131 = v90 * v87;
        v126 = v82[2];
        v132 = v126 * v87;
        m.m_el[0].mVec128.m128_f32[0] = m.m_el[0].mVec128.m128_f32[0] + v130;
        m.m_el[0].mVec128.m128_f32[1] = m.m_el[0].mVec128.m128_f32[1] + (float)(v90 * v87);
        m.m_el[0].mVec128.m128_f32[2] = m.m_el[0].mVec128.m128_f32[2] + (float)(v126 * v87);
        v141 = v90 * v88;
        v2 = v2 + (float)(v90 * v88);
        v79 = v79 + (float)(v89 * v88);
        m.m_el[1].mVec128.m128_f32[2] = m.m_el[1].mVec128.m128_f32[2] + (float)(v126 * v88);
        *(float *)&v91 = m.m_el[2].mVec128.m128_f32[0] + (float)(v89 * v138);
        *(float *)&v92 = m.m_el[2].mVec128.m128_f32[1] + (float)(v90 * v138);
        v93 = v3;
        v84 += 28;
        ++v81;
        v82 += 4;
        --v83;
        *(float *)&v93 = *(float *)&v3 + (float)(v126 * v138);
        m.m_el[2].mVec128.m128_u64[0] = __PAIR64__(v92, v91);
        v3 = v93;
      }
      while ( v83 );
      m.m_el[2].mVec128.m128_i32[2] = v93;
      m.m_el[1].mVec128.m128_u64[0] = __PAIR64__(LODWORD(v2), LODWORD(v79));
    }
    PolarDecompose(&m, &q, &v144);
    thisa[34].mVec128.m128_u64[0] = q.m_el[0].mVec128.m128_u64[0];
    thisa[34].mVec128.m128_u64[1] = q.m_el[0].mVec128.m128_u64[1];
    thisa[35].mVec128.m128_u64[0] = q.m_el[1].mVec128.m128_u64[0];
    v94 = q.m_el[2].mVec128.m128_f32[2];
    v95 = q.m_el[2].mVec128.m128_f32[1];
    v96 = q.m_el[2].mVec128.m128_f32[0];
    thisa[35].mVec128.m128_u64[1] = q.m_el[1].mVec128.m128_u64[1];
    thisa[36] = q.m_el[2];
    v97 = (float)((float)(thisa[42].mVec128.m128_f32[2] * v94) + (float)(thisa[42].mVec128.m128_f32[1] * v95))
        + (float)(v96 * thisa[42].mVec128.m128_f32[0]);
    v98 = (float)((float)(thisa[42].mVec128.m128_f32[2] * q.m_el[1].mVec128.m128_f32[2])
                + (float)(thisa[42].mVec128.m128_f32[1] * q.m_el[1].mVec128.m128_f32[1]))
        + (float)(thisa[42].mVec128.m128_f32[0] * q.m_el[1].mVec128.m128_f32[0]);
    v99 = (float)((float)(thisa[42].mVec128.m128_f32[2] * q.m_el[0].mVec128.m128_f32[2])
                + (float)(thisa[42].mVec128.m128_f32[1] * q.m_el[0].mVec128.m128_f32[1]))
        + (float)(thisa[42].mVec128.m128_f32[0] * q.m_el[0].mVec128.m128_f32[0]);
    v100 = (float)((float)(thisa[41].mVec128.m128_f32[2] * v94) + (float)(thisa[41].mVec128.m128_f32[1] * v95))
         + (float)(thisa[41].mVec128.m128_f32[0] * v96);
    v101 = thisa[40].mVec128.m128_f32[0];
    v102 = (float)((float)(thisa[41].mVec128.m128_f32[2] * q.m_el[1].mVec128.m128_f32[2])
                 + (float)(thisa[41].mVec128.m128_f32[1] * q.m_el[1].mVec128.m128_f32[1]))
         + (float)(q.m_el[1].mVec128.m128_f32[0] * thisa[41].mVec128.m128_f32[0]);
    v103 = (float)((float)(thisa[41].mVec128.m128_f32[2] * q.m_el[0].mVec128.m128_f32[2])
                 + (float)(thisa[41].mVec128.m128_f32[1] * q.m_el[0].mVec128.m128_f32[1]))
         + (float)(q.m_el[0].mVec128.m128_f32[0] * thisa[41].mVec128.m128_f32[0]);
    v129 = thisa[40].mVec128.m128_f32[1];
    v123 = thisa[40].mVec128.m128_f32[2];
    v127 = (float)((float)(v123 * q.m_el[2].mVec128.m128_f32[2]) + (float)(v129 * q.m_el[2].mVec128.m128_f32[1]))
         + (float)(v101 * q.m_el[2].mVec128.m128_f32[0]);
    v121 = (float)((float)(v123 * q.m_el[1].mVec128.m128_f32[2]) + (float)(v129 * q.m_el[1].mVec128.m128_f32[1]))
         + (float)(v101 * q.m_el[1].mVec128.m128_f32[0]);
    v124 = (float)((float)(v101 * q.m_el[0].mVec128.m128_f32[0]) + (float)(v123 * q.m_el[0].mVec128.m128_f32[2]))
         + (float)(v129 * q.m_el[0].mVec128.m128_f32[1]);
    v135 = (float)((float)(m.m_el[2].mVec128.m128_f32[2] * v97) + (float)(m.m_el[0].mVec128.m128_f32[2] * v99))
         + (float)(m.m_el[1].mVec128.m128_f32[2] * v98);
    v139 = (float)((float)(m.m_el[2].mVec128.m128_f32[1] * v97) + (float)(m.m_el[0].mVec128.m128_f32[1] * v99))
         + (float)(m.m_el[1].mVec128.m128_f32[1] * v98);
    v122 = (float)((float)(m.m_el[2].mVec128.m128_f32[0] * v97) + (float)(m.m_el[1].mVec128.m128_f32[0] * v98))
         + (float)(m.m_el[0].mVec128.m128_f32[0] * v99);
    v129 = (float)((float)(m.m_el[1].mVec128.m128_f32[2] * v102) + (float)(m.m_el[2].mVec128.m128_f32[2] * v100))
         + (float)(m.m_el[0].mVec128.m128_f32[2] * v103);
    *(float *)&v104 = (float)((float)(m.m_el[2].mVec128.m128_f32[1] * v100)
                            + (float)(m.m_el[1].mVec128.m128_f32[1] * v102))
                    + (float)(m.m_el[0].mVec128.m128_f32[1] * v103);
    v105 = (float)((float)(m.m_el[1].mVec128.m128_f32[0] * v102) + (float)(m.m_el[2].mVec128.m128_f32[0] * v100))
         + (float)(m.m_el[0].mVec128.m128_f32[0] * v103);
    q.m_el[0].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                                      (float)((float)(m.m_el[1].mVec128.m128_f32[2] * v121)
                                            + (float)(m.m_el[2].mVec128.m128_f32[2] * v127))
                                    + (float)(m.m_el[0].mVec128.m128_f32[2] * v124));
    q.m_el[1].mVec128.m128_i32[3] = 0;
    q.m_el[2].mVec128.m128_i32[3] = 0;
    m128_f32 = thisa[37].mVec128.m128_f32;
    q.m_el[0].mVec128.m128_f32[1] = (float)((float)(m.m_el[2].mVec128.m128_f32[1] * v127)
                                          + (float)(m.m_el[1].mVec128.m128_f32[1] * v121))
                                  + (float)(m.m_el[0].mVec128.m128_f32[1] * v124);
    *(float *)&v107 = v129;
    q.m_el[0].mVec128.m128_f32[0] = (float)((float)(m.m_el[1].mVec128.m128_f32[0] * v121)
                                          + (float)(m.m_el[2].mVec128.m128_f32[0] * v127))
                                  + (float)(m.m_el[0].mVec128.m128_f32[0] * v124);
    thisa[37].mVec128.m128_u64[0] = q.m_el[0].mVec128.m128_u64[0];
    thisa[37].mVec128.m128_u64[1] = q.m_el[0].mVec128.m128_u64[1];
    *(unsigned __int64 *)((char *)q.m_el[1].mVec128.m128_u64 + 4) = __PAIR64__(v107, v104);
    v108 = clear_value;
    q.m_el[1].mVec128.m128_f32[0] = v105;
    thisa[38].mVec128.m128_u64[0] = q.m_el[1].mVec128.m128_u64[0];
    q.m_el[2].mVec128.m128_f32[0] = v122;
    v109 = LODWORD(v139);
    thisa[38].mVec128.m128_u64[1] = q.m_el[1].mVec128.m128_u64[1];
    q.m_el[2].mVec128.m128_i32[1] = v109;
    v110 = LODWORD(v135);
    thisa[39].mVec128.m128_u64[0] = q.m_el[2].mVec128.m128_u64[0];
    q.m_el[2].mVec128.m128_i32[2] = v110;
    thisa[39].mVec128.m128_u64[1] = q.m_el[2].mVec128.m128_u64[1];
    if ( thisa[23].mVec128.m128_f32[1] > *(float *)&v108 )
    {
      v111 = thisa[38].mVec128.m128_f32[0];
      v112 = thisa[38].mVec128.m128_f32[1];
      v113 = thisa[39].mVec128.m128_f32[0];
      v114 = thisa[39].mVec128.m128_f32[2];
      v115 = thisa[38].mVec128.m128_f32[2];
      v135 = thisa[39].mVec128.m128_f32[1];
      v116 = (float)((float)((float)((float)(v111 * v135) - (float)(v112 * v113)) * thisa[37].mVec128.m128_f32[2])
                   + (float)((float)((float)(v113 * v115) - (float)(v114 * v111)) * thisa[37].mVec128.m128_f32[1]))
           + (float)((float)((float)(v112 * v114) - (float)(v115 * v135)) * *m128_f32);
      v117 = *(float *)&v108 / v116;
      if ( *(float *)&v108 <= (float)(*(float *)&v108 / v116) )
      {
        if ( v117 > thisa[23].mVec128.m128_f32[1] )
          v117 = thisa[23].mVec128.m128_f32[1];
      }
      else
      {
        v117 = *(float *)&v108;
      }
      v118 = Mul(&v144, m128_f32, v117);
      *v119 = *v118;
      v119[1] = v118[1];
      v119[2] = v118[2];
      v119[3] = v118[3];
      v119 += 4;
      *v119 = v118[4];
      v119[1] = v118[5];
    }
  }
}
