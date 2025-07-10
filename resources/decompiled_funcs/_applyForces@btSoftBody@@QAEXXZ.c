void __thiscall btSoftBody::applyForces(btSoftBody *this, btSoftBody *thisa)
{
  CProfileNode *v2; // esi
  int RecursionCounter; // eax
  int v4; // ecx
  btSoftBody *v5; // esi
  float kPR; // xmm3_4
  float kVC; // xmm4_4
  float _X; // xmm0_4
  bool v9; // al
  long double v10; // st7
  btSoftBody::Node *v11; // ebx
  float *p_air_density; // edx
  btSoftBody::eAeroModel::_ aeromodel; // eax
  float v14; // xmm4_4
  float v15; // xmm5_4
  int v16; // eax
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm3_4
  int v20; // xmm4_4
  int v21; // xmm5_4
  long double v22; // st7
  float v23; // xmm4_4
  float v24; // xmm0_4
  float v25; // xmm7_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  int v30; // eax
  float v31; // xmm5_4
  float v32; // xmm4_4
  float v33; // xmm7_4
  float v34; // xmm1_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm0_4
  float v39; // xmm3_4
  float v40; // xmm4_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm3_4
  btSoftBody::Face *v44; // edi
  float *v45; // ecx
  float *v46; // eax
  float v47; // xmm1_4
  float v48; // xmm3_4
  float v49; // xmm4_4
  float *v50; // eax
  int *m_n; // ebx
  float v52; // xmm1_4
  float v53; // xmm2_4
  float v54; // xmm3_4
  float *v55; // eax
  float v56; // xmm2_4
  float v57; // xmm3_4
  btSoftBody::eAeroModel::_ v58; // eax
  float v59; // xmm4_4
  int v60; // eax
  float v61; // xmm1_4
  float v62; // xmm0_4
  int v63; // xmm2_4
  float v64; // xmm6_4
  long double v65; // st7
  float v66; // xmm4_4
  float v67; // xmm0_4
  float v68; // xmm7_4
  float v69; // xmm4_4
  float v70; // xmm1_4
  float v71; // xmm2_4
  float v72; // xmm3_4
  float v73; // xmm6_4
  float *v74; // edx
  float *v75; // eax
  int v76; // eax
  float v77; // xmm2_4
  float v78; // xmm4_4
  float v79; // xmm1_4
  float v80; // xmm0_4
  float v81; // xmm1_4
  float v82; // xmm0_4
  btSoftBody::Node **v83; // edi
  int v84; // ebx
  CProfileNode *v85; // esi
  bool v86; // zf
  bool v87; // [esp+1349h] [ebp-F1h]
  char v88; // [esp+134Ah] [ebp-F0h]
  bool v89; // [esp+134Bh] [ebp-EFh]
  char v90; // [esp+134Ch] [ebp-EEh]
  char v91; // [esp+134Dh] [ebp-EDh]
  int v92; // [esp+134Eh] [ebp-ECh]
  int v93; // [esp+134Eh] [ebp-ECh]
  int m_size; // [esp+1352h] [ebp-E8h]
  float v95; // [esp+1352h] [ebp-E8h]
  float v96; // [esp+1356h] [ebp-E4h]
  float v97; // [esp+1356h] [ebp-E4h]
  unsigned __int64 v98; // [esp+135Ah] [ebp-E0h]
  __int64 v100; // [esp+135Ah] [ebp-E0h]
  unsigned __int64 v102; // [esp+1362h] [ebp-D8h]
  float v103; // [esp+1362h] [ebp-D8h]
  __int64 v104; // [esp+1362h] [ebp-D8h]
  float v105; // [esp+1362h] [ebp-D8h]
  float v106; // [esp+1376h] [ebp-C4h]
  float v107; // [esp+137Ah] [ebp-C0h]
  float v108; // [esp+137Ah] [ebp-C0h]
  float v109; // [esp+137Ah] [ebp-C0h]
  float v110; // [esp+137Eh] [ebp-BCh]
  int v111; // [esp+137Eh] [ebp-BCh]
  float kDG; // [esp+1382h] [ebp-B8h]
  float v113; // [esp+1386h] [ebp-B4h]
  float v114; // [esp+138Ah] [ebp-B0h]
  __m128i v115; // [esp+138Ah] [ebp-B0h]
  float v116; // [esp+138Eh] [ebp-ACh]
  float v117; // [esp+138Eh] [ebp-ACh]
  float v118; // [esp+1392h] [ebp-A8h]
  float v119; // [esp+1392h] [ebp-A8h]
  float v120; // [esp+139Ah] [ebp-A0h]
  float v121; // [esp+139Ah] [ebp-A0h]
  float v122; // [esp+139Eh] [ebp-9Ch]
  float v123; // [esp+139Eh] [ebp-9Ch]
  float v124; // [esp+13A2h] [ebp-98h]
  float v125; // [esp+13A2h] [ebp-98h]
  float v126; // [esp+13B2h] [ebp-88h]
  float v127; // [esp+13B2h] [ebp-88h]
  float v128; // [esp+13B6h] [ebp-84h]
  __m128i si128; // [esp+13BAh] [ebp-80h]
  float v130; // [esp+13BAh] [ebp-80h]
  float v131; // [esp+13BEh] [ebp-7Ch]
  float sdt; // [esp+13D2h] [ebp-68h]
  float v133; // [esp+13D6h] [ebp-64h]
  __m128i v134; // [esp+13DAh] [ebp-60h] BYREF
  btVector3 v135; // [esp+13EAh] [ebp-50h] BYREF
  btVector3 f; // [esp+13FAh] [ebp-40h] BYREF
  btSoftBody::sMedium v137; // [esp+140Ah] [ebp-30h] BYREF
  __m128i v138; // [esp+142Ah] [ebp-10h]

  if ( CProfileManager::CurrentNode->Name != "SoftBody applyForces" )
    CProfileManager::CurrentNode = CProfileNode::Get_Sub_Node((const char *)this);
  v2 = CProfileManager::CurrentNode;
  RecursionCounter = CProfileManager::CurrentNode->RecursionCounter;
  ++CProfileManager::CurrentNode->TotalCalls;
  v4 = RecursionCounter + 1;
  v2->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
    v2->StartTime = btClock::getTimeMicroseconds((btClock *)v4);
  v5 = thisa;
  kPR = thisa->m_cfg.kPR;
  kVC = thisa->m_cfg.kVC;
  sdt = thisa->m_sst.sdt;
  _X = thisa->m_cfg.kLF;
  v113 = _X;
  kDG = thisa->m_cfg.kDG;
  LOBYTE(v4) = _X > 0.0;
  v87 = kPR != 0.0;
  v89 = kVC > 0.0;
  if ( _X > 0.0 || thisa->m_cfg.kDG > 0.0 )
  {
    v88 = 1;
    if ( thisa->m_cfg.aeromodel < END )
    {
      v91 = 1;
      goto LABEL_9;
    }
  }
  else
  {
    v88 = 0;
  }
  v91 = 0;
  if ( !v88 )
  {
LABEL_10:
    v90 = 0;
    goto LABEL_11;
  }
LABEL_9:
  v90 = 1;
  if ( thisa->m_cfg.aeromodel < END )
    goto LABEL_10;
LABEL_11:
  v9 = kPR != 0.0 || kVC > 0.0;
  v133 = 0.0;
  v110 = 0.0;
  if ( v9 )
  {
    btSoftBody::getVolume((btSoftBody *)v4, (int *)thisa);
    v10 = fabsf(_X);
    v110 = (float)(thisa->m_pose.m_volume - _X) * kVC;
    v133 = kPR / v10;
  }
  if ( thisa->m_nodes.m_size > 0 )
  {
    v92 = 0;
    m_size = thisa->m_nodes.m_size;
    do
    {
      v11 = &v5->m_nodes.m_data[v92];
      if ( v11->m_im > 0.0 )
      {
        if ( v88 )
        {
          EvaluateMedium(v5->m_worldInfo, &v11->m_x, &v137);
          v5 = thisa;
          p_air_density = &thisa->m_worldInfo->air_density;
          v137.m_velocity.mVec128.m128_u64[0] = thisa->m_windVelocity.mVec128.m128_u64[0];
          v137.m_velocity.mVec128.m128_u64[1] = thisa->m_windVelocity.mVec128.m128_u64[1];
          v137.m_density = *p_air_density;
          if ( v91 )
          {
            v124 = v11->m_v.mVec128.m128_f32[2] - v137.m_velocity.mVec128.m128_f32[2];
            v122 = v11->m_v.mVec128.m128_f32[1] - v137.m_velocity.mVec128.m128_f32[1];
            v106 = (float)((float)(v124 * v124) + (float)(v122 * v122))
                 + (float)((float)(v11->m_v.mVec128.m128_f32[0] - v137.m_velocity.mVec128.m128_f32[0])
                         * (float)(v11->m_v.mVec128.m128_f32[0] - v137.m_velocity.mVec128.m128_f32[0]));
            v120 = v11->m_v.mVec128.m128_f32[0] - v137.m_velocity.mVec128.m128_f32[0];
            v126 = sqrtf(v106);
            if ( v106 > 0.00000011920929 )
            {
              aeromodel = thisa->m_cfg.aeromodel;
              v107 = *(float *)&clear_value / v126;
              v14 = v120 * (float)(*(float *)&clear_value / v126);
              v15 = v122 * (float)(*(float *)&clear_value / v126);
              v98 = v11->m_n.mVec128.m128_u64[0];
              v114 = v14;
              v116 = v15;
              v118 = v124 * (float)(*(float *)&clear_value / v126);
              v102 = v11->m_n.mVec128.m128_u64[1];
              if ( aeromodel == RContacts )
              {
                if ( (float)((float)((float)(*(float *)&v102 * v124) + (float)(*((float *)&v98 + 1) * v122))
                           + (float)(*(float *)&v98 * v120)) >= 0.0 )
                  v16 = 1;
                else
                  v16 = -1;
                *((float *)&v98 + 1) = *((float *)&v98 + 1) * (float)v16;
                v103 = *(float *)&v102 * (float)v16;
                v17 = (float)((float)(v103 * v118) + (float)(*((float *)&v98 + 1) * v15))
                    + (float)(v14 * (float)(*(float *)&v98 * (float)v16));
                v128 = v11->m_area * 0.5;
                *(float *)&v98 = *(float *)&v98 * (float)v16;
                v18 = (float)((float)((float)((float)(v128 * v17) * v106) * v137.m_density) * kDG) * 0.5;
                v19 = -v14;
                *(float *)&v20 = (float)-v15 * v18;
                *(float *)&v21 = (float)-v118 * v18;
                si128.m128i_i32[0] = 0;
                *(__int64 *)((char *)si128.m128i_i64 + 4) = 0;
                *(float *)v134.m128i_i32 = v19 * v18;
                v134.m128i_i32[1] = v20;
                v134.m128i_i32[2] = v21;
                if ( v17 > 0.0 && v17 < 0.98479998 )
                {
                  v22 = sqrtf(*(float *)&clear_value - (float)(v17 * v17));
                  v23 = (float)(*((float *)&v98 + 1) * v118) - (float)(v103 * v116);
                  v96 = v22 * v128 * v126 * v137.m_density * v113 * 0.5;
                  v24 = (float)(v116 * *(float *)&v98) - (float)(*((float *)&v98 + 1) * v114);
                  v25 = v24 * v116;
                  v26 = (float)(v24 * v114) - (float)(v118 * v23);
                  v27 = v116 * v23;
                  v20 = v134.m128i_i32[1];
                  v21 = v134.m128i_i32[2];
                  v135.mVec128.m128_f32[0] = (float)((float)((float)((float)(v103 * v114)
                                                                   - (float)(v118 * *(float *)&v98))
                                                           * v118)
                                                   - v25)
                                           * v96;
                  v135.mVec128.m128_f32[1] = v26 * v96;
                  v135.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                                               (float)(v27
                                                     - (float)((float)((float)(v103 * v114)
                                                                     - (float)(v118 * *(float *)&v98))
                                                             * v114))
                                             * v96);
                  si128 = _mm_load_si128((const __m128i *)&v135);
                }
                v28 = *(float *)&v20 + v11->m_f.mVec128.m128_f32[1];
                v29 = *(float *)&v21 + v11->m_f.mVec128.m128_f32[2];
                v11->m_f.mVec128.m128_f32[0] = v11->m_f.mVec128.m128_f32[0] + *(float *)v134.m128i_i32;
                v11->m_f.mVec128.m128_f32[1] = v28;
                v11->m_f.mVec128.m128_f32[2] = v29;
                v11->m_f.mVec128.m128_f32[0] = *(float *)si128.m128i_i32 + v11->m_f.mVec128.m128_f32[0];
                v11->m_f.mVec128.m128_f32[1] = *(float *)&si128.m128i_i32[1] + v11->m_f.mVec128.m128_f32[1];
                v11->m_f.mVec128.m128_f32[2] = *(float *)&si128.m128i_i32[2] + v11->m_f.mVec128.m128_f32[2];
              }
              else if ( aeromodel == Linear || aeromodel == SContacts || aeromodel == Anchors )
              {
                v30 = (float)((float)((float)(*(float *)&v102 * v124) + (float)(*((float *)&v98 + 1) * v122))
                            + (float)(*(float *)&v98 * v120)) >= 0.0
                    ? 1
                    : -1;
                v31 = *((float *)&v98 + 1) * (float)v30;
                v32 = *(float *)&v98 * (float)v30;
                v33 = *(float *)&v102 * (float)v30;
                v34 = (float)((float)(v33 * v124) + (float)(v31 * v122)) + (float)(v32 * v120);
                if ( v34 > 0.0 )
                {
                  v35 = (float)((float)((float)(v11->m_area * v34) * v106) * 0.5) * v137.m_density;
                  f.mVec128.m128_i32[3] = 0;
                  v36 = -(float)(v35 * v113);
                  v37 = -(float)(v35 * kDG);
                  f.mVec128.m128_f32[0] = (float)((float)(v107 * v120) * v37) + (float)(v32 * v36);
                  f.mVec128.m128_f32[1] = (float)((float)(v122 * v107) * v37) + (float)(v31 * v36);
                  f.mVec128.m128_f32[2] = (float)((float)(v124 * v107) * v37) + (float)(v33 * v36);
                  ApplyClampedForce(v11, &f, sdt);
                  v5 = thisa;
                }
              }
            }
          }
        }
        if ( v87 )
        {
          v38 = v11->m_area * v133;
          v39 = (float)(v11->m_n.mVec128.m128_f32[1] * v38) + v11->m_f.mVec128.m128_f32[1];
          v40 = (float)(v11->m_n.mVec128.m128_f32[2] * v38) + v11->m_f.mVec128.m128_f32[2];
          v11->m_f.mVec128.m128_f32[0] = (float)(v11->m_n.mVec128.m128_f32[0] * v38) + v11->m_f.mVec128.m128_f32[0];
          v11->m_f.mVec128.m128_f32[1] = v39;
          v11->m_f.mVec128.m128_f32[2] = v40;
        }
        if ( v89 )
        {
          v41 = v11->m_area * v110;
          v42 = (float)(v11->m_n.mVec128.m128_f32[1] * v41) + v11->m_f.mVec128.m128_f32[1];
          v43 = (float)(v11->m_n.mVec128.m128_f32[2] * v41) + v11->m_f.mVec128.m128_f32[2];
          v11->m_f.mVec128.m128_f32[0] = v11->m_f.mVec128.m128_f32[0] + (float)(v11->m_n.mVec128.m128_f32[0] * v41);
          v11->m_f.mVec128.m128_f32[1] = v42;
          v11->m_f.mVec128.m128_f32[2] = v43;
        }
      }
      ++v92;
      --m_size;
    }
    while ( m_size );
  }
  if ( v5->m_faces.m_size > 0 )
  {
    v93 = 0;
    v111 = v5->m_faces.m_size;
    do
    {
      v44 = &v5->m_faces.m_data[v93];
      if ( v90 )
      {
        v45 = (float *)v44->m_n[0];
        v46 = (float *)v44->m_n[1];
        v47 = v45[12] + v46[12];
        v48 = v46[13] + v45[13];
        v49 = v46[14] + v45[14];
        v50 = (float *)v44->m_n[2];
        m_n = (int *)v44->m_n;
        v52 = (float)(v47 + v50[12]) * 0.33333334;
        v53 = v50[13] + v48;
        v54 = v50[14];
        v55 = &v5->m_worldInfo->air_density;
        v137.m_velocity.mVec128.m128_u64[0] = v5->m_windVelocity.mVec128.m128_u64[0];
        v56 = (float)(v53 * 0.33333334) - v137.m_velocity.mVec128.m128_f32[1];
        v137.m_velocity.mVec128.m128_u64[1] = v5->m_windVelocity.mVec128.m128_u64[1];
        v57 = (float)((float)(v54 + v49) * 0.33333334) - v137.m_velocity.mVec128.m128_f32[2];
        v137.m_density = *v55;
        v130 = v52 - v137.m_velocity.mVec128.m128_f32[0];
        v95 = (float)((float)(v130 * v130) + (float)(v57 * v57)) + (float)(v56 * v56);
        v131 = v56;
        v108 = sqrtf(v95);
        if ( v95 > 0.00000011920929 )
        {
          v58 = v5->m_cfg.aeromodel;
          v127 = *(float *)&clear_value / v108;
          v123 = v56 * (float)(*(float *)&clear_value / v108);
          v59 = v130 * (float)(*(float *)&clear_value / v108);
          v100 = v44->m_normal.mVec128.m128_i64[0];
          v121 = v59;
          v125 = v57 * (float)(*(float *)&clear_value / v108);
          v104 = v44->m_normal.mVec128.m128_i64[1];
          if ( v58 == (END|Anchors) )
          {
            if ( (float)((float)((float)(v130 * *(float *)&v100) + (float)(*(float *)&v104 * v57))
                       + (float)(*((float *)&v100 + 1) * v56)) >= 0.0 )
              v60 = 1;
            else
              v60 = -1;
            v105 = *(float *)&v104 * (float)v60;
            *(float *)&v100 = *(float *)&v100 * (float)v60;
            v61 = (float)((float)(v59 * (float)(v44->m_normal.mVec128.m128_f32[0] * (float)v60)) + (float)(v105 * v125))
                + (float)((float)(*((float *)&v100 + 1) * (float)v60) * v123);
            *((float *)&v100 + 1) = *((float *)&v100 + 1) * (float)v60;
            v97 = v44->m_ra * 0.5;
            v62 = (float)((float)((float)((float)(v97 * v61) * v95) * v137.m_density) * kDG) * 0.5;
            *(float *)&v63 = (float)-v59 * v62;
            v134.m128i_i32[0] = v63;
            *(float *)&v134.m128i_i32[1] = (float)-v123 * v62;
            *(float *)&v134.m128i_i32[2] = (float)-v125 * v62;
            v134.m128i_i32[3] = 0;
            v115.m128i_i64[0] = 0;
            v64 = 0.0;
            v138 = _mm_load_si128(&v134);
            if ( v61 > 0.0 && v61 < 0.98479998 )
            {
              v65 = sqrtf(*(float *)&clear_value - (float)(v61 * v61));
              v66 = (float)(*((float *)&v100 + 1) * v125) - (float)(v105 * v123);
              v109 = v65 * v97 * v108 * v137.m_density * v113 * 0.5;
              v67 = (float)(v123 * *(float *)&v100) - (float)(*((float *)&v100 + 1) * v121);
              f.mVec128.m128_f32[0] = (float)((float)((float)((float)(v105 * v121) - (float)(v125 * *(float *)&v100))
                                                    * v125)
                                            - (float)(v67 * v123))
                                    * v109;
              v63 = v134.m128i_i32[0];
              f.mVec128.m128_f32[1] = (float)((float)(v67 * v121) - (float)(v125 * v66)) * v109;
              f.mVec128.m128_f32[2] = (float)((float)(v123 * v66)
                                            - (float)((float)((float)(v105 * v121) - (float)(v125 * *(float *)&v100))
                                                    * v121))
                                    * v109;
              f.mVec128.m128_i32[3] = 0;
              v115 = _mm_load_si128((const __m128i *)&f);
              v64 = *(float *)&v115.m128i_i32[2];
            }
            v4 = *m_n;
            v68 = *(float *)&v63 * 0.33333334;
            v119 = v64 * 0.33333334;
            v69 = *(float *)&v115.m128i_i32[1] * 0.33333334;
            v70 = *(float *)&v138.m128i_i32[1] * 0.33333334;
            v71 = *(float *)&v138.m128i_i32[2] * 0.33333334;
            v72 = *(float *)v115.m128i_i32 * 0.33333334;
            v117 = *(float *)&v115.m128i_i32[1] * 0.33333334;
            if ( *(float *)(*m_n + 96) > 0.0 )
            {
              *(float *)(v4 + 64) = *(float *)(v4 + 64) + v68;
              *(float *)(v4 + 68) = v70 + *(float *)(v4 + 68);
              *(float *)(v4 + 72) = v71 + *(float *)(v4 + 72);
              *(float *)(v4 + 64) = v72 + *(float *)(v4 + 64);
              v73 = *(float *)(v4 + 68) + v69;
              *(float *)(v4 + 72) = *(float *)(v4 + 72) + v119;
              v69 = v117;
              *(float *)(v4 + 68) = v73;
            }
            v74 = (float *)v44->m_n[1];
            if ( v74[24] > 0.0 )
            {
              v74[16] = v74[16] + v68;
              v74[17] = v70 + v74[17];
              v74[18] = v71 + v74[18];
              v74[16] = v72 + v74[16];
              v74[17] = v74[17] + v69;
              v74[18] = v74[18] + v119;
              v69 = v117;
            }
            v75 = (float *)v44->m_n[2];
            if ( v75[24] > 0.0 )
            {
              v75[16] = v75[16] + v68;
              v75[17] = v70 + v75[17];
              v75[18] = v71 + v75[18];
              v75[16] = v72 + v75[16];
              v75[17] = v75[17] + v69;
              v75[18] = v75[18] + v119;
            }
          }
          else if ( v58 == (END|RContacts) || v58 == END )
          {
            v76 = (float)((float)((float)(v130 * *(float *)&v100) + (float)(*(float *)&v104 * v57))
                        + (float)(*((float *)&v100 + 1) * v56)) >= 0.0
                ? 1
                : -1;
            v77 = *(float *)&v104 * (float)v76;
            v78 = *(float *)&v100 * (float)v76;
            v79 = (float)((float)(v130 * v78) + (float)(v77 * v57))
                + (float)((float)(*((float *)&v100 + 1) * (float)v76) * v131);
            if ( v79 > 0.0 )
            {
              v135.mVec128.m128_i32[3] = 0;
              v80 = (float)((float)(v44->m_ra * v79) * v95) * v137.m_density;
              v81 = -(float)(v80 * v113);
              v82 = -(float)(v80 * kDG);
              v83 = v44->m_n;
              v135.mVec128.m128_f32[0] = (float)((float)((float)(v127 * v130) * v82) + (float)(v78 * v81)) * 0.33333334;
              v135.mVec128.m128_f32[1] = (float)((float)((float)(v131 * v127) * v82)
                                               + (float)((float)(*((float *)&v100 + 1) * (float)v76) * v81))
                                       * 0.33333334;
              v135.mVec128.m128_f32[2] = (float)((float)((float)(v57 * v127) * v82) + (float)(v77 * v81)) * 0.33333334;
              v84 = 3;
              do
              {
                ApplyClampedForce(*v83++, &v135, sdt);
                --v84;
              }
              while ( v84 );
              v5 = thisa;
            }
          }
        }
      }
      ++v93;
      --v111;
    }
    while ( v111 );
  }
  v85 = CProfileManager::CurrentNode;
  v86 = CProfileManager::CurrentNode->RecursionCounter-- == 1;
  if ( v86 && v85->TotalCalls )
    v85->TotalTime = (double)(btClock::getTimeMicroseconds((btClock *)v4) - v85->StartTime) * 0.001 + v85->TotalTime;
  if ( !v85->RecursionCounter )
    CProfileManager::CurrentNode = CProfileManager::CurrentNode->Parent;
}
