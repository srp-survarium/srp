void __usercall segmentsClosestPoints(
        btVector3 *offsetB@<edi>,
        const btVector3 *translation@<edx>,
        const btVector3 *dirA@<esi>,
        const btVector3 *dirB@<ecx>,
        btVector3 *ptsVector,
        btVector3 *offsetA,
        float *tA,
        float *tB,
        float hlenA,
        float hlenB)
{
  float v10; // xmm5_4
  float v11; // xmm7_4
  float v12; // xmm4_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm6_4
  float v16; // xmm1_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm4_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float *v22; // eax
  float v23; // xmm1_4
  bool v24; // cc
  float v25; // xmm0_4
  float v26; // [esp+Ch] [ebp-14h]
  unsigned __int64 v27; // [esp+10h] [ebp-10h]
  unsigned int v28; // [esp+18h] [ebp-8h]
  unsigned int v29; // [esp+18h] [ebp-8h]
  unsigned int v30; // [esp+18h] [ebp-8h]

  v10 = dirA->mVec128.m128_f32[2];
  v11 = dirA->mVec128.m128_f32[1];
  v12 = translation->mVec128.m128_f32[1];
  v13 = translation->mVec128.m128_f32[2];
  v14 = (float)((float)(dirB->mVec128.m128_f32[0] * dirA->mVec128.m128_f32[0]) + (float)(dirB->mVec128.m128_f32[1] * v11))
      + (float)(dirB->mVec128.m128_f32[2] * v10);
  v26 = dirA->mVec128.m128_f32[0];
  v15 = v13 * v10;
  v16 = (float)((float)(translation->mVec128.m128_f32[0] * dirB->mVec128.m128_f32[0])
              + (float)(v12 * dirB->mVec128.m128_f32[1]))
      + (float)(v13 * dirB->mVec128.m128_f32[2]);
  v17 = *(float *)&clear_value - (float)(v14 * v14);
  v18 = (float)((float)(translation->mVec128.m128_f32[0] * dirA->mVec128.m128_f32[0]) + (float)(v12 * v11)) + v15;
  if ( v17 == 0.0 )
  {
    *tA = 0.0;
  }
  else
  {
    v19 = (float)(v18 - (float)(v16 * v14)) / v17;
    *tA = v19;
    if ( (float)-hlenA <= v19 )
    {
      if ( v19 > hlenA )
        *tA = hlenA;
    }
    else
    {
      *tA = -hlenA;
    }
  }
  v20 = (float)(*tA * v14) - v16;
  v21 = -hlenB;
  *tB = v20;
  if ( (float)-hlenB <= v20 )
  {
    if ( v20 <= hlenB )
      goto LABEL_17;
    *tB = hlenB;
    v22 = tA;
    v25 = (float)(v14 * hlenB) + v18;
    *tA = v25;
    if ( (float)-hlenA > v25 )
    {
      *tA = -hlenA;
      goto LABEL_17;
    }
    v24 = v25 <= hlenA;
  }
  else
  {
    *tB = v21;
    v22 = tA;
    v23 = (float)(v21 * v14) + v18;
    *tA = v23;
    if ( (float)-hlenA > v23 )
    {
      *tA = -hlenA;
      goto LABEL_17;
    }
    v24 = v23 <= hlenA;
  }
  if ( !v24 )
    *v22 = hlenA;
LABEL_17:
  *(float *)&v27 = *tA * v26;
  *(float *)&v28 = *tA * dirA->mVec128.m128_f32[2];
  *((float *)&v27 + 1) = dirA->mVec128.m128_f32[1] * *tA;
  offsetA->mVec128.m128_u64[0] = v27;
  offsetA->mVec128.m128_u64[1] = v28;
  *(float *)&v27 = *tB * dirB->mVec128.m128_f32[0];
  *(float *)&v29 = *tB * dirB->mVec128.m128_f32[2];
  *((float *)&v27 + 1) = *tB * dirB->mVec128.m128_f32[1];
  offsetB->mVec128.m128_u64[0] = v27;
  offsetB->mVec128.m128_u64[1] = v29;
  *(float *)&v27 = (float)(translation->mVec128.m128_f32[0] - offsetA->mVec128.m128_f32[0])
                 + offsetB->mVec128.m128_f32[0];
  *((float *)&v27 + 1) = offsetB->mVec128.m128_f32[1]
                       + (float)(translation->mVec128.m128_f32[1] - offsetA->mVec128.m128_f32[1]);
  *(float *)&v30 = offsetB->mVec128.m128_f32[2]
                 + (float)(translation->mVec128.m128_f32[2] - offsetA->mVec128.m128_f32[2]);
  ptsVector->mVec128.m128_u64[0] = v27;
  ptsVector->mVec128.m128_u64[1] = v30;
}
