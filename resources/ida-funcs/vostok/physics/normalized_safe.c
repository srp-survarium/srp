btVector3 *__usercall vostok::physics::normalized_safe@<eax>(
        const btVector3 *vector@<ecx>,
        btVector3 *result@<eax>,
        const btVector3 *result_in_case_of_zero_length)
{
  float v3; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm1_4

  v3 = vector->mVec128.m128_f32[0];
  if ( fabs(
         (float)((float)(vector->mVec128.m128_f32[1] * vector->mVec128.m128_f32[1])
               + (float)(vector->mVec128.m128_f32[2] * vector->mVec128.m128_f32[2]))
       + (float)(v3 * v3)) >= 0.0000099999997 )
  {
    v4 = s_bm_current_air_resistance
       / fsqrt(
           (float)((float)(vector->mVec128.m128_f32[1] * vector->mVec128.m128_f32[1])
                 + (float)(vector->mVec128.m128_f32[2] * vector->mVec128.m128_f32[2]))
         + (float)(v3 * v3));
    result->mVec128.m128_f32[0] = v3 * v4;
    v5 = v4 * vector->mVec128.m128_f32[1];
    result->mVec128.m128_f32[2] = v4 * vector->mVec128.m128_f32[2];
    result->mVec128.m128_f32[1] = v5;
    result->mVec128.m128_i32[3] = 0;
  }
  else
  {
    *result = (btVector3)result_in_case_of_zero_length->mVec128;
  }
  return result;
}
