btVector3 *__usercall Clamp@<eax>(const btVector3 *v@<eax>, btVector3 *a2@<esi>)
{
  float v2; // xmm0_4
  float v3; // xmm2_4
  long double v4; // st7
  btVector3 *result; // eax
  float v6; // [esp+20h] [ebp-14h]
  float v7; // [esp+28h] [ebp-Ch]

  v2 = v->mVec128.m128_f32[0];
  v3 = v->mVec128.m128_f32[2];
  if ( (float)((float)((float)(v2 * v2) + (float)(v->mVec128.m128_f32[1] * v->mVec128.m128_f32[1])) + (float)(v3 * v3)) <= 16.0 )
  {
    *a2 = (btVector3)v->mVec128;
    return a2;
  }
  else
  {
    v7 = v->mVec128.m128_f32[1] * 4.0;
    v4 = sqrtf((float)((float)(v2 * v2) + (float)(v->mVec128.m128_f32[1] * v->mVec128.m128_f32[1])) + (float)(v3 * v3));
    result = a2;
    v6 = 1.0 / v4;
    a2->mVec128.m128_f32[0] = (float)(v2 * 4.0) * v6;
    a2->mVec128.m128_f32[2] = v6 * (float)(v3 * 4.0);
    a2->mVec128.m128_f32[1] = v6 * v7;
    a2->mVec128.m128_i32[3] = 0;
  }
  return result;
}
