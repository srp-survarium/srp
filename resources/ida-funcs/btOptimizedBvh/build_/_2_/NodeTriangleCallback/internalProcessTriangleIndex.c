void __thiscall btOptimizedBvh::build_::_2_::NodeTriangleCallback::internalProcessTriangleIndex(
        btOptimizedBvh::build::__l2::NodeTriangleCallback *this,
        btVector3 *triangle,
        int partId,
        int triangleIndex)
{
  btAlignedObjectArray<btOptimizedBvhNode> *m_triangleNodes; // ebx
  int m_capacity; // ecx
  int m_size; // eax
  int v7; // eax
  btOptimizedBvhNode *v8; // edx
  btOptimizedBvhNode *v9; // edi
  int v10; // [esp+8h] [ebp-6Ch]
  int v11; // [esp+Ch] [ebp-68h]
  btOptimizedBvhNode *v12; // [esp+10h] [ebp-64h]
  float v13; // [esp+14h] [ebp-60h]
  float v14; // [esp+18h] [ebp-5Ch]
  float v15; // [esp+1Ch] [ebp-58h]
  float v16; // [esp+20h] [ebp-54h]
  float v17; // [esp+24h] [ebp-50h]
  float v18; // [esp+28h] [ebp-4Ch]
  float v19; // [esp+2Ch] [ebp-48h]
  float v20; // [esp+30h] [ebp-44h]
  _DWORD v21[16]; // [esp+34h] [ebp-40h] BYREF

  v13 = FLOAT_9_9999998e17;
  v14 = FLOAT_9_9999998e17;
  v15 = FLOAT_9_9999998e17;
  v16 = 0.0;
  v17 = FLOAT_N9_9999998e17;
  v18 = FLOAT_N9_9999998e17;
  v19 = FLOAT_N9_9999998e17;
  v20 = 0.0;
  if ( triangle->mVec128.m128_f32[0] < 9.9999998e17 )
    v13 = triangle->mVec128.m128_f32[0];
  if ( triangle->mVec128.m128_f32[1] < 9.9999998e17 )
    v14 = triangle->mVec128.m128_f32[1];
  if ( triangle->mVec128.m128_f32[2] < 9.9999998e17 )
    v15 = triangle->mVec128.m128_f32[2];
  if ( triangle->mVec128.m128_f32[3] < 0.0 )
    v16 = triangle->mVec128.m128_f32[3];
  if ( triangle->mVec128.m128_f32[0] > -9.9999998e17 )
    v17 = triangle->mVec128.m128_f32[0];
  if ( triangle->mVec128.m128_f32[1] > -9.9999998e17 )
    v18 = triangle->mVec128.m128_f32[1];
  if ( triangle->mVec128.m128_f32[2] > -9.9999998e17 )
    v19 = triangle->mVec128.m128_f32[2];
  if ( triangle->mVec128.m128_f32[3] > 0.0 )
    v20 = triangle->mVec128.m128_f32[3];
  if ( v13 > triangle[1].mVec128.m128_f32[0] )
    v13 = triangle[1].mVec128.m128_f32[0];
  if ( v14 > triangle[1].mVec128.m128_f32[1] )
    v14 = triangle[1].mVec128.m128_f32[1];
  if ( v15 > triangle[1].mVec128.m128_f32[2] )
    v15 = triangle[1].mVec128.m128_f32[2];
  if ( v16 > triangle[1].mVec128.m128_f32[3] )
    v16 = triangle[1].mVec128.m128_f32[3];
  if ( triangle[1].mVec128.m128_f32[0] > v17 )
    v17 = triangle[1].mVec128.m128_f32[0];
  if ( triangle[1].mVec128.m128_f32[1] > v18 )
    v18 = triangle[1].mVec128.m128_f32[1];
  if ( triangle[1].mVec128.m128_f32[2] > v19 )
    v19 = triangle[1].mVec128.m128_f32[2];
  if ( triangle[1].mVec128.m128_f32[3] > v20 )
    v20 = triangle[1].mVec128.m128_f32[3];
  if ( v13 > triangle[2].mVec128.m128_f32[0] )
    v13 = triangle[2].mVec128.m128_f32[0];
  if ( v14 > triangle[2].mVec128.m128_f32[1] )
    v14 = triangle[2].mVec128.m128_f32[1];
  if ( v15 > triangle[2].mVec128.m128_f32[2] )
    v15 = triangle[2].mVec128.m128_f32[2];
  if ( v16 > triangle[2].mVec128.m128_f32[3] )
    v16 = triangle[2].mVec128.m128_f32[3];
  if ( triangle[2].mVec128.m128_f32[0] > v17 )
    v17 = triangle[2].mVec128.m128_f32[0];
  if ( triangle[2].mVec128.m128_f32[1] > v18 )
    v18 = triangle[2].mVec128.m128_f32[1];
  if ( triangle[2].mVec128.m128_f32[2] > v19 )
    v19 = triangle[2].mVec128.m128_f32[2];
  if ( triangle[2].mVec128.m128_f32[3] > v20 )
    v20 = triangle[2].mVec128.m128_f32[3];
  *(float *)v21 = v13;
  *(float *)&v21[1] = v14;
  *(float *)&v21[2] = v15;
  m_triangleNodes = this->m_triangleNodes;
  m_capacity = m_triangleNodes->m_capacity;
  *(float *)&v21[3] = v16;
  *(float *)&v21[4] = v17;
  *(float *)&v21[5] = v18;
  *(float *)&v21[6] = v19;
  *(float *)&v21[7] = v20;
  v21[8] = -1;
  v21[9] = partId;
  v21[10] = triangleIndex;
  m_size = m_triangleNodes->m_size;
  if ( m_size == m_capacity )
  {
    v10 = m_size ? 2 * m_size : 1;
    if ( m_capacity < v10 )
    {
      if ( v10 )
        v12 = (btOptimizedBvhNode *)btAlignedAllocInternal(v10 << 6);
      else
        v12 = 0;
      v7 = m_triangleNodes->m_size;
      if ( v7 > 0 )
      {
        v8 = v12;
        v11 = 0;
        do
        {
          if ( v8 )
            qmemcpy(v8, &m_triangleNodes->m_data[v11], sizeof(btOptimizedBvhNode));
          ++v11;
          ++v8;
          --v7;
        }
        while ( v7 );
      }
      if ( m_triangleNodes->m_data )
      {
        if ( m_triangleNodes->m_ownsMemory )
          btAlignedFreeInternal(m_triangleNodes->m_data);
        m_triangleNodes->m_data = 0;
      }
      m_triangleNodes->m_data = v12;
      m_triangleNodes->m_ownsMemory = 1;
      m_triangleNodes->m_capacity = v10;
    }
  }
  v9 = &m_triangleNodes->m_data[m_triangleNodes->m_size];
  if ( v9 )
    qmemcpy(v9, v21, sizeof(btOptimizedBvhNode));
  ++m_triangleNodes->m_size;
}
