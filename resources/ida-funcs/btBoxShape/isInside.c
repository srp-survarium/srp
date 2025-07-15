bool __thiscall btBoxShape::isInside(btBoxShape *this, const btVector3 *pt, float tolerance)
{
  float v3; // xmm2_4
  float v4; // xmm2_4
  bool result; // al
  unsigned __int64 v6; // [esp+0h] [ebp-10h]
  float v7; // [esp+8h] [ebp-8h]

  v6 = this->m_implicitShapeDimensions.mVec128.m128_u64[0];
  v7 = this->m_implicitShapeDimensions.mVec128.m128_f32[2];
  result = 0;
  if ( (float)(*(float *)&v6 + tolerance) >= pt->mVec128.m128_f32[0]
    && pt->mVec128.m128_f32[0] >= (float)(COERCE_FLOAT(v6 ^ _mask__NegFloat_) - tolerance) )
  {
    v3 = pt->mVec128.m128_f32[1];
    if ( (float)(*((float *)&v6 + 1) + tolerance) >= v3
      && v3 >= (float)(COERCE_FLOAT(HIDWORD(v6) ^ _mask__NegFloat_) - tolerance) )
    {
      v4 = pt->mVec128.m128_f32[2];
      if ( (float)(v7 + tolerance) >= v4 && v4 >= (float)(COERCE_FLOAT(LODWORD(v7) ^ _mask__NegFloat_) - tolerance) )
        return 1;
    }
  }
  return result;
}
