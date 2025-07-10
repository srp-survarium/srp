void __thiscall btSphereShape::batchedUnitVectorGetSupportingVertexWithoutMargin(
        btSphereShape *this,
        const btVector3 *vectors,
        btVector3 *supportVerticesOut,
        int numVectors)
{
  int v4; // ecx
  int *v5; // eax

  v4 = numVectors;
  if ( numVectors > 0 )
  {
    v5 = &supportVerticesOut->mVec128.m128_i32[2];
    do
    {
      *(v5 - 2) = 0;
      *(v5 - 1) = 0;
      *v5 = 0;
      v5[1] = 0;
      v5 += 4;
      --v4;
    }
    while ( v4 );
  }
}
