btDbvtAabbMm *__usercall btDbvtAabbMm::FromPoints@<eax>(const btVector3 **ppts@<esi>, btDbvtAabbMm *result@<eax>)
{
  int i; // edx
  const btVector3 *v3; // ecx
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm0_4

  result->mx = (btVector3)(*ppts)->mVec128;
  result->mi.mVec128.m128_u64[0] = result->mx.mVec128.m128_u64[0];
  result->mi.mVec128.m128_u64[1] = result->mx.mVec128.m128_u64[1];
  for ( i = 1; i < 3; ++i )
  {
    v3 = ppts[i];
    if ( result->mi.mVec128.m128_f32[0] > v3->mVec128.m128_f32[0] )
      result->mi.mVec128.m128_i32[0] = v3->mVec128.m128_i32[0];
    v4 = v3->mVec128.m128_f32[1];
    if ( result->mi.mVec128.m128_f32[1] > v4 )
      result->mi.mVec128.m128_f32[1] = v4;
    v5 = v3->mVec128.m128_f32[2];
    if ( result->mi.mVec128.m128_f32[2] > v5 )
      result->mi.mVec128.m128_f32[2] = v5;
    v6 = v3->mVec128.m128_f32[3];
    if ( result->mi.mVec128.m128_f32[3] > v6 )
      result->mi.mVec128.m128_f32[3] = v6;
    if ( v3->mVec128.m128_f32[0] > result->mx.mVec128.m128_f32[0] )
      result->mx.mVec128.m128_i32[0] = v3->mVec128.m128_i32[0];
    v7 = v3->mVec128.m128_f32[1];
    if ( v7 > result->mx.mVec128.m128_f32[1] )
      result->mx.mVec128.m128_f32[1] = v7;
    v8 = v3->mVec128.m128_f32[2];
    if ( v8 > result->mx.mVec128.m128_f32[2] )
      result->mx.mVec128.m128_f32[2] = v8;
    v9 = v3->mVec128.m128_f32[3];
    if ( v9 > result->mx.mVec128.m128_f32[3] )
      result->mx.mVec128.m128_f32[3] = v9;
  }
  return result;
}
