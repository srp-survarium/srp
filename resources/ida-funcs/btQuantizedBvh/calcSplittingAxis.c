int __thiscall btQuantizedBvh::calcSplittingAxis(
        btQuantizedBvh *this,
        btQuantizedBvh *startIndex,
        int endIndex,
        int a4)
{
  float v4; // xmm0_4
  int v5; // ebx
  float v6; // xmm4_4
  float v7; // xmm5_4
  btVector3 *AabbMin; // esi
  btVector3 *AabbMax; // eax
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  int v13; // edi
  btVector3 *v14; // esi
  btVector3 *v15; // eax
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  float v23; // xmm1_4
  float v24; // xmm4_4
  float v26; // [esp+0h] [ebp-44h]
  float v27; // [esp+4h] [ebp-40h]
  float v28; // [esp+8h] [ebp-3Ch]
  float v29; // [esp+Ch] [ebp-38h]
  float v30; // [esp+14h] [ebp-30h]
  float v31; // [esp+18h] [ebp-2Ch]
  float v32; // [esp+1Ch] [ebp-28h]
  btVector3 v33; // [esp+24h] [ebp-20h] BYREF
  btVector3 v34; // [esp+34h] [ebp-10h] BYREF

  v4 = 0.0;
  v5 = endIndex;
  v6 = 0.0;
  v7 = 0.0;
  v30 = 0.0;
  v31 = 0.0;
  v32 = 0.0;
  while ( 1 )
  {
    v10 = v4;
    if ( v5 >= a4 )
      break;
    AabbMin = btQuantizedBvh::getAabbMin(v5, &v33, startIndex);
    AabbMax = btQuantizedBvh::getAabbMax(v5, &v34, startIndex);
    v4 = (float)((float)(AabbMax->mVec128.m128_f32[0] + AabbMin->mVec128.m128_f32[0]) * 0.5) + v4;
    v6 = (float)((float)(AabbMax->mVec128.m128_f32[1] + AabbMin->mVec128.m128_f32[1]) * 0.5) + v6;
    v7 = (float)((float)(AabbMax->mVec128.m128_f32[2] + AabbMin->mVec128.m128_f32[2]) * 0.5) + v7;
    ++v5;
  }
  v11 = s_bm_current_air_resistance;
  v12 = (float)(a4 - endIndex);
  v13 = endIndex;
  v26 = v12;
  v27 = v10 * (float)(s_bm_current_air_resistance / v12);
  v28 = v6 * (float)(s_bm_current_air_resistance / v12);
  v29 = v7 * (float)(s_bm_current_air_resistance / v12);
  if ( endIndex >= a4 )
  {
    v20 = 0.0;
    v18 = 0.0;
    v19 = 0.0;
  }
  else
  {
    do
    {
      v14 = btQuantizedBvh::getAabbMin(v13, &v34, startIndex);
      v15 = btQuantizedBvh::getAabbMax(v13, &v33, startIndex);
      v16 = (float)((float)(v15->mVec128.m128_f32[2] + v14->mVec128.m128_f32[2]) * 0.5) - v29;
      v17 = (float)((float)(v15->mVec128.m128_f32[1] + v14->mVec128.m128_f32[1]) * 0.5) - v28;
      ++v13;
      v18 = (float)(v17 * v17) + v31;
      v19 = (float)((float)((float)((float)(v15->mVec128.m128_f32[0] + v14->mVec128.m128_f32[0]) * 0.5) - v27)
                  * (float)((float)((float)(v15->mVec128.m128_f32[0] + v14->mVec128.m128_f32[0]) * 0.5) - v27))
          + v30;
      v20 = (float)(v16 * v16) + v32;
      v30 = v19;
      v31 = v18;
      v32 = v20;
    }
    while ( v13 < a4 );
    v11 = s_bm_current_air_resistance;
    v12 = v26;
  }
  v21 = v11 / (float)(v12 - v11);
  v22 = v19 * v21;
  v23 = v18 * v21;
  v24 = v20 * v21;
  if ( v23 > v22 )
  {
    if ( v24 <= v23 )
      return 1;
    return 2;
  }
  if ( v24 > v22 )
    return 2;
  return 0;
}
