void __thiscall btOptimizedBvh::build_::_3_::QuantizedNodeTriangleCallback::internalProcessTriangleIndex(
        btOptimizedBvh::build::__l3::QuantizedNodeTriangleCallback *this,
        btVector3 *triangle,
        int partId,
        int triangleIndex)
{
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm5_4
  float v9; // xmm4_4
  const btQuantizedBvh *m_optimizedTree; // eax
  btAlignedObjectArray<btQuantizedBvhNode> *m_triangleNodes; // esi
  int m_capacity; // ecx
  int m_size; // eax
  int v14; // edi
  _QWORD *v15; // ebx
  int v16; // edx
  _QWORD *v17; // ecx
  int v18; // edi
  btQuantizedBvhNode *m_data; // eax
  btQuantizedBvhNode *v20; // eax
  btQuantizedBvhNode *v21; // eax
  int v22; // [esp+0h] [ebp-14h]
  __int64 node; // [esp+4h] [ebp-10h]
  __int64 node_8; // [esp+Ch] [ebp-8h]

  v4 = 9.9999998e17;
  v5 = -9.9999998e17;
  v6 = 9.9999998e17;
  v7 = 9.9999998e17;
  v8 = -9.9999998e17;
  v9 = -9.9999998e17;
  if ( triangle->mVec128.m128_f32[0] < 9.9999998e17 )
    v6 = triangle->mVec128.m128_f32[0];
  if ( triangle->mVec128.m128_f32[1] < 9.9999998e17 )
    v7 = triangle->mVec128.m128_f32[1];
  if ( triangle->mVec128.m128_f32[2] < 9.9999998e17 )
    v4 = triangle->mVec128.m128_f32[2];
  if ( triangle->mVec128.m128_f32[0] > -9.9999998e17 )
    v5 = triangle->mVec128.m128_f32[0];
  if ( triangle->mVec128.m128_f32[1] > -9.9999998e17 )
    v8 = triangle->mVec128.m128_f32[1];
  if ( triangle->mVec128.m128_f32[2] > -9.9999998e17 )
    v9 = triangle->mVec128.m128_f32[2];
  if ( v6 > triangle[1].mVec128.m128_f32[0] )
    v6 = triangle[1].mVec128.m128_f32[0];
  if ( v7 > triangle[1].mVec128.m128_f32[1] )
    v7 = triangle[1].mVec128.m128_f32[1];
  if ( v4 > triangle[1].mVec128.m128_f32[2] )
    v4 = triangle[1].mVec128.m128_f32[2];
  if ( triangle[1].mVec128.m128_f32[0] > v5 )
    v5 = triangle[1].mVec128.m128_f32[0];
  if ( triangle[1].mVec128.m128_f32[1] > v8 )
    v8 = triangle[1].mVec128.m128_f32[1];
  if ( triangle[1].mVec128.m128_f32[2] > v9 )
    v9 = triangle[1].mVec128.m128_f32[2];
  if ( v6 > triangle[2].mVec128.m128_f32[0] )
    v6 = triangle[2].mVec128.m128_f32[0];
  if ( v7 > triangle[2].mVec128.m128_f32[1] )
    v7 = triangle[2].mVec128.m128_f32[1];
  if ( v4 > triangle[2].mVec128.m128_f32[2] )
    v4 = triangle[2].mVec128.m128_f32[2];
  if ( triangle[2].mVec128.m128_f32[0] > v5 )
    v5 = triangle[2].mVec128.m128_f32[0];
  if ( triangle[2].mVec128.m128_f32[1] > v8 )
    v8 = triangle[2].mVec128.m128_f32[1];
  if ( triangle[2].mVec128.m128_f32[2] > v9 )
    v9 = triangle[2].mVec128.m128_f32[2];
  if ( (float)(v5 - v6) < 0.0020000001 )
  {
    v5 = v5 + 0.001;
    v6 = v6 - 0.001;
  }
  if ( (float)(v8 - v7) < 0.0020000001 )
  {
    v8 = v8 + 0.001;
    v7 = v7 - 0.001;
  }
  if ( (float)(v9 - v4) < 0.0020000001 )
  {
    v9 = v9 + 0.001;
    v4 = v4 - 0.001;
  }
  m_optimizedTree = this->m_optimizedTree;
  LOWORD(node) = (int)(float)(m_optimizedTree->m_bvhQuantization.mVec128.m128_f32[0]
                            * (float)(v6 - m_optimizedTree->m_bvhAabbMin.mVec128.m128_f32[0]))
               & 0xFFFE;
  WORD1(node) = (int)(float)(m_optimizedTree->m_bvhQuantization.mVec128.m128_f32[1]
                           * (float)(v7 - m_optimizedTree->m_bvhAabbMin.mVec128.m128_f32[1]))
              & 0xFFFE;
  m_triangleNodes = this->m_triangleNodes;
  m_capacity = m_triangleNodes->m_capacity;
  WORD2(node) = (int)(float)(m_optimizedTree->m_bvhQuantization.mVec128.m128_f32[2]
                           * (float)(v4 - m_optimizedTree->m_bvhAabbMin.mVec128.m128_f32[2]))
              & 0xFFFE;
  HIWORD(node) = (int)(float)((float)(m_optimizedTree->m_bvhQuantization.mVec128.m128_f32[0]
                                    * (float)(v5 - m_optimizedTree->m_bvhAabbMin.mVec128.m128_f32[0]))
                            + *(float *)&clear_value)
               | 1;
  LOWORD(node_8) = (int)(float)((float)(m_optimizedTree->m_bvhQuantization.mVec128.m128_f32[1]
                                      * (float)(v8 - m_optimizedTree->m_bvhAabbMin.mVec128.m128_f32[1]))
                              + *(float *)&clear_value)
                 | 1;
  WORD1(node_8) = (int)(float)((float)(m_optimizedTree->m_bvhQuantization.mVec128.m128_f32[2]
                                     * (float)(v9 - m_optimizedTree->m_bvhAabbMin.mVec128.m128_f32[2]))
                             + *(float *)&clear_value)
                | 1;
  m_size = m_triangleNodes->m_size;
  if ( m_size == m_capacity )
  {
    if ( m_size )
    {
      v14 = 2 * m_size;
      v22 = 2 * m_size;
    }
    else
    {
      v22 = 1;
      v14 = 1;
    }
    if ( m_capacity < v14 )
    {
      if ( v14 )
      {
        ++gNumAlignedAllocs;
        v15 = sAlignedAllocFunc(16 * v14, 16);
      }
      else
      {
        v15 = 0;
      }
      if ( m_triangleNodes->m_size > 0 )
      {
        v16 = 0;
        v17 = v15;
        v18 = m_triangleNodes->m_size;
        do
        {
          if ( v17 )
          {
            m_data = m_triangleNodes->m_data;
            *v17 = *(_QWORD *)m_data[v16].m_quantizedAabbMin;
            v17[1] = *(_QWORD *)&m_data[v16].m_quantizedAabbMax[1];
          }
          ++v16;
          v17 += 2;
          --v18;
        }
        while ( v18 );
        v14 = v22;
      }
      v20 = m_triangleNodes->m_data;
      if ( v20 )
      {
        if ( m_triangleNodes->m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v20);
        }
        m_triangleNodes->m_data = 0;
      }
      m_triangleNodes->m_ownsMemory = 1;
      m_triangleNodes->m_data = (btQuantizedBvhNode *)v15;
      m_triangleNodes->m_capacity = v14;
    }
  }
  v21 = &m_triangleNodes->m_data[m_triangleNodes->m_size];
  if ( v21 )
  {
    *(_QWORD *)v21->m_quantizedAabbMin = node;
    HIDWORD(node_8) = triangleIndex | (partId << 21);
    *(_QWORD *)&v21->m_quantizedAabbMax[1] = node_8;
  }
  ++m_triangleNodes->m_size;
}
