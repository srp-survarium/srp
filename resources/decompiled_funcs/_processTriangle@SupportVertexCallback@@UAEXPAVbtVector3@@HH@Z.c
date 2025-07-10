void __thiscall SupportVertexCallback::processTriangle(
        SupportVertexCallback *this,
        btVector3 *triangle,
        int partId,
        int triangleIndex)
{
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4

  v4 = (float)((float)(this->m_supportVecLocal.mVec128.m128_f32[2] * triangle->mVec128.m128_f32[2])
             + (float)(this->m_supportVecLocal.mVec128.m128_f32[1] * triangle->mVec128.m128_f32[1]))
     + (float)(this->m_supportVecLocal.mVec128.m128_f32[0] * triangle->mVec128.m128_f32[0]);
  if ( v4 > this->m_maxDot )
  {
    this->m_maxDot = v4;
    this->m_supportVertexLocal = (btVector3)triangle->mVec128;
  }
  v5 = (float)((float)(triangle[1].mVec128.m128_f32[2] * this->m_supportVecLocal.mVec128.m128_f32[2])
             + (float)(triangle[1].mVec128.m128_f32[1] * this->m_supportVecLocal.mVec128.m128_f32[1]))
     + (float)(this->m_supportVecLocal.mVec128.m128_f32[0] * triangle[1].mVec128.m128_f32[0]);
  if ( v5 > this->m_maxDot )
  {
    this->m_maxDot = v5;
    this->m_supportVertexLocal = (btVector3)triangle[1].mVec128;
  }
  v6 = (float)((float)(triangle[2].mVec128.m128_f32[2] * this->m_supportVecLocal.mVec128.m128_f32[2])
             + (float)(triangle[2].mVec128.m128_f32[1] * this->m_supportVecLocal.mVec128.m128_f32[1]))
     + (float)(this->m_supportVecLocal.mVec128.m128_f32[0] * triangle[2].mVec128.m128_f32[0]);
  if ( v6 > this->m_maxDot )
  {
    this->m_maxDot = v6;
    this->m_supportVertexLocal = (btVector3)triangle[2].mVec128;
  }
}
