void __thiscall btOptimizedBvh::build_::_3_::QuantizedNodeTriangleCallback::internalProcessTriangleIndex(
        btOptimizedBvh::build::__l3::QuantizedNodeTriangleCallback *this,
        btVector3 *triangle,
        int partId,
        int triangleIndex)
{
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm6_4
  float v9; // xmm5_4
  const btQuantizedBvh *m_optimizedTree; // eax
  btAlignedObjectArray<btQuantizedBvhNode> *m_triangleNodes; // ebx
  int m_capacity; // ecx
  int m_size; // eax
  int v14; // eax
  _DWORD *v15; // ecx
  int v16; // edx
  btQuantizedBvhNode *v17; // esi
  btQuantizedBvhNode *v18; // edi
  unsigned __int16 *v19; // edi
  int v20; // [esp+0h] [ebp-18h]
  _DWORD *v21; // [esp+4h] [ebp-14h]
  int v22; // [esp+8h] [ebp-10h]
  int v23; // [esp+Ch] [ebp-Ch]
  int v24; // [esp+10h] [ebp-8h]

  v4 = FLOAT_9_9999998e17;
  v5 = FLOAT_9_9999998e17;
  v6 = FLOAT_9_9999998e17;
  v7 = FLOAT_N9_9999998e17;
  v8 = FLOAT_N9_9999998e17;
  v9 = FLOAT_N9_9999998e17;
  if ( triangle->mVec128.m128_f32[0] < 9.9999998e17 )
    v5 = triangle->mVec128.m128_f32[0];
  if ( triangle->mVec128.m128_f32[1] < 9.9999998e17 )
    v6 = triangle->mVec128.m128_f32[1];
  if ( triangle->mVec128.m128_f32[2] < 9.9999998e17 )
    v4 = triangle->mVec128.m128_f32[2];
  if ( triangle->mVec128.m128_f32[0] > -9.9999998e17 )
    v7 = triangle->mVec128.m128_f32[0];
  if ( triangle->mVec128.m128_f32[1] > -9.9999998e17 )
    v8 = triangle->mVec128.m128_f32[1];
  if ( triangle->mVec128.m128_f32[2] > -9.9999998e17 )
    v9 = triangle->mVec128.m128_f32[2];
  if ( v5 > triangle[1].mVec128.m128_f32[0] )
    v5 = triangle[1].mVec128.m128_f32[0];
  if ( v6 > triangle[1].mVec128.m128_f32[1] )
    v6 = triangle[1].mVec128.m128_f32[1];
  if ( v4 > triangle[1].mVec128.m128_f32[2] )
    v4 = triangle[1].mVec128.m128_f32[2];
  if ( triangle[1].mVec128.m128_f32[0] > v7 )
    v7 = triangle[1].mVec128.m128_f32[0];
  if ( triangle[1].mVec128.m128_f32[1] > v8 )
    v8 = triangle[1].mVec128.m128_f32[1];
  if ( triangle[1].mVec128.m128_f32[2] > v9 )
    v9 = triangle[1].mVec128.m128_f32[2];
  if ( v5 > triangle[2].mVec128.m128_f32[0] )
    v5 = triangle[2].mVec128.m128_f32[0];
  if ( v6 > triangle[2].mVec128.m128_f32[1] )
    v6 = triangle[2].mVec128.m128_f32[1];
  if ( v4 > triangle[2].mVec128.m128_f32[2] )
    v4 = triangle[2].mVec128.m128_f32[2];
  if ( triangle[2].mVec128.m128_f32[0] > v7 )
    v7 = triangle[2].mVec128.m128_f32[0];
  if ( triangle[2].mVec128.m128_f32[1] > v8 )
    v8 = triangle[2].mVec128.m128_f32[1];
  if ( triangle[2].mVec128.m128_f32[2] > v9 )
    v9 = triangle[2].mVec128.m128_f32[2];
  if ( (float)(v7 - v5) < 0.0020000001 )
  {
    v7 = v7 + 0.001;
    v5 = v5 - 0.001;
  }
  if ( (float)(v8 - v6) < 0.0020000001 )
  {
    v8 = v8 + 0.001;
    v6 = v6 - 0.001;
  }
  if ( (float)(v9 - v4) < 0.0020000001 )
  {
    v9 = v9 + 0.001;
    v4 = v4 - 0.001;
  }
  m_optimizedTree = this->m_optimizedTree;
  m_triangleNodes = this->m_triangleNodes;
  LOWORD(v22) = (int)(float)(m_optimizedTree->m_bvhQuantization.mVec128.m128_f32[0]
                           * (float)(v5 - m_optimizedTree->m_bvhAabbMin.mVec128.m128_f32[0]))
              & 0xFFFE;
  m_capacity = m_triangleNodes->m_capacity;
  HIWORD(v22) = (int)(float)(m_optimizedTree->m_bvhQuantization.mVec128.m128_f32[1]
                           * (float)(v6 - m_optimizedTree->m_bvhAabbMin.mVec128.m128_f32[1]))
              & 0xFFFE;
  HIWORD(v23) = (int)(float)((float)(m_optimizedTree->m_bvhQuantization.mVec128.m128_f32[0]
                                   * (float)(v7 - m_optimizedTree->m_bvhAabbMin.mVec128.m128_f32[0]))
                           + s_bm_current_air_resistance)
              | 1;
  LOWORD(v24) = (int)(float)((float)(m_optimizedTree->m_bvhQuantization.mVec128.m128_f32[1]
                                   * (float)(v8 - m_optimizedTree->m_bvhAabbMin.mVec128.m128_f32[1]))
                           + s_bm_current_air_resistance)
              | 1;
  HIWORD(v24) = (int)(float)((float)(m_optimizedTree->m_bvhQuantization.mVec128.m128_f32[2]
                                   * (float)(v9 - m_optimizedTree->m_bvhAabbMin.mVec128.m128_f32[2]))
                           + s_bm_current_air_resistance)
              | 1;
  LOWORD(v23) = (int)(float)(m_optimizedTree->m_bvhQuantization.mVec128.m128_f32[2]
                           * (float)(v4 - m_optimizedTree->m_bvhAabbMin.mVec128.m128_f32[2]))
              & 0xFFFE;
  m_size = m_triangleNodes->m_size;
  if ( m_size == m_capacity )
  {
    v20 = m_size ? 2 * m_size : 1;
    if ( m_capacity < v20 )
    {
      if ( v20 )
        v21 = btAlignedAllocInternal(16 * v20);
      else
        v21 = 0;
      v14 = m_triangleNodes->m_size;
      if ( v14 > 0 )
      {
        v15 = v21;
        v16 = 0;
        do
        {
          if ( v15 )
          {
            v17 = &m_triangleNodes->m_data[v16];
            *v15 = *(_DWORD *)v17->m_quantizedAabbMin;
            v17 = (btQuantizedBvhNode *)((char *)v17 + 4);
            v15[1] = *(_DWORD *)v17->m_quantizedAabbMin;
            v17 = (btQuantizedBvhNode *)((char *)v17 + 4);
            v15[2] = *(_DWORD *)v17->m_quantizedAabbMin;
            v15[3] = *(_DWORD *)&v17->m_quantizedAabbMin[2];
          }
          ++v16;
          v15 += 4;
          --v14;
        }
        while ( v14 );
      }
      if ( m_triangleNodes->m_data )
      {
        if ( m_triangleNodes->m_ownsMemory )
          btAlignedFreeInternal(m_triangleNodes->m_data);
        m_triangleNodes->m_data = 0;
      }
      m_triangleNodes->m_data = (btQuantizedBvhNode *)v21;
      m_triangleNodes->m_ownsMemory = 1;
      m_triangleNodes->m_capacity = v20;
    }
  }
  v18 = &m_triangleNodes->m_data[m_triangleNodes->m_size];
  if ( v18 )
  {
    *(_DWORD *)v18->m_quantizedAabbMin = v22;
    v19 = &v18->m_quantizedAabbMin[2];
    *(_DWORD *)v19 = v23;
    v19 += 2;
    *(_DWORD *)v19 = v24;
    *((_DWORD *)v19 + 1) = triangleIndex | (partId << 21);
  }
  ++m_triangleNodes->m_size;
}
