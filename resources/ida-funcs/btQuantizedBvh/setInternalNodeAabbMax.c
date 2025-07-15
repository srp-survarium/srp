void __fastcall btQuantizedBvh::setInternalNodeAabbMax(int nodeIndex, const btVector3 *aabbMax, btQuantizedBvh *this)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  const vostok::math::float4x4 *v5; // xmm3_4
  unsigned __int16 *m_quantizedAabbMax; // ecx

  if ( this->m_useQuantization )
  {
    v3 = this->m_bvhQuantization.mVec128.m128_f32[1]
       * (float)(aabbMax->mVec128.m128_f32[1] - this->m_bvhAabbMin.mVec128.m128_f32[1]);
    v4 = this->m_bvhQuantization.mVec128.m128_f32[2]
       * (float)(aabbMax->mVec128.m128_f32[2] - this->m_bvhAabbMin.mVec128.m128_f32[2]);
    v5 = clear_value;
    m_quantizedAabbMax = this->m_quantizedContiguousNodes.m_data[nodeIndex].m_quantizedAabbMax;
    *m_quantizedAabbMax = (int)(float)((float)(this->m_bvhQuantization.mVec128.m128_f32[0]
                                             * (float)(aabbMax->mVec128.m128_f32[0]
                                                     - this->m_bvhAabbMin.mVec128.m128_f32[0]))
                                     + *(float *)&clear_value)
                        | 1;
    m_quantizedAabbMax[1] = (int)(float)(v3 + *(float *)&v5) | 1;
    m_quantizedAabbMax[2] = (int)(float)(v4 + *(float *)&v5) | 1;
  }
  else
  {
    this->m_contiguousNodes.m_data[nodeIndex].m_aabbMaxOrg = (btVector3)aabbMax->mVec128;
  }
}
