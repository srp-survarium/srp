void __usercall btDiscreteDynamicsWorld::debugDrawConstraint(
        btDiscreteDynamicsWorld *this@<edi>,
        btTypedConstraint *constraint@<eax>,
        double a3@<st1>)
{
  btIDebugDraw *v4; // eax
  bool v5; // bl
  btIDebugDraw *v6; // eax
  __int16 v7; // ax
  btHingeConstraint *v8; // ecx
  float m_dbgDrawSize; // xmm1_4
  float *m_rbA; // eax
  unsigned __int64 v11; // xmm1_8
  float v12; // xmm4_4
  btDiscreteDynamicsWorld_vtbl *v13; // edx
  float v14; // xmm5_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  unsigned int v17; // xmm4_4
  btIDebugDraw *(__thiscall *getDebugDrawer)(struct btDiscreteDynamicsWorld *); // eax
  int v19; // eax
  unsigned __int64 v20; // xmm0_8
  float *m_rbB; // esi
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm4_4
  btIDebugDraw *v25; // eax
  float *v26; // eax
  float m_appliedImpulse; // xmm4_4
  btTypedConstraint_vtbl *v28; // xmm5_4
  float v29; // xmm3_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm6_4
  float v33; // xmm7_4
  float v34; // xmm6_4
  float v35; // xmm4_4
  float v36; // xmm7_4
  int m_userConstraintType; // xmm6_4
  btRigidBody *v38; // xmm5_4
  unsigned int v39; // xmm7_4
  float v40; // xmm4_4
  unsigned int v41; // xmm4_4
  unsigned int v42; // xmm5_4
  float m_breakingImpulseThreshold; // xmm6_4
  float v44; // xmm7_4
  float v45; // xmm7_4
  float v46; // xmm6_4
  float v47; // xmm7_4
  float v48; // xmm6_4
  float v49; // xmm7_4
  float v50; // xmm6_4
  float v51; // xmm7_4
  float v52; // xmm6_4
  btIDebugDraw *v53; // eax
  float *v54; // eax
  float v55; // xmm1_4
  float v56; // xmm5_4
  float v57; // xmm3_4
  btRigidBody *v58; // xmm4_4
  float v59; // xmm2_4
  float v60; // xmm7_4
  float v61; // xmm6_4
  float v62; // xmm5_4
  float v63; // xmm6_4
  float v64; // xmm5_4
  float v65; // xmm7_4
  float v66; // xmm7_4
  float v67; // xmm6_4
  float v68; // xmm4_4
  int v69; // xmm5_4
  unsigned int v70; // xmm7_4
  float v71; // xmm4_4
  unsigned int v72; // xmm4_4
  unsigned int v73; // xmm5_4
  btTypedConstraint_vtbl *v74; // xmm6_4
  float v75; // xmm7_4
  float v76; // xmm7_4
  int m_objectType; // xmm6_4
  float v78; // xmm7_4
  btTypedConstraint_vtbl *v79; // xmm6_4
  float v80; // xmm7_4
  float v81; // xmm6_4
  btIDebugDraw *v82; // eax
  btHingeConstraint *v83; // ecx
  float UpperLimit; // xmm0_4
  btIDebugDraw *(__thiscall *v85)(struct btDiscreteDynamicsWorld *); // edx
  int v86; // eax
  float *v87; // eax
  float v88; // xmm3_4
  float v89; // xmm1_4
  float v90; // xmm2_4
  btRigidBody *v91; // xmm4_4
  float v92; // xmm5_4
  btRigidBody *v93; // xmm6_4
  float v94; // xmm7_4
  btTypedConstraint_vtbl *v95; // xmm6_4
  float v96; // xmm5_4
  btRigidBody *v97; // xmm7_4
  unsigned int v98; // xmm4_4
  unsigned int v99; // xmm5_4
  float v100; // xmm6_4
  float v101; // xmm7_4
  float v102; // xmm6_4
  float v103; // xmm7_4
  int m_userConstraintId; // xmm6_4
  float v105; // xmm7_4
  float v106; // xmm6_4
  float v107; // xmm7_4
  int v108; // xmm6_4
  float v109; // xmm7_4
  float v110; // xmm6_4
  btIDebugDraw *v111; // eax
  float *v112; // eax
  int v113; // xmm4_4
  float v114; // xmm3_4
  float v115; // xmm1_4
  float v116; // xmm2_4
  float v117; // xmm5_4
  float v118; // xmm7_4
  float v119; // xmm7_4
  int v120; // xmm6_4
  float v121; // xmm4_4
  float v122; // xmm7_4
  btTypedConstraint_vtbl *v123; // xmm5_4
  unsigned int v124; // xmm7_4
  float v125; // xmm4_4
  float v126; // xmm6_4
  unsigned int v127; // xmm4_4
  unsigned int v128; // xmm5_4
  float v129; // xmm6_4
  float v130; // xmm7_4
  btTypedConstraint_vtbl *v131; // xmm6_4
  float v132; // xmm7_4
  float v133; // xmm6_4
  float v134; // xmm7_4
  float v135; // xmm6_4
  float v136; // xmm6_4
  btIDebugDraw *v137; // eax
  int v138; // ebx
  btIDebugDraw *(__thiscall *v139)(struct btDiscreteDynamicsWorld *); // eax
  int v140; // eax
  btIDebugDraw *v141; // eax
  float *v142; // eax
  float v143; // xmm4_4
  int v144; // xmm3_4
  float v145; // xmm0_4
  float v146; // xmm1_4
  int v147; // xmm5_4
  float v148; // xmm2_4
  float v149; // xmm7_4
  float v150; // xmm6_4
  float v151; // xmm7_4
  float v152; // xmm3_4
  float v153; // xmm6_4
  float v154; // xmm5_4
  btTypedConstraint_vtbl *v155; // xmm4_4
  float v156; // xmm6_4
  btRigidBody *v157; // xmm5_4
  int v158; // xmm7_4
  int v159; // xmm6_4
  unsigned int v160; // xmm3_4
  unsigned int v161; // xmm4_4
  unsigned int v162; // xmm5_4
  btTypedConstraint_vtbl *v163; // xmm6_4
  float v164; // xmm7_4
  float v165; // xmm6_4
  float v166; // xmm7_4
  float v167; // xmm6_4
  float v168; // xmm7_4
  float v169; // xmm6_4
  float v170; // xmm7_4
  float v171; // xmm6_4
  __m128i v172; // xmm1
  float *v173; // eax
  btRigidBody *v174; // xmm4_4
  btRigidBody *v175; // xmm5_4
  float v176; // xmm1_4
  float v177; // xmm2_4
  float v178; // xmm3_4
  float v179; // xmm0_4
  float v180; // xmm7_4
  int v181; // xmm6_4
  float v182; // xmm7_4
  float v183; // xmm6_4
  btTypedConstraint_vtbl *v184; // xmm4_4
  float v185; // xmm3_4
  btRigidBody *v186; // xmm5_4
  float v187; // xmm6_4
  float v188; // xmm3_4
  float v189; // xmm6_4
  float v190; // xmm7_4
  int v191; // xmm5_4
  float v192; // xmm6_4
  float v193; // xmm7_4
  float v194; // xmm6_4
  int v195; // xmm5_4
  float v196; // xmm7_4
  float v197; // xmm6_4
  float v198; // xmm7_4
  float v199; // xmm6_4
  float v200; // xmm5_4
  float v201; // xmm7_4
  float v202; // xmm6_4
  float v203; // xmm5_4
  float v204; // xmm6_4
  float v205; // xmm7_4
  float v206; // xmm5_4
  float v207; // xmm7_4
  int v208; // xmm5_4
  btRigidBody *v209; // xmm6_4
  float v210; // xmm7_4
  float v211; // xmm4_4
  float v212; // xmm6_4
  float v213; // xmm0_4
  float v214; // xmm2_4
  btIDebugDraw *(__thiscall *v215)(struct btDiscreteDynamicsWorld *); // eax
  int v216; // eax
  btIDebugDraw *v217; // eax
  btIDebugDraw *v218; // eax
  double v219; // st7
  double v220; // st7
  __int64 v221; // xmm1_8
  btDiscreteDynamicsWorld_vtbl *v222; // eax
  btIDebugDraw *(__thiscall *v223)(struct btDiscreteDynamicsWorld *); // edx
  btRigidBody *v224; // xmm0_4
  int v225; // eax
  __m128 v226; // xmm0
  long double v227; // st7
  float v228; // xmm5_4
  float v229; // xmm4_4
  int v230; // xmm1_4
  btTypedConstraint_vtbl *v231; // xmm0_4
  btIDebugDraw *v232; // eax
  btDiscreteDynamicsWorld_vtbl *v233; // eax
  btIDebugDraw *(__thiscall *v234)(struct btDiscreteDynamicsWorld *); // edx
  int v235; // eax
  btIDebugDraw *v236; // eax
  btIDebugDraw *v237; // eax
  __m128i *p_m_appliedImpulse; // eax
  float v239; // xmm4_4
  btIDebugDraw *(__thiscall *v240)(struct btDiscreteDynamicsWorld *); // edx
  float v241; // xmm1_4
  float v242; // xmm3_4
  float v243; // xmm7_4
  btRigidBody *v244; // xmm4_4
  float v245; // xmm2_4
  float v246; // xmm3_4
  int v247; // eax
  btDiscreteDynamicsWorld_vtbl *v248; // eax
  btIDebugDraw *(__thiscall *v249)(struct btDiscreteDynamicsWorld *); // edx
  int v250; // eax
  const float *v251; // [esp+3E0Eh] [ebp-1F0h]
  float xz[4]; // [esp+3E16h] [ebp-1E8h] BYREF
  float yy[2]; // [esp+3E26h] [ebp-1D8h] BYREF
  float yx[4]; // [esp+3E2Eh] [ebp-1D0h] BYREF
  btVector3 result; // [esp+3E3Eh] [ebp-1C0h] BYREF
  btRigidBody *m_appliedImpulse_low; // [esp+3E52h] [ebp-1ACh]
  _QWORD yz[2]; // [esp+3E56h] [ebp-1A8h] BYREF
  __int64 v258; // [esp+3E66h] [ebp-198h]
  __m128i v259; // [esp+3E6Eh] [ebp-190h] BYREF
  __m128i v260; // [esp+3E7Eh] [ebp-180h] BYREF
  __int64 v261; // [esp+3E8Eh] [ebp-170h]
  __int64 v262; // [esp+3E96h] [ebp-168h]
  btVector3 v263; // [esp+3E9Eh] [ebp-160h] BYREF
  __m128i v264; // [esp+3EAEh] [ebp-150h] BYREF
  __m128i v265; // [esp+3EBEh] [ebp-140h]
  __m128i v266; // [esp+3ECEh] [ebp-130h]
  __m128i si128; // [esp+3EDEh] [ebp-120h] BYREF
  __m128i v268; // [esp+3EEEh] [ebp-110h] BYREF
  btMatrix3x3 v269; // [esp+3F06h] [ebp-F8h] BYREF
  float v270; // [esp+3F36h] [ebp-C8h]
  int v271; // [esp+3F3Ah] [ebp-C4h]
  float xy; // [esp+3F4Ah] [ebp-B4h] BYREF
  _DWORD v273[4]; // [esp+3F4Eh] [ebp-B0h] BYREF
  _QWORD v274[2]; // [esp+3F5Eh] [ebp-A0h] BYREF
  _DWORD v275[10]; // [esp+3F6Eh] [ebp-90h] BYREF
  __int128 v276; // [esp+3F96h] [ebp-68h] BYREF
  int v277; // [esp+3FA6h] [ebp-58h]
  int v278; // [esp+3FAAh] [ebp-54h]
  int v279; // [esp+3FAEh] [ebp-50h] BYREF
  int v280; // [esp+3FB2h] [ebp-4Ch]
  int v281; // [esp+3FB6h] [ebp-48h]
  int v282; // [esp+3FBAh] [ebp-44h]
  __m128i v283; // [esp+3FBEh] [ebp-40h] BYREF
  _DWORD v284[4]; // [esp+3FCEh] [ebp-30h] BYREF
  _DWORD v285[4]; // [esp+3FDEh] [ebp-20h] BYREF
  _QWORD v286[2]; // [esp+3FEEh] [ebp-10h] BYREF

  v4 = this->getDebugDrawer(this);
  v5 = (v4->getDebugMode(v4) & 0x800) != 0;
  v6 = this->getDebugDrawer(this);
  v7 = v6->getDebugMode(v6);
  m_dbgDrawSize = constraint->m_dbgDrawSize;
  HIBYTE(yx[0]) = (v7 & 0x1000) != 0;
  yx[1] = m_dbgDrawSize;
  if ( m_dbgDrawSize > 0.0 )
  {
    switch ( constraint->m_objectType )
    {
      case 3:
        m_rbA = (float *)constraint->m_rbA;
        v264.m128i_i64[0] = (unsigned int)clear_value;
        v265.m128i_i32[1] = (int)clear_value;
        v266.m128i_i64[1] = (unsigned int)clear_value;
        v11 = *(_QWORD *)&constraint[8].m_breakingImpulseThreshold;
        si128 = 0u;
        m_rbA += 4;
        v264.m128i_i64[1] = 0;
        v265.m128i_i32[0] = 0;
        v265.m128i_i64[1] = 0;
        v266.m128i_i64[0] = 0;
        v12 = m_rbA[2];
        v13 = this->__vftable;
        v263.mVec128.m128_u64[0] = v11;
        v263.mVec128.m128_u64[1] = *(_QWORD *)&constraint[8].m_rbA;
        v14 = m_rbA[5];
        result.mVec128.m128_f32[0] = (float)((float)((float)(v12 * v263.mVec128.m128_f32[2])
                                                   + (float)(m_rbA[1] * *((float *)&v11 + 1)))
                                           + (float)(*(float *)&v11 * *m_rbA))
                                   + m_rbA[12];
        v15 = (float)(m_rbA[6] * v263.mVec128.m128_f32[2]) + (float)(v14 * *((float *)&v11 + 1));
        v16 = m_rbA[4] * *(float *)&v11;
        *(float *)&v11 = *(float *)&v11 * m_rbA[8];
        result.mVec128.m128_f32[1] = (float)(v15 + v16) + m_rbA[13];
        *(float *)&v17 = (float)((float)((float)(m_rbA[10] * v263.mVec128.m128_f32[2])
                                       + (float)(m_rbA[9] * v263.mVec128.m128_f32[1]))
                               + *(float *)&v11)
                       + m_rbA[14];
        getDebugDrawer = v13->getDebugDrawer;
        result.mVec128.m128_u64[1] = v17;
        si128 = _mm_load_si128((const __m128i *)&result);
        v19 = (int)getDebugDrawer(this);
        (*(void (__thiscall **)(int, __m128i *, _DWORD))(*(_DWORD *)v19 + 56))(v19, &v264, LODWORD(yx[1]));
        v263.mVec128.m128_u64[0] = *(_QWORD *)&constraint[8].m_appliedImpulse;
        v20 = *(_QWORD *)&constraint[9].__vftable;
        m_rbB = (float *)constraint->m_rbB;
        v22 = m_rbB[6];
        v23 = m_rbB[5];
        m_rbB += 4;
        v263.mVec128.m128_u64[1] = v20;
        v24 = m_rbB[5];
        result.mVec128.m128_f32[0] = (float)((float)((float)(v22 * *(float *)&v20)
                                                   + (float)(v23 * v263.mVec128.m128_f32[1]))
                                           + (float)(v263.mVec128.m128_f32[0] * *m_rbB))
                                   + m_rbB[12];
        result.mVec128.m128_f32[1] = (float)((float)((float)(m_rbB[6] * *(float *)&v20)
                                                   + (float)(v24 * v263.mVec128.m128_f32[1]))
                                           + (float)(m_rbB[4] * v263.mVec128.m128_f32[0]))
                                   + m_rbB[13];
        result.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                                       (float)((float)((float)(m_rbB[10] * *(float *)&v20)
                                                     + (float)(m_rbB[9] * v263.mVec128.m128_f32[1]))
                                             + (float)(m_rbB[8] * v263.mVec128.m128_f32[0]))
                                     + m_rbB[14]);
        si128 = _mm_load_si128((const __m128i *)&result);
        if ( v5 )
        {
          v25 = this->getDebugDrawer(this);
          ((void (__thiscall *)(btIDebugDraw *, __m128i *, _DWORD))v25->drawTransform)(v25, &v264, LODWORD(yx[1]));
        }
        return;
      case 4:
        v26 = (float *)constraint->m_rbA;
        m_appliedImpulse = constraint[16].m_appliedImpulse;
        v28 = constraint[17].__vftable;
        v29 = v26[5];
        v30 = v26[4];
        v31 = v26[6];
        v26 += 4;
        v32 = constraint[16].m_dbgDrawSize;
        result.mVec128.m128_f32[0] = (float)((float)((float)(m_appliedImpulse * v30) + (float)(v32 * v29))
                                           + (float)(*(float *)&v28 * v31))
                                   + v26[12];
        v33 = (float)((float)((float)(v26[5] * v32) + (float)(v26[6] * *(float *)&v28))
                    + (float)(m_appliedImpulse * v26[4]))
            + v26[13];
        v34 = constraint[16].m_dbgDrawSize;
        v35 = m_appliedImpulse * v26[8];
        result.mVec128.m128_f32[1] = v33;
        v36 = (float)(v26[9] * v34) + (float)(v26[10] * *(float *)&v28);
        m_userConstraintType = constraint[16].m_userConstraintType;
        v38 = constraint[16].m_rbA;
        *(float *)&v39 = (float)(v36 + v35) + v26[14];
        v40 = v26[9];
        result.mVec128.m128_u64[1] = v39;
        *(float *)&v41 = (float)((float)(v40 * *(float *)&m_userConstraintType) + (float)(v26[10] * *(float *)&v38))
                       + (float)(v26[8] * constraint[15].m_appliedImpulse);
        *(float *)&v42 = (float)((float)(v26[9] * *(float *)&constraint[16].m_objectType)
                               + (float)(v26[10] * *(float *)&constraint[16].m_isEnabled))
                       + (float)(v26[8] * *(float *)&constraint[15].m_rbB);
        m_breakingImpulseThreshold = constraint[16].m_breakingImpulseThreshold;
        yy[1] = v26[9] * *(float *)&constraint[16].__vftable;
        v44 = v26[5];
        yy[0] = (float)(yy[1] + (float)(v26[10] * m_breakingImpulseThreshold))
              + (float)(*(float *)&constraint[15].m_rbA * v26[8]);
        xz[3] = (float)(v44 * *(float *)&constraint[16].m_userConstraintType)
              + (float)(v26[6] * *(float *)&constraint[16].m_rbA);
        v45 = v26[5];
        yx[3] = xz[3] + (float)(v26[4] * constraint[15].m_appliedImpulse);
        v46 = *(float *)&constraint[16].m_isEnabled;
        xz[3] = v45 * *(float *)&constraint[16].m_objectType;
        v47 = v26[4];
        xz[3] = xz[3] + (float)(v26[6] * v46);
        v48 = xz[3] + (float)(v47 * *(float *)&constraint[15].m_rbB);
        v49 = v26[5];
        *(float *)yz = v48;
        v50 = constraint[16].m_breakingImpulseThreshold;
        xz[3] = v49 * *(float *)&constraint[16].__vftable;
        v51 = v26[4];
        xz[3] = xz[3] + (float)(v26[6] * v50);
        yx[2] = xz[3] + (float)(v51 * *(float *)&constraint[15].m_rbA);
        xz[3] = (float)(v30 * constraint[15].m_appliedImpulse)
              + (float)(v29 * *(float *)&constraint[16].m_userConstraintType);
        yy[1] = xz[3] + (float)(v31 * *(float *)&constraint[16].m_rbA);
        xz[3] = (float)(v30 * *(float *)&constraint[15].m_rbB) + (float)(v29 * *(float *)&constraint[16].m_objectType);
        v52 = xz[3] + (float)(v31 * *(float *)&constraint[16].m_isEnabled);
        *(float *)&yz[1] = (float)((float)(v30 * *(float *)&constraint[15].m_rbA)
                                 + (float)(v29 * *(float *)&constraint[16].__vftable))
                         + (float)(v31 * constraint[16].m_breakingImpulseThreshold);
        v258 = LODWORD(yy[1]);
        v259.m128i_i64[0] = __PAIR64__(yz[0], LODWORD(yx[2]));
        v259.m128i_i64[1] = LODWORD(yx[3]);
        v260.m128i_i64[0] = __PAIR64__(v42, LODWORD(yy[0]));
        *((float *)&yz[1] + 1) = v52;
        v264 = _mm_load_si128((const __m128i *)&yz[1]);
        v265 = _mm_load_si128(&v259);
        v260.m128i_i64[1] = v41;
        v266 = _mm_load_si128(&v260);
        si128 = _mm_load_si128((const __m128i *)&result);
        if ( v5 )
        {
          v53 = this->getDebugDrawer(this);
          ((void (__thiscall *)(btIDebugDraw *, __m128i *, _DWORD))v53->drawTransform)(v53, &v264, LODWORD(yx[1]));
        }
        v54 = (float *)constraint->m_rbB;
        v55 = v54[4];
        v56 = *(float *)&constraint[18].m_isEnabled;
        v57 = v54[5];
        v58 = constraint[18].m_rbA;
        v59 = v54[6];
        v54 += 4;
        v60 = (float)((float)((float)(v55 * constraint[18].m_breakingImpulseThreshold) + (float)(v57 * v56))
                    + (float)(v59 * *(float *)&v58))
            + v54[12];
        v61 = v54[5] * v56;
        v62 = v54[6];
        result.mVec128.m128_f32[0] = v60;
        v63 = v61 + (float)(v62 * *(float *)&v58);
        v64 = constraint[18].m_breakingImpulseThreshold;
        v65 = v54[9];
        result.mVec128.m128_f32[1] = (float)(v63 + (float)(v64 * v54[4])) + v54[13];
        v66 = (float)(v65 * *(float *)&constraint[18].m_isEnabled) + (float)(v54[10] * *(float *)&v58);
        v67 = constraint[17].m_appliedImpulse;
        v68 = v54[8] * v64;
        v69 = constraint[18].m_userConstraintType;
        *(float *)&v70 = (float)(v66 + v68) + v54[14];
        v71 = v54[9];
        result.mVec128.m128_u64[1] = v70;
        *(float *)&v72 = (float)((float)(v71 * v67) + (float)(v54[10] * *(float *)&v69))
                       + (float)(v54[8] * constraint[17].m_breakingImpulseThreshold);
        *(float *)&v73 = (float)((float)(v54[9] * *(float *)&constraint[17].m_rbB)
                               + (float)(v54[10] * *(float *)&constraint[18].m_objectType))
                       + (float)(v54[8] * *(float *)&constraint[17].m_userConstraintId);
        v74 = constraint[18].__vftable;
        yy[0] = v54[9] * *(float *)&constraint[17].m_rbA;
        v75 = v54[5];
        yx[2] = (float)(yy[0] + (float)(v54[10] * *(float *)&v74))
              + (float)(*(float *)&constraint[17].m_userConstraintType * v54[8]);
        yy[0] = v75 * constraint[17].m_appliedImpulse;
        v76 = v54[5];
        yy[1] = (float)(yy[0] + (float)(v54[6] * *(float *)&constraint[18].m_userConstraintType))
              + (float)(constraint[17].m_breakingImpulseThreshold * v54[4]);
        m_objectType = constraint[18].m_objectType;
        yy[0] = v76 * *(float *)&constraint[17].m_rbB;
        v78 = v54[5];
        *(float *)yz = (float)(yy[0] + (float)(v54[6] * *(float *)&m_objectType))
                     + (float)(*(float *)&constraint[17].m_userConstraintId * v54[4]);
        v79 = constraint[18].__vftable;
        xz[3] = v78 * *(float *)&constraint[17].m_rbA;
        v80 = v54[4];
        xz[3] = xz[3] + (float)(v54[6] * *(float *)&v79);
        yx[3] = xz[3] + (float)(v80 * *(float *)&constraint[17].m_userConstraintType);
        xz[3] = (float)(v55 * constraint[17].m_breakingImpulseThreshold)
              + (float)(v57 * constraint[17].m_appliedImpulse);
        yy[0] = xz[3] + (float)(v59 * *(float *)&constraint[18].m_userConstraintType);
        xz[3] = (float)(v55 * *(float *)&constraint[17].m_userConstraintId)
              + (float)(v57 * *(float *)&constraint[17].m_rbB);
        v81 = xz[3] + (float)(v59 * *(float *)&constraint[18].m_objectType);
        *(float *)&yz[1] = (float)((float)(v55 * *(float *)&constraint[17].m_userConstraintType)
                                 + (float)(v57 * *(float *)&constraint[17].m_rbA))
                         + (float)(v59 * *(float *)&constraint[18].__vftable);
        *((float *)&yz[1] + 1) = v81;
        v258 = LODWORD(yy[0]);
        v259.m128i_i64[0] = __PAIR64__(yz[0], LODWORD(yx[3]));
        v264 = _mm_load_si128((const __m128i *)&yz[1]);
        v259.m128i_i64[1] = LODWORD(yy[1]);
        v265 = _mm_load_si128(&v259);
        v260.m128i_i64[0] = __PAIR64__(v73, LODWORD(yx[2]));
        v260.m128i_i64[1] = v72;
        v266 = _mm_load_si128(&v260);
        si128 = _mm_load_si128((const __m128i *)&result);
        if ( v5 )
        {
          v82 = this->getDebugDrawer(this);
          ((void (__thiscall *)(btIDebugDraw *, __m128i *, _DWORD))v82->drawTransform)(v82, &v264, LODWORD(yx[1]));
        }
        xz[3] = btHingeConstraint::getLowerLimit(v8, (int)constraint, a3);
        UpperLimit = btHingeConstraint::getUpperLimit(v83, (int)constraint, a3);
        yy[1] = UpperLimit;
        if ( xz[3] != UpperLimit )
        {
          LOBYTE(yx[2]) = 1;
          if ( xz[3] > UpperLimit )
          {
            xz[3] = 0.0;
            yy[1] = c_fTwoPi_0;
            LOBYTE(yx[2]) = 0;
          }
          if ( HIBYTE(yx[0]) )
          {
            v85 = this->getDebugDrawer;
            v263.mVec128.m128_u64[0] = __PAIR64__(v265.m128i_u32[2], v264.m128i_u32[2]);
            v263.mVec128.m128_u64[1] = v266.m128i_u32[2];
            result.mVec128.m128_u64[0] = __PAIR64__(v265.m128i_u32[0], v264.m128i_u32[0]);
            result.mVec128.m128_u64[1] = v266.m128i_u32[0];
            v86 = (int)v85(this);
            v269.m_el[2].mVec128.m128_u64[1] = 0;
            v270 = 0.0;
            v271 = 0;
            (*(void (__thiscall **)(int, __m128i *, btVector3 *, btVector3 *, _DWORD, _DWORD, _DWORD, _DWORD, float *, _DWORD, _DWORD))(*(_DWORD *)v86 + 60))(
              v86,
              &si128,
              &v263,
              &result,
              LODWORD(yx[1]),
              LODWORD(yx[1]),
              LODWORD(xz[3]),
              LODWORD(yy[1]),
              &v269.m_el[2].mVec128.m128_f32[2],
              LODWORD(yx[2]),
              10.0);
          }
        }
        return;
      case 5:
        v87 = (float *)constraint->m_rbA;
        v88 = v87[5];
        v89 = v87[4];
        v90 = v87[6];
        v91 = constraint[9].m_rbA;
        v87 += 4;
        v92 = constraint[9].m_appliedImpulse;
        v269.m_el[2].mVec128.m128_f32[2] = (float)((float)((float)(v89 * *(float *)&v91)
                                                         + (float)(v88 * *(float *)&constraint[9].m_rbB))
                                                 + (float)(v90 * v92))
                                         + v87[12];
        v93 = constraint[9].m_rbB;
        v269.m_el[2].mVec128.m128_f32[3] = (float)((float)((float)(v87[5] * *(float *)&v93) + (float)(v87[6] * v92))
                                                 + (float)(*(float *)&v91 * v87[4]))
                                         + v87[13];
        v94 = (float)(v87[9] * *(float *)&v93) + (float)(v87[10] * v92);
        v95 = constraint[9].__vftable;
        v96 = constraint[9].m_breakingImpulseThreshold;
        v270 = (float)(v94 + (float)(*(float *)&v91 * v87[8])) + v87[14];
        v97 = constraint[8].m_rbA;
        v271 = 0;
        *(float *)&v98 = (float)((float)(v87[9] * *(float *)&v95) + (float)(v87[10] * v96))
                       + (float)(*(float *)&v97 * v87[8]);
        *(float *)&v99 = (float)((float)(v87[9] * constraint[8].m_dbgDrawSize)
                               + (float)(v87[10] * *(float *)&constraint[9].m_userConstraintId))
                       + (float)(*(float *)&constraint[8].m_isEnabled * v87[8]);
        v100 = constraint[8].m_appliedImpulse;
        yy[0] = v87[10] * *(float *)&constraint[9].m_userConstraintType;
        v101 = v87[5];
        yx[2] = (float)(yy[0] + (float)(v87[9] * v100)) + (float)(constraint[8].m_breakingImpulseThreshold * v87[8]);
        v102 = constraint[9].m_breakingImpulseThreshold;
        yy[0] = v101 * *(float *)&constraint[9].__vftable;
        v103 = v87[5];
        yy[1] = (float)(yy[0] + (float)(v87[6] * v102)) + (float)(*(float *)&constraint[8].m_rbA * v87[4]);
        m_userConstraintId = constraint[9].m_userConstraintId;
        xz[3] = v103 * constraint[8].m_dbgDrawSize;
        v105 = v87[4];
        xz[3] = xz[3] + (float)(v87[6] * *(float *)&m_userConstraintId);
        v106 = xz[3] + (float)(v105 * *(float *)&constraint[8].m_isEnabled);
        v107 = v87[5];
        *(float *)yz = v106;
        v108 = constraint[9].m_userConstraintType;
        xz[3] = v107 * constraint[8].m_appliedImpulse;
        v109 = v87[4];
        xz[3] = xz[3] + (float)(v87[6] * *(float *)&v108);
        yx[3] = xz[3] + (float)(v109 * constraint[8].m_breakingImpulseThreshold);
        xz[3] = (float)(v89 * *(float *)&constraint[8].m_rbA) + (float)(v88 * *(float *)&constraint[9].__vftable);
        yy[0] = xz[3] + (float)(v90 * constraint[9].m_breakingImpulseThreshold);
        xz[3] = (float)(v89 * *(float *)&constraint[8].m_isEnabled) + (float)(v88 * constraint[8].m_dbgDrawSize);
        v110 = xz[3] + (float)(v90 * *(float *)&constraint[9].m_userConstraintId);
        *(float *)&yz[1] = (float)((float)(v89 * constraint[8].m_breakingImpulseThreshold)
                                 + (float)(v88 * constraint[8].m_appliedImpulse))
                         + (float)(v90 * *(float *)&constraint[9].m_userConstraintType);
        *((float *)&yz[1] + 1) = v110;
        v258 = LODWORD(yy[0]);
        v259.m128i_i64[0] = __PAIR64__(yz[0], LODWORD(yx[3]));
        v259.m128i_i64[1] = LODWORD(yy[1]);
        v260.m128i_i64[0] = __PAIR64__(v99, LODWORD(yx[2]));
        v264 = _mm_load_si128((const __m128i *)&yz[1]);
        v265 = _mm_load_si128(&v259);
        v260.m128i_i64[1] = v98;
        v266 = _mm_load_si128(&v260);
        si128 = _mm_load_si128((const __m128i *)&v269.m_el[2].m_floats[2]);
        if ( v5 )
        {
          v111 = this->getDebugDrawer(this);
          ((void (__thiscall *)(btIDebugDraw *, __m128i *, _DWORD))v111->drawTransform)(v111, &v264, LODWORD(yx[1]));
        }
        v112 = (float *)constraint->m_rbB;
        v113 = constraint[11].m_userConstraintType;
        v114 = v112[5];
        v115 = v112[4];
        v116 = v112[6];
        v112 += 4;
        v117 = constraint[11].m_breakingImpulseThreshold;
        v118 = v112[5];
        result.mVec128.m128_f32[0] = (float)((float)((float)(v115 * *(float *)&v113)
                                                   + (float)(v114 * *(float *)&constraint[11].m_userConstraintId))
                                           + (float)(v116 * v117))
                                   + v112[12];
        v119 = (float)((float)((float)(v118 * *(float *)&constraint[11].m_userConstraintId) + (float)(v112[6] * v117))
                     + (float)(*(float *)&v113 * v112[4]))
             + v112[13];
        v120 = constraint[11].m_userConstraintId;
        v121 = *(float *)&v113 * v112[8];
        result.mVec128.m128_f32[1] = v119;
        v122 = (float)(v112[9] * *(float *)&v120) + (float)(v112[10] * v117);
        v123 = constraint[11].__vftable;
        *(float *)&v124 = (float)(v122 + v121) + v112[14];
        v125 = v112[9] * *(float *)&constraint[10].m_rbA;
        v126 = v112[10];
        result.mVec128.m128_u64[1] = v124;
        *(float *)&v127 = (float)(v125 + (float)(v126 * *(float *)&v123))
                        + (float)(*(float *)&constraint[10].m_userConstraintType * v112[8]);
        *(float *)&v128 = (float)((float)(v112[9] * *(float *)&constraint[10].m_isEnabled)
                                + (float)(v112[10] * constraint[10].m_dbgDrawSize))
                        + (float)(*(float *)&constraint[10].m_objectType * v112[8]);
        v129 = constraint[10].m_appliedImpulse;
        yy[0] = v112[9] * constraint[10].m_breakingImpulseThreshold;
        v130 = v112[5];
        yx[2] = (float)(yy[0] + (float)(v112[10] * v129)) + (float)(*(float *)&constraint[10].__vftable * v112[8]);
        v131 = constraint[11].__vftable;
        yy[0] = v130 * *(float *)&constraint[10].m_rbA;
        v132 = v112[5];
        yy[1] = (float)(yy[0] + (float)(v112[6] * *(float *)&v131))
              + (float)(*(float *)&constraint[10].m_userConstraintType * v112[4]);
        v133 = constraint[10].m_dbgDrawSize;
        yy[0] = v132 * *(float *)&constraint[10].m_isEnabled;
        v134 = v112[5];
        *(float *)yz = (float)(yy[0] + (float)(v112[6] * v133))
                     + (float)(*(float *)&constraint[10].m_objectType * v112[4]);
        v135 = constraint[10].m_appliedImpulse;
        yy[0] = v134 * constraint[10].m_breakingImpulseThreshold;
        yx[3] = (float)(yy[0] + (float)(v112[6] * v135)) + (float)(*(float *)&constraint[10].__vftable * v112[4]);
        xz[3] = (float)(v115 * *(float *)&constraint[10].m_userConstraintType)
              + (float)(v114 * *(float *)&constraint[10].m_rbA);
        yy[0] = xz[3] + (float)(v116 * *(float *)&constraint[11].__vftable);
        xz[3] = (float)(v115 * *(float *)&constraint[10].m_objectType)
              + (float)(v114 * *(float *)&constraint[10].m_isEnabled);
        v136 = xz[3] + (float)(v116 * constraint[10].m_dbgDrawSize);
        *(float *)&yz[1] = (float)((float)(v115 * *(float *)&constraint[10].__vftable)
                                 + (float)(v114 * constraint[10].m_breakingImpulseThreshold))
                         + (float)(v116 * constraint[10].m_appliedImpulse);
        v258 = LODWORD(yy[0]);
        v259.m128i_i64[0] = __PAIR64__(yz[0], LODWORD(yx[3]));
        *((float *)&yz[1] + 1) = v136;
        v259.m128i_i64[1] = LODWORD(yy[1]);
        v264 = _mm_load_si128((const __m128i *)&yz[1]);
        v265 = _mm_load_si128(&v259);
        v260.m128i_i64[0] = __PAIR64__(v128, LODWORD(yx[2]));
        v260.m128i_i64[1] = v127;
        v266 = _mm_load_si128(&v260);
        si128 = _mm_load_si128((const __m128i *)&result);
        if ( v5 )
        {
          v137 = this->getDebugDrawer(this);
          ((void (__thiscall *)(btIDebugDraw *, __m128i *, _DWORD))v137->drawTransform)(v137, &v264, LODWORD(yx[1]));
        }
        if ( HIBYTE(yx[0]) )
        {
          btConeTwistConstraint::GetPointForAngle(
            (btConeTwistConstraint *)v8,
            (int)constraint,
            &result,
            6.0868354,
            yx[1]);
          v263.mVec128.m128_f32[0] = (float)((float)((float)(result.mVec128.m128_f32[2] * *(float *)&v264.m128i_i32[2])
                                                   + (float)(*(float *)&v264.m128i_i32[1] * result.mVec128.m128_f32[1]))
                                           + (float)(*(float *)v264.m128i_i32 * result.mVec128.m128_f32[0]))
                                   + *(float *)si128.m128i_i32;
          v263.mVec128.m128_f32[1] = (float)((float)((float)(result.mVec128.m128_f32[2] * *(float *)&v265.m128i_i32[2])
                                                   + (float)(*(float *)&v265.m128i_i32[1] * result.mVec128.m128_f32[1]))
                                           + (float)(*(float *)v265.m128i_i32 * result.mVec128.m128_f32[0]))
                                   + *(float *)&si128.m128i_i32[1];
          v263.mVec128.m128_f32[2] = (float)((float)((float)(result.mVec128.m128_f32[2] * *(float *)&v266.m128i_i32[2])
                                                   + (float)(*(float *)&v266.m128i_i32[1] * result.mVec128.m128_f32[1]))
                                           + (float)(*(float *)v266.m128i_i32 * result.mVec128.m128_f32[0]))
                                   + *(float *)&si128.m128i_i32[2];
          v263.mVec128.m128_i32[3] = 0;
          result.mVec128 = (__m128)_mm_load_si128((const __m128i *)&v263);
          v138 = 0;
          v268.m128i_i32[3] = 0;
          do
          {
            btConeTwistConstraint::GetPointForAngle(
              (btConeTwistConstraint *)&v263,
              (int)constraint,
              &v263,
              (float)v138 * 0.19634953,
              yx[1]);
            v139 = this->getDebugDrawer;
            *(float *)v268.m128i_i32 = (float)((float)((float)(v263.mVec128.m128_f32[2] * *(float *)&v264.m128i_i32[2])
                                                     + (float)(*(float *)&v264.m128i_i32[1] * v263.mVec128.m128_f32[1]))
                                             + (float)(*(float *)v264.m128i_i32 * v263.mVec128.m128_f32[0]))
                                     + *(float *)si128.m128i_i32;
            *(float *)&v268.m128i_i32[1] = (float)((float)((float)(v263.mVec128.m128_f32[2]
                                                                 * *(float *)&v265.m128i_i32[2])
                                                         + (float)(*(float *)&v265.m128i_i32[1]
                                                                 * v263.mVec128.m128_f32[1]))
                                                 + (float)(*(float *)v265.m128i_i32 * v263.mVec128.m128_f32[0]))
                                         + *(float *)&si128.m128i_i32[1];
            *(float *)&v268.m128i_i32[2] = (float)((float)((float)(v263.mVec128.m128_f32[2]
                                                                 * *(float *)&v266.m128i_i32[2])
                                                         + (float)(*(float *)&v266.m128i_i32[1]
                                                                 * v263.mVec128.m128_f32[1]))
                                                 + (float)(*(float *)v266.m128i_i32 * v263.mVec128.m128_f32[0]))
                                         + *(float *)&si128.m128i_i32[2];
            v263.mVec128 = (__m128)_mm_load_si128(&v268);
            v140 = (int)v139(this);
            *((_QWORD *)&v276 + 1) = 0;
            v277 = 0;
            v278 = 0;
            (*(void (__thiscall **)(int, btVector3 *, btVector3 *, char *))(*(_DWORD *)v140 + 12))(
              v140,
              &result,
              &v263,
              (char *)&v276 + 8);
            if ( (v138 & 3) == 0 )
            {
              v141 = this->getDebugDrawer(this);
              memset(v285, 0, sizeof(v285));
              v141->drawLine(v141, (const btVector3 *)&si128, &v263, (const btVector3 *)v285);
            }
            ++v138;
            result.mVec128 = (__m128)_mm_load_si128((const __m128i *)&v263);
          }
          while ( v138 < 32 );
          v142 = (float *)constraint->m_rbB;
          HIDWORD(yz[0]) = constraint[12].m_userConstraintType;
          m_appliedImpulse_low = constraint[13].m_rbB;
          if ( v142[88] <= 0.0 )
          {
            v173 = (float *)constraint->m_rbA;
            v174 = constraint[9].m_rbB;
            v175 = constraint[9].m_rbA;
            v176 = v173[5];
            v177 = v173[4];
            v178 = constraint[9].m_appliedImpulse;
            v179 = v173[6];
            v173 += 4;
            v180 = v173[6];
            *(float *)v268.m128i_i32 = (float)((float)((float)(v177 * *(float *)&v175) + (float)(v176 * *(float *)&v174))
                                             + (float)(v179 * v178))
                                     + v173[12];
            *(float *)&v181 = (float)((float)((float)(v173[5] * *(float *)&v174) + (float)(v180 * v178))
                                    + (float)(v173[4] * *(float *)&v175))
                            + v173[13];
            v182 = v173[10];
            v268.m128i_i32[1] = v181;
            v183 = (float)(v173[9] * *(float *)&v174) + (float)(v173[10] * v178);
            v184 = constraint[9].__vftable;
            v185 = v173[8] * *(float *)&v175;
            v186 = constraint[8].m_rbA;
            *(float *)&v268.m128i_i32[2] = (float)(v183 + v185) + v173[14];
            v187 = v173[9] * *(float *)&v184;
            v268.m128i_i32[3] = 0;
            v188 = constraint[9].m_breakingImpulseThreshold;
            v189 = v187 + (float)(v182 * v188);
            v190 = v173[8] * *(float *)&v186;
            v191 = constraint[9].m_userConstraintId;
            v192 = v189 + v190;
            v193 = v173[9];
            yy[0] = v192;
            v194 = v173[10] * *(float *)&v191;
            v195 = constraint[9].m_userConstraintType;
            v196 = (float)((float)(v193 * constraint[8].m_dbgDrawSize) + v194)
                 + (float)(v173[8] * *(float *)&constraint[8].m_isEnabled);
            v197 = constraint[8].m_appliedImpulse;
            yx[3] = v196;
            v198 = (float)((float)(v173[9] * v197) + (float)(v173[10] * *(float *)&v195))
                 + (float)(v173[8] * constraint[8].m_breakingImpulseThreshold);
            v199 = v173[5] * *(float *)&v184;
            v200 = v173[6] * v188;
            *(float *)yz = v198;
            v201 = v173[6];
            v202 = (float)(v199 + v200) + (float)(*(float *)&constraint[8].m_rbA * v173[4]);
            v203 = constraint[8].m_dbgDrawSize;
            yy[1] = v202;
            v204 = (float)(v173[5] * v203) + (float)(v201 * *(float *)&constraint[9].m_userConstraintId);
            v205 = v173[5];
            v206 = constraint[8].m_appliedImpulse;
            yx[2] = v204 + (float)(*(float *)&constraint[8].m_isEnabled * v173[4]);
            v207 = v205 * v206;
            v208 = constraint[9].m_userConstraintType;
            v209 = constraint[8].m_rbA;
            xz[3] = (float)(v207 + (float)(v173[6] * *(float *)&v208))
                  + (float)(constraint[8].m_breakingImpulseThreshold * v173[4]);
            v210 = (float)((float)(v177 * *(float *)&v209) + (float)(v176 * *(float *)&v184)) + (float)(v179 * v188);
            v211 = (float)(v177 * *(float *)&constraint[8].m_isEnabled) + (float)(v176 * constraint[8].m_dbgDrawSize);
            v212 = v179 * *(float *)&constraint[9].m_userConstraintId;
            v213 = (float)(v179 * *(float *)&v208) + (float)(v177 * constraint[8].m_breakingImpulseThreshold);
            v214 = constraint[8].m_appliedImpulse;
            xy = v210;
            v269.m_el[0].mVec128.m128_f32[1] = v211 + v212;
            v269.m_el[0].mVec128.m128_f32[0] = v213 + (float)(v176 * v214);
            btMatrix3x3::btMatrix3x3(
              &v269,
              (btMatrix3x3 *)&yz[1],
              &v269.m_el[0].mVec128.m128_f32[1],
              &xy,
              &xz[3],
              &yx[2],
              &yy[1],
              (const float *)yz,
              &yx[3],
              yy,
              v251);
            v264 = _mm_load_si128((const __m128i *)&yz[1]);
            v265 = _mm_load_si128(&v259);
          }
          else
          {
            v143 = constraint[11].m_breakingImpulseThreshold;
            v144 = constraint[11].m_userConstraintType;
            v145 = v142[4];
            v146 = v142[6];
            v147 = constraint[11].m_userConstraintId;
            v148 = v142[5];
            v149 = v142[10];
            *(float *)v268.m128i_i32 = (float)((float)((float)(v143 * v146) + (float)(v145 * *(float *)&v144))
                                             + (float)(v148 * *(float *)&v147))
                                     + v142[16];
            v150 = (float)(v142[9] * *(float *)&v147) + (float)(v149 * v143);
            v151 = v142[8] * *(float *)&v144;
            v152 = *(float *)&v144 * v142[12];
            *(float *)&v268.m128i_i32[1] = (float)(v150 + v151) + v142[17];
            v153 = v142[13] * *(float *)&v147;
            v154 = v142[14] * v143;
            v155 = constraint[11].__vftable;
            v156 = v153 + v154;
            v157 = constraint[10].m_rbA;
            v158 = constraint[10].m_objectType;
            *(float *)&v268.m128i_i32[2] = (float)(v156 + v152) + v142[18];
            v159 = constraint[10].m_userConstraintType;
            v268.m128i_i32[3] = 0;
            *(float *)&v160 = (float)((float)(v142[13] * *(float *)&v157) + (float)(v142[14] * *(float *)&v155))
                            + (float)(v142[12] * *(float *)&v159);
            *(float *)&v161 = (float)((float)(v142[13] * *(float *)&constraint[10].m_isEnabled)
                                    + (float)(v142[14] * constraint[10].m_dbgDrawSize))
                            + (float)(v142[12] * *(float *)&v158);
            *(float *)&v162 = (float)((float)(v142[13] * constraint[10].m_breakingImpulseThreshold)
                                    + (float)(v142[14] * constraint[10].m_appliedImpulse))
                            + (float)(v142[12] * *(float *)&constraint[10].__vftable);
            v163 = constraint[11].__vftable;
            yy[0] = v142[9] * *(float *)&constraint[10].m_rbA;
            v164 = v142[9];
            yy[1] = (float)(yy[0] + (float)(v142[10] * *(float *)&v163))
                  + (float)(*(float *)&constraint[10].m_userConstraintType * v142[8]);
            v165 = constraint[10].m_dbgDrawSize;
            xz[3] = v164 * *(float *)&constraint[10].m_isEnabled;
            v166 = v142[8];
            xz[3] = xz[3] + (float)(v142[10] * v165);
            v167 = xz[3] + (float)(v166 * *(float *)&constraint[10].m_objectType);
            v168 = v142[9];
            *(float *)yz = v167;
            v169 = constraint[10].m_appliedImpulse;
            xz[3] = v168 * constraint[10].m_breakingImpulseThreshold;
            v170 = v142[8];
            xz[3] = xz[3] + (float)(v142[10] * v169);
            yx[3] = xz[3] + (float)(v170 * *(float *)&constraint[10].__vftable);
            xz[3] = (float)(v145 * *(float *)&constraint[10].m_userConstraintType)
                  + (float)(v148 * *(float *)&constraint[10].m_rbA);
            yy[0] = xz[3] + (float)(v146 * *(float *)&constraint[11].__vftable);
            xz[3] = (float)(v145 * *(float *)&constraint[10].m_objectType)
                  + (float)(v148 * *(float *)&constraint[10].m_isEnabled);
            v171 = xz[3] + (float)(v146 * constraint[10].m_dbgDrawSize);
            *(float *)&yz[1] = (float)((float)(v145 * *(float *)&constraint[10].__vftable)
                                     + (float)(v148 * constraint[10].m_breakingImpulseThreshold))
                             + (float)(v146 * constraint[10].m_appliedImpulse);
            v258 = LODWORD(yy[0]);
            *((float *)&yz[1] + 1) = v171;
            v259.m128i_i64[0] = __PAIR64__(yz[0], LODWORD(yx[3]));
            v259.m128i_i64[1] = LODWORD(yy[1]);
            v264 = _mm_load_si128((const __m128i *)&yz[1]);
            v172 = _mm_load_si128(&v259);
            v260.m128i_i64[0] = __PAIR64__(v161, v162);
            v260.m128i_i64[1] = v160;
            v265 = v172;
          }
          v266 = _mm_load_si128(&v260);
          v215 = this->getDebugDrawer;
          si128 = _mm_load_si128(&v268);
          v283 = si128;
          v269.m_el[0].mVec128.m128_u64[1] = __PAIR64__(v265.m128i_u32[0], v264.m128i_u32[0]);
          v269.m_el[1].mVec128.m128_u64[0] = v266.m128i_u32[0];
          v269.m_el[1].mVec128.m128_u64[1] = __PAIR64__(v265.m128i_u32[1], v264.m128i_u32[1]);
          v269.m_el[2].mVec128.m128_u64[0] = v266.m128i_u32[1];
          v216 = (int)v215(this);
          memset(v284, 0, sizeof(v284));
          (*(void (__thiscall **)(int, __m128i *, float *, float *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD *, int, _DWORD))(*(_DWORD *)v216 + 60))(
            v216,
            &v283,
            &v269.m_el[0].mVec128.m128_f32[2],
            &v269.m_el[1].mVec128.m128_f32[2],
            LODWORD(yx[1]),
            LODWORD(yx[1]),
            (float)-*(float *)&m_appliedImpulse_low - *((float *)yz + 1),
            *((float *)yz + 1) - *(float *)&m_appliedImpulse_low,
            v284,
            1,
            10.0);
        }
        return;
      case 6:
      case 9:
        yz[1] = *(_QWORD *)&constraint[29].m_userConstraintType;
        v258 = *(_QWORD *)&constraint[29].m_breakingImpulseThreshold;
        v259 = *(__m128i *)&constraint[29].m_rbA;
        v260 = *(__m128i *)&constraint[30].__vftable;
        v261 = *(_QWORD *)&constraint[30].m_breakingImpulseThreshold;
        v262 = *(_QWORD *)&constraint[30].m_rbA;
        if ( v5 )
        {
          v217 = this->getDebugDrawer(this);
          ((void (__thiscall *)(btIDebugDraw *, _QWORD *, _DWORD))v217->drawTransform)(v217, &yz[1], LODWORD(yx[1]));
        }
        yz[1] = *(_QWORD *)&constraint[30].m_appliedImpulse;
        v258 = *(_QWORD *)&constraint[31].__vftable;
        v259 = *(__m128i *)&constraint[31].m_userConstraintType;
        v260 = *(__m128i *)&constraint[31].m_rbA;
        v261 = *(_QWORD *)&constraint[32].__vftable;
        v262 = *(_QWORD *)&constraint[32].m_userConstraintType;
        if ( v5 )
        {
          v218 = this->getDebugDrawer(this);
          ((void (__thiscall *)(btIDebugDraw *, _QWORD *, _DWORD))v218->drawTransform)(v218, &yz[1], LODWORD(yx[1]));
        }
        if ( !HIBYTE(yx[0]) )
          return;
        v219 = *(float *)&constraint[25].m_rbB;
        yz[1] = *(_QWORD *)&constraint[29].m_userConstraintType;
        v269.m_el[0].mVec128.m128_f32[0] = v219;
        v220 = *(float *)&constraint[27].m_userConstraintType;
        v258 = *(_QWORD *)&constraint[29].m_breakingImpulseThreshold;
        *((float *)yz + 1) = v220;
        v221 = *(_QWORD *)&constraint[29].m_rbA;
        v222 = this->__vftable;
        m_appliedImpulse_low = (btRigidBody *)constraint[27].m_userConstraintId;
        v259.m128i_i64[0] = v221;
        v223 = v222->getDebugDrawer;
        v259.m128i_i64[1] = *(_QWORD *)&constraint[29].m_appliedImpulse;
        v260 = *(__m128i *)&constraint[30].__vftable;
        v261 = *(_QWORD *)&constraint[30].m_breakingImpulseThreshold;
        v262 = *(_QWORD *)&constraint[30].m_rbA;
        v269.m_el[0].mVec128.m128_i32[3] = v259.m128i_i32[2];
        v269.m_el[1].mVec128.m128_u64[0] = v260.m128i_u32[2];
        result.mVec128.m128_u64[0] = __PAIR64__(v221, yz[1]);
        v224 = constraint[25].m_rbA;
        result.mVec128.m128_u64[1] = v260.m128i_u32[0];
        *(unsigned __int64 *)((char *)v269.m_el[0].mVec128.m128_u64 + 4) = __PAIR64__(v258, (unsigned int)v224);
        v225 = (int)v223(this);
        v279 = 0;
        v280 = 0;
        v281 = 0;
        v282 = 0;
        (*(void (__thiscall **)(int, btTypedConstraint *, float *, btVector3 *, _DWORD, int, int, _DWORD, btRigidBody *, int *, _DWORD))(*(_DWORD *)v225 + 64))(
          v225,
          constraint + 32,
          &v269.m_el[0].mVec128.m128_f32[2],
          &result,
          yx[1] * 0.89999998,
          v269.m_el[0].mVec128.m128_i32[1],
          v269.m_el[0].mVec128.m128_i32[0],
          HIDWORD(yz[0]),
          m_appliedImpulse_low,
          &v279,
          10.0);
        v269.m_el[1].mVec128.m128_u64[1] = __PAIR64__(v259.m128i_u32[1], HIDWORD(yz[1]));
        v269.m_el[2].mVec128.m128_u64[0] = v260.m128i_u32[1];
        v226 = (__m128)_mm_load_si128((const __m128i *)&v269.m_el[1].m_floats[2]);
        m_appliedImpulse_low = *(btRigidBody **)&constraint[32].m_isEnabled;
        yy[1] = *(float *)&constraint[32].m_rbA;
        result.mVec128 = v226;
        *((float *)yz + 1) = cosf(*(float *)&m_appliedImpulse_low);
        v269.m_el[0].mVec128.m128_f32[0] = sinf(*(float *)&m_appliedImpulse_low);
        yx[2] = cosf(yy[1]);
        v227 = sinf(yy[1]);
        *(float *)&m_appliedImpulse_low = v227;
        v228 = *(float *)&v260.m128i_i32[1];
        *(float *)&v268.m128i_i32[1] = *(float *)&v259.m128i_i32[1] * yx[2] - v227 * *((float *)&yz[1] + 1);
        v229 = (float)(*(float *)&v259.m128i_i32[1] * *(float *)&m_appliedImpulse_low)
             + (float)(*((float *)&yz[1] + 1) * yx[2]);
        *(float *)&v268.m128i_i32[2] = (float)(*(float *)&v260.m128i_i32[1] * *((float *)yz + 1))
                                     + (float)(v229 * v269.m_el[0].mVec128.m128_f32[0]);
        yz[1] = *(_QWORD *)&constraint[30].m_appliedImpulse;
        v258 = *(_QWORD *)&constraint[31].__vftable;
        v259 = *(__m128i *)&constraint[31].m_userConstraintType;
        v260 = *(__m128i *)&constraint[31].m_rbA;
        v261 = *(_QWORD *)&constraint[32].__vftable;
        v262 = *(_QWORD *)&constraint[32].m_userConstraintType;
        v263.mVec128.m128_f32[0] = -*(float *)&yz[1];
        v263.mVec128.m128_i32[1] = v259.m128i_i32[0] ^ 0x80000000;
        v263.mVec128.m128_u64[1] = v260.m128i_u32[0] ^ 0x80000000LL;
        v230 = constraint[24].m_objectType;
        v231 = constraint[24].__vftable;
        *(float *)v268.m128i_i32 = (float)(v229 * *((float *)yz + 1)) - (float)(v228 * v269.m_el[0].mVec128.m128_f32[0]);
        HIDWORD(yz[0]) = v231;
        m_appliedImpulse_low = (btRigidBody *)v230;
        if ( *(float *)&v231 <= *(float *)&v230 )
        {
          if ( *(float *)&v230 <= *(float *)&v231 )
          {
LABEL_37:
            v233 = this->__vftable;
            yz[1] = *(_QWORD *)&constraint[29].m_userConstraintType;
            v234 = v233->getDebugDrawer;
            v258 = *(_QWORD *)&constraint[29].m_breakingImpulseThreshold;
            v259 = *(__m128i *)&constraint[29].m_rbA;
            v260 = *(__m128i *)&constraint[30].__vftable;
            v261 = *(_QWORD *)&constraint[30].m_breakingImpulseThreshold;
            v262 = *(_QWORD *)&constraint[30].m_rbA;
            v283 = *(__m128i *)&constraint[18].m_appliedImpulse;
            v286[0] = *(_QWORD *)&constraint[19].m_userConstraintType;
            v286[1] = *(_QWORD *)&constraint[19].m_breakingImpulseThreshold;
            v235 = (int)v234(this);
            memset(v273, 0, sizeof(v273));
            (*(void (__thiscall **)(int, __m128i *, _QWORD *, _QWORD *, _DWORD *))(*(_DWORD *)v235 + 68))(
              v235,
              &v283,
              v286,
              &yz[1],
              v273);
            return;
          }
          v232 = this->getDebugDrawer(this);
          yy[0] = 10.0;
          LODWORD(xz[3]) = 1;
          v278 = 0;
          v279 = 0;
          v280 = 0;
          v281 = 0;
        }
        else
        {
          v232 = this->getDebugDrawer(this);
          yy[0] = 10.0;
          xz[3] = 0.0;
          *(_QWORD *)((char *)&v276 + 4) = 0;
          HIDWORD(v276) = 0;
          v277 = 0;
        }
        ((void (__thiscall *)(btIDebugDraw *, btTypedConstraint *, char *, float *))v232->drawArc)(
          v232,
          constraint + 32,
          &v264.m128i_i8[12],
          &v269.m_el[0].mVec128.m128_f32[1]);
        goto LABEL_37;
      case 7:
        yz[1] = *(_QWORD *)&constraint[22].m_appliedImpulse;
        v258 = *(_QWORD *)&constraint[23].__vftable;
        v259 = *(__m128i *)&constraint[23].m_userConstraintType;
        v260 = *(__m128i *)&constraint[23].m_rbA;
        v261 = *(_QWORD *)&constraint[24].__vftable;
        v262 = *(_QWORD *)&constraint[24].m_userConstraintType;
        if ( v5 )
        {
          v236 = this->getDebugDrawer(this);
          ((void (__thiscall *)(btIDebugDraw *, _QWORD *, _DWORD))v236->drawTransform)(v236, &yz[1], LODWORD(yx[1]));
        }
        yz[1] = *(_QWORD *)&constraint[24].m_breakingImpulseThreshold;
        v258 = *(_QWORD *)&constraint[24].m_rbA;
        v259 = *(__m128i *)&constraint[24].m_appliedImpulse;
        v260 = *(__m128i *)&constraint[25].m_userConstraintType;
        v261 = *(_QWORD *)&constraint[25].m_rbA;
        v262 = *(_QWORD *)&constraint[25].m_appliedImpulse;
        if ( v5 )
        {
          v237 = this->getDebugDrawer(this);
          ((void (__thiscall *)(btIDebugDraw *, _QWORD *, _DWORD))v237->drawTransform)(v237, &yz[1], LODWORD(yx[1]));
        }
        if ( HIBYTE(yx[0]) )
        {
          p_m_appliedImpulse = (__m128i *)&constraint[22].m_appliedImpulse;
          if ( !LOBYTE(constraint[4].m_breakingImpulseThreshold) )
            p_m_appliedImpulse = (__m128i *)&constraint[24].m_breakingImpulseThreshold;
          v239 = *(float *)&constraint[4].m_isEnabled;
          v264 = *p_m_appliedImpulse;
          v265 = p_m_appliedImpulse[1];
          v266 = p_m_appliedImpulse[2];
          si128.m128i_i64[0] = p_m_appliedImpulse[3].m128i_i64[0];
          v240 = this->getDebugDrawer;
          si128.m128i_i64[1] = p_m_appliedImpulse[3].m128i_i64[1];
          v241 = (float)(*(float *)&v264.m128i_i32[1] + *(float *)&v264.m128i_i32[2]) * 0.0;
          v242 = (float)(*(float *)v265.m128i_i32 * v239) + *(float *)&si128.m128i_i32[1];
          v269.m_el[1].mVec128.m128_f32[2] = (float)((float)(*(float *)v264.m128i_i32 * v239) + *(float *)si128.m128i_i32)
                                           + v241;
          v243 = *(float *)v266.m128i_i32 * v239;
          v244 = constraint[4].m_rbA;
          v245 = (float)(*(float *)&v265.m128i_i32[1] + *(float *)&v265.m128i_i32[2]) * 0.0;
          v269.m_el[1].mVec128.m128_f32[3] = v242 + v245;
          v246 = (float)(*(float *)&v266.m128i_i32[1] + *(float *)&v266.m128i_i32[2]) * 0.0;
          v269.m_el[2].mVec128.m128_f32[0] = (float)(v243 + *(float *)&si128.m128i_i32[2]) + v246;
          v269.m_el[2].mVec128.m128_i32[1] = 0;
          v269.m_el[0].mVec128.m128_f32[2] = (float)((float)(*(float *)v264.m128i_i32 * *(float *)&v244)
                                                   + *(float *)si128.m128i_i32)
                                           + v241;
          v269.m_el[0].mVec128.m128_f32[3] = (float)((float)(*(float *)v265.m128i_i32 * *(float *)&v244)
                                                   + *(float *)&si128.m128i_i32[1])
                                           + v245;
          v269.m_el[1].mVec128.m128_f32[0] = (float)((float)(*(float *)v266.m128i_i32 * *(float *)&v244)
                                                   + *(float *)&si128.m128i_i32[2])
                                           + v246;
          v269.m_el[1].mVec128.m128_i32[1] = 0;
          v247 = (int)v240(this);
          memset(v274, 0, sizeof(v274));
          (*(void (__thiscall **)(int, float *, float *, _QWORD *))(*(_DWORD *)v247 + 12))(
            v247,
            &v269.m_el[1].mVec128.m128_f32[2],
            &v269.m_el[0].mVec128.m128_f32[2],
            v274);
          result.mVec128.m128_u64[0] = __PAIR64__(v265.m128i_u32[0], v264.m128i_u32[0]);
          v248 = this->__vftable;
          *((float *)yz + 1) = *(float *)&constraint[4].m_rbB;
          v249 = v248->getDebugDrawer;
          m_appliedImpulse_low = (btRigidBody *)LODWORD(constraint[4].m_appliedImpulse);
          v268.m128i_i64[0] = __PAIR64__(v265.m128i_u32[1], v264.m128i_u32[1]);
          result.mVec128.m128_u64[1] = v266.m128i_u32[0];
          v268.m128i_i64[1] = v266.m128i_u32[1];
          v250 = (int)v249(this);
          memset(v275, 0, 16);
          (*(void (__thiscall **)(int, btRigidBody **, btVector3 *, __m128i *, _DWORD, _DWORD, _DWORD, btRigidBody *, _DWORD *, int, _DWORD))(*(_DWORD *)v250 + 60))(
            v250,
            &constraint[25].m_rbA,
            &result,
            &v268,
            LODWORD(yx[1]),
            LODWORD(yx[1]),
            HIDWORD(yz[0]),
            m_appliedImpulse_low,
            v275,
            1,
            10.0);
        }
        return;
      default:
        return;
    }
  }
}
