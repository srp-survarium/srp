void __thiscall btSoftBody::updateClusters(btSoftBody *this, int a2)
{
  int v2; // eax
  const btSoftBody::Cluster *v3; // ebx
  int m_size; // eax
  const float *m128_f32; // edi
  float *v6; // ecx
  btSoftBody::Node **m_data; // esi
  float v8; // xmm7_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm4_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  btTransform *p_m_framexform; // ebx
  btMatrix3x3 *v15; // esi
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm7_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm7_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm7_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm7_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  float v34; // xmm7_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm2_4
  float v40; // xmm1_4
  float v41; // xmm7_4
  float v42; // xmm7_4
  float v43; // xmm5_4
  float v44; // xmm4_4
  float v45; // xmm0_4
  int v46; // eax
  btVector3 *p_m_lv; // edx
  __m128 *p_mVec128; // edi
  float *v49; // ecx
  int v50; // esi
  int v51; // edi
  float *v52; // esi
  float v53; // xmm1_4
  float v54; // xmm2_4
  float v55; // xmm1_4
  float v56; // xmm2_4
  float v57; // xmm4_4
  float *v58; // esi
  float v59; // xmm3_4
  float v60; // xmm4_4
  float v61; // xmm5_4
  float v62; // xmm7_4
  float v63; // xmm3_4
  bool v64; // cc
  float v65; // xmm1_4
  float v66; // xmm6_4
  float v67; // xmm5_4
  float v68; // xmm1_4
  float v69; // xmm4_4
  float v70; // xmm7_4
  float v71; // xmm6_4
  float v72; // xmm5_4
  float v73; // xmm1_4
  float v74; // xmm4_4
  float v75; // xmm2_4
  float v76; // xmm3_4
  float v77; // xmm7_4
  float v78; // xmm1_4
  int v79; // ecx
  float v80; // xmm1_4
  float v81; // xmm3_4
  float *v82; // esi
  float v83; // xmm5_4
  float v84; // xmm4_4
  float v85; // xmm7_4
  float *v86; // edi
  float v87; // xmm2_4
  float v88; // xmm6_4
  float v89; // xmm3_4
  float v90; // xmm4_4
  float v91; // xmm2_4
  __m128 **v92; // ecx
  __m128 *v93; // ebx
  float **v94; // edi
  int v95; // esi
  float *v96; // ecx
  btDbvt *v97; // ecx
  float v98; // xmm4_4
  float v99; // xmm2_4
  float v100; // xmm3_4
  btDbvtNode *v101; // eax
  float v102; // [esp+0h] [ebp-1F4h]
  const float *v103; // [esp+4h] [ebp-1F0h]
  const float *v104; // [esp+4h] [ebp-1F0h]
  int v105; // [esp+18h] [ebp-1DCh]
  int v106; // [esp+18h] [ebp-1DCh]
  int i; // [esp+1Ch] [ebp-1D8h]
  int v108; // [esp+20h] [ebp-1D4h]
  btMatrix3x3 v109; // [esp+24h] [ebp-1D0h] BYREF
  btSoftBody::Cluster *v110; // [esp+5Ch] [ebp-198h]
  float *v111; // [esp+60h] [ebp-194h]
  unsigned __int64 v112; // [esp+64h] [ebp-190h]
  unsigned __int64 v113; // [esp+6Ch] [ebp-188h]
  btVector3 v114; // [esp+74h] [ebp-180h]
  float v115; // [esp+84h] [ebp-170h] BYREF
  float v116; // [esp+88h] [ebp-16Ch] BYREF
  float v117; // [esp+8Ch] [ebp-168h] BYREF
  float v118; // [esp+90h] [ebp-164h] BYREF
  float v119; // [esp+94h] [ebp-160h] BYREF
  float v120; // [esp+98h] [ebp-15Ch] BYREF
  btMatrix3x3 v121; // [esp+9Ch] [ebp-158h] BYREF
  float v122; // [esp+CCh] [ebp-128h] BYREF
  float v123; // [esp+D0h] [ebp-124h] BYREF
  btMatrix3x3 v124; // [esp+D4h] [ebp-120h] BYREF
  int v125; // [esp+104h] [ebp-F0h]
  int v126; // [esp+108h] [ebp-ECh]
  int v127; // [esp+10Ch] [ebp-E8h]
  int v128; // [esp+110h] [ebp-E4h]
  int v129; // [esp+114h] [ebp-E0h]
  int v130; // [esp+118h] [ebp-DCh]
  int v131; // [esp+11Ch] [ebp-D8h]
  int v132; // [esp+120h] [ebp-D4h]
  int v133; // [esp+124h] [ebp-D0h]
  int v134; // [esp+128h] [ebp-CCh]
  int v135; // [esp+12Ch] [ebp-C8h]
  int v136; // [esp+130h] [ebp-C4h]
  btVector3 v137; // [esp+134h] [ebp-C0h] BYREF
  int v138; // [esp+144h] [ebp-B0h]
  int v139; // [esp+148h] [ebp-ACh]
  int v140; // [esp+14Ch] [ebp-A8h]
  int v141; // [esp+150h] [ebp-A4h]
  float v142; // [esp+154h] [ebp-A0h]
  float v143; // [esp+158h] [ebp-9Ch]
  float v144; // [esp+15Ch] [ebp-98h]
  int v145; // [esp+160h] [ebp-94h]
  float v146; // [esp+164h] [ebp-90h]
  float v147; // [esp+168h] [ebp-8Ch]
  float v148; // [esp+16Ch] [ebp-88h]
  int v149; // [esp+170h] [ebp-84h]
  int v150; // [esp+174h] [ebp-80h]
  int v151; // [esp+178h] [ebp-7Ch]
  int v152; // [esp+17Ch] [ebp-78h]
  int v153; // [esp+180h] [ebp-74h]
  float v154; // [esp+184h] [ebp-70h]
  float v155; // [esp+188h] [ebp-6Ch]
  float v156; // [esp+18Ch] [ebp-68h]
  int v157; // [esp+190h] [ebp-64h]
  float v158; // [esp+194h] [ebp-60h]
  float v159; // [esp+1ACh] [ebp-48h]
  btMatrix3x3 v160; // [esp+1B4h] [ebp-40h] BYREF
  btVector3 v161; // [esp+1E4h] [ebp-10h] BYREF

  v2 = a2;
  for ( i = 0; i < *(_DWORD *)(a2 + 1072); v2 = a2 )
  {
    v3 = *(const btSoftBody::Cluster **)(*(_DWORD *)(v2 + 1080) + 4 * i);
    m_size = v3->m_nodes.m_size;
    v110 = (btSoftBody::Cluster *)v3;
    v108 = m_size;
    if ( m_size )
    {
      v125 = 0;
      v126 = 0;
      v127 = 0;
      v128 = 0;
      memset(&v109.m_el[1].m_floats[2], 0, 16);
      memset(&v109.m_el[0].m_floats[2], 0, 12);
      v109.m_el[0].mVec128.m128_u64[0] = LODWORD(FLOAT_0_000099999997);
      v109.m_el[1].mVec128.m128_f32[1] = FLOAT_0_00019999999;
      v109.m_el[2].mVec128.m128_u64[1] = LODWORD(FLOAT_0_00029999999);
      v3->m_com = (btVector3)btSoftBody::clusterCom(v3, &v161)->mVec128;
      m128_f32 = v3->m_vimpulses[0].mVec128.m128_f32;
      if ( v108 > 0 )
      {
        v6 = v3->m_framerefs.m_data->mVec128.m128_f32;
        m_data = v3->m_nodes.m_data;
        m128_f32 = (const float *)v3->m_nodes.m_size;
        do
        {
          v8 = v6[2];
          v9 = *v6;
          v10 = v6[1];
          v11 = (*m_data)->m_x.mVec128.m128_f32[0] - v3->m_com.mVec128.m128_f32[0];
          v12 = (*m_data)->m_x.mVec128.m128_f32[1] - v3->m_com.mVec128.m128_f32[1];
          v13 = (*m_data)->m_x.mVec128.m128_f32[2] - v3->m_com.mVec128.m128_f32[2];
          v159 = v11 * v8;
          v109.m_el[0].mVec128.m128_f32[0] = v109.m_el[0].mVec128.m128_f32[0] + (float)(v11 * v9);
          v109.m_el[0].mVec128.m128_f32[1] = v109.m_el[0].mVec128.m128_f32[1] + (float)(v11 * v10);
          v109.m_el[0].mVec128.m128_f32[2] = v109.m_el[0].mVec128.m128_f32[2] + (float)(v11 * v8);
          v109.m_el[1].mVec128.m128_f32[1] = v109.m_el[1].mVec128.m128_f32[1] + (float)(v12 * v10);
          v109.m_el[1].mVec128.m128_f32[2] = (float)(v12 * v8) + v109.m_el[1].mVec128.m128_f32[2];
          v109.m_el[2].mVec128.m128_f32[1] = (float)(v13 * v10) + v109.m_el[2].mVec128.m128_f32[1];
          ++m_data;
          v6 += 4;
          m128_f32 = (const float *)((char *)m128_f32 - 1);
          v109.m_el[1].mVec128.m128_f32[0] = v109.m_el[1].mVec128.m128_f32[0] + (float)(v12 * v9);
          v109.m_el[2].mVec128.m128_f32[0] = v109.m_el[2].mVec128.m128_f32[0] + (float)(v13 * v9);
          v109.m_el[2].mVec128.m128_f32[2] = v109.m_el[2].mVec128.m128_f32[2] + (float)(v13 * v8);
        }
        while ( m128_f32 );
      }
      PolarDecompose(m128_f32, &v109, &v124, &v160);
      v3->m_framexform.m_origin.mVec128.m128_i32[0] = v3->m_com.mVec128.m128_i32[0];
      v3->m_framexform.m_origin.mVec128.m128_i32[1] = v3->m_com.mVec128.m128_i32[1];
      v3->m_framexform.m_origin.mVec128.m128_i32[2] = v3->m_com.mVec128.m128_i32[2];
      v3->m_framexform.m_origin.mVec128.m128_i32[3] = v3->m_com.mVec128.m128_i32[3];
      p_m_framexform = &v3->m_framexform;
      p_m_framexform->m_basis = v124;
      btMatrix3x3::btMatrix3x3(
        &p_m_framexform->m_basis,
        &v124,
        p_m_framexform->m_basis.m_el[1].mVec128.m128_f32,
        p_m_framexform->m_basis.m_el[2].mVec128.m128_f32,
        &p_m_framexform->m_basis.m_el[0].mVec128.m128_f32[1],
        &p_m_framexform->m_basis.m_el[1].mVec128.m128_f32[1],
        &p_m_framexform->m_basis.m_el[2].mVec128.m128_f32[1],
        &p_m_framexform->m_basis.m_el[0].mVec128.m128_f32[2],
        &p_m_framexform->m_basis.m_el[1].mVec128.m128_f32[2],
        &p_m_framexform->m_basis.m_el[2].mVec128.m128_f32[2]);
      v15 = (btMatrix3x3 *)v110;
      v16 = v110->m_locii.m_el[2].mVec128.m128_f32[2];
      v17 = v110->m_locii.m_el[1].mVec128.m128_f32[2];
      v18 = v110->m_locii.m_el[0].mVec128.m128_f32[2];
      v19 = v110->m_locii.m_el[2].mVec128.m128_f32[1];
      v20 = p_m_framexform->m_basis.m_el[2].mVec128.m128_f32[1];
      v21 = v110->m_locii.m_el[0].mVec128.m128_f32[1];
      v22 = p_m_framexform->m_basis.m_el[2].mVec128.m128_f32[2] * v19;
      v120 = (float)((float)(v20 * v17) + (float)(p_m_framexform->m_basis.m_el[2].mVec128.m128_f32[2] * v16))
           + (float)(p_m_framexform->m_basis.m_el[2].mVec128.m128_f32[0] * v18);
      v23 = v110->m_locii.m_el[1].mVec128.m128_f32[1];
      v24 = (float)(v20 * v23) + v22;
      v25 = p_m_framexform->m_basis.m_el[2].mVec128.m128_f32[0] * v21;
      v26 = v110->m_locii.m_el[2].mVec128.m128_f32[0];
      v27 = v24 + v25;
      v28 = p_m_framexform->m_basis.m_el[2].mVec128.m128_f32[1];
      v121.m_el[1].mVec128.m128_f32[2] = v27;
      v29 = p_m_framexform->m_basis.m_el[2].mVec128.m128_f32[2] * v26;
      v30 = v110->m_locii.m_el[0].mVec128.m128_f32[0];
      v31 = (float)((float)(v28 * v110->m_locii.m_el[1].mVec128.m128_f32[0]) + v29)
          + (float)(p_m_framexform->m_basis.m_el[2].mVec128.m128_f32[0] * v30);
      v32 = p_m_framexform->m_basis.m_el[1].mVec128.m128_f32[1] * v17;
      v33 = v30 * p_m_framexform->m_basis.m_el[1].mVec128.m128_f32[0];
      v116 = v31;
      v34 = p_m_framexform->m_basis.m_el[1].mVec128.m128_f32[2];
      v118 = (float)(v32 + (float)(v34 * v16)) + (float)(v18 * p_m_framexform->m_basis.m_el[1].mVec128.m128_f32[0]);
      v35 = (float)((float)(p_m_framexform->m_basis.m_el[1].mVec128.m128_f32[1] * v23)
                  + (float)(p_m_framexform->m_basis.m_el[1].mVec128.m128_f32[2] * v19))
          + (float)(v110->m_locii.m_el[0].mVec128.m128_f32[1] * p_m_framexform->m_basis.m_el[1].mVec128.m128_f32[0]);
      v36 = v110->m_locii.m_el[1].mVec128.m128_f32[0];
      v121.m_el[2].mVec128.m128_f32[0] = v35;
      v37 = p_m_framexform->m_basis.m_el[1].mVec128.m128_f32[1] * v36;
      v38 = p_m_framexform->m_basis.m_el[0].mVec128.m128_f32[0];
      v39 = (float)(v37 + (float)(v34 * v110->m_locii.m_el[2].mVec128.m128_f32[0])) + v33;
      v40 = p_m_framexform->m_basis.m_el[0].mVec128.m128_f32[2];
      v41 = p_m_framexform->m_basis.m_el[0].mVec128.m128_f32[0];
      v117 = v39;
      v42 = (float)((float)(v41 * v18) + (float)(p_m_framexform->m_basis.m_el[0].mVec128.m128_f32[1] * v17))
          + (float)(v40 * v16);
      v43 = p_m_framexform->m_basis.m_el[0].mVec128.m128_f32[1];
      v44 = (float)((float)(v38 * v110->m_locii.m_el[0].mVec128.m128_f32[1])
                  + (float)(v43 * v110->m_locii.m_el[1].mVec128.m128_f32[1]))
          + (float)(v40 * v19);
      v45 = (float)((float)(v38 * v110->m_locii.m_el[0].mVec128.m128_f32[0])
                  + (float)(v43 * v110->m_locii.m_el[1].mVec128.m128_f32[0]))
          + (float)(v40 * v110->m_locii.m_el[2].mVec128.m128_f32[0]);
      v121.m_el[2].mVec128.m128_f32[1] = v42;
      v119 = v44;
      v121.m_el[2].mVec128.m128_f32[3] = v45;
      btMatrix3x3::setValue(
        (btMatrix3x3 *)&v121.m_el[2].m_floats[3],
        (int)&v109,
        &v119,
        &v121.m_el[2].mVec128.m128_f32[1],
        &v117,
        v121.m_el[2].mVec128.m128_f32,
        &v118,
        &v116,
        &v121.m_el[1].mVec128.m128_f32[2],
        &v120,
        v103);
      v123 = (float)((float)(v124.m_el[2].mVec128.m128_f32[2] * v109.m_el[2].mVec128.m128_f32[2])
                   + (float)(v124.m_el[1].mVec128.m128_f32[2] * v109.m_el[2].mVec128.m128_f32[1]))
           + (float)(v124.m_el[0].mVec128.m128_f32[2] * v109.m_el[2].mVec128.m128_f32[0]);
      v121.m_el[0].mVec128.m128_f32[1] = (float)((float)(v124.m_el[2].mVec128.m128_f32[1]
                                                       * v109.m_el[2].mVec128.m128_f32[2])
                                               + (float)(v124.m_el[1].mVec128.m128_f32[1]
                                                       * v109.m_el[2].mVec128.m128_f32[1]))
                                       + (float)(v124.m_el[0].mVec128.m128_f32[1] * v109.m_el[2].mVec128.m128_f32[0]);
      v121.m_el[1].mVec128.m128_f32[3] = (float)((float)(v124.m_el[2].mVec128.m128_f32[0]
                                                       * v109.m_el[2].mVec128.m128_f32[2])
                                               + (float)(v124.m_el[1].mVec128.m128_f32[0]
                                                       * v109.m_el[2].mVec128.m128_f32[1]))
                                       + (float)(v124.m_el[0].mVec128.m128_f32[0] * v109.m_el[2].mVec128.m128_f32[0]);
      v121.m_el[0].mVec128.m128_f32[3] = (float)((float)(v124.m_el[2].mVec128.m128_f32[2]
                                                       * v109.m_el[1].mVec128.m128_f32[2])
                                               + (float)(v124.m_el[1].mVec128.m128_f32[2]
                                                       * v109.m_el[1].mVec128.m128_f32[1]))
                                       + (float)(v124.m_el[0].mVec128.m128_f32[2] * v109.m_el[1].mVec128.m128_f32[0]);
      v122 = (float)((float)(v124.m_el[2].mVec128.m128_f32[1] * v109.m_el[1].mVec128.m128_f32[2])
                   + (float)(v124.m_el[1].mVec128.m128_f32[1] * v109.m_el[1].mVec128.m128_f32[1]))
           + (float)(v124.m_el[0].mVec128.m128_f32[1] * v109.m_el[1].mVec128.m128_f32[0]);
      v121.m_el[2].mVec128.m128_f32[2] = (float)((float)(v124.m_el[2].mVec128.m128_f32[2]
                                                       * v109.m_el[0].mVec128.m128_f32[2])
                                               + (float)(v124.m_el[1].mVec128.m128_f32[2]
                                                       * v109.m_el[0].mVec128.m128_f32[1]))
                                       + (float)(v124.m_el[0].mVec128.m128_f32[2] * v109.m_el[0].mVec128.m128_f32[0]);
      v121.m_el[1].mVec128.m128_f32[1] = (float)((float)(v124.m_el[2].mVec128.m128_f32[0]
                                                       * v109.m_el[1].mVec128.m128_f32[2])
                                               + (float)(v124.m_el[1].mVec128.m128_f32[0]
                                                       * v109.m_el[1].mVec128.m128_f32[1]))
                                       + (float)(v124.m_el[0].mVec128.m128_f32[0] * v109.m_el[1].mVec128.m128_f32[0]);
      v115 = (float)((float)(v124.m_el[2].mVec128.m128_f32[1] * v109.m_el[0].mVec128.m128_f32[2])
                   + (float)(v124.m_el[1].mVec128.m128_f32[1] * v109.m_el[0].mVec128.m128_f32[1]))
           + (float)(v124.m_el[0].mVec128.m128_f32[1] * v109.m_el[0].mVec128.m128_f32[0]);
      v121.m_el[0].mVec128.m128_f32[0] = (float)((float)(v124.m_el[2].mVec128.m128_f32[0]
                                                       * v109.m_el[0].mVec128.m128_f32[2])
                                               + (float)(v124.m_el[1].mVec128.m128_f32[0]
                                                       * v109.m_el[0].mVec128.m128_f32[1]))
                                       + (float)(v124.m_el[0].mVec128.m128_f32[0] * v109.m_el[0].mVec128.m128_f32[0]);
      btMatrix3x3::setValue(
        &v121,
        (int)&v160,
        &v115,
        &v121.m_el[2].mVec128.m128_f32[2],
        &v121.m_el[1].mVec128.m128_f32[1],
        &v122,
        &v121.m_el[0].mVec128.m128_f32[3],
        &v121.m_el[1].mVec128.m128_f32[3],
        &v121.m_el[0].mVec128.m128_f32[1],
        &v123,
        v104);
      v15[4] = v160;
      v111 = (float *)&v15[4];
      v46 = (int)v110;
      v138 = 0;
      v139 = 0;
      v140 = 0;
      v141 = 0;
      p_m_lv = &v110->m_lv;
      p_mVec128 = &v110->m_lv.mVec128;
      v110->m_lv.mVec128.m128_i32[0] = 0;
      p_mVec128 = (__m128 *)((char *)p_mVec128 + 4);
      p_mVec128->m128_i32[0] = v139;
      p_mVec128 = (__m128 *)((char *)p_mVec128 + 4);
      p_mVec128->m128_i32[0] = v140;
      p_mVec128->m128_i32[1] = v141;
      v150 = 0;
      v151 = 0;
      v152 = 0;
      v153 = 0;
      v49 = (float *)(v46 + 352);
      *(_DWORD *)(v46 + 352) = 0;
      *(_DWORD *)(v46 + 356) = v151;
      *(_DWORD *)(v46 + 360) = v152;
      *(_DWORD *)(v46 + 364) = v153;
      v50 = 0;
      v105 = 0;
      if ( v108 > 0 )
      {
        do
        {
          v51 = 4 * v50;
          v121.m_el[0].mVec128.m128_i32[2] = 4 * v50 + *(_DWORD *)(v46 + 12);
          v52 = *(float **)(4 * v50 + *(_DWORD *)(v46 + 32));
          v53 = v52[13];
          v54 = v52[14];
          v121.m_el[1].mVec128.m128_i32[0] = v51;
          v55 = v53 * *(float *)v121.m_el[0].mVec128.m128_i32[2];
          v56 = v54 * *(float *)v121.m_el[0].mVec128.m128_i32[2];
          v57 = p_m_lv->mVec128.m128_f32[0] + (float)(*(float *)v121.m_el[0].mVec128.m128_i32[2] * v52[12]);
          v158 = *(float *)v121.m_el[0].mVec128.m128_i32[2] * v52[12];
          p_m_lv->mVec128.m128_f32[0] = v57;
          p_m_lv->mVec128.m128_f32[1] = v55 + p_m_lv->mVec128.m128_f32[1];
          p_m_lv->mVec128.m128_f32[2] = v56 + p_m_lv->mVec128.m128_f32[2];
          v58 = *(float **)(v51 + *(_DWORD *)(v46 + 32));
          v59 = v58[6] - *(float *)(v46 + 248);
          v60 = v58[5] - *(float *)(v46 + 244);
          v61 = v58[4] - *(float *)(v46 + 240);
          v62 = v59 * v55;
          v63 = (float)((float)(v59 * v158) - (float)(v56 * v61)) + *(float *)(v46 + 356);
          v50 = v105 + 1;
          v64 = v105 + 1 < v108;
          v65 = (float)((float)(v55 * v61) - (float)(v60 * v158)) + *(float *)(v46 + 360);
          *v49 = *v49 + (float)((float)(v60 * v56) - v62);
          *(float *)(v46 + 356) = v63;
          *(float *)(v46 + 360) = v65;
          ++v105;
        }
        while ( v64 );
      }
      v66 = *(float *)(v46 + 132);
      v67 = s_bm_current_air_resistance;
      v68 = p_m_lv->mVec128.m128_f32[1] * v66;
      v69 = s_bm_current_air_resistance - *(float *)(v46 + 376);
      v144 = (float)(p_m_lv->mVec128.m128_f32[2] * v66) * v69;
      v143 = v68 * v69;
      v142 = (float)(v66 * p_m_lv->mVec128.m128_f32[0]) * v69;
      v145 = 0;
      p_m_lv->mVec128.m128_f32[0] = v142;
      p_m_lv->mVec128.m128_f32[1] = v143;
      p_m_lv->mVec128.m128_f32[2] = v144;
      p_m_lv->mVec128.m128_i32[3] = v145;
      v70 = *(float *)(v46 + 356);
      v71 = *(float *)(v46 + 360);
      v72 = v67 - *(float *)(v46 + 380);
      v73 = (float)((float)(v111[1] * v70) + (float)(v111[2] * v71)) + (float)(*v49 * *v111);
      v74 = *v49 * v111[8];
      v75 = (float)((float)(v111[5] * v70) + (float)(v111[6] * v71)) + (float)(*v49 * v111[4]);
      v76 = v111[9] * v70;
      v77 = v111[10] * v71;
      v157 = 0;
      v154 = v73 * v72;
      v155 = v75 * v72;
      v156 = (float)((float)(v76 + v77) + v74) * v72;
      *v49 = v73 * v72;
      *(float *)(v46 + 356) = v155;
      *(float *)(v46 + 360) = v156;
      *(_DWORD *)(v46 + 364) = v157;
      v133 = 0;
      v134 = 0;
      v135 = 0;
      v136 = 0;
      *(_DWORD *)(v46 + 272) = 0;
      *(_DWORD *)(v46 + 276) = v134;
      *(_DWORD *)(v46 + 280) = v135;
      *(_DWORD *)(v46 + 284) = v136;
      *(_DWORD *)(v46 + 256) = v133;
      *(_DWORD *)(v46 + 260) = v134;
      *(_DWORD *)(v46 + 264) = v135;
      *(_DWORD *)(v46 + 268) = v136;
      v129 = 0;
      v130 = 0;
      v131 = 0;
      v132 = 0;
      *(_DWORD *)(v46 + 304) = 0;
      *(_DWORD *)(v46 + 308) = v130;
      v78 = *(float *)(v46 + 384);
      *(_DWORD *)(v46 + 312) = v131;
      *(_DWORD *)(v46 + 316) = v132;
      *(_DWORD *)(v46 + 288) = v129;
      *(_DWORD *)(v46 + 292) = v130;
      *(_DWORD *)(v46 + 296) = v131;
      v79 = 0;
      *(_DWORD *)(v46 + 300) = v132;
      *(_DWORD *)(v46 + 320) = 0;
      *(_DWORD *)(v46 + 324) = 0;
      if ( v78 > 0.0 && *(int *)(v46 + 24) > 0 )
      {
        v149 = 0;
        v106 = 0;
        do
        {
          v80 = p_m_framexform->m_basis.m_el[0].mVec128.m128_f32[0];
          v81 = p_m_framexform->m_basis.m_el[1].mVec128.m128_f32[2];
          v111 = *(float **)(*(_DWORD *)(v46 + 32) + 4 * v79);
          v82 = (float *)(v106 + *(_DWORD *)(v46 + 52));
          v83 = v82[1];
          v84 = v82[2];
          v85 = v111[6];
          v106 += 16;
          v86 = v111 + 4;
          v87 = (float)((float)(p_m_framexform->m_basis.m_el[1].mVec128.m128_f32[1] * v83) + (float)(v81 * v84))
              + (float)(*v82 * p_m_framexform->m_basis.m_el[1].mVec128.m128_f32[0]);
          v88 = v111[5];
          v89 = (float)((float)((float)(p_m_framexform->m_basis.m_el[2].mVec128.m128_f32[0] * *v82)
                              + (float)(v83 * p_m_framexform->m_basis.m_el[2].mVec128.m128_f32[1]))
                      + (float)(v84 * p_m_framexform->m_basis.m_el[2].mVec128.m128_f32[2]))
              + p_m_framexform->m_origin.mVec128.m128_f32[2];
          v90 = *(float *)(v46 + 384);
          v91 = (float)((float)(v87 + p_m_framexform->m_origin.mVec128.m128_f32[1]) - v88) * v90;
          v146 = (float)((float)((float)((float)((float)((float)(v80 * *v82)
                                                       + (float)(v83
                                                               * p_m_framexform->m_basis.m_el[0].mVec128.m128_f32[1]))
                                               + (float)(v82[2] * p_m_framexform->m_basis.m_el[0].mVec128.m128_f32[2]))
                                       + p_m_framexform->m_origin.mVec128.m128_f32[0])
                               - v111[4])
                       * v90)
               + v111[4];
          v147 = v91 + v88;
          v148 = (float)((float)(v89 - v85) * v90) + v85;
          v111[4] = v146;
          *++v86 = v147;
          *++v86 = v148;
          ++v79;
          *((_DWORD *)v86 + 1) = v149;
        }
        while ( v79 < *(_DWORD *)(v46 + 24) );
      }
      if ( *(_BYTE *)(v46 + 397) )
      {
        v92 = *(__m128 ***)(v46 + 32);
        v93 = *v92 + 1;
        v112 = v93->m128_u64[0];
        v113 = v93->m128_u64[1];
        v114.mVec128 = *v93;
        if ( v108 > 1 )
        {
          v94 = (float **)(v92 + 1);
          v95 = v108 - 1;
          do
          {
            v96 = *v94;
            if ( *(float *)&v112 > (*v94)[4] )
              *(float *)&v112 = (*v94)[4];
            if ( *((float *)&v112 + 1) > v96[5] )
              *((float *)&v112 + 1) = v96[5];
            if ( *(float *)&v113 > v96[6] )
              *(float *)&v113 = v96[6];
            if ( *((float *)&v113 + 1) > v96[7] )
              *((float *)&v113 + 1) = v96[7];
            if ( v96[4] > v114.mVec128.m128_f32[0] )
              v114.mVec128.m128_f32[0] = v96[4];
            if ( v96[5] > v114.mVec128.m128_f32[1] )
              v114.mVec128.m128_f32[1] = v96[5];
            if ( v96[6] > v114.mVec128.m128_f32[2] )
              v114.mVec128.m128_f32[2] = v96[6];
            if ( v96[7] > v114.mVec128.m128_f32[3] )
              v114.mVec128.m128_f32[3] = v96[7];
            ++v94;
            --v95;
          }
          while ( v95 );
        }
        v109.m_el[0].mVec128.m128_u64[0] = v112;
        v97 = *(btDbvt **)(v46 + 368);
        v109.m_el[0].mVec128.m128_u64[1] = v113;
        v109.m_el[1] = (btVector3)v114.mVec128;
        if ( v97 )
        {
          v98 = *(float *)(a2 + 460);
          v102 = *(float *)(a2 + 472);
          v99 = p_m_lv->mVec128.m128_f32[1] * v98;
          v100 = p_m_lv->mVec128.m128_f32[2] * v98;
          v137.mVec128.m128_f32[0] = (float)(p_m_lv->mVec128.m128_f32[0] * v98) * 3.0;
          v137.mVec128.m128_f32[1] = v99 * 3.0;
          v137.mVec128.m128_f32[2] = v100 * 3.0;
          v137.mVec128.m128_i32[3] = 0;
          btDbvt::update((btDbvtAabbMm *)&v109, &v137, (btDbvt *)(a2 + 1028), v97, v102);
        }
        else
        {
          v101 = btDbvt::insert(0, (btDbvt *)(a2 + 1028), &v109, v46);
          v110->m_leaf = v101;
        }
      }
    }
    ++i;
  }
}
