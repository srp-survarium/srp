btVector3 *__thiscall btConvexShape::localGetSupportVertexNonVirtual(
        btConvexShape *this,
        btVector3 *result,
        const btVector3 *localDir)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm0_4
  long double v7; // st7
  int m_shapeType; // eax
  float v9; // xmm0_4
  btVector3 *SupportVertexWithoutMarginNonVirtual; // ecx
  btVector3 *v11; // eax
  float v12; // [esp+38h] [ebp-34h]
  btVector3 v13; // [esp+3Ch] [ebp-30h] BYREF
  float v14; // [esp+4Ch] [ebp-20h]
  float v15; // [esp+50h] [ebp-1Ch]
  float v16; // [esp+54h] [ebp-18h]
  btVector3 v17; // [esp+5Ch] [ebp-10h] BYREF

  v13.mVec128 = localDir->mVec128;
  v3 = v13.mVec128.m128_f32[1];
  v4 = v13.mVec128.m128_f32[2];
  v5 = v13.mVec128.m128_f32[0];
  if ( (float)((float)((float)(v3 * v3) + (float)(v4 * v4)) + (float)(v5 * v5)) < 1.4210855e-14 )
  {
    v5 = -1.0;
    v3 = -1.0;
    v4 = -1.0;
    v13.mVec128.m128_u64[0] = 0xBF800000BF800000uLL;
    v13.mVec128.m128_u64[1] = 3212836864LL;
  }
  v7 = 1.0 / sqrtf((float)((float)(v3 * v3) + (float)(v4 * v4)) + (float)(v5 * v5));
  m_shapeType = this->m_shapeType;
  v13.mVec128.m128_f32[0] = v13.mVec128.m128_f32[0] * v7;
  v13.mVec128.m128_f32[1] = v13.mVec128.m128_f32[1] * v7;
  v13.mVec128.m128_f32[2] = v7 * v13.mVec128.m128_f32[2];
  switch ( m_shapeType )
  {
    case 0:
    case 1:
    case 4:
    case 5:
    case 10:
    case 13:
      v9 = *(float *)&this[3].__vftable;
      break;
    case 8:
      v9 = *(float *)&this[2].__vftable * *(float *)&this[1].__vftable;
      break;
    default:
      v12 = this->getMargin(this);
      v9 = v12;
      break;
  }
  v14 = v13.mVec128.m128_f32[0] * v9;
  v15 = v13.mVec128.m128_f32[1] * v9;
  v16 = v13.mVec128.m128_f32[2] * v9;
  SupportVertexWithoutMarginNonVirtual = btConvexShape::localGetSupportVertexWithoutMarginNonVirtual(this, &v17, &v13);
  v11 = result;
  result->mVec128.m128_f32[0] = SupportVertexWithoutMarginNonVirtual->mVec128.m128_f32[0] + v14;
  result->mVec128.m128_f32[1] = SupportVertexWithoutMarginNonVirtual->mVec128.m128_f32[1] + v15;
  result->mVec128.m128_f32[2] = SupportVertexWithoutMarginNonVirtual->mVec128.m128_f32[2] + v16;
  result->mVec128.m128_i32[3] = 0;
  return v11;
}
