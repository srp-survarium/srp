char __thiscall btSubsimplexConvexCast::calcTimeOfImpact(
        btSubsimplexConvexCast *this,
        const btTransform *fromA,
        const btTransform *toA,
        const btTransform *fromB,
        const btTransform *toB,
        btVoronoiSimplexSolver *result)
{
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  float v17; // xmm2_4
  float v18; // xmm6_4
  float v19; // xmm5_4
  float v20; // xmm1_4
  const btConvexShape *m_convexA; // ecx
  float v22; // xmm4_4
  float v23; // xmm0_4
  float v24; // xmm5_4
  float *v25; // eax
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm1_4
  float v30; // xmm4_4
  float v31; // xmm1_4
  btSubsimplexConvexCast *v32; // ebx
  const btConvexShape *m_convexB; // ecx
  float v34; // xmm0_4
  float v35; // xmm1_4
  float *v36; // eax
  float v37; // xmm5_4
  float v38; // xmm4_4
  unsigned int v39; // xmm0_4
  float v40; // xmm3_4
  unsigned int v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm5_4
  float v44; // xmm2_4
  float v45; // xmm4_4
  float v46; // xmm2_4
  float v47; // xmm1_4
  const btConvexShape *v49; // ecx
  float *v50; // eax
  float v51; // xmm2_4
  float v52; // xmm1_4
  float v53; // xmm3_4
  const btConvexShape *v54; // ecx
  float *v55; // eax
  float v56; // xmm4_4
  float v57; // xmm5_4
  float v58; // xmm2_4
  float v59; // xmm3_4
  float v60; // xmm1_4
  float v61; // xmm6_4
  float v62; // xmm3_4
  float v63; // xmm6_4
  float v64; // xmm1_4
  float v65; // xmm6_4
  float v66; // xmm1_4
  float v67; // xmm6_4
  float v68; // xmm1_4
  float v69; // xmm6_4
  float v70; // xmm1_4
  float v71; // xmm3_4
  const btVector3 *v72; // edx
  btVoronoiSimplexSolver *v73; // ecx
  int *p_m_numVertices; // esi
  bool updated; // al
  float v76; // xmm1_4
  float v77; // xmm3_4
  float v78; // xmm3_4
  int v81; // [esp+1Ch] [ebp-194h]
  float v82; // [esp+20h] [ebp-190h]
  float v83; // [esp+24h] [ebp-18Ch]
  float v84; // [esp+28h] [ebp-188h]
  int v85; // [esp+2Ch] [ebp-184h]
  float v86; // [esp+30h] [ebp-180h] BYREF
  float v87; // [esp+34h] [ebp-17Ch]
  float v88; // [esp+38h] [ebp-178h]
  int v89; // [esp+3Ch] [ebp-174h]
  float v90; // [esp+40h] [ebp-170h]
  float v91; // [esp+44h] [ebp-16Ch]
  float v92; // [esp+48h] [ebp-168h]
  float v93; // [esp+5Ch] [ebp-154h]
  btVector3 q; // [esp+60h] [ebp-150h] BYREF
  btVector3 p; // [esp+70h] [ebp-140h] BYREF
  btVector3 *p_m_origin; // [esp+88h] [ebp-128h]
  btVector3 *v97; // [esp+8Ch] [ebp-124h]
  float v98; // [esp+90h] [ebp-120h]
  float v99; // [esp+94h] [ebp-11Ch]
  float v100; // [esp+98h] [ebp-118h]
  int v101; // [esp+9Ch] [ebp-114h]
  btVector3 w; // [esp+A0h] [ebp-110h] BYREF
  float v103; // [esp+BCh] [ebp-F4h]
  unsigned __int64 v104; // [esp+C0h] [ebp-F0h]
  unsigned __int64 v105; // [esp+C8h] [ebp-E8h]
  btVector3 v106; // [esp+D0h] [ebp-E0h]
  unsigned __int64 v107; // [esp+E0h] [ebp-D0h]
  unsigned __int64 v108; // [esp+E8h] [ebp-C8h]
  unsigned __int64 v109; // [esp+F0h] [ebp-C0h]
  float v110; // [esp+F8h] [ebp-B8h]
  int v111; // [esp+FCh] [ebp-B4h]
  btTransform v112; // [esp+100h] [ebp-B0h]
  float v113[4]; // [esp+140h] [ebp-70h] BYREF
  float v114[12]; // [esp+150h] [ebp-60h] BYREF
  float v115; // [esp+180h] [ebp-30h]
  float v116; // [esp+184h] [ebp-2Ch]
  float v117; // [esp+188h] [ebp-28h]
  int v118; // [esp+18Ch] [ebp-24h]
  btVector3 p2; // [esp+190h] [ebp-20h] BYREF
  btVector3 v120; // [esp+1A0h] [ebp-10h] BYREF

  btVoronoiSimplexSolver::reset((btVoronoiSimplexSolver *)this, (int)this->m_simplexSolver);
  v6 = toB->m_origin.mVec128.m128_f32[0];
  v7 = toB->m_origin.mVec128.m128_f32[1];
  v8 = toB->m_origin.mVec128.m128_f32[2];
  v112 = *fromA;
  v10 = toA->m_origin.mVec128.m128_f32[0];
  v11 = toA->m_origin.mVec128.m128_f32[1];
  v12 = toA->m_origin.mVec128.m128_f32[2];
  v104 = fromB->m_basis.m_el[0].mVec128.m128_u64[0];
  v105 = fromB->m_basis.m_el[0].mVec128.m128_u64[1];
  v106.mVec128 = (__m128)fromB->m_basis.m_el[1];
  v107 = fromB->m_basis.m_el[2].mVec128.m128_u64[0];
  v13 = v10 - fromA->m_origin.mVec128.m128_f32[0];
  v14 = v11 - fromA->m_origin.mVec128.m128_f32[1];
  v15 = v6 - fromB->m_origin.mVec128.m128_f32[0];
  v16 = v7 - fromB->m_origin.mVec128.m128_f32[1];
  v17 = v12 - fromA->m_origin.mVec128.m128_f32[2];
  v18 = v8 - fromB->m_origin.mVec128.m128_f32[2];
  v108 = fromB->m_basis.m_el[2].mVec128.m128_u64[1];
  v109 = fromB->m_origin.mVec128.m128_u64[0];
  v110 = fromB->m_origin.mVec128.m128_f32[2];
  p_m_origin = &fromA->m_origin;
  v97 = &fromB->m_origin;
  v93 = 0.0;
  v111 = fromB->m_origin.mVec128.m128_i32[3];
  v90 = v13 - v15;
  v91 = v14 - v16;
  v19 = fromA->m_basis.m_el[2].mVec128.m128_f32[0];
  LODWORD(v20) = COERCE_UNSIGNED_INT(v13 - v15) ^ _mask__NegFloat_;
  m_convexA = this->m_convexA;
  v92 = v17 - v18;
  LODWORD(v22) = COERCE_UNSIGNED_INT(v17 - v18) ^ _mask__NegFloat_;
  v23 = (float)((float)(COERCE_FLOAT(LODWORD(v91) ^ _mask__NegFloat_) * fromA->m_basis.m_el[1].mVec128.m128_f32[0])
              + (float)(v19 * v22))
      + (float)(fromA->m_basis.m_el[0].mVec128.m128_f32[0] * v20);
  v24 = fromA->m_basis.m_el[1].mVec128.m128_f32[1];
  p.mVec128.m128_f32[0] = v23;
  p.mVec128.m128_f32[1] = (float)((float)(fromA->m_basis.m_el[2].mVec128.m128_f32[1] * v22)
                                + (float)(v24 * COERCE_FLOAT(LODWORD(v91) ^ _mask__NegFloat_)))
                        + (float)(v20 * fromA->m_basis.m_el[0].mVec128.m128_f32[1]);
  p.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                            (float)((float)(fromA->m_basis.m_el[2].mVec128.m128_f32[2] * v22)
                                  + (float)(fromA->m_basis.m_el[1].mVec128.m128_f32[2]
                                          * COERCE_FLOAT(LODWORD(v91) ^ _mask__NegFloat_)))
                          + (float)(fromA->m_basis.m_el[0].mVec128.m128_f32[2] * v20));
  v25 = (float *)m_convexA->localGetSupportingVertex(m_convexA, &w, &p);
  v26 = v25[1];
  v27 = *v25;
  v28 = v25[2];
  v30 = fromA->m_basis.m_el[1].mVec128.m128_f32[2];
  p.mVec128.m128_f32[0] = (float)((float)((float)(fromA->m_basis.m_el[0].mVec128.m128_f32[0] * *v25)
                                        + (float)(v26 * fromA->m_basis.m_el[0].mVec128.m128_f32[1]))
                                + (float)(fromA->m_basis.m_el[0].mVec128.m128_f32[2] * v28))
                        + p_m_origin->mVec128.m128_f32[0];
  p.mVec128.m128_f32[1] = (float)((float)((float)(fromA->m_basis.m_el[1].mVec128.m128_f32[1] * v26) + (float)(v30 * v28))
                                + (float)(fromA->m_basis.m_el[1].mVec128.m128_f32[0] * v27))
                        + fromA->m_origin.mVec128.m128_f32[1];
  p.mVec128.m128_f32[2] = (float)((float)((float)(fromA->m_basis.m_el[2].mVec128.m128_f32[1] * v26)
                                        + (float)(fromA->m_basis.m_el[2].mVec128.m128_f32[2] * v28))
                                + (float)(fromA->m_basis.m_el[2].mVec128.m128_f32[0] * v27))
                        + fromA->m_origin.mVec128.m128_f32[2];
  v31 = fromB->m_basis.m_el[1].mVec128.m128_f32[1] * v91;
  v32 = this;
  m_convexB = this->m_convexB;
  v86 = (float)((float)(fromB->m_basis.m_el[0].mVec128.m128_f32[0] * v90)
              + (float)(v92 * fromB->m_basis.m_el[2].mVec128.m128_f32[0]))
      + (float)(fromB->m_basis.m_el[1].mVec128.m128_f32[0] * v91);
  v34 = (float)((float)(fromB->m_basis.m_el[2].mVec128.m128_f32[1] * v92) + v31)
      + (float)(fromB->m_basis.m_el[0].mVec128.m128_f32[1] * v90);
  v35 = fromB->m_basis.m_el[1].mVec128.m128_f32[2] * v91;
  v87 = v34;
  v88 = (float)((float)(fromB->m_basis.m_el[2].mVec128.m128_f32[2] * v92) + v35)
      + (float)(fromB->m_basis.m_el[0].mVec128.m128_f32[2] * v90);
  v89 = 0;
  v36 = (float *)m_convexB->localGetSupportingVertex(m_convexB, &w, (const btVector3 *)&v86);
  v37 = v36[1];
  v38 = v36[2];
  *(float *)&v39 = (float)((float)((float)(v37 * fromB->m_basis.m_el[0].mVec128.m128_f32[1])
                                 + (float)(fromB->m_basis.m_el[0].mVec128.m128_f32[2] * v38))
                         + (float)(fromB->m_basis.m_el[0].mVec128.m128_f32[0] * *v36))
                 + v97->mVec128.m128_f32[0];
  v40 = *v36 * fromB->m_basis.m_el[2].mVec128.m128_f32[0];
  *(float *)&v41 = (float)((float)((float)(fromB->m_basis.m_el[1].mVec128.m128_f32[1] * v37)
                                 + (float)(fromB->m_basis.m_el[1].mVec128.m128_f32[2] * v38))
                         + (float)(*v36 * fromB->m_basis.m_el[1].mVec128.m128_f32[0]))
                 + fromB->m_origin.mVec128.m128_f32[1];
  v42 = fromB->m_basis.m_el[2].mVec128.m128_f32[1] * v37;
  v43 = fromB->m_basis.m_el[2].mVec128.m128_f32[2];
  q.mVec128.m128_u64[0] = __PAIR64__(v41, v39);
  v44 = (float)((float)(v42 + (float)(v43 * v38)) + v40) + fromB->m_origin.mVec128.m128_f32[2];
  v87 = p.mVec128.m128_f32[1] - *(float *)&v41;
  v88 = p.mVec128.m128_f32[2] - v44;
  q.mVec128.m128_f32[2] = v44;
  v86 = p.mVec128.m128_f32[0] - *(float *)&v39;
  v89 = 0;
  v82 = p.mVec128.m128_f32[0] - *(float *)&v39;
  v83 = p.mVec128.m128_f32[1] - *(float *)&v41;
  v84 = p.mVec128.m128_f32[2] - v44;
  v45 = (float)((float)(v86 * v86) + (float)((float)(p.mVec128.m128_f32[2] - v44) * (float)(p.mVec128.m128_f32[2] - v44)))
      + (float)((float)(p.mVec128.m128_f32[1] - *(float *)&v41) * (float)(p.mVec128.m128_f32[1] - *(float *)&v41));
  v46 = 0.0;
  v47 = 0.0;
  v85 = 0;
  v81 = 32;
  v98 = 0.0;
  v99 = 0.0;
  v100 = 0.0;
  if ( v45 > 0.000099999997 )
  {
    do
    {
      if ( !v81-- )
        break;
      v49 = v32->m_convexA;
      v113[0] = (float)((float)(v112.m_basis.m_el[0].mVec128.m128_f32[0] * COERCE_FLOAT(LODWORD(v82) ^ _mask__NegFloat_))
                      + (float)(v112.m_basis.m_el[2].mVec128.m128_f32[0] * COERCE_FLOAT(LODWORD(v84) ^ _mask__NegFloat_)))
              + (float)(v112.m_basis.m_el[1].mVec128.m128_f32[0] * COERCE_FLOAT(LODWORD(v83) ^ _mask__NegFloat_));
      v113[1] = (float)((float)(v112.m_basis.m_el[2].mVec128.m128_f32[1] * COERCE_FLOAT(LODWORD(v84) ^ _mask__NegFloat_))
                      + (float)(v112.m_basis.m_el[1].mVec128.m128_f32[1] * COERCE_FLOAT(LODWORD(v83) ^ _mask__NegFloat_)))
              + (float)(v112.m_basis.m_el[0].mVec128.m128_f32[1] * COERCE_FLOAT(LODWORD(v82) ^ _mask__NegFloat_));
      v113[2] = (float)((float)(v112.m_basis.m_el[2].mVec128.m128_f32[2] * COERCE_FLOAT(LODWORD(v84) ^ _mask__NegFloat_))
                      + (float)(v112.m_basis.m_el[1].mVec128.m128_f32[2] * COERCE_FLOAT(LODWORD(v83) ^ _mask__NegFloat_)))
              + (float)(v112.m_basis.m_el[0].mVec128.m128_f32[2] * COERCE_FLOAT(LODWORD(v82) ^ _mask__NegFloat_));
      v113[3] = 0.0;
      v50 = (float *)v49->localGetSupportingVertex(v49, &v120, (const btVector3 *)v113);
      v51 = v50[1];
      v52 = v50[2];
      v53 = *v50;
      v86 = (float)((float)((float)(v112.m_basis.m_el[0].mVec128.m128_f32[1] * v51)
                          + (float)(v112.m_basis.m_el[0].mVec128.m128_f32[2] * v52))
                  + (float)(*v50 * v112.m_basis.m_el[0].mVec128.m128_f32[0]))
          + v112.m_origin.mVec128.m128_f32[0];
      v87 = (float)((float)((float)(v112.m_basis.m_el[1].mVec128.m128_f32[1] * v51)
                          + (float)(v112.m_basis.m_el[1].mVec128.m128_f32[0] * v53))
                  + (float)(v112.m_basis.m_el[1].mVec128.m128_f32[2] * v52))
          + v112.m_origin.mVec128.m128_f32[1];
      v88 = (float)((float)((float)(v112.m_basis.m_el[2].mVec128.m128_f32[1] * v51)
                          + (float)(v112.m_basis.m_el[2].mVec128.m128_f32[0] * v53))
                  + (float)(v112.m_basis.m_el[2].mVec128.m128_f32[2] * v52))
          + v112.m_origin.mVec128.m128_f32[2];
      v89 = 0;
      p.mVec128.m128_f32[0] = v86;
      p.mVec128.m128_f32[1] = v87;
      v54 = v32->m_convexB;
      v114[0] = (float)((float)(*(float *)&v104 * v82) + (float)(v106.mVec128.m128_f32[0] * v83))
              + (float)(*(float *)&v107 * v84);
      v114[1] = (float)((float)(v106.mVec128.m128_f32[1] * v83) + (float)(*((float *)&v107 + 1) * v84))
              + (float)(*((float *)&v104 + 1) * v82);
      p.mVec128.m128_u64[1] = LODWORD(v88);
      v114[2] = (float)((float)(v106.mVec128.m128_f32[2] * v83) + (float)(*(float *)&v108 * v84))
              + (float)(*(float *)&v105 * v82);
      v114[3] = 0.0;
      v55 = (float *)v54->localGetSupportingVertex(v54, &p2, (const btVector3 *)v114);
      v56 = v55[2];
      v57 = v55[1];
      v58 = (float)((float)((float)(v106.mVec128.m128_f32[1] * v57) + (float)(*v55 * v106.mVec128.m128_f32[0]))
                  + (float)(v106.mVec128.m128_f32[2] * v56))
          + *((float *)&v109 + 1);
      v59 = (float)(*((float *)&v107 + 1) * v57) + (float)(*v55 * *(float *)&v107);
      v115 = (float)((float)((float)(*((float *)&v104 + 1) * v57) + (float)(*(float *)&v105 * v56))
                   + (float)(*v55 * *(float *)&v104))
           + *(float *)&v109;
      v116 = v58;
      v117 = (float)(v59 + (float)(*(float *)&v108 * v56)) + v110;
      v118 = 0;
      q.mVec128.m128_u64[0] = __PAIR64__(LODWORD(v58), LODWORD(v115));
      q.mVec128.m128_u64[1] = LODWORD(v117);
      v114[8] = v86 - v115;
      v114[10] = v88 - v117;
      v114[11] = 0.0;
      v114[9] = v87 - v58;
      w.mVec128.m128_f32[0] = v86 - v115;
      w.mVec128.m128_f32[1] = v87 - v58;
      v103 = v88 - v117;
      w.mVec128.m128_f32[2] = v88 - v117;
      v60 = (float)((float)((float)(v86 - v115) * v82) + (float)((float)(v87 - v58) * v83))
          + (float)((float)(v88 - v117) * v84);
      w.mVec128.m128_i32[3] = 0;
      if ( v93 > s_bm_current_air_resistance )
        return 0;
      if ( v60 > 0.0 )
      {
        v61 = (float)((float)(v82 * v90) + (float)(v84 * v92)) + (float)(v83 * v91);
        if ( v61 >= -1.4210855e-14 )
          return 0;
        v62 = v93 - (float)(v60 / v61);
        v63 = p_m_origin->mVec128.m128_f32[1];
        v112.m_origin.mVec128.m128_f32[0] = (float)(toA->m_origin.mVec128.m128_f32[0] * v62)
                                          + (float)(p_m_origin->mVec128.m128_f32[0]
                                                  * (float)(s_bm_current_air_resistance - v62));
        v64 = (float)(toA->m_origin.mVec128.m128_f32[1] * v62)
            + (float)(v63 * (float)(s_bm_current_air_resistance - v62));
        v65 = p_m_origin->mVec128.m128_f32[2];
        v112.m_origin.mVec128.m128_f32[1] = v64;
        v66 = (float)(toA->m_origin.mVec128.m128_f32[2] * v62)
            + (float)(v65 * (float)(s_bm_current_air_resistance - v62));
        v67 = toB->m_origin.mVec128.m128_f32[0];
        v112.m_origin.mVec128.m128_f32[2] = v66;
        v68 = (float)((float)(s_bm_current_air_resistance - v62) * v97->mVec128.m128_f32[0]) + (float)(v67 * v62);
        v69 = v97->mVec128.m128_f32[1];
        *(float *)&v109 = v68;
        *((float *)&v109 + 1) = (float)(toB->m_origin.mVec128.m128_f32[1] * v62)
                              + (float)(v69 * (float)(s_bm_current_air_resistance - v62));
        v70 = toB->m_origin.mVec128.m128_f32[2] * v62;
        v93 = v62;
        v71 = v97->mVec128.m128_f32[2] * (float)(s_bm_current_air_resistance - v62);
        v114[4] = v86 - v115;
        v114[5] = v87 - v58;
        v114[7] = 0.0;
        v110 = v70 + v71;
        v114[6] = v103;
        w.mVec128.m128_f32[0] = v86 - v115;
        w.mVec128.m128_f32[1] = v87 - v58;
        w.mVec128.m128_u64[1] = LODWORD(v103);
        v98 = v82;
        v99 = v83;
        v100 = v84;
        v101 = v85;
      }
      if ( !btVoronoiSimplexSolver::inSimplex(v32->m_simplexSolver, &w) )
        btVoronoiSimplexSolver::addVertex(v73, (btVector3 *)v73, v72, &p, &q);
      p_m_numVertices = &v32->m_simplexSolver->m_numVertices;
      updated = btVoronoiSimplexSolver::updateClosestVectorAndPoints(v73, p_m_numVertices);
      p_m_numVertices += 72;
      v82 = *(float *)p_m_numVertices++;
      v83 = *(float *)p_m_numVertices++;
      v84 = *(float *)p_m_numVertices;
      v85 = p_m_numVertices[1];
      v76 = updated ? (float)((float)(v82 * v82) + (float)(v83 * v83)) + (float)(v84 * v84) : 0.0;
    }
    while ( v76 > 0.000099999997 );
    v46 = v99;
    v47 = v100;
  }
  result->m_simplexPointsQ[0].mVec128.m128_f32[0] = v93;
  v77 = (float)((float)(v98 * v98) + (float)(v47 * v47)) + (float)(v46 * v46);
  q.mVec128.m128_i32[3] = 0;
  if ( v77 < 1.4210855e-14 )
  {
    memset(&q, 0, 12);
  }
  else
  {
    v78 = s_bm_current_air_resistance / fsqrt(v77);
    q.mVec128.m128_f32[0] = v78 * v98;
    q.mVec128.m128_f32[1] = v46 * v78;
    q.mVec128.m128_f32[2] = v47 * v78;
  }
  result->m_simplexPointsP[3] = (btVector3)q.mVec128;
  if ( (float)((float)((float)(result->m_simplexPointsP[3].mVec128.m128_f32[2] * v92)
                     + (float)(result->m_simplexPointsP[3].mVec128.m128_f32[1] * v91))
             + (float)(result->m_simplexPointsP[3].mVec128.m128_f32[0] * v90)) >= COERCE_FLOAT(
                                                                                    result->m_simplexPointsQ[0].mVec128.m128_i32[2]
                                                                                  ^ _mask__NegFloat_) )
    return 0;
  btVoronoiSimplexSolver::compute_points(result, (btVector3 *)v32->m_simplexSolver, &p2, &w);
  result->m_simplexPointsP[4] = (btVector3)w.mVec128;
  return 1;
}
