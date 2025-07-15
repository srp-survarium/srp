void __fastcall btQuantizedBvh::mergeInternalNodeAabb(
        const btVector3 *newAabbMin,
        const btVector3 *newAabbMax,
        btQuantizedBvh *this,
        int nodeIndex)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  int v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  int v12; // edi
  float v13; // xmm3_4
  int v14; // edi
  float v15; // xmm1_4
  float v16; // xmm2_4
  int v17; // esi
  int i; // ecx
  unsigned __int16 v19; // di
  unsigned __int16 *v20; // edx
  unsigned __int16 v21; // di
  unsigned __int16 *v22; // edx
  btOptimizedBvhNode *v23; // esi
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  btVector3 *p_m_aabbMaxOrg; // eax
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  _WORD v31[4]; // [esp+0h] [ebp-10h]
  _WORD v32[4]; // [esp+8h] [ebp-8h]

  v4 = newAabbMin->mVec128.m128_f32[0];
  if ( this->m_useQuantization )
  {
    v5 = newAabbMin->mVec128.m128_f32[1] - this->m_bvhAabbMin.mVec128.m128_f32[1];
    v6 = newAabbMin->mVec128.m128_f32[2] - this->m_bvhAabbMin.mVec128.m128_f32[2];
    v7 = (int)(float)((float)(v4 - this->m_bvhAabbMin.mVec128.m128_f32[0]) * this->m_bvhQuantization.mVec128.m128_f32[0]);
    v8 = this->m_bvhQuantization.mVec128.m128_f32[0];
    v9 = this->m_bvhQuantization.mVec128.m128_f32[1] * v5;
    v10 = this->m_bvhQuantization.mVec128.m128_f32[2] * v6;
    v11 = newAabbMax->mVec128.m128_f32[1] - this->m_bvhAabbMin.mVec128.m128_f32[1];
    v31[0] = v7 & 0xFFFE;
    v12 = (int)v9;
    v13 = newAabbMax->mVec128.m128_f32[2] - this->m_bvhAabbMin.mVec128.m128_f32[2];
    v31[1] = v12 & 0xFFFE;
    v14 = (int)v10;
    v15 = this->m_bvhQuantization.mVec128.m128_f32[1] * v11;
    v16 = this->m_bvhQuantization.mVec128.m128_f32[2] * v13;
    v32[0] = (int)(float)((float)(v8 * (float)(newAabbMax->mVec128.m128_f32[0] - this->m_bvhAabbMin.mVec128.m128_f32[0]))
                        + s_bm_current_air_resistance)
           | 1;
    v32[1] = (int)(float)(v15 + s_bm_current_air_resistance) | 1;
    v32[2] = (int)(float)(v16 + s_bm_current_air_resistance) | 1;
    v17 = 16 * nodeIndex + 6;
    v31[2] = v14 & 0xFFFE;
    for ( i = 0; i < 3; ++i )
    {
      v19 = v31[i];
      v20 = (unsigned __int16 *)((char *)&this->m_quantizedContiguousNodes.m_data->m_quantizedAabbMin[-3] + v17);
      if ( *v20 > v19 )
        *v20 = v19;
      v21 = v32[i];
      v22 = (unsigned __int16 *)((char *)this->m_quantizedContiguousNodes.m_data->m_quantizedAabbMin + v17);
      if ( *v22 < v21 )
        *v22 = v21;
      v17 += 2;
    }
  }
  else
  {
    v23 = &this->m_contiguousNodes.m_data[nodeIndex];
    if ( v23->m_aabbMinOrg.mVec128.m128_f32[0] > v4 )
      v23->m_aabbMinOrg.mVec128.m128_f32[0] = v4;
    v24 = newAabbMin->mVec128.m128_f32[1];
    if ( v23->m_aabbMinOrg.mVec128.m128_f32[1] > v24 )
      v23->m_aabbMinOrg.mVec128.m128_f32[1] = v24;
    v25 = newAabbMin->mVec128.m128_f32[2];
    if ( v23->m_aabbMinOrg.mVec128.m128_f32[2] > v25 )
      v23->m_aabbMinOrg.mVec128.m128_f32[2] = v25;
    v26 = newAabbMin->mVec128.m128_f32[3];
    if ( v23->m_aabbMinOrg.mVec128.m128_f32[3] > v26 )
      v23->m_aabbMinOrg.mVec128.m128_f32[3] = v26;
    p_m_aabbMaxOrg = &this->m_contiguousNodes.m_data[nodeIndex].m_aabbMaxOrg;
    if ( newAabbMax->mVec128.m128_f32[0] > p_m_aabbMaxOrg->mVec128.m128_f32[0] )
      p_m_aabbMaxOrg->mVec128.m128_i32[0] = newAabbMax->mVec128.m128_i32[0];
    v28 = newAabbMax->mVec128.m128_f32[1];
    if ( v28 > p_m_aabbMaxOrg->mVec128.m128_f32[1] )
      p_m_aabbMaxOrg->mVec128.m128_f32[1] = v28;
    v29 = newAabbMax->mVec128.m128_f32[2];
    if ( v29 > p_m_aabbMaxOrg->mVec128.m128_f32[2] )
      p_m_aabbMaxOrg->mVec128.m128_f32[2] = v29;
    v30 = newAabbMax->mVec128.m128_f32[3];
    if ( v30 > p_m_aabbMaxOrg->mVec128.m128_f32[3] )
      p_m_aabbMaxOrg->mVec128.m128_f32[3] = v30;
  }
}
