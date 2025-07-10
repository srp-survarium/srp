void __userpurge btAxisSweep3Internal<unsigned short>::quantize(
        unsigned __int16 *out@<esi>,
        const btVector3 *point@<edx>,
        unsigned __int16 isMax@<cx>,
        btAxisSweep3Internal<unsigned short> *this)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  unsigned __int16 v7; // dx
  int v8; // edx
  unsigned __int16 v9; // dx
  int v10; // edx
  int v11; // edx

  v4 = this->m_quantize.mVec128.m128_f32[0]
     * (float)(point->mVec128.m128_f32[0] - this->m_worldAabbMin.mVec128.m128_f32[0]);
  v5 = this->m_quantize.mVec128.m128_f32[1]
     * (float)(point->mVec128.m128_f32[1] - this->m_worldAabbMin.mVec128.m128_f32[1]);
  v6 = this->m_quantize.mVec128.m128_f32[2]
     * (float)(point->mVec128.m128_f32[2] - this->m_worldAabbMin.mVec128.m128_f32[2]);
  if ( v4 > 0.0 )
  {
    LOWORD(v8) = this->m_handleSentinel;
    if ( v4 < (float)(unsigned __int16)v8 )
      v8 = (int)v4;
    v7 = isMax | v8 & this->m_bpHandleMask;
  }
  else
  {
    v7 = isMax;
  }
  *out = v7;
  if ( v5 > 0.0 )
  {
    LOWORD(v10) = this->m_handleSentinel;
    if ( v5 < (float)(unsigned __int16)v10 )
      v10 = (int)v5;
    v9 = isMax | v10 & this->m_bpHandleMask;
  }
  else
  {
    v9 = isMax;
  }
  out[1] = v9;
  if ( v6 > 0.0 )
  {
    LOWORD(v11) = this->m_handleSentinel;
    if ( v6 < (float)(unsigned __int16)v11 )
      v11 = (int)v6;
    out[2] = isMax | v11 & this->m_bpHandleMask;
  }
  else
  {
    out[2] = isMax;
  }
}
