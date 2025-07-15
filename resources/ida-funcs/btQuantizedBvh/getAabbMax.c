btVector3 *__userpurge btQuantizedBvh::getAabbMax@<eax>(
        int nodeIndex@<edx>,
        btVector3 *result@<eax>,
        btQuantizedBvh *this)
{
  btQuantizedBvhNode *m_data; // esi
  unsigned __int16 *m_quantizedAabbMax; // edx
  float v5; // xmm0_4
  int v6; // esi
  int v7; // edx
  btVector3 *p_m_aabbMaxOrg; // ecx

  if ( this->m_useQuantization )
  {
    m_data = this->m_quantizedLeafNodes.m_data;
    result->mVec128.m128_i32[3] = 0;
    m_quantizedAabbMax = m_data[nodeIndex].m_quantizedAabbMax;
    v5 = (float)((float)*m_quantizedAabbMax / this->m_bvhQuantization.mVec128.m128_f32[0])
       + this->m_bvhAabbMin.mVec128.m128_f32[0];
    v6 = m_quantizedAabbMax[1];
    v7 = m_quantizedAabbMax[2];
    result->mVec128.m128_f32[0] = v5;
    result->mVec128.m128_f32[1] = (float)((float)v6 / this->m_bvhQuantization.mVec128.m128_f32[1])
                                + this->m_bvhAabbMin.mVec128.m128_f32[1];
    result->mVec128.m128_f32[2] = (float)((float)v7 / this->m_bvhQuantization.mVec128.m128_f32[2])
                                + this->m_bvhAabbMin.mVec128.m128_f32[2];
  }
  else
  {
    p_m_aabbMaxOrg = &this->m_leafNodes.m_data[nodeIndex].m_aabbMaxOrg;
    *result = (btVector3)p_m_aabbMaxOrg->mVec128;
  }
  return result;
}
