btVector3 *__fastcall vostok::physics::computeReflectionDirection(
        const btVector3 *normal,
        const btVector3 *direction,
        btVector3 *a3)
{
  float v3; // xmm3_4
  float v4; // xmm1_4
  btVector3 *result; // eax
  float v6; // xmm0_4
  float v7; // xmm4_4
  float v8; // xmm2_4

  v3 = direction->mVec128.m128_f32[1];
  v4 = direction->mVec128.m128_f32[2];
  result = a3;
  v6 = (float)((float)((float)(normal->mVec128.m128_f32[0] * direction->mVec128.m128_f32[0])
                     + (float)(normal->mVec128.m128_f32[1] * v3))
             + (float)(normal->mVec128.m128_f32[2] * v4))
     * 2.0;
  v7 = normal->mVec128.m128_f32[1] * v6;
  v8 = normal->mVec128.m128_f32[2] * v6;
  a3->mVec128.m128_f32[0] = direction->mVec128.m128_f32[0] - (float)(normal->mVec128.m128_f32[0] * v6);
  a3->mVec128.m128_f32[1] = v3 - v7;
  a3->mVec128.m128_f32[2] = v4 - v8;
  a3->mVec128.m128_i32[3] = 0;
  return result;
}
