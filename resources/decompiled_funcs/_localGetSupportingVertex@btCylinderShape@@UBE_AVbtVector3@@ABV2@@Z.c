btVector3 *__thiscall btCylinderShape::localGetSupportingVertex(
        btCylinderShape *this,
        btVector3 *result,
        const btVector3 *vec)
{
  btVector3 *v4; // eax
  float (__thiscall *getMargin)(struct btCylinderShape *); // edx
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  long double v9; // st7
  float (__thiscall *v10)(struct btCylinderShape *); // edx
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v15; // [esp+1Ch] [ebp-14h]
  float v16; // [esp+1Ch] [ebp-14h]
  btVector3 v17; // [esp+20h] [ebp-10h] BYREF

  v4 = this->localGetSupportingVertexWithoutMargin(this, &v17, vec);
  result->mVec128.m128_u64[0] = v4->mVec128.m128_u64[0];
  getMargin = this->getMargin;
  result->mVec128.m128_u64[1] = v4->mVec128.m128_u64[1];
  if ( ((double (__thiscall *)(btCylinderShape *))getMargin)(this) != 0.0 )
  {
    v17.mVec128 = vec->mVec128;
    v6 = v17.mVec128.m128_f32[1];
    v7 = v17.mVec128.m128_f32[0];
    v8 = v17.mVec128.m128_f32[2];
    if ( (float)((float)((float)(v7 * v7) + (float)(v6 * v6)) + (float)(v8 * v8)) < 1.4210855e-14 )
    {
      v7 = -1.0;
      v6 = -1.0;
      v8 = -1.0;
      v17.mVec128.m128_u64[0] = 0xBF800000BF800000uLL;
      v17.mVec128.m128_i32[2] = -1082130432;
    }
    v9 = sqrtf((float)((float)(v7 * v7) + (float)(v6 * v6)) + (float)(v8 * v8));
    v10 = this->getMargin;
    v15 = 1.0 / v9;
    v17.mVec128.m128_f32[0] = v15 * v17.mVec128.m128_f32[0];
    v17.mVec128.m128_f32[1] = v15 * v17.mVec128.m128_f32[1];
    v17.mVec128.m128_f32[2] = v15 * v17.mVec128.m128_f32[2];
    v16 = v10(this);
    v11 = v17.mVec128.m128_f32[2] * v16;
    v12 = result->mVec128.m128_f32[0] + (float)(v17.mVec128.m128_f32[0] * v16);
    result->mVec128.m128_f32[1] = result->mVec128.m128_f32[1] + (float)(v17.mVec128.m128_f32[1] * v16);
    v13 = result->mVec128.m128_f32[2] + v11;
    result->mVec128.m128_f32[0] = v12;
    result->mVec128.m128_f32[2] = v13;
  }
  return result;
}
