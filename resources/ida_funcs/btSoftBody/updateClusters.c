void __thiscall btSoftBody::updateClusters(btSoftBody *this, btSoftBody *thisa)
{
  CProfileNode *Sub_Node; // eax
  int RecursionCounter; // ecx
  btSoftBody *v4; // edx
  btClock *v5; // ecx
  bool v6; // cc
  btSoftBody::Cluster *v7; // esi
  int m_size; // ebx
  float *m128_f32; // ecx
  btSoftBody::Node **m_data; // edx
  int v11; // edi
  float v12; // xmm3_4
  float v13; // xmm7_4
  float v14; // xmm5_4
  float v15; // xmm1_4
  float v16; // xmm6_4
  float v17; // xmm2_4
  float v18; // xmm4_4
  float v19; // xmm2_4
  float v20; // xmm7_4
  float v21; // xmm0_4
  float v22; // xmm5_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm6_4
  float v26; // xmm4_4
  float v27; // xmm5_4
  float v28; // xmm5_4
  float v29; // xmm7_4
  float v30; // xmm6_4
  float v31; // xmm1_4
  float v32; // xmm7_4
  int v33; // edx
  float *v34; // ecx
  float v35; // xmm2_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm6_4
  float *v39; // ecx
  float v40; // xmm3_4
  float v41; // xmm7_4
  float v42; // xmm2_4
  float v43; // xmm4_4
  float v44; // xmm7_4
  float v45; // xmm2_4
  float *v46; // ecx
  float v47; // xmm6_4
  float v48; // xmm0_4
  float v49; // xmm1_4
  float *v50; // ecx
  float v51; // xmm3_4
  float v52; // xmm7_4
  float v53; // xmm2_4
  int v54; // ecx
  float v55; // xmm4_4
  float v56; // xmm7_4
  float *v57; // eax
  int v58; // edi
  float v59; // xmm2_4
  float v60; // xmm0_4
  float v61; // xmm1_4
  float v62; // xmm6_4
  float *v63; // eax
  float v64; // xmm3_4
  float v65; // xmm4_4
  float v66; // xmm0_4
  float v67; // xmm2_4
  float *v68; // eax
  float v69; // xmm2_4
  float v70; // xmm6_4
  float v71; // xmm0_4
  float v72; // xmm1_4
  float *v73; // eax
  float v74; // xmm3_4
  float v75; // xmm2_4
  float v76; // xmm4_4
  float v77; // xmm2_4
  float v78; // xmm0_4
  float v79; // xmm2_4
  float *v80; // eax
  float v81; // xmm0_4
  float v82; // xmm1_4
  float v83; // xmm6_4
  float *v84; // eax
  float v85; // xmm3_4
  float v86; // xmm2_4
  float v87; // xmm4_4
  float v88; // xmm2_4
  float v89; // xmm0_4
  float m_imass; // xmm4_4
  float v91; // xmm3_4
  const vostok::math::float4x4 *v92; // xmm6_4
  float v93; // xmm0_4
  float v94; // xmm2_4
  float v95; // xmm7_4
  float v96; // xmm3_4
  float v97; // xmm6_4
  float v98; // xmm3_4
  float v99; // xmm0_4
  float v100; // xmm4_4
  float v101; // xmm1_4
  float v102; // xmm2_4
  float v103; // xmm7_4
  int v104; // edx
  float m_matching; // xmm0_4
  int v106; // edi
  float *v107; // eax
  btVector3 *v108; // ecx
  float v109; // xmm6_4
  float v110; // xmm4_4
  float v111; // xmm3_4
  float v112; // xmm7_4
  float v113; // xmm0_4
  float v114; // xmm1_4
  float v115; // xmm2_4
  float v116; // xmm6_4
  float v117; // xmm2_4
  unsigned int v118; // xmm3_4
  unsigned int v119; // xmm4_4
  float v120; // xmm2_4
  btDbvt *v121; // ecx
  __m128 *p_mVec128; // eax
  float v123; // xmm4_4
  float v124; // xmm6_4
  float v125; // xmm2_4
  float v126; // xmm1_4
  int v127; // ebx
  btDbvtNode *m_root; // eax
  btDbvtNode *m_leaf; // edi
  bool v130; // cf
  float sdt; // xmm3_4
  float v132; // xmm2_4
  float v133; // xmm7_4
  float radmrg; // xmm0_4
  float v135; // xmm3_4
  float v136; // xmm4_4
  float v137; // xmm1_4
  float v138; // xmm6_4
  float v139; // xmm2_4
  bool v140; // zf
  int *p_RecursionCounter; // edi
  CProfileNode *v142; // esi
  btMatrix3x3 v143; // [esp+9D8h] [ebp-210h] BYREF
  float v144; // [esp+A14h] [ebp-1D4h]
  float v145; // [esp+A18h] [ebp-1D0h]
  float v146; // [esp+A1Ch] [ebp-1CCh]
  float v147; // [esp+A20h] [ebp-1C8h]
  float v148; // [esp+A24h] [ebp-1C4h]
  btVector3 v149; // [esp+A28h] [ebp-1C0h]
  unsigned __int64 v150; // [esp+A38h] [ebp-1B0h]
  unsigned __int64 v151; // [esp+A40h] [ebp-1A8h]
  float v152; // [esp+A54h] [ebp-194h]
  float v153; // [esp+A58h] [ebp-190h]
  float v154; // [esp+A5Ch] [ebp-18Ch]
  int v155; // [esp+A60h] [ebp-188h]
  unsigned int v156; // [esp+A64h] [ebp-184h]
  float v157; // [esp+A68h] [ebp-180h]
  float v158; // [esp+A7Ch] [ebp-16Ch]
  float v159; // [esp+A80h] [ebp-168h]
  float v160; // [esp+A84h] [ebp-164h]
  float v161; // [esp+A88h] [ebp-160h]
  float v162; // [esp+A8Ch] [ebp-15Ch]
  float v163; // [esp+A90h] [ebp-158h]
  float v164; // [esp+A94h] [ebp-154h]
  float v165; // [esp+A98h] [ebp-150h]
  float v166; // [esp+A9Ch] [ebp-14Ch]
  float v167; // [esp+AA0h] [ebp-148h]
  float v168; // [esp+AA4h] [ebp-144h]
  float v169; // [esp+AACh] [ebp-13Ch]
  float v170; // [esp+AB0h] [ebp-138h]
  float v171; // [esp+AB8h] [ebp-130h]
  float v172; // [esp+ABCh] [ebp-12Ch]
  float v173; // [esp+AC0h] [ebp-128h]
  float v174; // [esp+AC8h] [ebp-120h]
  unsigned __int64 v175; // [esp+AD8h] [ebp-110h]
  unsigned __int64 v176; // [esp+AE0h] [ebp-108h]
  unsigned __int64 v177; // [esp+AE8h] [ebp-100h]
  __int64 v178; // [esp+AF0h] [ebp-F8h]
  __int64 v179; // [esp+AF8h] [ebp-F0h]
  __int64 v180; // [esp+B00h] [ebp-E8h]
  __int64 v181; // [esp+B08h] [ebp-E0h]
  __int64 v182; // [esp+B10h] [ebp-D8h]
  __int64 v183; // [esp+B18h] [ebp-D0h]
  __int64 v184; // [esp+B20h] [ebp-C8h]
  __int64 v185; // [esp+B28h] [ebp-C0h]
  __int64 v186; // [esp+B30h] [ebp-B8h]
  unsigned __int64 v187; // [esp+B38h] [ebp-B0h]
  unsigned __int64 v188; // [esp+B40h] [ebp-A8h]
  __m128i v189; // [esp+B48h] [ebp-A0h] BYREF
  float v190; // [esp+B5Ch] [ebp-8Ch]
  float v191; // [esp+B60h] [ebp-88h]
  btMatrix3x3 q; // [esp+B68h] [ebp-80h] BYREF
  float v193; // [esp+BA0h] [ebp-48h]
  btVector3 result; // [esp+BA8h] [ebp-40h] BYREF
  btMatrix3x3 v195; // [esp+BB8h] [ebp-30h] BYREF

  Sub_Node = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "UpdateClusters" )
  {
    Sub_Node = CProfileNode::Get_Sub_Node((const char *)this);
    CProfileManager::CurrentNode = Sub_Node;
  }
  RecursionCounter = Sub_Node->RecursionCounter;
  ++Sub_Node->TotalCalls;
  Sub_Node->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
  {
    Sub_Node->StartTime = btClock::getTimeMicroseconds(0);
    Sub_Node = CProfileManager::CurrentNode;
  }
  v4 = thisa;
  v5 = 0;
  v6 = thisa->m_clusters.m_size <= 0;
  v155 = 0;
  if ( !v6 )
  {
    do
    {
      v7 = v4->m_clusters.m_data[(_DWORD)v5];
      m_size = v7->m_nodes.m_size;
      v156 = m_size;
      if ( m_size )
      {
        memset(&v189, 0, sizeof(v189));
        v143.m_el[2] = (btVector3)_mm_load_si128(&v189);
        v143.m_el[1] = v143.m_el[2];
        v143.m_el[0] = v143.m_el[2];
        v143.m_el[0].mVec128.m128_f32[0] = FLOAT_0_000099999997;
        v143.m_el[1].mVec128.m128_i32[1] = 961656599;
        v143.m_el[2].mVec128.m128_i32[2] = 966609233;
        v7->m_com = (btVector3)btSoftBody::clusterCom(&result, v7)->mVec128;
        if ( m_size > 0 )
        {
          m128_f32 = v7->m_framerefs.m_data->mVec128.m128_f32;
          m_data = v7->m_nodes.m_data;
          v163 = v7->m_com.mVec128.m128_f32[0];
          v159 = v7->m_com.mVec128.m128_f32[1];
          v162 = v7->m_com.mVec128.m128_f32[2];
          v11 = m_size;
          do
          {
            v12 = *m128_f32;
            v13 = m128_f32[2];
            v14 = m128_f32[1];
            v15 = (*m_data)->m_x.mVec128.m128_f32[1] - v159;
            v16 = (*m_data)->m_x.mVec128.m128_f32[0] - v163;
            v17 = (*m_data)->m_x.mVec128.m128_f32[2] - v162;
            v18 = *m128_f32 * v16;
            v193 = v16 * v13;
            v143.m_el[0].mVec128.m128_f32[0] = v143.m_el[0].mVec128.m128_f32[0] + v18;
            v143.m_el[0].mVec128.m128_f32[1] = v143.m_el[0].mVec128.m128_f32[1] + (float)(v16 * v14);
            v143.m_el[0].mVec128.m128_f32[2] = v143.m_el[0].mVec128.m128_f32[2] + (float)(v16 * v13);
            v143.m_el[1].mVec128.m128_f32[1] = v143.m_el[1].mVec128.m128_f32[1] + (float)(v15 * v14);
            v143.m_el[1].mVec128.m128_f32[2] = v143.m_el[1].mVec128.m128_f32[2] + (float)(v15 * v13);
            v143.m_el[2].mVec128.m128_f32[0] = v143.m_el[2].mVec128.m128_f32[0] + (float)(v12 * v17);
            ++m_data;
            m128_f32 += 4;
            --v11;
            v143.m_el[1].mVec128.m128_f32[0] = v143.m_el[1].mVec128.m128_f32[0] + (float)(v12 * v15);
            v143.m_el[2].mVec128.m128_f32[1] = v143.m_el[2].mVec128.m128_f32[1] + (float)(v17 * v14);
            v143.m_el[2].mVec128.m128_f32[2] = v143.m_el[2].mVec128.m128_f32[2] + (float)(v17 * v13);
          }
          while ( v11 );
        }
        PolarDecompose(&v143, &q, &v195);
        v7->m_framexform.m_origin.mVec128.m128_u64[0] = v7->m_com.mVec128.m128_u64[0];
        v7->m_framexform.m_origin.mVec128.m128_u64[1] = v7->m_com.mVec128.m128_u64[1];
        v7->m_framexform.m_basis = q;
        v19 = v7->m_framexform.m_basis.m_el[2].mVec128.m128_f32[2];
        v20 = v7->m_locii.m_el[0].mVec128.m128_f32[1];
        v21 = v7->m_framexform.m_basis.m_el[0].mVec128.m128_f32[0];
        v22 = v7->m_locii.m_el[2].mVec128.m128_f32[1];
        v23 = (float)((float)(v7->m_framexform.m_basis.m_el[2].mVec128.m128_f32[1]
                            * v7->m_locii.m_el[1].mVec128.m128_f32[2])
                    + (float)(v19 * v7->m_locii.m_el[2].mVec128.m128_f32[2]))
            + (float)(v7->m_framexform.m_basis.m_el[2].mVec128.m128_f32[0] * v7->m_locii.m_el[0].mVec128.m128_f32[2]);
        v24 = v7->m_framexform.m_basis.m_el[2].mVec128.m128_f32[1] * v7->m_locii.m_el[1].mVec128.m128_f32[1];
        v169 = v7->m_framexform.m_basis.m_el[1].mVec128.m128_f32[0];
        v25 = v7->m_locii.m_el[2].mVec128.m128_f32[0];
        v26 = (float)(v24 + (float)(v19 * v22)) + (float)(v7->m_framexform.m_basis.m_el[2].mVec128.m128_f32[0] * v20);
        v27 = v7->m_framexform.m_basis.m_el[2].mVec128.m128_f32[1] * v7->m_locii.m_el[1].mVec128.m128_f32[0];
        v170 = v7->m_framexform.m_basis.m_el[2].mVec128.m128_f32[0];
        v171 = v7->m_framexform.m_basis.m_el[0].mVec128.m128_f32[1];
        v28 = (float)(v27 + (float)(v19 * v25))
            + (float)(v7->m_framexform.m_basis.m_el[2].mVec128.m128_f32[0] * v7->m_locii.m_el[0].mVec128.m128_f32[0]);
        v29 = v7->m_framexform.m_basis.m_el[1].mVec128.m128_f32[1] * v7->m_locii.m_el[1].mVec128.m128_f32[2];
        v30 = v7->m_locii.m_el[2].mVec128.m128_f32[2];
        v172 = v7->m_framexform.m_basis.m_el[1].mVec128.m128_f32[1];
        v173 = v7->m_framexform.m_basis.m_el[2].mVec128.m128_f32[1];
        v174 = v7->m_framexform.m_basis.m_el[0].mVec128.m128_f32[2];
        v31 = v7->m_framexform.m_basis.m_el[1].mVec128.m128_f32[2];
        v144 = (float)(v29 + (float)(v31 * v30))
             + (float)(v7->m_locii.m_el[0].mVec128.m128_f32[2] * v7->m_framexform.m_basis.m_el[1].mVec128.m128_f32[0]);
        v32 = v7->m_framexform.m_basis.m_el[1].mVec128.m128_f32[1];
        v148 = (float)((float)(v32 * v7->m_locii.m_el[1].mVec128.m128_f32[1])
                     + (float)(v31 * v7->m_locii.m_el[2].mVec128.m128_f32[1]))
             + (float)(v7->m_locii.m_el[0].mVec128.m128_f32[1] * v7->m_framexform.m_basis.m_el[1].mVec128.m128_f32[0]);
        v152 = (float)((float)(v32 * v7->m_locii.m_el[1].mVec128.m128_f32[0])
                     + (float)(v31 * v7->m_locii.m_el[2].mVec128.m128_f32[0]))
             + (float)(v7->m_locii.m_el[0].mVec128.m128_f32[0] * v7->m_framexform.m_basis.m_el[1].mVec128.m128_f32[0]);
        v147 = v7->m_framexform.m_basis.m_el[0].mVec128.m128_f32[2];
        v146 = v7->m_framexform.m_basis.m_el[0].mVec128.m128_f32[1];
        v154 = v21;
        v145 = (float)((float)(v21 * v7->m_locii.m_el[0].mVec128.m128_f32[2])
                     + (float)(v146 * v7->m_locii.m_el[1].mVec128.m128_f32[2]))
             + (float)(v147 * v7->m_locii.m_el[2].mVec128.m128_f32[2]);
        v153 = (float)((float)(v147 * v7->m_locii.m_el[2].mVec128.m128_f32[1])
                     + (float)(v21 * v7->m_locii.m_el[0].mVec128.m128_f32[1]))
             + (float)(v146 * v7->m_locii.m_el[1].mVec128.m128_f32[1]);
        v164 = (float)((float)(v21 * v7->m_locii.m_el[0].mVec128.m128_f32[0])
                     + (float)(v146 * v7->m_locii.m_el[1].mVec128.m128_f32[0]))
             + (float)(v147 * v7->m_locii.m_el[2].mVec128.m128_f32[0]);
        v167 = (float)((float)(v173 * v26) + (float)(v19 * v23)) + (float)(v170 * v28);
        v158 = (float)((float)(v172 * v26) + (float)(v31 * v23)) + (float)(v169 * v28);
        v165 = (float)((float)(v21 * v28) + (float)(v171 * v26)) + (float)(v174 * v23);
        v160 = (float)((float)(v173 * v148) + (float)(v19 * v144)) + (float)(v170 * v152);
        v168 = (float)((float)(v172 * v148) + (float)(v31 * v144)) + (float)(v169 * v152);
        v161 = (float)((float)(v21 * v152) + (float)(v171 * v148)) + (float)(v174 * v144);
        v166 = (float)((float)(v19 * v145) + (float)(v173 * v153)) + (float)(v170 * v164);
        v143.m_el[0].mVec128.m128_f32[0] = (float)((float)(v21 * v164) + (float)(v174 * v145)) + (float)(v171 * v153);
        v143.m_el[0].mVec128.m128_f32[2] = v166;
        v143.m_el[1].mVec128.m128_f32[0] = v161;
        v143.m_el[1].mVec128.m128_f32[1] = v168;
        v143.m_el[1].mVec128.m128_f32[2] = v160;
        v143.m_el[2].mVec128.m128_u64[0] = __PAIR64__(LODWORD(v158), LODWORD(v165));
        v143.m_el[2].mVec128.m128_f32[2] = v167;
        v143.m_el[0].mVec128.m128_f32[1] = (float)((float)(v31 * v145) + (float)(v172 * v153)) + (float)(v169 * v164);
        v7->m_invwi.m_el[0].mVec128.m128_u64[0] = v143.m_el[0].mVec128.m128_u64[0];
        v143.m_el[0].mVec128.m128_i32[3] = 0;
        v7->m_invwi.m_el[0].mVec128.m128_u64[1] = v143.m_el[0].mVec128.m128_u32[2];
        v7->m_invwi.m_el[1].mVec128.m128_u64[0] = v143.m_el[1].mVec128.m128_u64[0];
        v143.m_el[1].mVec128.m128_i32[3] = 0;
        v7->m_invwi.m_el[1].mVec128.m128_u64[1] = v143.m_el[1].mVec128.m128_u32[2];
        v7->m_invwi.m_el[2].mVec128.m128_u64[0] = v143.m_el[2].mVec128.m128_u64[0];
        v143.m_el[2].mVec128.m128_i32[3] = 0;
        v7->m_invwi.m_el[2].mVec128.m128_u64[1] = v143.m_el[2].mVec128.m128_u32[2];
        v179 = 0;
        v7->m_lv.mVec128.m128_u64[0] = 0;
        v180 = 0;
        v7->m_lv.mVec128.m128_u64[1] = 0;
        v185 = 0;
        v7->m_av.mVec128.m128_u64[0] = 0;
        v186 = 0;
        v33 = 0;
        v7->m_av.mVec128.m128_u64[1] = 0;
        if ( m_size >= 4 )
        {
          do
          {
            v34 = (float *)v7->m_nodes.m_data[v33];
            v35 = v7->m_masses.m_data[v33];
            v36 = v34[13] * v35;
            v37 = v34[14] * v35;
            v38 = v35 * v34[12];
            v7->m_lv.mVec128.m128_f32[0] = v7->m_lv.mVec128.m128_f32[0] + v38;
            v7->m_lv.mVec128.m128_f32[1] = v36 + v7->m_lv.mVec128.m128_f32[1];
            v7->m_lv.mVec128.m128_f32[2] = v37 + v7->m_lv.mVec128.m128_f32[2];
            v39 = (float *)v7->m_nodes.m_data[v33];
            v40 = v39[5] - v7->m_com.mVec128.m128_f32[1];
            v157 = v39[4] - v7->m_com.mVec128.m128_f32[0];
            v41 = v39[6] - v7->m_com.mVec128.m128_f32[2];
            v42 = v41 * v38;
            v43 = (float)(v40 * v37) - (float)(v41 * v36);
            v44 = v157;
            v7->m_av.mVec128.m128_f32[0] = v43 + v7->m_av.mVec128.m128_f32[0];
            v7->m_av.mVec128.m128_f32[2] = (float)((float)(v36 * v44) - (float)(v40 * v38))
                                         + v7->m_av.mVec128.m128_f32[2];
            v7->m_av.mVec128.m128_f32[1] = (float)(v42 - (float)(v37 * v44)) + v7->m_av.mVec128.m128_f32[1];
            v45 = v7->m_masses.m_data[v33 + 1];
            v46 = (float *)v7->m_nodes.m_data[v33 + 1];
            v47 = v45 * v46[12];
            v48 = v46[13] * v45;
            v49 = v46[14] * v45;
            v7->m_lv.mVec128.m128_f32[0] = v7->m_lv.mVec128.m128_f32[0] + v47;
            v7->m_lv.mVec128.m128_f32[1] = v48 + v7->m_lv.mVec128.m128_f32[1];
            v7->m_lv.mVec128.m128_f32[2] = v49 + v7->m_lv.mVec128.m128_f32[2];
            v50 = (float *)v7->m_nodes.m_data[v33 + 1];
            v51 = v50[5] - v7->m_com.mVec128.m128_f32[1];
            v157 = v50[4] - v7->m_com.mVec128.m128_f32[0];
            v52 = v50[6] - v7->m_com.mVec128.m128_f32[2];
            v53 = v52 * v47;
            v54 = 4 * v33 + 12;
            v55 = (float)((float)(v51 * v49) - (float)(v52 * v48)) + v7->m_av.mVec128.m128_f32[0];
            v56 = v157;
            v7->m_av.mVec128.m128_f32[0] = v55;
            v7->m_av.mVec128.m128_f32[1] = (float)(v53 - (float)(v49 * v56)) + v7->m_av.mVec128.m128_f32[1];
            v7->m_av.mVec128.m128_f32[2] = (float)((float)(v48 * v56) - (float)(v51 * v47))
                                         + v7->m_av.mVec128.m128_f32[2];
            v57 = *(float **)((char *)v7->m_nodes.m_data + v54 - 4);
            v58 = 4 * v33 + 8;
            v59 = *(float *)((char *)v7->m_masses.m_data + v58);
            v60 = v57[13] * v59;
            v61 = v57[14] * v59;
            v62 = v59 * v57[12];
            v7->m_lv.mVec128.m128_f32[0] = v7->m_lv.mVec128.m128_f32[0] + v62;
            v7->m_lv.mVec128.m128_f32[1] = v60 + v7->m_lv.mVec128.m128_f32[1];
            v7->m_lv.mVec128.m128_f32[2] = v61 + v7->m_lv.mVec128.m128_f32[2];
            v63 = *(float **)((char *)v7->m_nodes.m_data + v58);
            v64 = v63[5] - v7->m_com.mVec128.m128_f32[1];
            v157 = v63[4] - v7->m_com.mVec128.m128_f32[0];
            v65 = (float)((float)(v64 * v61) - (float)((float)(v63[6] - v7->m_com.mVec128.m128_f32[2]) * v60))
                + v7->m_av.mVec128.m128_f32[0];
            v66 = v60 * v157;
            v67 = (float)((float)((float)(v63[6] - v7->m_com.mVec128.m128_f32[2]) * v62) - (float)(v61 * v157))
                + v7->m_av.mVec128.m128_f32[1];
            v7->m_av.mVec128.m128_f32[0] = v65;
            v7->m_av.mVec128.m128_f32[1] = v67;
            v7->m_av.mVec128.m128_f32[2] = (float)(v66 - (float)(v64 * v62)) + v7->m_av.mVec128.m128_f32[2];
            v68 = *(float **)((char *)v7->m_nodes.m_data + v54);
            v69 = *(float *)((char *)v7->m_masses.m_data + v54);
            v70 = v69 * v68[12];
            v71 = v68[13] * v69;
            v72 = v68[14] * v69;
            v7->m_lv.mVec128.m128_f32[0] = v7->m_lv.mVec128.m128_f32[0] + v70;
            m_size = v156;
            v7->m_lv.mVec128.m128_f32[1] = v71 + v7->m_lv.mVec128.m128_f32[1];
            v7->m_lv.mVec128.m128_f32[2] = v72 + v7->m_lv.mVec128.m128_f32[2];
            v73 = *(float **)((char *)v7->m_nodes.m_data + v54);
            v74 = v73[5] - v7->m_com.mVec128.m128_f32[1];
            v157 = v73[4] - v7->m_com.mVec128.m128_f32[0];
            v75 = v73[6] - v7->m_com.mVec128.m128_f32[2];
            v76 = (float)((float)(v74 * v72) - (float)(v75 * v71)) + v7->m_av.mVec128.m128_f32[0];
            v33 += 4;
            v77 = (float)((float)(v75 * v70) - (float)(v72 * v157)) + v7->m_av.mVec128.m128_f32[1];
            v78 = (float)((float)(v71 * v157) - (float)(v74 * v70)) + v7->m_av.mVec128.m128_f32[2];
            v7->m_av.mVec128.m128_f32[0] = v76;
            v7->m_av.mVec128.m128_f32[1] = v77;
            v7->m_av.mVec128.m128_f32[2] = v78;
          }
          while ( v33 < m_size - 3 );
        }
        for ( ; v33 < m_size; v7->m_av.mVec128.m128_f32[2] = v89 )
        {
          v79 = v7->m_masses.m_data[v33];
          v80 = (float *)v7->m_nodes.m_data[v33];
          v81 = v80[13] * v79;
          v82 = v80[14] * v79;
          v83 = v79 * v80[12];
          v7->m_lv.mVec128.m128_f32[0] = v7->m_lv.mVec128.m128_f32[0] + v83;
          v7->m_lv.mVec128.m128_f32[1] = v81 + v7->m_lv.mVec128.m128_f32[1];
          v7->m_lv.mVec128.m128_f32[2] = v82 + v7->m_lv.mVec128.m128_f32[2];
          v84 = (float *)v7->m_nodes.m_data[v33];
          v85 = v84[5] - v7->m_com.mVec128.m128_f32[1];
          v157 = v84[4] - v7->m_com.mVec128.m128_f32[0];
          v86 = v84[6] - v7->m_com.mVec128.m128_f32[2];
          v87 = (float)((float)(v85 * v82) - (float)(v86 * v81)) + v7->m_av.mVec128.m128_f32[0];
          ++v33;
          v88 = (float)((float)(v86 * v83) - (float)(v82 * v157)) + v7->m_av.mVec128.m128_f32[1];
          v89 = (float)((float)(v81 * v157) - (float)(v85 * v83)) + v7->m_av.mVec128.m128_f32[2];
          v7->m_av.mVec128.m128_f32[0] = v87;
          v7->m_av.mVec128.m128_f32[1] = v88;
        }
        m_imass = v7->m_imass;
        v91 = v7->m_lv.mVec128.m128_f32[2];
        v92 = clear_value;
        v93 = *(float *)&clear_value - v7->m_ldamping;
        v94 = (float)(v7->m_lv.mVec128.m128_f32[1] * m_imass) * v93;
        *(float *)&v175 = (float)(m_imass * v7->m_lv.mVec128.m128_f32[0]) * v93;
        *((float *)&v175 + 1) = v94;
        v7->m_lv.mVec128.m128_u64[0] = v175;
        *(float *)&v176 = (float)(v91 * m_imass) * v93;
        HIDWORD(v176) = 0;
        v7->m_lv.mVec128.m128_u64[1] = v176;
        v95 = v7->m_av.mVec128.m128_f32[1];
        v96 = *(float *)&v92;
        v97 = v7->m_av.mVec128.m128_f32[2];
        v98 = v96 - v7->m_adamping;
        v99 = (float)((float)(v7->m_invwi.m_el[0].mVec128.m128_f32[1] * v95)
                    + (float)(v7->m_invwi.m_el[0].mVec128.m128_f32[2] * v97))
            + (float)(v7->m_av.mVec128.m128_f32[0] * v7->m_invwi.m_el[0].mVec128.m128_f32[0]);
        v100 = v7->m_av.mVec128.m128_f32[0] * v7->m_invwi.m_el[2].mVec128.m128_f32[0];
        v101 = (float)((float)(v7->m_invwi.m_el[1].mVec128.m128_f32[1] * v95)
                     + (float)(v7->m_invwi.m_el[1].mVec128.m128_f32[2] * v97))
             + (float)(v7->m_av.mVec128.m128_f32[0] * v7->m_invwi.m_el[1].mVec128.m128_f32[0]);
        v102 = v7->m_invwi.m_el[2].mVec128.m128_f32[1] * v95;
        v103 = v7->m_invwi.m_el[2].mVec128.m128_f32[2];
        *(float *)&v187 = v99 * v98;
        *((float *)&v187 + 1) = v101 * v98;
        v7->m_av.mVec128.m128_u64[0] = v187;
        v188 = COERCE_UNSIGNED_INT((float)((float)(v102 + (float)(v103 * v97)) + v100) * v98);
        v7->m_av.mVec128.m128_u64[1] = v188;
        v181 = 0;
        v182 = 0;
        v7->m_vimpulses[1].mVec128.m128_u64[0] = 0;
        v7->m_vimpulses[0].mVec128.m128_u64[0] = 0;
        v183 = 0;
        v7->m_vimpulses[1].mVec128.m128_u64[1] = 0;
        v7->m_vimpulses[0].mVec128.m128_u64[1] = 0;
        v184 = 0;
        v7->m_dimpulses[1].mVec128.m128_u64[0] = 0;
        v7->m_dimpulses[0].mVec128.m128_u64[0] = 0;
        v7->m_dimpulses[1].mVec128.m128_u64[1] = 0;
        v7->m_dimpulses[0].mVec128.m128_u64[1] = 0;
        v104 = 0;
        m_matching = v7->m_matching;
        v7->m_nvimpulses = 0;
        v7->m_ndimpulses = 0;
        if ( m_matching > 0.0 && v7->m_nodes.m_size > 0 )
        {
          HIDWORD(v178) = 0;
          v106 = 0;
          do
          {
            v107 = (float *)v7->m_nodes.m_data[v104];
            v108 = v7->m_framerefs.m_data;
            v109 = v108[v106].mVec128.m128_f32[0];
            v110 = v108[v106].mVec128.m128_f32[1];
            v111 = v108[v106].mVec128.m128_f32[2];
            v112 = v7->m_matching;
            v113 = (float)((float)((float)(v109 * v7->m_framexform.m_basis.m_el[0].mVec128.m128_f32[0])
                                 + (float)(v110 * v7->m_framexform.m_basis.m_el[0].mVec128.m128_f32[1]))
                         + (float)(v111 * v7->m_framexform.m_basis.m_el[0].mVec128.m128_f32[2]))
                 + v7->m_framexform.m_origin.mVec128.m128_f32[0];
            v114 = (float)((float)(v110 * v7->m_framexform.m_basis.m_el[1].mVec128.m128_f32[1])
                         + (float)(v111 * v7->m_framexform.m_basis.m_el[1].mVec128.m128_f32[2]))
                 + (float)(v7->m_framexform.m_basis.m_el[1].mVec128.m128_f32[0] * v109);
            v115 = v7->m_framexform.m_basis.m_el[2].mVec128.m128_f32[0] * v109;
            v116 = v107[6];
            v117 = (float)(v115 + (float)(v110 * v7->m_framexform.m_basis.m_el[2].mVec128.m128_f32[1]))
                 + (float)(v111 * v7->m_framexform.m_basis.m_el[2].mVec128.m128_f32[2]);
            *(float *)&v118 = v107[4] + (float)((float)(v113 - v107[4]) * v112);
            *(float *)&v119 = v107[5]
                            + (float)((float)((float)(v114 + v7->m_framexform.m_origin.mVec128.m128_f32[1]) - v107[5])
                                    * v112);
            v120 = (float)((float)(v117 + v7->m_framexform.m_origin.mVec128.m128_f32[2]) - v116) * v112;
            v177 = __PAIR64__(v119, v118);
            *((_QWORD *)v107 + 2) = __PAIR64__(v119, v118);
            *(float *)&v178 = v116 + v120;
            ++v104;
            *((_QWORD *)v107 + 3) = v178;
            ++v106;
          }
          while ( v104 < v7->m_nodes.m_size );
        }
        if ( v7->m_collide )
        {
          v121 = (btDbvt *)v7->m_nodes.m_data;
          p_mVec128 = &v121->m_root->volume.mi.mVec128;
          v150 = v121->m_root->volume.mx.mVec128.m128_u64[0];
          v123 = *(float *)&v150;
          v151 = p_mVec128[1].m128_u64[1];
          v149.mVec128 = p_mVec128[1];
          v124 = v149.mVec128.m128_f32[0];
          if ( m_size > 1 )
          {
            v125 = *((float *)&v151 + 1);
            v126 = v149.mVec128.m128_f32[3];
            v121 = (btDbvt *)((char *)v121 + 4);
            v127 = m_size - 1;
            do
            {
              m_root = v121->m_root;
              if ( v123 > v121->m_root->volume.mx.mVec128.m128_f32[0] )
                v123 = v121->m_root->volume.mx.mVec128.m128_f32[0];
              if ( *((float *)&v150 + 1) > m_root->volume.mx.mVec128.m128_f32[1] )
                HIDWORD(v150) = m_root->volume.mx.mVec128.m128_i32[1];
              if ( *(float *)&v151 > m_root->volume.mx.mVec128.m128_f32[2] )
                LODWORD(v151) = m_root->volume.mx.mVec128.m128_i32[2];
              if ( v125 > m_root->volume.mx.mVec128.m128_f32[3] )
                v125 = m_root->volume.mx.mVec128.m128_f32[3];
              if ( m_root->volume.mx.mVec128.m128_f32[0] > v124 )
                v124 = m_root->volume.mx.mVec128.m128_f32[0];
              if ( m_root->volume.mx.mVec128.m128_f32[1] > v149.mVec128.m128_f32[1] )
                v149.mVec128.m128_i32[1] = m_root->volume.mx.mVec128.m128_i32[1];
              if ( m_root->volume.mx.mVec128.m128_f32[2] > v149.mVec128.m128_f32[2] )
                v149.mVec128.m128_i32[2] = m_root->volume.mx.mVec128.m128_i32[2];
              if ( m_root->volume.mx.mVec128.m128_f32[3] > v126 )
                v126 = m_root->volume.mx.mVec128.m128_f32[3];
              v121 = (btDbvt *)((char *)v121 + 4);
              --v127;
            }
            while ( v127 );
            v149.mVec128.m128_f32[3] = v126;
            v149.mVec128.m128_f32[0] = v124;
            *((float *)&v151 + 1) = v125;
            *(float *)&v150 = v123;
          }
          m_leaf = v7->m_leaf;
          v143.m_el[0].mVec128.m128_u64[0] = v150;
          v143.m_el[0].mVec128.m128_u64[1] = v151;
          v143.m_el[1] = (btVector3)v149.mVec128;
          if ( m_leaf )
          {
            v130 = v123 < m_leaf->volume.mi.mVec128.m128_f32[0];
            sdt = thisa->m_sst.sdt;
            v132 = v7->m_lv.mVec128.m128_f32[2] * sdt;
            v133 = (float)(sdt * v7->m_lv.mVec128.m128_f32[0]) * 3.0;
            radmrg = thisa->m_sst.radmrg;
            v190 = (float)(v7->m_lv.mVec128.m128_f32[1] * sdt) * 3.0;
            v191 = v132 * 3.0;
            if ( v130
              || *((float *)&v150 + 1) < m_leaf->volume.mi.mVec128.m128_f32[1]
              || *(float *)&v151 < m_leaf->volume.mi.mVec128.m128_f32[2]
              || m_leaf->volume.mx.mVec128.m128_f32[0] < v124
              || m_leaf->volume.mx.mVec128.m128_f32[1] < v149.mVec128.m128_f32[1]
              || m_leaf->volume.mx.mVec128.m128_f32[2] < v149.mVec128.m128_f32[2] )
            {
              v143.m_el[0].mVec128.m128_f32[0] = v123 - radmrg;
              v135 = radmrg + v124;
              v136 = v143.m_el[0].mVec128.m128_f32[1] - radmrg;
              v137 = v143.m_el[0].mVec128.m128_f32[2] - radmrg;
              v138 = v143.m_el[1].mVec128.m128_f32[1] + radmrg;
              v139 = v143.m_el[1].mVec128.m128_f32[2] + radmrg;
              v143.m_el[0].mVec128.m128_f32[1] = v143.m_el[0].mVec128.m128_f32[1] - radmrg;
              v143.m_el[0].mVec128.m128_f32[2] = v143.m_el[0].mVec128.m128_f32[2] - radmrg;
              v143.m_el[1].mVec128.m128_f32[0] = v135;
              v143.m_el[1].mVec128.m128_f32[1] = v143.m_el[1].mVec128.m128_f32[1] + radmrg;
              v143.m_el[1].mVec128.m128_f32[2] = v143.m_el[1].mVec128.m128_f32[2] + radmrg;
              if ( v133 <= 0.0 )
                v143.m_el[0].mVec128.m128_f32[0] = v143.m_el[0].mVec128.m128_f32[0] + v133;
              else
                v143.m_el[1].mVec128.m128_f32[0] = v135 + v133;
              if ( v190 <= 0.0 )
                v143.m_el[0].mVec128.m128_f32[1] = v136 + v190;
              else
                v143.m_el[1].mVec128.m128_f32[1] = v138 + v190;
              if ( v191 <= 0.0 )
                v143.m_el[0].mVec128.m128_f32[2] = v137 + v191;
              else
                v143.m_el[1].mVec128.m128_f32[2] = v139 + v191;
              btDbvt::update(&thisa->m_cdbvt, m_leaf, (btDbvtAabbMm *)&v143);
            }
          }
          else
          {
            v7->m_leaf = btDbvt::insert(v121, (const btDbvtAabbMm *)&v143, v7);
          }
        }
      }
      v4 = thisa;
      v5 = (btClock *)(v155 + 1);
      v6 = ++v155 < thisa->m_clusters.m_size;
    }
    while ( v6 );
    Sub_Node = CProfileManager::CurrentNode;
  }
  v140 = Sub_Node->RecursionCounter-- == 1;
  p_RecursionCounter = &Sub_Node->RecursionCounter;
  v142 = Sub_Node;
  if ( v140 && Sub_Node->TotalCalls )
  {
    v156 = btClock::getTimeMicroseconds(v5) - Sub_Node->StartTime;
    Sub_Node = CProfileManager::CurrentNode;
    v142->TotalTime = (double)v156 * 0.001 + v142->TotalTime;
  }
  if ( !*p_RecursionCounter )
    CProfileManager::CurrentNode = Sub_Node->Parent;
}
