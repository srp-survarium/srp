bool __thiscall btMinkowskiPenetrationDepthSolver::calcPenDepth(
        btMinkowskiPenetrationDepthSolver *this,
        btVoronoiSimplexSolver *simplexSolver,
        btConvexShape *convexA,
        btConvexShape *convexB,
        const btTransform *transA,
        const btTransform *transB,
        btVector3 *v,
        btVector3 *pa,
        btVector3 *pb,
        btIDebugDraw *debugDraw,
        btStackAlloc *stackAlloc)
{
  int m_shapeType; // eax
  unsigned __int64 v12; // rcx
  int v13; // eax
  btVector3 *PenetrationDirections; // eax
  int v15; // edx
  int v16; // ecx
  float v17; // xmm5_4
  float v18; // xmm1_4
  float v19; // xmm4_4
  float v20; // xmm2_4
  float v21; // xmm7_4
  float v22; // xmm6_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm4_4
  int v27; // xmm1_4
  float v28; // eax
  unsigned int v29; // ebx
  float v30; // xmm4_4
  float v31; // xmm0_4
  float v32; // xmm5_4
  float v33; // xmm1_4
  float v34; // xmm4_4
  int v35; // xmm0_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm4_4
  float v40; // xmm1_4
  float v41; // eax
  unsigned int v42; // ebx
  float v43; // xmm4_4
  float v44; // xmm5_4
  float v45; // xmm1_4
  float v46; // xmm4_4
  float v47; // xmm0_4
  float v48; // xmm2_4
  float v49; // xmm1_4
  float v50; // xmm0_4
  float v51; // xmm2_4
  float v52; // xmm4_4
  int v53; // xmm1_4
  btVector3 *v54; // eax
  int v55; // edx
  int v56; // ecx
  float v57; // xmm4_4
  float v58; // xmm7_4
  float v59; // xmm5_4
  float v60; // xmm7_4
  float v61; // xmm0_4
  float v62; // xmm5_4
  float v63; // xmm2_4
  float v64; // xmm2_4
  bool result; // al
  float v66; // xmm1_4
  float v67; // xmm0_4
  unsigned int v68; // edx
  double (*v69)(void); // eax
  float v70; // xmm3_4
  unsigned __int64 v71; // xmm0_8
  __m128i v72; // xmm0
  float v73; // xmm0_4
  int v74; // [esp+28h] [ebp-1150h]
  float v75; // [esp+28h] [ebp-1150h]
  char v76; // [esp+2Fh] [ebp-1149h]
  float v77; // [esp+30h] [ebp-1148h]
  float v78; // [esp+30h] [ebp-1148h]
  int v79; // [esp+34h] [ebp-1144h]
  int v80; // [esp+34h] [ebp-1144h]
  __m128i si128; // [esp+38h] [ebp-1140h] BYREF
  btVector3 v82; // [esp+48h] [ebp-1130h]
  btVector3 v83; // [esp+58h] [ebp-1120h] BYREF
  int v84; // [esp+74h] [ebp-1104h]
  __m128i v85; // [esp+78h] [ebp-1100h] BYREF
  btVector3 v86; // [esp+88h] [ebp-10F0h]
  __m128i v87; // [esp+98h] [ebp-10E0h] BYREF
  __m128i v88; // [esp+A8h] [ebp-10D0h]
  __m128i v89; // [esp+B8h] [ebp-10C0h]
  btDiscreteCollisionDetectorInterface::ClosestPointInput input; // [esp+C8h] [ebp-10B0h] BYREF
  float v91; // [esp+158h] [ebp-1020h]
  bool v92; // [esp+15Ch] [ebp-101Ch]
  btDiscreteCollisionDetectorInterface::Result output[2]; // [esp+168h] [ebp-1010h] BYREF
  unsigned __int64 v94; // [esp+170h] [ebp-1008h]
  btVector3 v95; // [esp+178h] [ebp-1000h]
  btVector3 v96; // [esp+188h] [ebp-FF0h]
  __m128i v97; // [esp+198h] [ebp-FE0h]
  unsigned __int64 v98; // [esp+1A8h] [ebp-FD0h]
  unsigned __int64 v99; // [esp+1B0h] [ebp-FC8h]
  btVector3 v100; // [esp+1B8h] [ebp-FC0h]
  btVector3 v101; // [esp+1C8h] [ebp-FB0h]
  unsigned __int64 v102; // [esp+1D8h] [ebp-FA0h]
  unsigned __int64 v103; // [esp+1E0h] [ebp-F98h]
  __int64 v104; // [esp+1E8h] [ebp-F90h]
  _QWORD v105[124]; // [esp+1F8h] [ebp-F80h] BYREF
  _QWORD v106[124]; // [esp+5D8h] [ebp-BA0h] BYREF
  _QWORD v107[124]; // [esp+9B8h] [ebp-7C0h] BYREF
  _QWORD v108[124]; // [esp+D98h] [ebp-3E0h] BYREF

  m_shapeType = convexA->m_shapeType;
  if ( m_shapeType != 17 && m_shapeType != 18 )
  {
    HIDWORD(v12) = convexB;
LABEL_7:
    v76 = 0;
    goto LABEL_8;
  }
  HIDWORD(v12) = convexB;
  v13 = convexB->m_shapeType;
  if ( v13 != 17 && v13 != 18 )
    goto LABEL_7;
  v76 = 1;
LABEL_8:
  v77 = 9.9999998e17;
  v86.mVec128 = (__m128)0LL;
  v74 = 42;
  v83.mVec128.m128_i32[3] = 0;
  si128.m128i_i32[3] = 0;
  do
  {
    PenetrationDirections = btMinkowskiPenetrationDepthSolver::getPenetrationDirections();
    v82.mVec128 = *(__m128 *)((char *)PenetrationDirections + v16);
    v17 = v82.mVec128.m128_f32[0];
    v18 = v82.mVec128.m128_f32[1];
    v19 = v82.mVec128.m128_f32[2];
    v20 = COERCE_FLOAT(v82.mVec128.m128_i32[2] ^ 0x80000000) * transA->m_basis.m_el[2].mVec128.m128_f32[2];
    v21 = COERCE_FLOAT(v82.mVec128.m128_i32[2] ^ 0x80000000) * transA->m_basis.m_el[2].mVec128.m128_f32[1];
    v83.mVec128.m128_f32[0] = (float)((float)((float)-v82.mVec128.m128_f32[1]
                                            * transA->m_basis.m_el[1].mVec128.m128_f32[0])
                                    + (float)(COERCE_FLOAT(v82.mVec128.m128_i32[2] ^ 0x80000000)
                                            * transA->m_basis.m_el[2].mVec128.m128_f32[0]))
                            + (float)((float)-v82.mVec128.m128_f32[0] * transA->m_basis.m_el[0].mVec128.m128_f32[0]);
    v22 = (float)-v82.mVec128.m128_f32[1] * transA->m_basis.m_el[1].mVec128.m128_f32[1];
    v83.mVec128.m128_f32[2] = (float)((float)((float)-v82.mVec128.m128_f32[1]
                                            * transA->m_basis.m_el[1].mVec128.m128_f32[2])
                                    + v20)
                            + (float)(transA->m_basis.m_el[0].mVec128.m128_f32[2] * (float)-v82.mVec128.m128_f32[0]);
    v83.mVec128.m128_f32[1] = (float)(v22 + v21)
                            + (float)((float)-v82.mVec128.m128_f32[0] * transA->m_basis.m_el[0].mVec128.m128_f32[1]);
    *(_QWORD *)((char *)v106 + v16) = v83.mVec128.m128_u64[0];
    *(_QWORD *)((char *)&v106[1] + v16) = v83.mVec128.m128_u64[1];
    *(float *)si128.m128i_i32 = (float)((float)(v18 * transB->m_basis.m_el[1].mVec128.m128_f32[0])
                                      + (float)(v19 * transB->m_basis.m_el[2].mVec128.m128_f32[0]))
                              + (float)(transB->m_basis.m_el[0].mVec128.m128_f32[0] * v17);
    v23 = v18 * transB->m_basis.m_el[1].mVec128.m128_f32[1];
    v24 = v18 * transB->m_basis.m_el[1].mVec128.m128_f32[2];
    v25 = v19 * transB->m_basis.m_el[2].mVec128.m128_f32[1];
    v26 = v19 * transB->m_basis.m_el[2].mVec128.m128_f32[2];
    *(float *)&si128.m128i_i32[1] = (float)(v23 + v25) + (float)(v17 * transB->m_basis.m_el[0].mVec128.m128_f32[1]);
    *(float *)&v27 = (float)(v24 + v26) + (float)(transB->m_basis.m_el[0].mVec128.m128_f32[2] * v17);
    *(_QWORD *)((char *)v105 + v16) = si128.m128i_i64[0];
    si128.m128i_i32[2] = v27;
    *(_QWORD *)((char *)&v105[1] + v16) = si128.m128i_i64[1];
  }
  while ( v16 + 16 < 672 );
  v28 = COERCE_FLOAT((*(int (__thiscall **)(int))(*(_DWORD *)v15 + 76))(v15));
  *(float *)&v84 = v28;
  if ( SLODWORD(v28) > 0 )
  {
    v29 = 0;
    v83.mVec128.m128_i32[3] = 0;
    v85.m128i_i32[3] = 0;
    v82.mVec128.m128_i32[3] = 0;
    v79 = 0;
    v74 = LODWORD(v28) + 42;
    do
    {
      convexA->getPreferredPenetrationDirection(convexA, v79, (btVector3 *)&si128);
      v30 = transA->m_basis.m_el[1].mVec128.m128_f32[2];
      v83.mVec128.m128_f32[0] = (float)((float)(*(float *)&si128.m128i_i32[1]
                                              * transA->m_basis.m_el[0].mVec128.m128_f32[1])
                                      + (float)(*(float *)&si128.m128i_i32[2]
                                              * transA->m_basis.m_el[0].mVec128.m128_f32[2]))
                              + (float)(*(float *)si128.m128i_i32 * transA->m_basis.m_el[0].mVec128.m128_f32[0]);
      v31 = *(float *)si128.m128i_i32 * transA->m_basis.m_el[2].mVec128.m128_f32[0];
      v83.mVec128.m128_f32[1] = (float)((float)(transA->m_basis.m_el[1].mVec128.m128_f32[1]
                                              * *(float *)&si128.m128i_i32[1])
                                      + (float)(v30 * *(float *)&si128.m128i_i32[2]))
                              + (float)(transA->m_basis.m_el[1].mVec128.m128_f32[0] * *(float *)si128.m128i_i32);
      v83.mVec128.m128_f32[2] = (float)((float)(transA->m_basis.m_el[2].mVec128.m128_f32[1]
                                              * *(float *)&si128.m128i_i32[1])
                                      + (float)(transA->m_basis.m_el[2].mVec128.m128_f32[2]
                                              * *(float *)&si128.m128i_i32[2]))
                              + v31;
      si128 = _mm_load_si128((const __m128i *)&v83);
      btMinkowskiPenetrationDepthSolver::getPenetrationDirections()[v29 / 2 + 42] = (btVector3)v83.mVec128;
      v32 = *(float *)si128.m128i_i32;
      v33 = *(float *)&si128.m128i_i32[1];
      v34 = *(float *)&si128.m128i_i32[2];
      *(float *)v85.m128i_i32 = (float)((float)((float)-*(float *)&si128.m128i_i32[2]
                                              * transA->m_basis.m_el[2].mVec128.m128_f32[0])
                                      + (float)(COERCE_FLOAT(si128.m128i_i32[1] ^ 0x80000000)
                                              * transA->m_basis.m_el[1].mVec128.m128_f32[0]))
                              + (float)((float)-*(float *)si128.m128i_i32 * transA->m_basis.m_el[0].mVec128.m128_f32[0]);
      *(float *)&v35 = (float)((float)((float)-*(float *)&si128.m128i_i32[2]
                                     * transA->m_basis.m_el[2].mVec128.m128_f32[2])
                             + (float)(COERCE_FLOAT(si128.m128i_i32[1] ^ 0x80000000)
                                     * transA->m_basis.m_el[1].mVec128.m128_f32[2]))
                     + (float)(transA->m_basis.m_el[0].mVec128.m128_f32[2] * (float)-*(float *)si128.m128i_i32);
      *(float *)&v85.m128i_i32[1] = (float)((float)((float)-*(float *)&si128.m128i_i32[2]
                                                  * transA->m_basis.m_el[2].mVec128.m128_f32[1])
                                          + (float)(COERCE_FLOAT(si128.m128i_i32[1] ^ 0x80000000)
                                                  * transA->m_basis.m_el[1].mVec128.m128_f32[1]))
                                  + (float)((float)-*(float *)si128.m128i_i32
                                          * transA->m_basis.m_el[0].mVec128.m128_f32[1]);
      v85.m128i_i32[2] = v35;
      v106[v29 + 84] = v85.m128i_i64[0];
      v106[v29 + 85] = v85.m128i_i64[1];
      v82.mVec128.m128_f32[0] = (float)((float)(v33 * transB->m_basis.m_el[1].mVec128.m128_f32[0])
                                      + (float)(v34 * transB->m_basis.m_el[2].mVec128.m128_f32[0]))
                              + (float)(transB->m_basis.m_el[0].mVec128.m128_f32[0] * v32);
      v36 = v33 * transB->m_basis.m_el[1].mVec128.m128_f32[1];
      v37 = v33 * transB->m_basis.m_el[1].mVec128.m128_f32[2];
      v38 = v34 * transB->m_basis.m_el[2].mVec128.m128_f32[1];
      v39 = v34 * transB->m_basis.m_el[2].mVec128.m128_f32[2];
      v82.mVec128.m128_f32[1] = (float)(v36 + v38) + (float)(v32 * transB->m_basis.m_el[0].mVec128.m128_f32[1]);
      v40 = (float)(v37 + v39) + (float)(transB->m_basis.m_el[0].mVec128.m128_f32[2] * v32);
      v105[v29 + 84] = v82.mVec128.m128_u64[0];
      v82.mVec128.m128_f32[2] = v40;
      v105[v29 + 85] = v82.mVec128.m128_u64[1];
      v29 += 2;
      ++v79;
    }
    while ( v79 < v84 );
    HIDWORD(v12) = convexB;
  }
  v41 = COERCE_FLOAT((*(int (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(v12) + 76))(HIDWORD(v12)));
  *(float *)&v84 = v41;
  if ( v41 != 0.0 )
  {
    v80 = 0;
    if ( SLODWORD(v41) > 0 )
    {
      v42 = 2 * v74;
      v74 += LODWORD(v41);
      v83.mVec128.m128_i32[3] = 0;
      v82.mVec128.m128_i32[3] = 0;
      v85.m128i_i32[3] = 0;
      do
      {
        convexB->getPreferredPenetrationDirection(convexB, v80, (btVector3 *)&si128);
        v43 = transB->m_basis.m_el[1].mVec128.m128_f32[2];
        v83.mVec128.m128_f32[0] = (float)((float)(*(float *)&si128.m128i_i32[1]
                                                * transB->m_basis.m_el[0].mVec128.m128_f32[1])
                                        + (float)(*(float *)&si128.m128i_i32[2]
                                                * transB->m_basis.m_el[0].mVec128.m128_f32[2]))
                                + (float)(transB->m_basis.m_el[0].mVec128.m128_f32[0] * *(float *)si128.m128i_i32);
        v83.mVec128.m128_f32[1] = (float)((float)(transB->m_basis.m_el[1].mVec128.m128_f32[1]
                                                * *(float *)&si128.m128i_i32[1])
                                        + (float)(v43 * *(float *)&si128.m128i_i32[2]))
                                + (float)(*(float *)si128.m128i_i32 * transB->m_basis.m_el[1].mVec128.m128_f32[0]);
        v83.mVec128.m128_f32[2] = (float)((float)(transB->m_basis.m_el[2].mVec128.m128_f32[1]
                                                * *(float *)&si128.m128i_i32[1])
                                        + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[2]
                                                * *(float *)&si128.m128i_i32[2]))
                                + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[0] * *(float *)si128.m128i_i32);
        si128 = _mm_load_si128((const __m128i *)&v83);
        btMinkowskiPenetrationDepthSolver::getPenetrationDirections()[v42 / 2] = (btVector3)v83.mVec128;
        v44 = *(float *)si128.m128i_i32;
        v45 = *(float *)&si128.m128i_i32[1];
        v46 = *(float *)&si128.m128i_i32[2];
        v82.mVec128.m128_f32[0] = (float)((float)((float)-*(float *)si128.m128i_i32
                                                * transA->m_basis.m_el[0].mVec128.m128_f32[0])
                                        + (float)(COERCE_FLOAT(si128.m128i_i32[2] ^ 0x80000000)
                                                * transA->m_basis.m_el[2].mVec128.m128_f32[0]))
                                + (float)((float)-*(float *)&si128.m128i_i32[1]
                                        * transA->m_basis.m_el[1].mVec128.m128_f32[0]);
        v47 = (float)((float)(COERCE_FLOAT(si128.m128i_i32[2] ^ 0x80000000) * transA->m_basis.m_el[2].mVec128.m128_f32[2])
                    + (float)((float)-*(float *)&si128.m128i_i32[1] * transA->m_basis.m_el[1].mVec128.m128_f32[2]))
            + (float)(transA->m_basis.m_el[0].mVec128.m128_f32[2] * (float)-*(float *)si128.m128i_i32);
        v82.mVec128.m128_f32[1] = (float)((float)((float)-*(float *)si128.m128i_i32
                                                * transA->m_basis.m_el[0].mVec128.m128_f32[1])
                                        + (float)(COERCE_FLOAT(si128.m128i_i32[2] ^ 0x80000000)
                                                * transA->m_basis.m_el[2].mVec128.m128_f32[1]))
                                + (float)((float)-*(float *)&si128.m128i_i32[1]
                                        * transA->m_basis.m_el[1].mVec128.m128_f32[1]);
        v82.mVec128.m128_f32[2] = v47;
        v106[v42] = v82.mVec128.m128_u64[0];
        v106[v42 + 1] = v82.mVec128.m128_u64[1];
        *(float *)v85.m128i_i32 = (float)((float)(v45 * transB->m_basis.m_el[1].mVec128.m128_f32[0])
                                        + (float)(v46 * transB->m_basis.m_el[2].mVec128.m128_f32[0]))
                                + (float)(transB->m_basis.m_el[0].mVec128.m128_f32[0] * v44);
        v48 = v45 * transB->m_basis.m_el[1].mVec128.m128_f32[1];
        v49 = v45 * transB->m_basis.m_el[1].mVec128.m128_f32[2];
        v50 = (float)(v44 * transB->m_basis.m_el[0].mVec128.m128_f32[1]) + v48;
        v51 = v46 * transB->m_basis.m_el[2].mVec128.m128_f32[1];
        v52 = v46 * transB->m_basis.m_el[2].mVec128.m128_f32[2];
        *(float *)&v85.m128i_i32[1] = v50 + v51;
        *(float *)&v53 = (float)(v49 + v52) + (float)(transB->m_basis.m_el[0].mVec128.m128_f32[2] * v44);
        v105[v42] = v85.m128i_i64[0];
        v85.m128i_i32[2] = v53;
        v105[v42 + 1] = v85.m128i_i64[1];
        v42 += 2;
        ++v80;
      }
      while ( v80 < v84 );
      HIDWORD(v12) = convexB;
    }
  }
  convexA->batchedUnitVectorGetSupportingVertexWithoutMargin(convexA, (const btVector3 *)v106, (btVector3 *)v107, v74);
  (*(void (__thiscall **)(_DWORD, _QWORD *, _QWORD *, int))(*(_DWORD *)HIDWORD(v12) + 68))(
    HIDWORD(v12),
    v105,
    v108,
    v74);
  if ( v74 > 0 )
  {
    do
    {
      v54 = btMinkowskiPenetrationDepthSolver::getPenetrationDirections();
      si128 = *(__m128i *)((char *)v54 + v56);
      if ( v76 )
      {
        v57 = 0.0;
        si128.m128i_i32[2] = 0;
      }
      else
      {
        v57 = *(float *)&si128.m128i_i32[2];
      }
      if ( (float)((float)((float)(*(float *)&si128.m128i_i32[1] * *(float *)&si128.m128i_i32[1]) + (float)(v57 * v57))
                 + (float)(*(float *)si128.m128i_i32 * *(float *)si128.m128i_i32)) > 0.01 )
      {
        v82.mVec128.m128_u64[0] = *(_QWORD *)((char *)v107 + v56);
        v82.mVec128.m128_u64[1] = *(_QWORD *)((char *)&v107[1] + v56);
        v83.mVec128.m128_u64[0] = *(_QWORD *)((char *)v108 + v56);
        v83.mVec128.m128_u64[1] = *(_QWORD *)((char *)&v108[1] + v56);
        v58 = transA->m_basis.m_el[1].mVec128.m128_f32[2];
        *(float *)v85.m128i_i32 = (float)((float)((float)(v82.mVec128.m128_f32[0]
                                                        * transA->m_basis.m_el[0].mVec128.m128_f32[0])
                                                + (float)(v82.mVec128.m128_f32[1]
                                                        * transA->m_basis.m_el[0].mVec128.m128_f32[1]))
                                        + (float)(v82.mVec128.m128_f32[2] * transA->m_basis.m_el[0].mVec128.m128_f32[2]))
                                + transA->m_origin.mVec128.m128_f32[0];
        *(float *)&v85.m128i_i32[1] = (float)((float)((float)(transA->m_basis.m_el[1].mVec128.m128_f32[1]
                                                            * v82.mVec128.m128_f32[1])
                                                    + (float)(v58 * v82.mVec128.m128_f32[2]))
                                            + (float)(transA->m_basis.m_el[1].mVec128.m128_f32[0]
                                                    * v82.mVec128.m128_f32[0]))
                                    + transA->m_origin.mVec128.m128_f32[1];
        *(float *)&v85.m128i_i32[2] = (float)((float)((float)(transA->m_basis.m_el[2].mVec128.m128_f32[1]
                                                            * v82.mVec128.m128_f32[1])
                                                    + (float)(transA->m_basis.m_el[2].mVec128.m128_f32[2]
                                                            * v82.mVec128.m128_f32[2]))
                                            + (float)(transA->m_basis.m_el[2].mVec128.m128_f32[0]
                                                    * v82.mVec128.m128_f32[0]))
                                    + transA->m_origin.mVec128.m128_f32[2];
        v59 = transB->m_basis.m_el[0].mVec128.m128_f32[0];
        v85.m128i_i32[3] = 0;
        v88 = _mm_load_si128(&v85);
        v60 = transB->m_basis.m_el[1].mVec128.m128_f32[2];
        *(float *)v87.m128i_i32 = (float)((float)((float)(v59 * v83.mVec128.m128_f32[0])
                                                + (float)(v83.mVec128.m128_f32[1]
                                                        * transB->m_basis.m_el[0].mVec128.m128_f32[1]))
                                        + (float)(v83.mVec128.m128_f32[2] * transB->m_basis.m_el[0].mVec128.m128_f32[2]))
                                + transB->m_origin.mVec128.m128_f32[0];
        v61 = v83.mVec128.m128_f32[0] * transB->m_basis.m_el[2].mVec128.m128_f32[0];
        *(float *)&v87.m128i_i32[1] = (float)((float)((float)(transB->m_basis.m_el[1].mVec128.m128_f32[1]
                                                            * v83.mVec128.m128_f32[1])
                                                    + (float)(v60 * v83.mVec128.m128_f32[2]))
                                            + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[0]
                                                    * v83.mVec128.m128_f32[0]))
                                    + transB->m_origin.mVec128.m128_f32[1];
        *(float *)&v87.m128i_i32[2] = (float)((float)((float)(transB->m_basis.m_el[2].mVec128.m128_f32[1]
                                                            * v83.mVec128.m128_f32[1])
                                                    + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[2]
                                                            * v83.mVec128.m128_f32[2]))
                                            + v61)
                                    + transB->m_origin.mVec128.m128_f32[2];
        v87.m128i_i32[3] = 0;
        v89 = _mm_load_si128(&v87);
        if ( v76 )
        {
          v62 = 0.0;
          v63 = 0.0;
        }
        else
        {
          v62 = *(float *)&v88.m128i_i32[2];
          v63 = *(float *)&v89.m128i_i32[2];
        }
        v64 = (float)(v63 - v62) * v57;
        if ( v77 > (float)((float)((float)((float)(*(float *)&v89.m128i_i32[1] - *(float *)&v88.m128i_i32[1])
                                         * *(float *)&si128.m128i_i32[1])
                                 + v64)
                         + (float)((float)(*(float *)v89.m128i_i32 - *(float *)v88.m128i_i32) * *(float *)si128.m128i_i32)) )
        {
          v77 = (float)((float)((float)(*(float *)&v89.m128i_i32[1] - *(float *)&v88.m128i_i32[1])
                              * *(float *)&si128.m128i_i32[1])
                      + v64)
              + (float)((float)(*(float *)v89.m128i_i32 - *(float *)v88.m128i_i32) * *(float *)si128.m128i_i32);
          v86.mVec128 = (__m128)si128;
        }
      }
    }
    while ( v55 != 1 );
  }
  LODWORD(v12) = convexA;
  switch ( convexA->m_shapeType )
  {
    case 0:
    case 1:
    case 4:
    case 5:
    case 8:
    case 0xA:
    case 0xD:
      break;
    default:
      ((void (*)(void))convexA->getMargin)();
      LODWORD(v12) = convexA;
      break;
  }
  switch ( *(_DWORD *)(HIDWORD(v12) + 4) )
  {
    case 0:
    case 1:
    case 4:
    case 5:
    case 8:
    case 0xA:
    case 0xD:
      break;
    default:
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(v12) + 40))(HIDWORD(v12));
      LODWORD(v12) = convexA;
      break;
  }
  if ( v77 < 0.0 )
    return 0;
  switch ( *(_DWORD *)(v12 + 4) )
  {
    case 0:
    case 1:
    case 4:
    case 5:
    case 0xA:
    case 0xD:
      v66 = *(float *)(v12 + 48);
      v75 = v66;
      break;
    case 8:
      v66 = *(float *)(v12 + 32) * *(float *)(v12 + 16);
      v75 = v66;
      break;
    default:
      v75 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)v12 + 40))(v12);
      v66 = v75;
      LODWORD(v12) = convexA;
      break;
  }
  switch ( *(_DWORD *)(HIDWORD(v12) + 4) )
  {
    case 0:
    case 1:
    case 4:
    case 5:
    case 0xA:
    case 0xD:
      v67 = *(float *)(HIDWORD(v12) + 48);
      break;
    case 8:
      v67 = *(float *)(HIDWORD(v12) + 32) * *(float *)(HIDWORD(v12) + 16);
      break;
    default:
      *(float *)&v84 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)HIDWORD(v12) + 40))(HIDWORD(v12));
      v67 = *(float *)&v84;
      v66 = v75;
      LODWORD(v12) = convexA;
      break;
  }
  v68 = *(_DWORD *)(v12 + 4);
  input.m_transformA.m_basis.m_el[2].mVec128.m128_i32[1] = (int)simplexSolver;
  input.m_transformA.m_origin.mVec128.m128_u64[0] = __PAIR64__(*(_DWORD *)(HIDWORD(v12) + 4), v68);
  v78 = (float)((float)(v67 + v66) + v77) + 0.5;
  v69 = *(double (**)(void))(*(_DWORD *)v12 + 40);
  input.m_transformA.m_basis.m_el[0].mVec128.m128_i32[0] = (int)&btGjkPairDetector::`vftable';
  input.m_transformA.m_basis.m_el[1].mVec128.m128_i32[0] = 0;
  *(unsigned __int64 *)((char *)input.m_transformA.m_basis.m_el[1].mVec128.m128_u64 + 4) = (unsigned int)clear_value;
  input.m_transformA.m_basis.m_el[1].mVec128.m128_i32[3] = 0;
  input.m_transformA.m_basis.m_el[2].mVec128.m128_i32[0] = 0;
  input.m_transformA.m_basis.m_el[2].mVec128.m128_u64[1] = v12;
  input.m_transformA.m_origin.mVec128.m128_f32[2] = v69();
  input.m_transformA.m_origin.mVec128.m128_f32[3] = ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)HIDWORD(v12)
                                                                                              + 40))(HIDWORD(v12));
  v70 = transA->m_origin.mVec128.m128_f32[0] + (float)(v86.mVec128.m128_f32[0] * v78);
  *(float *)&v87.m128i_i32[1] = transA->m_origin.mVec128.m128_f32[1] + (float)(v86.mVec128.m128_f32[1] * v78);
  *(float *)&v87.m128i_i32[2] = transA->m_origin.mVec128.m128_f32[2] + (float)(v86.mVec128.m128_f32[2] * v78);
  *(_QWORD *)&output[0].__vftable = transA->m_basis.m_el[0].mVec128.m128_u64[0];
  v94 = transA->m_basis.m_el[0].mVec128.m128_u64[1];
  v95.mVec128 = (__m128)transA->m_basis.m_el[1];
  v96.mVec128 = (__m128)transA->m_basis.m_el[2];
  *(float *)v87.m128i_i32 = v70;
  v87.m128i_i32[3] = 0;
  v97 = _mm_load_si128(&v87);
  v98 = transB->m_basis.m_el[0].mVec128.m128_u64[0];
  v99 = transB->m_basis.m_el[0].mVec128.m128_u64[1];
  v100.mVec128 = (__m128)transB->m_basis.m_el[1];
  v101.mVec128 = (__m128)transB->m_basis.m_el[2];
  v71 = transB->m_origin.mVec128.m128_u64[0];
  input.m_transformB.m_basis.m_el[0].mVec128.m128_i8[0] = 0;
  input.m_transformB.m_basis.m_el[0].mVec128.m128_i32[2] = -1;
  input.m_transformB.m_basis.m_el[1].mVec128.m128_i32[1] = 1;
  v102 = v71;
  v103 = transB->m_origin.mVec128.m128_u64[1];
  v104 = 1566444395;
  *(float *)v87.m128i_i32 = -v86.mVec128.m128_f32[0];
  *(float *)&v87.m128i_i32[1] = -v86.mVec128.m128_f32[1];
  *(float *)&v87.m128i_i32[2] = -v86.mVec128.m128_f32[2];
  v87.m128i_i32[3] = 0;
  v72 = _mm_load_si128(&v87);
  input.m_transformB.m_basis.m_el[2].mVec128.m128_i32[0] = (int)&`btMinkowskiPenetrationDepthSolver::calcPenDepth'::`2'::btIntermediateResult::`vftable';
  v92 = 0;
  input.m_transformA.m_basis.m_el[1] = (btVector3)v72;
  btGjkPairDetector::getClosestPointsNonVirtual(
    (btGjkPairDetector *)&input,
    &input,
    output,
    (btIDebugDraw *)&input.m_transformB.m_basis.m_el[2]);
  result = v92;
  v73 = v78 - v91;
  if ( v92 )
  {
    v82.mVec128.m128_f32[0] = input.m_maximumDistanceSquared - (float)(v86.mVec128.m128_f32[0] * v73);
    v82.mVec128.m128_f32[1] = *(float *)&input.m_stackAlloc - (float)(v86.mVec128.m128_f32[1] * v73);
    v82.mVec128.m128_f32[2] = *((float *)&input.m_stackAlloc + 1) - (float)(v86.mVec128.m128_f32[2] * v73);
    v82.mVec128.m128_i32[3] = 0;
    *pa = (btVector3)v82.mVec128;
    *pb = *(btVector3 *)&input.m_maximumDistanceSquared;
    *v = (btVector3)v86.mVec128;
  }
  return result;
}
