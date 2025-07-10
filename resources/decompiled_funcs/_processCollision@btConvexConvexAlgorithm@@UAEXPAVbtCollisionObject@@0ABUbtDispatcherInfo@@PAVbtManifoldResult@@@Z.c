void __thiscall btConvexConvexAlgorithm::processCollision(
        btConvexConvexAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        const btDispatcherInfo *dispatchInfo,
        btManifoldResult *resultOut)
{
  bool v6; // zf
  const btConvexShape *m_collisionShape; // esi
  btCollisionShape *v8; // edi
  int m_shapeType; // eax
  btConvexShape_vtbl *v10; // ecx
  float v11; // xmm0_4
  btIDebugDraw v12; // eax
  const btTransform *v13; // xmm0_4
  int v14; // esi
  float v15; // xmm6_4
  float v16; // xmm7_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm6_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm7_4
  unsigned int v30; // xmm2_4
  unsigned int v31; // xmm7_4
  float v32; // xmm5_4
  float v33; // xmm4_4
  long double v34; // st7
  long double v35; // st7
  float v36; // xmm1_4
  long double v37; // st7
  float v38; // xmm0_4
  long double v39; // st7
  float v40; // xmm5_4
  float v41; // xmm0_4
  float v42; // xmm3_4
  unsigned int v43; // xmm1_4
  btPersistentManifold *m_manifoldPtr; // eax
  int v45; // ecx
  float v46; // esi
  float (__thiscall *getMargin)(btCollisionShape *); // eax
  double v48; // st7
  __int64 v49; // xmm0_8
  btStackAlloc *m_stackAllocator; // edx
  btTransform *p_m_worldTransform; // ebx
  unsigned __int64 v52; // xmm0_8
  bool v53; // cc
  int v54; // edx
  const btConvexPolyhedron *v55; // eax
  const btConvexPolyhedron *v56; // ecx
  btPersistentManifold *v57; // esi
  float v58; // xmm1_4
  int v59; // edx
  double (__thiscall *v60)(_DWORD); // eax
  double v61; // st7
  float (__thiscall *v62)(btCollisionShape *); // eax
  double v63; // st7
  float (__thiscall *v64)(btCollisionShape *); // eax
  double v65; // st7
  int v66; // edx
  double v67; // st7
  float v68; // xmm2_4
  float v69; // xmm1_4
  float v70; // xmm0_4
  float v71; // xmm4_4
  float v72; // xmm3_4
  float v73; // xmm3_4
  float v74; // xmm4_4
  float v75; // xmm3_4
  float v76; // xmm4_4
  float v77; // xmm0_4
  btVector3 *v78; // eax
  float v79; // xmm2_4
  float v80; // xmm1_4
  float v81; // xmm0_4
  float v82; // xmm4_4
  float v83; // xmm3_4
  float v84; // xmm3_4
  float v85; // xmm4_4
  float v86; // xmm3_4
  float v87; // xmm4_4
  float v88; // xmm0_4
  btVector3 *v89; // esi
  _QWORD *v90; // eax
  float v91; // xmm0_4
  float v92; // xmm1_4
  float v93; // xmm2_4
  float v94; // xmm3_4
  float v95; // xmm4_4
  btVector3 *v96; // eax
  btVector3 *v97; // ebx
  int v98; // ecx
  int v99; // edx
  btVector3 *v100; // ebx
  int v101; // xmm0_4
  btPairSet *v102; // ecx
  float v103; // xmm1_4
  float v104; // ebx
  double (__thiscall *v105)(_DWORD); // eax
  double v106; // st7
  float (__thiscall *v107)(btCollisionShape *); // eax
  double v108; // st7
  btManifoldResult *v109; // esi
  btPersistentManifold *v110; // eax
  btPairSet *v111; // ecx
  float v112; // esi
  btManifoldResult *v113; // edx
  float v114; // xmm1_4
  long double v115; // st7
  long double v116; // st7
  double v117; // st7
  float v118; // xmm0_4
  btVector3 v119; // xmm0
  float v120; // xmm0_4
  float v121; // xmm0_4
  float v122; // xmm1_4
  float v123; // xmm3_4
  float v124; // xmm2_4
  float v125; // xmm6_4
  unsigned int v126; // xmm3_4
  unsigned int v127; // xmm4_4
  unsigned int v128; // xmm5_4
  unsigned int v129; // xmm6_4
  unsigned int v130; // xmm0_4
  float v131; // xmm7_4
  float v132; // xmm2_4
  float v133; // xmm1_4
  float v134; // xmm7_4
  float v135; // xmm2_4
  float v136; // xmm0_4
  float v137; // xmm3_4
  float v138; // xmm1_4
  float v139; // xmm6_4
  unsigned int v140; // xmm3_4
  unsigned int v141; // xmm4_4
  unsigned int v142; // xmm5_4
  float v143; // xmm6_4
  float v144; // xmm7_4
  unsigned int v145; // xmm6_4
  unsigned int v146; // xmm0_4
  float v147; // xmm7_4
  unsigned int v148; // xmm2_4
  btVector3 v149; // xmm0
  btVector3 v150; // xmm0
  btPersistentManifold *v151; // eax
  float v152; // [esp+55F4h] [ebp-43Ch]
  float _Xd; // [esp+55FCh] [ebp-434h]
  btPersistentManifold *_X; // [esp+55FCh] [ebp-434h]
  btPersistentManifold *_Xa; // [esp+55FCh] [ebp-434h]
  btPersistentManifold *_Xb; // [esp+55FCh] [ebp-434h]
  btPersistentManifold *_Xc; // [esp+55FCh] [ebp-434h]
  btIDebugDraw debugDraw; // [esp+560Ch] [ebp-424h] BYREF
  float maxDist; // [esp+5610h] [ebp-420h]
  void *ptr; // [esp+5614h] [ebp-41Ch] BYREF
  btQuaternion v161; // [esp+5618h] [ebp-418h] BYREF
  float v162; // [esp+5628h] [ebp-408h]
  float v163; // [esp+562Ch] [ebp-404h]
  btQuaternion v164; // [esp+5630h] [ebp-400h] BYREF
  const btTransform *transA[2]; // [esp+5648h] [ebp-3E8h] BYREF
  btVector3 axis; // [esp+5650h] [ebp-3E0h] BYREF
  btMatrix3x3 v167; // [esp+5660h] [ebp-3D0h] BYREF
  float v168; // [esp+5690h] [ebp-3A0h] BYREF
  float v169; // [esp+5694h] [ebp-39Ch]
  float v170; // [esp+5698h] [ebp-398h]
  float v171; // [esp+56A0h] [ebp-390h]
  float v172; // [esp+56A4h] [ebp-38Ch]
  float v173; // [esp+56A8h] [ebp-388h]
  float v174; // [esp+56B0h] [ebp-380h]
  float v175; // [esp+56B4h] [ebp-37Ch]
  float v176; // [esp+56B8h] [ebp-378h]
  __m128i v177; // [esp+56C0h] [ebp-370h] BYREF
  __m128i v178; // [esp+56D0h] [ebp-360h] BYREF
  __m128i v179; // [esp+56E0h] [ebp-350h] BYREF
  float v180; // [esp+56F8h] [ebp-338h]
  float v181; // [esp+56FCh] [ebp-334h]
  float v182; // [esp+5700h] [ebp-330h]
  float v183; // [esp+5704h] [ebp-32Ch]
  unsigned int sep; // [esp+5708h] [ebp-328h]
  unsigned int sep_4; // [esp+570Ch] [ebp-324h]
  btVector3 sep_8; // [esp+5710h] [ebp-320h] BYREF
  btAlignedObjectArray<btVector3> worldVertsB1_8; // [esp+5720h] [ebp-310h] BYREF
  __m128i output_8; // [esp+5740h] [ebp-2F0h] BYREF
  __m128i v189; // [esp+5750h] [ebp-2E0h] BYREF
  __m128i v190; // [esp+5760h] [ebp-2D0h] BYREF
  unsigned __int64 v191; // [esp+5770h] [ebp-2C0h] BYREF
  btTransform transformB; // [esp+5778h] [ebp-2B8h] BYREF
  unsigned __int64 v193; // [esp+57B8h] [ebp-278h]
  float v194; // [esp+57C0h] [ebp-270h]
  btStackAlloc *v195; // [esp+57C4h] [ebp-26Ch]
  _QWORD separatingNormal[3]; // [esp+57C8h] [ebp-268h] BYREF
  btMatrix3x3 v197; // [esp+57E0h] [ebp-250h] BYREF
  float v198; // [esp+5818h] [ebp-218h]
  btCollisionShape *v199; // [esp+581Ch] [ebp-214h]
  const btTransform *v200; // [esp+5834h] [ebp-1FCh]
  btTransform v201; // [esp+5850h] [ebp-1E0h]
  __m128i si128; // [esp+5890h] [ebp-1A0h] BYREF
  btPerturbedContactResult v203; // [esp+58A0h] [ebp-190h] BYREF

  v6 = this->m_manifoldPtr == 0;
  LODWORD(v161.m_floats[1]) = this;
  if ( v6 )
  {
    this->m_manifoldPtr = this->m_dispatcher->getNewManifold(this->m_dispatcher, body0, body1);
    this->m_ownManifold = 1;
  }
  resultOut->m_manifoldPtr = this->m_manifoldPtr;
  m_collisionShape = (const btConvexShape *)body0->m_collisionShape;
  v8 = body1->m_collisionShape;
  LODWORD(v161.m_floats[0]) = m_collisionShape;
  if ( m_collisionShape->m_shapeType == 10 && v8->m_shapeType == 10 )
  {
    m_collisionShape->getLocalScaling((struct btConvexShape *)m_collisionShape);
    v8->getLocalScaling(v8);
    m_shapeType = v8[5].m_shapeType;
    v10 = m_collisionShape[4].__vftable;
    v161.m_floats[0] = *(float *)(*(_DWORD *)(LODWORD(v161.m_floats[1]) + 20) + 1180);
    v11 = *((float *)&v8[2].m_userPointer + m_shapeType);
    v12.__vftable = (btIDebugDraw_vtbl *)m_collisionShape[4].__vftable;
    maxDist = v11;
    debugDraw.__vftable = v12.__vftable;
    axis.mVec128 = (__m128)body1->m_worldTransform.m_origin;
    v161.m_floats[1] = *((float *)&m_collisionShape[2].__vftable + ((int)&v10->~btConvexShape + 2) % 3);
    v13 = (const btTransform *)*((_DWORD *)&m_collisionShape[2].__vftable + (int)v12.__vftable);
    v14 = v8[5].m_shapeType;
    v15 = body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[(int)v12.__vftable];
    v16 = body0->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[(int)v12.__vftable];
    v17 = body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[v14];
    v18 = body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[(int)v12.__vftable];
    transA[0] = v13;
    v164.m_floats[2] = v17;
    v161.m_floats[2] = v18;
    v162 = v16;
    v161.m_floats[3] = v15;
    ptr = *(&v8[2].m_userPointer + (v14 + 2) % 3);
    v167.m_el[0] = body0->m_worldTransform.m_origin;
    v19 = axis.mVec128.m128_f32[0] - v167.m_el[0].mVec128.m128_f32[0];
    LODWORD(v164.m_floats[0]) = body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[v14];
    LODWORD(v164.m_floats[1]) = body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_i32[v14];
    v20 = (float)((float)(v17 * v16) + (float)(v164.m_floats[1] * v15)) + (float)(v164.m_floats[0] * v18);
    v21 = (float)((float)((float)(axis.mVec128.m128_f32[2] - v167.m_el[0].mVec128.m128_f32[2]) * v16)
                + (float)((float)(axis.mVec128.m128_f32[0] - v167.m_el[0].mVec128.m128_f32[0]) * v18))
        + (float)((float)(axis.mVec128.m128_f32[1] - v167.m_el[0].mVec128.m128_f32[1]) * v15);
    *(float *)&debugDraw.__vftable = v21;
    v22 = (float)((float)((float)(axis.mVec128.m128_f32[2] - v167.m_el[0].mVec128.m128_f32[2]) * v164.m_floats[2])
                + (float)((float)(axis.mVec128.m128_f32[1] - v167.m_el[0].mVec128.m128_f32[1]) * v164.m_floats[1]))
        + (float)((float)(axis.mVec128.m128_f32[0] - v167.m_el[0].mVec128.m128_f32[0]) * v164.m_floats[0]);
    v23 = *(float *)&clear_value - (float)(v20 * v20);
    if ( v23 == 0.0 )
    {
      v24 = 0.0;
    }
    else
    {
      v24 = (float)(v21 - (float)(v22 * v20)) / v23;
      v25 = -*(float *)transA;
      if ( (float)-*(float *)transA > v24 || (v25 = *(float *)transA, v24 > *(float *)transA) )
        v24 = v25;
    }
    v26 = (float)(v20 * v24) - v22;
    if ( (float)-maxDist <= v26 )
    {
      if ( v26 <= maxDist )
        goto LABEL_18;
      v26 = maxDist;
      v27 = v20 * maxDist;
    }
    else
    {
      v26 = -maxDist;
      v27 = v20 * (float)-maxDist;
    }
    v24 = v27 + *(float *)&debugDraw.__vftable;
    if ( (float)-*(float *)transA <= (float)(v27 + *(float *)&debugDraw.__vftable) )
    {
      if ( v24 > *(float *)transA )
        v24 = *(float *)transA;
    }
    else
    {
      v24 = -*(float *)transA;
    }
LABEL_18:
    axis.mVec128.m128_f32[0] = v164.m_floats[0] * v26;
    v28 = (float)(v19 - (float)(v161.m_floats[2] * v24)) + (float)(v164.m_floats[0] * v26);
    v29 = v26;
    *(float *)&v30 = v26 * v164.m_floats[2];
    *(float *)&v31 = v29 * v164.m_floats[1];
    v32 = (float)((float)(axis.mVec128.m128_f32[2] - v167.m_el[0].mVec128.m128_f32[2]) - (float)(v24 * v162))
        + *(float *)&v30;
    v164.m_floats[0] = v28;
    v33 = (float)((float)(axis.mVec128.m128_f32[1] - v167.m_el[0].mVec128.m128_f32[1]) - (float)(v24 * v161.m_floats[3]))
        + *(float *)&v31;
    maxDist = (float)((float)(v164.m_floats[0] * v164.m_floats[0]) + (float)(v32 * v32)) + (float)(v33 * v33);
    *(unsigned __int64 *)((char *)axis.mVec128.m128_u64 + 4) = __PAIR64__(v30, v31);
    v164.m_floats[1] = v33;
    v164.m_floats[2] = v32;
    v34 = sqrtf(maxDist) - v161.m_floats[1] - *(float *)&ptr;
    *(float *)&debugDraw.__vftable = v34;
    if ( v34 > v161.m_floats[0] )
    {
LABEL_26:
      if ( v161.m_floats[0] > *(float *)&debugDraw.__vftable )
      {
        _Xd = v34;
        ((void (__thiscall *)(btManifoldResult *, btVector3 *, __m128i *, _DWORD))resultOut->addContactPoint)(
          resultOut,
          &v167.m_el[2],
          &si128,
          LODWORD(_Xd));
      }
      m_manifoldPtr = resultOut->m_manifoldPtr;
      if ( m_manifoldPtr->m_cachedPoints )
      {
        _X = resultOut->m_manifoldPtr;
        if ( m_manifoldPtr->m_body0 == resultOut->m_body0 )
          btPersistentManifold::refreshContactPoints(_X, &resultOut->m_rootTransA, &resultOut->m_rootTransB);
        else
          btPersistentManifold::refreshContactPoints(_X, &resultOut->m_rootTransB, &resultOut->m_rootTransA);
      }
      return;
    }
    if ( maxDist > 1.4210855e-14 )
    {
      v167.m_el[0].mVec128.m128_i32[3] = 0;
      v39 = -(1.0 / sqrtf(maxDist));
      v167.m_el[0].mVec128.m128_f32[0] = v164.m_floats[0] * v39;
      v167.m_el[0].mVec128.m128_f32[1] = v164.m_floats[1] * v39;
      v167.m_el[0].mVec128.m128_f32[2] = v39 * v164.m_floats[2];
      v167.m_el[2] = (btVector3)_mm_load_si128((const __m128i *)&v167);
      v36 = v167.m_el[2].mVec128.m128_f32[0];
    }
    else
    {
      if ( fabsf(v162) <= hsqt2 )
      {
        v37 = 1.0 / sqrtf((float)(v161.m_floats[3] * v161.m_floats[3]) + (float)(v161.m_floats[2] * v161.m_floats[2]));
        v38 = 0.0;
        v167.m_el[2].mVec128.m128_i32[2] = 0;
        v167.m_el[2].mVec128.m128_f32[0] = -(v161.m_floats[3] * v37);
        v36 = v167.m_el[2].mVec128.m128_f32[0];
        v167.m_el[2].mVec128.m128_f32[1] = v37 * v161.m_floats[2];
LABEL_25:
        v34 = *(float *)&debugDraw.__vftable;
        v40 = v38 * *(float *)&ptr;
        v41 = (float)(body1->m_worldTransform.m_origin.mVec128.m128_f32[1] + axis.mVec128.m128_f32[1])
            + (float)(v167.m_el[2].mVec128.m128_f32[1] * *(float *)&ptr);
        v42 = (float)(axis.mVec128.m128_f32[0] + body1->m_worldTransform.m_origin.mVec128.m128_f32[0])
            + (float)(v36 * *(float *)&ptr);
        *(float *)&v43 = (float)(body1->m_worldTransform.m_origin.mVec128.m128_f32[2] + axis.mVec128.m128_f32[2]) + v40;
        v167.m_el[0].mVec128.m128_f32[0] = v42;
        v167.m_el[0].mVec128.m128_f32[1] = v41;
        v167.m_el[0].mVec128.m128_u64[1] = v43;
        si128 = _mm_load_si128((const __m128i *)&v167);
        goto LABEL_26;
      }
      v35 = 1.0 / sqrtf((float)(v162 * v162) + (float)(v161.m_floats[3] * v161.m_floats[3]));
      v36 = 0.0;
      v167.m_el[2].mVec128.m128_i32[0] = 0;
      v167.m_el[2].mVec128.m128_f32[1] = -(v162 * v35);
      v167.m_el[2].mVec128.m128_f32[2] = v35 * v161.m_floats[3];
    }
    v38 = v167.m_el[2].mVec128.m128_f32[2];
    goto LABEL_25;
  }
  btGjkPairDetector::btGjkPairDetector(
    (btGjkPairDetector *)&v197.m_el[1],
    m_collisionShape,
    (const btConvexShape *)v8,
    *(btVoronoiSimplexSolver **)(LODWORD(v161.m_floats[1]) + 8),
    *(btConvexPenetrationDepthSolver **)(LODWORD(v161.m_floats[1]) + 12));
  v45 = *(_DWORD *)(LODWORD(v161.m_floats[1]) + 20);
  v46 = v161.m_floats[0];
  getMargin = v8->getMargin;
  v198 = v161.m_floats[0];
  v199 = v8;
  debugDraw.__vftable = *(btIDebugDraw_vtbl **)(v45 + 1180);
  maxDist = getMargin(v8);
  v48 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)LODWORD(v46) + 40))(LODWORD(v46));
  output_8 = (__m128i)body0->m_worldTransform.m_basis.m_el[0];
  v189.m128i_i64[0] = body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_i64[0];
  v49 = body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_i64[1];
  v194 = (v48 + maxDist + *(float *)&debugDraw.__vftable) * (v48 + maxDist + *(float *)&debugDraw.__vftable);
  v189.m128i_i64[1] = v49;
  m_stackAllocator = dispatchInfo->m_stackAllocator;
  v190 = (__m128i)body0->m_worldTransform.m_basis.m_el[2];
  v191 = body0->m_worldTransform.m_origin.mVec128.m128_u64[0];
  p_m_worldTransform = &body1->m_worldTransform;
  transformB.m_basis.m_el[0].mVec128.m128_u64[0] = body0->m_worldTransform.m_origin.mVec128.m128_u64[1];
  transformB.m_basis.m_el[0].mVec128.m128_u64[1] = body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
  transformB.m_basis.m_el[1] = *(btVector3 *)((char *)body1->m_worldTransform.m_basis.m_el + 8);
  transformB.m_basis.m_el[2] = *(btVector3 *)((char *)&body1->m_worldTransform.m_basis.m_el[1] + 8);
  transformB.m_origin.mVec128.m128_u64[0] = body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[1];
  v52 = body1->m_worldTransform.m_origin.mVec128.m128_u64[0];
  transA[0] = &body0->m_worldTransform;
  v53 = *(_DWORD *)(LODWORD(v161.m_floats[0]) + 4) < 7;
  transformB.m_origin.mVec128.m128_u64[1] = v52;
  v195 = m_stackAllocator;
  v193 = body1->m_worldTransform.m_origin.mVec128.m128_u64[1];
  if ( !v53 )
    goto LABEL_73;
  v54 = v8->m_shapeType;
  if ( v54 >= 7 )
    goto LABEL_73;
  v55 = *(const btConvexPolyhedron **)(LODWORD(v161.m_floats[0]) + 64);
  *(float *)&debugDraw.__vftable = COERCE_FLOAT(&`btConvexConvexAlgorithm::processCollision'::`16'::btDummyResult::`vftable');
  if ( !v55 )
    goto LABEL_73;
  v56 = (const btConvexPolyhedron *)v8[5].m_shapeType;
  if ( v56 )
  {
    v6 = !dispatchInfo->m_enableSatConvex;
    maxDist = *(float *)(*(_DWORD *)(LODWORD(v161.m_floats[1]) + 20) + 1180);
    *(float *)&ptr = -1.0e30;
    if ( v6 )
    {
      btGjkPairDetector::getClosestPointsNonVirtual(
        (btGjkPairDetector *)&debugDraw,
        (const btDiscreteCollisionDetectorInterface::ClosestPointInput *)&v197.m_el[1],
        (btDiscreteCollisionDetectorInterface::Result *)&output_8,
        &debugDraw);
      v58 = (float)((float)(v197.m_el[2].mVec128.m128_f32[2] * v197.m_el[2].mVec128.m128_f32[2])
                  + (float)(v197.m_el[2].mVec128.m128_f32[0] * v197.m_el[2].mVec128.m128_f32[0]))
          + (float)(v197.m_el[2].mVec128.m128_f32[1] * v197.m_el[2].mVec128.m128_f32[1]);
      if ( v58 <= 0.00000011920929 )
        goto LABEL_38;
      v59 = *(_DWORD *)LODWORD(v46);
      ptr = (void *)v200;
      v60 = *(double (__thiscall **)(_DWORD))(v59 + 40);
      v167.m_el[0].mVec128.m128_f32[0] = v197.m_el[2].mVec128.m128_f32[0] * (float)(*(float *)&clear_value / v58);
      v167.m_el[0].mVec128.m128_f32[1] = v197.m_el[2].mVec128.m128_f32[1] * (float)(*(float *)&clear_value / v58);
      v167.m_el[0].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v197.m_el[2].mVec128.m128_f32[2] * (float)(*(float *)&clear_value / v58));
      sep_8.mVec128 = (__m128)_mm_load_si128((const __m128i *)&v167);
      v61 = v60(LODWORD(v46));
      v62 = v8->getMargin;
      *(float *)&ptr = *(float *)&ptr - v61;
      v63 = ((double (__thiscall *)(btCollisionShape *))v62)(v8);
      v64 = v8->getMargin;
      *(float *)&ptr = *(float *)&ptr - v63;
      transA[1] = v200;
      v65 = ((double (__thiscall *)(btCollisionShape *))v64)(v8);
      v66 = *(_DWORD *)LODWORD(v46);
      v167.m_el[1].mVec128.m128_f32[3] = v65;
      v67 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(v66 + 40))(LODWORD(v46));
      if ( v67 + v167.m_el[1].mVec128.m128_f32[3] > *(float *)&transA[1] )
        goto LABEL_38;
    }
    else if ( btPolyhedralContactClipping::findSeparatingAxis(v55, v56, transA[0], p_m_worldTransform, &sep_8) )
    {
LABEL_38:
      btPolyhedralContactClipping::clipHullAgainstHull(
        &sep_8,
        *(const btConvexPolyhedron **)(LODWORD(v46) + 64),
        (const btConvexPolyhedron *)v8[5].m_shapeType,
        transA[0],
        p_m_worldTransform,
        *(float *)&ptr - maxDist,
        maxDist,
        resultOut);
    }
    if ( *(_BYTE *)(LODWORD(v161.m_floats[1]) + 16) )
    {
      v57 = resultOut->m_manifoldPtr;
      if ( v57->m_cachedPoints )
      {
        _Xa = resultOut->m_manifoldPtr;
        if ( v57->m_body0 == resultOut->m_body0 )
          btPersistentManifold::refreshContactPoints(_Xa, &resultOut->m_rootTransA, &resultOut->m_rootTransB);
        else
          btPersistentManifold::refreshContactPoints(_Xa, &resultOut->m_rootTransB, &resultOut->m_rootTransA);
      }
    }
    return;
  }
  if ( v54 == 1 )
  {
    v68 = *(float *)&v8[7].__vftable;
    v69 = *(float *)&v8[7].m_shapeType;
    v70 = *(float *)&v8[6].m_userPointer;
    v71 = body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2];
    v72 = body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v68;
    ++gNumAlignedAllocs;
    v73 = (float)((float)(v72 + (float)(v71 * v69))
                + (float)(v70 * body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0]))
        + body1->m_worldTransform.m_origin.mVec128.m128_f32[0];
    v74 = body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2];
    axis.mVec128.m128_f32[0] = v73;
    v75 = (float)(body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v68) + (float)(v74 * v69);
    v76 = v70 * body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0];
    v77 = v70 * body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
    axis.mVec128.m128_f32[1] = (float)(v75 + v76) + body1->m_worldTransform.m_origin.mVec128.m128_f32[1];
    axis.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)(body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]
                                                       * v68)
                                               + (float)(body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]
                                                       * v69))
                                       + v77)
                               + body1->m_worldTransform.m_origin.mVec128.m128_f32[2]);
    *(float *)&v78 = COERCE_FLOAT(sAlignedAllocFunc(0x10u, 16));
    ptr = v78;
    if ( *(float *)&v78 != 0.0 )
      *v78 = (btVector3)axis.mVec128;
    v79 = *(float *)&v8[8].m_shapeType;
    v80 = *(float *)&v8[8].m_userPointer;
    v81 = *(float *)&v8[8].__vftable;
    v82 = body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2];
    v83 = body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v79;
    ++gNumAlignedAllocs;
    v84 = (float)((float)(v83 + (float)(v82 * v80))
                + (float)(v81 * body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0]))
        + body1->m_worldTransform.m_origin.mVec128.m128_f32[0];
    v85 = body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2];
    axis.mVec128.m128_f32[0] = v84;
    v86 = (float)(body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v79) + (float)(v85 * v80);
    v87 = v81 * body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0];
    v88 = v81 * body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
    axis.mVec128.m128_f32[1] = (float)(v86 + v87) + body1->m_worldTransform.m_origin.mVec128.m128_f32[1];
    axis.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)(body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]
                                                       * v79)
                                               + (float)(body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]
                                                       * v80))
                                       + v88)
                               + body1->m_worldTransform.m_origin.mVec128.m128_f32[2]);
    v89 = (btVector3 *)sAlignedAllocFunc(0x20u, 16);
    v90 = ptr;
    if ( v89 )
    {
      v89->mVec128.m128_u64[0] = *(_QWORD *)ptr;
      v89->mVec128.m128_u64[1] = v90[1];
    }
    if ( v90 )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(ptr);
    }
    if ( v89 != (btVector3 *)-16 )
      v89[1] = (btVector3)axis.mVec128;
    v91 = *(float *)&v8[10].__vftable;
    v92 = *(float *)&v8[9].m_userPointer;
    v93 = *(float *)&v8[9].m_shapeType;
    v94 = (float)(body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v92)
        + (float)(body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2] * v91);
    ++gNumAlignedAllocs;
    v95 = body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2];
    axis.mVec128.m128_f32[0] = (float)(v94 + (float)(v93 * body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0]))
                             + body1->m_worldTransform.m_origin.mVec128.m128_f32[0];
    axis.mVec128.m128_f32[1] = (float)((float)((float)(body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v92)
                                             + (float)(v95 * v91))
                                     + (float)(body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v93))
                             + body1->m_worldTransform.m_origin.mVec128.m128_f32[1];
    axis.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                                 (float)((float)((float)(body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]
                                                       * v92)
                                               + (float)(body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]
                                                       * v91))
                                       + (float)(body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0] * v93))
                               + body1->m_worldTransform.m_origin.mVec128.m128_f32[2]);
    v96 = (btVector3 *)sAlignedAllocFunc(0x40u, 16);
    v97 = v96;
    v98 = (char *)v89 - (char *)v96;
    v99 = 2;
    do
    {
      if ( v96 )
      {
        v96->mVec128.m128_u64[0] = *(unsigned __int64 *)((char *)v96->mVec128.m128_u64 + v98);
        v96->mVec128.m128_u64[1] = *(unsigned __int64 *)((char *)&v96->mVec128.m128_u64[1] + v98);
      }
      ++v96;
      --v99;
    }
    while ( v99 );
    if ( v89 )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v89);
    }
    worldVertsB1_8.m_data = v97;
    v6 = &v97[2] == 0;
    v100 = v97 + 2;
    worldVertsB1_8.m_ownsMemory = 1;
    worldVertsB1_8.m_capacity = 4;
    if ( !v6 )
      *v100 = (btVector3)axis.mVec128;
    v101 = *(_DWORD *)(*(_DWORD *)(LODWORD(v161.m_floats[1]) + 20) + 1180);
    worldVertsB1_8.m_size = 3;
    v167.m_el[1].mVec128.m128_i32[3] = v101;
    btGjkPairDetector::getClosestPointsNonVirtual(
      (btGjkPairDetector *)&v197.m_el[1],
      (const btDiscreteCollisionDetectorInterface::ClosestPointInput *)&v197.m_el[1],
      (btDiscreteCollisionDetectorInterface::Result *)&output_8,
      &debugDraw);
    v103 = (float)((float)(v197.m_el[2].mVec128.m128_f32[2] * v197.m_el[2].mVec128.m128_f32[2])
                 + (float)(v197.m_el[2].mVec128.m128_f32[0] * v197.m_el[2].mVec128.m128_f32[0]))
         + (float)(v197.m_el[2].mVec128.m128_f32[1] * v197.m_el[2].mVec128.m128_f32[1]);
    if ( v103 <= 0.00000011920929 )
    {
      v109 = resultOut;
    }
    else
    {
      v104 = v161.m_floats[0];
      transA[1] = v200;
      v105 = *(double (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(v161.m_floats[0]) + 40);
      v167.m_el[0].mVec128.m128_f32[0] = v197.m_el[2].mVec128.m128_f32[0] * (float)(*(float *)&clear_value / v103);
      v167.m_el[0].mVec128.m128_f32[1] = v197.m_el[2].mVec128.m128_f32[1] * (float)(*(float *)&clear_value / v103);
      v167.m_el[0].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v197.m_el[2].mVec128.m128_f32[2] * (float)(*(float *)&clear_value / v103));
      *(__m128i *)&separatingNormal[1] = _mm_load_si128((const __m128i *)&v167);
      v106 = v105(LODWORD(v161.m_floats[0]));
      v107 = v8->getMargin;
      *(float *)&transA[1] = *(float *)&transA[1] - v106;
      v108 = ((double (__thiscall *)(btCollisionShape *))v107)(v8);
      v109 = resultOut;
      v152 = *(float *)&transA[1] - v108 - v167.m_el[1].mVec128.m128_f32[3];
      btPolyhedralContactClipping::clipFaceAgainstHull(
        (const btVector3 *)&separatingNormal[1],
        *(const btConvexPolyhedron **)(LODWORD(v104) + 64),
        transA[0],
        &worldVertsB1_8,
        v152,
        v167.m_el[1].mVec128.m128_f32[3],
        resultOut);
    }
    if ( *(_BYTE *)(LODWORD(v161.m_floats[1]) + 16) )
    {
      v110 = v109->m_manifoldPtr;
      if ( v110->m_cachedPoints )
      {
        _Xb = v109->m_manifoldPtr;
        if ( v110->m_body0 != v109->m_body0 )
        {
          btPersistentManifold::refreshContactPoints(_Xb, &v109->m_rootTransB, &v109->m_rootTransA);
          btPairSet::~btPairSet(v111, (int)&worldVertsB1_8);
          return;
        }
        btPersistentManifold::refreshContactPoints(_Xb, &v109->m_rootTransA, &v109->m_rootTransB);
      }
    }
    btPairSet::~btPairSet(v102, (int)&worldVertsB1_8);
  }
  else
  {
LABEL_73:
    btGjkPairDetector::getClosestPointsNonVirtual(
      (btGjkPairDetector *)resultOut,
      (const btDiscreteCollisionDetectorInterface::ClosestPointInput *)&v197.m_el[1],
      (btDiscreteCollisionDetectorInterface::Result *)&output_8,
      (btIDebugDraw *)resultOut);
    v112 = v161.m_floats[1];
    v113 = resultOut;
    if ( *(_DWORD *)(LODWORD(v161.m_floats[1]) + 28) )
    {
      if ( resultOut->m_manifoldPtr->m_cachedPoints < *(_DWORD *)(LODWORD(v161.m_floats[1]) + 32) )
      {
        v114 = (float)((float)(v197.m_el[2].mVec128.m128_f32[2] * v197.m_el[2].mVec128.m128_f32[2])
                     + (float)(v197.m_el[2].mVec128.m128_f32[0] * v197.m_el[2].mVec128.m128_f32[0]))
             + (float)(v197.m_el[2].mVec128.m128_f32[1] * v197.m_el[2].mVec128.m128_f32[1]);
        if ( v114 > 0.00000011920929 )
        {
          v162 = v197.m_el[2].mVec128.m128_f32[2] * (float)(*(float *)&clear_value / v114);
          v161.m_floats[2] = v197.m_el[2].mVec128.m128_f32[0] * (float)(*(float *)&clear_value / v114);
          v161.m_floats[3] = v197.m_el[2].mVec128.m128_f32[1] * (float)(*(float *)&clear_value / v114);
          v163 = 0.0;
          *(__m128i *)&worldVertsB1_8.m_allocator = _mm_load_si128((const __m128i *)&v161.m_floats[2]);
          if ( fabsf(v162) <= hsqt2 )
          {
            v116 = 1.0
                 / sqrtf((float)(v161.m_floats[2] * v161.m_floats[2]) + (float)(v161.m_floats[3] * v161.m_floats[3]));
            axis.mVec128.m128_i32[2] = 0;
            axis.mVec128.m128_f32[0] = -(v161.m_floats[3] * v116);
            axis.mVec128.m128_f32[1] = v116 * v161.m_floats[2];
          }
          else
          {
            v115 = 1.0 / sqrtf((float)(v162 * v162) + (float)(v161.m_floats[3] * v161.m_floats[3]));
            axis.mVec128.m128_i32[0] = 0;
            axis.mVec128.m128_f32[1] = -(v162 * v115);
            axis.mVec128.m128_f32[2] = v115 * v161.m_floats[3];
          }
          maxDist = ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)LODWORD(v161.m_floats[0]) + 12))(LODWORD(v161.m_floats[0]));
          v117 = ((double (__thiscall *)(btCollisionShape *))v8->getAngularMotionDisc)(v8);
          *(float *)&transA[1] = v117;
          if ( v117 <= maxDist )
          {
            v118 = gContactBreakingThreshold / *(float *)&transA[1];
            LOBYTE(v161.m_floats[0]) = 0;
          }
          else
          {
            v118 = gContactBreakingThreshold / maxDist;
            LOBYTE(v161.m_floats[0]) = 1;
          }
          *(float *)&ptr = v118;
          if ( v118 > 0.39269909 )
            *(float *)&ptr = 0.39269909;
          if ( LOBYTE(v161.m_floats[0]) )
          {
            v201.m_basis.m_el[0] = (btVector3)_mm_load_si128(&output_8);
            v201.m_basis.m_el[1] = (btVector3)_mm_load_si128(&v189);
            v201.m_basis.m_el[2] = (btVector3)_mm_load_si128(&v190);
            v119.mVec128 = (__m128)_mm_load_si128((const __m128i *)&v191);
          }
          else
          {
            v201.m_basis.m_el[0] = (btVector3)_mm_load_si128((const __m128i *)&transformB.m_basis.m_el[0].m_floats[2]);
            v201.m_basis.m_el[1] = (btVector3)_mm_load_si128((const __m128i *)&transformB.m_basis.m_el[1].m_floats[2]);
            v201.m_basis.m_el[2] = (btVector3)_mm_load_si128((const __m128i *)&transformB.m_basis.m_el[2].m_floats[2]);
            v119.mVec128 = (__m128)_mm_load_si128((const __m128i *)&transformB.m_origin.m_floats[2]);
          }
          v53 = *(_DWORD *)(LODWORD(v161.m_floats[1]) + 28) <= 0;
          v201.m_origin = (btVector3)v119.mVec128;
          maxDist = 0.0;
          if ( !v53 )
          {
            v120 = (float)((float)(axis.mVec128.m128_f32[0] * axis.mVec128.m128_f32[0])
                         + (float)(axis.mVec128.m128_f32[2] * axis.mVec128.m128_f32[2]))
                 + (float)(axis.mVec128.m128_f32[1] * axis.mVec128.m128_f32[1]);
            v182 = v120;
            do
            {
              if ( v120 > 0.00000011920929 )
              {
                btQuaternion::setRotation((btQuaternion *)&v161.m_floats[2], &axis, (const float *)&ptr);
                *(float *)&transA[1] = (float)(6.2831855 / (float)*(int *)(LODWORD(v161.m_floats[1]) + 28))
                                     * (float)SLODWORD(maxDist);
                btQuaternion::setRotation(&v164, (const btVector3 *)&worldVertsB1_8, (const float *)&transA[1]);
                if ( LOBYTE(v161.m_floats[0]) )
                {
                  v121 = (float)((float)((float)((float)-v164.m_floats[0] * v163)
                                       + (float)(v161.m_floats[2] * v164.m_floats[3]))
                               + (float)(v162 * COERCE_FLOAT(LODWORD(v164.m_floats[1]) ^ 0x80000000)))
                       - (float)(v161.m_floats[3] * COERCE_FLOAT(LODWORD(v164.m_floats[2]) ^ 0x80000000));
                  *(unsigned __int64 *)((char *)sep_8.mVec128.m128_u64 + 4) = *(_QWORD *)&v164.m_floats[1]
                                                                            ^ 0x8000000080000000uLL;
                  v122 = (float)((float)((float)(v161.m_floats[2] * COERCE_FLOAT(LODWORD(v164.m_floats[2]) ^ 0x80000000))
                                       + (float)(v161.m_floats[3] * v164.m_floats[3]))
                               + (float)(v163 * COERCE_FLOAT(LODWORD(v164.m_floats[1]) ^ 0x80000000)))
                       - (float)((float)-v164.m_floats[0] * v162);
                  v123 = (float)((float)((float)(v163 * v164.m_floats[3])
                                       - (float)((float)-v164.m_floats[0] * v161.m_floats[2]))
                               - (float)(v161.m_floats[3] * COERCE_FLOAT(LODWORD(v164.m_floats[1]) ^ 0x80000000)))
                       - (float)(v162 * COERCE_FLOAT(LODWORD(v164.m_floats[2]) ^ 0x80000000));
                  v124 = (float)((float)((float)((float)-v164.m_floats[0] * v161.m_floats[3])
                                       + (float)(v162 * v164.m_floats[3]))
                               + (float)(v163 * COERCE_FLOAT(LODWORD(v164.m_floats[2]) ^ 0x80000000)))
                       - (float)(v161.m_floats[2] * COERCE_FLOAT(LODWORD(v164.m_floats[1]) ^ 0x80000000));
                  v167.m_el[0].mVec128.m128_f32[0] = (float)((float)((float)(v121 * v164.m_floats[3])
                                                                   + (float)(v164.m_floats[0] * v123))
                                                           + (float)(v122 * v164.m_floats[2]))
                                                   - (float)(v124 * v164.m_floats[1]);
                  v167.m_el[0].mVec128.m128_f32[1] = (float)((float)((float)(v164.m_floats[0] * v124)
                                                                   + (float)(v122 * v164.m_floats[3]))
                                                           + (float)(v123 * v164.m_floats[1]))
                                                   - (float)(v121 * v164.m_floats[2]);
                  v167.m_el[0].mVec128.m128_f32[2] = (float)((float)((float)(v121 * v164.m_floats[1])
                                                                   + (float)(v124 * v164.m_floats[3]))
                                                           + (float)(v123 * v164.m_floats[2]))
                                                   - (float)(v164.m_floats[0] * v122);
                  v167.m_el[0].mVec128.m128_f32[3] = (float)((float)((float)(v123 * v164.m_floats[3])
                                                                   - (float)(v121 * v164.m_floats[0]))
                                                           - (float)(v122 * v164.m_floats[1]))
                                                   - (float)(v124 * v164.m_floats[2]);
                  btMatrix3x3::setRotation(&v167, (int)&v168);
                  v125 = transA[0]->m_basis.m_el[1].mVec128.m128_f32[2];
                  *(float *)&v126 = (float)((float)(v174 * transA[0]->m_basis.m_el[0].mVec128.m128_f32[2])
                                          + (float)(v175 * v125))
                                  + (float)(v176 * transA[0]->m_basis.m_el[2].mVec128.m128_f32[2]);
                  *(float *)&v127 = (float)((float)(v174 * transA[0]->m_basis.m_el[0].mVec128.m128_f32[1])
                                          + (float)(v175 * transA[0]->m_basis.m_el[1].mVec128.m128_f32[1]))
                                  + (float)(v176 * transA[0]->m_basis.m_el[2].mVec128.m128_f32[1]);
                  *(float *)&sep = (float)((float)(v174 * transA[0]->m_basis.m_el[0].mVec128.m128_f32[0])
                                         + (float)(v175 * transA[0]->m_basis.m_el[1].mVec128.m128_f32[0]))
                                 + (float)(v176 * transA[0]->m_basis.m_el[2].mVec128.m128_f32[0]);
                  *(float *)&v128 = (float)((float)(v171 * transA[0]->m_basis.m_el[0].mVec128.m128_f32[2])
                                          + (float)(v172 * v125))
                                  + (float)(v173 * transA[0]->m_basis.m_el[2].mVec128.m128_f32[2]);
                  *(float *)&v129 = (float)((float)(v171 * transA[0]->m_basis.m_el[0].mVec128.m128_f32[1])
                                          + (float)(v172 * transA[0]->m_basis.m_el[1].mVec128.m128_f32[1]))
                                  + (float)(v173 * transA[0]->m_basis.m_el[2].mVec128.m128_f32[1]);
                  *(float *)&sep_4 = (float)((float)(v171 * transA[0]->m_basis.m_el[0].mVec128.m128_f32[0])
                                           + (float)(v172 * transA[0]->m_basis.m_el[1].mVec128.m128_f32[0]))
                                   + (float)(v173 * transA[0]->m_basis.m_el[2].mVec128.m128_f32[0]);
                  *(float *)&v130 = (float)((float)(v168 * transA[0]->m_basis.m_el[0].mVec128.m128_f32[2])
                                          + (float)(v169 * transA[0]->m_basis.m_el[1].mVec128.m128_f32[2]))
                                  + (float)(v170 * transA[0]->m_basis.m_el[2].mVec128.m128_f32[2]);
                  *(float *)&debugDraw.__vftable = (float)(v168 * transA[0]->m_basis.m_el[0].mVec128.m128_f32[1])
                                                 + (float)(v169 * transA[0]->m_basis.m_el[1].mVec128.m128_f32[1]);
                  v131 = transA[0]->m_basis.m_el[1].mVec128.m128_f32[0];
                  v167.m_el[1].mVec128.m128_f32[3] = *(float *)&debugDraw.__vftable
                                                   + (float)(v170 * transA[0]->m_basis.m_el[2].mVec128.m128_f32[1]);
                  v132 = v168 * transA[0]->m_basis.m_el[0].mVec128.m128_f32[0];
                  v133 = v169 * v131;
                  v134 = transA[0]->m_basis.m_el[2].mVec128.m128_f32[0];
                  v177.m128i_i64[1] = v130;
                  v177.m128i_i32[1] = v167.m_el[1].mVec128.m128_i32[3];
                  *(float *)v177.m128i_i32 = (float)(v132 + v133) + (float)(v170 * v134);
                  output_8 = _mm_load_si128(&v177);
                  v178.m128i_i64[0] = __PAIR64__(v129, sep_4);
                  v178.m128i_i64[1] = v128;
                  v189 = _mm_load_si128(&v178);
                  v179.m128i_i64[0] = __PAIR64__(v127, sep);
                  v179.m128i_i64[1] = v126;
                  v190 = _mm_load_si128(&v179);
                  transformB.m_basis.m_el[0].mVec128.m128_u64[1] = p_m_worldTransform->m_basis.m_el[0].mVec128.m128_u64[0];
                  transformB.m_basis.m_el[1] = *(btVector3 *)((char *)body1->m_worldTransform.m_basis.m_el + 8);
                  transformB.m_basis.m_el[2] = *(btVector3 *)((char *)&body1->m_worldTransform.m_basis.m_el[1] + 8);
                  transformB.m_origin = *(btVector3 *)((char *)&body1->m_worldTransform.m_basis.m_el[2] + 8);
                  v193 = body1->m_worldTransform.m_origin.mVec128.m128_u64[1];
                }
                else
                {
                  output_8 = (__m128i)transA[0]->m_basis.m_el[0];
                  v189 = (__m128i)transA[0]->m_basis.m_el[1];
                  v190 = (__m128i)transA[0]->m_basis.m_el[2];
                  v191 = transA[0]->m_origin.mVec128.m128_u64[0];
                  transformB.m_basis.m_el[0].mVec128.m128_u64[0] = transA[0]->m_origin.mVec128.m128_u64[1];
                  v135 = (float)((float)((float)(v161.m_floats[2] * v164.m_floats[3])
                                       + (float)((float)-v164.m_floats[1] * v162))
                               + (float)(v163 * (float)-v164.m_floats[0]))
                       - (float)((float)-v164.m_floats[2] * v161.m_floats[3]);
                  *(float *)&separatingNormal[1] = -v164.m_floats[0];
                  v136 = (float)((float)((float)(v161.m_floats[2] * (float)-v164.m_floats[2])
                                       + (float)((float)-v164.m_floats[1] * v163))
                               + (float)(v161.m_floats[3] * v164.m_floats[3]))
                       - (float)(v162 * (float)-v164.m_floats[0]);
                  v137 = (float)((float)((float)(v163 * v164.m_floats[3])
                                       - (float)(v161.m_floats[2] * (float)-v164.m_floats[0]))
                               - (float)((float)-v164.m_floats[1] * v161.m_floats[3]))
                       - (float)((float)-v164.m_floats[2] * v162);
                  v138 = (float)((float)((float)((float)-v164.m_floats[2] * v163) + (float)(v162 * v164.m_floats[3]))
                               + (float)(v161.m_floats[3] * (float)-v164.m_floats[0]))
                       - (float)(v161.m_floats[2] * (float)-v164.m_floats[1]);
                  v197.m_el[0].mVec128.m128_f32[0] = (float)((float)((float)(v164.m_floats[0] * v137)
                                                                   + (float)(v164.m_floats[3] * v135))
                                                           + (float)(v136 * v164.m_floats[2]))
                                                   - (float)(v138 * v164.m_floats[1]);
                  v197.m_el[0].mVec128.m128_f32[1] = (float)((float)((float)(v164.m_floats[0] * v138)
                                                                   + (float)(v136 * v164.m_floats[3]))
                                                           + (float)(v137 * v164.m_floats[1]))
                                                   - (float)(v164.m_floats[2] * v135);
                  v197.m_el[0].mVec128.m128_f32[2] = (float)((float)((float)(v164.m_floats[1] * v135)
                                                                   + (float)(v138 * v164.m_floats[3]))
                                                           + (float)(v137 * v164.m_floats[2]))
                                                   - (float)(v164.m_floats[0] * v136);
                  v197.m_el[0].mVec128.m128_f32[3] = (float)((float)((float)(v137 * v164.m_floats[3])
                                                                   - (float)(v164.m_floats[0] * v135))
                                                           - (float)(v136 * v164.m_floats[1]))
                                                   - (float)(v138 * v164.m_floats[2]);
                  btMatrix3x3::setRotation(&v197, (int)&v168);
                  v139 = body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2];
                  *(float *)&v140 = (float)((float)(v174 * body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2])
                                          + (float)(v175 * v139))
                                  + (float)(v176 * body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]);
                  *(float *)&v141 = (float)((float)(v174 * body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1])
                                          + (float)(v175 * body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]))
                                  + (float)(v176 * body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]);
                  v180 = (float)((float)(v174 * body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0])
                               + (float)(v175 * body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0]))
                       + (float)(v176 * body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0]);
                  *(float *)&v142 = (float)((float)(v171 * body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2])
                                          + (float)(v172 * v139))
                                  + (float)(v173 * body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]);
                  v143 = (float)(v171 * body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1])
                       + (float)(v172 * body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]);
                  v144 = v173 * body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1];
                  v183 = (float)((float)(v171 * body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0])
                               + (float)(v172 * body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0]))
                       + (float)(v173 * body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0]);
                  *(float *)&v145 = v143 + v144;
                  *(float *)&v146 = (float)((float)(v168 * body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2])
                                          + (float)(v169 * body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2]))
                                  + (float)(v170 * body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]);
                  *(float *)&debugDraw.__vftable = (float)(v168
                                                         * body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1])
                                                 + (float)(v169
                                                         * body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]);
                  v147 = body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0];
                  v181 = *(float *)&debugDraw.__vftable
                       + (float)(v170 * body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]);
                  *(float *)&v148 = (float)((float)(v168 * body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0])
                                          + (float)(v169 * v147))
                                  + (float)(v170 * body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0]);
                  v177.m128i_i64[1] = v146;
                  v177.m128i_i64[0] = __PAIR64__(LODWORD(v181), v148);
                  v149.mVec128 = (__m128)_mm_load_si128(&v177);
                  v178.m128i_i64[0] = __PAIR64__(v145, LODWORD(v183));
                  v178.m128i_i64[1] = v142;
                  *(btVector3 *)((char *)transformB.m_basis.m_el + 8) = (btVector3)v149.mVec128;
                  v150.mVec128 = (__m128)_mm_load_si128(&v178);
                  v179.m128i_i64[0] = __PAIR64__(v141, LODWORD(v180));
                  v179.m128i_i64[1] = v140;
                  *(btVector3 *)((char *)&transformB.m_basis.m_el[1] + 8) = (btVector3)v150.mVec128;
                  *(__m128i *)((char *)&transformB.m_basis.m_el[2] + 8) = _mm_load_si128(&v179);
                }
                btPerturbedContactResult::btPerturbedContactResult(
                  &v203,
                  resultOut,
                  (const btTransform *)&output_8,
                  SLOBYTE(v161.m_floats[0]),
                  dispatchInfo->m_debugDraw);
                btGjkPairDetector::getClosestPointsNonVirtual(
                  (btGjkPairDetector *)&v197.m_el[1],
                  (const btDiscreteCollisionDetectorInterface::ClosestPointInput *)&v197.m_el[1],
                  (btDiscreteCollisionDetectorInterface::Result *)&output_8,
                  (btIDebugDraw *)&v203);
                v120 = v182;
                v112 = v161.m_floats[1];
              }
              v53 = ++LODWORD(maxDist) < *(_DWORD *)(LODWORD(v112) + 28);
            }
            while ( v53 );
          }
          v113 = resultOut;
        }
      }
    }
    if ( *(_BYTE *)(LODWORD(v112) + 16) )
    {
      v151 = v113->m_manifoldPtr;
      if ( v151->m_cachedPoints )
      {
        _Xc = v113->m_manifoldPtr;
        if ( v151->m_body0 == v113->m_body0 )
          btPersistentManifold::refreshContactPoints(_Xc, &v113->m_rootTransA, &v113->m_rootTransB);
        else
          btPersistentManifold::refreshContactPoints(_Xc, &v113->m_rootTransB, &v113->m_rootTransA);
      }
    }
  }
}
