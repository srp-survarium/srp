char __userpurge btVoronoiSimplexSolver::closestPtPointTriangle@<al>(
        const btVector3 *b@<edx>,
        btSubSimplexClosestResult *result@<eax>,
        btVoronoiSimplexSolver *this,
        const btVector3 *p,
        const btVector3 *a,
        const btVector3 *c)
{
  float v6; // xmm6_4
  float v7; // xmm7_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm7_4
  float v12; // xmm6_4
  float v13; // xmm2_4
  float v14; // xmm5_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  float v17; // xmm6_4
  float v18; // xmm1_4
  float v19; // xmm1_4
  float v20; // xmm7_4
  float v21; // xmm1_4
  float v22; // xmm1_4
  float v23; // xmm6_4
  float v24; // xmm2_4
  float v25; // xmm4_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm3_4
  float v32; // [esp+10h] [ebp-60h]
  float v33; // [esp+14h] [ebp-5Ch]
  float v34; // [esp+18h] [ebp-58h]
  float v35; // [esp+1Ch] [ebp-54h]
  float v36; // [esp+20h] [ebp-50h]
  float v37; // [esp+20h] [ebp-50h]
  int m_numVertices; // [esp+24h] [ebp-4Ch]
  float v39; // [esp+24h] [ebp-4Ch]
  float v40; // [esp+28h] [ebp-48h]
  float v41; // [esp+28h] [ebp-48h]
  float v42; // [esp+2Ch] [ebp-44h]
  float v43; // [esp+30h] [ebp-40h]
  float v44; // [esp+34h] [ebp-3Ch]
  float v45; // [esp+38h] [ebp-38h]
  float v46; // [esp+38h] [ebp-38h]
  float v47; // [esp+3Ch] [ebp-34h]
  float v48; // [esp+44h] [ebp-2Ch]
  float v49; // [esp+48h] [ebp-28h]
  unsigned __int64 v50; // [esp+50h] [ebp-20h]
  float v51; // [esp+50h] [ebp-20h]
  float v52; // [esp+54h] [ebp-1Ch]
  float v53; // [esp+54h] [ebp-1Ch]
  float v54; // [esp+58h] [ebp-18h]
  float v55; // [esp+58h] [ebp-18h]

  *(_WORD *)&result->m_usedVertices &= 0xFFF0u;
  v6 = p->mVec128.m128_f32[1];
  v7 = p->mVec128.m128_f32[2];
  v8 = p->mVec128.m128_f32[0];
  v44 = a->mVec128.m128_f32[1];
  v48 = v44 - v6;
  v45 = a->mVec128.m128_f32[2];
  v49 = v45 - v7;
  v9 = b->mVec128.m128_f32[1] - v6;
  v10 = b->mVec128.m128_f32[2] - v7;
  m_numVertices = this->m_numVertices;
  v33 = *((float *)&this->m_numVertices + 1);
  v11 = v33 - v6;
  v40 = *((float *)&this->m_numVertices + 2);
  v12 = v40 - p->mVec128.m128_f32[2];
  v43 = b->mVec128.m128_f32[0];
  v13 = b->mVec128.m128_f32[0] - p->mVec128.m128_f32[0];
  v34 = (float)((float)(v12 * v10) + (float)(v11 * v9))
      + (float)((float)(*(float *)&this->m_numVertices - p->mVec128.m128_f32[0]) * v13);
  v42 = a->mVec128.m128_f32[0];
  v14 = a->mVec128.m128_f32[0] - p->mVec128.m128_f32[0];
  v35 = (float)((float)(v12 * v49) + (float)(v11 * v48))
      + (float)((float)(*(float *)&this->m_numVertices - p->mVec128.m128_f32[0]) * v14);
  if ( v34 <= 0.0 && v35 <= 0.0 )
  {
    v15 = s_bm_current_air_resistance;
    result->m_closestPointOnSimplex = (btVector3)p->mVec128;
    *(_WORD *)&result->m_usedVertices |= 1u;
    result->m_barycentricCoords[1] = 0.0;
    result->m_barycentricCoords[2] = 0.0;
LABEL_25:
    result->m_barycentricCoords[0] = v15;
    goto LABEL_26;
  }
  v52 = v33 - b->mVec128.m128_f32[1];
  v54 = v40 - b->mVec128.m128_f32[2];
  v32 = (float)((float)(v54 * v10) + (float)(v52 * v9)) + (float)((float)(*(float *)&m_numVertices - v43) * v13);
  v36 = (float)((float)(v54 * v49) + (float)(v52 * v48)) + (float)((float)(*(float *)&m_numVertices - v43) * v14);
  if ( v32 < 0.0
    || v32 < (float)((float)((float)(v54 * v49) + (float)(v52 * v48))
                   + (float)((float)(*(float *)&m_numVertices - v43) * v14)) )
  {
    v47 = (float)(v36 * v34) - (float)(v32 * v35);
    if ( v47 > 0.0 || v34 < 0.0 || v32 > 0.0 )
    {
      v51 = *(float *)&m_numVertices - v42;
      v39 = (float)((float)((float)(v40 - v45) * v10) + (float)((float)(v33 - v44) * v9))
          + (float)((float)(*(float *)&m_numVertices - v42) * v13);
      v20 = (float)((float)((float)(v40 - v45) * v49) + (float)((float)(v33 - v44) * v48)) + (float)(v51 * v14);
      if ( v20 >= 0.0 && v20 >= v39 )
      {
        v21 = s_bm_current_air_resistance;
        result->m_closestPointOnSimplex = (btVector3)a->mVec128;
        *(_WORD *)&result->m_usedVertices |= 4u;
        result->m_barycentricCoords[0] = 0.0;
        result->m_barycentricCoords[1] = 0.0;
        result->m_barycentricCoords[2] = v21;
        goto LABEL_26;
      }
      v41 = (float)(v39 * v35) - (float)(v20 * v34);
      if ( v41 > 0.0 || v35 < 0.0 || v20 > 0.0 )
      {
        v23 = (float)(v20 * v32) - (float)(v39 * v36);
        if ( v23 <= 0.0 )
        {
          v37 = v36 - v32;
          if ( v37 >= 0.0 && (float)(v39 - v20) >= 0.0 )
          {
            v24 = b->mVec128.m128_f32[2];
            v25 = v37 / (float)((float)(v39 - v20) + v37);
            v26 = b->mVec128.m128_f32[1];
            *(_WORD *)&result->m_usedVertices |= 6u;
            v53 = v26 + (float)((float)(v44 - v26) * v25);
            v27 = s_bm_current_air_resistance;
            result->m_closestPointOnSimplex.mVec128.m128_f32[0] = v43 + (float)((float)(v42 - v43) * v25);
            result->m_closestPointOnSimplex.mVec128.m128_f32[1] = v53;
            result->m_closestPointOnSimplex.mVec128.m128_f32[2] = v24 + (float)((float)(v45 - v24) * v25);
            result->m_closestPointOnSimplex.mVec128.m128_i32[3] = 0;
            result->m_barycentricCoords[0] = 0.0;
            result->m_barycentricCoords[1] = v27 - v25;
            result->m_barycentricCoords[2] = v25;
            goto LABEL_26;
          }
        }
        v46 = s_bm_current_air_resistance / (float)((float)(v23 + v41) + v47);
        v17 = v46 * v47;
        v28 = v8 + (float)(v13 * (float)(v46 * v41));
        v29 = p->mVec128.m128_f32[1] + (float)(v9 * (float)(v46 * v41));
        v30 = p->mVec128.m128_f32[2];
        *(_WORD *)&result->m_usedVertices |= 7u;
        *(float *)&v50 = v28 + (float)(v14 * (float)(v46 * v47));
        *((float *)&v50 + 1) = v29 + (float)(v48 * (float)(v46 * v47));
        v55 = (float)(v30 + (float)(v10 * (float)(v46 * v41))) + (float)(v49 * (float)(v46 * v47));
        v19 = s_bm_current_air_resistance - (float)(v46 * v41);
        result->m_barycentricCoords[1] = v46 * v41;
      }
      else
      {
        v17 = v35 / (float)(v35 - v20);
        *(float *)&v50 = v8 + (float)(v14 * v17);
        *((float *)&v50 + 1) = p->mVec128.m128_f32[1] + (float)(v48 * v17);
        v22 = p->mVec128.m128_f32[2];
        *(_WORD *)&result->m_usedVertices |= 5u;
        v55 = v22 + (float)(v49 * v17);
        v19 = s_bm_current_air_resistance;
        result->m_barycentricCoords[1] = 0.0;
      }
      result->m_barycentricCoords[2] = v17;
    }
    else
    {
      v17 = v34 / (float)(v34 - v32);
      *(float *)&v50 = v8 + (float)(v13 * v17);
      *((float *)&v50 + 1) = p->mVec128.m128_f32[1] + (float)(v9 * v17);
      v18 = p->mVec128.m128_f32[2];
      *(_WORD *)&result->m_usedVertices |= 3u;
      v55 = v18 + (float)(v10 * v17);
      v19 = s_bm_current_air_resistance;
      result->m_barycentricCoords[1] = v17;
      result->m_barycentricCoords[2] = 0.0;
    }
    result->m_closestPointOnSimplex.mVec128.m128_u64[0] = v50;
    result->m_closestPointOnSimplex.mVec128.m128_u64[1] = LODWORD(v55);
    v15 = v19 - v17;
    goto LABEL_25;
  }
  v16 = s_bm_current_air_resistance;
  result->m_closestPointOnSimplex = (btVector3)b->mVec128;
  *(_WORD *)&result->m_usedVertices |= 2u;
  result->m_barycentricCoords[0] = 0.0;
  result->m_barycentricCoords[1] = v16;
  result->m_barycentricCoords[2] = 0.0;
LABEL_26:
  result->m_barycentricCoords[3] = 0.0;
  return 1;
}
