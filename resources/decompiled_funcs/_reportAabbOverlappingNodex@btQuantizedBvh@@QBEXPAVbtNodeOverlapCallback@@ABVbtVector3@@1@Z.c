void __userpurge btQuantizedBvh::reportAabbOverlappingNodex(
        const btVector3 *aabbMin@<eax>,
        const btVector3 *aabbMax@<edx>,
        btQuantizedBvh *this,
        btNodeOverlapCallback *nodeCallback)
{
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  int v10; // eax
  unsigned __int64 v11; // xmm0_8
  float v12; // xmm3_4
  float v13; // xmm1_4
  int v14; // eax
  float v15; // xmm1_4
  unsigned __int64 v16; // xmm0_8
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm3_4
  float v21; // xmm2_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  btQuantizedBvh::btTraversalMode m_traversalMode; // eax
  __int32 v26; // eax
  unsigned __int16 v27[4]; // [esp+48h] [ebp-20h] BYREF
  unsigned __int16 v28[4]; // [esp+50h] [ebp-18h] BYREF
  btVector3 v29; // [esp+58h] [ebp-10h]

  if ( this->m_useQuantization )
  {
    v29.mVec128 = aabbMin->mVec128;
    v4 = v29.mVec128.m128_f32[0];
    if ( this->m_bvhAabbMin.mVec128.m128_f32[0] > v29.mVec128.m128_f32[0] )
      v4 = this->m_bvhAabbMin.mVec128.m128_f32[0];
    v5 = v29.mVec128.m128_f32[1];
    if ( this->m_bvhAabbMin.mVec128.m128_f32[1] > v29.mVec128.m128_f32[1] )
      v5 = this->m_bvhAabbMin.mVec128.m128_f32[1];
    v6 = v29.mVec128.m128_f32[2];
    if ( this->m_bvhAabbMin.mVec128.m128_f32[2] > v29.mVec128.m128_f32[2] )
      v6 = this->m_bvhAabbMin.mVec128.m128_f32[2];
    if ( v4 > this->m_bvhAabbMax.mVec128.m128_f32[0] )
      v4 = this->m_bvhAabbMax.mVec128.m128_f32[0];
    if ( v5 > this->m_bvhAabbMax.mVec128.m128_f32[1] )
      v5 = this->m_bvhAabbMax.mVec128.m128_f32[1];
    if ( v6 > this->m_bvhAabbMax.mVec128.m128_f32[2] )
      v6 = this->m_bvhAabbMax.mVec128.m128_f32[2];
    v7 = v6 - this->m_bvhAabbMin.mVec128.m128_f32[2];
    v8 = this->m_bvhQuantization.mVec128.m128_f32[0] * (float)(v4 - this->m_bvhAabbMin.mVec128.m128_f32[0]);
    v9 = this->m_bvhQuantization.mVec128.m128_f32[2];
    v10 = (int)v8;
    v11 = aabbMax->mVec128.m128_u64[0];
    v12 = v5 - this->m_bvhAabbMin.mVec128.m128_f32[1];
    v13 = this->m_bvhQuantization.mVec128.m128_f32[1];
    v28[0] = v10 & 0xFFFE;
    v14 = (int)(float)(v13 * v12);
    v15 = this->m_bvhAabbMin.mVec128.m128_f32[0];
    v29.mVec128.m128_u64[0] = v11;
    v16 = aabbMax->mVec128.m128_u64[1];
    v28[1] = v14 & 0xFFFE;
    v29.mVec128.m128_u64[1] = v16;
    v17 = v29.mVec128.m128_f32[0];
    v28[2] = (int)(float)(v9 * v7) & 0xFFFE;
    if ( v15 > v29.mVec128.m128_f32[0] )
      v17 = v15;
    v18 = v29.mVec128.m128_f32[1];
    if ( this->m_bvhAabbMin.mVec128.m128_f32[1] > v29.mVec128.m128_f32[1] )
      v18 = this->m_bvhAabbMin.mVec128.m128_f32[1];
    v19 = v29.mVec128.m128_f32[2];
    if ( this->m_bvhAabbMin.mVec128.m128_f32[2] > v29.mVec128.m128_f32[2] )
      v19 = this->m_bvhAabbMin.mVec128.m128_f32[2];
    if ( v17 > this->m_bvhAabbMax.mVec128.m128_f32[0] )
      v17 = this->m_bvhAabbMax.mVec128.m128_f32[0];
    if ( v18 > this->m_bvhAabbMax.mVec128.m128_f32[1] )
      v18 = this->m_bvhAabbMax.mVec128.m128_f32[1];
    if ( v19 > this->m_bvhAabbMax.mVec128.m128_f32[2] )
      v19 = this->m_bvhAabbMax.mVec128.m128_f32[2];
    v20 = v18 - this->m_bvhAabbMin.mVec128.m128_f32[1];
    v21 = (float)(v17 - this->m_bvhAabbMin.mVec128.m128_f32[0]) * this->m_bvhQuantization.mVec128.m128_f32[0];
    v22 = v19 - this->m_bvhAabbMin.mVec128.m128_f32[2];
    v23 = this->m_bvhQuantization.mVec128.m128_f32[2];
    v24 = (float)(this->m_bvhQuantization.mVec128.m128_f32[1] * v20) + *(float *)&clear_value;
    v27[0] = (int)(float)(v21 + *(float *)&clear_value) | 1;
    v27[1] = (int)v24 | 1;
    m_traversalMode = this->m_traversalMode;
    v27[2] = (int)(float)((float)(v23 * v22) + *(float *)&clear_value) | 1;
    if ( m_traversalMode )
    {
      v26 = m_traversalMode - 1;
      if ( v26 )
      {
        if ( v26 == 1 )
          btQuantizedBvh::walkRecursiveQuantizedTreeAgainstQueryAabb(
            this,
            this->m_quantizedContiguousNodes.m_data,
            nodeCallback,
            v28,
            v27);
      }
      else
      {
        btQuantizedBvh::walkStacklessQuantizedTreeCacheFriendly(v28, v27, this, nodeCallback);
      }
    }
    else
    {
      btQuantizedBvh::walkStacklessQuantizedTree(this, 0, nodeCallback, v28, v27, this->m_curNodeIndex);
    }
  }
  else
  {
    btQuantizedBvh::walkStacklessTree(this, this, nodeCallback, aabbMin, aabbMax);
  }
}
