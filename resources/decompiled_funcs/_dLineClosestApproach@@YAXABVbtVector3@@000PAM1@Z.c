void __usercall dLineClosestApproach(
        const btVector3 *pa@<esi>,
        const btVector3 *pb@<ecx>,
        const btVector3 *ub@<eax>,
        float *beta@<edi>,
        const btVector3 *ua,
        float *alpha)
{
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm4_4
  float v15; // [esp+Ch] [ebp-10h]
  float v16; // [esp+10h] [ebp-Ch]
  float v17; // [esp+18h] [ebp-4h]

  v6 = pb->mVec128.m128_f32[0] - pa->mVec128.m128_f32[0];
  v7 = pb->mVec128.m128_f32[1] - pa->mVec128.m128_f32[1];
  v8 = pb->mVec128.m128_f32[2] - pa->mVec128.m128_f32[2];
  v16 = ua->mVec128.m128_f32[2];
  v15 = ub->mVec128.m128_f32[2];
  v17 = ub->mVec128.m128_f32[1];
  v9 = ua->mVec128.m128_f32[0] * v6;
  v10 = (float)((float)(ub->mVec128.m128_f32[0] * ua->mVec128.m128_f32[0]) + (float)(v17 * ua->mVec128.m128_f32[1]))
      + (float)(v15 * v16);
  v11 = -(float)((float)((float)(ub->mVec128.m128_f32[0] * v6) + (float)(v17 * v7)) + (float)(v15 * v8));
  v12 = *(float *)&clear_value - (float)(v10 * v10);
  v13 = (float)(v9 + (float)(ua->mVec128.m128_f32[1] * v7)) + (float)(v16 * v8);
  if ( v12 > 0.000099999997 )
  {
    v14 = *(float *)&clear_value / v12;
    *alpha = (float)((float)(v11 * v10) + v13) * (float)(*(float *)&clear_value / v12);
    *beta = (float)((float)(v13 * v10) + v11) * v14;
  }
  else
  {
    *alpha = 0.0;
    *beta = 0.0;
  }
}
