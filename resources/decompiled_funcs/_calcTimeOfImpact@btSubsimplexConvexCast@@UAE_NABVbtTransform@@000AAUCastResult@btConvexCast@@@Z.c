char __thiscall btSubsimplexConvexCast::calcTimeOfImpact(
        btSubsimplexConvexCast *this,
        const btTransform *fromA,
        const btTransform *toA,
        const btTransform *fromB,
        const btTransform *toB,
        btConvexCast::CastResult *result)
{
  btSubsimplexConvexCast *v6; // esi
  btVoronoiSimplexSolver *m_simplexSolver; // eax
  float *v9; // edi
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm1_4
  float v17; // xmm4_4
  unsigned __int64 v18; // xmm7_8
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm3_4
  float v25; // xmm4_4
  unsigned __int64 v26; // xmm7_8
  float v27; // xmm3_4
  unsigned __int64 v28; // xmm7_8
  const btConvexShape *m_convexA; // ecx
  float *v30; // eax
  float v31; // xmm2_4
  float v32; // xmm3_4
  float v33; // xmm1_4
  float v34; // xmm4_4
  float v35; // xmm0_4
  float v36; // xmm4_4
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  float v40; // xmm3_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm3_4
  float v44; // xmm4_4
  const btConvexShape *m_convexB; // ecx
  float *v46; // eax
  btVoronoiSimplexSolver *v47; // ecx
  float v48; // xmm4_4
  float v49; // xmm5_4
  unsigned int v50; // xmm0_4
  unsigned int v51; // xmm1_4
  int v52; // eax
  float v53; // xmm2_4
  float v54; // xmm1_4
  float v55; // xmm0_4
  float v56; // xmm1_4
  float v57; // xmm2_4
  float v58; // xmm0_4
  const btConvexShape *v59; // ecx
  float *v60; // eax
  float v61; // xmm2_4
  float v62; // xmm1_4
  float v63; // xmm3_4
  const btConvexShape *v64; // ecx
  float *v65; // eax
  float v66; // xmm4_4
  float v67; // xmm5_4
  float v68; // xmm1_4
  unsigned int v69; // xmm2_4
  float v70; // xmm5_4
  float v71; // xmm0_4
  float v72; // xmm7_4
  float v73; // xmm0_4
  float v74; // xmm7_4
  float v75; // xmm2_4
  float v76; // xmm7_4
  float v77; // xmm2_4
  float v78; // xmm2_4
  __m128i v79; // xmm0
  btVoronoiSimplexSolver *v80; // ecx
  btVoronoiSimplexSolver *v81; // esi
  char updated; // al
  __int64 v83; // xmm0_8
  float v85; // xmm1_4
  long double v86; // st7
  float v87; // [esp+B64h] [ebp-1A4h]
  float v88; // [esp+B64h] [ebp-1A4h]
  float _X; // [esp+B64h] [ebp-1A4h]
  btVector3 p; // [esp+B68h] [ebp-1A0h] BYREF
  __int128 v91; // [esp+B78h] [ebp-190h]
  __m128i v92; // [esp+B88h] [ebp-180h] BYREF
  __m128i v93; // [esp+B98h] [ebp-170h] BYREF
  float v94; // [esp+BB4h] [ebp-154h]
  float v95; // [esp+BB8h] [ebp-150h]
  float v96; // [esp+BBCh] [ebp-14Ch]
  float v97; // [esp+BC0h] [ebp-148h]
  float v98; // [esp+BD4h] [ebp-134h]
  __m128i v99; // [esp+BD8h] [ebp-130h]
  int v100; // [esp+BF4h] [ebp-114h]
  btTransform v101; // [esp+BF8h] [ebp-110h]
  unsigned __int64 v102; // [esp+C38h] [ebp-D0h]
  unsigned __int64 v103; // [esp+C40h] [ebp-C8h]
  btVector3 v104; // [esp+C48h] [ebp-C0h]
  unsigned __int64 v105; // [esp+C58h] [ebp-B0h]
  unsigned __int64 v106; // [esp+C60h] [ebp-A8h]
  unsigned __int64 v107; // [esp+C68h] [ebp-A0h]
  unsigned __int64 v108; // [esp+C70h] [ebp-98h]
  btVector3 p2; // [esp+C78h] [ebp-90h] BYREF
  float v110[4]; // [esp+C88h] [ebp-80h] BYREF
  float v111[4]; // [esp+C98h] [ebp-70h] BYREF
  __m128i v112; // [esp+CA8h] [ebp-60h] BYREF
  __m128i v113; // [esp+CB8h] [ebp-50h] BYREF
  __m128i v114; // [esp+CC8h] [ebp-40h] BYREF
  btVector3 q; // [esp+CD8h] [ebp-30h] BYREF
  btVector3 p1; // [esp+CE8h] [ebp-20h] BYREF
  btVector3 v117; // [esp+CF8h] [ebp-10h] BYREF

  v6 = this;
  m_simplexSolver = this->m_simplexSolver;
  HIDWORD(v91) = this;
  btVoronoiSimplexSolver::reset((btVoronoiSimplexSolver *)this, (int)m_simplexSolver);
  v9 = (float *)fromB;
  v10 = toA->m_origin.mVec128.m128_f32[0] - fromA->m_origin.mVec128.m128_f32[0];
  v11 = toA->m_origin.mVec128.m128_f32[1] - fromA->m_origin.mVec128.m128_f32[1];
  v12 = toA->m_origin.mVec128.m128_f32[2] - fromA->m_origin.mVec128.m128_f32[2];
  v13 = toB->m_origin.mVec128.m128_f32[0] - fromB->m_origin.mVec128.m128_f32[0];
  v14 = toB->m_origin.mVec128.m128_f32[1] - fromB->m_origin.mVec128.m128_f32[1];
  v15 = toB->m_origin.mVec128.m128_f32[2] - fromB->m_origin.mVec128.m128_f32[2];
  v101 = *fromA;
  v102 = fromB->m_basis.m_el[0].mVec128.m128_u64[0];
  v16 = v11 - v14;
  v17 = fromA->m_basis.m_el[2].mVec128.m128_f32[0];
  v103 = fromB->m_basis.m_el[0].mVec128.m128_u64[1];
  v104.mVec128 = (__m128)fromB->m_basis.m_el[1];
  v18 = fromB->m_basis.m_el[2].mVec128.m128_u64[0];
  v95 = v10 - v13;
  v19 = -(float)(v10 - v13);
  v96 = v16;
  v20 = -v16;
  v97 = v12 - v15;
  v21 = -(float)(v12 - v15);
  v22 = (float)(v20 * fromA->m_basis.m_el[1].mVec128.m128_f32[0]) + (float)(v17 * v21);
  v23 = fromA->m_basis.m_el[0].mVec128.m128_f32[0];
  v105 = v18;
  v24 = v22 + (float)(v23 * v19);
  v25 = fromA->m_basis.m_el[1].mVec128.m128_f32[1];
  v106 = fromB->m_basis.m_el[2].mVec128.m128_u64[1];
  v26 = fromB->m_origin.mVec128.m128_u64[0];
  p.mVec128.m128_f32[0] = v24;
  v27 = fromA->m_basis.m_el[2].mVec128.m128_f32[1];
  v107 = v26;
  v28 = fromB->m_origin.mVec128.m128_u64[1];
  v94 = 0.0;
  v108 = v28;
  m_convexA = v6->m_convexA;
  p.mVec128.m128_f32[1] = (float)((float)(v27 * v21) + (float)(v25 * v20))
                        + (float)(v19 * fromA->m_basis.m_el[0].mVec128.m128_f32[1]);
  p.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                            (float)((float)(fromA->m_basis.m_el[2].mVec128.m128_f32[2] * v21)
                                  + (float)(fromA->m_basis.m_el[1].mVec128.m128_f32[2] * v20))
                          + (float)(fromA->m_basis.m_el[0].mVec128.m128_f32[2] * v19));
  v30 = (float *)m_convexA->localGetSupportingVertex(m_convexA, &q, &p);
  v31 = v30[1];
  v32 = *v30;
  v33 = v30[2];
  v34 = fromA->m_basis.m_el[1].mVec128.m128_f32[2] * v33;
  p.mVec128.m128_f32[0] = (float)((float)((float)(fromA->m_basis.m_el[0].mVec128.m128_f32[0] * *v30)
                                        + (float)(v31 * fromA->m_basis.m_el[0].mVec128.m128_f32[1]))
                                + (float)(fromA->m_basis.m_el[0].mVec128.m128_f32[2] * v33))
                        + fromA->m_origin.mVec128.m128_f32[0];
  v35 = (float)((float)((float)(fromA->m_basis.m_el[1].mVec128.m128_f32[1] * v31) + v34)
              + (float)(fromA->m_basis.m_el[1].mVec128.m128_f32[0] * v32))
      + fromA->m_origin.mVec128.m128_f32[1];
  v36 = fromB->m_basis.m_el[1].mVec128.m128_f32[0];
  p.mVec128.m128_f32[1] = v35;
  v37 = fromA->m_basis.m_el[2].mVec128.m128_f32[1] * v31;
  v38 = fromA->m_basis.m_el[2].mVec128.m128_f32[2] * v33;
  v39 = fromA->m_basis.m_el[2].mVec128.m128_f32[0] * v32;
  v40 = fromB->m_basis.m_el[0].mVec128.m128_f32[0];
  v41 = (float)((float)(v37 + v38) + v39) + fromA->m_origin.mVec128.m128_f32[2];
  v42 = v97 * fromB->m_basis.m_el[2].mVec128.m128_f32[0];
  p.mVec128.m128_f32[2] = v41;
  v43 = (float)((float)(v40 * v95) + v42) + (float)(v36 * v96);
  v44 = fromB->m_basis.m_el[1].mVec128.m128_f32[1];
  *(float *)v93.m128i_i32 = v43;
  *(float *)&v93.m128i_i32[1] = (float)((float)(v9[9] * v97) + (float)(v44 * v96)) + (float)(v9[1] * v95);
  m_convexB = v6->m_convexB;
  *(float *)&v93.m128i_i32[2] = (float)((float)(v9[10] * v97) + (float)(v9[6] * v96)) + (float)(v95 * v9[2]);
  v93.m128i_i32[3] = 0;
  v46 = (float *)m_convexB->localGetSupportingVertex(m_convexB, &q, (const btVector3 *)&v93);
  v48 = v46[2];
  v49 = v46[1];
  *(float *)&v50 = p.mVec128.m128_f32[1]
                 - (float)((float)((float)((float)(v9[5] * v49) + (float)(v9[6] * v48)) + (float)(*v46 * v9[4])) + v9[13]);
  *(float *)&v51 = p.mVec128.m128_f32[2]
                 - (float)((float)((float)((float)(fromB->m_basis.m_el[2].mVec128.m128_f32[1] * v49)
                                         + (float)(fromB->m_basis.m_el[2].mVec128.m128_f32[2] * v48))
                                 + (float)(*v46 * v9[8]))
                         + v9[14]);
  *(float *)v93.m128i_i32 = p.mVec128.m128_f32[0]
                          - (float)((float)((float)((float)(v48 * v9[2]) + (float)(*v9 * *v46)) + (float)(v9[1] * v49))
                                  + v9[12]);
  *(__int64 *)((char *)v93.m128i_i64 + 4) = __PAIR64__(v51, v50);
  v93.m128i_i32[3] = 0;
  v92 = _mm_load_si128(&v93);
  v52 = 32;
  v99.m128i_i64[0] = 0;
  v99.m128i_i32[2] = 0;
  if ( (float)((float)((float)(*(float *)v93.m128i_i32 * *(float *)v93.m128i_i32)
                     + (float)(*(float *)&v51 * *(float *)&v51))
             + (float)(*(float *)&v50 * *(float *)&v50)) > 0.000099999997 )
  {
    v53 = *(float *)&v92.m128i_i32[2];
    v54 = *(float *)&v92.m128i_i32[1];
    v55 = *(float *)v92.m128i_i32;
    while ( 1 )
    {
      v47 = (btVoronoiSimplexSolver *)v52;
      v100 = v52 - 1;
      if ( !v52 )
        break;
      v56 = -v54;
      v57 = -v53;
      v58 = -v55;
      v59 = v6->m_convexA;
      v110[0] = (float)((float)(v101.m_basis.m_el[0].mVec128.m128_f32[0] * v58)
                      + (float)(v101.m_basis.m_el[2].mVec128.m128_f32[0] * v57))
              + (float)(v101.m_basis.m_el[1].mVec128.m128_f32[0] * v56);
      v110[1] = (float)((float)(v101.m_basis.m_el[2].mVec128.m128_f32[1] * v57)
                      + (float)(v101.m_basis.m_el[1].mVec128.m128_f32[1] * v56))
              + (float)(v101.m_basis.m_el[0].mVec128.m128_f32[1] * v58);
      v110[2] = (float)((float)(v101.m_basis.m_el[2].mVec128.m128_f32[2] * v57)
                      + (float)(v101.m_basis.m_el[1].mVec128.m128_f32[2] * v56))
              + (float)(v101.m_basis.m_el[0].mVec128.m128_f32[2] * v58);
      v110[3] = 0.0;
      v60 = (float *)v59->localGetSupportingVertex(v59, &v117, (const btVector3 *)v110);
      v61 = v60[1];
      v62 = v60[2];
      v63 = *v60;
      *(float *)v93.m128i_i32 = (float)((float)((float)(v101.m_basis.m_el[0].mVec128.m128_f32[1] * v61)
                                              + (float)(v101.m_basis.m_el[0].mVec128.m128_f32[2] * v62))
                                      + (float)(*v60 * v101.m_basis.m_el[0].mVec128.m128_f32[0]))
                              + v101.m_origin.mVec128.m128_f32[0];
      *(float *)&v93.m128i_i32[1] = (float)((float)((float)(v101.m_basis.m_el[1].mVec128.m128_f32[1] * v61)
                                                  + (float)(v101.m_basis.m_el[1].mVec128.m128_f32[0] * v63))
                                          + (float)(v101.m_basis.m_el[1].mVec128.m128_f32[2] * v62))
                                  + v101.m_origin.mVec128.m128_f32[1];
      *(float *)&v93.m128i_i32[2] = (float)((float)((float)(v101.m_basis.m_el[2].mVec128.m128_f32[1] * v61)
                                                  + (float)(v101.m_basis.m_el[2].mVec128.m128_f32[0] * v63))
                                          + (float)(v101.m_basis.m_el[2].mVec128.m128_f32[2] * v62))
                                  + v101.m_origin.mVec128.m128_f32[2];
      v93.m128i_i32[3] = 0;
      p.mVec128 = (__m128)_mm_load_si128(&v93);
      v64 = v6->m_convexB;
      v111[0] = (float)((float)(*(float *)&v102 * *(float *)v92.m128i_i32)
                      + (float)(v104.mVec128.m128_f32[0] * *(float *)&v92.m128i_i32[1]))
              + (float)(*(float *)&v105 * *(float *)&v92.m128i_i32[2]);
      v111[1] = (float)((float)(v104.mVec128.m128_f32[1] * *(float *)&v92.m128i_i32[1])
                      + (float)(*((float *)&v105 + 1) * *(float *)&v92.m128i_i32[2]))
              + (float)(*((float *)&v102 + 1) * *(float *)v92.m128i_i32);
      v111[2] = (float)((float)(v104.mVec128.m128_f32[2] * *(float *)&v92.m128i_i32[1])
                      + (float)(*(float *)&v106 * *(float *)&v92.m128i_i32[2]))
              + (float)(*(float *)&v103 * *(float *)v92.m128i_i32);
      v111[3] = 0.0;
      v65 = (float *)v64->localGetSupportingVertex(v64, &p1, (const btVector3 *)v111);
      v66 = v65[2];
      v67 = v65[1];
      v68 = (float)((float)((float)(v104.mVec128.m128_f32[1] * v67) + (float)(*v65 * v104.mVec128.m128_f32[0]))
                  + (float)(v104.mVec128.m128_f32[2] * v66))
          + *((float *)&v107 + 1);
      *(float *)&v69 = (float)((float)((float)(*((float *)&v105 + 1) * v67) + (float)(*v65 * *(float *)&v105))
                             + (float)(*(float *)&v106 * v66))
                     + *(float *)&v108;
      *(float *)v113.m128i_i32 = (float)((float)((float)(*((float *)&v102 + 1) * v67) + (float)(*(float *)&v103 * v66))
                                       + (float)(*v65 * *(float *)&v102))
                               + *(float *)&v107;
      *(float *)&v113.m128i_i32[1] = v68;
      v113.m128i_i64[1] = v69;
      q.mVec128 = (__m128)_mm_load_si128(&v113);
      *(float *)v112.m128i_i32 = *(float *)v93.m128i_i32 - *(float *)v113.m128i_i32;
      *(float *)&v112.m128i_i32[1] = *(float *)&v93.m128i_i32[1] - v68;
      v70 = *(float *)&v93.m128i_i32[2] - *(float *)&v69;
      *(float *)&v112.m128i_i32[2] = *(float *)&v93.m128i_i32[2] - *(float *)&v69;
      v71 = (float)((float)((float)(*(float *)v93.m128i_i32 - *(float *)v113.m128i_i32) * *(float *)v92.m128i_i32)
                  + (float)((float)(*(float *)&v93.m128i_i32[1] - v68) * *(float *)&v92.m128i_i32[1]))
          + (float)((float)(*(float *)&v93.m128i_i32[2] - *(float *)&v69) * *(float *)&v92.m128i_i32[2]);
      v112.m128i_i32[3] = 0;
      p2.mVec128 = (__m128)_mm_load_si128(&v112);
      if ( v94 > *(float *)&clear_value )
        return 0;
      if ( v71 > 0.0 )
      {
        v72 = (float)((float)(*(float *)v92.m128i_i32 * v95) + (float)(*(float *)&v92.m128i_i32[2] * v97))
            + (float)(*(float *)&v92.m128i_i32[1] * v96);
        if ( v72 >= -1.4210855e-14 )
          return 0;
        v73 = v94 - (float)(v71 / v72);
        v87 = toA->m_origin.mVec128.m128_f32[0] * v73;
        v74 = fromA->m_origin.mVec128.m128_f32[0] * (float)(*(float *)&clear_value - v73);
        v98 = *(float *)&clear_value - v73;
        v101.m_origin.mVec128.m128_f32[0] = v87 + v74;
        v88 = toA->m_origin.mVec128.m128_f32[2] * v73;
        v75 = fromA->m_origin.mVec128.m128_f32[2] * (float)(*(float *)&clear_value - v73);
        v101.m_origin.mVec128.m128_f32[1] = (float)(toA->m_origin.mVec128.m128_f32[1] * v73)
                                          + (float)(fromA->m_origin.mVec128.m128_f32[1]
                                                  * (float)(*(float *)&clear_value - v73));
        v101.m_origin.mVec128.m128_f32[2] = v88 + v75;
        v76 = v9[13];
        *(float *)&v107 = (float)((float)(*(float *)&clear_value - v73) * v9[12])
                        + (float)(toB->m_origin.mVec128.m128_f32[0] * v73);
        *((float *)&v107 + 1) = (float)(toB->m_origin.mVec128.m128_f32[1] * v73)
                              + (float)(v76 * (float)(*(float *)&clear_value - v73));
        v77 = toB->m_origin.mVec128.m128_f32[2];
        v94 = v73;
        v78 = (float)(v77 * v73) + (float)(v9[14] * (float)(*(float *)&clear_value - v73));
        *(float *)v114.m128i_i32 = *(float *)v93.m128i_i32 - *(float *)v113.m128i_i32;
        *(float *)&v114.m128i_i32[1] = *(float *)&v93.m128i_i32[1] - v68;
        v114.m128i_i64[1] = LODWORD(v70);
        p2.mVec128 = (__m128)_mm_load_si128(&v114);
        v79 = _mm_load_si128(&v92);
        *(float *)&v108 = v78;
        v99 = v79;
      }
      if ( !btVoronoiSimplexSolver::inSimplex(v6->m_simplexSolver, &p2) )
      {
        btVoronoiSimplexSolver::addVertex(*(btVoronoiSimplexSolver **)(HIDWORD(v91) + 4), &p2, &p, &q);
        v9 = (float *)fromB;
      }
      v81 = *(btVoronoiSimplexSolver **)(HIDWORD(v91) + 4);
      updated = btVoronoiSimplexSolver::updateClosestVectorAndPoints(v80, v81);
      v92.m128i_i64[0] = v81->m_cachedV.mVec128.m128_i64[0];
      v83 = v81->m_cachedV.mVec128.m128_i64[1];
      v6 = (btSubsimplexConvexCast *)HIDWORD(v91);
      v92.m128i_i64[1] = v83;
      if ( !updated )
        break;
      v55 = *(float *)v92.m128i_i32;
      v54 = *(float *)&v92.m128i_i32[1];
      v53 = *(float *)&v92.m128i_i32[2];
      if ( (float)((float)((float)(v55 * v55) + (float)(v54 * v54)) + (float)(v53 * v53)) <= 0.000099999997 )
        break;
      v52 = v100;
    }
  }
  v85 = *(float *)&v99.m128i_i32[2];
  result->m_fraction = v94;
  _X = (float)((float)(*(float *)v99.m128i_i32 * *(float *)v99.m128i_i32) + (float)(v85 * v85))
     + (float)(*(float *)&v99.m128i_i32[1] * *(float *)&v99.m128i_i32[1]);
  if ( _X < 1.4210855e-14 )
  {
    memset(&p, 0, sizeof(p));
  }
  else
  {
    v86 = 1.0 / sqrtf(_X);
    p.mVec128.m128_i32[3] = 0;
    p.mVec128.m128_f32[0] = *(float *)v99.m128i_i32 * v86;
    p.mVec128.m128_f32[1] = *(float *)&v99.m128i_i32[1] * v86;
    p.mVec128.m128_f32[2] = v86 * *(float *)&v99.m128i_i32[2];
  }
  result->m_normal = (btVector3)p.mVec128;
  if ( (float)((float)((float)(result->m_normal.mVec128.m128_f32[2] * v97)
                     + (float)(result->m_normal.mVec128.m128_f32[1] * v96))
             + (float)(result->m_normal.mVec128.m128_f32[0] * v95)) >= (float)-result->m_allowedPenetration )
    return 0;
  btVoronoiSimplexSolver::compute_points(v6->m_simplexSolver, &p2, v47, &p1);
  result->m_hitPoint = (btVector3)p2.mVec128;
  return 1;
}
