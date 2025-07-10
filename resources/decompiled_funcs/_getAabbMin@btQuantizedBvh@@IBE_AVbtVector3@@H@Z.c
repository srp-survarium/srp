btVector3 *__userpurge btQuantizedBvh::getAabbMin@<eax>(
        int nodeIndex@<edx>,
        btVector3 *result@<eax>,
        btQuantizedBvh *this)
{
  btQuantizedBvhNode *v3; // edx
  float v4; // xmm0_4
  int v5; // esi
  int v6; // edx
  btOptimizedBvhNode *m_data; // ecx
  int v8; // edx

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
    m_data = this->m_leafNodes.m_data;
    v8 = nodeIndex << 6;
    result->mVec128.m128_u64[0] = *(unsigned __int64 *)((char *)m_data->m_aabbMinOrg.mVec128.m128_u64 + v8);
    result->mVec128.m128_u64[1] = *(unsigned __int64 *)((char *)&m_data->m_aabbMinOrg.mVec128.m128_u64[1] + v8);
  }
  return result;
}
