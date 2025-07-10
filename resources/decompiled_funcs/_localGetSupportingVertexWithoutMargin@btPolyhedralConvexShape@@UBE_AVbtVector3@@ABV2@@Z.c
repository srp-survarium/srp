btVector3 *__thiscall btPolyhedralConvexShape::localGetSupportingVertexWithoutMargin(
        btPolyhedralConvexShape *this,
        btVector3 *result,
        const btVector3 *vec0)
{
  float v4; // xmm0_4
  long double v5; // st7
  int i; // edi
  float v8; // [esp+94h] [ebp-28h]
  btVector3 v9; // [esp+9Ch] [ebp-20h]
  btVector3 v10; // [esp+ACh] [ebp-10h] BYREF

  v8 = -9.9999998e17;
  v9.mVec128 = vec0->mVec128;
  v4 = (float)((float)(v9.mVec128.m128_f32[2] * v9.mVec128.m128_f32[2])
             + (float)(v9.mVec128.m128_f32[1] * v9.mVec128.m128_f32[1]))
     + (float)(vec0->mVec128.m128_f32[0] * vec0->mVec128.m128_f32[0]);
  result->mVec128.m128_u64[0] = 0;
  result->mVec128.m128_u64[1] = 0;
  if ( v4 >= 0.000099999997 )
  {
    v5 = 1.0 / sqrtf(v4);
    v9.mVec128.m128_f32[0] = v9.mVec128.m128_f32[0] * v5;
    v9.mVec128.m128_f32[1] = v9.mVec128.m128_f32[1] * v5;
    v9.mVec128.m128_f32[2] = v5 * v9.mVec128.m128_f32[2];
  }
  else
  {
    v9.mVec128.m128_u64[0] = (unsigned int)clear_value;
    v9.mVec128.m128_i32[2] = 0;
  }
  for ( i = 0; i < this->getNumVertices(this); ++i )
  {
    this->getVertex(this, i, &v10);
    if ( (float)((float)((float)(v10.mVec128.m128_f32[2] * v9.mVec128.m128_f32[2])
                       + (float)(v10.mVec128.m128_f32[1] * v9.mVec128.m128_f32[1]))
               + (float)(v10.mVec128.m128_f32[0] * v9.mVec128.m128_f32[0])) > v8 )
    {
      v8 = (float)((float)(v10.mVec128.m128_f32[2] * v9.mVec128.m128_f32[2])
                 + (float)(v10.mVec128.m128_f32[1] * v9.mVec128.m128_f32[1]))
         + (float)(v10.mVec128.m128_f32[0] * v9.mVec128.m128_f32[0]);
      *result = (btVector3)v10.mVec128;
    }
  }
  return result;
}
