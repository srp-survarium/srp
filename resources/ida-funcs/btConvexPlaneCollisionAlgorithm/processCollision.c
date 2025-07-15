void __thiscall btConvexPlaneCollisionAlgorithm::processCollision(
        btConvexPlaneCollisionAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        const btDispatcherInfo *dispatchInfo,
        btManifoldResult *resultOut)
{
  bool v5; // zf
  btCollisionObject *v6; // edi
  btCollisionObject *v7; // esi
  int m_collisionShape; // ebx
  float *p_m_worldTransform; // edi
  float *v10; // esi
  btTransform *v11; // eax
  float v12; // xmm2_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm7_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm6_4
  float v20; // xmm3_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  float v23; // xmm1_4
  float v24; // xmm6_4
  float v25; // xmm5_4
  float v26; // xmm7_4
  float v27; // xmm6_4
  float v28; // xmm1_4
  float v29; // xmm7_4
  float v30; // xmm6_4
  float v31; // xmm5_4
  float v32; // xmm7_4
  float v33; // xmm5_4
  float v34; // xmm6_4
  float v35; // xmm5_4
  float v36; // xmm6_4
  btTransform *v37; // ecx
  btTransform *v38; // eax
  float v39; // xmm3_4
  float v40; // xmm5_4
  float v41; // xmm2_4
  float v42; // xmm4_4
  float v43; // xmm1_4
  float v44; // xmm0_4
  float v45; // xmm4_4
  float v46; // xmm0_4
  float v47; // xmm4_4
  float v48; // xmm5_4
  float v49; // xmm6_4
  float v50; // xmm7_4
  float v51; // xmm0_4
  float v52; // xmm2_4
  float v53; // xmm1_4
  float v54; // xmm3_4
  float v55; // xmm0_4
  float v56; // xmm1_4
  float v57; // xmm5_4
  float v58; // xmm1_4
  float v59; // xmm2_4
  float v60; // xmm0_4
  float v61; // xmm1_4
  float v62; // xmm6_4
  float v63; // xmm5_4
  float v64; // xmm2_4
  float v65; // xmm1_4
  float v66; // xmm6_4
  float v67; // xmm2_4
  float v68; // xmm7_4
  float v69; // xmm7_4
  float v70; // xmm6_4
  float v71; // xmm5_4
  float v72; // xmm6_4
  float v73; // xmm7_4
  float v74; // xmm5_4
  float v75; // xmm0_4
  float v76; // xmm1_4
  int v77; // eax
  float v78; // xmm3_4
  float v79; // xmm5_4
  float v80; // xmm6_4
  float v81; // xmm0_4
  float v82; // xmm2_4
  float v83; // xmm4_4
  int v84; // edi
  btPersistentManifold *v85; // ecx
  float v86; // xmm3_4
  float v87; // xmm2_4
  float v88; // xmm1_4
  float v89; // xmm0_4
  float v90; // xmm5_4
  float v91; // xmm4_4
  float m_contactBreakingThreshold; // xmm1_4
  btManifoldResult *v93; // eax
  float v94; // xmm3_4
  float v95; // xmm2_4
  float v96; // xmm1_4
  float v97; // xmm5_4
  btManifoldResult_vtbl *v98; // edx
  float v99; // xmm4_4
  float v100; // xmm5_4
  float v101; // xmm1_4
  float v102; // xmm4_4
  float v103; // xmm3_4
  float v104; // xmm3_4
  float v105; // xmm4_4
  float v106; // xmm0_4
  float v107; // xmm1_4
  float v108; // xmm3_4
  float v109; // xmm1_4
  __m128 v110; // xmm0
  __m128i v111; // xmm0
  float v112; // xmm3_4
  float v113; // xmm1_4
  float v114; // xmm2_4
  int v115; // eax
  int v116; // esi
  __m128 v117; // xmm0
  float v118; // xmm1_4
  __m128i v119; // xmm0
  float v120; // xmm1_4
  float v121; // xmm7_4
  float v122; // xmm1_4
  float v123; // xmm2_4
  float v124; // xmm3_4
  btConvexPlaneCollisionAlgorithm *v125; // ecx
  btPersistentManifold *m_manifoldPtr; // esi
  btPersistentManifold *p_m_rootTransB; // ecx
  const btTransform *p_m_rootTransA; // edx
  long double v129; // [esp+Ch] [ebp-150h]
  const float *v130; // [esp+Ch] [ebp-150h]
  long double v131; // [esp+Ch] [ebp-150h]
  float v132; // [esp+24h] [ebp-138h] BYREF
  float v133; // [esp+28h] [ebp-134h]
  btQuaternion v134; // [esp+2Ch] [ebp-130h]
  btMatrix3x3 v135; // [esp+44h] [ebp-118h] BYREF
  float v136; // [esp+74h] [ebp-E8h] BYREF
  float v137; // [esp+78h] [ebp-E4h] BYREF
  float v138; // [esp+7Ch] [ebp-E0h] BYREF
  float v139; // [esp+80h] [ebp-DCh] BYREF
  float v140; // [esp+84h] [ebp-D8h] BYREF
  float v141; // [esp+88h] [ebp-D4h] BYREF
  btQuaternion v142; // [esp+8Ch] [ebp-D0h] BYREF
  float v143; // [esp+9Ch] [ebp-C0h] BYREF
  float v144; // [esp+A0h] [ebp-BCh]
  float v145; // [esp+A4h] [ebp-B8h]
  float v146[12]; // [esp+ACh] [ebp-B0h] BYREF
  btTransform v147; // [esp+DCh] [ebp-80h] BYREF
  btTransform v148; // [esp+11Ch] [ebp-40h] BYREF

  v5 = this->m_manifoldPtr == 0;
  v135.m_el[2].mVec128.m128_i32[3] = (int)this;
  if ( !v5 )
  {
    v6 = body1;
    v7 = body0;
    if ( !this->m_isSwapped )
    {
      v6 = body0;
      v7 = body1;
    }
    m_collisionShape = (int)v7->m_collisionShape;
    v135.m_el[2].mVec128.m128_i32[2] = (int)v6->m_collisionShape;
    p_m_worldTransform = (float *)&v6->m_worldTransform;
    v10 = (float *)&v7->m_worldTransform;
    v11 = btTransform::inverse((btTransform *)this, (int)p_m_worldTransform, &v147);
    v12 = v10[10];
    v13 = v10[5];
    v14 = v11->m_basis.m_el[2].mVec128.m128_f32[2];
    v15 = v11->m_basis.m_el[2].mVec128.m128_f32[1] * v10[4];
    v16 = (float)(v11->m_basis.m_el[2].mVec128.m128_f32[1] * v10[6]) + (float)(v14 * v12);
    v17 = v11->m_basis.m_el[2].mVec128.m128_f32[0] * v10[2];
    v18 = v11->m_basis.m_el[2].mVec128.m128_f32[1];
    v135.m_el[2].mVec128.m128_f32[0] = v10[4];
    v19 = v11->m_basis.m_el[2].mVec128.m128_f32[2];
    v20 = v16 + v17;
    v21 = v10[1];
    v135.m_el[1].mVec128.m128_f32[3] = v20;
    v22 = v10[9];
    v23 = (float)((float)(v18 * v13) + (float)(v14 * v22)) + (float)(v11->m_basis.m_el[2].mVec128.m128_f32[0] * v21);
    v24 = v19 * v10[8];
    v135.m_el[0].mVec128.m128_f32[0] = v10[8];
    v25 = v11->m_basis.m_el[2].mVec128.m128_f32[0];
    v26 = v15 + v24;
    v27 = v11->m_basis.m_el[1].mVec128.m128_f32[1];
    v138 = v23;
    v28 = *v10;
    v29 = v26 + (float)(v25 * *v10);
    v30 = (float)(v27 * v10[6]) + (float)(v11->m_basis.m_el[1].mVec128.m128_f32[2] * v12);
    v31 = v10[2];
    v139 = v29;
    v32 = v11->m_basis.m_el[1].mVec128.m128_f32[0] * v31;
    v33 = v11->m_basis.m_el[1].mVec128.m128_f32[1];
    v136 = v30 + v32;
    v34 = v11->m_basis.m_el[1].mVec128.m128_f32[2] * v135.m_el[0].mVec128.m128_f32[0];
    v137 = (float)((float)(v33 * v13) + (float)(v11->m_basis.m_el[1].mVec128.m128_f32[2] * v22))
         + (float)(v21 * v11->m_basis.m_el[1].mVec128.m128_f32[0]);
    v35 = (float)((float)(v11->m_basis.m_el[1].mVec128.m128_f32[1] * v135.m_el[2].mVec128.m128_f32[0]) + v34)
        + (float)(v28 * v11->m_basis.m_el[1].mVec128.m128_f32[0]);
    v36 = v11->m_basis.m_el[0].mVec128.m128_f32[1];
    v141 = v35;
    v135.m_el[0].mVec128.m128_i32[1] = v11->m_basis.m_el[0].mVec128.m128_i32[2];
    v133 = v11->m_basis.m_el[0].mVec128.m128_f32[0];
    v135.m_el[2].mVec128.m128_f32[1] = v36;
    v132 = (float)((float)(v21 * v133) + (float)(v13 * v36)) + (float)(v22 * v135.m_el[0].mVec128.m128_f32[1]);
    v140 = (float)((float)(v133 * v10[2]) + (float)(v36 * v10[6])) + (float)(v12 * v135.m_el[0].mVec128.m128_f32[1]);
    v135.m_el[0].mVec128.m128_f32[0] = (float)((float)(v28 * v133) + (float)(v135.m_el[2].mVec128.m128_f32[0] * v36))
                                     + (float)(v135.m_el[0].mVec128.m128_f32[0] * v135.m_el[0].mVec128.m128_f32[1]);
    btMatrix3x3::setValue(
      &v135,
      (int)v146,
      &v132,
      &v140,
      &v141,
      &v137,
      &v136,
      &v139,
      &v138,
      &v135.m_el[1].mVec128.m128_f32[3],
      (const float *)LODWORD(v129));
    v38 = btTransform::inverse(v37, (int)v10, &v148);
    v39 = p_m_worldTransform[12];
    v40 = v38->m_basis.m_el[0].mVec128.m128_f32[1];
    v41 = p_m_worldTransform[13];
    v42 = v38->m_basis.m_el[0].mVec128.m128_f32[2];
    v43 = p_m_worldTransform[14];
    v135.m_el[0].mVec128.m128_i32[1] = v38->m_basis.m_el[0].mVec128.m128_i32[0];
    v135.m_el[2].mVec128.m128_f32[0] = v40;
    v44 = (float)((float)((float)(v39 * v135.m_el[0].mVec128.m128_f32[1]) + (float)(v41 * v40)) + (float)(v43 * v42))
        + v38->m_origin.mVec128.m128_f32[0];
    v133 = v42;
    v45 = v38->m_basis.m_el[1].mVec128.m128_f32[2];
    v134.m_floats[0] = v44;
    v46 = (float)((float)((float)(v38->m_basis.m_el[1].mVec128.m128_f32[1] * v41) + (float)(v45 * v43))
                + (float)(v38->m_basis.m_el[1].mVec128.m128_f32[0] * v39))
        + v38->m_origin.mVec128.m128_f32[1];
    v47 = p_m_worldTransform[6];
    v48 = p_m_worldTransform[5];
    v49 = v38->m_basis.m_el[2].mVec128.m128_f32[1] * v48;
    v50 = v38->m_basis.m_el[2].mVec128.m128_f32[1];
    v134.m_floats[1] = v46;
    v51 = (float)(v38->m_basis.m_el[2].mVec128.m128_f32[1] * v41)
        + (float)(v38->m_basis.m_el[2].mVec128.m128_f32[2] * v43);
    v52 = v38->m_basis.m_el[2].mVec128.m128_f32[2];
    v53 = v38->m_basis.m_el[2].mVec128.m128_f32[0] * v39;
    v54 = p_m_worldTransform[10];
    v55 = (float)(v51 + v53) + v38->m_origin.mVec128.m128_f32[2];
    v56 = v38->m_basis.m_el[2].mVec128.m128_f32[1];
    v135.m_el[0].mVec128.m128_f32[0] = v48;
    v57 = v38->m_basis.m_el[2].mVec128.m128_f32[2];
    v58 = (float)(v56 * v47) + (float)(v52 * v54);
    v59 = v38->m_basis.m_el[2].mVec128.m128_f32[0];
    v134.m_floats[2] = v55;
    v60 = p_m_worldTransform[2];
    v61 = v58 + (float)(v59 * v60);
    v62 = v49 + (float)(v57 * p_m_worldTransform[9]);
    v63 = p_m_worldTransform[8];
    v135.m_el[2].mVec128.m128_f32[1] = p_m_worldTransform[9];
    v64 = v38->m_basis.m_el[2].mVec128.m128_f32[0];
    v132 = v63;
    v140 = v61;
    v65 = p_m_worldTransform[1];
    v66 = v62 + (float)(v64 * v65);
    v67 = *p_m_worldTransform;
    v141 = v66;
    v68 = v50 * p_m_worldTransform[4];
    v135.m_el[1].mVec128.m128_f32[3] = p_m_worldTransform[4];
    v69 = (float)(v68 + (float)(v38->m_basis.m_el[2].mVec128.m128_f32[2] * v63))
        + (float)(v38->m_basis.m_el[2].mVec128.m128_f32[0] * v67);
    v70 = v38->m_basis.m_el[1].mVec128.m128_f32[2] * v135.m_el[2].mVec128.m128_f32[1];
    v136 = (float)((float)(v38->m_basis.m_el[1].mVec128.m128_f32[1] * v47)
                 + (float)(v38->m_basis.m_el[1].mVec128.m128_f32[2] * v54))
         + (float)(v38->m_basis.m_el[1].mVec128.m128_f32[0] * v60);
    v71 = (float)((float)(v38->m_basis.m_el[1].mVec128.m128_f32[1] * v135.m_el[0].mVec128.m128_f32[0]) + v70)
        + (float)(v38->m_basis.m_el[1].mVec128.m128_f32[0] * v65);
    v72 = v38->m_basis.m_el[1].mVec128.m128_f32[1];
    v137 = v69;
    v73 = v38->m_basis.m_el[1].mVec128.m128_f32[2];
    v139 = v71;
    v74 = v132;
    v132 = (float)((float)(v72 * v135.m_el[1].mVec128.m128_f32[3]) + (float)(v73 * v132))
         + (float)(v67 * v38->m_basis.m_el[1].mVec128.m128_f32[0]);
    v138 = (float)((float)(v60 * v135.m_el[0].mVec128.m128_f32[1]) + (float)(v47 * v135.m_el[2].mVec128.m128_f32[0]))
         + (float)(v54 * v133);
    v135.m_el[0].mVec128.m128_f32[0] = (float)((float)(v65 * v135.m_el[0].mVec128.m128_f32[1])
                                             + (float)(v135.m_el[0].mVec128.m128_f32[0]
                                                     * v135.m_el[2].mVec128.m128_f32[0]))
                                     + (float)(v135.m_el[2].mVec128.m128_f32[1] * v133);
    v135.m_el[1].mVec128.m128_f32[3] = (float)((float)(v67 * v135.m_el[0].mVec128.m128_f32[1])
                                             + (float)(v135.m_el[1].mVec128.m128_f32[3]
                                                     * v135.m_el[2].mVec128.m128_f32[0]))
                                     + (float)(v74 * v133);
    btMatrix3x3::setValue(
      (btMatrix3x3 *)&v135.m_el[1].m_floats[3],
      (int)&v147,
      (float *)&v135,
      &v138,
      &v132,
      &v139,
      &v136,
      &v137,
      &v141,
      &v140,
      v130);
    LODWORD(v75) = *(_DWORD *)(m_collisionShape + 52) ^ _mask__NegFloat_;
    LODWORD(v76) = *(_DWORD *)(m_collisionShape + 56) ^ _mask__NegFloat_;
    v77 = *(_DWORD *)v135.m_el[2].mVec128.m128_i32[2];
    LODWORD(v78) = *(_DWORD *)(m_collisionShape + 48) ^ _mask__NegFloat_;
    v135.m_el[0].mVec128.m128_f32[2] = (float)((float)(v146[1] * v75) + (float)(v146[2] * v76)) + (float)(v146[0] * v78);
    v135.m_el[0].mVec128.m128_f32[3] = (float)((float)(v146[4] * v78) + (float)(v75 * v146[5])) + (float)(v76 * v146[6]);
    v135.m_el[1].mVec128.m128_f32[0] = (float)((float)(v146[8] * v78) + (float)(v75 * v146[9]))
                                     + (float)(v76 * v146[10]);
    v135.m_el[1].mVec128.m128_i32[1] = 0;
    (*(void (__stdcall **)(float *, float *))(v77 + 56))(&v143, &v135.m_el[0].mVec128.m128_f32[2]);
    v79 = *(float *)(m_collisionShape + 52);
    v80 = *(float *)(m_collisionShape + 48);
    v81 = (float)((float)((float)(v147.m_basis.m_el[0].mVec128.m128_f32[0] * v143)
                        + (float)(v145 * v147.m_basis.m_el[0].mVec128.m128_f32[2]))
                + (float)(v144 * v147.m_basis.m_el[0].mVec128.m128_f32[1]))
        + v134.m_floats[0];
    v82 = (float)((float)((float)(v147.m_basis.m_el[2].mVec128.m128_f32[0] * v143)
                        + (float)(v145 * v147.m_basis.m_el[2].mVec128.m128_f32[2]))
                + (float)(v144 * v147.m_basis.m_el[2].mVec128.m128_f32[1]))
        + v134.m_floats[2];
    v83 = *(float *)(m_collisionShape + 56);
    v84 = v135.m_el[2].mVec128.m128_i32[3];
    v85 = *(btPersistentManifold **)(v135.m_el[2].mVec128.m128_i32[3] + 12);
    v86 = (float)((float)((float)(v81 * v80)
                        + (float)((float)((float)((float)((float)(v147.m_basis.m_el[1].mVec128.m128_f32[0] * v143)
                                                        + (float)(v145 * v147.m_basis.m_el[1].mVec128.m128_f32[2]))
                                                + (float)(v144 * v147.m_basis.m_el[1].mVec128.m128_f32[1]))
                                        + v134.m_floats[1])
                                * v79))
                + (float)(v82 * v83))
        - *(float *)(m_collisionShape + 64);
    v87 = v82 - (float)(v83 * v86);
    v88 = (float)((float)((float)((float)(v147.m_basis.m_el[1].mVec128.m128_f32[0] * v143)
                                + (float)(v145 * v147.m_basis.m_el[1].mVec128.m128_f32[2]))
                        + (float)(v144 * v147.m_basis.m_el[1].mVec128.m128_f32[1]))
                + v134.m_floats[1])
        - (float)(v79 * v86);
    v89 = v81 - (float)(v80 * v86);
    v90 = v10[5];
    v134.m_floats[0] = (float)((float)((float)(v10[2] * v87) + (float)(v10[1] * v88)) + (float)(v89 * *v10)) + v10[12];
    v134.m_floats[1] = (float)((float)((float)(v10[6] * v87) + (float)(v90 * v88)) + (float)(v10[4] * v89)) + v10[13];
    v91 = (float)((float)((float)(v10[10] * v87) + (float)(v10[9] * v88)) + (float)(v10[8] * v89)) + v10[14];
    m_contactBreakingThreshold = v85->m_contactBreakingThreshold;
    v132 = v86;
    v134.m_floats[2] = v91;
    v134.m_floats[3] = 0.0;
    v93 = resultOut;
    resultOut->m_manifoldPtr = v85;
    if ( m_contactBreakingThreshold > v86 )
    {
      v94 = *(float *)(m_collisionShape + 52);
      v95 = *(float *)(m_collisionShape + 56);
      v96 = *(float *)(m_collisionShape + 48);
      v97 = v10[6];
      v135.m_el[0].mVec128.m128_f32[2] = (float)((float)(v10[1] * v94) + (float)(v10[2] * v95)) + (float)(v96 * *v10);
      v98 = resultOut->__vftable;
      v99 = (float)(v10[5] * v94) + (float)(v97 * v95);
      v100 = v10[4] * v96;
      v101 = v96 * v10[8];
      v135.m_el[0].mVec128.m128_f32[3] = v99 + v100;
      v102 = v10[9] * v94;
      v103 = v10[10];
      v142 = v134;
      v135.m_el[1].mVec128.m128_f32[0] = (float)(v102 + (float)(v103 * v95)) + v101;
      v135.m_el[1].mVec128.m128_i32[1] = 0;
      v98->addContactPoint(
        resultOut,
        (const btVector3 *)&v135.m_el[0].m_floats[2],
        (const btVector3 *)&v142,
        COERCE_FLOAT(LODWORD(v132)));
      v93 = resultOut;
      v84 = v135.m_el[2].mVec128.m128_i32[3];
    }
    if ( *(int *)(v135.m_el[2].mVec128.m128_i32[2] + 4) < 7
      && v93->m_manifoldPtr->m_cachedPoints < *(_DWORD *)(v84 + 24) )
    {
      v104 = *(float *)(m_collisionShape + 56);
      if ( COERCE_FLOAT(LODWORD(v104) & _mask__AbsFloat_) <= hsqt2 )
      {
        v108 = *(float *)(m_collisionShape + 48);
        v109 = s_bm_current_air_resistance
             / fsqrt((float)(v108 * v108) + (float)(*(float *)(m_collisionShape + 52) * *(float *)(m_collisionShape + 52)));
        LODWORD(v134.m_floats[0]) = COERCE_UNSIGNED_INT(v109 * *(float *)(m_collisionShape + 52)) ^ _mask__NegFloat_;
        v134.m_floats[1] = v109 * v108;
        v134.m_floats[2] = 0.0;
      }
      else
      {
        v105 = (float)(*(float *)(m_collisionShape + 52) * *(float *)(m_collisionShape + 52))
             + (float)(*(float *)(m_collisionShape + 56) * *(float *)(m_collisionShape + 56));
        v134.m_floats[0] = 0.0;
        v106 = s_bm_current_air_resistance / fsqrt(v105);
        v107 = v106 * *(float *)(m_collisionShape + 52);
        LODWORD(v134.m_floats[1]) = COERCE_UNSIGNED_INT(v106 * v104) ^ _mask__NegFloat_;
        v134.m_floats[2] = v107;
      }
      v132 = ((double (*)(void))*(_DWORD *)(*(_DWORD *)v135.m_el[2].mVec128.m128_i32[2] + 12))();
      v110 = (__m128)LODWORD(gContactBreakingThreshold);
      v110.m128_f32[0] = gContactBreakingThreshold / v132;
      if ( (float)(gContactBreakingThreshold / v132) > 0.39269909 )
        v110 = (__m128)LODWORD(FLOAT_0_39269909);
      v110.m128_f32[0] = v110.m128_f32[0] * 0.5;
      v132 = v110.m128_f32[0];
      v111 = (__m128i)_mm_cvtps_pd(v110);
      __libm_sse2_sin(v111);
      *(float *)v111.m128i_i32 = *(double *)v111.m128i_i64;
      *(float *)v111.m128i_i32 = *(float *)v111.m128i_i32
                               / fsqrt(
                                   (float)((float)(v134.m_floats[2] * v134.m_floats[2])
                                         + (float)(v134.m_floats[1] * v134.m_floats[1]))
                                 + (float)(v134.m_floats[0] * v134.m_floats[0]));
      v112 = *(float *)v111.m128i_i32 * v134.m_floats[0];
      v113 = v134.m_floats[1] * *(float *)v111.m128i_i32;
      v114 = v134.m_floats[2] * *(float *)v111.m128i_i32;
      *(double *)v111.m128i_i64 = v132;
      v134.m_floats[0] = v112;
      v134.m_floats[1] = v113;
      v134.m_floats[2] = v114;
      __libm_sse2_cos(v129);
      v115 = *(_DWORD *)(v84 + 20);
      v116 = 0;
      *(float *)v111.m128i_i32 = *(double *)v111.m128i_i64;
      for ( LODWORD(v134.m_floats[3]) = v111.m128i_i32[0]; v116 < v115; ++v116 )
      {
        v117 = (__m128)LODWORD(pi_x2_13);
        v117.m128_f32[0] = (float)((float)(6.2831855 / (float)v115) * (float)v116) * 0.5;
        v135.m_el[2].mVec128.m128_u64[1] = *(_QWORD *)(m_collisionShape + 52);
        v118 = *(float *)(m_collisionShape + 48);
        v132 = v117.m128_f32[0];
        v133 = v118;
        v119 = (__m128i)_mm_cvtps_pd(v117);
        __libm_sse2_sin(v119);
        *(float *)v119.m128i_i32 = *(double *)v119.m128i_i64;
        *(float *)v119.m128i_i32 = *(float *)v119.m128i_i32
                                 / fsqrt(
                                     (float)((float)(v133 * v133)
                                           + (float)(v135.m_el[2].mVec128.m128_f32[2] * v135.m_el[2].mVec128.m128_f32[2]))
                                   + (float)(v135.m_el[2].mVec128.m128_f32[3] * v135.m_el[2].mVec128.m128_f32[3]));
        v135.m_el[0].mVec128.m128_f32[2] = *(float *)v119.m128i_i32 * v133;
        v120 = *(float *)v119.m128i_i32 * *(float *)(m_collisionShape + 52);
        v135.m_el[1].mVec128.m128_f32[0] = *(float *)v119.m128i_i32 * *(float *)(m_collisionShape + 56);
        *(double *)v119.m128i_i64 = v132;
        v135.m_el[0].mVec128.m128_f32[3] = v120;
        __libm_sse2_cos(v131);
        v121 = *(double *)v119.m128i_i64;
        v122 = (float)((float)((float)(COERCE_FLOAT(v135.m_el[0].mVec128.m128_i32[3] ^ _mask__NegFloat_)
                                     * v134.m_floats[2])
                             + (float)(v134.m_floats[3]
                                     * COERCE_FLOAT(v135.m_el[0].mVec128.m128_i32[2] ^ _mask__NegFloat_)))
                     + (float)(v121 * v134.m_floats[0]))
             - (float)(COERCE_FLOAT(v135.m_el[1].mVec128.m128_i32[0] ^ _mask__NegFloat_) * v134.m_floats[1]);
        v123 = (float)((float)((float)(COERCE_FLOAT(v135.m_el[0].mVec128.m128_i32[3] ^ _mask__NegFloat_)
                                     * v134.m_floats[3])
                             + (float)(v121 * v134.m_floats[1]))
                     + (float)(COERCE_FLOAT(v135.m_el[1].mVec128.m128_i32[0] ^ _mask__NegFloat_) * v134.m_floats[0]))
             - (float)(v134.m_floats[2] * COERCE_FLOAT(v135.m_el[0].mVec128.m128_i32[2] ^ _mask__NegFloat_));
        v135.m_el[1].mVec128.m128_f32[1] = v121;
        v124 = (float)((float)((float)(COERCE_FLOAT(v135.m_el[1].mVec128.m128_i32[0] ^ _mask__NegFloat_)
                                     * v134.m_floats[3])
                             + (float)(v121 * v134.m_floats[2]))
                     + (float)(v134.m_floats[1] * COERCE_FLOAT(v135.m_el[0].mVec128.m128_i32[2] ^ _mask__NegFloat_)))
             - (float)(COERCE_FLOAT(v135.m_el[0].mVec128.m128_i32[3] ^ _mask__NegFloat_) * v134.m_floats[0]);
        *(float *)v119.m128i_i32 = (float)((float)((float)(v121 * v134.m_floats[3])
                                                 - (float)(COERCE_FLOAT(v135.m_el[0].mVec128.m128_i32[2] ^ _mask__NegFloat_)
                                                         * v134.m_floats[0]))
                                         - (float)(COERCE_FLOAT(v135.m_el[0].mVec128.m128_i32[3] ^ _mask__NegFloat_)
                                                 * v134.m_floats[1]))
                                 - (float)(COERCE_FLOAT(v135.m_el[1].mVec128.m128_i32[0] ^ _mask__NegFloat_)
                                         * v134.m_floats[2]);
        v142.m_floats[0] = (float)((float)((float)(v123 * v135.m_el[1].mVec128.m128_f32[0]) + (float)(v121 * v122))
                                 + (float)(*(float *)v119.m128i_i32 * v135.m_el[0].mVec128.m128_f32[2]))
                         - (float)(v124 * v135.m_el[0].mVec128.m128_f32[3]);
        v142.m_floats[1] = (float)((float)((float)(v123 * v135.m_el[1].mVec128.m128_f32[1])
                                         + (float)((float)((float)((float)((float)(v135.m_el[1].mVec128.m128_f32[1]
                                                                                 * v134.m_floats[3])
                                                                         - (float)(COERCE_FLOAT(
                                                                                     v135.m_el[0].mVec128.m128_i32[2]
                                                                                   ^ _mask__NegFloat_)
                                                                                 * v134.m_floats[0]))
                                                                 - (float)(COERCE_FLOAT(
                                                                             v135.m_el[0].mVec128.m128_i32[3]
                                                                           ^ _mask__NegFloat_)
                                                                         * v134.m_floats[1]))
                                                         - (float)(COERCE_FLOAT(v135.m_el[1].mVec128.m128_i32[0] ^ _mask__NegFloat_)
                                                                 * v134.m_floats[2]))
                                                 * v135.m_el[0].mVec128.m128_f32[3]))
                                 + (float)(v124 * v135.m_el[0].mVec128.m128_f32[2]))
                         - (float)(v135.m_el[1].mVec128.m128_f32[0] * v122);
        v142.m_floats[2] = (float)((float)((float)(v124 * v121)
                                         + (float)(*(float *)v119.m128i_i32 * v135.m_el[1].mVec128.m128_f32[0]))
                                 + (float)(v135.m_el[0].mVec128.m128_f32[3] * v122))
                         - (float)(v123 * v135.m_el[0].mVec128.m128_f32[2]);
        v142.m_floats[3] = (float)((float)((float)(*(float *)v119.m128i_i32 * v121)
                                         - (float)(v122 * v135.m_el[0].mVec128.m128_f32[2]))
                                 - (float)(v123 * v135.m_el[0].mVec128.m128_f32[3]))
                         - (float)(v124 * v135.m_el[1].mVec128.m128_f32[0]);
        btConvexPlaneCollisionAlgorithm::collideSingleContact(
          v125,
          m_collisionShape,
          (const float *)v84,
          v116,
          (const btQuaternion *)v84,
          &v142,
          body0,
          body1,
          resultOut);
        v115 = *(_DWORD *)(v84 + 20);
      }
      v93 = resultOut;
    }
    if ( *(_BYTE *)(v84 + 8) )
    {
      if ( *(_DWORD *)(*(_DWORD *)(v84 + 12) + 1176) )
      {
        m_manifoldPtr = v93->m_manifoldPtr;
        if ( m_manifoldPtr->m_cachedPoints )
        {
          if ( m_manifoldPtr->m_body0 == v93->m_body0 )
          {
            p_m_rootTransB = (btPersistentManifold *)&v93->m_rootTransB;
            p_m_rootTransA = &v93->m_rootTransA;
          }
          else
          {
            p_m_rootTransB = (btPersistentManifold *)&v93->m_rootTransA;
            p_m_rootTransA = &v93->m_rootTransB;
          }
          btPersistentManifold::refreshContactPoints(p_m_rootTransB, p_m_rootTransA, v93->m_manifoldPtr);
        }
      }
    }
  }
}
