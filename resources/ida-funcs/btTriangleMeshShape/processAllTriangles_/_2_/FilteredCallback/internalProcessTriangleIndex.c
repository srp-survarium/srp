void __thiscall btTriangleMeshShape::processAllTriangles_::_2_::FilteredCallback::internalProcessTriangleIndex(
        btTriangleMeshShape::processAllTriangles::__l2::FilteredCallback *this,
        btVector3 *triangle,
        int partId,
        int triangleIndex)
{
  float v4; // xmm1_4
  btVector3 *v5; // eax
  float v6; // xmm2_4
  btVector3 *v7; // eax
  float *v8; // edx
  float *v9; // eax
  float *v10; // edx
  float *v11; // eax

  v4 = triangle[1].mVec128.m128_f32[0];
  v5 = triangle;
  if ( v4 <= triangle->mVec128.m128_f32[0] )
    v5 = triangle + 1;
  v6 = triangle[2].mVec128.m128_f32[0];
  if ( v6 <= v5->mVec128.m128_f32[0] )
    v5 = triangle + 2;
  if ( v5->mVec128.m128_f32[0] <= this->m_aabbMax.mVec128.m128_f32[0] )
  {
    v7 = triangle;
    if ( triangle->mVec128.m128_f32[0] <= v4 )
      v7 = triangle + 1;
    if ( v7->mVec128.m128_f32[0] <= v6 )
      v7 = triangle + 2;
    if ( this->m_aabbMin.mVec128.m128_f32[0] <= v7->mVec128.m128_f32[0] )
    {
      v8 = &triangle[1].mVec128.m128_f32[2];
      v9 = &triangle->mVec128.m128_f32[2];
      if ( triangle[1].mVec128.m128_f32[2] <= triangle->mVec128.m128_f32[2] )
        v9 = &triangle[1].mVec128.m128_f32[2];
      if ( triangle[2].mVec128.m128_f32[2] <= *v9 )
        v9 = &triangle[2].mVec128.m128_f32[2];
      if ( *v9 <= this->m_aabbMax.mVec128.m128_f32[2] )
      {
        if ( triangle->mVec128.m128_f32[2] > *v8 )
          v8 = &triangle->mVec128.m128_f32[2];
        if ( *v8 <= triangle[2].mVec128.m128_f32[2] )
          v8 = &triangle[2].mVec128.m128_f32[2];
        if ( this->m_aabbMin.mVec128.m128_f32[2] <= *v8 )
        {
          v10 = &triangle[1].mVec128.m128_f32[1];
          v11 = &triangle->mVec128.m128_f32[1];
          if ( triangle[1].mVec128.m128_f32[1] <= triangle->mVec128.m128_f32[1] )
            v11 = &triangle[1].mVec128.m128_f32[1];
          if ( triangle[2].mVec128.m128_f32[1] <= *v11 )
            v11 = &triangle[2].mVec128.m128_f32[1];
          if ( *v11 <= this->m_aabbMax.mVec128.m128_f32[1] )
          {
            if ( triangle->mVec128.m128_f32[1] > *v10 )
              v10 = &triangle->mVec128.m128_f32[1];
            if ( *v10 <= triangle[2].mVec128.m128_f32[1] )
              v10 = &triangle[2].mVec128.m128_f32[1];
            if ( this->m_aabbMin.mVec128.m128_f32[1] <= *v10 )
              this->m_callback->processTriangle(this->m_callback, triangle, partId, triangleIndex);
          }
        }
      }
    }
  }
}
