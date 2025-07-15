void __thiscall SupportVertexCallback::processTriangle(
        SupportVertexCallback *this,
        btVector3 *triangle,
        int partId,
        int triangleIndex)
{
  int v5; // edx
  float v6; // xmm0_4

  v5 = 3;
  do
  {
    v6 = (float)((float)(triangle->mVec128.m128_f32[2] * this->m_supportVecLocal.mVec128.m128_f32[2])
               + (float)(triangle->mVec128.m128_f32[1] * this->m_supportVecLocal.mVec128.m128_f32[1]))
       + (float)(this->m_supportVecLocal.mVec128.m128_f32[0] * triangle->mVec128.m128_f32[0]);
    if ( v6 > this->m_maxDot )
    {
      this->m_maxDot = v6;
      this->m_supportVertexLocal = (btVector3)triangle->mVec128;
    }
    ++triangle;
    --v5;
  }
  while ( v5 );
}
