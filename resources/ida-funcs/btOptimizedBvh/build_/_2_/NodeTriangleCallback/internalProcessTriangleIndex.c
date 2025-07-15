void __thiscall btOptimizedBvh::build_::_2_::NodeTriangleCallback::internalProcessTriangleIndex(
        btOptimizedBvh::build::__l2::NodeTriangleCallback *this,
        btVector3 *triangle,
        unsigned int partId,
        unsigned int triangleIndex)
{
  float v4; // xmm2_4
  float v5; // xmm5_4
  float v6; // xmm6_4
  float v7; // xmm7_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  btAlignedObjectArray<btOptimizedBvhNode> *m_triangleNodes; // ebx
  __m128i v11; // xmm0
  int m_capacity; // ecx
  int m_size; // eax
  int v14; // esi
  btOptimizedBvhNode *v15; // eax
  int v16; // edx
  btOptimizedBvhNode *m_data; // eax
  btOptimizedBvhNode *v18; // edi
  int v19; // [esp+F8h] [ebp-6Ch]
  btOptimizedBvhNode *v20; // [esp+FCh] [ebp-68h]
  int v21; // [esp+100h] [ebp-64h]
  __m128i v22; // [esp+104h] [ebp-60h] BYREF
  __m128i v23; // [esp+114h] [ebp-50h] BYREF
  _OWORD v24[4]; // [esp+124h] [ebp-40h] BYREF

  v4 = triangle->mVec128.m128_f32[0];
  v5 = 9.9999998e17;
  v6 = 9.9999998e17;
  v7 = 9.9999998e17;
  strcpy(v23.m128i_i8, "k\v^]k\v^]k\v^]");
  v23.m128i_i8[13] = 0;
  v23.m128i_i16[7] = 0;
  v22.m128i_i64[0] = 0xDD5E0B6BDD5E0B6BuLL;
  v22.m128i_i64[1] = 3713928043LL;
  if ( v4 < 9.9999998e17 )
  {
    v5 = v4;
    *(float *)v23.m128i_i32 = v4;
  }
  if ( triangle->mVec128.m128_f32[1] < 9.9999998e17 )
  {
    v6 = triangle->mVec128.m128_f32[1];
    *(float *)&v23.m128i_i32[1] = v6;
  }
  if ( triangle->mVec128.m128_f32[2] < 9.9999998e17 )
  {
    v7 = triangle->mVec128.m128_f32[2];
    *(float *)&v23.m128i_i32[2] = v7;
  }
  if ( triangle->mVec128.m128_f32[3] < 0.0 )
    v23.m128i_i32[3] = triangle->mVec128.m128_i32[3];
  if ( v4 > -9.9999998e17 )
    *(float *)v22.m128i_i32 = v4;
  if ( triangle->mVec128.m128_f32[1] > -9.9999998e17 )
    v22.m128i_i32[1] = triangle->mVec128.m128_i32[1];
  if ( triangle->mVec128.m128_f32[2] <= -9.9999998e17 )
  {
    v8 = *(float *)&v22.m128i_i32[2];
  }
  else
  {
    v8 = triangle->mVec128.m128_f32[2];
    *(float *)&v22.m128i_i32[2] = v8;
  }
  if ( triangle->mVec128.m128_f32[3] <= 0.0 )
  {
    v9 = *(float *)&v22.m128i_i32[3];
  }
  else
  {
    v9 = triangle->mVec128.m128_f32[3];
    *(float *)&v22.m128i_i32[3] = v9;
  }
  if ( v5 > triangle[1].mVec128.m128_f32[0] )
  {
    v5 = triangle[1].mVec128.m128_f32[0];
    *(float *)v23.m128i_i32 = v5;
  }
  if ( v6 > triangle[1].mVec128.m128_f32[1] )
  {
    v6 = triangle[1].mVec128.m128_f32[1];
    *(float *)&v23.m128i_i32[1] = v6;
  }
  if ( v7 > triangle[1].mVec128.m128_f32[2] )
  {
    v7 = triangle[1].mVec128.m128_f32[2];
    *(float *)&v23.m128i_i32[2] = v7;
  }
  if ( *(float *)&v23.m128i_i32[3] > triangle[1].mVec128.m128_f32[3] )
    v23.m128i_i32[3] = triangle[1].mVec128.m128_i32[3];
  if ( triangle[1].mVec128.m128_f32[0] > *(float *)v22.m128i_i32 )
    v22.m128i_i32[0] = triangle[1].mVec128.m128_i32[0];
  if ( triangle[1].mVec128.m128_f32[1] > *(float *)&v22.m128i_i32[1] )
    v22.m128i_i32[1] = triangle[1].mVec128.m128_i32[1];
  if ( triangle[1].mVec128.m128_f32[2] > v8 )
  {
    v8 = triangle[1].mVec128.m128_f32[2];
    *(float *)&v22.m128i_i32[2] = v8;
  }
  if ( triangle[1].mVec128.m128_f32[3] > v9 )
  {
    v9 = triangle[1].mVec128.m128_f32[3];
    *(float *)&v22.m128i_i32[3] = v9;
  }
  if ( v5 > triangle[2].mVec128.m128_f32[0] )
    v23.m128i_i32[0] = triangle[2].mVec128.m128_i32[0];
  if ( v6 > triangle[2].mVec128.m128_f32[1] )
    v23.m128i_i32[1] = triangle[2].mVec128.m128_i32[1];
  if ( v7 > triangle[2].mVec128.m128_f32[2] )
    v23.m128i_i32[2] = triangle[2].mVec128.m128_i32[2];
  if ( *(float *)&v23.m128i_i32[3] > triangle[2].mVec128.m128_f32[3] )
    v23.m128i_i32[3] = triangle[2].mVec128.m128_i32[3];
  if ( triangle[2].mVec128.m128_f32[0] > *(float *)v22.m128i_i32 )
    v22.m128i_i32[0] = triangle[2].mVec128.m128_i32[0];
  if ( triangle[2].mVec128.m128_f32[1] > *(float *)&v22.m128i_i32[1] )
    v22.m128i_i32[1] = triangle[2].mVec128.m128_i32[1];
  if ( triangle[2].mVec128.m128_f32[2] > v8 )
    v22.m128i_i32[2] = triangle[2].mVec128.m128_i32[2];
  if ( triangle[2].mVec128.m128_f32[3] > v9 )
    v22.m128i_i32[3] = triangle[2].mVec128.m128_i32[3];
  m_triangleNodes = this->m_triangleNodes;
  v11 = _mm_load_si128(&v23);
  m_capacity = m_triangleNodes->m_capacity;
  *(_QWORD *)((char *)&v24[2] + 4) = __PAIR64__(triangleIndex, partId);
  m_size = m_triangleNodes->m_size;
  v24[0] = v11;
  v24[1] = _mm_load_si128(&v22);
  LODWORD(v24[2]) = -1;
  if ( m_size == m_capacity )
  {
    if ( m_size )
    {
      v14 = 2 * m_size;
      v19 = 2 * m_size;
    }
    else
    {
      v19 = 1;
      v14 = 1;
    }
    if ( m_capacity < v14 )
    {
      if ( v14 )
      {
        ++gNumAlignedAllocs;
        v20 = (btOptimizedBvhNode *)sAlignedAllocFunc(v14 << 6, 16);
      }
      else
      {
        v20 = 0;
      }
      if ( m_triangleNodes->m_size > 0 )
      {
        v15 = v20;
        v16 = 0;
        v21 = m_triangleNodes->m_size;
        do
        {
          if ( v15 )
          {
            qmemcpy(v15, &m_triangleNodes->m_data[v16], sizeof(btOptimizedBvhNode));
            v14 = v19;
          }
          ++v16;
          ++v15;
          --v21;
        }
        while ( v21 );
      }
      m_data = m_triangleNodes->m_data;
      if ( m_data )
      {
        if ( m_triangleNodes->m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(m_data);
        }
        m_triangleNodes->m_data = 0;
      }
      m_triangleNodes->m_ownsMemory = 1;
      m_triangleNodes->m_data = v20;
      m_triangleNodes->m_capacity = v14;
    }
  }
  v18 = &m_triangleNodes->m_data[m_triangleNodes->m_size];
  if ( v18 )
    qmemcpy(v18, v24, sizeof(btOptimizedBvhNode));
  ++m_triangleNodes->m_size;
}
