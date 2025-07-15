void __thiscall btConvexInternalShape::setLocalScaling(btConvexInternalShape *this, const btVector3 *scaling)
{
  unsigned __int64 v2; // [esp+Ch] [ebp-Ch]

  LODWORD(v2) = scaling->mVec128.m128_i32[1] & _mask__AbsFloat_;
  HIDWORD(v2) = scaling->mVec128.m128_i32[2] & _mask__AbsFloat_;
  this->m_localScaling.mVec128.m128_i32[0] = scaling->mVec128.m128_i32[0] & _mask__AbsFloat_;
  *(unsigned __int64 *)((char *)this->m_localScaling.mVec128.m128_u64 + 4) = v2;
  this->m_localScaling.mVec128.m128_i32[3] = 0;
}
