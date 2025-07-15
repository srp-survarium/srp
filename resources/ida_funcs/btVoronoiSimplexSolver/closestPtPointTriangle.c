char __userpurge btVoronoiSimplexSolver::closestPtPointTriangle@<al>(
        const btVector3 *p@<edi>,
        const btVector3 *b@<edx>,
        const btVector3 *c@<esi>,
        btSubSimplexClosestResult *result@<eax>,
        btVoronoiSimplexSolver *this,
        const btVector3 *a)
{
  float v6; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm2_4
  float v9; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm4_4
  float v12; // xmm3_4
  float v13; // xmm7_4
  unsigned __int64 v14; // xmm1_8
  float v16; // xmm6_4
  unsigned __int64 v17; // xmm1_8
  float v18; // xmm6_4
  float v19; // xmm5_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  float v22; // xmm7_4
  unsigned __int64 v23; // xmm1_8
  float v24; // xmm7_4
  float v25; // xmm6_4
  float v26; // xmm2_4
  float v27; // xmm6_4
  float v28; // xmm2_4
  float v29; // xmm3_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm5_4
  float v33; // xmm3_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm1_4
  float v37; // [esp+328h] [ebp-54h]
  float v38; // [esp+32Ch] [ebp-50h]
  float v39; // [esp+32Ch] [ebp-50h]
  float v40; // [esp+330h] [ebp-4Ch]
  float v41; // [esp+330h] [ebp-4Ch]
  float v42; // [esp+334h] [ebp-48h]
  float v43; // [esp+338h] [ebp-44h]
  int m_numVertices; // [esp+33Ch] [ebp-40h]
  float v45; // [esp+340h] [ebp-3Ch]
  float v46; // [esp+340h] [ebp-3Ch]
  float v47; // [esp+344h] [ebp-38h]
  float v48; // [esp+344h] [ebp-38h]
  float v49; // [esp+348h] [ebp-34h]
  float v50; // [esp+34Ch] [ebp-30h]
  float v51; // [esp+350h] [ebp-2Ch]
  float v52; // [esp+354h] [ebp-28h]
  float v53; // [esp+354h] [ebp-28h]
  float v54; // [esp+358h] [ebp-24h]
  float v55; // [esp+35Ch] [ebp-20h]
  unsigned __int64 v56; // [esp+35Ch] [ebp-20h]
  unsigned __int64 v57; // [esp+35Ch] [ebp-20h]
  unsigned __int64 v58; // [esp+35Ch] [ebp-20h]
  float v59; // [esp+360h] [ebp-1Ch]
  float v60; // [esp+360h] [ebp-1Ch]
  float v61; // [esp+360h] [ebp-1Ch]
  float v62; // [esp+364h] [ebp-18h]
  unsigned __int64 v63; // [esp+364h] [ebp-18h]
  unsigned __int64 v64; // [esp+364h] [ebp-18h]
  unsigned __int64 v65; // [esp+364h] [ebp-18h]
  unsigned __int64 v66; // [esp+36Ch] [ebp-10h]
  float v67; // [esp+374h] [ebp-8h]

  *(_WORD *)&result->m_usedVertices &= 0xFFF0u;
  v6 = *((float *)&this->m_numVertices + 1);
  v7 = *((float *)&this->m_numVertices + 2);
  v8 = b->mVec128.m128_f32[1] - v6;
  v51 = c->mVec128.m128_f32[1];
  v9 = v51 - v6;
  v52 = c->mVec128.m128_f32[2];
  v67 = v52 - v7;
  v40 = p->mVec128.m128_f32[0];
  v55 = p->mVec128.m128_f32[0] - *(float *)&this->m_numVertices;
  v38 = p->mVec128.m128_f32[1];
  m_numVertices = this->m_numVertices;
  v50 = b->mVec128.m128_f32[0];
  v10 = b->mVec128.m128_f32[0] - *(float *)&this->m_numVertices;
  v49 = c->mVec128.m128_f32[0];
  v11 = c->mVec128.m128_f32[0] - *(float *)&this->m_numVertices;
  v59 = v38 - v6;
  v45 = p->mVec128.m128_f32[2];
  v12 = b->mVec128.m128_f32[2] - v7;
  v13 = (float)((float)((float)(v45 - v7) * (float)(v52 - v7)) + (float)((float)(v38 - v6) * (float)(v51 - v6)))
      + (float)(v55 * v11);
  v42 = (float)((float)((float)(v45 - v7) * v12) + (float)(v59 * v8)) + (float)(v55 * v10);
  v43 = v13;
  if ( v42 <= 0.0 && v13 <= 0.0 )
  {
    result->m_closestPointOnSimplex.mVec128.m128_u64[0] = *(_QWORD *)&this->m_numVertices;
    v14 = *((_QWORD *)&this->m_numVertices + 1);
    *(_WORD *)&result->m_usedVertices |= 1u;
    result->m_closestPointOnSimplex.mVec128.m128_u64[1] = v14;
    LODWORD(v14) = clear_value;
    result->m_barycentricCoords[1] = 0.0;
    result->m_barycentricCoords[2] = 0.0;
    LODWORD(result->m_barycentricCoords[0]) = v14;
    result->m_barycentricCoords[3] = 0.0;
    return 1;
  }
  v60 = v38 - b->mVec128.m128_f32[1];
  v62 = v45 - b->mVec128.m128_f32[2];
  v37 = (float)((float)(v62 * v12) + (float)(v60 * v8)) + (float)((float)(v40 - v50) * v10);
  v16 = (float)((float)(v62 * v67) + (float)(v60 * v9)) + (float)((float)(v40 - v50) * v11);
  v47 = v16;
  if ( v37 >= 0.0 && v37 >= v16 )
  {
    result->m_closestPointOnSimplex.mVec128.m128_u64[0] = b->mVec128.m128_u64[0];
    v17 = b->mVec128.m128_u64[1];
    *(_WORD *)&result->m_usedVertices |= 2u;
    result->m_closestPointOnSimplex.mVec128.m128_u64[1] = v17;
    LODWORD(v17) = clear_value;
    result->m_barycentricCoords[0] = 0.0;
    LODWORD(result->m_barycentricCoords[1]) = v17;
    result->m_barycentricCoords[2] = 0.0;
    result->m_barycentricCoords[3] = 0.0;
    return 1;
  }
  v54 = (float)(v16 * v42) - (float)(v37 * v13);
  if ( v54 <= 0.0 && v42 >= 0.0 && v37 <= 0.0 )
  {
    v18 = v42 / (float)(v42 - v37);
    v19 = *(float *)&m_numVertices + (float)(v10 * v18);
    *((float *)&v56 + 1) = *((float *)&this->m_numVertices + 1) + (float)(v8 * v18);
    v20 = *((float *)&this->m_numVertices + 2);
    *(_WORD *)&result->m_usedVertices |= 3u;
    *(float *)&v63 = v20 + (float)(v12 * v18);
    *(float *)&v56 = v19;
    result->m_closestPointOnSimplex.mVec128.m128_u64[0] = v56;
    HIDWORD(v63) = 0;
    result->m_closestPointOnSimplex.mVec128.m128_u64[1] = v63;
    v21 = *(float *)&clear_value - v18;
    result->m_barycentricCoords[1] = v18;
    result->m_barycentricCoords[2] = 0.0;
    result->m_barycentricCoords[0] = v21;
    result->m_barycentricCoords[3] = 0.0;
    return 1;
  }
  v22 = v38 - v51;
  v39 = (float)((float)((float)(v45 - v52) * v12) + (float)((float)(v38 - v51) * v8))
      + (float)((float)(v40 - v49) * v10);
  v41 = (float)((float)((float)(v45 - v52) * v67) + (float)(v22 * v9)) + (float)((float)(v40 - v49) * v11);
  if ( v41 >= 0.0 && v41 >= v39 )
  {
    result->m_closestPointOnSimplex.mVec128.m128_u64[0] = c->mVec128.m128_u64[0];
    v23 = c->mVec128.m128_u64[1];
    *(_WORD *)&result->m_usedVertices |= 4u;
    result->m_closestPointOnSimplex.mVec128.m128_u64[1] = v23;
    LODWORD(v23) = clear_value;
    result->m_barycentricCoords[0] = 0.0;
    result->m_barycentricCoords[1] = 0.0;
    LODWORD(result->m_barycentricCoords[2]) = v23;
    result->m_barycentricCoords[3] = 0.0;
    return 1;
  }
  v46 = (float)(v39 * v43) - (float)(v41 * v42);
  if ( v46 > 0.0 || v43 < 0.0 )
  {
    v24 = v41;
  }
  else
  {
    v24 = v41;
    if ( v41 <= 0.0 )
    {
      v25 = v43 / (float)(v43 - v41);
      *(float *)&v57 = *(float *)&m_numVertices + (float)(v11 * v25);
      *((float *)&v57 + 1) = *((float *)&this->m_numVertices + 1) + (float)(v9 * v25);
      v26 = *((float *)&this->m_numVertices + 2);
      *(_WORD *)&result->m_usedVertices |= 5u;
      *(float *)&v64 = v26 + (float)(v67 * v25);
      result->m_closestPointOnSimplex.mVec128.m128_u64[0] = v57;
      HIDWORD(v64) = 0;
      result->m_closestPointOnSimplex.mVec128.m128_u64[1] = v64;
      result->m_barycentricCoords[0] = *(float *)&clear_value - v25;
      result->m_barycentricCoords[1] = 0.0;
      result->m_barycentricCoords[2] = v25;
      result->m_barycentricCoords[3] = 0.0;
      return 1;
    }
  }
  v27 = (float)(v24 * v37) - (float)(v39 * v16);
  if ( v27 > 0.0 || (v48 = v47 - v37, v48 < 0.0) || (float)(v39 - v41) < 0.0 )
  {
    v53 = *(float *)&clear_value / (float)((float)(v27 + v46) + v54);
    v61 = v9 * (float)(v53 * v54);
    v32 = v12 * (float)(v53 * v46);
    v33 = *(float *)&m_numVertices + (float)(v10 * (float)(v53 * v46));
    v34 = *((float *)&this->m_numVertices + 1) + (float)(v8 * (float)(v53 * v46));
    v35 = *((float *)&this->m_numVertices + 2);
    *(_WORD *)&result->m_usedVertices |= 7u;
    *((float *)&v66 + 1) = v34 + v61;
    *(float *)&v66 = v33 + (float)(v11 * (float)(v53 * v54));
    result->m_closestPointOnSimplex.mVec128.m128_u64[0] = v66;
    result->m_closestPointOnSimplex.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT((float)(v35 + v32) + (float)(v67 * (float)(v53 * v54)));
    v36 = (float)(*(float *)&clear_value - (float)(v53 * v46)) - (float)(v53 * v54);
    result->m_barycentricCoords[1] = v53 * v46;
    result->m_barycentricCoords[2] = v53 * v54;
    result->m_barycentricCoords[0] = v36;
    result->m_barycentricCoords[3] = 0.0;
    return 1;
  }
  else
  {
    v28 = b->mVec128.m128_f32[1];
    v29 = b->mVec128.m128_f32[2];
    *(_WORD *)&result->m_usedVertices |= 6u;
    v30 = v48 / (float)((float)(v39 - v41) + v48);
    *((float *)&v58 + 1) = v28 + (float)((float)(v51 - v28) * v30);
    *(float *)&v58 = v50 + (float)((float)(v49 - v50) * v30);
    result->m_closestPointOnSimplex.mVec128.m128_u64[0] = v58;
    *(float *)&v65 = v29 + (float)((float)(v52 - v29) * v30);
    HIDWORD(v65) = 0;
    result->m_closestPointOnSimplex.mVec128.m128_u64[1] = v65;
    v31 = *(float *)&clear_value - v30;
    result->m_barycentricCoords[0] = 0.0;
    result->m_barycentricCoords[1] = v31;
    result->m_barycentricCoords[2] = v30;
    result->m_barycentricCoords[3] = 0.0;
    return 1;
  }
}
