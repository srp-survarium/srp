void __userpurge btContinuousConvexCollision::computeClosestPoints(
        const btTransform *transA@<edi>,
        const btTransform *transB@<esi>,
        btVoronoiSimplexSolver *a3@<ecx>,
        btContinuousConvexCollision *this,
        btPointCollector *pointCollector)
{
  const btConvexShape *m_convexA; // ecx
  double v6; // st7
  btConvexPenetrationDepthSolver *m_penetrationDepthSolver; // eax
  btVoronoiSimplexSolver *m_simplexSolver; // ecx
  unsigned __int64 v9; // xmm0_8
  unsigned __int64 v10; // xmm0_8
  unsigned __int64 v11; // xmm0_8
  const btConvexShape *v12; // eax
  const btStaticPlaneShape *m_planeShape; // ebx
  unsigned __int64 v14; // xmm0_8
  btTransform *v15; // eax
  float v16; // xmm4_4
  float v17; // xmm3_4
  float v18; // xmm7_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm7_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm6_4
  float v25; // xmm2_4
  float v26; // xmm6_4
  float v27; // xmm6_4
  float v28; // xmm7_4
  float *v29; // eax
  float v30; // xmm3_4
  float v31; // xmm4_4
  float v32; // xmm5_4
  float v33; // xmm1_4
  float v34; // xmm7_4
  float v35; // xmm2_4
  float v36; // xmm6_4
  float v37; // xmm7_4
  float v38; // xmm6_4
  float v39; // xmm7_4
  float v40; // xmm6_4
  float v41; // xmm7_4
  float v42; // xmm6_4
  float v43; // xmm4_4
  float v44; // xmm1_4
  btVector3 *(__thiscall *localGetSupportingVertex)(btConvexShape *, btVector3 *, const btVector3 *); // edx
  float v46; // xmm3_4
  float v47; // xmm4_4
  float v48; // xmm1_4
  float v49; // xmm3_4
  float v50; // xmm2_4
  float v51; // xmm3_4
  float v52; // xmm6_4
  float v53; // xmm1_4
  float v54; // xmm5_4
  float v55; // xmm2_4
  float v56; // xmm4_4
  float v57; // xmm2_4
  float v58; // xmm4_4
  float v59; // xmm7_4
  btPointCollector_vtbl *v60; // eax
  float v61; // xmm2_4
  float v62; // xmm3_4
  float v63; // xmm2_4
  float v64; // xmm1_4
  float v65; // xmm2_4
  float v66; // xmm3_4
  float v67; // xmm4_4
  float v68; // xmm7_4
  int m_shapeType; // [esp+984h] [ebp-1D4h]
  float v70; // [esp+984h] [ebp-1D4h]
  float v71; // [esp+984h] [ebp-1D4h]
  float v72; // [esp+988h] [ebp-1D0h]
  float v73; // [esp+988h] [ebp-1D0h]
  float v74; // [esp+988h] [ebp-1D0h]
  const btConvexShape *v75; // [esp+98Ch] [ebp-1CCh]
  float v76; // [esp+98Ch] [ebp-1CCh]
  int v77; // [esp+990h] [ebp-1C8h]
  float v78; // [esp+990h] [ebp-1C8h]
  const btConvexShape *m_convexB1; // [esp+994h] [ebp-1C4h]
  float v80; // [esp+994h] [ebp-1C4h]
  float v81; // [esp+998h] [ebp-1C0h]
  float v82; // [esp+99Ch] [ebp-1BCh]
  float v83; // [esp+9A0h] [ebp-1B8h]
  float v84; // [esp+9A0h] [ebp-1B8h]
  float v85; // [esp+9A4h] [ebp-1B4h]
  float v86; // [esp+9A4h] [ebp-1B4h]
  btTransform v87; // [esp+9A8h] [ebp-1B0h] BYREF
  float v88; // [esp+9E8h] [ebp-170h]
  float v89; // [esp+9ECh] [ebp-16Ch]
  float v90; // [esp+9F0h] [ebp-168h]
  float v91; // [esp+9F4h] [ebp-164h]
  float v92; // [esp+9F8h] [ebp-160h]
  float v93; // [esp+9FCh] [ebp-15Ch]
  float v94; // [esp+A00h] [ebp-158h]
  const btConvexShape *v95; // [esp+A04h] [ebp-154h]
  float v96; // [esp+A08h] [ebp-150h]
  float v97; // [esp+A0Ch] [ebp-14Ch]
  float v98; // [esp+A10h] [ebp-148h]
  float v99; // [esp+A14h] [ebp-144h]
  float v100; // [esp+A18h] [ebp-140h]
  float v101; // [esp+A1Ch] [ebp-13Ch]
  float v102; // [esp+A20h] [ebp-138h]
  float v103[4]; // [esp+A28h] [ebp-130h] BYREF
  float v104[4]; // [esp+A38h] [ebp-120h] BYREF
  float v105[4]; // [esp+A48h] [ebp-110h] BYREF
  float v106; // [esp+A58h] [ebp-100h] BYREF
  float v107; // [esp+A5Ch] [ebp-FCh]
  float v108; // [esp+A60h] [ebp-F8h]
  btDiscreteCollisionDetectorInterface::ClosestPointInput input; // [esp+A68h] [ebp-F0h] BYREF
  btVector3 v110; // [esp+AF8h] [ebp-60h]
  unsigned __int64 v111; // [esp+B08h] [ebp-50h]
  unsigned __int64 v112; // [esp+B10h] [ebp-48h]
  btVector3 v113; // [esp+B18h] [ebp-40h]
  unsigned __int64 v114; // [esp+B28h] [ebp-30h]
  unsigned __int64 v115; // [esp+B30h] [ebp-28h]
  unsigned __int64 v116; // [esp+B38h] [ebp-20h]
  unsigned __int64 v117; // [esp+B40h] [ebp-18h]
  int v118; // [esp+B48h] [ebp-10h]
  int v119; // [esp+B4Ch] [ebp-Ch]

  if ( this->m_convexB1 )
  {
    btVoronoiSimplexSolver::reset(a3, (int)this->m_simplexSolver);
    m_convexA = this->m_convexA;
    m_convexB1 = this->m_convexB1;
    m_shapeType = m_convexB1->m_shapeType;
    v77 = m_convexA->m_shapeType;
    v75 = m_convexA;
    v72 = ((double (*)(void))m_convexA->getMargin)();
    v6 = ((double (__thiscall *)(const btConvexShape *))this->m_convexB1->getMargin)(this->m_convexB1);
    input.m_transformA.m_origin.mVec128.m128_f32[2] = v72;
    input.m_transformA.m_basis.m_el[1].mVec128.m128_i32[0] = 0;
    input.m_transformA.m_origin.mVec128.m128_f32[3] = v6;
    input.m_transformA.m_basis.m_el[1].mVec128.m128_i32[3] = 0;
    v118 = 1566444395;
    input.m_transformB.m_basis.m_el[2].mVec128.m128_u64[0] = transA->m_basis.m_el[0].mVec128.m128_u64[0];
    m_penetrationDepthSolver = this->m_penetrationDepthSolver;
    input.m_transformB.m_basis.m_el[2].mVec128.m128_u64[1] = transA->m_basis.m_el[0].mVec128.m128_u64[1];
    m_simplexSolver = this->m_simplexSolver;
    input.m_transformB.m_origin = transA->m_basis.m_el[1];
    *(btVector3 *)&input.m_maximumDistanceSquared = transA->m_basis.m_el[2];
    v110.mVec128 = (__m128)transA->m_origin;
    v111 = transB->m_basis.m_el[0].mVec128.m128_u64[0];
    v112 = transB->m_basis.m_el[0].mVec128.m128_u64[1];
    v113.mVec128 = (__m128)transB->m_basis.m_el[1];
    v114 = transB->m_basis.m_el[2].mVec128.m128_u64[0];
    v9 = transB->m_basis.m_el[2].mVec128.m128_u64[1];
    input.m_transformA.m_basis.m_el[2].mVec128.m128_u64[0] = __PAIR64__(
                                                               (unsigned int)m_simplexSolver,
                                                               (unsigned int)m_penetrationDepthSolver);
    v115 = v9;
    v10 = transB->m_origin.mVec128.m128_u64[0];
    input.m_transformA.m_basis.m_el[2].mVec128.m128_u64[1] = __PAIR64__((unsigned int)m_convexB1, (unsigned int)v75);
    v116 = v10;
    v11 = transB->m_origin.mVec128.m128_u64[1];
    input.m_transformA.m_basis.m_el[0].mVec128.m128_i32[0] = (int)&btGjkPairDetector::`vftable';
    *(unsigned __int64 *)((char *)input.m_transformA.m_basis.m_el[1].mVec128.m128_u64 + 4) = (unsigned int)clear_value;
    input.m_transformA.m_origin.mVec128.m128_u64[0] = __PAIR64__(m_shapeType, v77);
    input.m_transformB.m_basis.m_el[0].mVec128.m128_i8[0] = 0;
    input.m_transformB.m_basis.m_el[0].mVec128.m128_i32[2] = -1;
    input.m_transformB.m_basis.m_el[1].mVec128.m128_i32[1] = 1;
    v119 = 0;
    v117 = v11;
    btGjkPairDetector::getClosestPointsNonVirtual(
      (btGjkPairDetector *)&input.m_transformB.m_basis.m_el[2],
      (btGjkPairDetector *)&input,
      (const btDiscreteCollisionDetectorInterface::ClosestPointInput *)&input.m_transformB.m_basis.m_el[2],
      pointCollector,
      0);
  }
  else
  {
    v12 = this->m_convexA;
    m_planeShape = this->m_planeShape;
    v87.m_basis.m_el[0].mVec128.m128_u64[0] = transA->m_basis.m_el[0].mVec128.m128_u64[0];
    v87.m_basis.m_el[0].mVec128.m128_u64[1] = transA->m_basis.m_el[0].mVec128.m128_u64[1];
    v87.m_basis.m_el[1] = transA->m_basis.m_el[1];
    v87.m_basis.m_el[2] = transA->m_basis.m_el[2];
    v14 = transA->m_origin.mVec128.m128_u64[0];
    v95 = v12;
    v87.m_origin.mVec128.m128_u64[0] = v14;
    v87.m_origin.mVec128.m128_u64[1] = transA->m_origin.mVec128.m128_u64[1];
    v15 = btTransform::inverse(transB, &input.m_transformA);
    v16 = v15->m_basis.m_el[0].mVec128.m128_f32[1];
    LODWORD(v14) = v15->m_basis.m_el[0].mVec128.m128_i32[0];
    v17 = v15->m_basis.m_el[0].mVec128.m128_f32[2];
    v18 = v15->m_basis.m_el[1].mVec128.m128_f32[2] * v87.m_origin.mVec128.m128_f32[2];
    v100 = (float)((float)((float)(v87.m_origin.mVec128.m128_f32[0] * v15->m_basis.m_el[0].mVec128.m128_f32[0])
                         + (float)(v87.m_origin.mVec128.m128_f32[1] * v16))
                 + (float)(v87.m_origin.mVec128.m128_f32[2] * v17))
         + v15->m_origin.mVec128.m128_f32[0];
    v19 = v87.m_origin.mVec128.m128_f32[0] * v15->m_basis.m_el[2].mVec128.m128_f32[0];
    v20 = (float)((float)((float)(v15->m_basis.m_el[1].mVec128.m128_f32[1] * v87.m_origin.mVec128.m128_f32[1]) + v18)
                + (float)(v87.m_origin.mVec128.m128_f32[0] * v15->m_basis.m_el[1].mVec128.m128_f32[0]))
        + v15->m_origin.mVec128.m128_f32[1];
    v21 = v15->m_basis.m_el[2].mVec128.m128_f32[2] * v87.m_basis.m_el[2].mVec128.m128_f32[1];
    v101 = v20;
    v22 = (float)((float)((float)(v15->m_basis.m_el[2].mVec128.m128_f32[1] * v87.m_origin.mVec128.m128_f32[1])
                        + (float)(v15->m_basis.m_el[2].mVec128.m128_f32[2] * v87.m_origin.mVec128.m128_f32[2]))
                + v19)
        + v15->m_origin.mVec128.m128_f32[2];
    v23 = v15->m_basis.m_el[2].mVec128.m128_f32[1];
    v24 = v15->m_basis.m_el[2].mVec128.m128_f32[2] * v87.m_basis.m_el[2].mVec128.m128_f32[2];
    v102 = v22;
    v25 = (float)((float)(v23 * v87.m_basis.m_el[1].mVec128.m128_f32[2]) + v24)
        + (float)(v87.m_basis.m_el[0].mVec128.m128_f32[2] * v15->m_basis.m_el[2].mVec128.m128_f32[0]);
    v26 = v15->m_basis.m_el[2].mVec128.m128_f32[1];
    v93 = v25;
    v83 = (float)((float)(v26 * v87.m_basis.m_el[1].mVec128.m128_f32[1]) + v21)
        + (float)(v87.m_basis.m_el[0].mVec128.m128_f32[1] * v15->m_basis.m_el[2].mVec128.m128_f32[0]);
    v85 = (float)((float)(v15->m_basis.m_el[2].mVec128.m128_f32[1] * v87.m_basis.m_el[1].mVec128.m128_f32[0])
                + (float)(v15->m_basis.m_el[2].mVec128.m128_f32[2] * v87.m_basis.m_el[2].mVec128.m128_f32[0]))
        + (float)(v15->m_basis.m_el[2].mVec128.m128_f32[0] * v87.m_basis.m_el[0].mVec128.m128_f32[0]);
    v92 = (float)((float)(v15->m_basis.m_el[1].mVec128.m128_f32[1] * v87.m_basis.m_el[1].mVec128.m128_f32[2])
                + (float)(v15->m_basis.m_el[1].mVec128.m128_f32[2] * v87.m_basis.m_el[2].mVec128.m128_f32[2]))
        + (float)(v87.m_basis.m_el[0].mVec128.m128_f32[2] * v15->m_basis.m_el[1].mVec128.m128_f32[0]);
    v70 = v15->m_basis.m_el[1].mVec128.m128_f32[1] * v87.m_basis.m_el[1].mVec128.m128_f32[0];
    v27 = v15->m_basis.m_el[1].mVec128.m128_f32[2] * v87.m_basis.m_el[2].mVec128.m128_f32[0];
    v98 = (float)((float)(v15->m_basis.m_el[1].mVec128.m128_f32[1] * v87.m_basis.m_el[1].mVec128.m128_f32[1])
                + (float)(v15->m_basis.m_el[1].mVec128.m128_f32[2] * v87.m_basis.m_el[2].mVec128.m128_f32[1]))
        + (float)(v15->m_basis.m_el[1].mVec128.m128_f32[0] * v87.m_basis.m_el[0].mVec128.m128_f32[1]);
    v28 = (float)(v70 + v27)
        + (float)(v15->m_basis.m_el[1].mVec128.m128_f32[0] * v87.m_basis.m_el[0].mVec128.m128_f32[0]);
    v88 = (float)((float)(v87.m_basis.m_el[1].mVec128.m128_f32[2] * v16)
                + (float)(v87.m_basis.m_el[0].mVec128.m128_f32[2] * *(float *)&v14))
        + (float)(v87.m_basis.m_el[2].mVec128.m128_f32[2] * v17);
    v94 = v28;
    v97 = (float)((float)(v87.m_basis.m_el[1].mVec128.m128_f32[1] * v16)
                + (float)(v87.m_basis.m_el[0].mVec128.m128_f32[1] * *(float *)&v14))
        + (float)(v87.m_basis.m_el[2].mVec128.m128_f32[1] * v17);
    v91 = (float)((float)(*(float *)&v14 * v87.m_basis.m_el[0].mVec128.m128_f32[0])
                + (float)(v87.m_basis.m_el[1].mVec128.m128_f32[0] * v16))
        + (float)(v87.m_basis.m_el[2].mVec128.m128_f32[0] * v17);
    v29 = (float *)btTransform::inverse(&v87, &input.m_transformA);
    v30 = transB->m_basis.m_el[2].mVec128.m128_f32[2];
    v31 = transB->m_basis.m_el[1].mVec128.m128_f32[2];
    LODWORD(v14) = transB->m_basis.m_el[0].mVec128.m128_i32[2];
    v32 = (float)((float)(v29[9] * v31) + (float)(v29[10] * v30)) + (float)(*(float *)&v14 * v29[8]);
    v33 = transB->m_basis.m_el[0].mVec128.m128_f32[1];
    v78 = transB->m_basis.m_el[1].mVec128.m128_f32[1];
    v80 = transB->m_basis.m_el[2].mVec128.m128_f32[1];
    v73 = v29[9] * transB->m_basis.m_el[1].mVec128.m128_f32[0];
    v34 = v29[10];
    v76 = transB->m_basis.m_el[1].mVec128.m128_f32[0];
    v96 = (float)((float)(v29[9] * v78) + (float)(v34 * v80)) + (float)(v33 * v29[8]);
    v71 = transB->m_basis.m_el[2].mVec128.m128_f32[0];
    v35 = transB->m_basis.m_el[0].mVec128.m128_f32[0];
    v36 = (float)(v73 + (float)(v34 * v71)) + (float)(transB->m_basis.m_el[0].mVec128.m128_f32[0] * v29[8]);
    v37 = v29[6] * v30;
    v90 = v36;
    v38 = (float)((float)(v29[5] * v31) + v37) + (float)(*(float *)&v14 * v29[4]);
    v39 = v29[6] * v80;
    v89 = v38;
    v40 = (float)((float)(v29[5] * v78) + v39) + (float)(v33 * v29[4]);
    v41 = v29[6] * v71;
    v99 = v40;
    v42 = (float)((float)(v29[5] * v76) + v41) + (float)(v35 * v29[4]);
    v74 = v29[1];
    *(float *)&v14 = (float)(*(float *)&v14 * *v29) + (float)(v31 * v74);
    v43 = v29[2];
    v81 = *(float *)&v14 + (float)(v30 * v43);
    v44 = (float)((float)(v33 * *v29) + (float)(v78 * v74)) + (float)(v80 * v43);
    localGetSupportingVertex = v95->localGetSupportingVertex;
    v82 = (float)((float)(v35 * *v29) + (float)(v76 * v74)) + (float)(v71 * v43);
    *(float *)&v14 = -m_planeShape->m_planeNormal.mVec128.m128_f32[0];
    v46 = -m_planeShape->m_planeNormal.mVec128.m128_f32[1];
    v47 = -m_planeShape->m_planeNormal.mVec128.m128_f32[2];
    v104[0] = (float)((float)(v46 * v44) + (float)(v47 * v81)) + (float)(*(float *)&v14 * v82);
    v104[2] = (float)((float)(*(float *)&v14 * v90) + (float)(v46 * v96)) + (float)(v47 * v32);
    v104[1] = (float)((float)(v46 * v99) + (float)(v47 * v89)) + (float)(*(float *)&v14 * v42);
    v104[3] = 0.0;
    ((void (__stdcall *)(float *, float *))localGetSupportingVertex)(&v106, v104);
    *(float *)&v14 = (float)((float)((float)(v106 * v91) + (float)(v107 * v97)) + (float)(v108 * v88)) + v100;
    v48 = (float)((float)((float)(v106 * v94) + (float)(v107 * v98)) + (float)(v108 * v92)) + v101;
    v49 = (float)((float)((float)(v108 * v93) + (float)(v106 * v85)) + (float)(v107 * v83)) + v102;
    v50 = (float)((float)((float)(m_planeShape->m_planeNormal.mVec128.m128_f32[0] * *(float *)&v14)
                        + (float)(m_planeShape->m_planeNormal.mVec128.m128_f32[1] * v48))
                + (float)(m_planeShape->m_planeNormal.mVec128.m128_f32[2] * v49))
        - m_planeShape->m_planeConstant;
    v51 = v49 - (float)(m_planeShape->m_planeNormal.mVec128.m128_f32[2] * v50);
    v86 = v50;
    *(float *)&v14 = *(float *)&v14 - (float)(m_planeShape->m_planeNormal.mVec128.m128_f32[0] * v50);
    v52 = transB->m_basis.m_el[0].mVec128.m128_f32[1];
    v84 = transB->m_basis.m_el[0].mVec128.m128_f32[0];
    v53 = v48 - (float)(m_planeShape->m_planeNormal.mVec128.m128_f32[1] * v50);
    v54 = transB->m_basis.m_el[0].mVec128.m128_f32[2];
    v55 = transB->m_basis.m_el[1].mVec128.m128_f32[2];
    v105[0] = (float)((float)((float)(v52 * v53) + (float)(v54 * v51))
                    + (float)(transB->m_basis.m_el[0].mVec128.m128_f32[0] * *(float *)&v14))
            + transB->m_origin.mVec128.m128_f32[0];
    v56 = transB->m_basis.m_el[1].mVec128.m128_f32[0] * *(float *)&v14;
    *(float *)&v14 = *(float *)&v14 * transB->m_basis.m_el[2].mVec128.m128_f32[0];
    v57 = (float)((float)((float)(v55 * v51) + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[1] * v53)) + v56)
        + transB->m_origin.mVec128.m128_f32[1];
    v58 = transB->m_basis.m_el[2].mVec128.m128_f32[2];
    v59 = transB->m_basis.m_el[1].mVec128.m128_f32[2];
    v60 = pointCollector->__vftable;
    v105[1] = v57;
    v61 = (float)(transB->m_basis.m_el[2].mVec128.m128_f32[2] * v51)
        + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[1] * v53);
    v62 = transB->m_basis.m_el[2].mVec128.m128_f32[1];
    v63 = (float)(v61 + *(float *)&v14) + transB->m_origin.mVec128.m128_f32[2];
    v105[3] = 0.0;
    v105[2] = v63;
    v64 = m_planeShape->m_planeNormal.mVec128.m128_f32[2];
    LODWORD(v14) = m_planeShape->m_planeNormal.mVec128.m128_i32[1];
    v65 = m_planeShape->m_planeNormal.mVec128.m128_f32[0];
    v66 = (float)((float)(v62 * *(float *)&v14) + (float)(v58 * v64))
        + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[0] * v65);
    v67 = (float)(transB->m_basis.m_el[1].mVec128.m128_f32[1] * *(float *)&v14) + (float)(v59 * v64);
    v68 = v65 * transB->m_basis.m_el[1].mVec128.m128_f32[0];
    v103[0] = (float)((float)(*(float *)&v14 * v52) + (float)(v64 * v54)) + (float)(v65 * v84);
    v103[1] = v67 + v68;
    v103[2] = v66;
    v103[3] = 0.0;
    ((void (__stdcall *)(float *, float *, float))v60->addContactPoint)(v103, v105, COERCE_FLOAT(LODWORD(v86)));
  }
}
