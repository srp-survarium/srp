char __fastcall btVoronoiSimplexSolver::inSimplex(btVoronoiSimplexSolver *this, const btVector3 *w)
{
  int m_numVertices; // eax
  float *v3; // esi
  char result; // al
  char v5; // [esp+Fh] [ebp-1h]

  m_numVertices = this->m_numVertices;
  v5 = 0;
  if ( this->m_numVertices > 0 )
  {
    v3 = &this->m_simplexVectorW[0].mVec128.m128_f32[2];
    do
    {
      if ( this->m_equalVertexThreshold >= (float)((float)((float)((float)(w->mVec128.m128_f32[0] - *(v3 - 2))
                                                                 * (float)(w->mVec128.m128_f32[0] - *(v3 - 2)))
                                                         + (float)((float)(w->mVec128.m128_f32[2] - *v3)
                                                                 * (float)(w->mVec128.m128_f32[2] - *v3)))
                                                 + (float)((float)(w->mVec128.m128_f32[1] - *(v3 - 1))
                                                         * (float)(w->mVec128.m128_f32[1] - *(v3 - 1)))) )
        v5 = 1;
      v3 += 4;
      --m_numVertices;
    }
    while ( m_numVertices );
  }
  if ( w->mVec128.m128_f32[3] != this->m_lastW.mVec128.m128_f32[3] )
    return v5;
  if ( w->mVec128.m128_f32[2] != this->m_lastW.mVec128.m128_f32[2] )
    return v5;
  if ( w->mVec128.m128_f32[1] != this->m_lastW.mVec128.m128_f32[1] )
    return v5;
  result = 1;
  if ( w->mVec128.m128_f32[0] != this->m_lastW.mVec128.m128_f32[0] )
    return v5;
  return result;
}
