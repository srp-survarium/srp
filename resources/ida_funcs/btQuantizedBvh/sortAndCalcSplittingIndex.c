int __userpurge btQuantizedBvh::sortAndCalcSplittingIndex@<eax>(
        btQuantizedBvh *this@<ecx>,
        btQuantizedBvh *a2@<eax>,
        int startIndex,
        int endIndex,
        int splitAxis)
{
  int v5; // ecx
  float v6; // xmm3_4
  int v7; // edx
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  int v12; // edi
  int v13; // edx
  int v14; // ecx
  btQuantizedBvhNode *m_data; // eax
  int v16; // edx
  unsigned __int16 *v17; // eax
  int v18; // ecx
  int v19; // eax
  btOptimizedBvhNode *v20; // eax
  btVector3 *AabbMax; // eax
  float v22; // xmm4_4
  int v23; // edx
  int v24; // edi
  btQuantizedBvhNode *v25; // eax
  int v26; // edx
  btQuantizedBvhNode *v27; // eax
  float v28; // xmm0_4
  float v29; // xmm6_4
  float v30; // xmm5_4
  float v31; // xmm4_4
  btOptimizedBvhNode *v32; // eax
  float v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // xmm0_4
  __int64 *v36; // eax
  bool v37; // cc
  int result; // eax
  signed int v39; // [esp+14Ch] [ebp-4Ch]
  int v40; // [esp+150h] [ebp-48h]
  int v41; // [esp+150h] [ebp-48h]
  int v42; // [esp+154h] [ebp-44h]
  int v43; // [esp+154h] [ebp-44h]
  float v44; // [esp+164h] [ebp-34h]
  __int64 v45; // [esp+168h] [ebp-30h]
  __int64 v46; // [esp+170h] [ebp-28h]
  __int64 v47; // [esp+178h] [ebp-20h]
  __int64 v48; // [esp+180h] [ebp-18h]
  btVector3 v49; // [esp+188h] [ebp-10h] BYREF

  v5 = startIndex;
  v6 = FLOAT_0_5;
  v7 = endIndex - startIndex;
  v8 = 0.0;
  v9 = 0.0;
  v10 = 0.0;
  v39 = startIndex;
  v45 = 0;
  v46 = 0;
  v12 = startIndex;
  if ( startIndex < endIndex )
  {
    v13 = startIndex << 6;
    v14 = 16 * startIndex;
    v42 = startIndex << 6;
    v40 = 16 * startIndex;
    while ( 1 )
    {
      if ( a2->m_useQuantization )
      {
        m_data = a2->m_quantizedLeafNodes.m_data;
        v16 = *(unsigned __int16 *)((char *)&m_data->m_quantizedAabbMin[1] + v14);
        v17 = (unsigned __int16 *)((char *)m_data->m_quantizedAabbMin + v14);
        v18 = *v17;
        v19 = v17[2];
        *(float *)&v47 = (float)((float)v18 / a2->m_bvhQuantization.mVec128.m128_f32[0])
                       + a2->m_bvhAabbMin.mVec128.m128_f32[0];
        *((float *)&v47 + 1) = a2->m_bvhAabbMin.mVec128.m128_f32[1]
                             + (float)((float)v16 / a2->m_bvhQuantization.mVec128.m128_f32[1]);
        *(float *)&v48 = a2->m_bvhAabbMin.mVec128.m128_f32[2]
                       + (float)((float)v19 / a2->m_bvhQuantization.mVec128.m128_f32[2]);
      }
      else
      {
        v20 = a2->m_leafNodes.m_data;
        v47 = *(__int64 *)((char *)v20->m_aabbMinOrg.mVec128.m128_i64 + v13);
        v48 = *(__int64 *)((char *)&v20->m_aabbMinOrg.mVec128.m128_i64[1] + v13);
      }
      AabbMax = btQuantizedBvh::getAabbMax(v12, &v49, a2);
      v6 = FLOAT_0_5;
      v40 += 16;
      v42 += 64;
      ++v12;
      v8 = (float)((float)(AabbMax->mVec128.m128_f32[0] + *(float *)&v47) * 0.5) + *(float *)&v45;
      v9 = (float)((float)(AabbMax->mVec128.m128_f32[1] + *((float *)&v47 + 1)) * 0.5) + *((float *)&v45 + 1);
      v10 = (float)((float)(AabbMax->mVec128.m128_f32[2] + *(float *)&v48) * 0.5) + *(float *)&v46;
      *(float *)&v45 = v8;
      *((float *)&v45 + 1) = v9;
      *(float *)&v46 = v10;
      if ( v12 >= endIndex )
        break;
      v14 = v40;
      v13 = v42;
    }
    v5 = startIndex;
    v7 = endIndex - startIndex;
  }
  v22 = *(float *)&clear_value / (float)v7;
  *(float *)&v45 = v8 * v22;
  *((float *)&v45 + 1) = v9 * v22;
  *(float *)&v46 = v10 * v22;
  v44 = *((float *)&v45 + splitAxis);
  v43 = v5;
  if ( v5 < endIndex )
  {
    v23 = v5 << 6;
    v49.mVec128.m128_i32[3] = 0;
    v41 = v5 << 6;
    v24 = v5;
    do
    {
      if ( a2->m_useQuantization )
      {
        v25 = a2->m_quantizedLeafNodes.m_data;
        v26 = v25[v24].m_quantizedAabbMin[0];
        v27 = &v25[v24];
        v28 = (float)v26;
        v23 = v41;
        v29 = a2->m_bvhAabbMin.mVec128.m128_f32[0] + (float)(v28 / a2->m_bvhQuantization.mVec128.m128_f32[0]);
        v30 = a2->m_bvhAabbMin.mVec128.m128_f32[1]
            + (float)((float)v27->m_quantizedAabbMin[1] / a2->m_bvhQuantization.mVec128.m128_f32[1]);
        v31 = a2->m_bvhAabbMin.mVec128.m128_f32[2]
            + (float)((float)v27->m_quantizedAabbMin[2] / a2->m_bvhQuantization.mVec128.m128_f32[2]);
      }
      else
      {
        v32 = a2->m_leafNodes.m_data;
        v47 = *(__int64 *)((char *)v32->m_aabbMinOrg.mVec128.m128_i64 + v23);
        v30 = *((float *)&v47 + 1);
        v29 = *(float *)&v47;
        v48 = *(__int64 *)((char *)&v32->m_aabbMinOrg.mVec128.m128_i64[1] + v23);
        v31 = *(float *)&v48;
      }
      if ( a2->m_useQuantization )
      {
        v33 = (float)((float)a2->m_quantizedLeafNodes.m_data[v24].m_quantizedAabbMax[0]
                    / a2->m_bvhQuantization.mVec128.m128_f32[0])
            + a2->m_bvhAabbMin.mVec128.m128_f32[0];
        v34 = a2->m_bvhAabbMin.mVec128.m128_f32[1]
            + (float)((float)a2->m_quantizedLeafNodes.m_data[v24].m_quantizedAabbMax[1]
                    / a2->m_bvhQuantization.mVec128.m128_f32[1]);
        v35 = a2->m_bvhAabbMin.mVec128.m128_f32[2]
            + (float)((float)a2->m_quantizedLeafNodes.m_data[v24].m_quantizedAabbMax[2]
                    / a2->m_bvhQuantization.mVec128.m128_f32[2]);
      }
      else
      {
        v36 = (__int64 *)((char *)&a2->m_leafNodes.m_data->m_aabbMaxOrg + v23);
        v45 = *v36;
        v34 = *((float *)&v45 + 1);
        v33 = *(float *)&v45;
        v46 = v36[1];
        v35 = *(float *)&v46;
      }
      v49.mVec128.m128_f32[0] = (float)(v33 + v29) * v6;
      v49.mVec128.m128_f32[1] = (float)(v34 + v30) * v6;
      v49.mVec128.m128_f32[2] = (float)(v35 + v31) * v6;
      if ( v49.mVec128.m128_f32[splitAxis] > v44 )
      {
        btQuantizedBvh::swapLeafNodes(v43, v39++, a2);
        v5 = startIndex;
        v23 = v41;
      }
      v23 += 64;
      ++v24;
      v37 = ++v43 < endIndex;
      v41 = v23;
    }
    while ( v37 );
    v7 = endIndex - startIndex;
  }
  result = v39;
  if ( v39 <= v7 / 3 + v5 || v39 >= endIndex - v7 / 3 - 1 )
    return v5 + ((endIndex - startIndex) >> 1);
  return result;
}
