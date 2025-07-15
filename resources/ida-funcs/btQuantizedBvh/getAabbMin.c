btVector3 *__userpurge btQuantizedBvh::getAabbMin@<eax>(
        int nodeIndex@<edx>,
        btVector3 *result@<eax>,
        btQuantizedBvh *this)
{
  btQuantizedBvhNode *v3; // edx
  float v4; // xmm0_4
  int v5; // esi
  int v6; // edx
  btOptimizedBvhNode *v7; // esi

  if ( this->m_useQuantization )
  {
    v3 = &this->m_quantizedLeafNodes.m_data[nodeIndex];
    result->mVec128.m128_i32[3] = 0;
    v4 = (float)((float)v3->m_quantizedAabbMin[0] / this->m_bvhQuantization.mVec128.m128_f32[0])
       + this->m_bvhAabbMin.mVec128.m128_f32[0];
    v5 = v3->m_quantizedAabbMin[1];
    v6 = v3->m_quantizedAabbMin[2];
    result->mVec128.m128_f32[0] = v4;
    result->mVec128.m128_f32[1] = (float)((float)v5 / this->m_bvhQuantization.mVec128.m128_f32[1])
                                + this->m_bvhAabbMin.mVec128.m128_f32[1];
    result->mVec128.m128_f32[2] = (float)((float)v6 / this->m_bvhQuantization.mVec128.m128_f32[2])
                                + this->m_bvhAabbMin.mVec128.m128_f32[2];
  }
  else
  {
    v7 = &this->m_leafNodes.m_data[nodeIndex];
    result->mVec128.m128_i32[0] = v7->m_aabbMinOrg.mVec128.m128_i32[0];
    v7 = (btOptimizedBvhNode *)((char *)v7 + 4);
    result->mVec128.m128_i32[1] = v7->m_aabbMinOrg.mVec128.m128_i32[0];
    result->mVec128.m128_u64[1] = *(unsigned __int64 *)((char *)v7->m_aabbMinOrg.mVec128.m128_u64 + 4);
  }
  return result;
}
