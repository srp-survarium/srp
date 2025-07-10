void __thiscall btConvexHullShape::getEdge(btConvexHullShape *this, int i, btVector3 *pa, btVector3 *pb)
{
  int m_size; // esi
  btVector3 *v5; // edx
  unsigned int v6; // xmm0_4
  btVector3 *v7; // edx
  unsigned int v8; // xmm1_4
  unsigned __int64 v9; // [esp+10h] [ebp-10h]

  m_size = this->m_unscaledPoints.m_size;
  v5 = &this->m_unscaledPoints.m_data[i % m_size];
  *(float *)&v9 = this->m_localScaling.mVec128.m128_f32[0] * v5->mVec128.m128_f32[0];
  *((float *)&v9 + 1) = this->m_localScaling.mVec128.m128_f32[1] * v5->mVec128.m128_f32[1];
  *(float *)&v6 = this->m_localScaling.mVec128.m128_f32[2] * v5->mVec128.m128_f32[2];
  pa->mVec128.m128_u64[0] = v9;
  pa->mVec128.m128_u64[1] = v6;
  v7 = &this->m_unscaledPoints.m_data[(i + 1) % m_size];
  *(float *)&v9 = this->m_localScaling.mVec128.m128_f32[0] * v7->mVec128.m128_f32[0];
  *((float *)&v9 + 1) = this->m_localScaling.mVec128.m128_f32[1] * v7->mVec128.m128_f32[1];
  *(float *)&v8 = this->m_localScaling.mVec128.m128_f32[2] * v7->mVec128.m128_f32[2];
  pb->mVec128.m128_u64[0] = v9;
  pb->mVec128.m128_u64[1] = v8;
}
