btVector3 *__fastcall ProjectOnPlane(const btVector3 *a, const btVector3 *v, btVector3 *a3)
{
  float v3; // xmm3_4
  float v4; // xmm1_4
  btVector3 *result; // eax
  float v6; // xmm0_4
  float v7; // xmm4_4
  float v8; // xmm2_4

  v3 = v->mVec128.m128_f32[1];
  v4 = v->mVec128.m128_f32[2];
  result = a3;
  v6 = (float)((float)(a->mVec128.m128_f32[0] * v->mVec128.m128_f32[0]) + (float)(a->mVec128.m128_f32[1] * v3))
     + (float)(a->mVec128.m128_f32[2] * v4);
  v7 = a->mVec128.m128_f32[1] * v6;
  v8 = a->mVec128.m128_f32[2] * v6;
  a3->mVec128.m128_f32[0] = v->mVec128.m128_f32[0] - (float)(a->mVec128.m128_f32[0] * v6);
  a3->mVec128.m128_f32[1] = v3 - v7;
  a3->mVec128.m128_f32[2] = v4 - v8;
  a3->mVec128.m128_i32[3] = 0;
  return result;
}
