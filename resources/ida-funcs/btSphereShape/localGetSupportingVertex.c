btVector3 *__thiscall btSphereShape::localGetSupportingVertex(
        btSphereShape *this,
        btVector3 *result,
        const btVector3 *vec)
{
  float v3; // xmm1_4
  float v4; // xmm3_4
  float v5; // xmm4_4
  btSphereShape_vtbl *v6; // eax
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v13; // [esp+Ch] [ebp-14h]
  btVector3 v14; // [esp+10h] [ebp-10h] BYREF

  *result = *(btVector3 *)((int (__stdcall *)(btVector3 *, const btVector3 *))this->localGetSupportingVertexWithoutMargin)(
                            &v14,
                            vec);
  v14.mVec128 = vec->mVec128;
  v3 = v14.mVec128.m128_f32[2];
  v4 = v14.mVec128.m128_f32[0];
  v5 = v14.mVec128.m128_f32[1];
  if ( (float)((float)((float)(v3 * v3) + (float)(v4 * v4)) + (float)(v5 * v5)) < 1.4210855e-14 )
  {
    v3 = FLOAT_N1_0;
    v4 = FLOAT_N1_0;
    v5 = FLOAT_N1_0;
  }
  v6 = this->__vftable;
  v7 = s_bm_current_air_resistance / fsqrt((float)((float)(v3 * v3) + (float)(v4 * v4)) + (float)(v5 * v5));
  v14.mVec128.m128_f32[0] = v7 * v4;
  v14.mVec128.m128_f32[1] = v7 * v5;
  v14.mVec128.m128_f32[2] = v3 * v7;
  v13 = v6->getMargin(this);
  v8 = v14.mVec128.m128_f32[2] * v13;
  v9 = result->mVec128.m128_f32[0] + (float)(v14.mVec128.m128_f32[0] * v13);
  result->mVec128.m128_f32[1] = result->mVec128.m128_f32[1] + (float)(v14.mVec128.m128_f32[1] * v13);
  v10 = result->mVec128.m128_f32[2] + v8;
  result->mVec128.m128_f32[0] = v9;
  result->mVec128.m128_f32[2] = v10;
  return result;
}
