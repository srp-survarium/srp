btVector3 *__thiscall btConvexInternalShape::localGetSupportingVertex(
        btConvexInternalShape *this,
        btVector3 *result,
        const btVector3 *vec)
{
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v12; // [esp+Ch] [ebp-14h]
  float v13; // [esp+10h] [ebp-10h]

  ((void (__stdcall *)(btVector3 *, const btVector3 *))this->localGetSupportingVertexWithoutMargin)(result, vec);
  if ( ((double (__thiscall *)(btConvexInternalShape *))this->getMargin)(this) != 0.0 )
  {
    v4 = vec->mVec128.m128_f32[2];
    v5 = vec->mVec128.m128_f32[0];
    v6 = vec->mVec128.m128_f32[1];
    if ( (float)((float)((float)(v4 * v4) + (float)(v5 * v5)) + (float)(v6 * v6)) < 1.4210855e-14 )
    {
      v4 = FLOAT_N1_0;
      v5 = FLOAT_N1_0;
      v6 = FLOAT_N1_0;
    }
    v7 = s_bm_current_air_resistance / fsqrt((float)((float)(v4 * v4) + (float)(v5 * v5)) + (float)(v6 * v6));
    v13 = v7 * v5;
    v12 = this->getMargin(this);
    v8 = (float)((float)(v4 * v7) * v12) + result->mVec128.m128_f32[2];
    v9 = (float)((float)(v7 * v6) * v12) + result->mVec128.m128_f32[1];
    result->mVec128.m128_f32[0] = result->mVec128.m128_f32[0] + (float)(v13 * v12);
    result->mVec128.m128_f32[1] = v9;
    result->mVec128.m128_f32[2] = v8;
  }
  return result;
}
