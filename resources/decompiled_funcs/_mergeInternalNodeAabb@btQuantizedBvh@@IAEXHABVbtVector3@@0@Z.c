void __fastcall btQuantizedBvh::mergeInternalNodeAabb(
        const btVector3 *newAabbMin,
        const btVector3 *newAabbMax,
        btQuantizedBvh *this,
        int nodeIndex)
{
  float v4; // xmm0_4
  float v5; // xmm3_4
  float v6; // xmm1_4
  unsigned __int16 v7; // cx
  unsigned __int16 v8; // si
  btQuantizedBvhNode *v9; // ebx
  unsigned __int16 v10; // dx
  btQuantizedBvhNode *m_data; // ecx
  bool v12; // cf
  unsigned __int16 *m_quantizedAabbMax; // ecx
  btQuantizedBvhNode *v14; // edx
  btQuantizedBvhNode *v15; // ecx
  unsigned __int16 *v16; // ecx
  unsigned __int16 *v17; // ecx
  btQuantizedBvhNode *v18; // eax
  unsigned __int16 *v19; // eax
  int v20; // edi
  btOptimizedBvhNode *v21; // esi
  float v22; // xmm1_4
  float *m128_f32; // esi
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  btOptimizedBvhNode *v27; // ecx
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  unsigned __int16 v31; // [esp+Ah] [ebp-Eh]
  unsigned __int16 v32; // [esp+Ch] [ebp-Ch]
  unsigned __int16 quantizedAabbMin_4; // [esp+14h] [ebp-4h]

  v4 = newAabbMin->mVec128.m128_f32[0];
  if ( this->m_useQuantization )
  {
    v5 = this->m_bvhQuantization.mVec128.m128_f32[1]
       * (float)(newAabbMin->mVec128.m128_f32[1] - this->m_bvhAabbMin.mVec128.m128_f32[1]);
    v6 = this->m_bvhQuantization.mVec128.m128_f32[2]
       * (float)(newAabbMin->mVec128.m128_f32[2] - this->m_bvhAabbMin.mVec128.m128_f32[2]);
    v7 = (int)(float)((float)(v4 - this->m_bvhAabbMin.mVec128.m128_f32[0]) * this->m_bvhQuantization.mVec128.m128_f32[0])
       & 0xFFFE;
    v8 = (int)v5 & 0xFFFE;
    quantizedAabbMin_4 = (int)v6 & 0xFFFE;
    v31 = (int)(float)((float)(this->m_bvhQuantization.mVec128.m128_f32[1]
                             * (float)(newAabbMax->mVec128.m128_f32[1] - this->m_bvhAabbMin.mVec128.m128_f32[1]))
                     + *(float *)&clear_value)
        | 1;
    v32 = (int)(float)((float)(this->m_bvhQuantization.mVec128.m128_f32[2]
                             * (float)(newAabbMax->mVec128.m128_f32[2] - this->m_bvhAabbMin.mVec128.m128_f32[2]))
                     + *(float *)&clear_value)
        | 1;
    v9 = &this->m_quantizedContiguousNodes.m_data[nodeIndex];
    v10 = (int)(float)((float)(this->m_bvhQuantization.mVec128.m128_f32[0]
                             * (float)(newAabbMax->mVec128.m128_f32[0] - this->m_bvhAabbMin.mVec128.m128_f32[0]))
                     + *(float *)&clear_value)
        | 1;
    if ( v9->m_quantizedAabbMin[0] > v7 )
      v9->m_quantizedAabbMin[0] = v7;
    m_data = this->m_quantizedContiguousNodes.m_data;
    v12 = m_data[nodeIndex].m_quantizedAabbMax[0] < v10;
    m_quantizedAabbMax = m_data[nodeIndex].m_quantizedAabbMax;
    if ( v12 )
      *m_quantizedAabbMax = v10;
    v14 = this->m_quantizedContiguousNodes.m_data;
    if ( v14[nodeIndex].m_quantizedAabbMin[1] > v8 )
      v14[nodeIndex].m_quantizedAabbMin[1] = v8;
    v15 = this->m_quantizedContiguousNodes.m_data;
    v12 = v15[nodeIndex].m_quantizedAabbMax[1] < v31;
    v16 = &v15[nodeIndex].m_quantizedAabbMax[1];
    if ( v12 )
      *v16 = v31;
    v17 = &this->m_quantizedContiguousNodes.m_data[nodeIndex].m_quantizedAabbMin[2];
    if ( *v17 > quantizedAabbMin_4 )
      *v17 = quantizedAabbMin_4;
    v18 = this->m_quantizedContiguousNodes.m_data;
    v12 = v18[nodeIndex].m_quantizedAabbMax[2] < v32;
    v19 = &v18[nodeIndex].m_quantizedAabbMax[2];
    if ( v12 )
      *v19 = v32;
  }
  else
  {
    v20 = nodeIndex << 6;
    v21 = this->m_contiguousNodes.m_data;
    v22 = v21[nodeIndex].m_aabbMinOrg.mVec128.m128_f32[0];
    m128_f32 = v21[nodeIndex].m_aabbMinOrg.mVec128.m128_f32;
    if ( v22 > v4 )
      *m128_f32 = v4;
    v24 = newAabbMin->mVec128.m128_f32[1];
    if ( m128_f32[1] > v24 )
      m128_f32[1] = v24;
    v25 = newAabbMin->mVec128.m128_f32[2];
    if ( m128_f32[2] > v25 )
      m128_f32[2] = v25;
    v26 = newAabbMin->mVec128.m128_f32[3];
    if ( m128_f32[3] > v26 )
      m128_f32[3] = v26;
    v27 = this->m_contiguousNodes.m_data;
    if ( newAabbMax->mVec128.m128_f32[0] > *(float *)((char *)v27->m_aabbMaxOrg.mVec128.m128_f32 + v20) )
      *(int *)((char *)v27->m_aabbMaxOrg.mVec128.m128_i32 + v20) = newAabbMax->mVec128.m128_i32[0];
    v28 = newAabbMax->mVec128.m128_f32[1];
    if ( v28 > *(float *)((char *)&v27->m_aabbMaxOrg.mVec128.m128_f32[1] + v20) )
      *(float *)((char *)&v27->m_aabbMaxOrg.mVec128.m128_f32[1] + v20) = v28;
    v29 = newAabbMax->mVec128.m128_f32[2];
    if ( v29 > *(float *)((char *)&v27->m_aabbMaxOrg.mVec128.m128_f32[2] + v20) )
      *(float *)((char *)&v27->m_aabbMaxOrg.mVec128.m128_f32[2] + v20) = v29;
    v30 = newAabbMax->mVec128.m128_f32[3];
    if ( v30 > *(float *)((char *)&v27->m_aabbMaxOrg.mVec128.m128_f32[3] + v20) )
      *(float *)((char *)&v27->m_aabbMaxOrg.mVec128.m128_f32[3] + v20) = v30;
  }
}
