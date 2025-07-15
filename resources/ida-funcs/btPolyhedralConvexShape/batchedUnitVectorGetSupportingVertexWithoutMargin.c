void __thiscall btPolyhedralConvexShape::batchedUnitVectorGetSupportingVertexWithoutMargin(
        btPolyhedralConvexShape *this,
        const btVector3 *vectors,
        btVector3 *supportVerticesOut,
        int numVectors)
{
  btPolyhedralConvexShape *v4; // esi
  float *v5; // eax
  int v6; // edi
  float *v7; // ebx
  float v8; // xmm0_4
  int i; // [esp+10h] [ebp-20h]
  btVector3 *v10; // [esp+14h] [ebp-1Ch]
  int v11; // [esp+18h] [ebp-18h]
  float v13; // [esp+20h] [ebp-10h] BYREF
  float v14; // [esp+24h] [ebp-Ch]
  float v15; // [esp+28h] [ebp-8h]
  int v16; // [esp+2Ch] [ebp-4h]

  v4 = this;
  if ( numVectors > 0 )
  {
    v5 = &supportVerticesOut->mVec128.m128_f32[3];
    v6 = numVectors;
    do
    {
      *v5 = FLOAT_N9_9999998e17;
      v5 += 4;
      --v6;
    }
    while ( v6 );
    v10 = supportVerticesOut;
    v7 = &vectors->mVec128.m128_f32[1];
    v11 = numVectors;
    do
    {
      for ( i = 0; i < v4->getNumVertices(v4); ++i )
      {
        v4->getVertex(v4, i, (btVector3 *)&v13);
        v8 = (float)((float)(v7[1] * v15) + (float)(v13 * *(v7 - 1))) + (float)(v14 * *v7);
        if ( v8 > v10->mVec128.m128_f32[3] )
        {
          v10->mVec128.m128_f32[0] = v13;
          v10->mVec128.m128_f32[1] = v14;
          v10->mVec128.m128_f32[2] = v15;
          v10->mVec128.m128_i32[3] = v16;
          v4 = this;
          v10->mVec128.m128_f32[3] = v8;
        }
      }
      ++v10;
      v7 += 4;
      --v11;
    }
    while ( v11 );
  }
}
