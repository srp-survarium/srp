btVector3 *__thiscall btSphereShape::localGetSupportingVertex(
        btSphereShape *this,
        btVector3 *result,
        const btVector3 *vec)
{
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm2_4
  long double v7; // st7
  float (__thiscall *getMargin)(struct btSphereShape *); // edx
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v13; // [esp+1Ch] [ebp-14h]
  float v14; // [esp+1Ch] [ebp-14h]
  btVector3 v15; // [esp+20h] [ebp-10h] BYREF

  *result = (btVector3)this->localGetSupportingVertexWithoutMargin(this, &v15, vec)->mVec128;
  v15.mVec128 = vec->mVec128;
  v4 = v15.mVec128.m128_f32[1];
  v5 = v15.mVec128.m128_f32[0];
  v6 = v15.mVec128.m128_f32[2];
  if ( (float)((float)((float)(v5 * v5) + (float)(v4 * v4)) + (float)(v6 * v6)) < 1.4210855e-14 )
  {
    v5 = -1.0;
    v4 = -1.0;
    v6 = -1.0;
    v15.mVec128.m128_u64[0] = 0xBF800000BF800000uLL;
    v15.mVec128.m128_i32[2] = -1082130432;
  }
  v7 = sqrtf((float)((float)(v5 * v5) + (float)(v4 * v4)) + (float)(v6 * v6));
  getMargin = this->getMargin;
  v13 = 1.0 / v7;
  v15.mVec128.m128_f32[0] = v13 * v15.mVec128.m128_f32[0];
  v15.mVec128.m128_f32[1] = v13 * v15.mVec128.m128_f32[1];
  v15.mVec128.m128_f32[2] = v13 * v15.mVec128.m128_f32[2];
  v14 = getMargin(this);
  v9 = v15.mVec128.m128_f32[2] * v14;
  v10 = result->mVec128.m128_f32[0] + (float)(v15.mVec128.m128_f32[0] * v14);
  result->mVec128.m128_f32[1] = result->mVec128.m128_f32[1] + (float)(v15.mVec128.m128_f32[1] * v14);
  v11 = result->mVec128.m128_f32[2] + v9;
  result->mVec128.m128_f32[0] = v10;
  result->mVec128.m128_f32[2] = v11;
  return result;
}
