const char *__userpurge btQuantizedBvh::serialize@<eax>(
        btQuantizedBvh *this@<ecx>,
        void *a2@<edi>,
        btVector3 *dataBuffer,
        btSerializer *serializer)
{
  void *v5; // eax
  int m_size; // edi
  int v7; // eax
  int v8; // ecx
  btSerializer *v9; // eax
  int v10; // edi
  btOptimizedBvhNode *m_data; // edx
  double v12; // st7
  float *m128_f32; // edx
  btOptimizedBvhNode *v14; // edx
  double v15; // st7
  float *v16; // edx
  void *v17; // eax
  int v18; // edi
  int v19; // eax
  int v20; // ecx
  int v21; // edx
  void *v22; // eax
  int v23; // edi
  int v24; // eax
  int v25; // ecx
  int v26; // edx
  int v29; // [esp+28h] [ebp+Ch]

  dataBuffer[1] = this->m_bvhAabbMax;
  *dataBuffer = this->m_bvhAabbMin;
  dataBuffer[2] = this->m_bvhQuantization;
  dataBuffer[3].mVec128.m128_i32[0] = this->m_curNodeIndex;
  dataBuffer[3].mVec128.m128_i32[1] = this->m_useQuantization;
  dataBuffer[3].mVec128.m128_i32[2] = this->m_contiguousNodes.m_size;
  if ( this->m_contiguousNodes.m_size )
    v5 = serializer->getUniquePointer(serializer, this->m_contiguousNodes.m_data);
  else
    v5 = 0;
  dataBuffer[4].mVec128.m128_i32[0] = (int)v5;
  if ( v5 )
  {
    m_size = this->m_contiguousNodes.m_size;
    v7 = ((int (__thiscall *)(btSerializer *, int, int, void *))serializer->allocate)(serializer, 48, m_size, a2);
    v8 = *(_DWORD *)(v7 + 8);
    v29 = v7;
    if ( m_size > 0 )
    {
      v9 = serializer;
      v10 = 0;
      do
      {
        m_data = this->m_contiguousNodes.m_data;
        v12 = m_data[v10].m_aabbMaxOrg.mVec128.m128_f32[0];
        m128_f32 = m_data[v10].m_aabbMaxOrg.mVec128.m128_f32;
        *(float *)(v8 + 16) = v12;
        v8 += 48;
        *(float *)(v8 - 28) = m128_f32[1];
        *(float *)(v8 - 24) = m128_f32[2];
        *(float *)(v8 - 20) = m128_f32[3];
        v14 = this->m_contiguousNodes.m_data;
        v15 = v14[v10].m_aabbMinOrg.mVec128.m128_f32[0];
        v16 = v14[v10].m_aabbMinOrg.mVec128.m128_f32;
        *(float *)(v8 - 48) = v15;
        ++v10;
        v9 = (btSerializer *)((char *)v9 - 1);
        *(float *)(v8 - 44) = v16[1];
        *(float *)(v8 - 40) = v16[2];
        *(float *)(v8 - 36) = v16[3];
        *(_DWORD *)(v8 - 16) = this->m_contiguousNodes.m_data[v10 - 1].m_escapeIndex;
        *(_DWORD *)(v8 - 12) = this->m_contiguousNodes.m_data[v10 - 1].m_subPart;
        *(_DWORD *)(v8 - 8) = this->m_contiguousNodes.m_data[v10 - 1].m_triangleIndex;
      }
      while ( v9 );
      v7 = v29;
    }
    a2 = this->m_contiguousNodes.m_data;
    ((void (__thiscall *)(btSerializer *, int, const char *, int))serializer->finalizeChunk)(
      serializer,
      v7,
      "btOptimizedBvhNodeData",
      1497453121);
  }
  dataBuffer[3].mVec128.m128_i32[3] = this->m_quantizedContiguousNodes.m_size;
  if ( this->m_quantizedContiguousNodes.m_size )
    v17 = serializer->getUniquePointer(serializer, this->m_quantizedContiguousNodes.m_data);
  else
    v17 = 0;
  dataBuffer[4].mVec128.m128_i32[1] = (int)v17;
  if ( v17 )
  {
    v18 = this->m_quantizedContiguousNodes.m_size;
    v19 = ((int (__thiscall *)(btSerializer *, int, int, void *))serializer->allocate)(serializer, 16, v18, a2);
    v20 = *(_DWORD *)(v19 + 8);
    if ( v18 > 0 )
    {
      v21 = 0;
      do
      {
        *(_DWORD *)(v20 + 12) = this->m_quantizedContiguousNodes.m_data[v21].m_escapeIndexOrTriangleIndex;
        *(_WORD *)(v20 + 6) = this->m_quantizedContiguousNodes.m_data[v21].m_quantizedAabbMax[0];
        *(_WORD *)(v20 + 8) = this->m_quantizedContiguousNodes.m_data[v21].m_quantizedAabbMax[1];
        *(_WORD *)(v20 + 10) = this->m_quantizedContiguousNodes.m_data[v21].m_quantizedAabbMax[2];
        *(_WORD *)v20 = this->m_quantizedContiguousNodes.m_data[v21].m_quantizedAabbMin[0];
        *(_WORD *)(v20 + 2) = this->m_quantizedContiguousNodes.m_data[v21].m_quantizedAabbMin[1];
        *(_WORD *)(v20 + 4) = this->m_quantizedContiguousNodes.m_data[v21++].m_quantizedAabbMin[2];
        v20 += 16;
        --v18;
      }
      while ( v18 );
    }
    a2 = this->m_quantizedContiguousNodes.m_data;
    ((void (__thiscall *)(btSerializer *, int, const char *, int))serializer->finalizeChunk)(
      serializer,
      v19,
      "btQuantizedBvhNodeData",
      1497453121);
  }
  dataBuffer[4].mVec128.m128_i32[3] = this->m_traversalMode;
  dataBuffer[5].mVec128.m128_i32[0] = this->m_SubtreeHeaders.m_size;
  if ( this->m_SubtreeHeaders.m_size )
    v22 = serializer->getUniquePointer(serializer, this->m_SubtreeHeaders.m_data);
  else
    v22 = 0;
  dataBuffer[4].mVec128.m128_i32[2] = (int)v22;
  if ( v22 )
  {
    v23 = this->m_SubtreeHeaders.m_size;
    v24 = ((int (__thiscall *)(btSerializer *, int, int, void *))serializer->allocate)(serializer, 20, v23, a2);
    v25 = *(_DWORD *)(v24 + 8);
    if ( v23 > 0 )
    {
      v26 = 0;
      do
      {
        *(_WORD *)(v25 + 14) = this->m_SubtreeHeaders.m_data[v26].m_quantizedAabbMax[0];
        *(_WORD *)(v25 + 16) = this->m_SubtreeHeaders.m_data[v26].m_quantizedAabbMax[1];
        *(_WORD *)(v25 + 18) = this->m_SubtreeHeaders.m_data[v26].m_quantizedAabbMax[2];
        *(_WORD *)(v25 + 8) = this->m_SubtreeHeaders.m_data[v26].m_quantizedAabbMin[0];
        *(_WORD *)(v25 + 10) = this->m_SubtreeHeaders.m_data[v26].m_quantizedAabbMin[1];
        *(_WORD *)(v25 + 12) = this->m_SubtreeHeaders.m_data[v26].m_quantizedAabbMin[2];
        *(_DWORD *)v25 = this->m_SubtreeHeaders.m_data[v26].m_rootNodeIndex;
        *(_DWORD *)(v25 + 4) = this->m_SubtreeHeaders.m_data[v26++].m_subtreeSize;
        v25 += 20;
        --v23;
      }
      while ( v23 );
    }
    ((void (__thiscall *)(btSerializer *, int, const char *, int))serializer->finalizeChunk)(
      serializer,
      v24,
      "btBvhSubtreeInfoData",
      1497453121);
  }
  return "btQuantizedBvhFloatData";
}
