btVector3 *__usercall btQuaternion::getAxis@<eax>(btQuaternion *this@<ecx>, float *a2@<edi>, btVector3 *a3@<esi>)
{
  btVector3 *v3; // eax
  long double v4; // st7

  if ( (float)(*(float *)&clear_value - (float)(a2[3] * a2[3])) >= 0.0000011920929 )
  {
    v4 = 1.0 / sqrtf(*(float *)&clear_value - (float)(a2[3] * a2[3]));
    v3 = a3;
    a3->mVec128.m128_i32[3] = 0;
    a3->mVec128.m128_f32[0] = *a2 * v4;
    a3->mVec128.m128_f32[1] = a2[1] * v4;
    a3->mVec128.m128_f32[2] = v4 * a2[2];
  }
  else
  {
    a3->mVec128.m128_i32[0] = (int)clear_value;
    a3->mVec128.m128_i32[1] = 0;
    a3->mVec128.m128_i32[2] = 0;
    v3 = a3;
    a3->mVec128.m128_i32[3] = 0;
  }
  return v3;
}
