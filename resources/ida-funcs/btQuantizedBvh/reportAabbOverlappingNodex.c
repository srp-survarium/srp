void __fastcall btQuantizedBvh::reportAabbOverlappingNodex(
        btQuantizedBvh *this,
        btNodeOverlapCallback *nodeCallback,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax)
{
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  unsigned __int16 v12; // si
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm4_4
  float v21; // xmm1_4
  btQuantizedBvh::btTraversalMode m_traversalMode; // eax
  __int32 v23; // eax
  unsigned __int16 quantizedQueryAabbMax[4]; // [esp+10h] [ebp-20h] BYREF
  unsigned __int16 quantizedQueryAabbMin[4]; // [esp+18h] [ebp-18h] BYREF
  btVector3 v26; // [esp+20h] [ebp-10h]

  if ( this->m_useQuantization )
  {
    v4 = this->m_bvhAabbMin.mVec128.m128_f32[0];
    v26.mVec128 = aabbMin->mVec128;
    v5 = v26.mVec128.m128_f32[0];
    if ( v4 > v26.mVec128.m128_f32[0] )
      v5 = v4;
    v6 = v26.mVec128.m128_f32[1];
    if ( this->m_bvhAabbMin.mVec128.m128_f32[1] > v26.mVec128.m128_f32[1] )
      v6 = this->m_bvhAabbMin.mVec128.m128_f32[1];
    v7 = v26.mVec128.m128_f32[2];
    if ( this->m_bvhAabbMin.mVec128.m128_f32[2] > v26.mVec128.m128_f32[2] )
      v7 = this->m_bvhAabbMin.mVec128.m128_f32[2];
    if ( v5 > this->m_bvhAabbMax.mVec128.m128_f32[0] )
      v5 = this->m_bvhAabbMax.mVec128.m128_f32[0];
    if ( v6 > this->m_bvhAabbMax.mVec128.m128_f32[1] )
      v6 = this->m_bvhAabbMax.mVec128.m128_f32[1];
    if ( v7 > this->m_bvhAabbMax.mVec128.m128_f32[2] )
      v7 = this->m_bvhAabbMax.mVec128.m128_f32[2];
    v8 = v6 - this->m_bvhAabbMin.mVec128.m128_f32[1];
    v9 = v7 - this->m_bvhAabbMin.mVec128.m128_f32[2];
    v10 = this->m_bvhQuantization.mVec128.m128_f32[0] * (float)(v5 - this->m_bvhAabbMin.mVec128.m128_f32[0]);
    v11 = this->m_bvhQuantization.mVec128.m128_f32[2];
    quantizedQueryAabbMin[0] = (int)v10 & 0xFFFE;
    v12 = (int)(float)(this->m_bvhQuantization.mVec128.m128_f32[1] * v8) & 0xFFFE;
    v13 = this->m_bvhAabbMin.mVec128.m128_f32[0];
    quantizedQueryAabbMin[1] = v12;
    quantizedQueryAabbMin[2] = (int)(float)(v11 * v9) & 0xFFFE;
    v26.mVec128 = aabbMax->mVec128;
    v14 = v26.mVec128.m128_f32[0];
    if ( v13 > v26.mVec128.m128_f32[0] )
      v14 = v13;
    v15 = v26.mVec128.m128_f32[1];
    if ( this->m_bvhAabbMin.mVec128.m128_f32[1] > v26.mVec128.m128_f32[1] )
      v15 = this->m_bvhAabbMin.mVec128.m128_f32[1];
    v16 = v26.mVec128.m128_f32[2];
    if ( this->m_bvhAabbMin.mVec128.m128_f32[2] > v26.mVec128.m128_f32[2] )
      v16 = this->m_bvhAabbMin.mVec128.m128_f32[2];
    if ( v14 > this->m_bvhAabbMax.mVec128.m128_f32[0] )
      v14 = this->m_bvhAabbMax.mVec128.m128_f32[0];
    if ( v15 > this->m_bvhAabbMax.mVec128.m128_f32[1] )
      v15 = this->m_bvhAabbMax.mVec128.m128_f32[1];
    if ( v16 > this->m_bvhAabbMax.mVec128.m128_f32[2] )
      v16 = this->m_bvhAabbMax.mVec128.m128_f32[2];
    v17 = v16 - this->m_bvhAabbMin.mVec128.m128_f32[2];
    v18 = (float)(v14 - this->m_bvhAabbMin.mVec128.m128_f32[0]) * this->m_bvhQuantization.mVec128.m128_f32[0];
    v19 = this->m_bvhQuantization.mVec128.m128_f32[1] * (float)(v15 - this->m_bvhAabbMin.mVec128.m128_f32[1]);
    quantizedQueryAabbMax[0] = (int)(float)(v18 + s_bm_current_air_resistance) | 1;
    v20 = v17;
    v21 = this->m_bvhQuantization.mVec128.m128_f32[2];
    quantizedQueryAabbMax[1] = (int)(float)(v19 + s_bm_current_air_resistance) | 1;
    quantizedQueryAabbMax[2] = (int)(float)((float)(v21 * v20) + s_bm_current_air_resistance) | 1;
    m_traversalMode = this->m_traversalMode;
    if ( m_traversalMode )
    {
      v23 = m_traversalMode - 1;
      if ( v23 )
      {
        if ( v23 == 1 )
          btQuantizedBvh::walkRecursiveQuantizedTreeAgainstQueryAabb(
            this,
            this->m_quantizedContiguousNodes.m_data,
            nodeCallback,
            quantizedQueryAabbMin,
            quantizedQueryAabbMax);
      }
      else
      {
        btQuantizedBvh::walkStacklessQuantizedTreeCacheFriendly(
          quantizedQueryAabbMin,
          quantizedQueryAabbMax,
          this,
          nodeCallback);
      }
    }
    else
    {
      btQuantizedBvh::walkStacklessQuantizedTree(
        this,
        0,
        nodeCallback,
        quantizedQueryAabbMin,
        quantizedQueryAabbMax,
        this->m_curNodeIndex);
    }
  }
  else
  {
    btQuantizedBvh::walkStacklessTree(
      this,
      (btNodeOverlapCallback *)this,
      (const btVector3 *)nodeCallback,
      aabbMin,
      aabbMax->mVec128.m128_f32);
  }
}
