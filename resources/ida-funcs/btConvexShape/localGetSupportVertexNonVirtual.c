btVector3 *__thiscall btConvexShape::localGetSupportVertexNonVirtual(
        btConvexShape *this,
        btVector3 *result,
        const btVector3 *localDir)
{
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v7; // xmm0_4
  btVector3 *SupportVertexWithoutMarginNonVirtual; // ecx
  btVector3 *v9; // eax
  float MarginNonVirtual; // [esp+Ch] [ebp-34h]
  btVector3 localDira; // [esp+10h] [ebp-30h] BYREF
  float v12; // [esp+20h] [ebp-20h]
  float v13; // [esp+24h] [ebp-1Ch]
  float v14; // [esp+28h] [ebp-18h]
  btVector3 resulta; // [esp+30h] [ebp-10h] BYREF

  localDira.mVec128 = localDir->mVec128;
  v3 = localDira.mVec128.m128_f32[1];
  v4 = localDira.mVec128.m128_f32[0];
  v5 = localDira.mVec128.m128_f32[2];
  if ( (float)((float)((float)(v3 * v3) + (float)(v4 * v4)) + (float)(v5 * v5)) < 1.4210855e-14 )
  {
    v4 = FLOAT_N1_0;
    v3 = FLOAT_N1_0;
    v5 = FLOAT_N1_0;
    localDira.mVec128.m128_i32[3] = 0;
  }
  v7 = s_bm_current_air_resistance / fsqrt((float)((float)(v3 * v3) + (float)(v4 * v4)) + (float)(v5 * v5));
  localDira.mVec128.m128_f32[0] = v7 * v4;
  localDira.mVec128.m128_f32[1] = v7 * v3;
  localDira.mVec128.m128_f32[2] = v7 * v5;
  MarginNonVirtual = btConvexShape::getMarginNonVirtual(this);
  v12 = (float)(v7 * v4) * MarginNonVirtual;
  v13 = (float)(v7 * v3) * MarginNonVirtual;
  v14 = (float)(v7 * v5) * MarginNonVirtual;
  SupportVertexWithoutMarginNonVirtual = btConvexShape::localGetSupportVertexWithoutMarginNonVirtual(
                                           this,
                                           &resulta,
                                           &localDira);
  v9 = result;
  result->mVec128.m128_f32[0] = SupportVertexWithoutMarginNonVirtual->mVec128.m128_f32[0] + v12;
  result->mVec128.m128_f32[1] = SupportVertexWithoutMarginNonVirtual->mVec128.m128_f32[1] + v13;
  result->mVec128.m128_f32[2] = SupportVertexWithoutMarginNonVirtual->mVec128.m128_f32[2] + v14;
  result->mVec128.m128_i32[3] = 0;
  return v9;
}
