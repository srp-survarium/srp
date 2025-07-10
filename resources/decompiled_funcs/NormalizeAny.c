btVector3 *__usercall NormalizeAny@<eax>(const btVector3 *v@<edi>, btVector3 *a2@<esi>)
{
  long double v2; // st7
  btVector3 *result; // eax
  float v4; // xmm0_4
  float v5; // xmm1_4
  float l; // [esp+4h] [ebp-8h]
  float v7; // [esp+8h] [ebp-4h]

  v7 = v->mVec128.m128_f32[0];
  v2 = sqrtf(
         (float)((float)(v7 * v7) + (float)(v->mVec128.m128_f32[1] * v->mVec128.m128_f32[1]))
       + (float)(v->mVec128.m128_f32[2] * v->mVec128.m128_f32[2]));
  l = v2;
  result = a2;
  if ( v2 <= 0.00000011920929 )
  {
    a2->mVec128.m128_i32[0] = 0;
    a2->mVec128.m128_i32[1] = 0;
    a2->mVec128.m128_i32[2] = 0;
  }
  else
  {
    v4 = *(float *)&clear_value / l;
    a2->mVec128.m128_f32[0] = v7 * (float)(*(float *)&clear_value / l);
    v5 = v4 * v->mVec128.m128_f32[1];
    a2->mVec128.m128_f32[2] = v4 * v->mVec128.m128_f32[2];
    a2->mVec128.m128_f32[1] = v5;
  }
  a2->mVec128.m128_i32[3] = 0;
  return result;
}
