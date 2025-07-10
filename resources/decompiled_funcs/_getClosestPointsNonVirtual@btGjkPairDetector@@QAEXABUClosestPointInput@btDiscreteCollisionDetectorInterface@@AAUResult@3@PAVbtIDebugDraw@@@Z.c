void __thiscall btGjkPairDetector::getClosestPointsNonVirtual(
        btGjkPairDetector *this,
        btGjkPairDetector *input,
        const btDiscreteCollisionDetectorInterface::ClosestPointInput *output,
        btDiscreteCollisionDetectorInterface::Result *debugDraw,
        btIDebugDraw *debugDrawa)
{
  const btDiscreteCollisionDetectorInterface::ClosestPointInput *v5; // edi
  int m_minkowskiA; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  int v10; // eax
  int v11; // eax
  float m_marginB; // xmm0_4
  float m_marginA; // xmm1_4
  const vostok::math::float4x4 *v14; // xmm2_4
  int m_simplexSolver; // eax
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm4_4
  float v20; // xmm0_4
  btDiscreteCollisionDetectorInterface::Result_vtbl *v21; // xmm5_4
  float v22; // xmm4_4
  float v23; // xmm2_4
  float v24; // xmm4_4
  btConvexShape *v25; // ecx
  float v26; // xmm0_4
  float v27; // xmm1_4
  unsigned int v28; // xmm4_4
  float v29; // xmm0_4
  float v30; // xmm5_4
  float v31; // xmm0_4
  btVoronoiSimplexSolver *v32; // ecx
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm4_4
  float v36; // xmm5_4
  float v37; // xmm3_4
  float v38; // xmm0_4
  float v39; // xmm3_4
  float v40; // xmm0_4
  float v41; // xmm3_4
  btVoronoiSimplexSolver *v42; // edi
  btVoronoiSimplexSolver *v43; // ecx
  char updated; // al
  unsigned __int64 v45; // xmm2_8
  unsigned __int64 v46; // xmm3_8
  float v47; // xmm0_4
  bool v48; // cf
  int m_curIter; // eax
  btVoronoiSimplexSolver *v50; // esi
  float v51; // xmm2_4
  float v52; // xmm1_4
  float v53; // xmm0_4
  long double v54; // st7
  long double v55; // st7
  float v56; // xmm0_4
  float v57; // xmm1_4
  float v58; // xmm2_4
  bool v59; // al
  float *m128_f32; // esi
  int v61; // ecx
  unsigned __int8 (__thiscall *v62)(int, int, int, int, unsigned __int64 *, unsigned __int64 *, btVector3 *, btVector3 *, btVector3 *, btIDebugDraw *, btDiscreteCollisionDetectorInterface::Result_vtbl *); // eax
  float v63; // xmm0_4
  float v64; // xmm2_4
  float v65; // xmm1_4
  long double v66; // st7
  unsigned __int64 v67; // xmm2_8
  float v68; // xmm0_4
  void (__thiscall *addContactPoint)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *); // edx
  long double v70; // st7
  float v71; // xmm1_4
  float v72; // xmm2_4
  unsigned __int64 v73; // xmm0_8
  long double v74; // st7
  btDiscreteCollisionDetectorInterface::Result_vtbl *_X_4; // [esp+1A00h] [ebp-164h]
  char v76; // [esp+1A1Ah] [ebp-14Ah]
  bool v77; // [esp+1A1Bh] [ebp-149h]
  float v78; // [esp+1A1Ch] [ebp-148h]
  float v79; // [esp+1A20h] [ebp-144h]
  float v80; // [esp+1A20h] [ebp-144h]
  btVector3 v81; // [esp+1A24h] [ebp-140h] BYREF
  btVector3 v82; // [esp+1A34h] [ebp-130h] BYREF
  __int64 v83; // [esp+1A44h] [ebp-120h]
  float _X; // [esp+1A4Ch] [ebp-118h]
  float v85; // [esp+1A50h] [ebp-114h]
  btVector3 p; // [esp+1A54h] [ebp-110h] BYREF
  btVector3 q; // [esp+1A64h] [ebp-100h] BYREF
  btVector3 v88; // [esp+1A74h] [ebp-F0h] BYREF
  float v89; // [esp+1A90h] [ebp-D4h]
  unsigned __int64 v90; // [esp+1A94h] [ebp-D0h] BYREF
  unsigned __int64 v91; // [esp+1A9Ch] [ebp-C8h]
  unsigned __int64 v92; // [esp+1AA4h] [ebp-C0h] BYREF
  unsigned __int64 v93; // [esp+1AACh] [ebp-B8h]
  unsigned __int64 v94; // [esp+1AB4h] [ebp-B0h]
  unsigned __int64 v95; // [esp+1ABCh] [ebp-A8h]
  unsigned __int64 v96; // [esp+1AC4h] [ebp-A0h]
  unsigned __int64 v97; // [esp+1ACCh] [ebp-98h]
  unsigned __int64 v98; // [esp+1AD4h] [ebp-90h]
  unsigned __int64 v99; // [esp+1ADCh] [ebp-88h]
  unsigned __int64 v100; // [esp+1AE4h] [ebp-80h] BYREF
  unsigned __int64 v101; // [esp+1AECh] [ebp-78h]
  unsigned __int64 v102; // [esp+1AF4h] [ebp-70h]
  unsigned __int64 v103; // [esp+1AFCh] [ebp-68h]
  unsigned __int64 v104; // [esp+1B04h] [ebp-60h]
  unsigned __int64 v105; // [esp+1B0Ch] [ebp-58h]
  unsigned __int64 v106; // [esp+1B14h] [ebp-50h]
  unsigned __int64 v107; // [esp+1B1Ch] [ebp-48h]
  float v108; // [esp+1B24h] [ebp-40h]
  float v109; // [esp+1B28h] [ebp-3Ch]
  float v110; // [esp+1B2Ch] [ebp-38h]
  btVector3 v111; // [esp+1B34h] [ebp-30h] BYREF
  btVector3 localDir; // [esp+1B44h] [ebp-20h] BYREF
  btVector3 result; // [esp+1B54h] [ebp-10h] BYREF

  v5 = (const btDiscreteCollisionDetectorInterface::ClosestPointInput *)input;
  input->m_cachedSeparatingDistance = 0.0;
  v92 = output->m_transformA.m_basis.m_el[0].mVec128.m128_u64[0];
  v93 = output->m_transformA.m_basis.m_el[0].mVec128.m128_u64[1];
  v94 = output->m_transformA.m_basis.m_el[1].mVec128.m128_u64[0];
  v95 = output->m_transformA.m_basis.m_el[1].mVec128.m128_u64[1];
  v96 = output->m_transformA.m_basis.m_el[2].mVec128.m128_u64[0];
  v97 = output->m_transformA.m_basis.m_el[2].mVec128.m128_u64[1];
  v98 = output->m_transformA.m_origin.mVec128.m128_u64[0];
  v99 = output->m_transformA.m_origin.mVec128.m128_u64[1];
  v100 = output->m_transformB.m_basis.m_el[0].mVec128.m128_u64[0];
  v101 = output->m_transformB.m_basis.m_el[0].mVec128.m128_u64[1];
  m_minkowskiA = (int)input->m_minkowskiA;
  v102 = output->m_transformB.m_basis.m_el[1].mVec128.m128_u64[0];
  v103 = output->m_transformB.m_basis.m_el[1].mVec128.m128_u64[1];
  v104 = output->m_transformB.m_basis.m_el[2].mVec128.m128_u64[0];
  v105 = output->m_transformB.m_basis.m_el[2].mVec128.m128_u64[1];
  v106 = output->m_transformB.m_origin.mVec128.m128_u64[0];
  v107 = output->m_transformB.m_origin.mVec128.m128_u64[1];
  v7 = (float)(*(float *)&v106 + *(float *)&v98) * 0.5;
  *(float *)&v98 = *(float *)&v98 - v7;
  v8 = (float)(*((float *)&v106 + 1) + *((float *)&v98 + 1)) * 0.5;
  *((float *)&v98 + 1) = *((float *)&v98 + 1) - v8;
  v108 = v7;
  v9 = (float)(*(float *)&v107 + *(float *)&v99) * 0.5;
  memset(&v81, 0, sizeof(v81));
  *(float *)&v99 = *(float *)&v99 - v9;
  *(float *)&v106 = *(float *)&v106 - v7;
  *((float *)&v106 + 1) = *((float *)&v106 + 1) - v8;
  *(float *)&v107 = *(float *)&v107 - v9;
  v10 = *(_DWORD *)(m_minkowskiA + 4);
  v78 = 0.0;
  v109 = v8;
  v110 = v9;
  v77 = 0;
  if ( v10 == 17 || v10 == 18 )
  {
    this = (btGjkPairDetector *)input->m_minkowskiB;
    v11 = *((_DWORD *)&this->btDiscreteCollisionDetectorInterface + 1);
    if ( v11 == 17 || v11 == 18 )
      v77 = 1;
  }
  ++gNumGjkChecks;
  m_marginB = input->m_marginB;
  m_marginA = input->m_marginA;
  v79 = m_marginB;
  if ( input->m_ignoreMargin )
  {
    m_marginB = 0.0;
    m_marginA = 0.0;
    v79 = 0.0;
  }
  v14 = clear_value;
  input->m_curIter = 0;
  input->m_cachedSeparatingAxis.mVec128.m128_i32[1] = (int)v14;
  input->m_cachedSeparatingAxis.mVec128.m128_i32[0] = 0;
  input->m_cachedSeparatingAxis.mVec128.m128_u64[1] = 0;
  input->m_degenerateSimplex = 0;
  v76 = 0;
  m_simplexSolver = (int)input->m_simplexSolver;
  input->m_lastUsedMethod = -1;
  HIDWORD(v83) = 1566444395;
  v89 = m_marginB + m_marginA;
  btVoronoiSimplexSolver::reset((btVoronoiSimplexSolver *)this, m_simplexSolver);
  p.mVec128.m128_i32[3] = 0;
  q.mVec128.m128_i32[3] = 0;
  v82.mVec128.m128_i32[3] = 0;
  while ( 1 )
  {
    v16 = -v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1];
    v17 = -v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2];
    v18 = -v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[0];
    localDir.mVec128.m128_f32[0] = (float)((float)(v17 * output->m_transformA.m_basis.m_el[2].mVec128.m128_f32[0])
                                         + (float)(v16 * output->m_transformA.m_basis.m_el[1].mVec128.m128_f32[0]))
                                 + (float)(output->m_transformA.m_basis.m_el[0].mVec128.m128_f32[0] * v18);
    v19 = v17 * output->m_transformA.m_basis.m_el[2].mVec128.m128_f32[1];
    v20 = v17 * output->m_transformA.m_basis.m_el[2].mVec128.m128_f32[2];
    v21 = (btDiscreteCollisionDetectorInterface::Result_vtbl *)output->m_transformB.m_basis.m_el[0].mVec128.m128_i32[0];
    localDir.mVec128.m128_f32[1] = (float)(v19 + (float)(v18 * output->m_transformA.m_basis.m_el[0].mVec128.m128_f32[1]))
                                 + (float)(v16 * output->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1]);
    v22 = output->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2] * v16;
    v23 = v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1];
    v24 = v22 + v20;
    v25 = (btConvexShape *)v5->m_transformA.m_basis.m_el[2].mVec128.m128_i32[2];
    v26 = output->m_transformA.m_basis.m_el[0].mVec128.m128_f32[2] * v18;
    v27 = v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2];
    *(float *)&v28 = v24 + v26;
    v29 = v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[0];
    localDir.mVec128.m128_u64[1] = v28;
    v111.mVec128.m128_f32[0] = (float)((float)(output->m_transformB.m_basis.m_el[2].mVec128.m128_f32[0] * v27)
                                     + (float)(*(float *)&v21 * v29))
                             + (float)(output->m_transformB.m_basis.m_el[1].mVec128.m128_f32[0] * v23);
    v30 = output->m_transformB.m_basis.m_el[0].mVec128.m128_f32[1] * v29;
    v31 = v29 * output->m_transformB.m_basis.m_el[0].mVec128.m128_f32[2];
    v111.mVec128.m128_f32[1] = (float)((float)(v23 * output->m_transformB.m_basis.m_el[1].mVec128.m128_f32[1])
                                     + (float)(v27 * output->m_transformB.m_basis.m_el[2].mVec128.m128_f32[1]))
                             + v30;
    v111.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                                 (float)((float)(output->m_transformB.m_basis.m_el[1].mVec128.m128_f32[2] * v23)
                                       + (float)(output->m_transformB.m_basis.m_el[2].mVec128.m128_f32[2] * v27))
                               + v31);
    btConvexShape::localGetSupportVertexWithoutMarginNonVirtual(v25, &result, &localDir);
    btConvexShape::localGetSupportVertexWithoutMarginNonVirtual(
      (btConvexShape *)v5->m_transformA.m_basis.m_el[2].mVec128.m128_i32[3],
      &v88,
      &v111);
    v33 = (float)((float)((float)(*((float *)&v92 + 1) * result.mVec128.m128_f32[1])
                        + (float)(*(float *)&v93 * result.mVec128.m128_f32[2]))
                + (float)(*(float *)&v92 * result.mVec128.m128_f32[0]))
        + *(float *)&v98;
    v34 = (float)((float)((float)(*((float *)&v96 + 1) * result.mVec128.m128_f32[1])
                        + (float)(*(float *)&v97 * result.mVec128.m128_f32[2]))
                + (float)(*(float *)&v96 * result.mVec128.m128_f32[0]))
        + *(float *)&v99;
    v35 = (float)((float)((float)(*((float *)&v100 + 1) * v88.mVec128.m128_f32[1])
                        + (float)(*(float *)&v101 * v88.mVec128.m128_f32[2]))
                + (float)(*(float *)&v100 * v88.mVec128.m128_f32[0]))
        + *(float *)&v106;
    v36 = (float)((float)((float)(*((float *)&v102 + 1) * v88.mVec128.m128_f32[1])
                        + (float)(*(float *)&v103 * v88.mVec128.m128_f32[2]))
                + (float)(*(float *)&v102 * v88.mVec128.m128_f32[0]))
        + *((float *)&v106 + 1);
    v37 = (float)((float)((float)(*((float *)&v104 + 1) * v88.mVec128.m128_f32[1])
                        + (float)(*(float *)&v105 * v88.mVec128.m128_f32[2]))
                + (float)(v88.mVec128.m128_f32[0] * *(float *)&v104))
        + *(float *)&v107;
    p.mVec128.m128_f32[0] = v33;
    p.mVec128.m128_f32[1] = (float)((float)((float)(*((float *)&v94 + 1) * result.mVec128.m128_f32[1])
                                          + (float)(*(float *)&v95 * result.mVec128.m128_f32[2]))
                                  + (float)(*(float *)&v94 * result.mVec128.m128_f32[0]))
                          + *((float *)&v98 + 1);
    p.mVec128.m128_f32[2] = v34;
    q.mVec128.m128_f32[0] = v35;
    q.mVec128.m128_f32[1] = v36;
    q.mVec128.m128_f32[2] = v37;
    if ( v77 )
    {
      v34 = 0.0;
      v37 = 0.0;
      p.mVec128.m128_i32[2] = 0;
      q.mVec128.m128_i32[2] = 0;
    }
    v38 = v34 - v37;
    v39 = v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2] * v38;
    v82.mVec128.m128_f32[2] = v38;
    v40 = v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1];
    v82.mVec128.m128_f32[0] = v33 - v35;
    v41 = (float)(v39
                + (float)(v40
                        * (float)((float)((float)((float)((float)(*((float *)&v94 + 1) * result.mVec128.m128_f32[1])
                                                        + (float)(*(float *)&v95 * result.mVec128.m128_f32[2]))
                                                + (float)(*(float *)&v94 * result.mVec128.m128_f32[0]))
                                        + *((float *)&v98 + 1))
                                - v36)))
        + (float)((float)(v33 - v35) * v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[0]);
    v82.mVec128.m128_f32[1] = (float)((float)((float)((float)(*((float *)&v94 + 1) * result.mVec128.m128_f32[1])
                                                    + (float)(*(float *)&v95 * result.mVec128.m128_f32[2]))
                                            + (float)(*(float *)&v94 * result.mVec128.m128_f32[0]))
                                    + *((float *)&v98 + 1))
                            - v36;
    _X = v41;
    if ( v41 > 0.0 && (float)(v41 * v41) > (float)(output->m_maximumDistanceSquared * *((float *)&v83 + 1)) )
    {
      v5->m_transformB.m_basis.m_el[1].mVec128.m128_i32[0] = 10;
      goto LABEL_29;
    }
    if ( btVoronoiSimplexSolver::inSimplex(
           (btVoronoiSimplexSolver *)v5->m_transformA.m_basis.m_el[2].mVec128.m128_i32[1],
           &v82) )
    {
      v5->m_transformB.m_basis.m_el[1].mVec128.m128_i32[0] = 1;
      goto LABEL_29;
    }
    if ( (float)(*((float *)&v83 + 1) * 0.000001) >= (float)(*((float *)&v83 + 1) - _X) )
      break;
    btVoronoiSimplexSolver::addVertex(input->m_simplexSolver, &v82, &p, &q);
    v42 = input->m_simplexSolver;
    updated = btVoronoiSimplexSolver::updateClosestVectorAndPoints(v43, v42);
    v45 = v42->m_cachedV.mVec128.m128_u64[0];
    v46 = v42->m_cachedV.mVec128.m128_u64[1];
    v90 = v45;
    v91 = v46;
    if ( !updated )
    {
      input->m_degenerateSimplex = 3;
LABEL_28:
      v5 = (const btDiscreteCollisionDetectorInterface::ClosestPointInput *)input;
      goto LABEL_29;
    }
    v47 = (float)((float)(*(float *)&v90 * *(float *)&v90) + (float)(*((float *)&v90 + 1) * *((float *)&v90 + 1)))
        + (float)(*(float *)&v91 * *(float *)&v91);
    if ( v47 < 0.000001 )
    {
      input->m_cachedSeparatingAxis.mVec128.m128_u64[0] = v45;
      input->m_cachedSeparatingAxis.mVec128.m128_u64[1] = v46;
      input->m_degenerateSimplex = 6;
      goto LABEL_28;
    }
    v48 = (float)(*((float *)&v83 + 1) * 0.00000011920929) < (float)(*((float *)&v83 + 1) - v47);
    *((float *)&v83 + 1) = (float)((float)(*(float *)&v90 * *(float *)&v90)
                                 + (float)(*((float *)&v90 + 1) * *((float *)&v90 + 1)))
                         + (float)(*(float *)&v91 * *(float *)&v91);
    if ( !v48 )
    {
      input->m_degenerateSimplex = 12;
      goto LABEL_28;
    }
    m_curIter = input->m_curIter;
    input->m_cachedSeparatingAxis.mVec128.m128_u64[0] = v45;
    input->m_cachedSeparatingAxis.mVec128.m128_u64[1] = v46;
    input->m_curIter = m_curIter + 1;
    v5 = (const btDiscreteCollisionDetectorInterface::ClosestPointInput *)input;
    if ( m_curIter > 1000 )
      goto LABEL_37;
    if ( input->m_simplexSolver->m_numVertices == 4 )
    {
      input->m_degenerateSimplex = 13;
      goto LABEL_37;
    }
  }
  if ( (float)(*((float *)&v83 + 1) - _X) > 0.0 )
    v5->m_transformB.m_basis.m_el[1].mVec128.m128_i32[0] = 11;
  else
    v5->m_transformB.m_basis.m_el[1].mVec128.m128_i32[0] = 2;
LABEL_29:
  v50 = (btVoronoiSimplexSolver *)v5->m_transformA.m_basis.m_el[2].mVec128.m128_i32[1];
  btVoronoiSimplexSolver::updateClosestVectorAndPoints(v32, v50);
  v51 = v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1];
  v52 = v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2];
  v82.mVec128 = (__m128)v50->m_cachedP2;
  v81.mVec128 = (__m128)v5->m_transformA.m_basis.m_el[1];
  v53 = (float)((float)(v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[0]
                      * v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[0])
              + (float)(v51 * v51))
      + (float)(v52 * v52);
  _X = v53;
  if ( v53 < 0.0001 )
    v5->m_transformB.m_basis.m_el[1].mVec128.m128_i32[0] = 5;
  if ( v53 <= 1.4210855e-14 )
  {
    v5->m_transformB.m_basis.m_el[0].mVec128.m128_i32[2] = 2;
  }
  else
  {
    v54 = 1.0 / sqrtf(_X);
    v85 = v54;
    v81.mVec128.m128_f32[0] = v81.mVec128.m128_f32[0] * v54;
    v81.mVec128.m128_f32[1] = v81.mVec128.m128_f32[1] * v54;
    v81.mVec128.m128_f32[2] = v54 * v81.mVec128.m128_f32[2];
    v55 = sqrtf(*((float *)&v83 + 1));
    v56 = v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[0];
    v57 = v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1];
    v58 = v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2];
    v76 = 1;
    v5->m_transformB.m_basis.m_el[0].mVec128.m128_i32[2] = 1;
    _X = v79 / v55;
    v82.mVec128.m128_f32[0] = (float)(v56 * _X) + v82.mVec128.m128_f32[0];
    v82.mVec128.m128_f32[1] = v82.mVec128.m128_f32[1] + (float)(v57 * _X);
    v82.mVec128.m128_f32[2] = v82.mVec128.m128_f32[2] + (float)(v58 * _X);
    v78 = (float)(*(float *)&clear_value / v85) - v89;
  }
LABEL_37:
  v59 = v5->m_transformB.m_basis.m_el[1].mVec128.m128_i32[1]
     && v5->m_transformA.m_basis.m_el[2].mVec128.m128_i32[0]
     && v5->m_transformB.m_basis.m_el[1].mVec128.m128_i32[0]
     && (float)(v89 + v78) < 0.01;
  if ( v76 && !v59 || !v5->m_transformA.m_basis.m_el[2].mVec128.m128_i32[0] )
    goto LABEL_53;
  m128_f32 = v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32;
  v5->m_transformA.m_basis.m_el[1].mVec128.m128_i32[0] = 0;
  v5->m_transformA.m_basis.m_el[1].mVec128.m128_i32[1] = 0;
  v5->m_transformA.m_basis.m_el[1].mVec128.m128_i32[2] = 0;
  v5->m_transformA.m_basis.m_el[1].mVec128.m128_i32[3] = 0;
  _X_4 = (btDiscreteCollisionDetectorInterface::Result_vtbl *)output->m_stackAlloc;
  v61 = v5->m_transformA.m_basis.m_el[2].mVec128.m128_i32[0];
  v62 = *(unsigned __int8 (__thiscall **)(int, int, int, int, unsigned __int64 *, unsigned __int64 *, btVector3 *, btVector3 *, btVector3 *, btIDebugDraw *, btDiscreteCollisionDetectorInterface::Result_vtbl *))(*(_DWORD *)v61 + 4);
  ++gNumDeepPenetrationChecks;
  if ( !v62(
          v61,
          v5->m_transformA.m_basis.m_el[2].mVec128.m128_i32[1],
          v5->m_transformA.m_basis.m_el[2].mVec128.m128_i32[2],
          v5->m_transformA.m_basis.m_el[2].mVec128.m128_i32[3],
          &v92,
          &v100,
          &v5->m_transformA.m_basis.m_el[1],
          &v88,
          &p,
          debugDrawa,
          _X_4) )
  {
    if ( (float)((float)((float)(*m128_f32 * *m128_f32)
                       + (float)(v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1]
                               * v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1]))
               + (float)(v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2]
                       * v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2])) > 0.0 )
    {
      v70 = sqrtf(
              (float)((float)((float)(v88.mVec128.m128_f32[2] - p.mVec128.m128_f32[2])
                            * (float)(v88.mVec128.m128_f32[2] - p.mVec128.m128_f32[2]))
                    + (float)((float)(v88.mVec128.m128_f32[1] - p.mVec128.m128_f32[1])
                            * (float)(v88.mVec128.m128_f32[1] - p.mVec128.m128_f32[1])))
            + (float)((float)(v88.mVec128.m128_f32[0] - p.mVec128.m128_f32[0])
                    * (float)(v88.mVec128.m128_f32[0] - p.mVec128.m128_f32[0])));
      v85 = v70 - v89;
      if ( !v76 || v78 > v85 )
      {
        v71 = v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1];
        v72 = v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2];
        v78 = v85;
        v82.mVec128 = p.mVec128;
        v82.mVec128.m128_f32[0] = (float)(v79 * *m128_f32) + p.mVec128.m128_f32[0];
        v81.mVec128.m128_u64[0] = *(_QWORD *)m128_f32;
        v73 = v5->m_transformA.m_basis.m_el[1].mVec128.m128_u64[1];
        v82.mVec128.m128_f32[1] = (float)(v71 * v79) + p.mVec128.m128_f32[1];
        v81.mVec128.m128_u64[1] = v73;
        v82.mVec128.m128_f32[2] = (float)(v72 * v79) + p.mVec128.m128_f32[2];
        v74 = 1.0
            / sqrtf(
                (float)((float)(v81.mVec128.m128_f32[0] * v81.mVec128.m128_f32[0])
                      + (float)(*(float *)&v73 * *(float *)&v73))
              + (float)(v81.mVec128.m128_f32[1] * v81.mVec128.m128_f32[1]));
        v5->m_transformB.m_basis.m_el[0].mVec128.m128_i32[2] = 6;
        v81.mVec128.m128_f32[0] = v81.mVec128.m128_f32[0] * v74;
        v81.mVec128.m128_f32[1] = v81.mVec128.m128_f32[1] * v74;
        v81.mVec128.m128_f32[2] = v74 * v81.mVec128.m128_f32[2];
        goto LABEL_54;
      }
      v5->m_transformB.m_basis.m_el[0].mVec128.m128_i32[2] = 5;
    }
LABEL_53:
    if ( !v76 )
      return;
    goto LABEL_54;
  }
  q.mVec128.m128_i32[3] = 0;
  q.mVec128.m128_f32[2] = p.mVec128.m128_f32[2] - v88.mVec128.m128_f32[2];
  q.mVec128.m128_f32[1] = p.mVec128.m128_f32[1] - v88.mVec128.m128_f32[1];
  v63 = (float)((float)(q.mVec128.m128_f32[2] * q.mVec128.m128_f32[2])
              + (float)((float)(p.mVec128.m128_f32[1] - v88.mVec128.m128_f32[1])
                      * (float)(p.mVec128.m128_f32[1] - v88.mVec128.m128_f32[1])))
      + (float)((float)(p.mVec128.m128_f32[0] - v88.mVec128.m128_f32[0])
              * (float)(p.mVec128.m128_f32[0] - v88.mVec128.m128_f32[0]));
  q.mVec128.m128_f32[0] = p.mVec128.m128_f32[0] - v88.mVec128.m128_f32[0];
  v80 = v63;
  if ( v63 <= 1.4210855e-14 )
  {
    v64 = v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1];
    v65 = v5->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2];
    q.mVec128.m128_u64[0] = *(_QWORD *)m128_f32;
    q.mVec128.m128_u64[1] = v5->m_transformA.m_basis.m_el[1].mVec128.m128_u64[1];
    v63 = (float)((float)(*m128_f32 * *m128_f32) + (float)(v64 * v64)) + (float)(v65 * v65);
    v80 = v63;
  }
  if ( v63 <= 1.4210855e-14 )
  {
    v5->m_transformB.m_basis.m_el[0].mVec128.m128_i32[2] = 9;
    goto LABEL_53;
  }
  v66 = 1.0 / sqrtf(v80);
  q.mVec128.m128_f32[0] = q.mVec128.m128_f32[0] * v66;
  q.mVec128.m128_f32[1] = q.mVec128.m128_f32[1] * v66;
  q.mVec128.m128_f32[2] = v66 * q.mVec128.m128_f32[2];
  v85 = -sqrtf(
           (float)((float)((float)(v88.mVec128.m128_f32[2] - p.mVec128.m128_f32[2])
                         * (float)(v88.mVec128.m128_f32[2] - p.mVec128.m128_f32[2]))
                 + (float)((float)(v88.mVec128.m128_f32[1] - p.mVec128.m128_f32[1])
                         * (float)(v88.mVec128.m128_f32[1] - p.mVec128.m128_f32[1])))
         + (float)((float)(v88.mVec128.m128_f32[0] - p.mVec128.m128_f32[0])
                 * (float)(v88.mVec128.m128_f32[0] - p.mVec128.m128_f32[0])));
  if ( v76 && v78 <= v85 )
  {
    v5->m_transformB.m_basis.m_el[0].mVec128.m128_i32[2] = 8;
    goto LABEL_53;
  }
  v78 = v85;
  v82.mVec128 = p.mVec128;
  v81.mVec128 = q.mVec128;
  v5->m_transformB.m_basis.m_el[0].mVec128.m128_i32[2] = 3;
LABEL_54:
  if ( v78 < 0.0 || output->m_maximumDistanceSquared > (float)(v78 * v78) )
  {
    v67 = v81.mVec128.m128_u64[0];
    v5->m_transformB.m_basis.m_el[0].mVec128.m128_f32[1] = v78;
    *(float *)&v90 = v82.mVec128.m128_f32[0] + v108;
    v68 = v82.mVec128.m128_f32[1] + v109;
    v5->m_transformA.m_basis.m_el[1].mVec128.m128_u64[0] = v67;
    v5->m_transformA.m_basis.m_el[1].mVec128.m128_u64[1] = v81.mVec128.m128_u64[1];
    addContactPoint = (void (__thiscall *)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *))debugDraw->addContactPoint;
    *((float *)&v90 + 1) = v68;
    *(float *)&v91 = v82.mVec128.m128_f32[2] + v110;
    HIDWORD(v91) = 0;
    addContactPoint((btIDebugDraw *)debugDraw, &v81, (const btVector3 *)&v90, (const btVector3 *)LODWORD(v78));
  }
}
