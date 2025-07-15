void __thiscall btConvexHullShape::getVertex(btConvexHullShape *this, int i, btVector3 *vtx)
{
  btVector3 *v3; // eax
  unsigned __int64 v4; // [esp+Ch] [ebp-Ch]

  v3 = &this->m_unscaledPoints.m_data[i];
  *(float *)&v4 = this->m_localScaling.mVec128.m128_f32[1] * v3->mVec128.m128_f32[1];
  *((float *)&v4 + 1) = this->m_localScaling.mVec128.m128_f32[2] * v3->mVec128.m128_f32[2];
  vtx->mVec128.m128_f32[0] = this->m_localScaling.mVec128.m128_f32[0] * v3->mVec128.m128_f32[0];
  *(unsigned __int64 *)((char *)vtx->mVec128.m128_u64 + 4) = v4;
  vtx->mVec128.m128_i32[3] = 0;
}
