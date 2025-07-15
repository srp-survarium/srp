btVector3 *__fastcall vostok::physics::parallelComponent(
        const btVector3 *normal,
        const btVector3 *direction,
        btVector3 *a3)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  btVector3 *result; // eax
  float v6; // xmm0_4

  v3 = normal->mVec128.m128_f32[2];
  v4 = normal->mVec128.m128_f32[1];
  result = a3;
  v6 = (float)((float)(direction->mVec128.m128_f32[1] * v4) + (float)(direction->mVec128.m128_f32[2] * v3))
     + (float)(direction->mVec128.m128_f32[0] * normal->mVec128.m128_f32[0]);
  a3->mVec128.m128_f32[0] = normal->mVec128.m128_f32[0] * v6;
  a3->mVec128.m128_f32[1] = v4 * v6;
  a3->mVec128.m128_f32[2] = v3 * v6;
  a3->mVec128.m128_i32[3] = 0;
  return result;
}
