int __thiscall btQuantizedBvh::sortAndCalcSplittingIndex(
        btQuantizedBvh *this,
        btQuantizedBvh *startIndex,
        int endIndex,
        int splitAxis,
        int a5)
{
  int v5; // ecx
  int v6; // esi
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  btVector3 *AabbMin; // edi
  btVector3 *AabbMax; // eax
  float v12; // xmm4_4
  btVector3 *v13; // edi
  btVector3 *v14; // eax
  float v15; // xmm1_4
  float v16; // xmm2_4
  int i; // [esp+4h] [ebp-40h]
  int ia; // [esp+4h] [ebp-40h]
  int splitIndex; // [esp+8h] [ebp-3Ch]
  float v21; // [esp+10h] [ebp-34h]
  float v22; // [esp+14h] [ebp-30h]
  float v23; // [esp+18h] [ebp-2Ch]
  float v24; // [esp+1Ch] [ebp-28h]
  int v25; // [esp+20h] [ebp-24h]
  btVector3 v26; // [esp+24h] [ebp-20h] BYREF
  btVector3 v27; // [esp+34h] [ebp-10h] BYREF

  v5 = endIndex;
  v6 = splitAxis - endIndex;
  v7 = 0.0;
  v8 = 0.0;
  v9 = 0.0;
  splitIndex = endIndex;
  v22 = 0.0;
  v23 = 0.0;
  v24 = 0.0;
  v25 = 0;
  i = endIndex;
  if ( endIndex < splitAxis )
  {
    do
    {
      AabbMin = btQuantizedBvh::getAabbMin(i, &v26, startIndex);
      AabbMax = btQuantizedBvh::getAabbMax(i++, &v27, startIndex);
      v7 = (float)((float)(AabbMax->mVec128.m128_f32[0] + AabbMin->mVec128.m128_f32[0]) * 0.5) + v22;
      v8 = (float)((float)(AabbMax->mVec128.m128_f32[1] + AabbMin->mVec128.m128_f32[1]) * 0.5) + v23;
      v9 = (float)((float)(AabbMax->mVec128.m128_f32[2] + AabbMin->mVec128.m128_f32[2]) * 0.5) + v24;
      v22 = v7;
      v23 = v8;
      v24 = v9;
    }
    while ( i < splitAxis );
    v5 = endIndex;
  }
  v12 = s_bm_current_air_resistance / (float)v6;
  v22 = v7 * v12;
  v23 = v8 * v12;
  v24 = v9 * v12;
  v21 = *(&v22 + a5);
  ia = v5;
  if ( v5 < splitAxis )
  {
    v25 = 0;
    do
    {
      v13 = btQuantizedBvh::getAabbMin(ia, &v27, startIndex);
      v14 = btQuantizedBvh::getAabbMax(ia, &v26, startIndex);
      v15 = (float)(v14->mVec128.m128_f32[1] + v13->mVec128.m128_f32[1]) * 0.5;
      v16 = (float)(v14->mVec128.m128_f32[2] + v13->mVec128.m128_f32[2]) * 0.5;
      v22 = (float)(v13->mVec128.m128_f32[0] + v14->mVec128.m128_f32[0]) * 0.5;
      v23 = v15;
      v24 = v16;
      if ( *(&v22 + a5) > v21 )
        btQuantizedBvh::swapLeafNodes(startIndex, ia, splitIndex++);
      ++ia;
    }
    while ( ia < splitAxis );
    v5 = endIndex;
  }
  if ( splitIndex <= v6 / 3 + v5 || splitIndex >= splitAxis - v6 / 3 - 1 )
    return v5 + (v6 >> 1);
  return splitIndex;
}
