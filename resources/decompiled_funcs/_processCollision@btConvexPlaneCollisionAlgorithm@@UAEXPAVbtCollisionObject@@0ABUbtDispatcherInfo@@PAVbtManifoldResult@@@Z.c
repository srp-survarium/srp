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
  float v8; // eax
  btCollisionShape *m_collisionShape; // ebx
  btTransform *p_m_worldTransform; // edi
  const btVector3 *v11; // ebx
  btTransform *v12; // esi
  float *v13; // eax
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm0_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm7_4
  float v22; // xmm2_4
  float v23; // xmm7_4
  float v24; // xmm2_4
  float v25; // xmm7_4
  float v26; // xmm2_4
  float v27; // xmm7_4
  float v28; // xmm2_4
  float v29; // xmm7_4
  float v30; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float *v33; // eax
  float v34; // xmm3_4
  float v35; // xmm2_4
  float v36; // xmm1_4
  float v37; // xmm5_4
  float v38; // xmm4_4
  float v39; // xmm0_4
  float v40; // xmm0_4
  float v41; // xmm4_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm3_4
  float v45; // xmm0_4
  float v46; // xmm1_4
  float v47; // xmm2_4
  float v48; // xmm0_4
  float v49; // xmm5_4
  float v50; // xmm7_4
  float v51; // xmm1_4
  float v52; // xmm2_4
  float v53; // xmm6_4
  float v54; // xmm1_4
  float v55; // xmm2_4
  float v56; // xmm6_4
  float v57; // xmm7_4
  float v58; // xmm2_4
  float v59; // xmm6_4
  float v60; // xmm7_4
  float v61; // xmm6_4
  float v62; // xmm7_4
  float v63; // xmm6_4
  float v64; // xmm7_4
  float v65; // xmm6_4
  float v66; // xmm0_4
  float v67; // xmm4_4
  void (__stdcall *v68)(btVector3 *, btVector3 *); // edx
  float v69; // xmm0_4
  float v70; // xmm1_4
  float v71; // xmm2_4
  float v72; // xmm0_4
  float v73; // xmm4_4
  float v74; // xmm1_4
  float v75; // xmm5_4
  float v76; // xmm2_4
  float v77; // xmm3_4
  btPersistentManifold *m_manifoldPtr; // eax
  float v79; // xmm1_4
  float v80; // xmm0_4
  float v81; // xmm5_4
  float v82; // xmm4_4
  float m_contactBreakingThreshold; // xmm1_4
  float v84; // xmm4_4
  btManifoldResult *v85; // edi
  float v86; // xmm1_4
  float v87; // xmm2_4
  float v88; // xmm3_4
  void (__thiscall *addContactPoint)(struct btManifoldResult *, const btVector3 *, const btVector3 *, float); // edx
  float v90; // xmm5_4
  float v91; // xmm4_4
  float v92; // xmm2_4
  float v93; // xmm1_4
  __m128i si128; // xmm0
  float v95; // esi
  long double v96; // st7
  float v97; // xmm0_4
  long double v98; // st7
  long double v99; // st7
  int m_numPerturbationIterations; // eax
  float v101; // xmm1_4
  float v102; // xmm2_4
  float v103; // xmm3_4
  btConvexPlaneCollisionAlgorithm *v104; // esi
  btPersistentManifold *v105; // eax
  btPersistentManifold *_X; // [esp+C6Ch] [ebp-124h]
  btManifoldResult *v107; // [esp+C70h] [ebp-120h]
  float v108; // [esp+C88h] [ebp-108h]
  int i; // [esp+C88h] [ebp-108h]
  float angle; // [esp+C8Ch] [ebp-104h] BYREF
  btVector3 axis; // [esp+C90h] [ebp-100h] BYREF
  btQuaternion v112; // [esp+CA8h] [ebp-E8h] BYREF
  float v113; // [esp+CB8h] [ebp-D8h]
  float v114; // [esp+CBCh] [ebp-D4h]
  btConvexPlaneCollisionAlgorithm *v115; // [esp+CCCh] [ebp-C4h]
  float v116; // [esp+CD0h] [ebp-C0h]
  float v117; // [esp+CD4h] [ebp-BCh]
  float v118; // [esp+CD8h] [ebp-B8h]
  float v119; // [esp+CDCh] [ebp-B4h]
  float v120; // [esp+CE0h] [ebp-B0h]
  float v121; // [esp+CE4h] [ebp-ACh]
  float v122; // [esp+CE8h] [ebp-A8h]
  float v123; // [esp+CECh] [ebp-A4h]
  float v124; // [esp+CF0h] [ebp-A0h]
  float v125; // [esp+CF4h] [ebp-9Ch]
  float v126; // [esp+CF8h] [ebp-98h]
  float v127; // [esp+CFCh] [ebp-94h]
  float v128; // [esp+D00h] [ebp-90h]
  float v129; // [esp+D04h] [ebp-8Ch]
  float v130; // [esp+D08h] [ebp-88h]
  float v131; // [esp+D0Ch] [ebp-84h]
  float v132; // [esp+D10h] [ebp-80h]
  float v133; // [esp+D14h] [ebp-7Ch]
  float v134; // [esp+D18h] [ebp-78h]
  float v135; // [esp+D1Ch] [ebp-74h]
  btMatrix3x3 v136; // [esp+D20h] [ebp-70h] BYREF
  btTransform v137; // [esp+D50h] [ebp-40h] BYREF

  v5 = this->m_manifoldPtr == 0;
  v115 = this;
  if ( !v5 )
  {
    v6 = body1;
    if ( this->m_isSwapped )
    {
      v7 = body0;
    }
    else
    {
      v6 = body0;
      v7 = body1;
    }
    v8 = *(float *)&v6->m_collisionShape;
    m_collisionShape = v7->m_collisionShape;
    p_m_worldTransform = &v6->m_worldTransform;
    v112.m_floats[1] = v8;
    angle = *(float *)&m_collisionShape;
    v11 = (const btVector3 *)&m_collisionShape[4];
    v12 = &v7->m_worldTransform;
    v13 = (float *)btTransform::inverse(p_m_worldTransform, &v137);
    v14 = v12->m_basis.m_el[2].mVec128.m128_f32[2];
    v15 = v12->m_basis.m_el[1].mVec128.m128_f32[2];
    v16 = v12->m_basis.m_el[0].mVec128.m128_f32[2];
    v17 = v12->m_basis.m_el[2].mVec128.m128_f32[1];
    v18 = v12->m_basis.m_el[1].mVec128.m128_f32[1];
    v19 = (float)(v13[9] * v18) + (float)(v13[10] * v17);
    v135 = (float)((float)(v13[9] * v15) + (float)(v13[10] * v14)) + (float)(v16 * v13[8]);
    v20 = v12->m_basis.m_el[0].mVec128.m128_f32[1];
    v21 = v13[9];
    v128 = v19 + (float)(v20 * v13[8]);
    v22 = (float)((float)(v21 * v12->m_basis.m_el[1].mVec128.m128_f32[0])
                + (float)(v13[10] * v12->m_basis.m_el[2].mVec128.m128_f32[0]))
        + (float)(v13[8] * v12->m_basis.m_el[0].mVec128.m128_f32[0]);
    v23 = v13[6];
    v126 = v22;
    v24 = (float)((float)(v13[5] * v15) + (float)(v23 * v14)) + (float)(v16 * v13[4]);
    v25 = v13[6];
    v131 = v24;
    v26 = (float)((float)(v13[5] * v18) + (float)(v25 * v17)) + (float)(v20 * v13[4]);
    v27 = v13[5];
    v123 = v26;
    v28 = (float)((float)(v27 * v12->m_basis.m_el[1].mVec128.m128_f32[0])
                + (float)(v13[6] * v12->m_basis.m_el[2].mVec128.m128_f32[0]))
        + (float)(v13[4] * v12->m_basis.m_el[0].mVec128.m128_f32[0]);
    v29 = v13[1];
    v129 = v28;
    v117 = v13[2];
    v30 = *v13;
    v127 = (float)((float)(v16 * *v13) + (float)(v15 * v29)) + (float)(v14 * v117);
    v31 = (float)((float)(v20 * v30) + (float)(v18 * v29)) + (float)(v17 * v117);
    v32 = (float)((float)(v30 * v12->m_basis.m_el[0].mVec128.m128_f32[0])
                + (float)(v29 * v12->m_basis.m_el[1].mVec128.m128_f32[0]))
        + (float)(v117 * v12->m_basis.m_el[2].mVec128.m128_f32[0]);
    v125 = v31;
    v132 = v32;
    v33 = (float *)btTransform::inverse(v12, &v137);
    v34 = p_m_worldTransform->m_origin.mVec128.m128_f32[0];
    v35 = p_m_worldTransform->m_origin.mVec128.m128_f32[1];
    v36 = p_m_worldTransform->m_origin.mVec128.m128_f32[2];
    v37 = v33[1];
    v38 = v33[2];
    v39 = v34 * *v33;
    v118 = *v33;
    v120 = v37;
    v112.m_floats[2] = (float)((float)(v39 + (float)(v35 * v37)) + (float)(v36 * v38)) + v33[12];
    v40 = v33[5] * v35;
    v121 = v38;
    v41 = p_m_worldTransform->m_basis.m_el[1].mVec128.m128_f32[2];
    v112.m_floats[3] = (float)((float)(v40 + (float)(v33[6] * v36)) + (float)(v33[4] * v34)) + v33[13];
    v42 = (float)(v33[9] * v35) + (float)(v33[10] * v36);
    v43 = v33[8] * v34;
    v44 = p_m_worldTransform->m_basis.m_el[2].mVec128.m128_f32[2];
    v45 = (float)(v42 + v43) + v33[14];
    v46 = (float)(v33[9] * v41) + (float)(v33[10] * v44);
    v47 = v33[8];
    v113 = v45;
    v48 = p_m_worldTransform->m_basis.m_el[0].mVec128.m128_f32[2];
    v49 = p_m_worldTransform->m_basis.m_el[2].mVec128.m128_f32[1];
    v50 = v33[9];
    v122 = p_m_worldTransform->m_basis.m_el[1].mVec128.m128_f32[1];
    v51 = v46 + (float)(v47 * v48);
    v52 = (float)(v33[9] * v122) + (float)(v33[10] * v49);
    v53 = v33[8];
    v119 = v51;
    v54 = p_m_worldTransform->m_basis.m_el[0].mVec128.m128_f32[1];
    v55 = v52 + (float)(v53 * v54);
    v56 = p_m_worldTransform->m_basis.m_el[1].mVec128.m128_f32[0];
    v116 = v50 * v56;
    v57 = v33[10];
    v117 = v56;
    v124 = v55;
    v108 = p_m_worldTransform->m_basis.m_el[2].mVec128.m128_f32[0];
    v58 = p_m_worldTransform->m_basis.m_el[0].mVec128.m128_f32[0];
    v59 = (float)(v116 + (float)(v57 * v108))
        + (float)(v33[8] * p_m_worldTransform->m_basis.m_el[0].mVec128.m128_f32[0]);
    v60 = v33[6];
    v133 = v59;
    v61 = (float)((float)(v33[5] * v41) + (float)(v60 * v44)) + (float)(v33[4] * v48);
    v62 = v33[6];
    v134 = v61;
    v63 = (float)((float)(v33[5] * v122) + (float)(v62 * v49)) + (float)(v33[4] * v54);
    v64 = v33[6] * v108;
    v130 = v63;
    v116 = v33[5] * v117;
    v116 = (float)(v116 + v64) + (float)(v33[4] * v58);
    v65 = v120;
    v66 = (float)(v48 * v118) + (float)(v41 * v120);
    v67 = v121;
    v120 = v66 + (float)(v44 * v121);
    v121 = (float)((float)(v54 * v118) + (float)(v122 * v65)) + (float)(v49 * v121);
    v68 = *(void (__stdcall **)(btVector3 *, btVector3 *))(*(_DWORD *)LODWORD(v112.m_floats[1]) + 56);
    v69 = -v11->mVec128.m128_f32[0];
    v70 = -v11->mVec128.m128_f32[1];
    v118 = (float)((float)(v58 * v118) + (float)(v117 * v65)) + (float)(v108 * v67);
    v71 = -v11->mVec128.m128_f32[2];
    axis.mVec128.m128_f32[0] = (float)((float)(v69 * v132) + (float)(v70 * v125)) + (float)(v71 * v127);
    axis.mVec128.m128_f32[2] = (float)((float)(v69 * v126) + (float)(v71 * v135)) + (float)(v70 * v128);
    axis.mVec128.m128_f32[1] = (float)((float)(v69 * v129) + (float)(v71 * v131)) + (float)(v70 * v123);
    axis.mVec128.m128_i32[3] = 0;
    v68(&v136.m_el[1], &axis);
    v72 = (float)((float)((float)(v136.m_el[1].mVec128.m128_f32[1] * v121)
                        + (float)(v136.m_el[1].mVec128.m128_f32[2] * v120))
                + (float)(v136.m_el[1].mVec128.m128_f32[0] * v118))
        + v112.m_floats[2];
    v73 = v11->mVec128.m128_f32[2];
    v74 = (float)((float)((float)(v136.m_el[1].mVec128.m128_f32[2] * v134)
                        + (float)(v136.m_el[1].mVec128.m128_f32[1] * v130))
                + (float)(v136.m_el[1].mVec128.m128_f32[0] * v116))
        + v112.m_floats[3];
    v75 = v11->mVec128.m128_f32[1];
    v76 = (float)((float)((float)(v74 * v75)
                        + (float)((float)((float)((float)((float)(v136.m_el[1].mVec128.m128_f32[0] * v133)
                                                        + (float)(v136.m_el[1].mVec128.m128_f32[1] * v124))
                                                + (float)(v136.m_el[1].mVec128.m128_f32[2] * v119))
                                        + v113)
                                * v73))
                + (float)(v72 * v11->mVec128.m128_f32[0]))
        - *(float *)(LODWORD(angle) + 64);
    v77 = (float)((float)((float)((float)(v136.m_el[1].mVec128.m128_f32[0] * v133)
                                + (float)(v136.m_el[1].mVec128.m128_f32[1] * v124))
                        + (float)(v136.m_el[1].mVec128.m128_f32[2] * v119))
                + v113)
        - (float)(v73 * v76);
    m_manifoldPtr = v115->m_manifoldPtr;
    v79 = v74 - (float)(v75 * v76);
    v80 = v72 - (float)(v11->mVec128.m128_f32[0] * v76);
    v81 = v12->m_basis.m_el[1].mVec128.m128_f32[1];
    v112.m_floats[2] = (float)((float)((float)(v12->m_basis.m_el[0].mVec128.m128_f32[2] * v77)
                                     + (float)(v12->m_basis.m_el[0].mVec128.m128_f32[1] * v79))
                             + (float)(v80 * v12->m_basis.m_el[0].mVec128.m128_f32[0]))
                     + v12->m_origin.mVec128.m128_f32[0];
    v112.m_floats[3] = (float)((float)((float)(v12->m_basis.m_el[1].mVec128.m128_f32[2] * v77) + (float)(v81 * v79))
                             + (float)(v12->m_basis.m_el[1].mVec128.m128_f32[0] * v80))
                     + v12->m_origin.mVec128.m128_f32[1];
    v82 = (float)((float)(v12->m_basis.m_el[2].mVec128.m128_f32[2] * v77)
                + (float)(v12->m_basis.m_el[2].mVec128.m128_f32[1] * v79))
        + (float)(v12->m_basis.m_el[2].mVec128.m128_f32[0] * v80);
    m_contactBreakingThreshold = m_manifoldPtr->m_contactBreakingThreshold;
    v84 = v82 + v12->m_origin.mVec128.m128_f32[2];
    angle = v76;
    v113 = v84;
    v114 = 0.0;
    v85 = resultOut;
    resultOut->m_manifoldPtr = m_manifoldPtr;
    if ( m_contactBreakingThreshold > v76 )
    {
      v86 = v11->mVec128.m128_f32[2];
      v87 = v11->mVec128.m128_f32[1];
      v88 = v11->mVec128.m128_f32[0];
      addContactPoint = resultOut->addContactPoint;
      v90 = v12->m_basis.m_el[1].mVec128.m128_f32[2];
      axis.mVec128.m128_f32[0] = (float)((float)(v12->m_basis.m_el[0].mVec128.m128_f32[1] * v87)
                                       + (float)(v12->m_basis.m_el[0].mVec128.m128_f32[2] * v86))
                               + (float)(v12->m_basis.m_el[0].mVec128.m128_f32[0] * v11->mVec128.m128_f32[0]);
      axis.mVec128.m128_f32[1] = (float)((float)(v12->m_basis.m_el[1].mVec128.m128_f32[1] * v87) + (float)(v90 * v86))
                               + (float)(v12->m_basis.m_el[1].mVec128.m128_f32[0] * v88);
      v91 = v12->m_basis.m_el[2].mVec128.m128_f32[1] * v87;
      v92 = v12->m_basis.m_el[2].mVec128.m128_f32[2] * v86;
      v93 = v12->m_basis.m_el[2].mVec128.m128_f32[0] * v88;
      axis.mVec128.m128_i32[3] = 0;
      si128 = _mm_load_si128((const __m128i *)&v112.m_floats[2]);
      axis.mVec128.m128_f32[2] = (float)(v91 + v92) + v93;
      v136.m_el[0] = (btVector3)si128;
      ((void (__thiscall *)(btManifoldResult *, btVector3 *, btMatrix3x3 *, _DWORD))addContactPoint)(
        resultOut,
        &axis,
        &v136,
        LODWORD(angle));
    }
    v95 = v112.m_floats[1];
    if ( *(int *)(LODWORD(v112.m_floats[1]) + 4) < 7
      && resultOut->m_manifoldPtr->m_cachedPoints < v115->m_minimumPointsPerturbationThreshold )
    {
      angle = v11->mVec128.m128_f32[2];
      if ( fabsf(angle) <= hsqt2 )
      {
        v97 = v11->mVec128.m128_f32[1];
        v119 = v11->mVec128.m128_f32[0];
        v98 = 1.0 / sqrtf((float)(v119 * v119) + (float)(v97 * v97));
        angle = v98;
        v99 = v98 * v11->mVec128.m128_f32[1];
        axis.mVec128.m128_f32[1] = angle * v119;
        axis.mVec128.m128_i32[2] = 0;
        axis.mVec128.m128_f32[0] = -v99;
      }
      else
      {
        v96 = 1.0
            / sqrtf(
                (float)(v11->mVec128.m128_f32[1] * v11->mVec128.m128_f32[1])
              + (float)(v11->mVec128.m128_f32[2] * v11->mVec128.m128_f32[2]));
        axis.mVec128.m128_i32[0] = 0;
        axis.mVec128.m128_f32[1] = -(angle * v96);
        axis.mVec128.m128_f32[2] = v96 * v11->mVec128.m128_f32[1];
      }
      angle = ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)LODWORD(v95) + 12))(LODWORD(v95));
      v112.m_floats[1] = gContactBreakingThreshold / angle;
      if ( (float)(gContactBreakingThreshold / angle) > 0.39269909 )
        v112.m_floats[1] = 0.39269909;
      btQuaternion::setRotation((btQuaternion *)&v112.m_floats[2], &axis, &v112.m_floats[1]);
      m_numPerturbationIterations = v115->m_numPerturbationIterations;
      for ( i = 0; i < m_numPerturbationIterations; ++i )
      {
        angle = (float)(6.2831855 / (float)m_numPerturbationIterations) * (float)i;
        btQuaternion::setRotation((btQuaternion *)&axis, v11, &angle);
        v101 = (float)((float)((float)(v113 * COERCE_FLOAT(axis.mVec128.m128_i32[1] ^ 0x80000000))
                             + (float)(v114 * COERCE_FLOAT(axis.mVec128.m128_i32[0] ^ 0x80000000)))
                     + (float)(axis.mVec128.m128_f32[3] * v112.m_floats[2]))
             - (float)(v112.m_floats[3] * COERCE_FLOAT(axis.mVec128.m128_i32[2] ^ 0x80000000));
        v136.m_el[2].mVec128.m128_i32[2] = axis.mVec128.m128_i32[2] ^ 0x80000000;
        v102 = (float)((float)((float)(v112.m_floats[3] * axis.mVec128.m128_f32[3])
                             + (float)(v114 * COERCE_FLOAT(axis.mVec128.m128_i32[1] ^ 0x80000000)))
                     + (float)(COERCE_FLOAT(axis.mVec128.m128_i32[2] ^ 0x80000000) * v112.m_floats[2]))
             - (float)(v113 * COERCE_FLOAT(axis.mVec128.m128_i32[0] ^ 0x80000000));
        v103 = (float)((float)((float)(v113 * axis.mVec128.m128_f32[3])
                             + (float)(v114 * COERCE_FLOAT(axis.mVec128.m128_i32[2] ^ 0x80000000)))
                     + (float)(v112.m_floats[3] * COERCE_FLOAT(axis.mVec128.m128_i32[0] ^ 0x80000000)))
             - (float)(COERCE_FLOAT(axis.mVec128.m128_i32[1] ^ 0x80000000) * v112.m_floats[2]);
        v136.m_el[0].mVec128.m128_f32[0] = (float)((float)((float)(v102 * axis.mVec128.m128_f32[2])
                                                         + (float)(axis.mVec128.m128_f32[3] * v101))
                                                 + (float)((float)((float)((float)((float)(v114
                                                                                         * axis.mVec128.m128_f32[3])
                                                                                 - (float)(COERCE_FLOAT(
                                                                                             axis.mVec128.m128_i32[0]
                                                                                           ^ 0x80000000)
                                                                                         * v112.m_floats[2]))
                                                                         - (float)(v112.m_floats[3]
                                                                                 * COERCE_FLOAT(
                                                                                     axis.mVec128.m128_i32[1]
                                                                                   ^ 0x80000000)))
                                                                 - (float)(v113
                                                                         * COERCE_FLOAT(axis.mVec128.m128_i32[2] ^ 0x80000000)))
                                                         * axis.mVec128.m128_f32[0]))
                                         - (float)(v103 * axis.mVec128.m128_f32[1]);
        v104 = v115;
        v136.m_el[0].mVec128.m128_f32[1] = (float)((float)((float)(v102 * axis.mVec128.m128_f32[3])
                                                         + (float)((float)((float)((float)((float)(v114
                                                                                                 * axis.mVec128.m128_f32[3])
                                                                                         - (float)(COERCE_FLOAT(axis.mVec128.m128_i32[0] ^ 0x80000000)
                                                                                                 * v112.m_floats[2]))
                                                                                 - (float)(v112.m_floats[3]
                                                                                         * COERCE_FLOAT(
                                                                                             axis.mVec128.m128_i32[1]
                                                                                           ^ 0x80000000)))
                                                                         - (float)(v113
                                                                                 * COERCE_FLOAT(
                                                                                     axis.mVec128.m128_i32[2]
                                                                                   ^ 0x80000000)))
                                                                 * axis.mVec128.m128_f32[1]))
                                                 + (float)(v103 * axis.mVec128.m128_f32[0]))
                                         - (float)(axis.mVec128.m128_f32[2] * v101);
        v136.m_el[0].mVec128.m128_f32[2] = (float)((float)((float)(v103 * axis.mVec128.m128_f32[3])
                                                         + (float)((float)((float)((float)((float)(v114
                                                                                                 * axis.mVec128.m128_f32[3])
                                                                                         - (float)(COERCE_FLOAT(axis.mVec128.m128_i32[0] ^ 0x80000000)
                                                                                                 * v112.m_floats[2]))
                                                                                 - (float)(v112.m_floats[3]
                                                                                         * COERCE_FLOAT(
                                                                                             axis.mVec128.m128_i32[1]
                                                                                           ^ 0x80000000)))
                                                                         - (float)(v113
                                                                                 * COERCE_FLOAT(
                                                                                     axis.mVec128.m128_i32[2]
                                                                                   ^ 0x80000000)))
                                                                 * axis.mVec128.m128_f32[2]))
                                                 + (float)(axis.mVec128.m128_f32[1] * v101))
                                         - (float)(v102 * axis.mVec128.m128_f32[0]);
        v136.m_el[0].mVec128.m128_f32[3] = (float)((float)((float)((float)((float)((float)((float)(v114
                                                                                                 * axis.mVec128.m128_f32[3])
                                                                                         - (float)(COERCE_FLOAT(axis.mVec128.m128_i32[0] ^ 0x80000000)
                                                                                                 * v112.m_floats[2]))
                                                                                 - (float)(v112.m_floats[3]
                                                                                         * COERCE_FLOAT(
                                                                                             axis.mVec128.m128_i32[1]
                                                                                           ^ 0x80000000)))
                                                                         - (float)(v113
                                                                                 * COERCE_FLOAT(
                                                                                     axis.mVec128.m128_i32[2]
                                                                                   ^ 0x80000000)))
                                                                 * axis.mVec128.m128_f32[3])
                                                         - (float)(v101 * axis.mVec128.m128_f32[0]))
                                                 - (float)(v102 * axis.mVec128.m128_f32[1]))
                                         - (float)(v103 * axis.mVec128.m128_f32[2]);
        btConvexPlaneCollisionAlgorithm::collideSingleContact(body0, body1, v115, &v136, resultOut, v107);
        m_numPerturbationIterations = v104->m_numPerturbationIterations;
      }
      v85 = resultOut;
    }
    if ( v115->m_ownManifold )
    {
      if ( v115->m_manifoldPtr->m_cachedPoints )
      {
        v105 = v85->m_manifoldPtr;
        if ( v105->m_cachedPoints )
        {
          _X = v85->m_manifoldPtr;
          if ( v105->m_body0 == v85->m_body0 )
            btPersistentManifold::refreshContactPoints(_X, &v85->m_rootTransA, &v85->m_rootTransB);
          else
            btPersistentManifold::refreshContactPoints(_X, &v85->m_rootTransB, &v85->m_rootTransA);
        }
      }
    }
  }
}
