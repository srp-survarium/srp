void __thiscall btPolyhedralConvexShape::batchedUnitVectorGetSupportingVertexWithoutMargin(
        btPolyhedralConvexShape *this,
        const btVector3 *vectors,
        btVector3 *supportVerticesOut,
        int numVectors)
{
  int *v5; // eax
  int v6; // edx
  float *v7; // edi
  int i; // ebx
  float v9; // xmm0_4
  btVector3 *v10; // [esp+28h] [ebp-18h]
  int v11; // [esp+2Ch] [ebp-14h]
  unsigned __int64 v12; // [esp+30h] [ebp-10h] BYREF
  unsigned __int64 v13; // [esp+38h] [ebp-8h]

  if ( numVectors > 0 )
  {
    v5 = &supportVerticesOut->mVec128.m128_i32[3];
    v6 = numVectors;
    do
    {
      *v5 = -581039253;
      v5 += 4;
      --v6;
    }
    while ( v6 );
    v10 = supportVerticesOut;
    v7 = &vectors->mVec128.m128_f32[1];
    v11 = numVectors;
    do
    {
      for ( i = 0; i < this->getNumVertices(this); ++i )
      {
        this->getVertex(this, i, (btVector3 *)&v12);
        v9 = (float)((float)(v7[1] * *(float *)&v13) + (float)(*(float *)&v12 * *(v7 - 1)))
           + (float)(*((float *)&v12 + 1) * *v7);
        if ( v9 > v10->mVec128.m128_f32[3] )
        {
          v10->mVec128.m128_u64[0] = v12;
          v10->mVec128.m128_u64[1] = v13;
          v10->mVec128.m128_f32[3] = v9;
        }
      }
      ++v10;
      v7 += 4;
      --v11;
    }
    while ( v11 );
  }
}
