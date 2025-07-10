char __thiscall btVoronoiSimplexSolver::updateClosestVectorAndPoints(
        btVoronoiSimplexSolver *this,
        btVoronoiSimplexSolver *thisa)
{
  int m_numVertices; // ecx
  const vostok::math::float4x4 *v3; // xmm0_4
  char result; // al
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  const vostok::math::float4x4 *v9; // xmm5_4
  const btUsageBitfield *p_m_usedVertices; // edi
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm7_4
  float v15; // xmm2_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm7_4
  float v22; // xmm5_4
  float v23; // xmm6_4
  float v24; // xmm4_4
  float v25; // xmm0_4
  unsigned __int64 v26; // xmm0_8
  float v27; // xmm0_4
  float v28; // xmm6_4
  float v29; // xmm7_4
  float v30; // xmm4_4
  float v31; // xmm5_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm0_4
  float v35; // xmm6_4
  float v36; // xmm0_4
  float v37; // xmm0_4
  float v38; // xmm7_4
  float v39; // xmm4_4
  float v40; // xmm5_4
  float v41; // xmm6_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm0_4
  float v45; // xmm1_4
  float v46; // xmm2_4
  float v47; // xmm2_4
  btSubSimplexClosestResult *v48; // [esp+20h] [ebp-30h]
  unsigned __int64 v49; // [esp+30h] [ebp-20h]
  unsigned __int64 v50; // [esp+30h] [ebp-20h]
  unsigned __int64 v51; // [esp+30h] [ebp-20h]
  unsigned __int64 v52; // [esp+30h] [ebp-20h]
  unsigned __int64 v53; // [esp+38h] [ebp-18h]
  unsigned int v54; // [esp+38h] [ebp-18h]
  unsigned int v55; // [esp+38h] [ebp-18h]
  unsigned int v56; // [esp+38h] [ebp-18h]
  unsigned int v57; // [esp+38h] [ebp-18h]
  unsigned __int64 v58; // [esp+38h] [ebp-18h]
  float v59; // [esp+38h] [ebp-18h]
  float v60; // [esp+38h] [ebp-18h]
  btVector3 v61; // [esp+40h] [ebp-10h] BYREF

  if ( thisa->m_needsUpdate )
  {
    thisa->m_cachedBC.m_degenerate = 0;
    thisa->m_cachedBC.m_barycentricCoords[0] = 0.0;
    thisa->m_cachedBC.m_barycentricCoords[1] = 0.0;
    thisa->m_cachedBC.m_barycentricCoords[2] = 0.0;
    thisa->m_cachedBC.m_barycentricCoords[3] = 0.0;
    *(_WORD *)&thisa->m_cachedBC.m_usedVertices &= 0xFFF0u;
    m_numVertices = thisa->m_numVertices;
    thisa->m_needsUpdate = 0;
    switch ( m_numVertices )
    {
      case 1:
        thisa->m_cachedP1.mVec128.m128_u64[0] = thisa->m_simplexPointsP[0].mVec128.m128_u64[0];
        thisa->m_cachedP1.mVec128.m128_u64[1] = thisa->m_simplexPointsP[0].mVec128.m128_u64[1];
        thisa->m_cachedP2.mVec128.m128_u64[0] = thisa->m_simplexPointsQ[0].mVec128.m128_u64[0];
        thisa->m_cachedP2.mVec128.m128_u64[1] = thisa->m_simplexPointsQ[0].mVec128.m128_u64[1];
        *(float *)&v49 = thisa->m_cachedP1.mVec128.m128_f32[0] - thisa->m_cachedP2.mVec128.m128_f32[0];
        *((float *)&v49 + 1) = thisa->m_cachedP1.mVec128.m128_f32[1] - thisa->m_cachedP2.mVec128.m128_f32[1];
        *(float *)&v53 = thisa->m_cachedP1.mVec128.m128_f32[2] - thisa->m_cachedP2.mVec128.m128_f32[2];
        thisa->m_cachedV.mVec128.m128_u64[0] = v49;
        HIDWORD(v53) = 0;
        thisa->m_cachedV.mVec128.m128_u64[1] = v53;
        v3 = clear_value;
        thisa->m_cachedBC.m_degenerate = 0;
        thisa->m_cachedBC.m_barycentricCoords[0] = 0.0;
        thisa->m_cachedBC.m_barycentricCoords[1] = 0.0;
        thisa->m_cachedBC.m_barycentricCoords[2] = 0.0;
        thisa->m_cachedBC.m_barycentricCoords[3] = 0.0;
        *(_WORD *)&thisa->m_cachedBC.m_usedVertices &= 0xFFF0u;
        thisa->m_cachedBC.m_barycentricCoords[0] = *(float *)&v3;
        thisa->m_cachedBC.m_barycentricCoords[1] = 0.0;
        thisa->m_cachedBC.m_barycentricCoords[2] = 0.0;
        thisa->m_cachedBC.m_barycentricCoords[3] = 0.0;
        if ( *(float *)&v3 < 0.0 )
          goto LABEL_5;
        result = 1;
        thisa->m_cachedValidClosest = 1;
        return result;
      case 2:
        v5 = thisa->m_simplexVectorW[1].mVec128.m128_f32[0] - thisa->m_simplexVectorW[0].mVec128.m128_f32[0];
        v6 = thisa->m_simplexVectorW[1].mVec128.m128_f32[1] - thisa->m_simplexVectorW[0].mVec128.m128_f32[1];
        v7 = thisa->m_simplexVectorW[1].mVec128.m128_f32[2] - thisa->m_simplexVectorW[0].mVec128.m128_f32[2];
        v8 = (float)((float)(v5 * (float)-thisa->m_simplexVectorW[0].mVec128.m128_f32[0])
                   + (float)(v7 * (float)-thisa->m_simplexVectorW[0].mVec128.m128_f32[2]))
           + (float)(v6 * (float)-thisa->m_simplexVectorW[0].mVec128.m128_f32[1]);
        v9 = clear_value;
        p_m_usedVertices = &thisa->m_cachedBC.m_usedVertices;
        if ( v8 <= 0.0 )
        {
          *(_WORD *)p_m_usedVertices |= 1u;
          v12 = 0.0;
        }
        else
        {
          v11 = (float)((float)(v5 * v5) + (float)(v7 * v7)) + (float)(v6 * v6);
          if ( v11 <= v8 )
          {
            *(_WORD *)p_m_usedVertices |= 2u;
            v12 = *(float *)&v9;
          }
          else
          {
            *(_WORD *)p_m_usedVertices |= 3u;
            v12 = v8 / v11;
          }
        }
        thisa->m_cachedBC.m_barycentricCoords[1] = v12;
        thisa->m_cachedBC.m_barycentricCoords[2] = 0.0;
        thisa->m_cachedBC.m_barycentricCoords[3] = 0.0;
        thisa->m_cachedBC.m_barycentricCoords[0] = *(float *)&v9 - v12;
        *(float *)&v50 = (float)((float)(thisa->m_simplexPointsP[1].mVec128.m128_f32[0]
                                       - thisa->m_simplexPointsP[0].mVec128.m128_f32[0])
                               * v12)
                       + thisa->m_simplexPointsP[0].mVec128.m128_f32[0];
        *((float *)&v50 + 1) = thisa->m_simplexPointsP[0].mVec128.m128_f32[1]
                             + (float)((float)(thisa->m_simplexPointsP[1].mVec128.m128_f32[1]
                                             - thisa->m_simplexPointsP[0].mVec128.m128_f32[1])
                                     * v12);
        *(float *)&v54 = thisa->m_simplexPointsP[0].mVec128.m128_f32[2]
                       + (float)((float)(thisa->m_simplexPointsP[1].mVec128.m128_f32[2]
                                       - thisa->m_simplexPointsP[0].mVec128.m128_f32[2])
                               * v12);
        thisa->m_cachedP1.mVec128.m128_u64[0] = v50;
        thisa->m_cachedP1.mVec128.m128_u64[1] = v54;
        *((float *)&v50 + 1) = thisa->m_simplexPointsQ[0].mVec128.m128_f32[1]
                             + (float)((float)(thisa->m_simplexPointsQ[1].mVec128.m128_f32[1]
                                             - thisa->m_simplexPointsQ[0].mVec128.m128_f32[1])
                                     * v12);
        *(float *)&v55 = thisa->m_simplexPointsQ[0].mVec128.m128_f32[2]
                       + (float)((float)(thisa->m_simplexPointsQ[1].mVec128.m128_f32[2]
                                       - thisa->m_simplexPointsQ[0].mVec128.m128_f32[2])
                               * v12);
        *(float *)&v50 = (float)((float)(thisa->m_simplexPointsQ[1].mVec128.m128_f32[0]
                                       - thisa->m_simplexPointsQ[0].mVec128.m128_f32[0])
                               * v12)
                       + thisa->m_simplexPointsQ[0].mVec128.m128_f32[0];
        thisa->m_cachedP2.mVec128.m128_u64[0] = v50;
        thisa->m_cachedP2.mVec128.m128_u64[1] = v55;
        *(float *)&v50 = thisa->m_cachedP1.mVec128.m128_f32[0] - thisa->m_cachedP2.mVec128.m128_f32[0];
        *((float *)&v50 + 1) = thisa->m_cachedP1.mVec128.m128_f32[1] - thisa->m_cachedP2.mVec128.m128_f32[1];
        *(float *)&v56 = thisa->m_cachedP1.mVec128.m128_f32[2] - thisa->m_cachedP2.mVec128.m128_f32[2];
        thisa->m_cachedV.mVec128.m128_u64[0] = v50;
        thisa->m_cachedV.mVec128.m128_u64[1] = v56;
        btVoronoiSimplexSolver::reduceVertices(thisa, p_m_usedVertices);
        if ( thisa->m_cachedBC.m_barycentricCoords[0] < 0.0
          || thisa->m_cachedBC.m_barycentricCoords[1] < 0.0
          || thisa->m_cachedBC.m_barycentricCoords[2] < 0.0
          || thisa->m_cachedBC.m_barycentricCoords[3] < 0.0 )
        {
          goto LABEL_5;
        }
        result = 1;
        goto LABEL_6;
      case 3:
        memset(&v61, 0, sizeof(v61));
        btVoronoiSimplexSolver::closestPtPointTriangle(
          &v61,
          &thisa->m_simplexVectorW[1],
          &thisa->m_simplexVectorW[2],
          &thisa->m_cachedBC,
          (btVoronoiSimplexSolver *)thisa->m_simplexVectorW,
          &v48->m_closestPointOnSimplex);
        v13 = thisa->m_cachedBC.m_barycentricCoords[2];
        v14 = thisa->m_cachedBC.m_barycentricCoords[0];
        v15 = thisa->m_simplexPointsP[0].mVec128.m128_f32[2];
        v16 = thisa->m_simplexPointsP[2].mVec128.m128_f32[1] * v13;
        v17 = thisa->m_simplexPointsP[2].mVec128.m128_f32[2] * v13;
        v18 = thisa->m_simplexPointsP[2].mVec128.m128_f32[0] * v13;
        v19 = thisa->m_cachedBC.m_barycentricCoords[1];
        v61.mVec128.m128_f32[1] = thisa->m_simplexPointsP[1].mVec128.m128_f32[1] * v19;
        v61.mVec128.m128_f32[2] = thisa->m_simplexPointsP[1].mVec128.m128_f32[2] * v19;
        *((float *)&v51 + 1) = (float)((float)(thisa->m_simplexPointsP[0].mVec128.m128_f32[1] * v14)
                                     + v61.mVec128.m128_f32[1])
                             + v16;
        *(float *)&v51 = (float)((float)(thisa->m_simplexPointsP[0].mVec128.m128_f32[0] * v14)
                               + (float)(v19 * thisa->m_simplexPointsP[1].mVec128.m128_f32[0]))
                       + v18;
        thisa->m_cachedP1.mVec128.m128_u64[0] = v51;
        thisa->m_cachedP1.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT((float)((float)(v15 * v14) + v61.mVec128.m128_f32[2]) + v17);
        v20 = thisa->m_cachedBC.m_barycentricCoords[2];
        v21 = thisa->m_cachedBC.m_barycentricCoords[0];
        v22 = thisa->m_simplexPointsQ[2].mVec128.m128_f32[1] * v20;
        v23 = thisa->m_simplexPointsQ[2].mVec128.m128_f32[2] * v20;
        v24 = thisa->m_simplexPointsQ[2].mVec128.m128_f32[0] * v20;
        v25 = thisa->m_cachedBC.m_barycentricCoords[1];
        *(float *)&v51 = (float)((float)(v21 * thisa->m_simplexPointsQ[0].mVec128.m128_f32[0])
                               + (float)(v25 * thisa->m_simplexPointsQ[1].mVec128.m128_f32[0]))
                       + v24;
        *((float *)&v51 + 1) = (float)((float)(thisa->m_simplexPointsQ[0].mVec128.m128_f32[1] * v21)
                                     + (float)(thisa->m_simplexPointsQ[1].mVec128.m128_f32[1] * v25))
                             + v22;
        *(float *)&v57 = (float)((float)(thisa->m_simplexPointsQ[0].mVec128.m128_f32[2] * v21)
                               + (float)(thisa->m_simplexPointsQ[1].mVec128.m128_f32[2] * v25))
                       + v23;
        thisa->m_cachedP2.mVec128.m128_u64[0] = v51;
        thisa->m_cachedP2.mVec128.m128_u64[1] = v57;
        *(float *)&v51 = thisa->m_cachedP1.mVec128.m128_f32[0] - thisa->m_cachedP2.mVec128.m128_f32[0];
        *((float *)&v51 + 1) = thisa->m_cachedP1.mVec128.m128_f32[1] - thisa->m_cachedP2.mVec128.m128_f32[1];
        *(float *)&v58 = thisa->m_cachedP1.mVec128.m128_f32[2] - thisa->m_cachedP2.mVec128.m128_f32[2];
        HIDWORD(v58) = 0;
        thisa->m_cachedV.mVec128.m128_u64[0] = v51;
        v26 = v58;
        goto LABEL_18;
      case 4:
        memset(&v61, 0, sizeof(v61));
        if ( btVoronoiSimplexSolver::closestPtPointTetrahedron(
               &v61,
               (btVoronoiSimplexSolver *)thisa->m_simplexVectorW,
               &thisa->m_simplexVectorW[1],
               &thisa->m_simplexVectorW[2],
               &thisa->m_simplexVectorW[3],
               &thisa->m_cachedBC,
               v48) )
        {
          v27 = thisa->m_cachedBC.m_barycentricCoords[3];
          v28 = thisa->m_simplexPointsP[2].mVec128.m128_f32[0];
          v29 = thisa->m_cachedBC.m_barycentricCoords[0];
          v30 = thisa->m_simplexPointsP[3].mVec128.m128_f32[1] * v27;
          v31 = thisa->m_simplexPointsP[3].mVec128.m128_f32[2] * v27;
          v32 = thisa->m_simplexPointsP[0].mVec128.m128_f32[2];
          v33 = v27;
          v34 = thisa->m_cachedBC.m_barycentricCoords[2];
          v61.mVec128.m128_f32[1] = thisa->m_simplexPointsP[2].mVec128.m128_f32[1] * v34;
          v61.mVec128.m128_f32[2] = thisa->m_simplexPointsP[2].mVec128.m128_f32[2] * v34;
          v35 = v28 * v34;
          v36 = thisa->m_cachedBC.m_barycentricCoords[1];
          v59 = thisa->m_simplexPointsP[1].mVec128.m128_f32[2] * v36;
          *((float *)&v52 + 1) = (float)((float)((float)(thisa->m_simplexPointsP[0].mVec128.m128_f32[1] * v29)
                                               + (float)(thisa->m_simplexPointsP[1].mVec128.m128_f32[1] * v36))
                                       + v61.mVec128.m128_f32[1])
                               + v30;
          *(float *)&v52 = (float)((float)((float)(v29 * thisa->m_simplexPointsP[0].mVec128.m128_f32[0])
                                         + (float)(v36 * thisa->m_simplexPointsP[1].mVec128.m128_f32[0]))
                                 + v35)
                         + (float)(v33 * thisa->m_simplexPointsP[3].mVec128.m128_f32[0]);
          thisa->m_cachedP1.mVec128.m128_u64[0] = v52;
          thisa->m_cachedP1.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                                                    (float)((float)((float)(v32 * v29) + v59) + v61.mVec128.m128_f32[2])
                                                  + v31);
          v37 = thisa->m_cachedBC.m_barycentricCoords[3];
          v38 = thisa->m_cachedBC.m_barycentricCoords[0];
          v39 = v37 * thisa->m_simplexPointsQ[3].mVec128.m128_f32[0];
          v40 = thisa->m_simplexPointsQ[3].mVec128.m128_f32[1] * v37;
          v41 = thisa->m_simplexPointsQ[3].mVec128.m128_f32[2] * v37;
          v42 = thisa->m_cachedBC.m_barycentricCoords[2];
          v61.mVec128.m128_f32[0] = v42 * thisa->m_simplexPointsQ[2].mVec128.m128_f32[0];
          v61.mVec128.m128_f32[1] = thisa->m_simplexPointsQ[2].mVec128.m128_f32[1] * v42;
          v43 = thisa->m_simplexPointsQ[2].mVec128.m128_f32[2] * v42;
          v44 = thisa->m_cachedBC.m_barycentricCoords[1];
          v61.mVec128.m128_f32[2] = v43;
          *((float *)&v52 + 1) = thisa->m_simplexPointsQ[1].mVec128.m128_f32[1] * v44;
          v60 = thisa->m_simplexPointsQ[1].mVec128.m128_f32[2] * v44;
          v45 = thisa->m_simplexPointsQ[0].mVec128.m128_f32[1];
          v46 = thisa->m_simplexPointsQ[0].mVec128.m128_f32[2];
          v61.mVec128.m128_f32[0] = (float)((float)((float)(thisa->m_simplexPointsQ[0].mVec128.m128_f32[0] * v38)
                                                  + (float)(v44 * thisa->m_simplexPointsQ[1].mVec128.m128_f32[0]))
                                          + v61.mVec128.m128_f32[0])
                                  + v39;
          v47 = (float)((float)(v46 * v38) + v60) + v61.mVec128.m128_f32[2];
          v61.mVec128.m128_f32[1] = (float)((float)((float)(v45 * v38) + *((float *)&v52 + 1)) + v61.mVec128.m128_f32[1])
                                  + v40;
          thisa->m_cachedP2.mVec128.m128_u64[0] = v61.mVec128.m128_u64[0];
          v61.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v47 + v41);
          thisa->m_cachedP2.mVec128.m128_u64[1] = v61.mVec128.m128_u64[1];
          v61.mVec128.m128_f32[0] = thisa->m_cachedP1.mVec128.m128_f32[0] - thisa->m_cachedP2.mVec128.m128_f32[0];
          v61.mVec128.m128_f32[1] = thisa->m_cachedP1.mVec128.m128_f32[1] - thisa->m_cachedP2.mVec128.m128_f32[1];
          v61.mVec128.m128_f32[2] = thisa->m_cachedP1.mVec128.m128_f32[2] - thisa->m_cachedP2.mVec128.m128_f32[2];
          v61.mVec128.m128_i32[3] = 0;
          thisa->m_cachedV.mVec128.m128_u64[0] = v61.mVec128.m128_u64[0];
          v26 = v61.mVec128.m128_u64[1];
LABEL_18:
          thisa->m_cachedV.mVec128.m128_u64[1] = v26;
          btVoronoiSimplexSolver::reduceVertices(thisa, &thisa->m_cachedBC.m_usedVertices);
          if ( thisa->m_cachedBC.m_barycentricCoords[0] < 0.0
            || thisa->m_cachedBC.m_barycentricCoords[1] < 0.0
            || thisa->m_cachedBC.m_barycentricCoords[2] < 0.0
            || thisa->m_cachedBC.m_barycentricCoords[3] < 0.0 )
          {
LABEL_5:
            result = 0;
          }
          else
          {
            result = 1;
          }
LABEL_6:
          thisa->m_cachedValidClosest = result;
          return result;
        }
        if ( !thisa->m_cachedBC.m_degenerate )
        {
          thisa->m_cachedValidClosest = 1;
          thisa->m_cachedV.mVec128.m128_i32[0] = 0;
          thisa->m_cachedV.mVec128.m128_i32[1] = 0;
          thisa->m_cachedV.mVec128.m128_i32[2] = 0;
          thisa->m_cachedV.mVec128.m128_i32[3] = 0;
          return thisa->m_cachedValidClosest;
        }
$LN1_44:
        thisa->m_cachedValidClosest = 0;
        break;
      default:
        goto $LN1_44;
    }
  }
  return thisa->m_cachedValidClosest;
}
