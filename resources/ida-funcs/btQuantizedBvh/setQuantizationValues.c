void __userpurge btQuantizedBvh::setQuantizationValues(
        const btVector3 *bvhAabbMin@<eax>,
        const btVector3 *bvhAabbMax@<ecx>,
        btQuantizedBvh *this,
        float quantizationMargin)
{
  float v4; // xmm0_4
  unsigned int v6; // xmm2_4
  unsigned __int64 v7; // [esp+Ch] [ebp-Ch]

  v4 = s_bm_current_air_resistance;
  *(float *)&v7 = bvhAabbMin->mVec128.m128_f32[1] - s_bm_current_air_resistance;
  *((float *)&v7 + 1) = bvhAabbMin->mVec128.m128_f32[2] - s_bm_current_air_resistance;
  this->m_bvhAabbMin.mVec128.m128_f32[0] = bvhAabbMin->mVec128.m128_f32[0] - s_bm_current_air_resistance;
  *(unsigned __int64 *)((char *)this->m_bvhAabbMin.mVec128.m128_u64 + 4) = v7;
  this->m_bvhAabbMin.mVec128.m128_i32[3] = 0;
  *(float *)&v7 = bvhAabbMax->mVec128.m128_f32[1] + v4;
  *(float *)&v6 = bvhAabbMax->mVec128.m128_f32[2] + v4;
  this->m_bvhAabbMax.mVec128.m128_f32[0] = bvhAabbMax->mVec128.m128_f32[0] + v4;
  this->m_bvhAabbMax.mVec128.m128_i32[1] = v7;
  this->m_bvhAabbMax.mVec128.m128_u64[1] = v6;
  *(float *)&v7 = 65533.0 / (float)(this->m_bvhAabbMax.mVec128.m128_f32[1] - this->m_bvhAabbMin.mVec128.m128_f32[1]);
  *((float *)&v7 + 1) = 65533.0
                      / (float)(this->m_bvhAabbMax.mVec128.m128_f32[2] - this->m_bvhAabbMin.mVec128.m128_f32[2]);
  this->m_bvhQuantization.mVec128.m128_f32[0] = 65533.0
                                              / (float)(this->m_bvhAabbMax.mVec128.m128_f32[0]
                                                      - this->m_bvhAabbMin.mVec128.m128_f32[0]);
  *(unsigned __int64 *)((char *)this->m_bvhQuantization.mVec128.m128_u64 + 4) = v7;
  this->m_bvhQuantization.mVec128.m128_i32[3] = 0;
  this->m_useQuantization = 1;
}
