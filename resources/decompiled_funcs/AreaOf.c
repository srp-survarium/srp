void __usercall AreaOf(const btVector3 *x1@<ecx>, const btVector3 *x2@<eax>, const btVector3 *x0)
{
  float v3; // xmm3_4
  float v4; // xmm4_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm5_4
  float v10; // xmm3_4

  v3 = x0->mVec128.m128_f32[1];
  v4 = x0->mVec128.m128_f32[2];
  v5 = x2->mVec128.m128_f32[0] - x0->mVec128.m128_f32[0];
  v6 = x1->mVec128.m128_f32[0] - x0->mVec128.m128_f32[0];
  v7 = x1->mVec128.m128_f32[2] - v4;
  v8 = x2->mVec128.m128_f32[1] - v3;
  v9 = x1->mVec128.m128_f32[1] - v3;
  v10 = x2->mVec128.m128_f32[2] - v4;
  sqrtf(
    (float)((float)((float)((float)(v10 * v9) - (float)(v8 * v7)) * (float)((float)(v10 * v9) - (float)(v8 * v7)))
          + (float)((float)((float)(v6 * v8) - (float)(v5 * v9)) * (float)((float)(v6 * v8) - (float)(v5 * v9))))
  + (float)((float)((float)(v5 * v7) - (float)(v10 * v6)) * (float)((float)(v5 * v7) - (float)(v10 * v6))));
}
