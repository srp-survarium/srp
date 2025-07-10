void __fastcall btQuantizedBvh::setInternalNodeAabbMin(int nodeIndex, const btVector3 *aabbMin, btQuantizedBvh *this)
{
  float v3; // xmm2_4
  btQuantizedBvhNode *v4; // ecx
  float v5; // xmm0_4
  float v6; // xmm1_4

  if ( this->m_useQuantization )
  {
    v3 = aabbMin->mVec128.m128_f32[2] - this->m_bvhAabbMin.mVec128.m128_f32[2];
    v4 = &this->m_quantizedContiguousNodes.m_data[nodeIndex];
    v5 = this->m_bvhQuantization.mVec128.m128_f32[1]
       * (float)(aabbMin->mVec128.m128_f32[1] - this->m_bvhAabbMin.mVec128.m128_f32[1]);
    v6 = this->m_bvhQuantization.mVec128.m128_f32[2];
    v4->m_quantizedAabbMin[0] = (int)(float)(this->m_bvhQuantization.mVec128.m128_f32[0]
                                           * (float)(aabbMin->mVec128.m128_f32[0]
                                                   - this->m_bvhAabbMin.mVec128.m128_f32[0]))
                              & 0xFFFE;
    v4->m_quantizedAabbMin[1] = (int)v5 & 0xFFFE;
    v4->m_quantizedAabbMin[2] = (int)(float)(v6 * v3) & 0xFFFE;
  }
  else
  {
    this->m_contiguousNodes.m_data[nodeIndex].m_aabbMinOrg = (btVector3)aabbMin->mVec128;
  }
}
