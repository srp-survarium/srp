char __userpurge btVoronoiSimplexSolver::closestPtPointTetrahedron@<al>(
        const btVector3 *p@<eax>,
        btVoronoiSimplexSolver *this,
        btVector3 *a,
        const btVector3 *b,
        const btVector3 *c,
        btSubSimplexClosestResult *d,
        btSubSimplexClosestResult *finalResult)
{
  btUsageBitfield v8; // ax
  btVoronoiSimplexSolver *v9; // edx
  int v10; // ecx
  int v11; // eax
  int v12; // xmm0_4
  char v13; // cl
  int v14; // xmm0_4
  int v15; // xmm0_4
  __int16 m_usedVertices; // dx
  __int16 v17; // cx
  int v18; // xmm0_4
  unsigned int v19; // eax
  int v20; // xmm0_4
  int v21; // ecx
  int v22; // xmm0_4
  char v23; // al
  __int16 v24; // dx
  __int16 v25; // ax
  int v26; // xmm0_4
  const btVector3 *v28; // [esp+158h] [ebp-50h]
  const btVector3 *v29; // [esp+158h] [ebp-50h]
  const btVector3 *v30; // [esp+158h] [ebp-50h]
  const btVector3 *v31; // [esp+158h] [ebp-50h]
  const btVector3 *v32; // [esp+158h] [ebp-50h]
  int v33; // [esp+168h] [ebp-40h]
  float v34; // [esp+168h] [ebp-40h]
  int v35; // [esp+16Ch] [ebp-3Ch]
  int v36; // [esp+170h] [ebp-38h]
  int v37; // [esp+174h] [ebp-34h]
  btSubSimplexClosestResult result; // [esp+178h] [ebp-30h] BYREF

  v8 = (btUsageBitfield)(*(_WORD *)&result.m_usedVertices & 0xFFF0);
  d->m_closestPointOnSimplex.mVec128.m128_u64[0] = p->mVec128.m128_u64[0];
  result.m_usedVertices = v8;
  d->m_closestPointOnSimplex.mVec128.m128_u64[1] = p->mVec128.m128_u64[1];
  *(_WORD *)&d->m_usedVertices &= 0xFFF0u;
  *(_WORD *)&d->m_usedVertices |= 0xFu;
  v33 = btVoronoiSimplexSolver::pointOutsideOfPlane(p, a, b, c, this, v28);
  v35 = btVoronoiSimplexSolver::pointOutsideOfPlane(p, b, c, a, this, v29);
  v36 = btVoronoiSimplexSolver::pointOutsideOfPlane(p, c, a, b, this, v30);
  v10 = btVoronoiSimplexSolver::pointOutsideOfPlane(p, c, b, (const btVector3 *)this, v9, v31);
  v11 = v33;
  v37 = v10;
  if ( v33 < 0 || v35 < 0 || v36 < 0 || v10 < 0 )
  {
    d->m_degenerate = 1;
    return 0;
  }
  if ( !v33 && !v35 && !v36 && !v10 )
    return 0;
  v34 = 3.4028235e38;
  if ( v11 )
  {
    btVoronoiSimplexSolver::closestPtPointTriangle(p, a, b, &result, this, v32);
    if ( (float)((float)((float)((float)(result.m_closestPointOnSimplex.mVec128.m128_f32[2] - p->mVec128.m128_f32[2])
                               * (float)(result.m_closestPointOnSimplex.mVec128.m128_f32[2] - p->mVec128.m128_f32[2]))
                       + (float)((float)(result.m_closestPointOnSimplex.mVec128.m128_f32[1] - p->mVec128.m128_f32[1])
                               * (float)(result.m_closestPointOnSimplex.mVec128.m128_f32[1] - p->mVec128.m128_f32[1])))
               + (float)((float)(result.m_closestPointOnSimplex.mVec128.m128_f32[0] - p->mVec128.m128_f32[0])
                       * (float)(result.m_closestPointOnSimplex.mVec128.m128_f32[0] - p->mVec128.m128_f32[0]))) < 3.4028235e38 )
    {
      v34 = (float)((float)((float)(result.m_closestPointOnSimplex.mVec128.m128_f32[2] - p->mVec128.m128_f32[2])
                          * (float)(result.m_closestPointOnSimplex.mVec128.m128_f32[2] - p->mVec128.m128_f32[2]))
                  + (float)((float)(result.m_closestPointOnSimplex.mVec128.m128_f32[1] - p->mVec128.m128_f32[1])
                          * (float)(result.m_closestPointOnSimplex.mVec128.m128_f32[1] - p->mVec128.m128_f32[1])))
          + (float)((float)(result.m_closestPointOnSimplex.mVec128.m128_f32[0] - p->mVec128.m128_f32[0])
                  * (float)(result.m_closestPointOnSimplex.mVec128.m128_f32[0] - p->mVec128.m128_f32[0]));
      d->m_closestPointOnSimplex = result.m_closestPointOnSimplex;
      v12 = LODWORD(result.m_barycentricCoords[0]);
      *(_WORD *)&d->m_usedVertices &= 0xFFF0u;
      v13 = *(_BYTE *)&result.m_usedVertices ^ *(_WORD *)&d->m_usedVertices;
      LODWORD(d->m_barycentricCoords[0]) = v12;
      d->m_barycentricCoords[1] = result.m_barycentricCoords[1];
      v14 = LODWORD(result.m_barycentricCoords[2]);
      *(_WORD *)&d->m_usedVertices ^= v13 & 7;
      LODWORD(d->m_barycentricCoords[2]) = v14;
      d->m_barycentricCoords[3] = 0.0;
    }
  }
  if ( v35 )
  {
    btVoronoiSimplexSolver::closestPtPointTriangle(p, b, c, &result, this, v32);
    if ( v34 > (float)((float)((float)((float)(result.m_closestPointOnSimplex.mVec128.m128_f32[2]
                                             - p->mVec128.m128_f32[2])
                                     * (float)(result.m_closestPointOnSimplex.mVec128.m128_f32[2]
                                             - p->mVec128.m128_f32[2]))
                             + (float)((float)(result.m_closestPointOnSimplex.mVec128.m128_f32[1]
                                             - p->mVec128.m128_f32[1])
                                     * (float)(result.m_closestPointOnSimplex.mVec128.m128_f32[1]
                                             - p->mVec128.m128_f32[1])))
                     + (float)((float)(result.m_closestPointOnSimplex.mVec128.m128_f32[0] - p->mVec128.m128_f32[0])
                             * (float)(result.m_closestPointOnSimplex.mVec128.m128_f32[0] - p->mVec128.m128_f32[0]))) )
    {
      v34 = (float)((float)((float)(result.m_closestPointOnSimplex.mVec128.m128_f32[2] - p->mVec128.m128_f32[2])
                          * (float)(result.m_closestPointOnSimplex.mVec128.m128_f32[2] - p->mVec128.m128_f32[2]))
                  + (float)((float)(result.m_closestPointOnSimplex.mVec128.m128_f32[1] - p->mVec128.m128_f32[1])
                          * (float)(result.m_closestPointOnSimplex.mVec128.m128_f32[1] - p->mVec128.m128_f32[1])))
          + (float)((float)(result.m_closestPointOnSimplex.mVec128.m128_f32[0] - p->mVec128.m128_f32[0])
                  * (float)(result.m_closestPointOnSimplex.mVec128.m128_f32[0] - p->mVec128.m128_f32[0]));
      d->m_closestPointOnSimplex = result.m_closestPointOnSimplex;
      v15 = LODWORD(result.m_barycentricCoords[0]);
      *(_WORD *)&d->m_usedVertices &= 0xFFF0u;
      m_usedVertices = (__int16)d->m_usedVertices;
      v17 = *(_BYTE *)&result.m_usedVertices & 1 | (2 * (*(_BYTE *)&result.m_usedVertices & 6));
      LODWORD(d->m_barycentricCoords[0]) = v15;
      d->m_barycentricCoords[1] = 0.0;
      d->m_barycentricCoords[2] = result.m_barycentricCoords[1];
      v18 = LODWORD(result.m_barycentricCoords[2]);
      d->m_usedVertices = (btUsageBitfield)(m_usedVertices & 0xFFF2 | v17);
      LODWORD(d->m_barycentricCoords[3]) = v18;
    }
  }
  if ( v36 )
  {
    btVoronoiSimplexSolver::closestPtPointTriangle(p, c, a, &result, this, v32);
    if ( v34 > (float)((float)((float)((float)(result.m_closestPointOnSimplex.mVec128.m128_f32[2]
                                             - p->mVec128.m128_f32[2])
                                     * (float)(result.m_closestPointOnSimplex.mVec128.m128_f32[2]
                                             - p->mVec128.m128_f32[2]))
                             + (float)((float)(result.m_closestPointOnSimplex.mVec128.m128_f32[1]
                                             - p->mVec128.m128_f32[1])
                                     * (float)(result.m_closestPointOnSimplex.mVec128.m128_f32[1]
                                             - p->mVec128.m128_f32[1])))
                     + (float)((float)(result.m_closestPointOnSimplex.mVec128.m128_f32[0] - p->mVec128.m128_f32[0])
                             * (float)(result.m_closestPointOnSimplex.mVec128.m128_f32[0] - p->mVec128.m128_f32[0]))) )
    {
      v19 = *(_DWORD *)&result.m_usedVertices;
      v34 = (float)((float)((float)(result.m_closestPointOnSimplex.mVec128.m128_f32[2] - p->mVec128.m128_f32[2])
                          * (float)(result.m_closestPointOnSimplex.mVec128.m128_f32[2] - p->mVec128.m128_f32[2]))
                  + (float)((float)(result.m_closestPointOnSimplex.mVec128.m128_f32[1] - p->mVec128.m128_f32[1])
                          * (float)(result.m_closestPointOnSimplex.mVec128.m128_f32[1] - p->mVec128.m128_f32[1])))
          + (float)((float)(result.m_closestPointOnSimplex.mVec128.m128_f32[0] - p->mVec128.m128_f32[0])
                  * (float)(result.m_closestPointOnSimplex.mVec128.m128_f32[0] - p->mVec128.m128_f32[0]));
      d->m_closestPointOnSimplex = result.m_closestPointOnSimplex;
      v20 = LODWORD(result.m_barycentricCoords[0]);
      *(_WORD *)&d->m_usedVertices &= 0xFFF0u;
      v21 = v19 & 1 | (4 * (v19 & 2)) | (v19 >> 1) & 2;
      LOWORD(v19) = d->m_usedVertices;
      LODWORD(d->m_barycentricCoords[0]) = v20;
      d->m_barycentricCoords[1] = result.m_barycentricCoords[2];
      d->m_barycentricCoords[2] = 0.0;
      v22 = LODWORD(result.m_barycentricCoords[1]);
      d->m_usedVertices = (btUsageBitfield)(v19 & 0xFFF4 | v21);
      LODWORD(d->m_barycentricCoords[3]) = v22;
    }
  }
  if ( v37 )
  {
    btVoronoiSimplexSolver::closestPtPointTriangle(p, c, b, &result, (btVoronoiSimplexSolver *)a, v32);
    if ( v34 > (float)((float)((float)((float)(result.m_closestPointOnSimplex.mVec128.m128_f32[2]
                                             - p->mVec128.m128_f32[2])
                                     * (float)(result.m_closestPointOnSimplex.mVec128.m128_f32[2]
                                             - p->mVec128.m128_f32[2]))
                             + (float)((float)(result.m_closestPointOnSimplex.mVec128.m128_f32[1]
                                             - p->mVec128.m128_f32[1])
                                     * (float)(result.m_closestPointOnSimplex.mVec128.m128_f32[1]
                                             - p->mVec128.m128_f32[1])))
                     + (float)((float)(result.m_closestPointOnSimplex.mVec128.m128_f32[0] - p->mVec128.m128_f32[0])
                             * (float)(result.m_closestPointOnSimplex.mVec128.m128_f32[0] - p->mVec128.m128_f32[0]))) )
    {
      v23 = (char)result.m_usedVertices;
      d->m_closestPointOnSimplex = result.m_closestPointOnSimplex;
      *(_WORD *)&d->m_usedVertices &= 0xFFF0u;
      v24 = v23 & 4 | (2 * (v23 & 1 | (2 * (v23 & 2))));
      v25 = (__int16)d->m_usedVertices;
      d->m_barycentricCoords[0] = 0.0;
      d->m_barycentricCoords[1] = result.m_barycentricCoords[0];
      d->m_barycentricCoords[2] = result.m_barycentricCoords[2];
      v26 = LODWORD(result.m_barycentricCoords[1]);
      d->m_usedVertices = (btUsageBitfield)(v25 & 0xFFF1 | v24);
      LODWORD(d->m_barycentricCoords[3]) = v26;
    }
  }
  return 1;
}
