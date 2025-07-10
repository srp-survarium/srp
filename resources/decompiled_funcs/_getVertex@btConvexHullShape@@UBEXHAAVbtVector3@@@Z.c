void __thiscall btConvexHullShape::getVertex(btConvexHullShape *this, int i, btVector3 *vtx)
{
  btVector3 *v3; // eax
  btVector3 v4; // [esp+0h] [ebp-10h]

  v3 = &this->m_unscaledPoints.m_data[i];
  v4.mVec128.m128_f32[0] = this->m_localScaling.mVec128.m128_f32[0] * v3->mVec128.m128_f32[0];
  v4.mVec128.m128_f32[1] = this->m_localScaling.mVec128.m128_f32[1] * v3->mVec128.m128_f32[1];
  v4.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(this->m_localScaling.mVec128.m128_f32[2] * v3->mVec128.m128_f32[2]);
  *vtx = (btVector3)v4.mVec128;
}
