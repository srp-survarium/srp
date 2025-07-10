btVector3 *__fastcall convexHullSupport(
        const btVector3 *localScaling,
        const btVector3 *localDirOrg,
        const btVector3 *points,
        const btVector3 *numPoints,
        int numPointsa)
{
  float v5; // xmm0_4
  float v6; // xmm5_4
  float v7; // xmm6_4
  btVector3 *result; // eax
  int v9; // esi
  int v10; // ecx
  float v11; // xmm4_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float *v15; // edx
  float *v16; // edx
  float *m128_f32; // esi
  float v18; // [esp+0h] [ebp-4h]

  v5 = localScaling->mVec128.m128_f32[2];
  v6 = localScaling->mVec128.m128_f32[0];
  v7 = localScaling->mVec128.m128_f32[1];
  result = (btVector3 *)points;
  v9 = -1;
  v10 = 0;
  v18 = v5;
  v11 = localDirOrg->mVec128.m128_f32[2] * v5;
  v12 = -9.9999998e17;
  v13 = localDirOrg->mVec128.m128_f32[0] * v6;
  v14 = localDirOrg->mVec128.m128_f32[1] * v7;
  if ( numPointsa >= 4 )
  {
    v15 = &numPoints[1].mVec128.m128_f32[1];
    do
    {
      if ( (float)((float)((float)(*(v15 - 5) * v13) + (float)(*(v15 - 3) * v11)) + (float)(*(v15 - 4) * v14)) > v12 )
      {
        v12 = (float)((float)(*(v15 - 5) * v13) + (float)(*(v15 - 3) * v11)) + (float)(*(v15 - 4) * v14);
        v9 = v10;
      }
      if ( (float)((float)((float)(*(v15 - 1) * v13) + (float)(v15[1] * v11)) + (float)(*v15 * v14)) > v12 )
      {
        v12 = (float)((float)(*(v15 - 1) * v13) + (float)(v15[1] * v11)) + (float)(*v15 * v14);
        v9 = v10 + 1;
      }
      if ( (float)((float)((float)(v15[3] * v13) + (float)(v15[5] * v11)) + (float)(v15[4] * v14)) > v12 )
      {
        v12 = (float)((float)(v15[3] * v13) + (float)(v15[5] * v11)) + (float)(v15[4] * v14);
        v9 = v10 + 2;
      }
      if ( (float)((float)((float)(v15[7] * v13) + (float)(v15[9] * v11)) + (float)(v15[8] * v14)) > v12 )
      {
        v12 = (float)((float)(v15[7] * v13) + (float)(v15[9] * v11)) + (float)(v15[8] * v14);
        v9 = v10 + 3;
      }
      v10 += 4;
      v15 += 16;
    }
    while ( v10 < numPointsa - 3 );
  }
  if ( v10 < numPointsa )
  {
    v16 = &numPoints[v10].mVec128.m128_f32[1];
    do
    {
      if ( (float)((float)((float)(*(v16 - 1) * v13) + (float)(v16[1] * v11)) + (float)(*v16 * v14)) > v12 )
      {
        v12 = (float)((float)(*(v16 - 1) * v13) + (float)(v16[1] * v11)) + (float)(*v16 * v14);
        v9 = v10;
      }
      ++v10;
      v16 += 4;
    }
    while ( v10 < numPointsa );
  }
  m128_f32 = numPoints[v9].mVec128.m128_f32;
  points->mVec128.m128_f32[0] = *m128_f32 * v6;
  points->mVec128.m128_f32[1] = m128_f32[1] * v7;
  points->mVec128.m128_f32[2] = m128_f32[2] * v18;
  points->mVec128.m128_i32[3] = 0;
  return result;
}
