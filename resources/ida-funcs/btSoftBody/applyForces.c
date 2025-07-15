void __thiscall btSoftBody::applyForces(btSoftBody *this, int a2)
{
  int v2; // esi
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm0_4
  bool v7; // al
  int v8; // xmm7_4
  btSoftBody::Node *v9; // ebx
  float v10; // xmm0_4
  int v11; // esi
  float v12; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm4_4
  int v17; // eax
  float v18; // xmm6_4
  int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm4_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm6_4
  float v30; // xmm3_4
  float v31; // xmm4_4
  int v32; // eax
  float v33; // xmm4_4
  float v34; // xmm6_4
  float v35; // xmm1_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  float v39; // xmm3_4
  float v40; // xmm1_4
  float v41; // xmm2_4
  float v42; // xmm2_4
  float v43; // xmm0_4
  float v44; // xmm1_4
  float v45; // xmm6_4
  int v46; // ebx
  float *v47; // eax
  float *v48; // edx
  float *v49; // ecx
  float v50; // xmm0_4
  float v51; // xmm2_4
  float v52; // xmm3_4
  float v53; // xmm1_4
  float v54; // xmm2_4
  float v55; // xmm0_4
  float v56; // xmm1_4
  unsigned int v57; // xmm2_4
  float v58; // xmm0_4
  int v59; // esi
  float v60; // xmm3_4
  float v61; // xmm2_4
  float v62; // xmm1_4
  float v63; // xmm0_4
  float v64; // xmm4_4
  int v65; // eax
  int v66; // eax
  float v67; // xmm2_4
  float v68; // xmm3_4
  float v69; // xmm4_4
  float v70; // xmm2_4
  float **v71; // ecx
  float v72; // xmm0_4
  float v73; // xmm1_4
  int v74; // edx
  float *v75; // eax
  int v76; // eax
  float v77; // xmm4_4
  float v78; // xmm1_4
  float v79; // xmm0_4
  btSoftBody::Node **v80; // edx
  float v81; // xmm1_4
  float v82; // xmm0_4
  int v83; // esi
  int v84; // edx
  const btSoftBodyWorldInfo *v85; // [esp+0h] [ebp-154h]
  bool v86; // [esp+1Fh] [ebp-135h]
  char v87; // [esp+20h] [ebp-134h]
  bool v88; // [esp+21h] [ebp-133h]
  char v89; // [esp+22h] [ebp-132h]
  char v90; // [esp+23h] [ebp-131h]
  float v91; // [esp+24h] [ebp-130h]
  float v92; // [esp+24h] [ebp-130h]
  float v93; // [esp+24h] [ebp-130h]
  float v94; // [esp+24h] [ebp-130h]
  float v95; // [esp+28h] [ebp-12Ch]
  float v96; // [esp+28h] [ebp-12Ch]
  float v97; // [esp+28h] [ebp-12Ch]
  float v98; // [esp+28h] [ebp-12Ch]
  float v99; // [esp+28h] [ebp-12Ch]
  float v100; // [esp+2Ch] [ebp-128h]
  float v101; // [esp+2Ch] [ebp-128h]
  float v102; // [esp+2Ch] [ebp-128h]
  float v103; // [esp+2Ch] [ebp-128h]
  float v104; // [esp+2Ch] [ebp-128h]
  float v105; // [esp+2Ch] [ebp-128h]
  int v106; // [esp+3Ch] [ebp-118h]
  float v107; // [esp+40h] [ebp-114h]
  int v108; // [esp+40h] [ebp-114h]
  float v109; // [esp+44h] [ebp-110h]
  float v110; // [esp+44h] [ebp-110h]
  float v111; // [esp+48h] [ebp-10Ch]
  float v112; // [esp+4Ch] [ebp-108h]
  float v113; // [esp+4Ch] [ebp-108h]
  int v114; // [esp+60h] [ebp-F4h]
  float v115; // [esp+64h] [ebp-F0h]
  float v116; // [esp+68h] [ebp-ECh]
  int v117; // [esp+68h] [ebp-ECh]
  float v118; // [esp+6Ch] [ebp-E8h]
  float v119; // [esp+70h] [ebp-E4h]
  float v120; // [esp+74h] [ebp-E0h]
  float v121; // [esp+74h] [ebp-E0h]
  float v122; // [esp+78h] [ebp-DCh]
  float v123; // [esp+78h] [ebp-DCh]
  float v124; // [esp+7Ch] [ebp-D8h]
  float v125; // [esp+7Ch] [ebp-D8h]
  float v126; // [esp+7Ch] [ebp-D8h]
  float v127; // [esp+88h] [ebp-CCh]
  float v128; // [esp+88h] [ebp-CCh]
  float v129; // [esp+8Ch] [ebp-C8h]
  float v130; // [esp+8Ch] [ebp-C8h]
  float v131; // [esp+90h] [ebp-C4h]
  float v132; // [esp+90h] [ebp-C4h]
  btVector3 v133; // [esp+94h] [ebp-C0h] BYREF
  btVector3 v134; // [esp+A4h] [ebp-B0h] BYREF
  float v135; // [esp+C0h] [ebp-94h]
  float v136; // [esp+C4h] [ebp-90h]
  float v137; // [esp+C8h] [ebp-8Ch]
  float v138; // [esp+CCh] [ebp-88h]
  int v139; // [esp+D0h] [ebp-84h]
  btSoftBody::sMedium v140; // [esp+D4h] [ebp-80h] BYREF
  btVector3 v141; // [esp+F4h] [ebp-60h] BYREF
  float v142; // [esp+104h] [ebp-50h]
  float v143; // [esp+108h] [ebp-4Ch]
  float v144; // [esp+10Ch] [ebp-48h]
  int v145; // [esp+110h] [ebp-44h]
  float v146; // [esp+114h] [ebp-40h]
  float v147; // [esp+118h] [ebp-3Ch]
  float v148; // [esp+124h] [ebp-30h]
  float v149; // [esp+128h] [ebp-2Ch]
  float v150; // [esp+12Ch] [ebp-28h]
  float v151; // [esp+134h] [ebp-20h]
  float v152; // [esp+148h] [ebp-Ch]

  v2 = a2;
  v3 = *(float *)(a2 + 308);
  v4 = *(float *)(a2 + 316);
  v5 = *(float *)(a2 + 320);
  v135 = *(float *)(a2 + 460);
  v6 = *(float *)(a2 + 312);
  v119 = v6;
  v118 = v3;
  v88 = v4 != 0.0;
  v86 = v5 > 0.0;
  if ( v6 > 0.0 || v3 > 0.0 )
  {
    v87 = 1;
    if ( *(int *)(a2 + 296) < 4 )
    {
      v89 = 1;
      goto LABEL_5;
    }
  }
  else
  {
    v87 = 0;
  }
  v89 = 0;
  if ( !v87 )
  {
LABEL_6:
    v90 = 0;
    goto LABEL_7;
  }
LABEL_5:
  v90 = 1;
  if ( *(int *)(a2 + 296) < 4 )
    goto LABEL_6;
LABEL_7:
  v7 = v4 != 0.0 || v5 > 0.0;
  v116 = 0.0;
  v115 = 0.0;
  if ( v7 )
  {
    LOBYTE(this) = v3 > 0.0;
    btSoftBody::getVolume(this, (int *)a2);
    v116 = v4 / COERCE_FLOAT(LODWORD(v6) & _mask__AbsFloat_);
    v115 = (float)(*(float *)(a2 + 484) - v6) * v5;
  }
  v8 = _mask__NegFloat_;
  if ( *(int *)(a2 + 720) > 0 )
  {
    v106 = 0;
    v114 = *(_DWORD *)(a2 + 720);
    do
    {
      v9 = (btSoftBody::Node *)(v106 + *(_DWORD *)(v2 + 728));
      if ( v9->m_im > 0.0 )
      {
        if ( v87 )
        {
          EvaluateMedium(&v140, &v9->m_x, *(const btSoftBodyWorldInfo **)(v2 + 692));
          v10 = **(float **)(a2 + 692);
          v11 = v2 + 1184;
          v140.m_velocity.mVec128.m128_i32[0] = *(_DWORD *)v11;
          v11 += 4;
          v140.m_velocity.mVec128.m128_i32[1] = *(_DWORD *)v11;
          v140.m_velocity.mVec128.m128_u64[1] = *(_QWORD *)(v11 + 4);
          v140.m_density = v10;
          if ( v89 )
          {
            v12 = v9->m_v.mVec128.m128_f32[0] - v140.m_velocity.mVec128.m128_f32[0];
            v13 = v9->m_v.mVec128.m128_f32[1] - v140.m_velocity.mVec128.m128_f32[1];
            v14 = v9->m_v.mVec128.m128_f32[2] - v140.m_velocity.mVec128.m128_f32[2];
            v15 = (float)((float)(v12 * v12) + (float)(v13 * v13)) + (float)(v14 * v14);
            v16 = fsqrt(v15);
            v141.mVec128.m128_f32[0] = v12;
            v127 = v16;
            v107 = v15;
            if ( v15 > 0.00000011920929 )
            {
              v17 = *(_DWORD *)(a2 + 296);
              v91 = v9->m_n.mVec128.m128_f32[0];
              v95 = v9->m_n.mVec128.m128_f32[1];
              v100 = v9->m_n.mVec128.m128_f32[2];
              v109 = (float)(s_bm_current_air_resistance / v16) * v12;
              v129 = s_bm_current_air_resistance / v16;
              v18 = v13 * (float)(s_bm_current_air_resistance / v16);
              v112 = v14 * (float)(s_bm_current_air_resistance / v16);
              if ( v17 == 2 )
              {
                if ( (float)((float)((float)(v91 * v12) + (float)(v95 * v13)) + (float)(v100 * v14)) >= 0.0 )
                  v19 = 1;
                else
                  v19 = -1;
                v92 = v91 * (float)v19;
                v101 = v100 * (float)v19;
                v96 = v95 * (float)v19;
                v20 = (float)((float)(v101 * v112) + (float)(v96 * v18)) + (float)(v109 * v92);
                v131 = v9->m_area * 0.5;
                v21 = (float)((float)((float)((float)(v131 * v20) * v107) * v140.m_density) * v118) * 0.5;
                v22 = COERCE_FLOAT(LODWORD(v18) ^ v8) * v21;
                v23 = COERCE_FLOAT(LODWORD(v112) ^ v8) * v21;
                v120 = 0.0;
                v122 = 0.0;
                v124 = 0.0;
                v134.mVec128.m128_f32[0] = COERCE_FLOAT(LODWORD(v109) ^ v8) * v21;
                v134.mVec128.m128_f32[1] = v22;
                v134.mVec128.m128_f32[2] = v23;
                if ( v20 > 0.0 && v20 < 0.98479998 )
                {
                  v24 = (float)((float)((float)((float)(fsqrt(s_bm_current_air_resistance - (float)(v20 * v20)) * v131)
                                              * v127)
                                      * v140.m_density)
                              * v119)
                      * 0.5;
                  v25 = (float)(v96 * v112) - (float)(v101 * v18);
                  v143 = (float)(v101 * v109) - (float)(v112 * v92);
                  v26 = (float)(v18 * v92) - (float)(v96 * v109);
                  v27 = (float)(v143 * v112) - (float)(v26 * v18);
                  v28 = (float)(v26 * v109) - (float)(v112 * v25);
                  v23 = v134.mVec128.m128_f32[2];
                  v29 = (float)(v18 * v25) - (float)(v143 * v109);
                  v22 = v134.mVec128.m128_f32[1];
                  v139 = 0;
                  v136 = v27 * v24;
                  v137 = v28 * v24;
                  v138 = v29 * v24;
                  v120 = v27 * v24;
                  v122 = v28 * v24;
                  v124 = v29 * v24;
                }
                v30 = v22 + v9->m_f.mVec128.m128_f32[1];
                v31 = v23 + v9->m_f.mVec128.m128_f32[2];
                v9->m_f.mVec128.m128_f32[0] = v9->m_f.mVec128.m128_f32[0] + v134.mVec128.m128_f32[0];
                v9->m_f.mVec128.m128_f32[1] = v30;
                v9->m_f.mVec128.m128_f32[2] = v31;
                v9->m_f.mVec128.m128_f32[0] = v120 + v9->m_f.mVec128.m128_f32[0];
                v9->m_f.mVec128.m128_f32[1] = v122 + v9->m_f.mVec128.m128_f32[1];
                v9->m_f.mVec128.m128_f32[2] = v124 + v9->m_f.mVec128.m128_f32[2];
              }
              else if ( !v17 || v17 == 3 || v17 == 1 )
              {
                v32 = (float)((float)((float)(v91 * v12) + (float)(v95 * v13)) + (float)(v100 * v14)) >= 0.0 ? 1 : -1;
                v33 = v95 * (float)v32;
                v34 = v91 * (float)v32;
                v102 = v100 * (float)v32;
                v35 = (float)((float)(v34 * v141.mVec128.m128_f32[0]) + (float)(v33 * v13)) + (float)(v102 * v14);
                if ( v35 > 0.0 )
                {
                  v36 = (float)((float)((float)(v9->m_area * v35) * v15) * 0.5) * v140.m_density;
                  LODWORD(v37) = COERCE_UNSIGNED_INT(v36 * v119) ^ v8;
                  v133.mVec128.m128_i32[3] = 0;
                  LODWORD(v38) = COERCE_UNSIGNED_INT(v36 * v118) ^ v8;
                  v133.mVec128.m128_f32[0] = (float)((float)(v129 * v141.mVec128.m128_f32[0]) * v38)
                                           + (float)(v34 * v37);
                  v133.mVec128.m128_f32[1] = (float)((float)(v13 * v129) * v38) + (float)(v33 * v37);
                  v133.mVec128.m128_f32[2] = (float)((float)(v14 * v129) * v38) + (float)(v102 * v37);
                  ApplyClampedForce(v9, &v133, v135);
                  v8 = _mask__NegFloat_;
                }
              }
            }
          }
          v2 = a2;
        }
        if ( v88 )
        {
          v39 = v9->m_area * v116;
          v40 = (float)(v9->m_n.mVec128.m128_f32[1] * v39) + v9->m_f.mVec128.m128_f32[1];
          v41 = (float)(v9->m_n.mVec128.m128_f32[2] * v39) + v9->m_f.mVec128.m128_f32[2];
          v9->m_f.mVec128.m128_f32[0] = (float)(v9->m_n.mVec128.m128_f32[0] * v39) + v9->m_f.mVec128.m128_f32[0];
          v9->m_f.mVec128.m128_f32[1] = v40;
          v9->m_f.mVec128.m128_f32[2] = v41;
        }
        if ( v86 )
        {
          v42 = v9->m_area * v115;
          v43 = (float)(v9->m_n.mVec128.m128_f32[1] * v42) + v9->m_f.mVec128.m128_f32[1];
          v44 = (float)(v9->m_n.mVec128.m128_f32[2] * v42) + v9->m_f.mVec128.m128_f32[2];
          v9->m_f.mVec128.m128_f32[0] = v9->m_f.mVec128.m128_f32[0] + (float)(v9->m_n.mVec128.m128_f32[0] * v42);
          v9->m_f.mVec128.m128_f32[1] = v43;
          v9->m_f.mVec128.m128_f32[2] = v44;
        }
      }
      v106 += 112;
      --v114;
    }
    while ( v114 );
  }
  if ( *(int *)(v2 + 760) > 0 )
  {
    v108 = 0;
    v45 = FLOAT_0_33333334;
    v117 = *(_DWORD *)(v2 + 760);
    do
    {
      v46 = v108 + *(_DWORD *)(v2 + 768);
      if ( v90 )
      {
        v47 = *(float **)(v46 + 12);
        v48 = *(float **)(v46 + 16);
        v85 = *(const btSoftBodyWorldInfo **)(v2 + 692);
        v49 = *(float **)(v46 + 8);
        v50 = (float)(v49[12] + v47[12]) + v48[12];
        v51 = v48[14] + (float)(v47[14] + v49[14]);
        v52 = v49[6] + v47[6];
        v149 = (float)(v48[13] + (float)(v47[13] + v49[13])) * v45;
        v53 = v47[4] + v49[4];
        v150 = v51 * v45;
        v54 = v49[5] + v47[5];
        v148 = v50 * v45;
        v55 = v48[4] + v53;
        v56 = v48[5] + v54;
        *(float *)&v57 = (float)(v48[6] + v52) * v45;
        v141.mVec128.m128_f32[0] = v55 * v45;
        v141.mVec128.m128_f32[1] = v56 * v45;
        v141.mVec128.m128_u64[1] = v57;
        EvaluateMedium(&v140, &v141, v85);
        v58 = **(float **)(a2 + 692);
        v59 = v2 + 1184;
        v140.m_velocity.mVec128.m128_i32[0] = *(_DWORD *)v59;
        v59 += 4;
        v140.m_velocity.mVec128.m128_i32[1] = *(_DWORD *)v59;
        v140.m_velocity.mVec128.m128_u64[1] = *(_QWORD *)(v59 + 4);
        v60 = v150 - v140.m_velocity.mVec128.m128_f32[2];
        v61 = v149 - v140.m_velocity.mVec128.m128_f32[1];
        v140.m_density = v58;
        v62 = v148 - v140.m_velocity.mVec128.m128_f32[0];
        v63 = (float)((float)(v62 * v62) + (float)(v60 * v60)) + (float)(v61 * v61);
        v64 = fsqrt(v63);
        v151 = v148 - v140.m_velocity.mVec128.m128_f32[0];
        v128 = v64;
        if ( v63 > 0.00000011920929 )
        {
          v65 = *(_DWORD *)(a2 + 296);
          v93 = *(float *)(v46 + 32);
          v97 = *(float *)(v46 + 36);
          v110 = (float)(s_bm_current_air_resistance / v64) * v62;
          v103 = *(float *)(v46 + 40);
          v111 = v61 * (float)(s_bm_current_air_resistance / v64);
          v132 = s_bm_current_air_resistance / v64;
          v113 = v60 * (float)(s_bm_current_air_resistance / v64);
          if ( v65 == 5 )
          {
            if ( (float)((float)((float)(v62 * v93) + (float)(v103 * v60)) + (float)(v97 * v61)) >= 0.0 )
              v66 = 1;
            else
              v66 = -1;
            v104 = v103 * (float)v66;
            v94 = v93 * (float)v66;
            v98 = v97 * (float)v66;
            v67 = (float)((float)(v110 * v94) + (float)(v104 * v113)) + (float)(v98 * v111);
            v130 = *(float *)(v46 + 48) * 0.5;
            v68 = (float)((float)((float)((float)(v130 * v67) * v63) * v140.m_density) * v118) * 0.5;
            v139 = 0;
            v69 = COERCE_FLOAT(LODWORD(v110) ^ v8) * v68;
            v136 = v69;
            v137 = COERCE_FLOAT(LODWORD(v111) ^ v8) * v68;
            v138 = COERCE_FLOAT(LODWORD(v113) ^ v8) * v68;
            v133.mVec128.m128_f32[0] = v69;
            v133.mVec128.m128_f32[1] = v137;
            v133.mVec128.m128_f32[2] = v138;
            v121 = 0.0;
            v123 = 0.0;
            v125 = 0.0;
            v133.mVec128.m128_i32[3] = 0;
            if ( v67 > 0.0 && v67 < 0.98479998 )
            {
              v70 = (float)((float)((float)((float)(fsqrt(s_bm_current_air_resistance - (float)(v67 * v67)) * v130)
                                          * v128)
                                  * v140.m_density)
                          * v119)
                  * 0.5;
              v146 = (float)(v98 * v113) - (float)(v104 * v111);
              v147 = (float)(v104 * v110) - (float)(v113 * v94);
              v69 = v136;
              v145 = 0;
              v142 = (float)((float)(v147 * v113) - (float)((float)((float)(v111 * v94) - (float)(v98 * v110)) * v111))
                   * v70;
              v143 = (float)((float)((float)((float)(v111 * v94) - (float)(v98 * v110)) * v110) - (float)(v113 * v146))
                   * v70;
              v144 = (float)((float)(v111 * v146) - (float)(v147 * v110)) * v70;
              v121 = v142;
              v123 = v143;
              v125 = v144;
            }
            v71 = (float **)(v46 + 8);
            v133.mVec128.m128_f32[0] = v69 * v45;
            v72 = v133.mVec128.m128_f32[1] * v45;
            v73 = v133.mVec128.m128_f32[2] * v45;
            v133.mVec128.m128_f32[1] = v133.mVec128.m128_f32[1] * v45;
            v133.mVec128.m128_f32[2] = v133.mVec128.m128_f32[2] * v45;
            v126 = v125 * v45;
            v74 = 3;
            do
            {
              v75 = *v71;
              if ( (*v71)[24] > 0.0 )
              {
                v75[16] = v75[16] + v133.mVec128.m128_f32[0];
                v75[17] = v75[17] + v72;
                v75[18] = v75[18] + v73;
                v75[16] = (float)(v121 * v45) + v75[16];
                v75[17] = (float)(v123 * v45) + v75[17];
                v75[18] = v126 + v75[18];
              }
              ++v71;
              --v74;
            }
            while ( v74 );
          }
          else if ( v65 == 6 || v65 == 4 )
          {
            v76 = (float)((float)((float)(v62 * v93) + (float)(v103 * v60)) + (float)(v97 * v61)) >= 0.0 ? 1 : -1;
            v99 = v97 * (float)v76;
            v77 = v93 * (float)v76;
            v105 = v103 * (float)v76;
            v78 = (float)((float)(v151 * v77) + (float)(v105 * v60)) + (float)(v99 * v61);
            if ( v78 > 0.0 )
            {
              v79 = (float)((float)(*(float *)(v46 + 48) * v78) * v63) * v140.m_density;
              v80 = (btSoftBody::Node **)(v46 + 8);
              LODWORD(v81) = COERCE_UNSIGNED_INT(v79 * v119) ^ v8;
              v134.mVec128.m128_i32[3] = 0;
              v152 = v99 * v81;
              LODWORD(v82) = COERCE_UNSIGNED_INT(v79 * v118) ^ v8;
              v134.mVec128.m128_f32[0] = (float)((float)((float)(v132 * v151) * v82) + (float)(v77 * v81)) * v45;
              v134.mVec128.m128_f32[1] = (float)((float)((float)(v61 * v132) * v82) + (float)(v99 * v81)) * v45;
              v134.mVec128.m128_f32[2] = (float)((float)((float)(v60 * v132) * v82) + (float)(v105 * v81)) * v45;
              v83 = 3;
              do
              {
                ApplyClampedForce(*v80, &v134, v135);
                v80 = (btSoftBody::Node **)(v84 + 4);
                --v83;
              }
              while ( v83 );
              v45 = FLOAT_0_33333334;
              v8 = _mask__NegFloat_;
            }
          }
        }
        v2 = a2;
      }
      v108 += 64;
      --v117;
    }
    while ( v117 );
  }
}
