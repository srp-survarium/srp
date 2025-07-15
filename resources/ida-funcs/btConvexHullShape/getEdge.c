void __thiscall btConvexHullShape::getEdge(btConvexHullShape *this, int i, btVector3 *pa, btVector3 *pb)
{
  int m_size; // ebx
  btVector3 *v5; // edx
  btVector3 *v6; // edx
  unsigned __int64 v7; // [esp+Ch] [ebp-Ch]

  m_size = this->m_unscaledPoints.m_size;
  v5 = &this->m_unscaledPoints.m_data[i % m_size];
  *(float *)&v7 = this->m_localScaling.mVec128.m128_f32[1] * v5->mVec128.m128_f32[1];
  *((float *)&v7 + 1) = this->m_localScaling.mVec128.m128_f32[2] * v5->mVec128.m128_f32[2];
  pa->mVec128.m128_f32[0] = this->m_localScaling.mVec128.m128_f32[0] * v5->mVec128.m128_f32[0];
  *(unsigned __int64 *)((char *)pa->mVec128.m128_u64 + 4) = v7;
  pa->mVec128.m128_i32[3] = 0;
  v6 = &this->m_unscaledPoints.m_data[(i + 1) % m_size];
  *(float *)&v7 = this->m_localScaling.mVec128.m128_f32[1] * v6->mVec128.m128_f32[1];
  *((float *)&v7 + 1) = this->m_localScaling.mVec128.m128_f32[2] * v6->mVec128.m128_f32[2];
  pb->mVec128.m128_f32[0] = this->m_localScaling.mVec128.m128_f32[0] * v6->mVec128.m128_f32[0];
  *(unsigned __int64 *)((char *)pb->mVec128.m128_u64 + 4) = v7;
  pb->mVec128.m128_i32[3] = 0;
}
