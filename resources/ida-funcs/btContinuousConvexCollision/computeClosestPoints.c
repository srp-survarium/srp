void __userpurge btContinuousConvexCollision::computeClosestPoints(
        btContinuousConvexCollision *this@<ecx>,
        int a2@<eax>,
        const btTransform *transA,
        const btTransform *transB,
        btIDebugDraw *pointCollector)
{
  _DWORD *v6; // edi
  double v7; // st7
  int v8; // eax
  btGjkPairDetector *v9; // ecx
  btTransform *v10; // eax
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm5_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm6_4
  float v21; // xmm3_4
  float v22; // xmm5_4
  float v23; // xmm5_4
  float v24; // xmm6_4
  float v25; // xmm5_4
  float v26; // xmm6_4
  float v27; // xmm5_4
  float v28; // xmm6_4
  float v29; // xmm5_4
  float v30; // xmm6_4
  btTransform *v31; // ecx
  btTransform *v32; // eax
  float v33; // xmm3_4
  float v34; // xmm4_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm0_4
  float v38; // xmm6_4
  float v39; // xmm7_4
  float v40; // xmm1_4
  float v41; // xmm6_4
  float v42; // xmm5_4
  float v43; // xmm2_4
  float v44; // xmm1_4
  float v45; // xmm6_4
  float v46; // xmm2_4
  float v47; // xmm7_4
  float v48; // xmm6_4
  float v49; // xmm5_4
  float v50; // xmm7_4
  float v51; // xmm6_4
  float v52; // xmm5_4
  float v53; // xmm6_4
  float v54; // xmm7_4
  float v55; // xmm6_4
  float *v56; // esi
  int v57; // eax
  float v58; // xmm0_4
  float v59; // xmm1_4
  float v60; // xmm2_4
  float v61; // xmm0_4
  float v62; // xmm6_4
  float v63; // xmm1_4
  float v64; // xmm2_4
  float v65; // xmm7_4
  float v66; // xmm3_4
  float v67; // xmm4_4
  float v68; // xmm5_4
  float v69; // xmm1_4
  float v70; // xmm6_4
  float v71; // xmm0_4
  float v72; // xmm4_4
  float v73; // xmm3_4
  float v74; // xmm2_4
  float v75; // xmm1_4
  float v76; // xmm2_4
  float v77; // xmm6_4
  btIDebugDraw_vtbl *v78; // eax
  float v79; // xmm4_4
  float v80; // xmm0_4
  float v81; // xmm5_4
  float v82; // xmm1_4
  float v83; // xmm2_4
  float v84; // xmm6_4
  const float *v85; // [esp+Ch] [ebp-200h]
  const float *v86; // [esp+Ch] [ebp-200h]
  btMatrix3x3 v87; // [esp+18h] [ebp-1F4h] BYREF
  float v88; // [esp+48h] [ebp-1C4h]
  btTransform v89; // [esp+4Ch] [ebp-1C0h] BYREF
  float v90; // [esp+98h] [ebp-174h] BYREF
  float v91; // [esp+9Ch] [ebp-170h]
  float v92; // [esp+A0h] [ebp-16Ch]
  float v93; // [esp+A4h] [ebp-168h]
  float v94[4]; // [esp+ACh] [ebp-160h] BYREF
  _DWORD v95[4]; // [esp+BCh] [ebp-150h] BYREF
  float v96[4]; // [esp+CCh] [ebp-140h] BYREF
  float v97; // [esp+DCh] [ebp-130h] BYREF
  float v98; // [esp+E0h] [ebp-12Ch]
  float v99; // [esp+E4h] [ebp-128h]
  float v100[12]; // [esp+ECh] [ebp-120h] BYREF
  btDiscreteCollisionDetectorInterface::ClosestPointInput input; // [esp+11Ch] [ebp-F0h] BYREF
  btVector3 v102; // [esp+1ACh] [ebp-60h]
  unsigned __int64 v103; // [esp+1BCh] [ebp-50h]
  unsigned __int64 v104; // [esp+1C4h] [ebp-48h]
  btVector3 v105; // [esp+1CCh] [ebp-40h]
  btVector3 v106; // [esp+1DCh] [ebp-30h]
  btVector3 v107; // [esp+1ECh] [ebp-20h]
  float v108; // [esp+1FCh] [ebp-10h]
  int v109; // [esp+200h] [ebp-Ch]

  if ( *(_DWORD *)(a2 + 16) )
  {
    btVoronoiSimplexSolver::reset((btVoronoiSimplexSolver *)this, *(_DWORD *)(a2 + 4));
    v6 = *(_DWORD **)(a2 + 12);
    v87.m_el[0].mVec128.m128_i32[2] = *(_DWORD *)(a2 + 16);
    v87.m_el[0].mVec128.m128_i32[1] = *(_DWORD *)(v87.m_el[0].mVec128.m128_i32[2] + 4);
    v87.m_el[0].mVec128.m128_i32[3] = v6[1];
    v87.m_el[0].mVec128.m128_f32[0] = ((double (__thiscall *)(_DWORD *))*(_DWORD *)(*v6 + 40))(v6);
    v7 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(**(_DWORD **)(a2 + 16) + 40))(*(_DWORD *)(a2 + 16));
    v8 = *(_DWORD *)(a2 + 8);
    input.m_transformA.m_origin.mVec128.m128_f32[2] = v87.m_el[0].mVec128.m128_f32[0];
    input.m_transformB.m_basis.m_el[0].mVec128.m128_i32[2] = -1;
    input.m_transformA.m_origin.mVec128.m128_f32[3] = v7;
    v109 = 0;
    input.m_transformA.m_basis.m_el[2].mVec128.m128_u64[1] = __PAIR64__(
                                                               v87.m_el[0].mVec128.m128_u32[2],
                                                               (unsigned int)v6);
    input.m_transformA.m_basis.m_el[2].mVec128.m128_i32[0] = v8;
    input.m_transformA.m_basis.m_el[2].mVec128.m128_i32[1] = *(_DWORD *)(a2 + 4);
    input.m_transformA.m_origin.mVec128.m128_u64[0] = __PAIR64__(
                                                        v87.m_el[0].mVec128.m128_u32[1],
                                                        v87.m_el[0].mVec128.m128_u32[3]);
    input.m_transformA.m_basis.m_el[1].mVec128.m128_i32[0] = 0;
    input.m_transformA.m_basis.m_el[1].mVec128.m128_u64[1] = 0;
    v108 = FLOAT_9_9999998e17;
    input.m_transformB.m_basis.m_el[2] = transA->m_basis.m_el[0];
    input.m_transformB.m_origin = transA->m_basis.m_el[1];
    *(btVector3 *)&input.m_maximumDistanceSquared = transA->m_basis.m_el[2];
    v102.mVec128 = (__m128)transA->m_origin;
    v103 = transB->m_basis.m_el[0].mVec128.m128_u64[0];
    v104 = transB->m_basis.m_el[0].mVec128.m128_u64[1];
    v105.mVec128 = (__m128)transB->m_basis.m_el[1];
    input.m_transformA.m_basis.m_el[0].mVec128.m128_i32[0] = (int)&btGjkPairDetector::`vftable';
    input.m_transformA.m_basis.m_el[1].mVec128.m128_f32[1] = s_bm_current_air_resistance;
    input.m_transformB.m_basis.m_el[0].mVec128.m128_i8[0] = 0;
    input.m_transformB.m_basis.m_el[1].mVec128.m128_i32[1] = 1;
    v106.mVec128 = (__m128)transB->m_basis.m_el[2];
    v107.mVec128 = (__m128)transB->m_origin;
    btGjkPairDetector::getClosestPointsNonVirtual(
      v9,
      &input,
      (btDiscreteCollisionDetectorInterface::Result *)&input.m_transformB.m_basis.m_el[2],
      pointCollector,
      0);
  }
  else
  {
    v87.m_el[2].mVec128.m128_i32[3] = *(_DWORD *)(a2 + 12);
    v88 = *(float *)(a2 + 20);
    v89 = *transA;
    v10 = btTransform::inverse((btTransform *)this, (int)transB, &input.m_transformA);
    v11 = v10->m_basis.m_el[0].mVec128.m128_f32[1];
    v12 = v10->m_basis.m_el[0].mVec128.m128_f32[0];
    v87.m_el[0].mVec128.m128_i32[0] = v10->m_basis.m_el[0].mVec128.m128_i32[2];
    v87.m_el[1].mVec128.m128_f32[0] = v11;
    v13 = v10->m_basis.m_el[2].mVec128.m128_f32[2];
    v14 = v10->m_basis.m_el[1].mVec128.m128_f32[2] * v89.m_origin.mVec128.m128_f32[2];
    v91 = (float)((float)((float)(v12 * v89.m_origin.mVec128.m128_f32[0])
                        + (float)(v11 * v89.m_origin.mVec128.m128_f32[1]))
                + (float)(v87.m_el[0].mVec128.m128_f32[0] * v89.m_origin.mVec128.m128_f32[2]))
        + v10->m_origin.mVec128.m128_f32[0];
    v15 = (float)((float)((float)(v10->m_basis.m_el[1].mVec128.m128_f32[1] * v89.m_origin.mVec128.m128_f32[1]) + v14)
                + (float)(v10->m_basis.m_el[1].mVec128.m128_f32[0] * v89.m_origin.mVec128.m128_f32[0]))
        + v10->m_origin.mVec128.m128_f32[1];
    v16 = v10->m_basis.m_el[2].mVec128.m128_f32[2] * v89.m_origin.mVec128.m128_f32[2];
    v92 = v15;
    v17 = (float)((float)((float)(v10->m_basis.m_el[2].mVec128.m128_f32[1] * v89.m_origin.mVec128.m128_f32[1]) + v16)
                + (float)(v10->m_basis.m_el[2].mVec128.m128_f32[0] * v89.m_origin.mVec128.m128_f32[0]))
        + v10->m_origin.mVec128.m128_f32[2];
    v18 = v10->m_basis.m_el[2].mVec128.m128_f32[1];
    v93 = v17;
    v19 = v10->m_basis.m_el[2].mVec128.m128_f32[1];
    v87.m_el[0].mVec128.m128_f32[2] = (float)((float)(v18 * v89.m_basis.m_el[1].mVec128.m128_f32[2])
                                            + (float)(v13 * v89.m_basis.m_el[2].mVec128.m128_f32[2]))
                                    + (float)(v10->m_basis.m_el[2].mVec128.m128_f32[0]
                                            * v89.m_basis.m_el[0].mVec128.m128_f32[2]);
    v20 = v10->m_basis.m_el[2].mVec128.m128_f32[2] * v89.m_basis.m_el[2].mVec128.m128_f32[0];
    v21 = (float)((float)(v19 * v89.m_basis.m_el[1].mVec128.m128_f32[1])
                + (float)(v13 * v89.m_basis.m_el[2].mVec128.m128_f32[1]))
        + (float)(v89.m_basis.m_el[0].mVec128.m128_f32[1] * v10->m_basis.m_el[2].mVec128.m128_f32[0]);
    v22 = v10->m_basis.m_el[2].mVec128.m128_f32[1];
    v87.m_el[0].mVec128.m128_f32[3] = v21;
    v23 = (float)((float)(v22 * v89.m_basis.m_el[1].mVec128.m128_f32[0]) + v20)
        + (float)(v89.m_basis.m_el[0].mVec128.m128_f32[0] * v10->m_basis.m_el[2].mVec128.m128_f32[0]);
    v24 = v10->m_basis.m_el[1].mVec128.m128_f32[2];
    v87.m_el[0].mVec128.m128_f32[1] = v23;
    v25 = (float)((float)(v10->m_basis.m_el[1].mVec128.m128_f32[1] * v89.m_basis.m_el[1].mVec128.m128_f32[2])
                + (float)(v24 * v89.m_basis.m_el[2].mVec128.m128_f32[2]))
        + (float)(v89.m_basis.m_el[0].mVec128.m128_f32[2] * v10->m_basis.m_el[1].mVec128.m128_f32[0]);
    v26 = v10->m_basis.m_el[1].mVec128.m128_f32[2] * v89.m_basis.m_el[2].mVec128.m128_f32[1];
    v87.m_el[1].mVec128.m128_f32[3] = v25;
    v27 = (float)((float)(v10->m_basis.m_el[1].mVec128.m128_f32[1] * v89.m_basis.m_el[1].mVec128.m128_f32[1]) + v26)
        + (float)(v89.m_basis.m_el[0].mVec128.m128_f32[1] * v10->m_basis.m_el[1].mVec128.m128_f32[0]);
    v28 = v10->m_basis.m_el[1].mVec128.m128_f32[2] * v89.m_basis.m_el[2].mVec128.m128_f32[0];
    v87.m_el[2].mVec128.m128_f32[2] = v27;
    v29 = (float)(v10->m_basis.m_el[1].mVec128.m128_f32[1] * v89.m_basis.m_el[1].mVec128.m128_f32[0]) + v28;
    v30 = v10->m_basis.m_el[1].mVec128.m128_f32[0] * v89.m_basis.m_el[0].mVec128.m128_f32[0];
    v87.m_el[2].mVec128.m128_f32[1] = (float)((float)(v89.m_basis.m_el[1].mVec128.m128_f32[2]
                                                    * v87.m_el[1].mVec128.m128_f32[0])
                                            + (float)(v89.m_basis.m_el[2].mVec128.m128_f32[2]
                                                    * v87.m_el[0].mVec128.m128_f32[0]))
                                    + (float)(v89.m_basis.m_el[0].mVec128.m128_f32[2] * v12);
    v87.m_el[2].mVec128.m128_f32[0] = v29 + v30;
    v87.m_el[1].mVec128.m128_f32[1] = (float)((float)(v89.m_basis.m_el[1].mVec128.m128_f32[1]
                                                    * v87.m_el[1].mVec128.m128_f32[0])
                                            + (float)(v89.m_basis.m_el[2].mVec128.m128_f32[1]
                                                    * v87.m_el[0].mVec128.m128_f32[0]))
                                    + (float)(v89.m_basis.m_el[0].mVec128.m128_f32[1] * v12);
    v87.m_el[0].mVec128.m128_f32[0] = (float)((float)(v89.m_basis.m_el[1].mVec128.m128_f32[0]
                                                    * v87.m_el[1].mVec128.m128_f32[0])
                                            + (float)(v89.m_basis.m_el[2].mVec128.m128_f32[0]
                                                    * v87.m_el[0].mVec128.m128_f32[0]))
                                    + (float)(v12 * v89.m_basis.m_el[0].mVec128.m128_f32[0]);
    btMatrix3x3::setValue(
      &v87,
      (int)v100,
      &v87.m_el[1].mVec128.m128_f32[1],
      &v87.m_el[2].mVec128.m128_f32[1],
      v87.m_el[2].mVec128.m128_f32,
      &v87.m_el[2].mVec128.m128_f32[2],
      &v87.m_el[1].mVec128.m128_f32[3],
      &v87.m_el[0].mVec128.m128_f32[1],
      &v87.m_el[0].mVec128.m128_f32[3],
      &v87.m_el[0].mVec128.m128_f32[2],
      v85);
    v32 = btTransform::inverse(v31, (int)&v89, &input.m_transformA);
    v33 = transB->m_basis.m_el[2].mVec128.m128_f32[2];
    v34 = transB->m_basis.m_el[1].mVec128.m128_f32[2];
    v35 = v32->m_basis.m_el[2].mVec128.m128_f32[1];
    v36 = v32->m_basis.m_el[2].mVec128.m128_f32[2];
    v37 = transB->m_basis.m_el[0].mVec128.m128_f32[2];
    v38 = v35 * transB->m_basis.m_el[1].mVec128.m128_f32[1];
    v39 = v35;
    v87.m_el[1].mVec128.m128_i32[0] = transB->m_basis.m_el[1].mVec128.m128_i32[1];
    v40 = (float)((float)(v35 * v34) + (float)(v36 * v33)) + (float)(v32->m_basis.m_el[2].mVec128.m128_f32[0] * v37);
    v41 = v38 + (float)(v32->m_basis.m_el[2].mVec128.m128_f32[2] * transB->m_basis.m_el[2].mVec128.m128_f32[1]);
    v42 = transB->m_basis.m_el[2].mVec128.m128_f32[0];
    v87.m_el[0].mVec128.m128_i32[1] = transB->m_basis.m_el[2].mVec128.m128_i32[1];
    v43 = v32->m_basis.m_el[2].mVec128.m128_f32[0];
    v87.m_el[1].mVec128.m128_f32[1] = v42;
    v87.m_el[2].mVec128.m128_f32[1] = v40;
    v44 = transB->m_basis.m_el[0].mVec128.m128_f32[1];
    v45 = v41 + (float)(v43 * v44);
    v46 = transB->m_basis.m_el[0].mVec128.m128_f32[0];
    v87.m_el[2].mVec128.m128_f32[0] = v45;
    v87.m_el[0].mVec128.m128_i32[2] = transB->m_basis.m_el[1].mVec128.m128_i32[0];
    v47 = (float)((float)(v39 * v87.m_el[0].mVec128.m128_f32[2])
                + (float)(v32->m_basis.m_el[2].mVec128.m128_f32[2] * v42))
        + (float)(v46 * v32->m_basis.m_el[2].mVec128.m128_f32[0]);
    v48 = v32->m_basis.m_el[1].mVec128.m128_f32[2] * v87.m_el[0].mVec128.m128_f32[1];
    v87.m_el[1].mVec128.m128_f32[3] = (float)((float)(v32->m_basis.m_el[1].mVec128.m128_f32[1] * v34)
                                            + (float)(v32->m_basis.m_el[1].mVec128.m128_f32[2] * v33))
                                    + (float)(v37 * v32->m_basis.m_el[1].mVec128.m128_f32[0]);
    v49 = (float)(v32->m_basis.m_el[1].mVec128.m128_f32[1] * v87.m_el[1].mVec128.m128_f32[0]) + v48;
    v87.m_el[2].mVec128.m128_f32[2] = v47;
    v50 = v32->m_basis.m_el[1].mVec128.m128_f32[2];
    v51 = v32->m_basis.m_el[1].mVec128.m128_f32[1] * v87.m_el[0].mVec128.m128_f32[2];
    v90 = v49 + (float)(v44 * v32->m_basis.m_el[1].mVec128.m128_f32[0]);
    v52 = v87.m_el[1].mVec128.m128_f32[1];
    v53 = (float)(v51 + (float)(v50 * v87.m_el[1].mVec128.m128_f32[1]))
        + (float)(v46 * v32->m_basis.m_el[1].mVec128.m128_f32[0]);
    v87.m_el[0].mVec128.m128_i32[0] = v32->m_basis.m_el[0].mVec128.m128_i32[1];
    v54 = v32->m_basis.m_el[0].mVec128.m128_f32[0];
    v87.m_el[1].mVec128.m128_f32[1] = v53;
    v55 = v32->m_basis.m_el[0].mVec128.m128_f32[2];
    v87.m_el[0].mVec128.m128_f32[3] = v54;
    v87.m_el[1].mVec128.m128_f32[2] = (float)((float)(v37 * v54) + (float)(v34 * v87.m_el[0].mVec128.m128_f32[0]))
                                    + (float)(v33 * v55);
    v87.m_el[0].mVec128.m128_f32[1] = (float)((float)(v44 * v54)
                                            + (float)(v87.m_el[1].mVec128.m128_f32[0] * v87.m_el[0].mVec128.m128_f32[0]))
                                    + (float)(v87.m_el[0].mVec128.m128_f32[1] * v55);
    v87.m_el[0].mVec128.m128_f32[2] = (float)((float)(v46 * v54)
                                            + (float)(v87.m_el[0].mVec128.m128_f32[2] * v87.m_el[0].mVec128.m128_f32[0]))
                                    + (float)(v52 * v55);
    btMatrix3x3::setValue(
      (btMatrix3x3 *)&v87.m_el[0].m_floats[2],
      (int)&v89,
      &v87.m_el[0].mVec128.m128_f32[1],
      &v87.m_el[1].mVec128.m128_f32[2],
      &v87.m_el[1].mVec128.m128_f32[1],
      &v90,
      &v87.m_el[1].mVec128.m128_f32[3],
      &v87.m_el[2].mVec128.m128_f32[2],
      v87.m_el[2].mVec128.m128_f32,
      &v87.m_el[2].mVec128.m128_f32[1],
      v86);
    v56 = (float *)LODWORD(v88);
    v57 = *(_DWORD *)v87.m_el[2].mVec128.m128_i32[3];
    LODWORD(v58) = *(_DWORD *)(LODWORD(v88) + 56) ^ _mask__NegFloat_;
    LODWORD(v59) = *(_DWORD *)(LODWORD(v88) + 48) ^ _mask__NegFloat_;
    LODWORD(v60) = *(_DWORD *)(LODWORD(v88) + 52) ^ _mask__NegFloat_;
    v94[0] = (float)((float)(v60 * v89.m_basis.m_el[0].mVec128.m128_f32[1])
                   + (float)(v58 * v89.m_basis.m_el[0].mVec128.m128_f32[2]))
           + (float)(v59 * v89.m_basis.m_el[0].mVec128.m128_f32[0]);
    v94[2] = (float)((float)(v58 * v89.m_basis.m_el[2].mVec128.m128_f32[2])
                   + (float)(v59 * v89.m_basis.m_el[2].mVec128.m128_f32[0]))
           + (float)(v60 * v89.m_basis.m_el[2].mVec128.m128_f32[1]);
    v94[1] = (float)((float)(v60 * v89.m_basis.m_el[1].mVec128.m128_f32[1])
                   + (float)(v58 * v89.m_basis.m_el[1].mVec128.m128_f32[2]))
           + (float)(v59 * v89.m_basis.m_el[1].mVec128.m128_f32[0]);
    v94[3] = 0.0;
    (*(void (__stdcall **)(float *, float *))(v57 + 56))(&v97, v94);
    v61 = (float)((float)((float)(v97 * v100[0]) + (float)(v99 * v100[2])) + (float)(v98 * v100[1])) + v91;
    v62 = (float)((float)((float)(v97 * v100[8]) + (float)(v99 * v100[10])) + (float)(v98 * v100[9])) + v93;
    v63 = (float)((float)((float)(v97 * v100[4]) + (float)(v99 * v100[6])) + (float)(v98 * v100[5])) + v92;
    v64 = (float)((float)((float)(v56[12] * v61) + (float)(v56[13] * v63)) + (float)(v56[14] * v62)) - v56[16];
    v65 = transB->m_basis.m_el[0].mVec128.m128_f32[2];
    v66 = v56[14] * v64;
    v67 = v56[13] * v64;
    v68 = v56[12] * v64;
    v87.m_el[1].mVec128.m128_f32[2] = v64;
    v87.m_el[2].mVec128.m128_i32[3] = transB->m_basis.m_el[0].mVec128.m128_i32[1];
    v69 = v63 - v67;
    v70 = v62 - v66;
    v71 = v61 - v68;
    v88 = transB->m_basis.m_el[0].mVec128.m128_f32[0];
    v72 = (float)((float)((float)(v69 * v87.m_el[2].mVec128.m128_f32[3]) + (float)(v70 * v65)) + (float)(v71 * v88))
        + transB->m_origin.mVec128.m128_f32[0];
    v73 = transB->m_basis.m_el[2].mVec128.m128_f32[1];
    *(float *)&v95[1] = (float)((float)((float)(transB->m_basis.m_el[1].mVec128.m128_f32[2] * v70)
                                      + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[1] * v69))
                              + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[0] * v71))
                      + transB->m_origin.mVec128.m128_f32[1];
    v74 = (float)((float)((float)(transB->m_basis.m_el[2].mVec128.m128_f32[2] * v70) + (float)(v73 * v69))
                + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[0] * v71))
        + transB->m_origin.mVec128.m128_f32[2];
    *(float *)v95 = v72;
    *(float *)&v95[2] = v74;
    v75 = transB->m_basis.m_el[2].mVec128.m128_f32[1];
    v76 = transB->m_basis.m_el[2].mVec128.m128_f32[2];
    v77 = transB->m_basis.m_el[1].mVec128.m128_f32[2];
    v78 = pointCollector->__vftable;
    v95[3] = 0;
    v79 = v56[14];
    v80 = v56[13];
    v81 = v56[12];
    v82 = (float)((float)(v75 * v80) + (float)(v76 * v79)) + (float)(v81 * transB->m_basis.m_el[2].mVec128.m128_f32[0]);
    v83 = (float)(transB->m_basis.m_el[1].mVec128.m128_f32[1] * v80) + (float)(v77 * v79);
    v84 = v81 * transB->m_basis.m_el[1].mVec128.m128_f32[0];
    v96[0] = (float)((float)(v80 * v87.m_el[2].mVec128.m128_f32[3]) + (float)(v79 * v65)) + (float)(v81 * v88);
    v96[1] = v83 + v84;
    v96[2] = v82;
    v96[3] = 0.0;
    ((void (__stdcall *)(float *, _DWORD *, int))v78->drawLine)(v96, v95, v87.m_el[1].mVec128.m128_i32[2]);
  }
}
