void __thiscall btConvexInternalShape::setLocalScaling(btConvexInternalShape *this, const btVector3 *scaling)
{
  btVector3 v3; // [esp+14h] [ebp-10h]

  v3.mVec128.m128_f32[0] = fabsf(scaling->mVec128.m128_f32[0]);
  v3.mVec128.m128_f32[1] = fabsf(scaling->mVec128.m128_f32[1]);
  v3.mVec128.m128_f32[2] = fabsf(scaling->mVec128.m128_f32[2]);
  v3.mVec128.m128_i32[3] = 0;
  this->m_localScaling = (btVector3)v3.mVec128;
}
