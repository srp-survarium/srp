char __thiscall btVoronoiSimplexSolver::closestPtPointTetrahedron(
        btVoronoiSimplexSolver *this,
        btVector3 *p,
        btVoronoiSimplexSolver *a,
        const btVector3 *b,
        const btVector3 *c,
        const btVector3 *d,
        btSubSimplexClosestResult *finalResult)
{
  btVoronoiSimplexSolver *v7; // edx
  int v8; // eax
  const btVector3 *v9; // edx
  const btVector3 *v10; // ecx
  btVector3 *v11; // esi
  float v12; // xmm2_4
  float v13; // xmm0_4
  char v14; // al
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  __int16 v18; // cx
  btUsageBitfield m_usedVertices; // ax
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  int v23; // ecx
  btUsageBitfield v24; // ax
  float v25; // xmm0_4
  __int16 v26; // cx
  btUsageBitfield v27; // ax
  float v28; // xmm0_4
  const btVector3 *v30; // [esp+0h] [ebp-50h]
  const btVector3 *v31; // [esp+0h] [ebp-50h]
  const btVector3 *v32; // [esp+0h] [ebp-50h]
  const btVector3 *v33; // [esp+0h] [ebp-50h]
  const btVector3 *v34; // [esp+0h] [ebp-50h]
  float v35; // [esp+Ch] [ebp-44h]
  int v36; // [esp+10h] [ebp-40h]
  int v37; // [esp+14h] [ebp-3Ch]
  int v38; // [esp+18h] [ebp-38h]
  int v39; // [esp+1Ch] [ebp-34h]
  btSubSimplexClosestResult v40; // [esp+20h] [ebp-30h] BYREF

  finalResult->m_closestPointOnSimplex.mVec128.m128_u64[0] = p->mVec128.m128_u64[0];
  *(_WORD *)&v40.m_usedVertices &= 0xFFFCu;
  finalResult->m_closestPointOnSimplex.mVec128.m128_i32[2] = p->mVec128.m128_i32[2];
  *(_WORD *)&v40.m_usedVertices &= 0xFFF3u;
  finalResult->m_closestPointOnSimplex.mVec128.m128_i32[3] = p->mVec128.m128_i32[3];
  *(_WORD *)&finalResult->m_usedVertices &= 0xFFF0u;
  *(_WORD *)&finalResult->m_usedVertices |= 0xFu;
  v36 = btVoronoiSimplexSolver::pointOutsideOfPlane(p, b, c, d, a, v30);
  v37 = btVoronoiSimplexSolver::pointOutsideOfPlane(p, c, d, b, a, v31);
  v38 = btVoronoiSimplexSolver::pointOutsideOfPlane(p, d, b, c, a, v32);
  v8 = btVoronoiSimplexSolver::pointOutsideOfPlane(p, d, c, (const btVector3 *)a, v7, v33);
  v39 = v8;
  if ( v36 < 0 || v37 < 0 || v38 < 0 || v8 < 0 )
  {
    finalResult->m_degenerate = 1;
    return 0;
  }
  if ( !v36 && !v37 && !v38 && !v8 )
    return 0;
  v11 = p;
  v35 = FLOAT_3_4028235e38;
  if ( v36 )
  {
    btVoronoiSimplexSolver::closestPtPointTriangle(b, &v40, (btVoronoiSimplexSolver *)p, v10, v9, v34);
    v12 = (float)((float)((float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[2] - p->mVec128.m128_f32[2])
                        * (float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[2] - p->mVec128.m128_f32[2]))
                + (float)((float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[1] - p->mVec128.m128_f32[1])
                        * (float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[1] - p->mVec128.m128_f32[1])))
        + (float)((float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[0] - p->mVec128.m128_f32[0])
                * (float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[0] - p->mVec128.m128_f32[0]));
    if ( v12 < 3.4028235e38 )
    {
      v13 = v40.m_barycentricCoords[0];
      finalResult->m_closestPointOnSimplex.mVec128.m128_u64[0] = v40.m_closestPointOnSimplex.mVec128.m128_u64[0];
      finalResult->m_closestPointOnSimplex.mVec128.m128_u64[1] = v40.m_closestPointOnSimplex.mVec128.m128_u64[1];
      v11 = p;
      *(_WORD *)&finalResult->m_usedVertices &= 0xFFF0u;
      v14 = *(_BYTE *)&v40.m_usedVertices ^ *(_WORD *)&finalResult->m_usedVertices;
      finalResult->m_barycentricCoords[0] = v13;
      finalResult->m_barycentricCoords[1] = v40.m_barycentricCoords[1];
      v15 = v40.m_barycentricCoords[2];
      *(_WORD *)&finalResult->m_usedVertices ^= v14 & 7;
      finalResult->m_barycentricCoords[2] = v15;
      v35 = v12;
      finalResult->m_barycentricCoords[3] = 0.0;
    }
  }
  if ( v37 )
  {
    btVoronoiSimplexSolver::closestPtPointTriangle(c, &v40, (btVoronoiSimplexSolver *)v11, (const btVector3 *)a, d, v34);
    v16 = (float)((float)((float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[2] - v11->mVec128.m128_f32[2])
                        * (float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[2] - v11->mVec128.m128_f32[2]))
                + (float)((float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[1] - v11->mVec128.m128_f32[1])
                        * (float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[1] - v11->mVec128.m128_f32[1])))
        + (float)((float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[0] - v11->mVec128.m128_f32[0])
                * (float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[0] - v11->mVec128.m128_f32[0]));
    if ( v35 > v16 )
    {
      v17 = v40.m_barycentricCoords[0];
      finalResult->m_closestPointOnSimplex.mVec128.m128_u64[0] = v40.m_closestPointOnSimplex.mVec128.m128_u64[0];
      finalResult->m_closestPointOnSimplex.mVec128.m128_u64[1] = v40.m_closestPointOnSimplex.mVec128.m128_u64[1];
      v11 = p;
      *(_WORD *)&finalResult->m_usedVertices &= 0xFFF0u;
      v18 = *(_BYTE *)&v40.m_usedVertices & 1 | (2 * (*(_BYTE *)&v40.m_usedVertices & 6));
      m_usedVertices = finalResult->m_usedVertices;
      finalResult->m_barycentricCoords[0] = v17;
      finalResult->m_barycentricCoords[1] = 0.0;
      finalResult->m_barycentricCoords[2] = v40.m_barycentricCoords[1];
      v20 = v40.m_barycentricCoords[2];
      v35 = v16;
      finalResult->m_usedVertices = (btUsageBitfield)(*(_WORD *)&m_usedVertices & 0xFFF2 | v18);
      finalResult->m_barycentricCoords[3] = v20;
    }
  }
  if ( v38 )
  {
    btVoronoiSimplexSolver::closestPtPointTriangle(d, &v40, (btVoronoiSimplexSolver *)v11, (const btVector3 *)a, b, v34);
    v21 = (float)((float)((float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[2] - v11->mVec128.m128_f32[2])
                        * (float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[2] - v11->mVec128.m128_f32[2]))
                + (float)((float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[1] - v11->mVec128.m128_f32[1])
                        * (float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[1] - v11->mVec128.m128_f32[1])))
        + (float)((float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[0] - v11->mVec128.m128_f32[0])
                * (float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[0] - v11->mVec128.m128_f32[0]));
    if ( v35 > v21 )
    {
      v22 = v40.m_barycentricCoords[0];
      finalResult->m_closestPointOnSimplex.mVec128.m128_u64[0] = v40.m_closestPointOnSimplex.mVec128.m128_u64[0];
      finalResult->m_closestPointOnSimplex.mVec128.m128_u64[1] = v40.m_closestPointOnSimplex.mVec128.m128_u64[1];
      v11 = p;
      *(_WORD *)&finalResult->m_usedVertices &= 0xFFF0u;
      v23 = *(_BYTE *)&v40.m_usedVertices & 1
          | (4 * (*(_BYTE *)&v40.m_usedVertices & 2))
          | (*(_DWORD *)&v40.m_usedVertices >> 1) & 2;
      v24 = finalResult->m_usedVertices;
      finalResult->m_barycentricCoords[0] = v22;
      finalResult->m_barycentricCoords[1] = v40.m_barycentricCoords[2];
      finalResult->m_barycentricCoords[2] = 0.0;
      v25 = v40.m_barycentricCoords[1];
      v35 = v21;
      finalResult->m_usedVertices = (btUsageBitfield)(*(_WORD *)&v24 & 0xFFF4 | v23);
      finalResult->m_barycentricCoords[3] = v25;
    }
  }
  if ( v39 )
  {
    btVoronoiSimplexSolver::closestPtPointTriangle(d, &v40, (btVoronoiSimplexSolver *)v11, b, c, v34);
    if ( v35 > (float)((float)((float)((float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[2] - v11->mVec128.m128_f32[2])
                                     * (float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[2] - v11->mVec128.m128_f32[2]))
                             + (float)((float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[1] - v11->mVec128.m128_f32[1])
                                     * (float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[1] - v11->mVec128.m128_f32[1])))
                     + (float)((float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[0] - v11->mVec128.m128_f32[0])
                             * (float)(v40.m_closestPointOnSimplex.mVec128.m128_f32[0] - v11->mVec128.m128_f32[0]))) )
    {
      finalResult->m_closestPointOnSimplex.mVec128.m128_u64[0] = v40.m_closestPointOnSimplex.mVec128.m128_u64[0];
      finalResult->m_closestPointOnSimplex.mVec128.m128_u64[1] = v40.m_closestPointOnSimplex.mVec128.m128_u64[1];
      *(_WORD *)&finalResult->m_usedVertices &= 0xFFF0u;
      v26 = *(_BYTE *)&v40.m_usedVertices & 4
          | (2 * (*(_BYTE *)&v40.m_usedVertices & 1 | (2 * (*(_BYTE *)&v40.m_usedVertices & 2))));
      v27 = finalResult->m_usedVertices;
      finalResult->m_barycentricCoords[0] = 0.0;
      finalResult->m_barycentricCoords[1] = v40.m_barycentricCoords[0];
      finalResult->m_barycentricCoords[2] = v40.m_barycentricCoords[2];
      v28 = v40.m_barycentricCoords[1];
      finalResult->m_usedVertices = (btUsageBitfield)(*(_WORD *)&v27 & 0xFFF1 | v26);
      finalResult->m_barycentricCoords[3] = v28;
    }
  }
  return 1;
}
