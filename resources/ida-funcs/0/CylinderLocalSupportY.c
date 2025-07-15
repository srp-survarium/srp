btVector3 *__usercall CylinderLocalSupportY@<eax>(
        const btVector3 *halfExtents@<eax>,
        const btVector3 *v@<ecx>,
        btVector3 *a3)
{
  float v3; // xmm0_4
  float v4; // xmm2_4
  int v5; // xmm3_4
  float v6; // xmm4_4
  bool v7; // cc
  float v8; // xmm2_4
  btVector3 *result; // eax

  v3 = v->mVec128.m128_f32[0];
  v4 = halfExtents->mVec128.m128_f32[0];
  v5 = halfExtents->mVec128.m128_i32[1];
  v6 = fsqrt((float)(v3 * v3) + (float)(v->mVec128.m128_f32[2] * v->mVec128.m128_f32[2]));
  if ( v6 == 0.0 )
  {
    v7 = v->mVec128.m128_f32[1] >= 0.0;
    a3->mVec128.m128_f32[0] = v4;
    if ( !v7 )
      v5 ^= _mask__NegFloat_;
    a3->mVec128.m128_i32[2] = 0;
  }
  else
  {
    v7 = v->mVec128.m128_f32[1] >= 0.0;
    v8 = v4 / v6;
    a3->mVec128.m128_f32[0] = v3 * v8;
    if ( !v7 )
      v5 ^= _mask__NegFloat_;
    a3->mVec128.m128_f32[2] = v->mVec128.m128_f32[2] * v8;
  }
  result = a3;
  a3->mVec128.m128_i32[1] = v5;
  return result;
}
