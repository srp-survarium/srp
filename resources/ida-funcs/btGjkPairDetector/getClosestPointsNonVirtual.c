void __thiscall btGjkPairDetector::getClosestPointsNonVirtual(
        btGjkPairDetector *this,
        const btDiscreteCollisionDetectorInterface::ClosestPointInput *input,
        btDiscreteCollisionDetectorInterface::Result *output,
        btIDebugDraw *debugDraw,
        int a5)
{
  int v5; // eax
  int v6; // eax
  int v7; // eax
  bool v8; // zf
  float v9; // xmm0_4
  float v10; // xmm2_4
  int v11; // eax
  float *v12; // edx
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm4_4
  float v17; // xmm0_4
  float v18; // xmm4_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  btConvexShape *v21; // ecx
  float v22; // xmm0_4
  float v23; // xmm2_4
  unsigned int v24; // xmm4_4
  float v25; // xmm0_4
  float v26; // xmm5_4
  float v27; // xmm0_4
  btVoronoiSimplexSolver *v28; // ecx
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm4_4
  float v32; // xmm5_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm0_4
  const btVector3 *v37; // edx
  int v38; // esi
  btVoronoiSimplexSolver *v39; // ecx
  bool updated; // al
  float v41; // xmm0_4
  bool v42; // cf
  int v43; // eax
  float v44; // xmm2_4
  float v45; // xmm1_4
  float v46; // xmm0_4
  float v47; // xmm3_4
  float v48; // xmm4_4
  float v49; // xmm1_4
  float v50; // xmm2_4
  bool v51; // al
  int *v52; // ecx
  int v53; // edx
  float v54; // xmm1_4
  float v55; // xmm0_4
  float v56; // xmm2_4
  float v57; // xmm3_4
  float v58; // xmm1_4
  float v59; // xmm0_4
  float v60; // xmm2_4
  float v61; // xmm1_4
  float v62; // xmm3_4
  float v63; // xmm7_4
  float v64; // xmm0_4
  btVector3 *v65; // eax
  float v66; // xmm0_4
  float v67; // xmm1_4
  float v68; // xmm2_4
  float v69; // xmm0_4
  float v70; // xmm0_4
  float v71; // xmm0_4
  float v72; // xmm0_4
  unsigned int v73; // xmm0_4
  btIDebugDraw_vtbl *v74; // eax
  btDiscreteCollisionDetectorInterface::Result_vtbl *v75; // [esp+28h] [ebp-174h]
  char v76; // [esp+42h] [ebp-15Ah]
  bool v77; // [esp+43h] [ebp-159h]
  float v78; // [esp+44h] [ebp-158h]
  float v79; // [esp+48h] [ebp-154h]
  btVector3 v80; // [esp+4Ch] [ebp-150h] BYREF
  btVector3 v81; // [esp+5Ch] [ebp-140h] BYREF
  float v82; // [esp+78h] [ebp-124h]
  btVector3 result; // [esp+7Ch] [ebp-120h] BYREF
  btVector3 v84; // [esp+8Ch] [ebp-110h] BYREF
  float v85; // [esp+A8h] [ebp-F4h]
  btVector3 v86; // [esp+ACh] [ebp-F0h] BYREF
  btVector3 v87; // [esp+BCh] [ebp-E0h] BYREF
  float v88; // [esp+D8h] [ebp-C4h]
  float v89; // [esp+DCh] [ebp-C0h]
  float v90; // [esp+E0h] [ebp-BCh]
  float v91; // [esp+E4h] [ebp-B8h]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v92; // [esp+ECh] [ebp-B0h] BYREF
  btDiscreteCollisionDetectorInterface::Result_vtbl *v93; // [esp+F0h] [ebp-ACh]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v94; // [esp+F4h] [ebp-A8h]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v95; // [esp+F8h] [ebp-A4h]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v96; // [esp+FCh] [ebp-A0h]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v97; // [esp+100h] [ebp-9Ch]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v98; // [esp+104h] [ebp-98h]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v99; // [esp+108h] [ebp-94h]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v100; // [esp+10Ch] [ebp-90h]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v101; // [esp+110h] [ebp-8Ch]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v102; // [esp+114h] [ebp-88h]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v103; // [esp+118h] [ebp-84h]
  float v104; // [esp+11Ch] [ebp-80h]
  float v105; // [esp+120h] [ebp-7Ch]
  float v106; // [esp+124h] [ebp-78h]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v107; // [esp+128h] [ebp-74h]
  btVector3 v108; // [esp+12Ch] [ebp-70h] BYREF
  btDiscreteCollisionDetectorInterface::Result_vtbl *v109; // [esp+13Ch] [ebp-60h] BYREF
  btDiscreteCollisionDetectorInterface::Result_vtbl *v110; // [esp+140h] [ebp-5Ch]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v111; // [esp+144h] [ebp-58h]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v112; // [esp+148h] [ebp-54h]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v113; // [esp+14Ch] [ebp-50h]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v114; // [esp+150h] [ebp-4Ch]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v115; // [esp+154h] [ebp-48h]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v116; // [esp+158h] [ebp-44h]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v117; // [esp+15Ch] [ebp-40h]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v118; // [esp+160h] [ebp-3Ch]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v119; // [esp+164h] [ebp-38h]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v120; // [esp+168h] [ebp-34h]
  float v121; // [esp+16Ch] [ebp-30h]
  float v122; // [esp+170h] [ebp-2Ch]
  float v123; // [esp+174h] [ebp-28h]
  btDiscreteCollisionDetectorInterface::Result_vtbl *v124; // [esp+178h] [ebp-24h]
  btVector3 v125; // [esp+17Ch] [ebp-20h] BYREF
  btVector3 localDir; // [esp+18Ch] [ebp-10h] BYREF

  input->m_transformB.m_basis.m_el[0].mVec128.m128_i32[1] = 0;
  v92 = output->__vftable;
  v93 = output[1].__vftable;
  v94 = output[2].__vftable;
  v95 = output[3].__vftable;
  v96 = output[4].__vftable;
  v97 = output[5].__vftable;
  v98 = output[6].__vftable;
  v99 = output[7].__vftable;
  v100 = output[8].__vftable;
  v101 = output[9].__vftable;
  v102 = output[10].__vftable;
  v103 = output[11].__vftable;
  v104 = *(float *)&output[12].__vftable;
  v105 = *(float *)&output[13].__vftable;
  v106 = *(float *)&output[14].__vftable;
  v107 = output[15].__vftable;
  v109 = output[16].__vftable;
  v110 = output[17].__vftable;
  v111 = output[18].__vftable;
  v112 = output[19].__vftable;
  v113 = output[20].__vftable;
  v114 = output[21].__vftable;
  v115 = output[22].__vftable;
  v116 = output[23].__vftable;
  v117 = output[24].__vftable;
  v118 = output[25].__vftable;
  v119 = output[26].__vftable;
  v120 = output[27].__vftable;
  v121 = *(float *)&output[28].__vftable;
  v122 = *(float *)&output[29].__vftable;
  v123 = *(float *)&output[30].__vftable;
  v124 = output[31].__vftable;
  v89 = (float)(v121 + v104) * 0.5;
  v78 = 0.0;
  memset(&v80, 0, sizeof(v80));
  v90 = (float)(v122 + v105) * 0.5;
  v91 = (float)(v123 + v106) * 0.5;
  v104 = v104 - v89;
  v5 = input->m_transformA.m_basis.m_el[2].mVec128.m128_i32[2];
  v105 = v105 - v90;
  v106 = v106 - v91;
  v121 = v121 - v89;
  v122 = v122 - v90;
  v123 = v123 - v91;
  v6 = *(_DWORD *)(v5 + 4);
  v77 = 0;
  if ( v6 == 17 || v6 == 18 )
  {
    v7 = *(_DWORD *)(input->m_transformA.m_basis.m_el[2].mVec128.m128_i32[3] + 4);
    if ( v7 == 17 || v7 == 18 )
      v77 = 1;
  }
  ++gNumGjkChecks;
  v8 = input->m_transformB.m_basis.m_el[0].mVec128.m128_i8[0] == 0;
  v9 = input->m_transformA.m_origin.mVec128.m128_f32[3];
  v10 = input->m_transformA.m_origin.mVec128.m128_f32[2];
  v82 = v9;
  if ( !v8 )
  {
    v9 = 0.0;
    v10 = 0.0;
    v82 = 0.0;
  }
  input->m_transformB.m_basis.m_el[0].mVec128.m128_i32[3] = 0;
  input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1] = s_bm_current_air_resistance;
  input->m_transformA.m_basis.m_el[1].mVec128.m128_i32[0] = 0;
  input->m_transformA.m_basis.m_el[1].mVec128.m128_u64[1] = 0;
  v11 = input->m_transformA.m_basis.m_el[2].mVec128.m128_i32[1];
  input->m_transformB.m_basis.m_el[1].mVec128.m128_i32[0] = 0;
  input->m_transformB.m_basis.m_el[0].mVec128.m128_i32[2] = -1;
  v76 = 0;
  v79 = FLOAT_9_9999998e17;
  v85 = v9 + v10;
  btVoronoiSimplexSolver::reset((btVoronoiSimplexSolver *)this, v11);
  v108.mVec128.m128_i32[3] = 0;
  v86.mVec128.m128_i32[3] = 0;
  v125.mVec128.m128_i32[3] = 0;
  while ( 1 )
  {
    LODWORD(v13) = input->m_transformA.m_basis.m_el[1].mVec128.m128_i32[1] ^ _mask__NegFloat_;
    LODWORD(v14) = input->m_transformA.m_basis.m_el[1].mVec128.m128_i32[2] ^ _mask__NegFloat_;
    LODWORD(v15) = input->m_transformA.m_basis.m_el[1].mVec128.m128_i32[0] ^ _mask__NegFloat_;
    localDir.mVec128.m128_f32[0] = (float)((float)(v14 * v12[8]) + (float)(v13 * v12[4])) + (float)(*v12 * v15);
    v16 = v14 * v12[9];
    v17 = v14 * v12[10];
    localDir.mVec128.m128_f32[1] = (float)(v16 + (float)(v15 * v12[1])) + (float)(v13 * v12[5]);
    v18 = v12[6] * v13;
    v19 = input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1];
    v20 = v18 + v17;
    v21 = (btConvexShape *)input->m_transformA.m_basis.m_el[2].mVec128.m128_i32[2];
    v22 = v12[2] * v15;
    v23 = input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2];
    *(float *)&v24 = v20 + v22;
    v25 = input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[0];
    localDir.mVec128.m128_u64[1] = v24;
    v87.mVec128.m128_f32[0] = (float)((float)(v23 * v12[24]) + (float)(v19 * v12[20])) + (float)(v12[16] * v25);
    v26 = v12[17] * v25;
    v27 = v25 * v12[18];
    v87.mVec128.m128_f32[1] = (float)((float)(v19 * v12[21]) + (float)(v23 * v12[25])) + v26;
    v87.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT((float)((float)(v12[22] * v19) + (float)(v12[26] * v23)) + v27);
    btConvexShape::localGetSupportVertexWithoutMarginNonVirtual(v21, &result, &localDir);
    btConvexShape::localGetSupportVertexWithoutMarginNonVirtual(
      (btConvexShape *)input->m_transformA.m_basis.m_el[2].mVec128.m128_i32[3],
      &v84,
      &v87);
    v29 = (float)((float)((float)(*(float *)&v93 * result.mVec128.m128_f32[1])
                        + (float)(*(float *)&v94 * result.mVec128.m128_f32[2]))
                + (float)(*(float *)&v92 * result.mVec128.m128_f32[0]))
        + v104;
    v30 = (float)((float)((float)(*(float *)&v101 * result.mVec128.m128_f32[1])
                        + (float)(*(float *)&v102 * result.mVec128.m128_f32[2]))
                + (float)(*(float *)&v100 * result.mVec128.m128_f32[0]))
        + v106;
    v31 = (float)((float)((float)(*(float *)&v110 * v84.mVec128.m128_f32[1])
                        + (float)(*(float *)&v111 * v84.mVec128.m128_f32[2]))
                + (float)(*(float *)&v109 * v84.mVec128.m128_f32[0]))
        + v121;
    v32 = (float)((float)((float)(*(float *)&v114 * v84.mVec128.m128_f32[1])
                        + (float)(*(float *)&v115 * v84.mVec128.m128_f32[2]))
                + (float)(*(float *)&v113 * v84.mVec128.m128_f32[0]))
        + v122;
    v108.mVec128.m128_f32[0] = v29;
    v108.mVec128.m128_f32[1] = (float)((float)((float)(*(float *)&v97 * result.mVec128.m128_f32[1])
                                             + (float)(*(float *)&v98 * result.mVec128.m128_f32[2]))
                                     + (float)(*(float *)&v96 * result.mVec128.m128_f32[0]))
                             + v105;
    v108.mVec128.m128_f32[2] = v30;
    v86.mVec128.m128_f32[0] = v31;
    v86.mVec128.m128_f32[1] = v32;
    v86.mVec128.m128_f32[2] = (float)((float)((float)(v84.mVec128.m128_f32[2] * *(float *)&v119)
                                            + (float)(*(float *)&v118 * v84.mVec128.m128_f32[1]))
                                    + (float)(v84.mVec128.m128_f32[0] * *(float *)&v117))
                            + v123;
    if ( v77 )
    {
      v30 = 0.0;
      v108.mVec128.m128_i32[2] = 0;
      v86.mVec128.m128_i32[2] = 0;
    }
    v33 = v30 - v86.mVec128.m128_f32[2];
    v34 = input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2] * v33;
    v125.mVec128.m128_f32[2] = v33;
    v35 = input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1];
    v125.mVec128.m128_f32[0] = v29 - v31;
    v36 = (float)(v34
                + (float)(v35
                        * (float)((float)((float)((float)((float)(*(float *)&v97 * result.mVec128.m128_f32[1])
                                                        + (float)(*(float *)&v98 * result.mVec128.m128_f32[2]))
                                                + (float)(*(float *)&v96 * result.mVec128.m128_f32[0]))
                                        + v105)
                                - v32)))
        + (float)((float)(v29 - v31) * input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[0]);
    v125.mVec128.m128_f32[1] = (float)((float)((float)((float)(*(float *)&v97 * result.mVec128.m128_f32[1])
                                                     + (float)(*(float *)&v98 * result.mVec128.m128_f32[2]))
                                             + (float)(*(float *)&v96 * result.mVec128.m128_f32[0]))
                                     + v105)
                             - v32;
    v88 = v36;
    if ( v36 > 0.0 && (float)(v36 * v36) > (float)(*(float *)&output[32].__vftable * v79) )
    {
      input->m_transformB.m_basis.m_el[1].mVec128.m128_i32[0] = 10;
      goto LABEL_23;
    }
    if ( btVoronoiSimplexSolver::inSimplex(
           (btVoronoiSimplexSolver *)input->m_transformA.m_basis.m_el[2].mVec128.m128_i32[1],
           &v125) )
    {
      input->m_transformB.m_basis.m_el[1].mVec128.m128_i32[0] = 1;
      goto LABEL_23;
    }
    if ( (float)(v79 * 0.000001) >= (float)(v79 - v88) )
      break;
    btVoronoiSimplexSolver::addVertex(v28, (btVector3 *)v28, v37, &v108, &v86);
    v38 = input->m_transformA.m_basis.m_el[2].mVec128.m128_i32[1];
    updated = btVoronoiSimplexSolver::updateClosestVectorAndPoints(v39, (btVoronoiSimplexSolver *)v38);
    v38 += 288;
    v81.mVec128.m128_i32[0] = *(_DWORD *)v38;
    v38 += 4;
    v81.mVec128.m128_i32[1] = *(_DWORD *)v38;
    v81.mVec128.m128_u64[1] = *(_QWORD *)(v38 + 4);
    if ( !updated )
    {
      input->m_transformB.m_basis.m_el[1].mVec128.m128_i32[0] = 3;
      goto LABEL_23;
    }
    v41 = (float)((float)(v81.mVec128.m128_f32[0] * v81.mVec128.m128_f32[0])
                + (float)(v81.mVec128.m128_f32[1] * v81.mVec128.m128_f32[1]))
        + (float)(v81.mVec128.m128_f32[2] * v81.mVec128.m128_f32[2]);
    if ( v41 < 0.000001 )
    {
      input->m_transformA.m_basis.m_el[1] = (btVector3)v81.mVec128;
      input->m_transformB.m_basis.m_el[1].mVec128.m128_i32[0] = 6;
      goto LABEL_23;
    }
    v42 = (float)(v79 * 0.00000011920929) < (float)(v79 - v41);
    v79 = (float)((float)(v81.mVec128.m128_f32[0] * v81.mVec128.m128_f32[0])
                + (float)(v81.mVec128.m128_f32[1] * v81.mVec128.m128_f32[1]))
        + (float)(v81.mVec128.m128_f32[2] * v81.mVec128.m128_f32[2]);
    if ( !v42 )
    {
      input->m_transformB.m_basis.m_el[1].mVec128.m128_i32[0] = 12;
      goto LABEL_23;
    }
    v43 = input->m_transformB.m_basis.m_el[0].mVec128.m128_i32[3];
    input->m_transformA.m_basis.m_el[1] = (btVector3)v81.mVec128;
    input->m_transformB.m_basis.m_el[0].mVec128.m128_i32[3] = v43 + 1;
    if ( v43 > 1000 )
      goto LABEL_36;
    if ( *(_DWORD *)input->m_transformA.m_basis.m_el[2].mVec128.m128_i32[1] == 4 )
    {
      input->m_transformB.m_basis.m_el[1].mVec128.m128_i32[0] = 13;
      goto LABEL_36;
    }
    v12 = (float *)output;
  }
  if ( (float)(v79 - v88) > 0.0 )
    input->m_transformB.m_basis.m_el[1].mVec128.m128_i32[0] = 11;
  else
    input->m_transformB.m_basis.m_el[1].mVec128.m128_i32[0] = 2;
LABEL_23:
  btVoronoiSimplexSolver::compute_points(
    v28,
    (btVoronoiSimplexSolver *)input->m_transformA.m_basis.m_el[2].mVec128.m128_i32[1],
    &v87,
    &v81);
  v44 = input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1];
  v45 = input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2];
  v80.mVec128 = (__m128)input->m_transformA.m_basis.m_el[1];
  v46 = (float)((float)(v80.mVec128.m128_f32[0] * v80.mVec128.m128_f32[0]) + (float)(v44 * v44)) + (float)(v45 * v45);
  if ( v46 < 0.0001 )
    input->m_transformB.m_basis.m_el[1].mVec128.m128_i32[0] = 5;
  if ( v46 <= 1.4210855e-14 )
  {
    input->m_transformB.m_basis.m_el[0].mVec128.m128_i32[2] = 2;
  }
  else
  {
    v47 = input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1];
    v48 = input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2];
    v49 = s_bm_current_air_resistance / fsqrt(v46);
    v80.mVec128.m128_f32[0] = v80.mVec128.m128_f32[0] * v49;
    v80.mVec128.m128_f32[1] = v80.mVec128.m128_f32[1] * v49;
    v80.mVec128.m128_f32[2] = v80.mVec128.m128_f32[2] * v49;
    v50 = v82 / fsqrt(v79);
    v81.mVec128.m128_f32[0] = (float)(input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[0] * v50)
                            + v81.mVec128.m128_f32[0];
    v81.mVec128.m128_f32[1] = v81.mVec128.m128_f32[1] + (float)(v47 * v50);
    v81.mVec128.m128_f32[2] = v81.mVec128.m128_f32[2] + (float)(v48 * v50);
    v78 = (float)(s_bm_current_air_resistance / v49) - v85;
    v76 = 1;
    input->m_transformB.m_basis.m_el[0].mVec128.m128_i32[2] = 1;
  }
LABEL_36:
  v51 = input->m_transformB.m_basis.m_el[1].mVec128.m128_i32[1]
     && input->m_transformA.m_basis.m_el[2].mVec128.m128_i32[0]
     && input->m_transformB.m_basis.m_el[1].mVec128.m128_i32[0]
     && (float)(v85 + v78) < 0.01;
  if ( (!v76 || v51) && input->m_transformA.m_basis.m_el[2].mVec128.m128_i32[0] )
  {
    input->m_transformA.m_basis.m_el[1].mVec128.m128_u64[0] = 0;
    input->m_transformA.m_basis.m_el[1].mVec128.m128_u64[1] = 0;
    v75 = output[33].__vftable;
    v52 = (int *)input->m_transformA.m_basis.m_el[2].mVec128.m128_i32[0];
    v53 = *v52;
    ++gNumDeepPenetrationChecks;
    if ( (*(unsigned __int8 (__thiscall **)(int *, int, int, int, btDiscreteCollisionDetectorInterface::Result_vtbl **, btDiscreteCollisionDetectorInterface::Result_vtbl **, btVector3 *, btVector3 *, btVector3 *, int, btDiscreteCollisionDetectorInterface::Result_vtbl *))(v53 + 4))(
           v52,
           input->m_transformA.m_basis.m_el[2].mVec128.m128_i32[1],
           input->m_transformA.m_basis.m_el[2].mVec128.m128_i32[2],
           input->m_transformA.m_basis.m_el[2].mVec128.m128_i32[3],
           &v92,
           &v109,
           &input->m_transformA.m_basis.m_el[1],
           &v86,
           &v84,
           a5,
           v75) )
    {
      result.mVec128.m128_i32[3] = 0;
      v54 = v84.mVec128.m128_f32[1] - v86.mVec128.m128_f32[1];
      v55 = v84.mVec128.m128_f32[2] - v86.mVec128.m128_f32[2];
      v56 = v84.mVec128.m128_f32[0] - v86.mVec128.m128_f32[0];
      v57 = (float)((float)(v55 * v55) + (float)(v54 * v54)) + (float)(v56 * v56);
      result.mVec128.m128_f32[0] = v84.mVec128.m128_f32[0] - v86.mVec128.m128_f32[0];
      result.mVec128.m128_f32[1] = v84.mVec128.m128_f32[1] - v86.mVec128.m128_f32[1];
      result.mVec128.m128_f32[2] = v84.mVec128.m128_f32[2] - v86.mVec128.m128_f32[2];
      if ( v57 <= 1.4210855e-14 )
      {
        v58 = input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1];
        v59 = input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2];
        result.mVec128 = (__m128)input->m_transformA.m_basis.m_el[1];
        v60 = v58 * v58;
        v61 = v59 * v59;
        v55 = result.mVec128.m128_f32[2];
        v62 = (float)(result.mVec128.m128_f32[0] * result.mVec128.m128_f32[0]) + v60;
        v56 = result.mVec128.m128_f32[0];
        v57 = v62 + v61;
        v54 = result.mVec128.m128_f32[1];
      }
      if ( v57 <= 1.4210855e-14 )
      {
        input->m_transformB.m_basis.m_el[0].mVec128.m128_i32[2] = 9;
        goto LABEL_60;
      }
      v63 = fsqrt(v57);
      result.mVec128.m128_f32[2] = v55 * (float)(s_bm_current_air_resistance / v63);
      result.mVec128.m128_f32[1] = v54 * (float)(s_bm_current_air_resistance / v63);
      LODWORD(v64) = COERCE_UNSIGNED_INT(
                       fsqrt(
                         (float)((float)((float)(v86.mVec128.m128_f32[2] - v84.mVec128.m128_f32[2])
                                       * (float)(v86.mVec128.m128_f32[2] - v84.mVec128.m128_f32[2]))
                               + (float)((float)(v86.mVec128.m128_f32[1] - v84.mVec128.m128_f32[1])
                                       * (float)(v86.mVec128.m128_f32[1] - v84.mVec128.m128_f32[1])))
                       + (float)((float)(v86.mVec128.m128_f32[0] - v84.mVec128.m128_f32[0])
                               * (float)(v86.mVec128.m128_f32[0] - v84.mVec128.m128_f32[0]))))
                   ^ _mask__NegFloat_;
      result.mVec128.m128_f32[0] = v56 * (float)(s_bm_current_air_resistance / v63);
      if ( v76 && v78 <= v64 )
      {
        input->m_transformB.m_basis.m_el[0].mVec128.m128_i32[2] = 8;
        goto LABEL_60;
      }
      v81.mVec128 = v84.mVec128;
      v80.mVec128 = result.mVec128;
      v78 = v64;
      input->m_transformB.m_basis.m_el[0].mVec128.m128_i32[2] = 3;
    }
    else
    {
      v65 = &input->m_transformA.m_basis.m_el[1];
      if ( (float)((float)((float)(input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[0]
                                 * input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[0])
                         + (float)(input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1]
                                 * input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1]))
                 + (float)(input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2]
                         * input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2])) <= 0.0 )
        goto LABEL_60;
      v66 = fsqrt(
              (float)((float)((float)(v86.mVec128.m128_f32[2] - v84.mVec128.m128_f32[2])
                            * (float)(v86.mVec128.m128_f32[2] - v84.mVec128.m128_f32[2]))
                    + (float)((float)(v86.mVec128.m128_f32[1] - v84.mVec128.m128_f32[1])
                            * (float)(v86.mVec128.m128_f32[1] - v84.mVec128.m128_f32[1])))
            + (float)((float)(v86.mVec128.m128_f32[0] - v84.mVec128.m128_f32[0])
                    * (float)(v86.mVec128.m128_f32[0] - v84.mVec128.m128_f32[0])))
          - v85;
      if ( v76 && v78 <= v66 )
      {
        input->m_transformB.m_basis.m_el[0].mVec128.m128_i32[2] = 5;
        goto LABEL_60;
      }
      v67 = input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[1] * v82;
      v81.mVec128 = v84.mVec128;
      v68 = (float)(input->m_transformA.m_basis.m_el[1].mVec128.m128_f32[2] * v82) + v84.mVec128.m128_f32[2];
      v80.mVec128.m128_u64[0] = v65->mVec128.m128_u64[0];
      v80.mVec128.m128_i32[2] = input->m_transformA.m_basis.m_el[1].mVec128.m128_i32[2];
      v78 = v66;
      v69 = (float)(v65->mVec128.m128_f32[0] * v82) + v84.mVec128.m128_f32[0];
      v81.mVec128.m128_f32[1] = v67 + v84.mVec128.m128_f32[1];
      v80.mVec128.m128_i32[3] = input->m_transformA.m_basis.m_el[1].mVec128.m128_i32[3];
      v81.mVec128.m128_f32[0] = v69;
      v70 = s_bm_current_air_resistance
          / fsqrt(
              (float)((float)(v80.mVec128.m128_f32[0] * v80.mVec128.m128_f32[0])
                    + (float)(v80.mVec128.m128_f32[2] * v80.mVec128.m128_f32[2]))
            + (float)(v80.mVec128.m128_f32[1] * v80.mVec128.m128_f32[1]));
      v80.mVec128.m128_f32[0] = v70 * v80.mVec128.m128_f32[0];
      v81.mVec128.m128_f32[2] = v68;
      v80.mVec128.m128_f32[1] = v70 * v80.mVec128.m128_f32[1];
      v80.mVec128.m128_f32[2] = v70 * v80.mVec128.m128_f32[2];
      input->m_transformB.m_basis.m_el[0].mVec128.m128_i32[2] = 6;
    }
    v76 = 1;
  }
LABEL_60:
  if ( v76 && (v78 < 0.0 || *(float *)&output[32].__vftable > (float)(v78 * v78)) )
  {
    input->m_transformA.m_basis.m_el[1].mVec128.m128_i32[0] = v80.mVec128.m128_i32[0];
    input->m_transformB.m_basis.m_el[0].mVec128.m128_f32[1] = v78;
    v71 = v81.mVec128.m128_f32[0] + v89;
    input->m_transformA.m_basis.m_el[1].mVec128.m128_i32[1] = v80.mVec128.m128_i32[1];
    v87.mVec128.m128_f32[0] = v71;
    v72 = v81.mVec128.m128_f32[1] + v90;
    input->m_transformA.m_basis.m_el[1].mVec128.m128_i32[2] = v80.mVec128.m128_i32[2];
    v87.mVec128.m128_f32[1] = v72;
    *(float *)&v73 = v81.mVec128.m128_f32[2] + v91;
    input->m_transformA.m_basis.m_el[1].mVec128.m128_i32[3] = v80.mVec128.m128_i32[3];
    v74 = debugDraw->__vftable;
    v87.mVec128.m128_u64[1] = v73;
    ((void (__thiscall *)(btIDebugDraw *, btVector3 *, btVector3 *, float))v74->drawLine)(
      debugDraw,
      &v80,
      &v87,
      COERCE_FLOAT(LODWORD(v78)));
  }
}
