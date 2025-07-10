btVector3 *__usercall vostok::physics::getNormalizedVector@<eax>(const btVector3 *v@<edi>, btVector3 *a2@<esi>)
{
  long double v2; // st7
  float v3; // xmm1_4
  float v4; // xmm0_4
  long double v5; // st7
  btVector3 *result; // eax
  float v7; // [esp+Ch] [ebp-8h]
  float v8; // [esp+10h] [ebp-4h]

  v8 = v->mVec128.m128_f32[0];
  v2 = sqrtf(
         (float)((float)(v8 * v8) + (float)(v->mVec128.m128_f32[1] * v->mVec128.m128_f32[1]))
       + (float)(v->mVec128.m128_f32[2] * v->mVec128.m128_f32[2]));
  a2->mVec128.m128_i32[3] = 0;
  v7 = 1.0 / v2;
  v3 = v7 * v->mVec128.m128_f32[2];
  v4 = v7 * v->mVec128.m128_f32[1];
  a2->mVec128.m128_f32[2] = v3;
  a2->mVec128.m128_f32[1] = v4;
  a2->mVec128.m128_f32[0] = v8 * v7;
  v5 = sqrtf((float)((float)(v3 * v3) + (float)(v4 * v4)) + (float)((float)(v8 * v7) * (float)(v8 * v7)));
  result = a2;
  if ( v5 < 0.00000011920929 )
  {
    a2->mVec128.m128_i32[0] = 0;
    a2->mVec128.m128_i32[1] = 0;
    a2->mVec128.m128_i32[2] = 0;
    a2->mVec128.m128_i32[3] = 0;
  }
  return result;
}
