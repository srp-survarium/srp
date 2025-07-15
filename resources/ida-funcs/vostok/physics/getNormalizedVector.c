btVector3 *__usercall vostok::physics::getNormalizedVector@<eax>(const btVector3 *v@<ecx>, btVector3 *result@<eax>)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm0_4
  float v6; // xmm2_4

  v2 = s_bm_current_air_resistance
     / fsqrt(
         (float)((float)(v->mVec128.m128_f32[0] * v->mVec128.m128_f32[0])
               + (float)(v->mVec128.m128_f32[1] * v->mVec128.m128_f32[1]))
       + (float)(v->mVec128.m128_f32[2] * v->mVec128.m128_f32[2]));
  v3 = v->mVec128.m128_f32[0] * v2;
  v4 = v2;
  v5 = v2 * v->mVec128.m128_f32[2];
  v6 = v4 * v->mVec128.m128_f32[1];
  result->mVec128.m128_f32[2] = v5;
  result->mVec128.m128_f32[0] = v3;
  result->mVec128.m128_f32[1] = v6;
  result->mVec128.m128_i32[3] = 0;
  if ( fsqrt((float)((float)(v5 * v5) + (float)(v6 * v6)) + (float)(v3 * v3)) < 0.00000011920929 )
  {
    result->mVec128.m128_i32[0] = 0;
    result->mVec128.m128_i32[1] = 0;
    result->mVec128.m128_i32[2] = 0;
    result->mVec128.m128_i32[3] = 0;
  }
  return result;
}
