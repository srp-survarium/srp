btVector3 *__usercall convexHullSupport@<eax>(
        const btVector3 *localDirOrg@<edx>,
        const btVector3 *points@<edi>,
        const btVector3 *localScaling@<ecx>,
        btVector3 *numPoints,
        int a5)
{
  float v5; // xmm0_4
  float v6; // xmm5_4
  float v7; // xmm6_4
  btVector3 *result; // eax
  float v9; // xmm4_4
  int v10; // esi
  int v11; // ecx
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float *v15; // edx
  const btVector3 *v16; // ecx

  v5 = localScaling->mVec128.m128_f32[2];
  v6 = localScaling->mVec128.m128_f32[0];
  v7 = localScaling->mVec128.m128_f32[1];
  result = numPoints;
  v9 = FLOAT_N9_9999998e17;
  v10 = 0;
  v11 = -1;
  v12 = localDirOrg->mVec128.m128_f32[0] * v6;
  v13 = localDirOrg->mVec128.m128_f32[1] * v7;
  v14 = localDirOrg->mVec128.m128_f32[2] * v5;
  if ( a5 > 0 )
  {
    v15 = &points->mVec128.m128_f32[1];
    do
    {
      if ( (float)((float)((float)(*(v15 - 1) * v12) + (float)(v15[1] * v14)) + (float)(v13 * *v15)) > v9 )
      {
        v9 = (float)((float)(*(v15 - 1) * v12) + (float)(v15[1] * v14)) + (float)(v13 * *v15);
        v11 = v10;
      }
      ++v10;
      v15 += 4;
    }
    while ( v10 < a5 );
  }
  v16 = &points[v11];
  numPoints->mVec128.m128_f32[0] = v16->mVec128.m128_f32[0] * v6;
  numPoints->mVec128.m128_f32[1] = v16->mVec128.m128_f32[1] * v7;
  numPoints->mVec128.m128_f32[2] = v16->mVec128.m128_f32[2] * v5;
  numPoints->mVec128.m128_i32[3] = 0;
  return result;
}
