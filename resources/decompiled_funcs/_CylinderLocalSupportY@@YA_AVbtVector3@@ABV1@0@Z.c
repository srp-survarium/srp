btVector3 *__usercall CylinderLocalSupportY@<eax>(
        const btVector3 *halfExtents@<eax>,
        const btVector3 *v@<edi>,
        btVector3 *a3@<esi>)
{
  long double v3; // st7
  float v4; // xmm1_4
  btVector3 *result; // eax
  bool v6; // cc
  float v7; // xmm0_4
  float v8; // [esp+24h] [ebp-10h]
  float v9; // [esp+28h] [ebp-Ch]
  float v10; // [esp+2Ch] [ebp-8h]
  float v11; // [esp+30h] [ebp-4h]

  v9 = halfExtents->mVec128.m128_f32[0];
  v8 = halfExtents->mVec128.m128_f32[1];
  v11 = v->mVec128.m128_f32[0];
  v3 = sqrtf((float)(v11 * v11) + (float)(v->mVec128.m128_f32[2] * v->mVec128.m128_f32[2]));
  if ( v3 == 0.0 )
  {
    v6 = v->mVec128.m128_f32[1] >= 0.0;
    a3->mVec128.m128_f32[0] = v9;
    v7 = v8;
    if ( !v6 )
      v7 = -v8;
    a3->mVec128.m128_f32[1] = v7;
    result = a3;
    a3->mVec128.m128_i32[2] = 0;
  }
  else
  {
    v10 = v3;
    a3->mVec128.m128_f32[0] = v11 * (float)(v9 / v10);
    v4 = v8;
    if ( v->mVec128.m128_f32[1] < 0.0 )
      v4 = -v8;
    a3->mVec128.m128_f32[1] = v4;
    result = a3;
    a3->mVec128.m128_f32[2] = v->mVec128.m128_f32[2] * (float)(v9 / v10);
  }
  return result;
}
