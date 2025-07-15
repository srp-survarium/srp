int __userpurge btPersistentManifold::getCacheEntry@<eax>(
        const btManifoldPoint *newPoint@<eax>,
        btPersistentManifold *this)
{
  btPersistentManifold *v2; // edx
  int m_cachedPoints; // edi
  int result; // eax
  int v6; // ecx
  float v7; // xmm0_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  float *v11; // edx
  float *v12; // edx

  v2 = this;
  m_cachedPoints = this->m_cachedPoints;
  result = -1;
  v6 = 0;
  v7 = this->m_contactBreakingThreshold * this->m_contactBreakingThreshold;
  if ( m_cachedPoints >= 4 )
  {
    v8 = newPoint->m_localPointA.mVec128.m128_f32[0];
    v9 = newPoint->m_localPointA.mVec128.m128_f32[1];
    v10 = newPoint->m_localPointA.mVec128.m128_f32[2];
    v11 = &this->m_pointCache[0].m_localPointA.mVec128.m128_f32[2];
    do
    {
      if ( v7 > (float)((float)((float)((float)(*(v11 - 2) - v8) * (float)(*(v11 - 2) - v8))
                              + (float)((float)(*(v11 - 1) - v9) * (float)(*(v11 - 1) - v9)))
                      + (float)((float)(*v11 - v10) * (float)(*v11 - v10))) )
      {
        v7 = (float)((float)((float)(*(v11 - 2) - v8) * (float)(*(v11 - 2) - v8))
                   + (float)((float)(*(v11 - 1) - v9) * (float)(*(v11 - 1) - v9)))
           + (float)((float)(*v11 - v10) * (float)(*v11 - v10));
        result = v6;
      }
      if ( v7 > (float)((float)((float)((float)(v11[70] - v8) * (float)(v11[70] - v8))
                              + (float)((float)(v11[71] - v9) * (float)(v11[71] - v9)))
                      + (float)((float)(v11[72] - v10) * (float)(v11[72] - v10))) )
      {
        v7 = (float)((float)((float)(v11[70] - v8) * (float)(v11[70] - v8))
                   + (float)((float)(v11[71] - v9) * (float)(v11[71] - v9)))
           + (float)((float)(v11[72] - v10) * (float)(v11[72] - v10));
        result = v6 + 1;
      }
      if ( v7 > (float)((float)((float)((float)(v11[142] - v8) * (float)(v11[142] - v8))
                              + (float)((float)(v11[143] - v9) * (float)(v11[143] - v9)))
                      + (float)((float)(v11[144] - v10) * (float)(v11[144] - v10))) )
      {
        v7 = (float)((float)((float)(v11[142] - v8) * (float)(v11[142] - v8))
                   + (float)((float)(v11[143] - v9) * (float)(v11[143] - v9)))
           + (float)((float)(v11[144] - v10) * (float)(v11[144] - v10));
        result = v6 + 2;
      }
      if ( v7 > (float)((float)((float)((float)(v11[214] - v8) * (float)(v11[214] - v8))
                              + (float)((float)(v11[215] - v9) * (float)(v11[215] - v9)))
                      + (float)((float)(v11[216] - v10) * (float)(v11[216] - v10))) )
      {
        v7 = (float)((float)((float)(v11[214] - v8) * (float)(v11[214] - v8))
                   + (float)((float)(v11[215] - v9) * (float)(v11[215] - v9)))
           + (float)((float)(v11[216] - v10) * (float)(v11[216] - v10));
        result = v6 + 3;
      }
      v6 += 4;
      v11 += 288;
    }
    while ( v6 < m_cachedPoints - 3 );
    v2 = this;
  }
  if ( v6 < m_cachedPoints )
  {
    v12 = &v2->m_pointCache[v6].m_localPointA.mVec128.m128_f32[2];
    do
    {
      if ( v7 > (float)((float)((float)((float)(*(v12 - 2) - newPoint->m_localPointA.mVec128.m128_f32[0])
                                      * (float)(*(v12 - 2) - newPoint->m_localPointA.mVec128.m128_f32[0]))
                              + (float)((float)(*(v12 - 1) - newPoint->m_localPointA.mVec128.m128_f32[1])
                                      * (float)(*(v12 - 1) - newPoint->m_localPointA.mVec128.m128_f32[1])))
                      + (float)((float)(*v12 - newPoint->m_localPointA.mVec128.m128_f32[2])
                              * (float)(*v12 - newPoint->m_localPointA.mVec128.m128_f32[2]))) )
      {
        v7 = (float)((float)((float)(*(v12 - 2) - newPoint->m_localPointA.mVec128.m128_f32[0])
                           * (float)(*(v12 - 2) - newPoint->m_localPointA.mVec128.m128_f32[0]))
                   + (float)((float)(*(v12 - 1) - newPoint->m_localPointA.mVec128.m128_f32[1])
                           * (float)(*(v12 - 1) - newPoint->m_localPointA.mVec128.m128_f32[1])))
           + (float)((float)(*v12 - newPoint->m_localPointA.mVec128.m128_f32[2])
                   * (float)(*v12 - newPoint->m_localPointA.mVec128.m128_f32[2]));
        result = v6;
      }
      ++v6;
      v12 += 72;
    }
    while ( v6 < m_cachedPoints );
  }
  return result;
}
