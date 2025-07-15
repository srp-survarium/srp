bool __thiscall btVoronoiSimplexSolver::updateClosestVectorAndPoints(
        btVoronoiSimplexSolver *this,
        btVoronoiSimplexSolver *a2)
{
  btSubSimplexClosestResult *p_m_cachedBC; // eax
  int m_numVertices; // ecx
  bool v4; // zf
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm7_4
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm3_4
  float v14; // xmm6_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float *m128_f32; // eax
  float v21; // xmm2_4
  float v22; // xmm4_4
  float v23; // xmm5_4
  float v24; // xmm6_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  float v27; // xmm2_4
  float v28; // xmm6_4
  float v29; // xmm2_4
  float v30; // xmm7_4
  unsigned int v31; // xmm2_4
  unsigned int v32; // xmm3_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm7_4
  float v36; // xmm2_4
  float v37; // xmm4_4
  float v38; // xmm5_4
  float v39; // xmm3_4
  float v40; // xmm6_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm0_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm7_4
  float v47; // xmm4_4
  float v48; // xmm5_4
  float v49; // xmm6_4
  float v50; // xmm1_4
  float v51; // xmm2_4
  float v52; // xmm1_4
  const btUsageBitfield *v53; // esi
  float v54; // xmm3_4
  float v55; // xmm4_4
  float v56; // xmm5_4
  float v57; // xmm1_4
  float v58; // xmm2_4
  int *p_m_usedVertices; // edx
  float v60; // xmm3_4
  float v61; // xmm4_4
  float v62; // xmm2_4
  float v63; // xmm3_4
  float v64; // xmm1_4
  float v65; // xmm2_4
  float v66; // xmm3_4
  float v67; // xmm1_4
  int v68; // xmm1_4
  bool v69; // al
  const btVector3 *v71; // [esp+0h] [ebp-40h]
  btVector3 p; // [esp+10h] [ebp-30h] BYREF
  float v73; // [esp+20h] [ebp-20h]
  float v74; // [esp+24h] [ebp-1Ch]
  float v75; // [esp+28h] [ebp-18h]
  float v76; // [esp+30h] [ebp-10h]

  if ( !a2->m_needsUpdate )
    return a2->m_cachedValidClosest;
  p_m_cachedBC = &a2->m_cachedBC;
  a2->m_cachedBC.m_degenerate = 0;
  a2->m_cachedBC.m_barycentricCoords[0] = 0.0;
  a2->m_cachedBC.m_barycentricCoords[1] = 0.0;
  a2->m_cachedBC.m_barycentricCoords[2] = 0.0;
  a2->m_cachedBC.m_barycentricCoords[3] = 0.0;
  *(_WORD *)&a2->m_cachedBC.m_usedVertices &= 0xFFF0u;
  m_numVertices = a2->m_numVertices;
  v4 = a2->m_numVertices == 0;
  a2->m_needsUpdate = 0;
  if ( v4 )
    goto LABEL_28;
  v5 = m_numVertices - 1;
  if ( v5 )
  {
    v6 = v5 - 1;
    if ( !v6 )
    {
      v54 = a2->m_simplexVectorW[1].mVec128.m128_f32[0] - a2->m_simplexVectorW[0].mVec128.m128_f32[0];
      v55 = a2->m_simplexVectorW[1].mVec128.m128_f32[1] - a2->m_simplexVectorW[0].mVec128.m128_f32[1];
      v56 = a2->m_simplexVectorW[1].mVec128.m128_f32[2] - a2->m_simplexVectorW[0].mVec128.m128_f32[2];
      v57 = (float)((float)(v54 * COERCE_FLOAT(a2->m_simplexVectorW[0].mVec128.m128_i32[0] ^ _mask__NegFloat_))
                  + (float)(v56 * COERCE_FLOAT(a2->m_simplexVectorW[0].mVec128.m128_i32[2] ^ _mask__NegFloat_)))
          + (float)(v55 * COERCE_FLOAT(a2->m_simplexVectorW[0].mVec128.m128_i32[1] ^ _mask__NegFloat_));
      v58 = s_bm_current_air_resistance;
      p_m_usedVertices = (int *)&a2->m_cachedBC.m_usedVertices;
      if ( v57 <= 0.0 )
      {
        *(_WORD *)p_m_usedVertices |= 1u;
        v61 = 0.0;
      }
      else
      {
        v60 = (float)((float)(v54 * v54) + (float)(v56 * v56)) + (float)(v55 * v55);
        if ( v60 <= v57 )
        {
          *(_WORD *)p_m_usedVertices |= 2u;
          v61 = v58;
        }
        else
        {
          *(_WORD *)p_m_usedVertices |= 3u;
          v61 = v57 / v60;
        }
      }
      a2->m_cachedBC.m_barycentricCoords[1] = v61;
      a2->m_cachedBC.m_barycentricCoords[2] = 0.0;
      a2->m_cachedBC.m_barycentricCoords[3] = 0.0;
      a2->m_cachedBC.m_barycentricCoords[0] = v58 - v61;
      v62 = a2->m_simplexPointsP[1].mVec128.m128_f32[1] - a2->m_simplexPointsP[0].mVec128.m128_f32[1];
      v63 = a2->m_simplexPointsP[1].mVec128.m128_f32[2] - a2->m_simplexPointsP[0].mVec128.m128_f32[2];
      p.mVec128.m128_f32[0] = (float)((float)(a2->m_simplexPointsP[1].mVec128.m128_f32[0]
                                            - a2->m_simplexPointsP[0].mVec128.m128_f32[0])
                                    * v61)
                            + a2->m_simplexPointsP[0].mVec128.m128_f32[0];
      v64 = a2->m_simplexPointsP[0].mVec128.m128_f32[1];
      p.mVec128.m128_i32[3] = 0;
      p.mVec128.m128_f32[1] = v64 + (float)(v62 * v61);
      p.mVec128.m128_f32[2] = a2->m_simplexPointsP[0].mVec128.m128_f32[2] + (float)(v63 * v61);
      a2->m_cachedP1 = (btVector3)p.mVec128;
      v65 = a2->m_simplexPointsQ[1].mVec128.m128_f32[1] - a2->m_simplexPointsQ[0].mVec128.m128_f32[1];
      v66 = a2->m_simplexPointsQ[1].mVec128.m128_f32[2] - a2->m_simplexPointsQ[0].mVec128.m128_f32[2];
      p.mVec128.m128_f32[0] = (float)((float)(a2->m_simplexPointsQ[1].mVec128.m128_f32[0]
                                            - a2->m_simplexPointsQ[0].mVec128.m128_f32[0])
                                    * v61)
                            + a2->m_simplexPointsQ[0].mVec128.m128_f32[0];
      v67 = a2->m_simplexPointsQ[0].mVec128.m128_f32[1];
      p.mVec128.m128_i32[3] = 0;
      p.mVec128.m128_f32[1] = v67 + (float)(v65 * v61);
      p.mVec128.m128_f32[2] = a2->m_simplexPointsQ[0].mVec128.m128_f32[2] + (float)(v66 * v61);
      a2->m_cachedP2 = (btVector3)p.mVec128;
      p.mVec128.m128_f32[0] = a2->m_cachedP1.mVec128.m128_f32[0] - a2->m_cachedP2.mVec128.m128_f32[0];
      p.mVec128.m128_f32[1] = a2->m_cachedP1.mVec128.m128_f32[1] - a2->m_cachedP2.mVec128.m128_f32[1];
      p.mVec128.m128_f32[2] = a2->m_cachedP1.mVec128.m128_f32[2] - a2->m_cachedP2.mVec128.m128_f32[2];
      p.mVec128.m128_i32[3] = 0;
      a2->m_cachedV = (btVector3)p.mVec128;
      v53 = &a2->m_cachedBC.m_usedVertices;
      goto LABEL_19;
    }
    v7 = v6 - 1;
    if ( !v7 )
    {
      memset(&p, 0, sizeof(p));
      btVoronoiSimplexSolver::closestPtPointTriangle(
        &a2->m_simplexVectorW[1],
        p_m_cachedBC,
        (btVoronoiSimplexSolver *)&p,
        a2->m_simplexVectorW,
        &a2->m_simplexVectorW[2],
        v71);
      v33 = a2->m_cachedBC.m_barycentricCoords[2];
      v34 = a2->m_cachedBC.m_barycentricCoords[1];
      v35 = a2->m_cachedBC.m_barycentricCoords[0];
      v36 = a2->m_simplexPointsP[0].mVec128.m128_f32[2];
      v37 = a2->m_simplexPointsP[2].mVec128.m128_f32[1] * v33;
      v38 = a2->m_simplexPointsP[2].mVec128.m128_f32[2] * v33;
      v39 = a2->m_simplexPointsP[2].mVec128.m128_f32[0] * v33;
      v40 = a2->m_simplexPointsP[1].mVec128.m128_f32[1] * v34;
      v73 = v34 * a2->m_simplexPointsP[1].mVec128.m128_f32[0];
      v41 = a2->m_simplexPointsP[1].mVec128.m128_f32[2] * v34;
      v42 = (float)(a2->m_simplexPointsP[0].mVec128.m128_f32[1] * v35) + v40;
      v75 = v41;
      v43 = a2->m_simplexPointsP[0].mVec128.m128_f32[0];
      p.mVec128.m128_f32[1] = v42 + v37;
      p.mVec128.m128_f32[0] = (float)((float)(v43 * v35) + v73) + v39;
      p.mVec128.m128_f32[2] = (float)((float)(v36 * v35) + v75) + v38;
      p.mVec128.m128_i32[3] = 0;
      m128_f32 = a2->m_cachedP1.mVec128.m128_f32;
      a2->m_cachedP1 = (btVector3)p.mVec128;
      v44 = a2->m_cachedBC.m_barycentricCoords[2];
      v45 = a2->m_cachedBC.m_barycentricCoords[1];
      v46 = a2->m_cachedBC.m_barycentricCoords[0];
      v47 = a2->m_simplexPointsQ[2].mVec128.m128_f32[0] * v44;
      v48 = a2->m_simplexPointsQ[2].mVec128.m128_f32[1] * v44;
      v49 = a2->m_simplexPointsQ[2].mVec128.m128_f32[2] * v44;
      p.mVec128.m128_f32[0] = v45 * a2->m_simplexPointsQ[1].mVec128.m128_f32[0];
      p.mVec128.m128_f32[1] = a2->m_simplexPointsQ[1].mVec128.m128_f32[1] * v45;
      v50 = a2->m_simplexPointsQ[1].mVec128.m128_f32[2] * v45;
      v51 = a2->m_simplexPointsQ[0].mVec128.m128_f32[2];
      p.mVec128.m128_f32[2] = v50;
      v52 = (float)((float)(a2->m_simplexPointsQ[0].mVec128.m128_f32[1] * v46) + p.mVec128.m128_f32[1]) + v48;
      p.mVec128.m128_f32[0] = (float)((float)(v46 * a2->m_simplexPointsQ[0].mVec128.m128_f32[0]) + p.mVec128.m128_f32[0])
                            + v47;
      p.mVec128.m128_f32[1] = v52;
      p.mVec128.m128_f32[2] = (float)((float)(v51 * v46) + p.mVec128.m128_f32[2]) + v49;
      goto LABEL_12;
    }
    if ( v7 == 1 )
    {
      memset(&p, 0, sizeof(p));
      if ( btVoronoiSimplexSolver::closestPtPointTetrahedron(
             0,
             &p,
             (btVoronoiSimplexSolver *)a2->m_simplexVectorW,
             &a2->m_simplexVectorW[1],
             &a2->m_simplexVectorW[2],
             &a2->m_simplexVectorW[3],
             &a2->m_cachedBC) )
      {
        v8 = a2->m_cachedBC.m_barycentricCoords[3];
        v9 = a2->m_cachedBC.m_barycentricCoords[2];
        v10 = a2->m_cachedBC.m_barycentricCoords[0];
        v11 = a2->m_simplexPointsP[3].mVec128.m128_f32[2] * v8;
        v12 = a2->m_simplexPointsP[3].mVec128.m128_f32[1] * v8;
        v13 = a2->m_simplexPointsP[3].mVec128.m128_f32[0] * v8;
        v14 = a2->m_simplexPointsP[2].mVec128.m128_f32[0] * v9;
        v74 = a2->m_simplexPointsP[2].mVec128.m128_f32[1] * v9;
        v15 = a2->m_simplexPointsP[2].mVec128.m128_f32[2] * v9;
        v16 = a2->m_cachedBC.m_barycentricCoords[1];
        v75 = v15;
        p.mVec128.m128_f32[0] = a2->m_simplexPointsP[1].mVec128.m128_f32[0] * v16;
        p.mVec128.m128_f32[1] = a2->m_simplexPointsP[1].mVec128.m128_f32[1] * v16;
        v17 = a2->m_simplexPointsP[1].mVec128.m128_f32[2] * v16;
        v18 = a2->m_simplexPointsP[0].mVec128.m128_f32[2];
        p.mVec128.m128_f32[2] = v17;
        v19 = a2->m_simplexPointsP[0].mVec128.m128_f32[1];
        p.mVec128.m128_f32[2] = (float)((float)((float)(v18 * v10) + p.mVec128.m128_f32[2]) + v75) + v11;
        p.mVec128.m128_f32[1] = (float)((float)((float)(v19 * v10) + p.mVec128.m128_f32[1]) + v74) + v12;
        p.mVec128.m128_f32[0] = (float)((float)((float)(v10 * a2->m_simplexPointsP[0].mVec128.m128_f32[0])
                                              + p.mVec128.m128_f32[0])
                                      + v14)
                              + v13;
        p.mVec128.m128_i32[3] = 0;
        m128_f32 = a2->m_cachedP1.mVec128.m128_f32;
        a2->m_cachedP1 = (btVector3)p.mVec128;
        v21 = a2->m_cachedBC.m_barycentricCoords[3];
        v22 = a2->m_simplexPointsQ[3].mVec128.m128_f32[1];
        v23 = a2->m_simplexPointsQ[3].mVec128.m128_f32[2];
        v76 = v21 * a2->m_simplexPointsQ[3].mVec128.m128_f32[0];
        v24 = a2->m_simplexPointsQ[2].mVec128.m128_f32[1];
        v25 = v22 * v21;
        v26 = v23 * v21;
        v27 = a2->m_cachedBC.m_barycentricCoords[2];
        v73 = v27 * a2->m_simplexPointsQ[2].mVec128.m128_f32[0];
        v75 = a2->m_simplexPointsQ[2].mVec128.m128_f32[2] * v27;
        v28 = v24 * v27;
        v29 = a2->m_cachedBC.m_barycentricCoords[1];
        p.mVec128.m128_f32[0] = v29 * a2->m_simplexPointsQ[1].mVec128.m128_f32[0];
        v30 = a2->m_cachedBC.m_barycentricCoords[0];
        p.mVec128.m128_f32[1] = a2->m_simplexPointsQ[1].mVec128.m128_f32[1] * v29;
        p.mVec128.m128_f32[2] = a2->m_simplexPointsQ[1].mVec128.m128_f32[2] * v29;
        *(float *)&v31 = (float)((float)((float)(a2->m_simplexPointsQ[0].mVec128.m128_f32[1] * v30)
                                       + p.mVec128.m128_f32[1])
                               + v28)
                       + v25;
        *(float *)&v32 = (float)((float)((float)(a2->m_simplexPointsQ[0].mVec128.m128_f32[2] * v30)
                                       + p.mVec128.m128_f32[2])
                               + v75)
                       + v26;
        p.mVec128.m128_f32[0] = (float)((float)((float)(a2->m_simplexPointsQ[0].mVec128.m128_f32[0] * v30)
                                              + p.mVec128.m128_f32[0])
                                      + v73)
                              + v76;
        *(unsigned __int64 *)((char *)p.mVec128.m128_u64 + 4) = __PAIR64__(v32, v31);
LABEL_12:
        p.mVec128.m128_i32[3] = 0;
        a2->m_cachedP2 = (btVector3)p.mVec128;
        p.mVec128.m128_f32[0] = *m128_f32 - a2->m_cachedP2.mVec128.m128_f32[0];
        p.mVec128.m128_f32[1] = m128_f32[1] - a2->m_cachedP2.mVec128.m128_f32[1];
        p.mVec128.m128_f32[2] = m128_f32[2] - a2->m_cachedP2.mVec128.m128_f32[2];
        p.mVec128.m128_i32[3] = 0;
        a2->m_cachedV = (btVector3)p.mVec128;
        v53 = &a2->m_cachedBC.m_usedVertices;
LABEL_19:
        btVoronoiSimplexSolver::reduceVertices(a2, v53);
        p_m_cachedBC = &a2->m_cachedBC;
        goto LABEL_21;
      }
      if ( !a2->m_cachedBC.m_degenerate )
      {
        a2->m_cachedValidClosest = 1;
        a2->m_cachedV.mVec128.m128_i32[0] = 0;
        a2->m_cachedV.mVec128.m128_i32[1] = 0;
        a2->m_cachedV.mVec128.m128_i32[2] = 0;
        a2->m_cachedV.mVec128.m128_i32[3] = 0;
        return a2->m_cachedValidClosest;
      }
    }
LABEL_28:
    a2->m_cachedValidClosest = 0;
    return a2->m_cachedValidClosest;
  }
  a2->m_cachedP1.mVec128.m128_i32[0] = a2->m_simplexPointsP[0].mVec128.m128_i32[0];
  a2->m_cachedP1.mVec128.m128_i32[1] = a2->m_simplexPointsP[0].mVec128.m128_i32[1];
  a2->m_cachedP1.mVec128.m128_i32[2] = a2->m_simplexPointsP[0].mVec128.m128_i32[2];
  a2->m_cachedP1.mVec128.m128_i32[3] = a2->m_simplexPointsP[0].mVec128.m128_i32[3];
  a2->m_cachedP2.mVec128.m128_i32[0] = a2->m_simplexPointsQ[0].mVec128.m128_i32[0];
  a2->m_cachedP2.mVec128.m128_i32[1] = a2->m_simplexPointsQ[0].mVec128.m128_i32[1];
  a2->m_cachedP2.mVec128.m128_i32[2] = a2->m_simplexPointsQ[0].mVec128.m128_i32[2];
  a2->m_cachedP2.mVec128.m128_i32[3] = a2->m_simplexPointsQ[0].mVec128.m128_i32[3];
  p.mVec128.m128_f32[0] = a2->m_cachedP1.mVec128.m128_f32[0] - a2->m_cachedP2.mVec128.m128_f32[0];
  p.mVec128.m128_f32[1] = a2->m_cachedP1.mVec128.m128_f32[1] - a2->m_cachedP2.mVec128.m128_f32[1];
  p.mVec128.m128_f32[2] = a2->m_cachedP1.mVec128.m128_f32[2] - a2->m_cachedP2.mVec128.m128_f32[2];
  v68 = LODWORD(s_bm_current_air_resistance);
  p.mVec128.m128_i32[3] = 0;
  a2->m_cachedV = (btVector3)p.mVec128;
  a2->m_cachedBC.m_degenerate = 0;
  a2->m_cachedBC.m_barycentricCoords[0] = 0.0;
  a2->m_cachedBC.m_barycentricCoords[1] = 0.0;
  a2->m_cachedBC.m_barycentricCoords[2] = 0.0;
  a2->m_cachedBC.m_barycentricCoords[3] = 0.0;
  *(_WORD *)&a2->m_cachedBC.m_usedVertices &= 0xFFF0u;
  LODWORD(a2->m_cachedBC.m_barycentricCoords[0]) = v68;
  a2->m_cachedBC.m_barycentricCoords[1] = 0.0;
  a2->m_cachedBC.m_barycentricCoords[2] = 0.0;
  a2->m_cachedBC.m_barycentricCoords[3] = 0.0;
LABEL_21:
  v69 = p_m_cachedBC->m_barycentricCoords[0] >= 0.0
     && p_m_cachedBC->m_barycentricCoords[1] >= 0.0
     && p_m_cachedBC->m_barycentricCoords[2] >= 0.0
     && p_m_cachedBC->m_barycentricCoords[3] >= 0.0;
  a2->m_cachedValidClosest = v69;
  return a2->m_cachedValidClosest;
}
