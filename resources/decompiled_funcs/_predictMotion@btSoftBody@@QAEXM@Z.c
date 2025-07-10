void __thiscall btSoftBody::predictMotion(btSoftBody *this, btSoftBody *dt, float dta)
{
  btDbvt *v3; // ecx
  btSoftBody *v4; // ecx
  float v5; // xmm0_4
  const vostok::math::float4x4 *v6; // xmm1_4
  btCollisionShape *m_collisionShape; // ecx
  double v8; // st7
  float *m128_f32; // eax
  float sdt; // xmm0_4
  btSoftBody *v11; // ecx
  int v12; // ecx
  int m_size; // edi
  int v14; // eax
  unsigned int v15; // esi
  btSoftBody::Node *m_data; // eax
  float m_im; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  float *v21; // eax
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  btSoftBody::Node *v29; // edx
  int v30; // eax
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm4_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm3_4
  btSoftBody::Node *v39; // eax
  float *v40; // edx
  float v41; // xmm0_4
  float v42; // xmm2_4
  float v43; // xmm3_4
  float v44; // xmm4_4
  int v45; // eax
  float v46; // xmm2_4
  float v47; // xmm3_4
  float v48; // xmm4_4
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm2_4
  float v52; // xmm3_4
  btSoftBody::Node *v53; // eax
  __int64 v54; // xmm0_8
  btSoftBody::Node *v55; // eax
  float v56; // xmm2_4
  float v57; // xmm3_4
  float v58; // xmm4_4
  float v59; // xmm1_4
  float v60; // xmm2_4
  float v61; // xmm3_4
  int v62; // edi
  btSoftBody::Node *v63; // eax
  __int64 v64; // xmm0_8
  btSoftBody::Node *v65; // eax
  float v66; // xmm2_4
  float v67; // xmm3_4
  float v68; // xmm4_4
  float v69; // xmm1_4
  float v70; // xmm2_4
  float v71; // xmm3_4
  btSoftBody *v72; // ecx
  btSoftBody *v73; // ecx
  int v74; // edi
  int v75; // esi
  float radmrg; // xmm0_4
  double updmrg; // st7
  btSoftBody::Node *v78; // eax
  float v79; // xmm1_4
  btSoftBody::Node *v80; // eax
  float v81; // xmm2_4
  float v82; // xmm3_4
  int v83; // xmm4_4
  float velmrg; // xmm0_4
  btDbvtNode *m_leaf; // ecx
  float v86; // xmm1_4
  bool v87; // cc
  _DWORD *v88; // edi
  btVector3 *v89; // eax
  btVector3 *v90; // ecx
  btVector3 *v91; // edx
  float v92; // xmm3_4
  float v93; // xmm1_4
  float v94; // xmm2_4
  float v95; // xmm0_4
  btDbvtNode *v96; // edi
  float v97; // xmm1_4
  bool v98; // cf
  float v99; // xmm4_4
  float v100; // xmm5_4
  float v101; // xmm6_4
  float v102; // xmm7_4
  float v103; // xmm3_4
  float v104; // xmm0_4
  float v105; // xmm3_4
  float v106; // xmm2_4
  float v107; // xmm0_4
  float v108; // xmm5_4
  float v109; // xmm7_4
  float v110; // xmm4_4
  float v111; // xmm6_4
  float v112; // xmm1_4
  int v113; // eax
  float v114; // xmm6_4
  float v115; // xmm5_4
  int v116; // edx
  int v117; // esi
  unsigned int v118; // edi
  btSoftBody::Node *v119; // eax
  float v120; // xmm0_4
  float *v121; // eax
  btVector3 *v122; // ecx
  float v123; // xmm2_4
  float v124; // xmm7_4
  float v125; // xmm3_4
  float v126; // xmm0_4
  float v127; // xmm1_4
  float v128; // xmm2_4
  float v129; // xmm3_4
  float v130; // xmm0_4
  float v131; // xmm1_4
  float kMT; // xmm2_4
  float v133; // xmm7_4
  float v134; // xmm3_4
  btSoftBody::Node *v135; // ecx
  float *v136; // eax
  btVector3 *v137; // ecx
  float v138; // xmm7_4
  float v139; // xmm2_4
  float v140; // xmm3_4
  float v141; // xmm0_4
  float v142; // xmm1_4
  float v143; // xmm2_4
  float v144; // xmm3_4
  float v145; // xmm0_4
  float v146; // xmm1_4
  float v147; // xmm2_4
  float v148; // xmm7_4
  float v149; // xmm3_4
  btSoftBody::Node *v150; // eax
  float v151; // xmm0_4
  float *v152; // eax
  btVector3 *v153; // ecx
  float v154; // xmm7_4
  float v155; // xmm2_4
  float v156; // xmm3_4
  float v157; // xmm0_4
  float v158; // xmm1_4
  float v159; // xmm2_4
  float v160; // xmm3_4
  float v161; // xmm0_4
  float v162; // xmm1_4
  float v163; // xmm2_4
  float v164; // xmm7_4
  float v165; // xmm3_4
  btSoftBody::Node *v166; // eax
  float v167; // xmm0_4
  float *v168; // eax
  btVector3 *v169; // ecx
  float v170; // xmm7_4
  float v171; // xmm2_4
  float v172; // xmm3_4
  float v173; // xmm0_4
  float v174; // xmm1_4
  float v175; // xmm2_4
  float v176; // xmm3_4
  float v177; // xmm0_4
  float v178; // xmm1_4
  float v179; // xmm2_4
  float v180; // xmm7_4
  float v181; // xmm3_4
  int v182; // edx
  int v183; // esi
  int v184; // edi
  btSoftBody::Node *v185; // eax
  float v186; // xmm0_4
  float *v187; // eax
  btVector3 *v188; // ecx
  float v189; // xmm3_4
  float v190; // xmm2_4
  float v191; // xmm7_4
  float v192; // xmm0_4
  float v193; // xmm1_4
  float v194; // xmm2_4
  float v195; // xmm3_4
  float v196; // xmm0_4
  float v197; // xmm1_4
  float v198; // xmm2_4
  float v199; // xmm7_4
  float v200; // xmm3_4
  int v201; // ecx
  btSoftBody::RContact *v202; // eax
  int v203; // esi
  int v204; // eax
  int v205; // esi
  btSoftBody::SContact *v206; // eax
  int v207; // edx
  btDbvtAabbMm *v208; // eax
  btDbvt *v209; // ecx
  btDbvt *v210; // ecx
  float margin; // [esp+774h] [ebp-154h]
  btVector3 *ppts[4]; // [esp+788h] [ebp-140h] BYREF
  int v213; // [esp+7A0h] [ebp-128h]
  int v214; // [esp+7A4h] [ebp-124h]
  __m128i v215; // [esp+7A8h] [ebp-120h] BYREF
  float v216; // [esp+7C4h] [ebp-104h]
  btDbvtAabbMm v217[2]; // [esp+7C8h] [ebp-100h] BYREF
  btDbvtAabbMm volume; // [esp+808h] [ebp-C0h] BYREF
  btVector3 velocity; // [esp+828h] [ebp-A0h] BYREF
  btSoftBody::RContact v220; // [esp+838h] [ebp-90h] BYREF

  if ( dt->m_bUpdateRtCst )
  {
    dt->m_bUpdateRtCst = 0;
    btSoftBody::updateConstants(this, dt);
    btDbvt::clear(v3);
    if ( (dt->m_cfg.collisions & 0x10) != 0 )
      btSoftBody::initializeFaceTree(v4, dt);
  }
  v5 = dt->m_cfg.timescale * dta;
  v6 = clear_value;
  m_collisionShape = dt->m_collisionShape;
  dt->m_sst.sdt = v5;
  dt->m_sst.isdt = *(float *)&v6 / v5;
  dt->m_sst.velmrg = v5 * 3.0;
  v8 = ((double (__thiscall *)(btCollisionShape *))m_collisionShape->getMargin)(m_collisionShape);
  dt->m_sst.radmrg = v8;
  m128_f32 = dt->m_worldInfo->m_gravity.mVec128.m128_f32;
  dt->m_sst.updmrg = v8 * 0.25;
  sdt = dt->m_sst.sdt;
  *(float *)v215.m128i_i32 = sdt * *m128_f32;
  *(float *)&v215.m128i_i32[1] = m128_f32[1] * sdt;
  v215.m128i_i64[1] = COERCE_UNSIGNED_INT(m128_f32[2] * sdt);
  btSoftBody::addVelocity((btSoftBody *)&v215, (const btVector3 *)dt);
  btSoftBody::applyForces(v11, dt);
  m_size = dt->m_nodes.m_size;
  v14 = 0;
  if ( m_size >= 4 )
  {
    v12 = 0;
    v15 = ((unsigned int)(m_size - 4) >> 2) + 1;
    memset(ppts, 0, sizeof(ppts));
    v213 = 4 * v15;
    do
    {
      m_data = dt->m_nodes.m_data;
      m_data[v12].m_q.mVec128.m128_u64[0] = m_data[v12].m_x.mVec128.m128_u64[0];
      m_data[v12].m_q.mVec128.m128_u64[1] = m_data[v12].m_x.mVec128.m128_u64[1];
      m_im = m_data[v12].m_im;
      v18 = m_data[v12].m_f.mVec128.m128_f32[0];
      v19 = m_data[v12].m_f.mVec128.m128_f32[1];
      v20 = m_data[v12].m_f.mVec128.m128_f32[2];
      v21 = (float *)&m_data[v12];
      v22 = v18 * m_im;
      v23 = v19 * m_im;
      v24 = v20 * m_im;
      v25 = dt->m_sst.sdt;
      v21[12] = (float)(v25 * v22) + v21[12];
      v21[13] = v21[13] + (float)(v25 * v23);
      v21[14] = v21[14] + (float)(v25 * v24);
      v26 = dt->m_sst.sdt;
      v27 = v21[13];
      v28 = v21[14];
      v21[4] = (float)(v21[12] * v26) + v21[4];
      v21[5] = v21[5] + (float)(v27 * v26);
      v21[6] = v21[6] + (float)(v28 * v26);
      *((_QWORD *)v21 + 8) = 0;
      *((_QWORD *)v21 + 9) = 0;
      v29 = dt->m_nodes.m_data;
      v30 = (int)&v29[v12 + 1];
      *(_QWORD *)(v30 + 32) = v29[v12 + 1].m_x.mVec128.m128_u64[0];
      *(_QWORD *)(v30 + 40) = v29[v12 + 1].m_x.mVec128.m128_u64[1];
      v31 = v29[v12 + 1].m_im;
      v32 = v29[v12 + 1].m_f.mVec128.m128_f32[0] * v31;
      v33 = v29[v12 + 1].m_f.mVec128.m128_f32[1] * v31;
      v34 = v29[v12 + 1].m_f.mVec128.m128_f32[2] * v31;
      v35 = dt->m_sst.sdt;
      *(float *)(v30 + 48) = (float)(v35 * v32) + v29[v12 + 1].m_v.mVec128.m128_f32[0];
      *(float *)(v30 + 52) = v29[v12 + 1].m_v.mVec128.m128_f32[1] + (float)(v35 * v33);
      *(float *)(v30 + 56) = v29[v12 + 1].m_v.mVec128.m128_f32[2] + (float)(v35 * v34);
      v36 = dt->m_sst.sdt;
      v37 = v29[v12 + 1].m_v.mVec128.m128_f32[1];
      v38 = v29[v12 + 1].m_v.mVec128.m128_f32[2];
      *(float *)(v30 + 16) = (float)(v29[v12 + 1].m_v.mVec128.m128_f32[0] * v36) + v29[v12 + 1].m_x.mVec128.m128_f32[0];
      *(float *)(v30 + 20) = v29[v12 + 1].m_x.mVec128.m128_f32[1] + (float)(v37 * v36);
      *(float *)(v30 + 24) = v29[v12 + 1].m_x.mVec128.m128_f32[2] + (float)(v38 * v36);
      *(_QWORD *)(v30 + 64) = 0;
      *(_QWORD *)(v30 + 72) = 0;
      v39 = dt->m_nodes.m_data;
      v40 = (float *)(v12 * 112 + 336);
      *(_QWORD *)((char *)v39 + (_DWORD)v40 - 80) = v39[v12 + 2].m_x.mVec128.m128_u64[0];
      *(_QWORD *)((char *)v39 + (_DWORD)v40 - 72) = v39[v12 + 2].m_x.mVec128.m128_u64[1];
      v41 = v39[v12 + 2].m_im;
      v42 = v39[v12 + 2].m_f.mVec128.m128_f32[0];
      v43 = v39[v12 + 2].m_f.mVec128.m128_f32[1];
      v44 = v39[v12 + 2].m_f.mVec128.m128_f32[2];
      v45 = (int)&v39[v12 + 2];
      v46 = v42 * v41;
      v47 = v43 * v41;
      v48 = v44 * v41;
      v49 = dt->m_sst.sdt;
      *(float *)(v45 + 48) = (float)(v49 * v46) + *(float *)(v45 + 48);
      *(float *)(v45 + 52) = *(float *)(v45 + 52) + (float)(v49 * v47);
      *(float *)(v45 + 56) = *(float *)(v45 + 56) + (float)(v49 * v48);
      v50 = dt->m_sst.sdt;
      v51 = *(float *)(v45 + 52);
      v52 = *(float *)(v45 + 56);
      *(float *)(v45 + 16) = (float)(*(float *)(v45 + 48) * v50) + *(float *)(v45 + 16);
      *(float *)(v45 + 20) = *(float *)(v45 + 20) + (float)(v51 * v50);
      *(float *)(v45 + 24) = *(float *)(v45 + 24) + (float)(v52 * v50);
      *(_QWORD *)(v45 + 64) = 0;
      *(_QWORD *)(v45 + 72) = 0;
      v53 = dt->m_nodes.m_data;
      v54 = v53[v12 + 3].m_x.mVec128.m128_i64[0];
      v55 = &v53[v12 + 3];
      v55->m_q.mVec128.m128_u64[0] = v54;
      v55->m_q.mVec128.m128_u64[1] = v55->m_x.mVec128.m128_u64[1];
      *(float *)&v54 = v55->m_im;
      v56 = v55->m_f.mVec128.m128_f32[0] * *(float *)&v54;
      v57 = v55->m_f.mVec128.m128_f32[1] * *(float *)&v54;
      v58 = v55->m_f.mVec128.m128_f32[2] * *(float *)&v54;
      *(float *)&v54 = dt->m_sst.sdt;
      v55->m_v.mVec128.m128_f32[0] = (float)(*(float *)&v54 * v56) + v55->m_v.mVec128.m128_f32[0];
      v55->m_v.mVec128.m128_f32[1] = v55->m_v.mVec128.m128_f32[1] + (float)(*(float *)&v54 * v57);
      v55->m_v.mVec128.m128_f32[2] = v55->m_v.mVec128.m128_f32[2] + (float)(*(float *)&v54 * v58);
      v59 = dt->m_sst.sdt;
      v60 = v55->m_v.mVec128.m128_f32[1];
      v61 = v55->m_v.mVec128.m128_f32[2];
      v55->m_x.mVec128.m128_f32[0] = (float)(v55->m_v.mVec128.m128_f32[0] * v59) + v55->m_x.mVec128.m128_f32[0];
      v55->m_x.mVec128.m128_f32[1] = v55->m_x.mVec128.m128_f32[1] + (float)(v60 * v59);
      v55->m_x.mVec128.m128_f32[2] = v55->m_x.mVec128.m128_f32[2] + (float)(v61 * v59);
      v12 += 4;
      --v15;
      v55->m_f.mVec128.m128_u64[0] = 0;
      v55->m_f.mVec128.m128_u64[1] = 0;
    }
    while ( v15 );
    v14 = v213;
  }
  if ( v14 < m_size )
  {
    memset(ppts, 0, sizeof(ppts));
    v12 = v14;
    v62 = m_size - v14;
    do
    {
      v63 = dt->m_nodes.m_data;
      v64 = v63[v12].m_x.mVec128.m128_i64[0];
      v65 = &v63[v12];
      v65->m_q.mVec128.m128_u64[0] = v64;
      v65->m_q.mVec128.m128_u64[1] = v65->m_x.mVec128.m128_u64[1];
      *(float *)&v64 = v65->m_im;
      v66 = v65->m_f.mVec128.m128_f32[0] * *(float *)&v64;
      v67 = v65->m_f.mVec128.m128_f32[1] * *(float *)&v64;
      v68 = v65->m_f.mVec128.m128_f32[2] * *(float *)&v64;
      *(float *)&v64 = dt->m_sst.sdt;
      v65->m_v.mVec128.m128_f32[0] = (float)(*(float *)&v64 * v66) + v65->m_v.mVec128.m128_f32[0];
      v65->m_v.mVec128.m128_f32[1] = v65->m_v.mVec128.m128_f32[1] + (float)(*(float *)&v64 * v67);
      v65->m_v.mVec128.m128_f32[2] = v65->m_v.mVec128.m128_f32[2] + (float)(*(float *)&v64 * v68);
      v69 = dt->m_sst.sdt;
      v70 = v65->m_v.mVec128.m128_f32[1];
      v71 = v65->m_v.mVec128.m128_f32[2];
      v65->m_x.mVec128.m128_f32[0] = (float)(v65->m_v.mVec128.m128_f32[0] * v69) + v65->m_x.mVec128.m128_f32[0];
      v65->m_x.mVec128.m128_f32[1] = v65->m_x.mVec128.m128_f32[1] + (float)(v70 * v69);
      v65->m_x.mVec128.m128_f32[2] = v65->m_x.mVec128.m128_f32[2] + (float)(v71 * v69);
      ++v12;
      --v62;
      v65->m_f.mVec128.m128_u64[0] = 0;
      v65->m_f.mVec128.m128_u64[1] = 0;
    }
    while ( v62 );
  }
  btSoftBody::updateClusters((btSoftBody *)(v12 * 112), dt);
  btSoftBody::updateBounds(v72, (int)dt);
  v74 = dt->m_nodes.m_size;
  if ( v74 > 0 )
  {
    v215.m128i_i32[3] = 0;
    ppts[3] = 0;
    velocity.mVec128.m128_i32[3] = 0;
    v75 = 0;
    do
    {
      radmrg = dt->m_sst.radmrg;
      updmrg = dt->m_sst.updmrg;
      v78 = dt->m_nodes.m_data;
      v79 = v78[v75].m_x.mVec128.m128_f32[0];
      v80 = &v78[v75];
      *(float *)v215.m128i_i32 = v79 - radmrg;
      v81 = v80->m_x.mVec128.m128_f32[1];
      *(float *)&v215.m128i_i32[1] = v81 - radmrg;
      v82 = v80->m_x.mVec128.m128_f32[2];
      *(float *)ppts = v79 + radmrg;
      *(float *)&v83 = v82 - radmrg;
      *(float *)&ppts[1] = v81 + radmrg;
      *(float *)&ppts[2] = v82 + radmrg;
      volume.mx = (btVector3)_mm_load_si128((const __m128i *)ppts);
      velmrg = dt->m_sst.velmrg;
      velocity.mVec128.m128_f32[0] = velmrg * v80->m_v.mVec128.m128_f32[0];
      m_leaf = v80->m_leaf;
      margin = updmrg;
      velocity.mVec128.m128_f32[1] = v80->m_v.mVec128.m128_f32[1] * velmrg;
      v86 = v80->m_v.mVec128.m128_f32[2];
      v215.m128i_i32[2] = v83;
      volume.mi = (btVector3)_mm_load_si128(&v215);
      velocity.mVec128.m128_f32[2] = v86 * velmrg;
      btDbvt::update(&dt->m_ndbvt, m_leaf, &volume, &velocity, margin);
      ++v75;
      --v74;
    }
    while ( v74 );
  }
  if ( dt->m_fdbvt.m_root )
  {
    v87 = dt->m_faces.m_size <= 0;
    v214 = 0;
    if ( !v87 )
    {
      v213 = 0;
      do
      {
        v88 = (void **)((char *)&dt->m_faces.m_data->m_tag + v213);
        v89 = (btVector3 *)v88[3];
        v90 = (btVector3 *)v88[2];
        v91 = (btVector3 *)v88[4];
        v92 = v89[3].mVec128.m128_f32[2] + v90[3].mVec128.m128_f32[2];
        v93 = v91[3].mVec128.m128_f32[1] + (float)(v89[3].mVec128.m128_f32[1] + v90[3].mVec128.m128_f32[1]);
        v94 = v91[3].mVec128.m128_f32[2];
        *(float *)v215.m128i_i32 = (float)((float)(v89[3].mVec128.m128_f32[0] + v90[3].mVec128.m128_f32[0])
                                         + v91[3].mVec128.m128_f32[0])
                                 * 0.33333334;
        v95 = dt->m_sst.radmrg;
        ppts[1] = v89 + 1;
        *(float *)&v215.m128i_i32[1] = v93 * 0.33333334;
        *(float *)&v215.m128i_i32[2] = (float)(v94 + v92) * 0.33333334;
        v216 = v95;
        ppts[0] = v90 + 1;
        ppts[2] = v91 + 1;
        btDbvtAabbMm::FromPoints((const btVector3 **)ppts, v217);
        v96 = (btDbvtNode *)v88[13];
        v97 = v217[0].mi.mVec128.m128_f32[0] - v216;
        v98 = (float)(v217[0].mi.mVec128.m128_f32[0] - v216) < v96->volume.mi.mVec128.m128_f32[0];
        v99 = v217[0].mi.mVec128.m128_f32[1] - v216;
        v100 = v217[0].mi.mVec128.m128_f32[2] - v216;
        v101 = v217[0].mx.mVec128.m128_f32[0] + v216;
        v102 = v217[0].mx.mVec128.m128_f32[1] + v216;
        v217[0].mx.mVec128.m128_f32[2] = v217[0].mx.mVec128.m128_f32[2] + v216;
        v217[0].mi.mVec128.m128_f32[0] = v217[0].mi.mVec128.m128_f32[0] - v216;
        v217[0].mi.mVec128.m128_f32[1] = v217[0].mi.mVec128.m128_f32[1] - v216;
        v217[0].mi.mVec128.m128_f32[2] = v217[0].mi.mVec128.m128_f32[2] - v216;
        volume.mi = (btVector3)_mm_load_si128((const __m128i *)v217);
        v217[0].mx.mVec128.m128_f32[0] = v217[0].mx.mVec128.m128_f32[0] + v216;
        v217[0].mx.mVec128.m128_f32[1] = v217[0].mx.mVec128.m128_f32[1] + v216;
        volume.mx = (btVector3)_mm_load_si128((const __m128i *)&v217[0].mx);
        v103 = dt->m_sst.velmrg;
        v104 = v103 * *(float *)&v215.m128i_i32[2];
        v105 = v103 * *(float *)v215.m128i_i32;
        velocity.mVec128.m128_f32[1] = dt->m_sst.velmrg * *(float *)&v215.m128i_i32[1];
        v106 = dt->m_sst.updmrg;
        velocity.mVec128.m128_f32[2] = v104;
        if ( v98
          || v99 < v96->volume.mi.mVec128.m128_f32[1]
          || v100 < v96->volume.mi.mVec128.m128_f32[2]
          || v96->volume.mx.mVec128.m128_f32[0] < v101
          || v96->volume.mx.mVec128.m128_f32[1] < v102
          || v96->volume.mx.mVec128.m128_f32[2] < v217[0].mx.mVec128.m128_f32[2] )
        {
          v107 = v97 - v106;
          v108 = volume.mi.mVec128.m128_f32[1] - v106;
          v109 = volume.mi.mVec128.m128_f32[2] - v106;
          v110 = volume.mx.mVec128.m128_f32[0] + v106;
          v111 = volume.mx.mVec128.m128_f32[1] + v106;
          v112 = volume.mx.mVec128.m128_f32[2] + v106;
          volume.mi.mVec128.m128_f32[0] = v107;
          volume.mi.mVec128.m128_f32[1] = volume.mi.mVec128.m128_f32[1] - v106;
          volume.mi.mVec128.m128_f32[2] = volume.mi.mVec128.m128_f32[2] - v106;
          volume.mx.mVec128.m128_f32[0] = volume.mx.mVec128.m128_f32[0] + v106;
          volume.mx.mVec128.m128_f32[1] = volume.mx.mVec128.m128_f32[1] + v106;
          volume.mx.mVec128.m128_f32[2] = volume.mx.mVec128.m128_f32[2] + v106;
          if ( v105 <= 0.0 )
            volume.mi.mVec128.m128_f32[0] = v107 + v105;
          else
            volume.mx.mVec128.m128_f32[0] = v110 + v105;
          if ( velocity.mVec128.m128_f32[1] <= 0.0 )
            volume.mi.mVec128.m128_f32[1] = v108 + velocity.mVec128.m128_f32[1];
          else
            volume.mx.mVec128.m128_f32[1] = v111 + velocity.mVec128.m128_f32[1];
          if ( velocity.mVec128.m128_f32[2] <= 0.0 )
            volume.mi.mVec128.m128_f32[2] = v109 + velocity.mVec128.m128_f32[2];
          else
            volume.mx.mVec128.m128_f32[2] = v112 + velocity.mVec128.m128_f32[2];
          btDbvt::update(&dt->m_fdbvt, v96, &volume);
        }
        v213 += 64;
        v87 = ++v214 < dt->m_faces.m_size;
      }
      while ( v87 );
    }
  }
  btSoftBody::updatePose(v73, (btVector3 *)dt);
  if ( dt->m_pose.m_bframe && dt->m_cfg.kMT > 0.0 )
  {
    v113 = dt->m_nodes.m_size;
    v217[0] = *(btDbvtAabbMm *)dt->m_pose.m_rot.m_el[0].mVec128.m128_i8;
    v217[1].mi.mVec128.m128_u64[0] = dt->m_pose.m_rot.m_el[2].mVec128.m128_u64[0];
    v114 = v217[1].mi.mVec128.m128_f32[1];
    v217[1].mi.mVec128.m128_u64[1] = dt->m_pose.m_rot.m_el[2].mVec128.m128_u64[1];
    v115 = v217[1].mi.mVec128.m128_f32[2];
    v214 = 0;
    v213 = v113;
    if ( v113 >= 4 )
    {
      v116 = 0;
      v117 = 0;
      v118 = ((unsigned int)(v113 - 4) >> 2) + 1;
      v214 = 4 * v118;
      do
      {
        v119 = dt->m_nodes.m_data;
        v120 = v119[v117].m_im;
        v121 = (float *)&v119[v117];
        if ( v120 > 0.0 )
        {
          v122 = dt->m_pose.m_pos.m_data;
          v123 = v122[v116].mVec128.m128_f32[1];
          v124 = v122[v116].mVec128.m128_f32[0];
          v125 = v122[v116].mVec128.m128_f32[2];
          v126 = (float)((float)(v217[0].mi.mVec128.m128_f32[0] * v124) + (float)(v217[0].mi.mVec128.m128_f32[1] * v123))
               + (float)(v217[0].mi.mVec128.m128_f32[2] * v125);
          v127 = (float)((float)(v217[0].mx.mVec128.m128_f32[0] * v124) + (float)(v217[0].mx.mVec128.m128_f32[1] * v123))
               + (float)(v217[0].mx.mVec128.m128_f32[2] * v125);
          v128 = v115 * v125;
          v129 = dt->m_pose.m_com.mVec128.m128_f32[0] + v126;
          v130 = dt->m_pose.m_com.mVec128.m128_f32[1] + v127;
          v131 = dt->m_pose.m_com.mVec128.m128_f32[2]
               + (float)((float)(v128 + (float)(v217[1].mi.mVec128.m128_f32[0] * v124))
                       + (float)(v114 * v122[v116].mVec128.m128_f32[1]));
          kMT = dt->m_cfg.kMT;
          v133 = v121[6];
          v134 = (float)((float)(v129 - v121[4]) * kMT) + v121[4];
          *(float *)&ppts[1] = (float)((float)(v130 - v121[5]) * kMT) + v121[5];
          ppts[0] = (btVector3 *)LODWORD(v134);
          *((_QWORD *)v121 + 2) = *(_QWORD *)ppts;
          *(float *)&ppts[2] = (float)((float)(v131 - v133) * kMT) + v133;
          ppts[3] = 0;
          *((_QWORD *)v121 + 3) = *(_QWORD *)&ppts[2];
        }
        v135 = dt->m_nodes.m_data;
        v136 = (float *)&v135[v117 + 1];
        if ( v135[v117 + 1].m_im > 0.0 )
        {
          v137 = dt->m_pose.m_pos.m_data;
          v138 = v137[v116 + 1].mVec128.m128_f32[1];
          v139 = v137[v116 + 1].mVec128.m128_f32[0];
          v140 = v137[v116 + 1].mVec128.m128_f32[2];
          v141 = (float)((float)(v217[0].mi.mVec128.m128_f32[0] * v139) + (float)(v217[0].mi.mVec128.m128_f32[1] * v138))
               + (float)(v217[0].mi.mVec128.m128_f32[2] * v140);
          v142 = (float)((float)(v217[0].mx.mVec128.m128_f32[0] * v139) + (float)(v217[0].mx.mVec128.m128_f32[1] * v138))
               + (float)(v217[0].mx.mVec128.m128_f32[2] * v140);
          v143 = v115 * v140;
          v144 = dt->m_pose.m_com.mVec128.m128_f32[0] + v141;
          v145 = dt->m_pose.m_com.mVec128.m128_f32[1] + v142;
          v146 = dt->m_pose.m_com.mVec128.m128_f32[2]
               + (float)((float)(v143 + (float)(v217[1].mi.mVec128.m128_f32[0] * v137[v116 + 1].mVec128.m128_f32[0]))
                       + (float)(v114 * v138));
          v147 = dt->m_cfg.kMT;
          v148 = v136[6];
          v149 = (float)((float)(v144 - v136[4]) * v147) + v136[4];
          *(float *)&ppts[1] = (float)((float)(v145 - v136[5]) * v147) + v136[5];
          ppts[0] = (btVector3 *)LODWORD(v149);
          *((_QWORD *)v136 + 2) = *(_QWORD *)ppts;
          *(float *)&ppts[2] = (float)((float)(v146 - v148) * v147) + v148;
          ppts[3] = 0;
          *((_QWORD *)v136 + 3) = *(_QWORD *)&ppts[2];
        }
        v150 = dt->m_nodes.m_data;
        v151 = v150[v117 + 2].m_im;
        v152 = (float *)&v150[v117 + 2];
        if ( v151 > 0.0 )
        {
          v153 = dt->m_pose.m_pos.m_data;
          v154 = v153[v116 + 2].mVec128.m128_f32[1];
          v155 = v153[v116 + 2].mVec128.m128_f32[0];
          v156 = v153[v116 + 2].mVec128.m128_f32[2];
          v157 = (float)((float)(v217[0].mi.mVec128.m128_f32[0] * v155) + (float)(v217[0].mi.mVec128.m128_f32[1] * v154))
               + (float)(v217[0].mi.mVec128.m128_f32[2] * v156);
          v158 = (float)((float)(v217[0].mx.mVec128.m128_f32[0] * v155) + (float)(v217[0].mx.mVec128.m128_f32[1] * v154))
               + (float)(v217[0].mx.mVec128.m128_f32[2] * v156);
          v159 = v115 * v156;
          v160 = dt->m_pose.m_com.mVec128.m128_f32[0] + v157;
          v161 = dt->m_pose.m_com.mVec128.m128_f32[1] + v158;
          v162 = dt->m_pose.m_com.mVec128.m128_f32[2]
               + (float)((float)(v159 + (float)(v217[1].mi.mVec128.m128_f32[0] * v153[v116 + 2].mVec128.m128_f32[0]))
                       + (float)(v114 * v154));
          v163 = dt->m_cfg.kMT;
          v164 = v152[6];
          v165 = (float)((float)(v160 - v152[4]) * v163) + v152[4];
          *(float *)&ppts[1] = (float)((float)(v161 - v152[5]) * v163) + v152[5];
          ppts[0] = (btVector3 *)LODWORD(v165);
          *((_QWORD *)v152 + 2) = *(_QWORD *)ppts;
          *(float *)&ppts[2] = (float)((float)(v162 - v164) * v163) + v164;
          ppts[3] = 0;
          *((_QWORD *)v152 + 3) = *(_QWORD *)&ppts[2];
        }
        v166 = dt->m_nodes.m_data;
        v167 = v166[v117 + 3].m_im;
        v168 = (float *)&v166[v117 + 3];
        if ( v167 > 0.0 )
        {
          v169 = dt->m_pose.m_pos.m_data;
          v170 = v169[v116 + 3].mVec128.m128_f32[1];
          v171 = v169[v116 + 3].mVec128.m128_f32[0];
          v172 = v169[v116 + 3].mVec128.m128_f32[2];
          v173 = (float)((float)(v217[0].mi.mVec128.m128_f32[0] * v171) + (float)(v217[0].mi.mVec128.m128_f32[1] * v170))
               + (float)(v217[0].mi.mVec128.m128_f32[2] * v172);
          v174 = (float)((float)(v217[0].mx.mVec128.m128_f32[0] * v171) + (float)(v217[0].mx.mVec128.m128_f32[1] * v170))
               + (float)(v217[0].mx.mVec128.m128_f32[2] * v172);
          v175 = v115 * v172;
          v176 = dt->m_pose.m_com.mVec128.m128_f32[0] + v173;
          v177 = dt->m_pose.m_com.mVec128.m128_f32[1] + v174;
          v178 = dt->m_pose.m_com.mVec128.m128_f32[2]
               + (float)((float)(v175 + (float)(v217[1].mi.mVec128.m128_f32[0] * v169[v116 + 3].mVec128.m128_f32[0]))
                       + (float)(v114 * v170));
          v179 = dt->m_cfg.kMT;
          v180 = v168[6];
          v181 = (float)((float)(v176 - v168[4]) * v179) + v168[4];
          *(float *)&ppts[1] = (float)((float)(v177 - v168[5]) * v179) + v168[5];
          ppts[0] = (btVector3 *)LODWORD(v181);
          *((_QWORD *)v168 + 2) = *(_QWORD *)ppts;
          *(float *)&ppts[2] = (float)((float)(v178 - v180) * v179) + v180;
          ppts[3] = 0;
          *((_QWORD *)v168 + 3) = *(_QWORD *)&ppts[2];
        }
        v117 += 4;
        v116 += 4;
        --v118;
      }
      while ( v118 );
    }
    if ( v214 < v213 )
    {
      v182 = v214;
      v183 = v214;
      v184 = v213 - v214;
      do
      {
        v185 = dt->m_nodes.m_data;
        v186 = v185[v183].m_im;
        v187 = (float *)&v185[v183];
        if ( v186 > 0.0 )
        {
          v188 = dt->m_pose.m_pos.m_data;
          v189 = v188[v182].mVec128.m128_f32[2];
          v190 = v188[v182].mVec128.m128_f32[1];
          v191 = v188[v182].mVec128.m128_f32[0];
          v192 = (float)((float)(v217[0].mi.mVec128.m128_f32[1] * v190) + (float)(v217[0].mi.mVec128.m128_f32[2] * v189))
               + (float)(v217[0].mi.mVec128.m128_f32[0] * v191);
          v193 = (float)((float)(v217[0].mx.mVec128.m128_f32[1] * v190) + (float)(v217[0].mx.mVec128.m128_f32[2] * v189))
               + (float)(v217[0].mx.mVec128.m128_f32[0] * v191);
          v194 = v115 * v189;
          v195 = dt->m_pose.m_com.mVec128.m128_f32[0] + v192;
          v196 = dt->m_pose.m_com.mVec128.m128_f32[1] + v193;
          v197 = dt->m_pose.m_com.mVec128.m128_f32[2]
               + (float)((float)(v194 + (float)(v114 * v188[v182].mVec128.m128_f32[1]))
                       + (float)(v217[1].mi.mVec128.m128_f32[0] * v191));
          v198 = dt->m_cfg.kMT;
          v199 = v187[6];
          v200 = (float)((float)(v195 - v187[4]) * v198) + v187[4];
          *(float *)&ppts[1] = (float)((float)(v196 - v187[5]) * v198) + v187[5];
          ppts[0] = (btVector3 *)LODWORD(v200);
          *((_QWORD *)v187 + 2) = *(_QWORD *)ppts;
          *(float *)&ppts[2] = (float)((float)(v197 - v199) * v198) + v199;
          ppts[3] = 0;
          *((_QWORD *)v187 + 3) = *(_QWORD *)&ppts[2];
        }
        ++v183;
        ++v182;
        --v184;
      }
      while ( v184 );
    }
  }
  v214 = dt->m_rcontacts.m_size;
  v201 = v214;
  if ( v214 <= 0 )
  {
    if ( v214 < 0 && dt->m_rcontacts.m_capacity < 0 )
    {
      v202 = dt->m_rcontacts.m_data;
      if ( v202 )
      {
        if ( dt->m_rcontacts.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v202);
          v201 = v214;
        }
        dt->m_rcontacts.m_data = 0;
      }
      dt->m_rcontacts.m_ownsMemory = 1;
      dt->m_rcontacts.m_data = 0;
      dt->m_rcontacts.m_capacity = 0;
    }
    if ( v201 < 0 )
    {
      v203 = v201;
      do
      {
        v204 = (int)&dt->m_rcontacts.m_data[v203];
        if ( v204 )
          btSoftBody::RContact::RContact(&v220, v204);
        ++v203;
      }
      while ( v203 < 0 );
    }
  }
  dt->m_rcontacts.m_size = 0;
  v205 = dt->m_scontacts.m_size;
  v216 = *(float *)&v205;
  if ( v205 <= 0 )
  {
    if ( v205 < 0 && dt->m_scontacts.m_capacity < 0 )
    {
      v206 = dt->m_scontacts.m_data;
      if ( v206 )
      {
        if ( dt->m_scontacts.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v206);
        }
        dt->m_scontacts.m_data = 0;
      }
      dt->m_scontacts.m_ownsMemory = 1;
      dt->m_scontacts.m_data = 0;
      dt->m_scontacts.m_capacity = 0;
    }
    if ( v205 < 0 )
    {
      v207 = v205 << 6;
      do
      {
        v208 = (btDbvtAabbMm *)((char *)dt->m_scontacts.m_data + v207);
        if ( v208 )
        {
          qmemcpy(v208, v217, 0x40u);
          v201 = 0;
        }
        v207 += 64;
      }
      while ( v207 < 0 );
    }
  }
  dt->m_scontacts.m_size = 0;
  btDbvt::optimizeIncremental((btDbvt *)v201, (int)&dt->m_ndbvt);
  btDbvt::optimizeIncremental(v209, (int)&dt->m_fdbvt);
  btDbvt::optimizeIncremental(v210, (int)&dt->m_cdbvt);
}
