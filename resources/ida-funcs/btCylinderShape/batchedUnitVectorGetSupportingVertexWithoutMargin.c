void __thiscall btCylinderShape::batchedUnitVectorGetSupportingVertexWithoutMargin(
        btCylinderShape *this,
        const btVector3 *vectors,
        btVector3 *supportVerticesOut,
        int numVectors)
{
  __m128 *p_mVec128; // edi
  btVector3 *v5; // eax
  bool v6; // zf
  btVector3 *v7; // [esp+14h] [ebp-1Ch]
  int v8; // [esp+18h] [ebp-18h]
  btVector3 *p_m_implicitShapeDimensions; // [esp+1Ch] [ebp-14h]
  btVector3 v10; // [esp+20h] [ebp-10h] BYREF

  if ( numVectors > 0 )
  {
    p_m_implicitShapeDimensions = &this->m_implicitShapeDimensions;
    v7 = supportVerticesOut;
    v8 = numVectors;
    do
    {
      p_mVec128 = &v7->mVec128;
      v5 = CylinderLocalSupportY(
             p_m_implicitShapeDimensions,
             (btVector3 *)((char *)v7++ + (char *)vectors - (char *)supportVerticesOut),
             &v10);
      v6 = v8-- == 1;
      p_mVec128->m128_i32[0] = v5->mVec128.m128_i32[0];
      p_mVec128 = (__m128 *)((char *)p_mVec128 + 4);
      p_mVec128->m128_i32[0] = v5->mVec128.m128_i32[1];
      p_mVec128 = (__m128 *)((char *)p_mVec128 + 4);
      p_mVec128->m128_i32[0] = v5->mVec128.m128_i32[2];
      p_mVec128->m128_i32[1] = v5->mVec128.m128_i32[3];
    }
    while ( !v6 );
  }
}
