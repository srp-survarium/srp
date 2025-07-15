btVector3 *__thiscall btCylinderShape::localGetSupportingVertex(
        btCylinderShape *this,
        btVector3 *result,
        const btVector3 *vec)
{
  btVector3 *v4; // esi
  btCylinderShape_vtbl *v5; // eax
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  btCylinderShape_vtbl *v9; // eax
  float v10; // xmm0_4
  btVector3 *v11; // eax
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // [esp+Ch] [ebp-14h]
  btVector3 v16; // [esp+10h] [ebp-10h] BYREF

  v4 = this->localGetSupportingVertexWithoutMargin(this, &v16, vec);
  v5 = this->__vftable;
  result->mVec128.m128_i32[0] = v4->mVec128.m128_i32[0];
  v4 = (btVector3 *)((char *)v4 + 4);
  result->mVec128.m128_i32[1] = v4->mVec128.m128_i32[0];
  result->mVec128.m128_u64[1] = *(unsigned __int64 *)((char *)v4->mVec128.m128_u64 + 4);
  if ( ((double (__thiscall *)(btCylinderShape *))v5->getMargin)(this) == 0.0 )
    return result;
  v16.mVec128 = vec->mVec128;
  v6 = v16.mVec128.m128_f32[2];
  v7 = v16.mVec128.m128_f32[0];
  v8 = v16.mVec128.m128_f32[1];
  if ( (float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(v8 * v8)) < 1.4210855e-14 )
  {
    v6 = FLOAT_N1_0;
    v7 = FLOAT_N1_0;
    v8 = FLOAT_N1_0;
  }
  v9 = this->__vftable;
  v10 = s_bm_current_air_resistance / fsqrt((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(v8 * v8));
  v16.mVec128.m128_f32[0] = v10 * v7;
  v16.mVec128.m128_f32[1] = v10 * v8;
  v16.mVec128.m128_f32[2] = v6 * v10;
  v15 = v9->getMargin(this);
  v11 = result;
  v12 = v16.mVec128.m128_f32[2] * v15;
  v13 = result->mVec128.m128_f32[0] + (float)(v16.mVec128.m128_f32[0] * v15);
  result->mVec128.m128_f32[1] = result->mVec128.m128_f32[1] + (float)(v16.mVec128.m128_f32[1] * v15);
  v14 = result->mVec128.m128_f32[2] + v12;
  result->mVec128.m128_f32[0] = v13;
  result->mVec128.m128_f32[2] = v14;
  return v11;
}
