btVector3 *__thiscall btConvexInternalShape::localGetSupportingVertex(
        btConvexInternalShape *this,
        btVector3 *result,
        const btVector3 *vec)
{
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v10; // [esp+1Ch] [ebp-14h]
  float v11; // [esp+1Ch] [ebp-14h]
  btVector3 v12; // [esp+20h] [ebp-10h]

  this->localGetSupportingVertexWithoutMargin(this, result, vec);
  if ( ((double (__thiscall *)(btConvexInternalShape *))this->getMargin)(this) != 0.0 )
  {
    v12.mVec128 = vec->mVec128;
    v4 = vec->mVec128.m128_f32[1];
    v5 = vec->mVec128.m128_f32[0];
    v6 = vec->mVec128.m128_f32[2];
    if ( (float)((float)((float)(v5 * v5) + (float)(v4 * v4)) + (float)(v6 * v6)) < 1.4210855e-14 )
    {
      v5 = -1.0;
      v4 = -1.0;
      v6 = -1.0;
      v12.mVec128.m128_u64[0] = 0xBF800000BF800000uLL;
      v12.mVec128.m128_i32[2] = -1082130432;
    }
    v10 = 1.0 / sqrtf((float)((float)(v5 * v5) + (float)(v4 * v4)) + (float)(v6 * v6));
    v12.mVec128.m128_f32[0] = v10 * v12.mVec128.m128_f32[0];
    v12.mVec128.m128_f32[1] = v10 * v12.mVec128.m128_f32[1];
    v12.mVec128.m128_f32[2] = v10 * v12.mVec128.m128_f32[2];
    v11 = this->getMargin(this);
    v7 = (float)(v12.mVec128.m128_f32[1] * v11) + result->mVec128.m128_f32[1];
    v8 = (float)(v12.mVec128.m128_f32[2] * v11) + result->mVec128.m128_f32[2];
    result->mVec128.m128_f32[0] = result->mVec128.m128_f32[0] + (float)(v12.mVec128.m128_f32[0] * v11);
    result->mVec128.m128_f32[1] = v7;
    result->mVec128.m128_f32[2] = v8;
  }
  return result;
}
