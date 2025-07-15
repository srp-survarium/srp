bool __thiscall btBoxShape::isInside(btBoxShape *this, const btVector3 *pt, float tolerance)
{
  float v3; // xmm2_4
  float v4; // xmm2_4
  bool result; // al
  btVector3 v6; // [esp+10h] [ebp-10h]

  v6.mVec128 = (__m128)this->m_implicitShapeDimensions;
  result = 0;
  if ( (float)(v6.mVec128.m128_f32[0] + tolerance) >= pt->mVec128.m128_f32[0]
    && pt->mVec128.m128_f32[0] >= (float)((float)-v6.mVec128.m128_f32[0] - tolerance) )
  {
    v3 = pt->mVec128.m128_f32[1];
    if ( (float)(v6.mVec128.m128_f32[1] + tolerance) >= v3 && v3 >= (float)((float)-v6.mVec128.m128_f32[1] - tolerance) )
    {
      v4 = pt->mVec128.m128_f32[2];
      if ( (float)(v6.mVec128.m128_f32[2] + tolerance) >= v4
        && v4 >= (float)((float)-v6.mVec128.m128_f32[2] - tolerance) )
      {
        return 1;
      }
    }
  }
  return result;
}
