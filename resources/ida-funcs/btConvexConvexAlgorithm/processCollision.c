void __thiscall btConvexConvexAlgorithm::processCollision(
        btConvexConvexAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        const btDispatcherInfo *dispatchInfo,
        btIDebugDraw *resultOut)
{
  btConvexShape *m_collisionShape; // esi
  btCollisionShape *v7; // edi
  btConvexShape_vtbl *v8; // esi
  int m_shapeType; // ecx
  float v10; // xmm5_4
  float v11; // xmm0_4
  float v12; // xmm6_4
  float v13; // xmm4_4
  float v14; // xmm7_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm3_4
  float v18; // xmm6_4
  float v19; // xmm6_4
  float v20; // xmm6_4
  float v21; // xmm0_4
  float v22; // xmm5_4
  float v23; // xmm3_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm1_4
  float v29; // xmm4_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm4_4
  float v33; // xmm4_4
  float v34; // xmm3_4
  btIDebugDraw_vtbl *v35; // eax
  btIDebugDraw *v36; // ecx
  btIDebugDraw *v37; // edx
  btPersistentManifold *m_manifoldPtr; // eax
  btGjkPairDetector *v39; // ecx
  double v40; // st7
  double v41; // st6
  btTransform *p_m_worldTransform; // ebx
  btCollisionShape *v43; // esi
  int v44; // edx
  btConvexPolyhedron *v45; // eax
  bool v46; // zf
  char SeparatingAxis; // al
  float v48; // xmm4_4
  const btConvexPolyhedron *v49; // eax
  btIDebugDraw *v50; // edi
  btIDebugDraw_vtbl *v51; // eax
  float v52; // xmm0_4
  float v53; // xmm1_4
  float v54; // xmm2_4
  float *v55; // eax
  float v56; // xmm2_4
  float v57; // xmm1_4
  float v58; // xmm0_4
  float *v59; // eax
  float v60; // xmm0_4
  float v61; // xmm1_4
  float v62; // xmm2_4
  char *v63; // eax
  int v64; // ebx
  btGjkPairDetector *v65; // ecx
  int v66; // edx
  float v67; // xmm0_4
  btAlignedObjectArray<GrahamVector2> *v68; // ecx
  float v69; // xmm4_4
  btIDebugDraw_vtbl *v70; // esi
  btIDebugDraw *v71; // ecx
  btIDebugDraw *v72; // edx
  float v73; // xmm5_4
  float v74; // xmm2_4
  float v75; // xmm3_4
  float v76; // xmm4_4
  float v77; // xmm1_4
  float v78; // xmm0_4
  float v79; // xmm0_4
  float v80; // xmm0_4
  float v81; // xmm1_4
  const btConvexPolyhedron *v82; // eax
  __m128i v83; // xmm0
  btVector3 *p_m_origin; // esi
  bool v85; // cc
  int *v86; // esi
  float v87; // xmm1_4
  float v88; // xmm0_4
  float v89; // xmm0_4
  float v90; // xmm1_4
  double v91; // xmm0_8
  __m128 v92; // xmm0
  __m128i v93; // xmm0
  float v94; // xmm1_4
  float v95; // xmm4_4
  float v96; // xmm5_4
  float v97; // xmm1_4
  float v98; // xmm3_4
  float v99; // xmm2_4
  float v100; // xmm0_4
  float v101; // xmm3_4
  float v102; // xmm4_4
  float v103; // xmm6_4
  float v104; // xmm2_4
  float v105; // xmm1_4
  float v106; // xmm0_4
  float v107; // xmm2_4
  float v108; // xmm5_4
  float v109; // xmm6_4
  float v110; // xmm2_4
  float v111; // xmm7_4
  float v112; // xmm4_4
  float v113; // xmm3_4
  float v114; // xmm0_4
  btVector3 *p_m_maximumDistanceSquared; // esi
  btVector3 *v116; // edi
  float v117; // xmm5_4
  float v118; // xmm1_4
  float v119; // xmm2_4
  float v120; // xmm3_4
  float v121; // xmm0_4
  float v122; // xmm3_4
  float v123; // xmm0_4
  float v124; // xmm4_4
  float v125; // xmm1_4
  int v126; // xmm2_4
  float v127; // xmm5_4
  float v128; // xmm2_4
  int *v129; // edi
  int *v130; // esi
  btGjkPairDetector *v131; // ecx
  btIDebugDraw_vtbl *v132; // eax
  float minDist; // [esp+8h] [ebp-46Ch]
  btIDebugDraw_vtbl *v134; // [esp+10h] [ebp-464h]
  btGjkPairDetector *v135; // [esp+10h] [ebp-464h]
  btIDebugDraw *m_debugDraw; // [esp+10h] [ebp-464h]
  long double v137; // [esp+14h] [ebp-460h]
  long double v138; // [esp+14h] [ebp-460h]
  float v140; // [esp+28h] [ebp-44Ch]
  const btConvexPolyhedron **v141; // [esp+2Ch] [ebp-448h]
  float v142; // [esp+2Ch] [ebp-448h]
  float v143; // [esp+2Ch] [ebp-448h]
  float v144; // [esp+2Ch] [ebp-448h]
  float v145; // [esp+30h] [ebp-444h]
  float v146; // [esp+30h] [ebp-444h]
  float v147; // [esp+30h] [ebp-444h]
  float v148; // [esp+30h] [ebp-444h]
  float v149; // [esp+30h] [ebp-444h]
  float v150; // [esp+30h] [ebp-444h]
  float v151; // [esp+30h] [ebp-444h]
  float v152; // [esp+34h] [ebp-440h]
  float *v153; // [esp+34h] [ebp-440h]
  char *v154; // [esp+34h] [ebp-440h]
  float v155; // [esp+38h] [ebp-43Ch]
  float m_contactBreakingThreshold; // [esp+3Ch] [ebp-438h]
  float v157; // [esp+3Ch] [ebp-438h]
  float v158; // [esp+3Ch] [ebp-438h]
  float v159; // [esp+3Ch] [ebp-438h]
  float ptr; // [esp+40h] [ebp-434h]
  float *ptra; // [esp+40h] [ebp-434h]
  bool ptrb; // [esp+40h] [ebp-434h]
  float v163; // [esp+44h] [ebp-430h]
  float v164; // [esp+44h] [ebp-430h]
  float v165; // [esp+44h] [ebp-430h]
  float v166; // [esp+44h] [ebp-430h]
  float v167; // [esp+48h] [ebp-42Ch]
  float v168; // [esp+48h] [ebp-42Ch]
  float v169; // [esp+48h] [ebp-42Ch]
  float v170; // [esp+48h] [ebp-42Ch]
  float v171; // [esp+48h] [ebp-42Ch]
  float v172; // [esp+48h] [ebp-42Ch]
  float v173; // [esp+4Ch] [ebp-428h]
  float v174; // [esp+4Ch] [ebp-428h]
  float v175; // [esp+4Ch] [ebp-428h]
  float v176; // [esp+4Ch] [ebp-428h]
  float v177; // [esp+4Ch] [ebp-428h]
  float v178; // [esp+54h] [ebp-420h]
  float v179; // [esp+54h] [ebp-420h]
  float v180; // [esp+58h] [ebp-41Ch]
  float v181; // [esp+58h] [ebp-41Ch]
  float v182; // [esp+5Ch] [ebp-418h]
  float v183; // [esp+60h] [ebp-414h]
  float transA; // [esp+64h] [ebp-410h]
  btTransform *transAa; // [esp+64h] [ebp-410h]
  float v186; // [esp+68h] [ebp-40Ch]
  float v187; // [esp+68h] [ebp-40Ch]
  float v188; // [esp+68h] [ebp-40Ch]
  btIDebugDraw debugDraw; // [esp+6Ch] [ebp-408h] BYREF
  float maxDist; // [esp+70h] [ebp-404h]
  float v191; // [esp+74h] [ebp-400h]
  float v192; // [esp+78h] [ebp-3FCh]
  float v193; // [esp+7Ch] [ebp-3F8h]
  float v194; // [esp+84h] [ebp-3F0h]
  float v195; // [esp+88h] [ebp-3ECh]
  float v196; // [esp+8Ch] [ebp-3E8h]
  btVector3 sep; // [esp+94h] [ebp-3E0h] BYREF
  btMatrix3x3 v198; // [esp+A4h] [ebp-3D0h] BYREF
  float v199; // [esp+D4h] [ebp-3A0h] BYREF
  float v200; // [esp+D8h] [ebp-39Ch]
  float v201; // [esp+DCh] [ebp-398h]
  int v202; // [esp+E0h] [ebp-394h]
  btVector3 v203; // [esp+E4h] [ebp-390h] BYREF
  float v204; // [esp+F4h] [ebp-380h] BYREF
  float v205; // [esp+F8h] [ebp-37Ch] BYREF
  float v206; // [esp+FCh] [ebp-378h] BYREF
  float v207; // [esp+100h] [ebp-374h] BYREF
  float v208; // [esp+104h] [ebp-370h] BYREF
  float v209; // [esp+108h] [ebp-36Ch] BYREF
  float v210; // [esp+10Ch] [ebp-368h] BYREF
  float v211; // [esp+110h] [ebp-364h] BYREF
  float v212; // [esp+114h] [ebp-360h] BYREF
  float v213; // [esp+118h] [ebp-35Ch] BYREF
  float v214; // [esp+11Ch] [ebp-358h] BYREF
  float v215; // [esp+120h] [ebp-354h] BYREF
  float v216; // [esp+124h] [ebp-350h] BYREF
  float v217; // [esp+128h] [ebp-34Ch]
  btMatrix3x3 v218; // [esp+12Ch] [ebp-348h] BYREF
  btTransform output; // [esp+164h] [ebp-310h] BYREF
  btTransform m_worldTransform; // [esp+1A4h] [ebp-2D0h] BYREF
  float v221; // [esp+1E4h] [ebp-290h]
  btStackAlloc *m_stackAllocator; // [esp+1E8h] [ebp-28Ch]
  btDiscreteCollisionDetectorInterface::ClosestPointInput v223; // [esp+1F4h] [ebp-280h] BYREF
  btTransform v224; // [esp+284h] [ebp-1F0h] BYREF
  float v225[8]; // [esp+2C4h] [ebp-1B0h] BYREF
  btPerturbedContactResult v226; // [esp+2E4h] [ebp-190h] BYREF

  if ( !this->m_manifoldPtr )
  {
    this->m_manifoldPtr = this->m_dispatcher->getNewManifold(this->m_dispatcher, body0, body1);
    this->m_ownManifold = 1;
  }
  resultOut[1].__vftable = (btIDebugDraw_vtbl *)this->m_manifoldPtr;
  m_collisionShape = (btConvexShape *)body0->m_collisionShape;
  v7 = body1->m_collisionShape;
  v141 = (const btConvexPolyhedron **)m_collisionShape;
  if ( m_collisionShape->m_shapeType == 10 && v7->m_shapeType == 10 )
  {
    m_collisionShape->getLocalScaling(m_collisionShape);
    v7->getLocalScaling(v7);
    v8 = m_collisionShape[4].__vftable;
    m_shapeType = v7[5].m_shapeType;
    m_contactBreakingThreshold = this->m_manifoldPtr->m_contactBreakingThreshold;
    maxDist = *((float *)&v7[2].m_userPointer + m_shapeType);
    v10 = body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[m_shapeType];
    v173 = body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[m_shapeType];
    v186 = *(float *)&v141[((int)&v8->~btConvexShape + 2) % 3 + 8];
    transA = *(float *)&v141[(_DWORD)v8 + 8];
    v11 = *((float *)&v7[2].m_userPointer + (m_shapeType + 2) % 3);
    v12 = body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[(_DWORD)v8];
    v13 = body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[(_DWORD)v8];
    v14 = body0->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[(_DWORD)v8];
    v203.mVec128 = (__m128)body0->m_worldTransform.m_origin;
    v152 = v11;
    v15 = body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[m_shapeType];
    sep.mVec128 = (__m128)body1->m_worldTransform.m_origin;
    v167 = v15;
    v178 = v13;
    v16 = sep.mVec128.m128_f32[1] - v203.mVec128.m128_f32[1];
    v180 = v12;
    v17 = (float)((float)(v173 * v14) + (float)(v15 * v12)) + (float)(v10 * v13);
    ptr = (float)((float)((float)(sep.mVec128.m128_f32[2] - v203.mVec128.m128_f32[2]) * v14)
                + (float)((float)(sep.mVec128.m128_f32[1] - v203.mVec128.m128_f32[1]) * v12))
        + (float)((float)(sep.mVec128.m128_f32[0] - v203.mVec128.m128_f32[0]) * v13);
    v142 = (float)((float)((float)(sep.mVec128.m128_f32[2] - v203.mVec128.m128_f32[2]) * v173)
                 + (float)((float)(sep.mVec128.m128_f32[1] - v203.mVec128.m128_f32[1]) * v15))
         + (float)((float)(sep.mVec128.m128_f32[0] - v203.mVec128.m128_f32[0]) * v10);
    if ( (float)(s_bm_current_air_resistance - (float)(v17 * v17)) == 0.0 )
    {
      v140 = 0.0;
    }
    else
    {
      v140 = (float)(ptr - (float)(v142 * v17)) / (float)(s_bm_current_air_resistance - (float)(v17 * v17));
      LODWORD(v18) = LODWORD(transA) ^ _mask__NegFloat_;
      if ( COERCE_FLOAT(LODWORD(transA) ^ _mask__NegFloat_) > v140 || (v18 = transA, v140 > transA) )
        v140 = v18;
    }
    v143 = (float)(v17 * v140) - v142;
    LODWORD(v19) = LODWORD(maxDist) ^ _mask__NegFloat_;
    if ( COERCE_FLOAT(LODWORD(maxDist) ^ _mask__NegFloat_) > v143 || (v19 = maxDist, v143 > maxDist) )
    {
      v143 = v19;
      v20 = (float)(v17 * v19) + ptr;
      v140 = v20;
      if ( COERCE_FLOAT(LODWORD(transA) ^ _mask__NegFloat_) <= v20 )
      {
        if ( v20 > transA )
          v140 = transA;
      }
      else
      {
        LODWORD(v140) = LODWORD(transA) ^ _mask__NegFloat_;
      }
    }
    v194 = v10 * v143;
    v21 = (float)((float)(sep.mVec128.m128_f32[0] - v203.mVec128.m128_f32[0]) - (float)(v13 * v140))
        + (float)(v10 * v143);
    sep.mVec128.m128_f32[1] = v140 * v180;
    v195 = v167 * v143;
    v22 = (float)(v16 - (float)(v140 * v180)) + (float)(v167 * v143);
    v23 = v21;
    v24 = (float)((float)(sep.mVec128.m128_f32[2] - v203.mVec128.m128_f32[2]) - (float)(v14 * v140))
        + (float)(v173 * v143);
    v25 = (float)((float)(v21 * v21) + (float)(v24 * v24)) + (float)(v22 * v22);
    v26 = (float)(fsqrt(v25) - v186) - v152;
    if ( v26 <= m_contactBreakingThreshold )
    {
      if ( v25 > 1.4210855e-14 )
      {
        LODWORD(v33) = COERCE_UNSIGNED_INT(s_bm_current_air_resistance / fsqrt(v25)) ^ _mask__NegFloat_;
        v199 = v23 * v33;
        v200 = v22 * v33;
        v201 = v24 * v33;
        v202 = 0;
        v31 = v24 * v33;
        v30 = v23 * v33;
      }
      else
      {
        v27 = v180 * v180;
        if ( COERCE_FLOAT(LODWORD(v14) & _mask__AbsFloat_) <= hsqt2 )
        {
          v32 = s_bm_current_air_resistance / fsqrt(v27 + (float)(v13 * v13));
          LODWORD(v30) = COERCE_UNSIGNED_INT(v32 * v180) ^ _mask__NegFloat_;
          v200 = v178 * v32;
          v31 = 0.0;
        }
        else
        {
          v28 = fsqrt(v27 + (float)(v14 * v14));
          v29 = (float)(s_bm_current_air_resistance / v28) * v180;
          LODWORD(v200) = COERCE_UNSIGNED_INT(v14 * (float)(s_bm_current_air_resistance / v28)) ^ _mask__NegFloat_;
          v30 = 0.0;
          v31 = v29;
        }
        v199 = v30;
        v201 = v31;
      }
      v34 = body1->m_worldTransform.m_origin.mVec128.m128_f32[2];
      sep.mVec128.m128_f32[2] = v31 * v152;
      v168 = (float)(body1->m_worldTransform.m_origin.mVec128.m128_f32[1] + v195) + (float)(v200 * v152);
      v225[0] = (float)(body1->m_worldTransform.m_origin.mVec128.m128_f32[0] + v194) + (float)(v30 * v152);
      v225[1] = v168;
      v225[2] = (float)(v34 + (float)(v173 * v143)) + (float)(v31 * v152);
      v225[3] = 0.0;
    }
    if ( m_contactBreakingThreshold > v26 )
      resultOut->drawLine(resultOut, (const btVector3 *)&v199, (const btVector3 *)v225, (const btVector3 *)LODWORD(v26));
    v35 = resultOut[1].__vftable;
    if ( v35[12].drawTriangle )
    {
      v134 = resultOut[1].__vftable;
      if ( v35[12].drawSphere == (void (__thiscall *)(btIDebugDraw *, const btVector3 *, float, const btVector3 *))resultOut[36].__vftable )
      {
        v36 = resultOut + 20;
        v37 = resultOut + 4;
      }
      else
      {
        v36 = resultOut + 4;
        v37 = resultOut + 20;
      }
LABEL_100:
      btPersistentManifold::refreshContactPoints(
        (btPersistentManifold *)v36,
        (const btTransform *)v37,
        (btPersistentManifold *)v134);
      return;
    }
    return;
  }
  btGjkPairDetector::btGjkPairDetector(
    (btGjkPairDetector *)&v223,
    m_collisionShape,
    (btConvexShape *)v7,
    this->m_pdSolver,
    this->m_simplexSolver);
  m_manifoldPtr = this->m_manifoldPtr;
  v223.m_transformA.m_basis.m_el[2].mVec128.m128_u64[1] = __PAIR64__((unsigned int)v7, (unsigned int)m_collisionShape);
  v187 = m_manifoldPtr->m_contactBreakingThreshold;
  v145 = v7->getMargin(v7);
  v40 = ((double (__thiscall *)(btConvexShape *))m_collisionShape->getMargin)(m_collisionShape);
  m_stackAllocator = dispatchInfo->m_stackAllocator;
  v41 = v40 + v145 + v187;
  p_m_worldTransform = &body1->m_worldTransform;
  transAa = &body0->m_worldTransform;
  v221 = v41 * v41;
  output = body0->m_worldTransform;
  m_worldTransform = body1->m_worldTransform;
  if ( m_collisionShape->m_shapeType >= 7
    || (v43 = v7, v44 = v7->m_shapeType, v44 >= 7)
    || (v39 = (btGjkPairDetector *)v141[16],
        *(float *)&debugDraw.__vftable = COERCE_FLOAT(&`btConvexConvexAlgorithm::processCollision'::`16'::btDummyResult::`vftable'),
        !v39) )
  {
LABEL_73:
    btGjkPairDetector::getClosestPointsNonVirtual(
      v39,
      &v223,
      (btDiscreteCollisionDetectorInterface::Result *)&output,
      resultOut,
      (int)dispatchInfo->m_debugDraw);
    if ( this->m_numPerturbationIterations )
    {
      if ( (int)resultOut[1].__vftable[12].drawTriangle < this->m_minimumPointsPerturbationThreshold )
      {
        v73 = (float)((float)(v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[0]
                            * v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[0])
                    + (float)(v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[1]
                            * v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[1]))
            + (float)(v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[2]
                    * v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[2]);
        if ( v73 > 0.00000011920929 )
        {
          v74 = v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[0] * (float)(s_bm_current_air_resistance / v73);
          v75 = v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[1] * (float)(s_bm_current_air_resistance / v73);
          v76 = v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[2] * (float)(s_bm_current_air_resistance / v73);
          v77 = v75 * v75;
          v166 = v74;
          v172 = v75;
          v177 = v76;
          maxDist = v75 * v75;
          if ( COERCE_FLOAT(LODWORD(v76) & _mask__AbsFloat_) <= hsqt2 )
          {
            v80 = s_bm_current_air_resistance / fsqrt((float)(v74 * v74) + v77);
            v81 = v80 * v75;
            v195 = v80 * v74;
            v79 = 0.0;
            LODWORD(v194) = LODWORD(v81) ^ _mask__NegFloat_;
          }
          else
          {
            v78 = s_bm_current_air_resistance / fsqrt((float)(v76 * v76) + v77);
            v194 = 0.0;
            LODWORD(v195) = COERCE_UNSIGNED_INT(v78 * v76) ^ _mask__NegFloat_;
            v79 = v78 * v75;
          }
          v82 = *v141;
          v196 = v79;
          *(float *)&debugDraw.__vftable = ((double (__thiscall *)(const btConvexPolyhedron **))(&v82->__vftable)[3])(v141);
          v158 = v7->getAngularMotionDisc(v7);
          v83 = (__m128i)LODWORD(gContactBreakingThreshold);
          if ( v158 <= (double)*(float *)&debugDraw.__vftable )
          {
            *(float *)v83.m128i_i32 = gContactBreakingThreshold / v158;
            ptrb = 0;
          }
          else
          {
            *(float *)v83.m128i_i32 = gContactBreakingThreshold / *(float *)&debugDraw.__vftable;
            ptrb = 1;
          }
          v155 = *(float *)v83.m128i_i32;
          if ( *(float *)v83.m128i_i32 > 0.39269909 )
          {
            v83 = (__m128i)LODWORD(FLOAT_0_39269909);
            v155 = FLOAT_0_39269909;
          }
          if ( ptrb )
          {
            v224.m_basis.m_el[0].mVec128.m128_u64[0] = output.m_basis.m_el[0].mVec128.m128_u64[0];
            v224.m_basis.m_el[0].mVec128.m128_u64[1] = output.m_basis.m_el[0].mVec128.m128_u64[1];
            v224.m_basis.m_el[1] = output.m_basis.m_el[1];
            v224.m_basis.m_el[2] = output.m_basis.m_el[2];
            p_m_origin = &output.m_origin;
          }
          else
          {
            v224.m_basis.m_el[0].mVec128.m128_u64[0] = m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
            v224.m_basis.m_el[0].mVec128.m128_u64[1] = m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
            v224.m_basis.m_el[1] = m_worldTransform.m_basis.m_el[1];
            v224.m_basis.m_el[2] = m_worldTransform.m_basis.m_el[2];
            p_m_origin = &m_worldTransform.m_origin;
          }
          v154 = 0;
          v85 = this->m_numPerturbationIterations <= 0;
          v224.m_origin.mVec128.m128_i32[0] = p_m_origin->mVec128.m128_i32[0];
          v86 = &p_m_origin->mVec128.m128_i32[1];
          v224.m_origin.mVec128.m128_i32[1] = *v86;
          v224.m_origin.mVec128.m128_u64[1] = *(_QWORD *)(v86 + 1);
          if ( !v85 )
          {
            v87 = (float)((float)(v194 * v194) + (float)(v196 * v196)) + (float)(v195 * v195);
            v151 = v87;
            do
            {
              if ( v87 > 0.00000011920929 )
              {
                v218.m_el[0].mVec128.m128_f32[3] = *(float *)v83.m128i_i32 * 0.5;
                *(double *)v83.m128i_i64 = (float)(*(float *)v83.m128i_i32 * 0.5);
                __libm_sse2_sin(v83);
                v88 = *(double *)v83.m128i_i64;
                v89 = v88 / fsqrt(v151);
                v179 = v89 * v194;
                v90 = v89 * v195;
                v182 = v89 * v196;
                v91 = v218.m_el[0].mVec128.m128_f32[3];
                v181 = v90;
                __libm_sse2_cos(v137);
                *(float *)&v91 = v91;
                v183 = *(float *)&v91;
                v92 = (__m128)LODWORD(pi_x2_13);
                v217 = (float)((float)(6.2831855 / (float)this->m_numPerturbationIterations) * (float)(int)v154) * 0.5;
                v92.m128_f32[0] = v217;
                v93 = (__m128i)_mm_cvtps_pd(v92);
                __libm_sse2_sin(v93);
                *(float *)v93.m128i_i32 = *(double *)v93.m128i_i64;
                *(float *)v93.m128i_i32 = *(float *)v93.m128i_i32
                                        / fsqrt((float)((float)(v166 * v166) + (float)(v177 * v177)) + maxDist);
                v191 = *(float *)v93.m128i_i32 * v166;
                v94 = *(float *)v93.m128i_i32 * v172;
                v193 = *(float *)v93.m128i_i32 * v177;
                *(double *)v93.m128i_i64 = v217;
                v192 = v94;
                __libm_sse2_cos(v138);
                v95 = *(double *)v93.m128i_i64;
                if ( ptrb )
                {
                  LODWORD(v96) = LODWORD(v94) ^ _mask__NegFloat_;
                  v97 = (float)((float)((float)(v183 * COERCE_FLOAT(LODWORD(v191) ^ _mask__NegFloat_))
                                      + (float)(v179 * v95))
                              + (float)(COERCE_FLOAT(LODWORD(v94) ^ _mask__NegFloat_) * v182))
                      - (float)(COERCE_FLOAT(LODWORD(v193) ^ _mask__NegFloat_) * v181);
                  LODWORD(v225[6]) = LODWORD(v193) ^ _mask__NegFloat_;
                  v98 = (float)((float)((float)(v181 * COERCE_FLOAT(LODWORD(v191) ^ _mask__NegFloat_))
                                      + (float)(COERCE_FLOAT(LODWORD(v193) ^ _mask__NegFloat_) * v183))
                              + (float)(v95 * v182))
                      - (float)(v179 * v96);
                  v99 = (float)((float)((float)(v179 * COERCE_FLOAT(LODWORD(v193) ^ _mask__NegFloat_))
                                      + (float)(v96 * v183))
                              + (float)(v95 * v181))
                      - (float)(v182 * COERCE_FLOAT(LODWORD(v191) ^ _mask__NegFloat_));
                  v100 = (float)((float)((float)(v95 * v183)
                                       - (float)(v179 * COERCE_FLOAT(LODWORD(v191) ^ _mask__NegFloat_)))
                               - (float)(v96 * v181))
                       - (float)(COERCE_FLOAT(LODWORD(v193) ^ _mask__NegFloat_) * v182);
                  v203.mVec128.m128_f32[0] = (float)((float)((float)(v95 * v97) + (float)(v100 * v191))
                                                   + (float)(v99 * v193))
                                           - (float)(v98 * v192);
                  v203.mVec128.m128_f32[1] = (float)((float)((float)(v98 * v191) + (float)(v99 * v95))
                                                   + (float)(v100 * v192))
                                           - (float)(v193 * v97);
                  v203.mVec128.m128_f32[2] = (float)((float)((float)(v192 * v97) + (float)(v98 * v95))
                                                   + (float)(v100 * v193))
                                           - (float)(v99 * v191);
                  v203.mVec128.m128_f32[3] = (float)((float)((float)(v100 * v95) - (float)(v97 * v191))
                                                   - (float)(v99 * v192))
                                           - (float)(v98 * v193);
                  btMatrix3x3::setRotation((const btQuaternion *)&v203, &v198);
                  v101 = body0->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2];
                  v102 = body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2];
                  v103 = body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1];
                  v218.m_el[0].mVec128.m128_f32[2] = (float)((float)(v198.m_el[2].mVec128.m128_f32[2] * v101)
                                                           + (float)(v198.m_el[2].mVec128.m128_f32[0]
                                                                   * body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]))
                                                   + (float)(v198.m_el[2].mVec128.m128_f32[1] * v102);
                  v104 = v198.m_el[2].mVec128.m128_f32[1] * body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0];
                  v105 = v198.m_el[2].mVec128.m128_f32[2] * body0->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
                  v205 = (float)((float)(v198.m_el[2].mVec128.m128_f32[0] * v103)
                               + (float)(v198.m_el[2].mVec128.m128_f32[1]
                                       * body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]))
                       + (float)(v198.m_el[2].mVec128.m128_f32[2]
                               * body0->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]);
                  v106 = (float)(v198.m_el[2].mVec128.m128_f32[0] * transAa->m_basis.m_el[0].mVec128.m128_f32[0]) + v104;
                  v107 = body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2];
                  v207 = v106 + v105;
                  v209 = (float)((float)(v198.m_el[1].mVec128.m128_f32[2] * v101)
                               + (float)(v198.m_el[1].mVec128.m128_f32[0] * v107))
                       + (float)(v198.m_el[1].mVec128.m128_f32[1] * v102);
                  v108 = body0->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1];
                  v211 = (float)((float)(v198.m_el[1].mVec128.m128_f32[0]
                                       * body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1])
                               + (float)(v198.m_el[1].mVec128.m128_f32[1]
                                       * body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]))
                       + (float)(v198.m_el[1].mVec128.m128_f32[2] * v108);
                  v109 = body0->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
                  v110 = body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2];
                  v213 = (float)((float)(v198.m_el[1].mVec128.m128_f32[0]
                                       * body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0])
                               + (float)(v198.m_el[1].mVec128.m128_f32[1]
                                       * body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0]))
                       + (float)(v198.m_el[1].mVec128.m128_f32[2] * v109);
                  v111 = (float)((float)(v198.m_el[0].mVec128.m128_f32[2] * v101)
                               + (float)(v198.m_el[0].mVec128.m128_f32[0] * v110))
                       + (float)(v198.m_el[0].mVec128.m128_f32[1] * v102);
                  v112 = v198.m_el[0].mVec128.m128_f32[0] * body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1];
                  v113 = body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1];
                  v218.m_el[1].mVec128.m128_f32[0] = v111;
                  v114 = (float)((float)(v198.m_el[0].mVec128.m128_f32[0]
                                       * body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0])
                               + (float)(v198.m_el[0].mVec128.m128_f32[1]
                                       * body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0]))
                       + (float)(v198.m_el[0].mVec128.m128_f32[2] * v109);
                  v206 = (float)(v112 + (float)(v198.m_el[0].mVec128.m128_f32[1] * v113))
                       + (float)(v198.m_el[0].mVec128.m128_f32[2] * v108);
                  v218.m_el[0].mVec128.m128_f32[1] = v114;
                  btMatrix3x3::setValue(
                    (btMatrix3x3 *)&v218.m_el[0].m_floats[1],
                    (int)&v223.m_transformB.m_basis.m_el[2],
                    &v206,
                    v218.m_el[1].mVec128.m128_f32,
                    &v213,
                    &v211,
                    &v209,
                    &v207,
                    &v205,
                    &v218.m_el[0].mVec128.m128_f32[2],
                    (const float *)LODWORD(v137));
                  output.m_basis.m_el[0] = v223.m_transformB.m_basis.m_el[2];
                  output.m_basis.m_el[1] = v223.m_transformB.m_origin;
                  output.m_basis.m_el[2] = *(btVector3 *)&v223.m_maximumDistanceSquared;
                  m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0] = p_m_worldTransform->m_basis.m_el[0].mVec128.m128_u64[0];
                  m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1] = body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
                  m_worldTransform.m_basis.m_el[1] = body1->m_worldTransform.m_basis.m_el[1];
                  m_worldTransform.m_basis.m_el[2] = body1->m_worldTransform.m_basis.m_el[2];
                  p_m_maximumDistanceSquared = &body1->m_worldTransform.m_origin;
                  v116 = &m_worldTransform.m_origin;
                }
                else
                {
                  output.m_basis.m_el[0].mVec128.m128_u64[0] = transAa->m_basis.m_el[0].mVec128.m128_u64[0];
                  output.m_basis.m_el[0].mVec128.m128_u64[1] = body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
                  LODWORD(v117) = LODWORD(v94) ^ _mask__NegFloat_;
                  output.m_basis.m_el[1] = body0->m_worldTransform.m_basis.m_el[1];
                  output.m_basis.m_el[2] = body0->m_worldTransform.m_basis.m_el[2];
                  v118 = (float)((float)((float)(v179 * v95)
                                       + (float)(v183 * COERCE_FLOAT(LODWORD(v191) ^ _mask__NegFloat_)))
                               + (float)(COERCE_FLOAT(LODWORD(v94) ^ _mask__NegFloat_) * v182))
                       - (float)(COERCE_FLOAT(LODWORD(v193) ^ _mask__NegFloat_) * v181);
                  v119 = (float)((float)((float)(v179 * COERCE_FLOAT(LODWORD(v193) ^ _mask__NegFloat_))
                                       + (float)(v117 * v183))
                               + (float)(v95 * v181))
                       - (float)(v182 * COERCE_FLOAT(LODWORD(v191) ^ _mask__NegFloat_));
                  v218.m_el[2].mVec128.m128_i32[0] = LODWORD(v193) ^ _mask__NegFloat_;
                  output.m_origin = body0->m_worldTransform.m_origin;
                  v120 = (float)((float)((float)(v181 * COERCE_FLOAT(LODWORD(v191) ^ _mask__NegFloat_))
                                       + (float)(COERCE_FLOAT(LODWORD(v193) ^ _mask__NegFloat_) * v183))
                               + (float)(v95 * v182))
                       - (float)(v179 * v117);
                  v121 = (float)((float)((float)(v95 * v183)
                                       - (float)(v179 * COERCE_FLOAT(LODWORD(v191) ^ _mask__NegFloat_)))
                               - (float)(v117 * v181))
                       - (float)(COERCE_FLOAT(LODWORD(v193) ^ _mask__NegFloat_) * v182);
                  sep.mVec128.m128_f32[0] = (float)((float)((float)(v121 * v191) + (float)(v95 * v118))
                                                  + (float)(v119 * v193))
                                          - (float)(v120 * v192);
                  sep.mVec128.m128_f32[1] = (float)((float)((float)(v120 * v191) + (float)(v119 * v95))
                                                  + (float)(v121 * v192))
                                          - (float)(v193 * v118);
                  sep.mVec128.m128_f32[2] = (float)((float)((float)(v192 * v118) + (float)(v120 * v95))
                                                  + (float)(v121 * v193))
                                          - (float)(v119 * v191);
                  sep.mVec128.m128_f32[3] = (float)((float)((float)(v121 * v95) - (float)(v118 * v191))
                                                  - (float)(v119 * v192))
                                          - (float)(v120 * v193);
                  btMatrix3x3::setRotation((const btQuaternion *)&sep, &v198);
                  v122 = body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2];
                  v123 = body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2];
                  v124 = body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2];
                  v159 = body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1];
                  debugDraw.__vftable = (btIDebugDraw_vtbl *)LODWORD(body1->m_worldTransform.m_basis.m_el[1].m_floats[1]);
                  v208 = (float)((float)(v122 * v198.m_el[2].mVec128.m128_f32[1])
                               + (float)(v198.m_el[2].mVec128.m128_f32[2] * v123))
                       + (float)(v124 * v198.m_el[2].mVec128.m128_f32[0]);
                  v125 = body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1];
                  v126 = body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_i32[0];
                  v127 = body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
                  v204 = (float)((float)(v198.m_el[2].mVec128.m128_f32[2] * v159)
                               + (float)(v125 * v198.m_el[2].mVec128.m128_f32[0]))
                       + (float)(*(float *)&debugDraw.__vftable * v198.m_el[2].mVec128.m128_f32[1]);
                  v144 = *(float *)&v126;
                  v128 = p_m_worldTransform->m_basis.m_el[0].mVec128.m128_f32[0];
                  v210 = (float)((float)(v127 * v198.m_el[2].mVec128.m128_f32[2])
                               + (float)(p_m_worldTransform->m_basis.m_el[0].mVec128.m128_f32[0]
                                       * v198.m_el[2].mVec128.m128_f32[0]))
                       + (float)(v144 * v198.m_el[2].mVec128.m128_f32[1]);
                  v218.m_el[1].mVec128.m128_f32[1] = (float)((float)(v122 * v198.m_el[1].mVec128.m128_f32[1])
                                                           + (float)(v123 * v198.m_el[1].mVec128.m128_f32[2]))
                                                   + (float)(v124 * v198.m_el[1].mVec128.m128_f32[0]);
                  v214 = (float)((float)(v123 * v198.m_el[0].mVec128.m128_f32[2])
                               + (float)(v124 * v198.m_el[0].mVec128.m128_f32[0]))
                       + (float)(v122 * v198.m_el[0].mVec128.m128_f32[1]);
                  v212 = (float)((float)(v125 * v198.m_el[1].mVec128.m128_f32[0])
                               + (float)(*(float *)&debugDraw.__vftable * v198.m_el[1].mVec128.m128_f32[1]))
                       + (float)(v159 * v198.m_el[1].mVec128.m128_f32[2]);
                  v215 = (float)((float)(v128 * v198.m_el[1].mVec128.m128_f32[0])
                               + (float)(v144 * v198.m_el[1].mVec128.m128_f32[1]))
                       + (float)(v127 * v198.m_el[1].mVec128.m128_f32[2]);
                  v216 = (float)((float)(v125 * v198.m_el[0].mVec128.m128_f32[0])
                               + (float)(*(float *)&debugDraw.__vftable * v198.m_el[0].mVec128.m128_f32[1]))
                       + (float)(v159 * v198.m_el[0].mVec128.m128_f32[2]);
                  v218.m_el[0].mVec128.m128_f32[0] = (float)((float)(v128 * v198.m_el[0].mVec128.m128_f32[0])
                                                           + (float)(v144 * v198.m_el[0].mVec128.m128_f32[1]))
                                                   + (float)(v127 * v198.m_el[0].mVec128.m128_f32[2]);
                  btMatrix3x3::setValue(
                    &v218,
                    (int)&v223.m_transformB.m_basis.m_el[2],
                    &v216,
                    &v214,
                    &v215,
                    &v212,
                    &v218.m_el[1].mVec128.m128_f32[1],
                    &v210,
                    &v204,
                    &v208,
                    (const float *)LODWORD(v137));
                  m_worldTransform.m_basis.m_el[0] = v223.m_transformB.m_basis.m_el[2];
                  m_worldTransform.m_basis.m_el[1] = v223.m_transformB.m_origin;
                  p_m_maximumDistanceSquared = (btVector3 *)&v223.m_maximumDistanceSquared;
                  v116 = &m_worldTransform.m_basis.m_el[2];
                }
                v116->mVec128.m128_i32[0] = p_m_maximumDistanceSquared->mVec128.m128_i32[0];
                v130 = &p_m_maximumDistanceSquared->mVec128.m128_i32[1];
                v129 = &v116->mVec128.m128_i32[1];
                *v129 = *v130++;
                *++v129 = *v130;
                v129[1] = v130[1];
                btPerturbedContactResult::btPerturbedContactResult(
                  &v226,
                  &v224,
                  (btManifoldResult *)resultOut,
                  &output,
                  &m_worldTransform,
                  ptrb,
                  dispatchInfo->m_debugDraw);
                btGjkPairDetector::getClosestPointsNonVirtual(
                  v131,
                  &v223,
                  (btDiscreteCollisionDetectorInterface::Result *)&output,
                  (btIDebugDraw *)&v226,
                  (int)dispatchInfo->m_debugDraw);
                v83 = (__m128i)LODWORD(v155);
                v87 = v151;
              }
              ++v154;
            }
            while ( (int)v154 < this->m_numPerturbationIterations );
          }
        }
      }
    }
    if ( this->m_ownManifold )
    {
      v132 = resultOut[1].__vftable;
      if ( v132[12].drawTriangle )
      {
        v134 = resultOut[1].__vftable;
        if ( v132[12].drawSphere == (void (__thiscall *)(btIDebugDraw *, const btVector3 *, float, const btVector3 *))resultOut[36].__vftable )
        {
          v36 = resultOut + 20;
          v37 = resultOut + 4;
        }
        else
        {
          v36 = resultOut + 4;
          v37 = resultOut + 20;
        }
        goto LABEL_100;
      }
    }
    return;
  }
  v45 = (btConvexPolyhedron *)v7[5].m_shapeType;
  if ( !v45 )
  {
    if ( v44 == 1 )
    {
      v52 = *(float *)&v7[7].m_shapeType;
      v53 = *(float *)&v7[7].__vftable;
      v54 = *(float *)&v7[6].m_userPointer;
      v163 = (float)((float)((float)(body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v53)
                           + (float)(body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2] * v52))
                   + (float)(body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0] * v54))
           + body1->m_worldTransform.m_origin.mVec128.m128_f32[0];
      v169 = (float)((float)((float)(body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v53)
                           + (float)(body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v52))
                   + (float)(body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v54))
           + body1->m_worldTransform.m_origin.mVec128.m128_f32[1];
      v174 = (float)((float)((float)(body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v53)
                           + (float)(body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v52))
                   + (float)(body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0] * v54))
           + body1->m_worldTransform.m_origin.mVec128.m128_f32[2];
      v55 = (float *)btAlignedAllocInternal(0x10u);
      ptra = v55;
      if ( v55 )
      {
        *v55 = v163;
        v55[1] = v169;
        v55[2] = v174;
        v55[3] = 0.0;
        v43 = v7;
      }
      v56 = *(float *)&v43[8].m_shapeType;
      v57 = *(float *)&v43[8].m_userPointer;
      v58 = *(float *)&v43[8].__vftable;
      v164 = (float)((float)((float)(body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v56)
                           + (float)(body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2] * v57))
                   + (float)(body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0] * v58))
           + body1->m_worldTransform.m_origin.mVec128.m128_f32[0];
      v170 = (float)((float)((float)(body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v56)
                           + (float)(body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v57))
                   + (float)(body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v58))
           + body1->m_worldTransform.m_origin.mVec128.m128_f32[1];
      v175 = (float)((float)((float)(body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v56)
                           + (float)(body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v57))
                   + (float)(v58 * body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0]))
           + body1->m_worldTransform.m_origin.mVec128.m128_f32[2];
      v59 = (float *)btAlignedAllocInternal(0x20u);
      v153 = v59;
      if ( v59 )
      {
        *v59 = *ptra;
        v59[1] = ptra[1];
        v59[2] = ptra[2];
        v59[3] = ptra[3];
        v43 = v7;
      }
      if ( ptra )
        btAlignedFreeInternal(ptra);
      if ( v153 != (float *)-16 )
      {
        v153[4] = v164;
        v153[5] = v170;
        v153[6] = v175;
        v153[7] = 0.0;
        v43 = v7;
      }
      v60 = *(float *)&v43[10].__vftable;
      v61 = *(float *)&v43[9].m_userPointer;
      v62 = *(float *)&v43[9].m_shapeType;
      v165 = (float)((float)((float)(body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v61)
                           + (float)(body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2] * v60))
                   + (float)(body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0] * v62))
           + body1->m_worldTransform.m_origin.mVec128.m128_f32[0];
      v171 = (float)((float)((float)(body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v61)
                           + (float)(body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v60))
                   + (float)(body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v62))
           + body1->m_worldTransform.m_origin.mVec128.m128_f32[1];
      v176 = (float)((float)((float)(body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v61)
                           + (float)(body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v60))
                   + (float)(body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0] * v62))
           + body1->m_worldTransform.m_origin.mVec128.m128_f32[2];
      v63 = (char *)btAlignedAllocInternal(0x40u);
      v64 = (int)v63;
      v65 = (btGjkPairDetector *)((char *)v153 - v63);
      v66 = 2;
      do
      {
        if ( v63 )
        {
          *(_DWORD *)v63 = *(_DWORD *)&v63[(_DWORD)v65];
          *((_DWORD *)v63 + 1) = *(_DWORD *)&v63[(_DWORD)v65 + 4];
          *((_DWORD *)v63 + 2) = *(_DWORD *)&v63[(_DWORD)v65 + 8];
          *((_DWORD *)v63 + 3) = *(_DWORD *)&v63[(_DWORD)v65 + 12];
        }
        v63 += 16;
        --v66;
      }
      while ( v66 );
      if ( v153 )
      {
        btAlignedFreeInternal(v153);
        v65 = v135;
      }
      v218.m_el[2].mVec128.m128_i8[8] = 1;
      v218.m_el[2].mVec128.m128_i32[1] = v64;
      v218.m_el[2].mVec128.m128_i32[0] = 4;
      if ( v64 != -32 )
      {
        *(float *)(v64 + 32) = v165;
        *(float *)(v64 + 36) = v171;
        *(float *)(v64 + 40) = v176;
        *(_DWORD *)(v64 + 44) = 0;
      }
      v67 = this->m_manifoldPtr->m_contactBreakingThreshold;
      m_debugDraw = dispatchInfo->m_debugDraw;
      v218.m_el[1].mVec128.m128_i32[3] = 3;
      btGjkPairDetector::getClosestPointsNonVirtual(
        v65,
        &v223,
        (btDiscreteCollisionDetectorInterface::Result *)&output,
        &debugDraw,
        (int)m_debugDraw);
      v69 = (float)((float)(v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[0]
                          * v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[0])
                  + (float)(v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[1]
                          * v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[1]))
          + (float)(v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[2]
                  * v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[2]);
      if ( v69 > 0.00000011920929 )
      {
        v149 = v223.m_transformB.m_basis.m_el[0].mVec128.m128_f32[1];
        sep.mVec128.m128_f32[0] = v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[0]
                                * (float)(s_bm_current_air_resistance / v69);
        sep.mVec128.m128_f32[1] = v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[1]
                                * (float)(s_bm_current_air_resistance / v69);
        sep.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                                    v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[2]
                                  * (float)(s_bm_current_air_resistance / v69));
        v150 = v149 - ((double (__thiscall *)(const btConvexPolyhedron **))(*v141)->m_faces.m_size)(v141);
        minDist = v150 - ((double (__thiscall *)(btCollisionShape *))v7->getMargin)(v7) - v67;
        btPolyhedralContactClipping::clipFaceAgainstHull(
          (btAlignedObjectArray<btVector3> *)&v218.m_el[1].m_floats[2],
          &sep,
          v141[16],
          transAa,
          minDist,
          v67,
          (btDiscreteCollisionDetectorInterface::Result *)resultOut);
      }
      if ( this->m_ownManifold )
      {
        v70 = resultOut[1].__vftable;
        if ( v70[12].drawTriangle )
        {
          if ( v70[12].drawSphere == (void (__thiscall *)(btIDebugDraw *, const btVector3 *, float, const btVector3 *))resultOut[36].__vftable )
          {
            v71 = resultOut + 20;
            v72 = resultOut + 4;
          }
          else
          {
            v71 = resultOut + 4;
            v72 = resultOut + 20;
          }
          btPersistentManifold::refreshContactPoints(
            (btPersistentManifold *)v71,
            (const btTransform *)v72,
            (btPersistentManifold *)resultOut[1].__vftable);
        }
      }
      btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
        v68,
        (int)&v218.m_el[1].mVec128.m128_i32[2]);
      return;
    }
    goto LABEL_73;
  }
  v46 = !dispatchInfo->m_enableSatConvex;
  maxDist = this->m_manifoldPtr->m_contactBreakingThreshold;
  v157 = FLOAT_N1_0e30;
  if ( v46 )
  {
    btGjkPairDetector::getClosestPointsNonVirtual(
      v39,
      &v223,
      (btDiscreteCollisionDetectorInterface::Result *)&output,
      &debugDraw,
      (int)dispatchInfo->m_debugDraw);
    v48 = (float)((float)(v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[0]
                        * v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[0])
                + (float)(v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[1]
                        * v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[1]))
        + (float)(v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[2]
                * v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[2]);
    if ( v48 <= 0.00000011920929 )
      goto LABEL_40;
    v146 = v223.m_transformB.m_basis.m_el[0].mVec128.m128_f32[1];
    v49 = *v141;
    sep.mVec128.m128_f32[0] = v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[0]
                            * (float)(s_bm_current_air_resistance / v48);
    sep.mVec128.m128_f32[1] = v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[1]
                            * (float)(s_bm_current_air_resistance / v48);
    sep.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                                v223.m_transformA.m_basis.m_el[1].mVec128.m128_f32[2]
                              * (float)(s_bm_current_air_resistance / v48));
    v43 = v7;
    v147 = v146 - ((double (__thiscall *)(const btConvexPolyhedron **))v49->m_faces.m_size)(v141);
    v157 = v147 - ((double (__thiscall *)(btCollisionShape *))v7->getMargin)(v7);
    v188 = v223.m_transformB.m_basis.m_el[0].mVec128.m128_f32[1];
    v148 = v7->getMargin(v7);
    if ( ((double (__thiscall *)(const btConvexPolyhedron **))(*v141)->m_faces.m_size)(v141) + v148 > v188 )
      goto LABEL_40;
    SeparatingAxis = 0;
  }
  else
  {
    SeparatingAxis = btPolyhedralContactClipping::findSeparatingAxis(
                       (btConvexPolyhedron *)v39,
                       v45,
                       transAa,
                       p_m_worldTransform,
                       &sep);
  }
  if ( !SeparatingAxis )
  {
    v50 = resultOut;
    goto LABEL_42;
  }
LABEL_40:
  v50 = resultOut;
  btPolyhedralContactClipping::clipHullAgainstHull(
    &sep,
    v141[16],
    (const btConvexPolyhedron *)v43[5].m_shapeType,
    transAa,
    p_m_worldTransform,
    v157 - maxDist,
    maxDist,
    (btDiscreteCollisionDetectorInterface::Result *)resultOut);
LABEL_42:
  if ( this->m_ownManifold )
  {
    v51 = v50[1].__vftable;
    if ( v51[12].drawTriangle )
    {
      v134 = v50[1].__vftable;
      if ( v51[12].drawSphere == (void (__thiscall *)(btIDebugDraw *, const btVector3 *, float, const btVector3 *))v50[36].__vftable )
      {
        v36 = v50 + 20;
        v37 = v50 + 4;
      }
      else
      {
        v36 = v50 + 4;
        v37 = v50 + 20;
      }
      goto LABEL_100;
    }
  }
}
