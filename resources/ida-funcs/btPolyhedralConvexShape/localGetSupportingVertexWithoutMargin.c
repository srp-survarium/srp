btVector3 *__thiscall btPolyhedralConvexShape::localGetSupportingVertexWithoutMargin(
        btPolyhedralConvexShape *this,
        btVector3 *result,
        const btVector3 *vec0)
{
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  int i; // [esp+18h] [ebp-28h]
  float v12; // [esp+1Ch] [ebp-24h]
  float v13; // [esp+20h] [ebp-20h]
  float v14; // [esp+24h] [ebp-1Ch]
  float v15; // [esp+28h] [ebp-18h]
  btVector3 v16; // [esp+30h] [ebp-10h] BYREF

  v4 = vec0->mVec128.m128_f32[1];
  v12 = FLOAT_N9_9999998e17;
  v5 = vec0->mVec128.m128_f32[2];
  v6 = vec0->mVec128.m128_f32[0];
  v7 = (float)((float)(v5 * v5) + (float)(v4 * v4)) + (float)(v6 * v6);
  result->mVec128.m128_u64[0] = 0;
  result->mVec128.m128_u64[1] = 0;
  if ( v7 >= 0.000099999997 )
  {
    v8 = s_bm_current_air_resistance / fsqrt(v7);
    v13 = v6 * v8;
    v14 = v4 * v8;
    v15 = v5 * v8;
  }
  else
  {
    v13 = s_bm_current_air_resistance;
    v14 = 0.0;
    v15 = 0.0;
  }
  for ( i = 0; i < this->getNumVertices(this); ++i )
  {
    this->getVertex(this, i, &v16);
    v9 = (float)((float)(v16.mVec128.m128_f32[2] * v15) + (float)(v16.mVec128.m128_f32[1] * v14))
       + (float)(v16.mVec128.m128_f32[0] * v13);
    if ( v9 > v12 )
    {
      *result = (btVector3)v16.mVec128;
      v12 = v9;
    }
  }
  return result;
}
