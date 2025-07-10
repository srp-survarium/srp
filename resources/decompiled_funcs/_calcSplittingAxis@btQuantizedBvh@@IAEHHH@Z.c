int __userpurge btQuantizedBvh::calcSplittingAxis@<eax>(
        btQuantizedBvh *this@<ecx>,
        btQuantizedBvh *a2@<esi>,
        int startIndex,
        int endIndex)
{
  float v4; // xmm0_4
  int v5; // ecx
  float v6; // xmm3_4
  int v7; // eax
  float v8; // xmm5_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  int v11; // edi
  int v12; // edx
  int v13; // ecx
  btQuantizedBvhNode *m_data; // eax
  int v15; // edx
  unsigned __int16 *v16; // eax
  btOptimizedBvhNode *v17; // eax
  btVector3 *AabbMax; // eax
  const vostok::math::float4x4 *v19; // xmm4_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  int v22; // ecx
  int v23; // ebx
  int v24; // edi
  unsigned __int16 *m_quantizedAabbMin; // eax
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm4_4
  float v29; // xmm4_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  btOptimizedBvhNode *v33; // eax
  __int64 v34; // xmm0_8
  char *v35; // eax
  float v36; // xmm4_4
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm4_4
  float v40; // xmm5_4
  float v41; // xmm6_4
  float v42; // xmm7_4
  int v44; // [esp+6Ch] [ebp-4Ch]
  int v45; // [esp+70h] [ebp-48h]
  float v46; // [esp+70h] [ebp-48h]
  float v47; // [esp+74h] [ebp-44h]
  float v48; // [esp+78h] [ebp-40h]
  float v49; // [esp+78h] [ebp-40h]
  float v50; // [esp+7Ch] [ebp-3Ch]
  float v51; // [esp+7Ch] [ebp-3Ch]
  float v52; // [esp+80h] [ebp-38h]
  float v53; // [esp+80h] [ebp-38h]
  __int64 v54; // [esp+88h] [ebp-30h]
  __int64 v55; // [esp+88h] [ebp-30h]
  __int64 v56; // [esp+90h] [ebp-28h]
  float v57; // [esp+90h] [ebp-28h]
  __int64 v58; // [esp+90h] [ebp-28h]
  btVector3 v59; // [esp+A8h] [ebp-10h] BYREF

  v4 = 0.0;
  v5 = endIndex;
  v6 = FLOAT_0_5;
  v7 = endIndex - startIndex;
  v8 = 0.0;
  v9 = 0.0;
  v10 = 0.0;
  v48 = 0.0;
  v50 = 0.0;
  v52 = 0.0;
  v11 = startIndex;
  if ( startIndex < endIndex )
  {
    v12 = startIndex << 6;
    v13 = 16 * startIndex;
    v45 = startIndex << 6;
    v44 = 16 * startIndex;
    while ( 1 )
    {
      if ( a2->m_useQuantization )
      {
        m_data = a2->m_quantizedLeafNodes.m_data;
        v15 = *(unsigned __int16 *)((char *)&m_data->m_quantizedAabbMin[1] + v13);
        v16 = (unsigned __int16 *)((char *)m_data->m_quantizedAabbMin + v13);
        *((float *)&v54 + 1) = a2->m_bvhAabbMin.mVec128.m128_f32[1]
                             + (float)((float)v15 / a2->m_bvhQuantization.mVec128.m128_f32[1]);
        *(float *)&v54 = a2->m_bvhAabbMin.mVec128.m128_f32[0]
                       + (float)((float)*v16 / a2->m_bvhQuantization.mVec128.m128_f32[0]);
        *(float *)&v56 = a2->m_bvhAabbMin.mVec128.m128_f32[2]
                       + (float)((float)v16[2] / a2->m_bvhQuantization.mVec128.m128_f32[2]);
      }
      else
      {
        v17 = a2->m_leafNodes.m_data;
        v54 = *(__int64 *)((char *)v17->m_aabbMinOrg.mVec128.m128_i64 + v12);
        v56 = *(__int64 *)((char *)&v17->m_aabbMinOrg.mVec128.m128_i64[1] + v12);
      }
      AabbMax = btQuantizedBvh::getAabbMax(v11, &v59, a2);
      v6 = FLOAT_0_5;
      v44 += 16;
      v45 += 64;
      ++v11;
      v4 = (float)((float)(AabbMax->mVec128.m128_f32[0] + *(float *)&v54) * 0.5) + v48;
      v48 = v4;
      v50 = (float)((float)(AabbMax->mVec128.m128_f32[1] + *((float *)&v54 + 1)) * 0.5) + v50;
      v52 = (float)((float)(AabbMax->mVec128.m128_f32[2] + *(float *)&v56) * 0.5) + v52;
      if ( v11 >= endIndex )
        break;
      v13 = v44;
      v12 = v45;
    }
    v8 = 0.0;
    v9 = 0.0;
    v10 = 0.0;
    v7 = endIndex - startIndex;
    v5 = endIndex;
  }
  v19 = clear_value;
  v20 = (float)v7;
  v21 = *(float *)&clear_value / (float)v7;
  v49 = v4 * v21;
  v51 = v50 * v21;
  v46 = (float)v7;
  v53 = v52 * v21;
  if ( startIndex < v5 )
  {
    v22 = startIndex << 6;
    v23 = startIndex;
    v24 = v7;
    do
    {
      if ( a2->m_useQuantization )
      {
        m_quantizedAabbMin = a2->m_quantizedLeafNodes.m_data[v23].m_quantizedAabbMin;
        v26 = *(float *)&v19 / a2->m_bvhQuantization.mVec128.m128_f32[0];
        v27 = *(float *)&v19 / a2->m_bvhQuantization.mVec128.m128_f32[1];
        v28 = *(float *)&v19 / a2->m_bvhQuantization.mVec128.m128_f32[2];
        v57 = (float)m_quantizedAabbMin[2] * v28;
        v47 = v28;
        *(float *)&v55 = a2->m_bvhAabbMin.mVec128.m128_f32[0] + (float)((float)*m_quantizedAabbMin * v26);
        v29 = (float)m_quantizedAabbMin[3] * v26;
        *((float *)&v55 + 1) = a2->m_bvhAabbMin.mVec128.m128_f32[1] + (float)((float)m_quantizedAabbMin[1] * v27);
        *(float *)&v58 = a2->m_bvhAabbMin.mVec128.m128_f32[2] + v57;
        v30 = a2->m_bvhAabbMin.mVec128.m128_f32[1] + (float)((float)m_quantizedAabbMin[4] * v27);
        v31 = a2->m_bvhAabbMin.mVec128.m128_f32[2] + (float)((float)m_quantizedAabbMin[5] * v47);
        v32 = a2->m_bvhAabbMin.mVec128.m128_f32[0] + v29;
      }
      else
      {
        v33 = a2->m_leafNodes.m_data;
        v34 = *(__int64 *)((char *)v33->m_aabbMinOrg.mVec128.m128_i64 + v22);
        v35 = (char *)v33 + v22;
        v55 = v34;
        v58 = *((_QWORD *)v35 + 1);
        v30 = *((float *)v35 + 5);
        v32 = *((float *)v35 + 4);
        v31 = *((float *)v35 + 6);
      }
      v36 = (float)((float)(v31 + *(float *)&v58) * v6) - v53;
      v37 = (float)((float)((float)(v32 + *(float *)&v55) * v6) - v49)
          * (float)((float)((float)(v32 + *(float *)&v55) * v6) - v49);
      v38 = v36 * v36;
      v19 = clear_value;
      ++v23;
      v22 += 64;
      --v24;
      v8 = v37 + v8;
      v9 = (float)((float)((float)((float)(v30 + *((float *)&v55 + 1)) * v6) - v51)
                 * (float)((float)((float)(v30 + *((float *)&v55 + 1)) * v6) - v51))
         + v9;
      v10 = v38 + v10;
    }
    while ( v24 );
    v20 = v46;
  }
  v39 = *(float *)&v19 / (float)(v20 - *(float *)&v19);
  v40 = v8 * v39;
  v41 = v9 * v39;
  v42 = v10 * v39;
  if ( v41 > v40 )
  {
    if ( v42 <= v41 )
      return 1;
    return 2;
  }
  if ( v42 > v40 )
    return 2;
  return 0;
}
