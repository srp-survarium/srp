char __usercall btVoronoiSimplexSolver::inSimplex@<al>(btVoronoiSimplexSolver *this@<edx>, const btVector3 *w@<esi>)
{
  int m_numVertices; // edi
  char v3; // bl
  int v4; // ecx
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm5_4
  float m_equalVertexThreshold; // xmm6_4
  unsigned int v9; // ecx
  float *v10; // eax
  float *v11; // eax
  int v12; // edi
  float v13; // xmm1_4
  char result; // al
  int v15; // [esp+16h] [ebp-4h]

  m_numVertices = this->m_numVertices;
  v3 = 0;
  v4 = 0;
  if ( this->m_numVertices >= 4 )
  {
    v5 = w->mVec128.m128_f32[0];
    v6 = w->mVec128.m128_f32[1];
    v7 = w->mVec128.m128_f32[2];
    m_equalVertexThreshold = this->m_equalVertexThreshold;
    v9 = ((unsigned int)(m_numVertices - 4) >> 2) + 1;
    v15 = 4 * v9;
    v3 = 0;
    v10 = &this->m_simplexVectorW[0].mVec128.m128_f32[2];
    do
    {
      if ( m_equalVertexThreshold >= (float)((float)((float)((float)(v5 - *(v10 - 2)) * (float)(v5 - *(v10 - 2)))
                                                   + (float)((float)(v7 - *v10) * (float)(v7 - *v10)))
                                           + (float)((float)(v6 - *(v10 - 1)) * (float)(v6 - *(v10 - 1)))) )
        v3 = 1;
      if ( m_equalVertexThreshold >= (float)((float)((float)((float)(v5 - v10[2]) * (float)(v5 - v10[2]))
                                                   + (float)((float)(v7 - v10[4]) * (float)(v7 - v10[4])))
                                           + (float)((float)(v6 - v10[3]) * (float)(v6 - v10[3]))) )
        v3 = 1;
      if ( m_equalVertexThreshold >= (float)((float)((float)((float)(v5 - v10[6]) * (float)(v5 - v10[6]))
                                                   + (float)((float)(v7 - v10[8]) * (float)(v7 - v10[8])))
                                           + (float)((float)(v6 - v10[7]) * (float)(v6 - v10[7]))) )
        v3 = 1;
      if ( m_equalVertexThreshold >= (float)((float)((float)((float)(v5 - v10[10]) * (float)(v5 - v10[10]))
                                                   + (float)((float)(v7 - v10[12]) * (float)(v7 - v10[12])))
                                           + (float)((float)(v6 - v10[11]) * (float)(v6 - v10[11]))) )
        v3 = 1;
      v10 += 16;
      --v9;
    }
    while ( v9 );
    v4 = v15;
  }
  if ( v4 < m_numVertices )
  {
    v11 = &this->m_simplexVectorW[v4].mVec128.m128_f32[2];
    v12 = m_numVertices - v4;
    do
    {
      v13 = w->mVec128.m128_f32[1] - *(v11 - 1);
      if ( this->m_equalVertexThreshold >= (float)((float)((float)((float)(w->mVec128.m128_f32[0] - *(v11 - 2))
                                                                 * (float)(w->mVec128.m128_f32[0] - *(v11 - 2)))
                                                         + (float)((float)(w->mVec128.m128_f32[2] - *v11)
                                                                 * (float)(w->mVec128.m128_f32[2] - *v11)))
                                                 + (float)(v13 * v13)) )
        v3 = 1;
      v11 += 4;
      --v12;
    }
    while ( v12 );
  }
  if ( w->mVec128.m128_f32[3] != this->m_lastW.mVec128.m128_f32[3] )
    return v3;
  if ( w->mVec128.m128_f32[2] != this->m_lastW.mVec128.m128_f32[2] )
    return v3;
  if ( w->mVec128.m128_f32[1] != this->m_lastW.mVec128.m128_f32[1] )
    return v3;
  result = 1;
  if ( w->mVec128.m128_f32[0] != this->m_lastW.mVec128.m128_f32[0] )
    return v3;
  return result;
}
