void __userpurge btQuantizedBvh::setQuantizationValues(
        const btVector3 *bvhAabbMin@<edx>,
        const btVector3 *bvhAabbMax@<ecx>,
        btQuantizedBvh *this,
        float quantizationMargin)
{
  const vostok::math::float4x4 *v4; // xmm0_4
  unsigned int v6; // xmm1_4
  unsigned __int64 v7; // [esp+0h] [ebp-10h]
  unsigned int v8; // [esp+8h] [ebp-8h]
  unsigned int v9; // [esp+8h] [ebp-8h]

  v4 = clear_value;
  *(float *)&v7 = bvhAabbMin->mVec128.m128_f32[0] - *(float *)&clear_value;
  *((float *)&v7 + 1) = bvhAabbMin->mVec128.m128_f32[1] - *(float *)&clear_value;
  *(float *)&v8 = bvhAabbMin->mVec128.m128_f32[2] - *(float *)&clear_value;
  this->m_bvhAabbMin.mVec128.m128_u64[0] = v7;
  this->m_bvhAabbMin.mVec128.m128_u64[1] = v8;
  *(float *)&v7 = bvhAabbMax->mVec128.m128_f32[0] + *(float *)&v4;
  *((float *)&v7 + 1) = bvhAabbMax->mVec128.m128_f32[1] + *(float *)&v4;
  *(float *)&v6 = bvhAabbMax->mVec128.m128_f32[2] + *(float *)&v4;
  this->m_bvhAabbMax.mVec128.m128_u64[0] = v7;
  this->m_bvhAabbMax.mVec128.m128_u64[1] = v6;
  *(float *)&v9 = 65533.0 / (float)(this->m_bvhAabbMax.mVec128.m128_f32[2] - this->m_bvhAabbMin.mVec128.m128_f32[2]);
  *(float *)&v7 = 65533.0 / (float)(this->m_bvhAabbMax.mVec128.m128_f32[0] - this->m_bvhAabbMin.mVec128.m128_f32[0]);
  *((float *)&v7 + 1) = 65533.0
                      / (float)(this->m_bvhAabbMax.mVec128.m128_f32[1] - this->m_bvhAabbMin.mVec128.m128_f32[1]);
  this->m_bvhQuantization.mVec128.m128_u64[0] = v7;
  this->m_bvhQuantization.mVec128.m128_u64[1] = v9;
  this->m_useQuantization = 1;
}
