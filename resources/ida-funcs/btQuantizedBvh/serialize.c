const char *__thiscall btQuantizedBvh::serialize(btQuantizedBvh *this, float *dataBuffer, btSerializer *serializer)
{
  float *v3; // ebx
  float *v5; // ecx
  btVector3 *p_m_bvhAabbMax; // eax
  int v7; // edi
  double v8; // st7
  int v9; // ecx
  btVector3 *p_m_bvhAabbMin; // eax
  double v11; // st7
  float *v12; // ecx
  btVector3 *p_m_bvhQuantization; // eax
  int v14; // edi
  double v15; // st7
  void *v17; // eax
  btChunk *v18; // eax
  _DWORD *m_oldPtr; // ecx
  int v20; // eax
  btVector3 *p_m_aabbMaxOrg; // edx
  double v22; // st7
  float *v23; // ebx
  void *v24; // eax
  btChunk *v25; // eax
  _DWORD *v26; // ecx
  int v27; // edx
  void *v28; // eax
  int v29; // ebx
  btChunk *v30; // eax
  _WORD *v31; // ecx
  int v32; // edx
  btChunk *v34; // [esp+Ch] [ebp-Ch]
  int v35; // [esp+10h] [ebp-8h]
  float *v36; // [esp+14h] [ebp-4h]
  int v37; // [esp+14h] [ebp-4h]
  int v38; // [esp+20h] [ebp+8h]
  int v39; // [esp+20h] [ebp+8h]
  int m_size; // [esp+24h] [ebp+Ch]
  int v41; // [esp+24h] [ebp+Ch]
  char *v42; // [esp+24h] [ebp+Ch]

  v3 = dataBuffer;
  v5 = dataBuffer + 4;
  p_m_bvhAabbMax = &this->m_bvhAabbMax;
  v7 = 4;
  do
  {
    v8 = p_m_bvhAabbMax->mVec128.m128_f32[0];
    p_m_bvhAabbMax = (btVector3 *)((char *)p_m_bvhAabbMax + 4);
    *v5++ = v8;
    --v7;
  }
  while ( v7 );
  v9 = 0;
  p_m_bvhAabbMin = &this->m_bvhAabbMin;
  do
  {
    v11 = p_m_bvhAabbMin->mVec128.m128_f32[0];
    p_m_bvhAabbMin = (btVector3 *)((char *)p_m_bvhAabbMin + 4);
    dataBuffer[v9++] = v11;
  }
  while ( v9 < 4 );
  v12 = dataBuffer + 8;
  p_m_bvhQuantization = &this->m_bvhQuantization;
  v14 = 4;
  do
  {
    v15 = p_m_bvhQuantization->mVec128.m128_f32[0];
    p_m_bvhQuantization = (btVector3 *)((char *)p_m_bvhQuantization + 4);
    *v12++ = v15;
    --v14;
  }
  while ( v14 );
  dataBuffer[12] = *(float *)&this->m_curNodeIndex;
  *((_DWORD *)dataBuffer + 13) = this->m_useQuantization;
  dataBuffer[14] = *(float *)&this->m_contiguousNodes.m_size;
  v17 = 0;
  if ( this->m_contiguousNodes.m_size )
    v17 = serializer->getUniquePointer(serializer, this->m_contiguousNodes.m_data);
  *((_DWORD *)dataBuffer + 16) = v17;
  if ( v17 )
  {
    m_size = this->m_contiguousNodes.m_size;
    v18 = serializer->allocate(serializer, 48, m_size);
    m_oldPtr = v18->m_oldPtr;
    v34 = v18;
    if ( m_size > 0 )
    {
      v20 = 0;
      v35 = m_size;
      do
      {
        v41 = 0;
        p_m_aabbMaxOrg = &this->m_contiguousNodes.m_data[v20].m_aabbMaxOrg;
        v36 = (float *)(m_oldPtr + 4);
        do
        {
          v22 = p_m_aabbMaxOrg->mVec128.m128_f32[v41++];
          *v36++ = v22;
        }
        while ( v41 < 4 );
        v42 = (char *)((char *)&this->m_contiguousNodes.m_data[v20] - (char *)m_oldPtr);
        v23 = (float *)m_oldPtr;
        v37 = 4;
        do
        {
          *v23 = *(float *)((char *)v23 + (_DWORD)v42);
          ++v23;
          --v37;
        }
        while ( v37 );
        m_oldPtr[8] = this->m_contiguousNodes.m_data[v20].m_escapeIndex;
        m_oldPtr[9] = this->m_contiguousNodes.m_data[v20].m_subPart;
        m_oldPtr[10] = this->m_contiguousNodes.m_data[v20++].m_triangleIndex;
        m_oldPtr += 12;
        --v35;
      }
      while ( v35 );
      v3 = dataBuffer;
    }
    serializer->finalizeChunk(serializer, v34, "btOptimizedBvhNodeData", 1497453121, this->m_contiguousNodes.m_data);
  }
  v3[15] = *(float *)&this->m_quantizedContiguousNodes.m_size;
  v24 = 0;
  if ( this->m_quantizedContiguousNodes.m_size )
    v24 = serializer->getUniquePointer(serializer, this->m_quantizedContiguousNodes.m_data);
  *((_DWORD *)v3 + 17) = v24;
  if ( v24 )
  {
    v38 = this->m_quantizedContiguousNodes.m_size;
    v25 = serializer->allocate(serializer, 16, v38);
    v26 = v25->m_oldPtr;
    if ( v38 > 0 )
    {
      v27 = 0;
      do
      {
        v26[3] = this->m_quantizedContiguousNodes.m_data[v27].m_escapeIndexOrTriangleIndex;
        *((_WORD *)v26 + 3) = this->m_quantizedContiguousNodes.m_data[v27].m_quantizedAabbMax[0];
        *((_WORD *)v26 + 4) = this->m_quantizedContiguousNodes.m_data[v27].m_quantizedAabbMax[1];
        *((_WORD *)v26 + 5) = this->m_quantizedContiguousNodes.m_data[v27].m_quantizedAabbMax[2];
        *(_WORD *)v26 = this->m_quantizedContiguousNodes.m_data[v27].m_quantizedAabbMin[0];
        *((_WORD *)v26 + 1) = this->m_quantizedContiguousNodes.m_data[v27].m_quantizedAabbMin[1];
        *((_WORD *)v26 + 2) = this->m_quantizedContiguousNodes.m_data[v27++].m_quantizedAabbMin[2];
        v26 += 4;
        --v38;
      }
      while ( v38 );
    }
    serializer->finalizeChunk(
      serializer,
      v25,
      "btQuantizedBvhNodeData",
      1497453121,
      this->m_quantizedContiguousNodes.m_data);
  }
  v3[19] = *(float *)&this->m_traversalMode;
  v3[20] = *(float *)&this->m_SubtreeHeaders.m_size;
  v28 = 0;
  if ( this->m_SubtreeHeaders.m_size )
    v28 = serializer->getUniquePointer(serializer, this->m_SubtreeHeaders.m_data);
  *((_DWORD *)v3 + 18) = v28;
  if ( v28 )
  {
    v29 = this->m_SubtreeHeaders.m_size;
    v30 = serializer->allocate(serializer, 20, v29);
    v31 = v30->m_oldPtr;
    if ( v29 > 0 )
    {
      v32 = 0;
      v39 = v29;
      do
      {
        v31[7] = this->m_SubtreeHeaders.m_data[v32].m_quantizedAabbMax[0];
        v31[8] = this->m_SubtreeHeaders.m_data[v32].m_quantizedAabbMax[1];
        v31[9] = this->m_SubtreeHeaders.m_data[v32].m_quantizedAabbMax[2];
        v31[4] = this->m_SubtreeHeaders.m_data[v32].m_quantizedAabbMin[0];
        v31[5] = this->m_SubtreeHeaders.m_data[v32].m_quantizedAabbMin[1];
        v31[6] = this->m_SubtreeHeaders.m_data[v32].m_quantizedAabbMin[2];
        *(_DWORD *)v31 = this->m_SubtreeHeaders.m_data[v32].m_rootNodeIndex;
        *((_DWORD *)v31 + 1) = this->m_SubtreeHeaders.m_data[v32++].m_subtreeSize;
        v31 += 10;
        --v39;
      }
      while ( v39 );
    }
    serializer->finalizeChunk(serializer, v30, "btBvhSubtreeInfoData", 1497453121, this->m_SubtreeHeaders.m_data);
  }
  return "btQuantizedBvhFloatData";
}


char __thiscall btQuantizedBvh::serialize(
        btQuantizedBvh *this,
        btQuantizedBvh *o_alignedDataBuffer,
        unsigned int __formal,
        bool i_swapEndian)
{
  btVector3 *v5; // edi
  char *v6; // esi
  char *v7; // eax
  int v8; // ecx
  char *v9; // esi
  char *v10; // eax
  char *v11; // esi
  char *v12; // eax
  btAlignedObjectArray<btOptimizedBvhNode> *v13; // ecx
  int v14; // ecx
  int v15; // eax
  unsigned int v16; // ecx
  int v17; // ecx
  int v18; // eax
  btAlignedObjectArray<btOptimizedBvhNode> *v19; // ecx
  btAlignedObjectArray<btOptimizedBvhNode> *v20; // ecx
  int v21; // ecx
  unsigned int v22; // eax
  btOptimizedBvhNode *v23; // ecx
  int v24; // edx
  char *v25; // ecx
  char *v26; // esi
  bool v27; // zf
  char *v28; // ecx
  char *v29; // esi
  unsigned int v30; // ecx
  int v31; // edx
  int v32; // eax
  int *v33; // esi
  btOptimizedBvhNode *v34; // edi
  btVector3 *p_m_aabbMaxOrg; // esi
  btVector3 *v36; // edi
  btAlignedObjectArray<btOptimizedBvhNode> *v37; // ecx
  btAlignedObjectArray<btOptimizedBvhNode> *v38; // ecx
  unsigned int v39; // eax
  unsigned int v40; // ecx
  int v41; // eax
  btQuantizedBvh *v43; // [esp-Ch] [ebp-2Ch]
  int v44; // [esp-4h] [ebp-24h]
  int v45; // [esp+Ch] [ebp-14h]
  int v46; // [esp+10h] [ebp-10h]
  int v47; // [esp+10h] [ebp-10h]
  int v48; // [esp+14h] [ebp-Ch]
  char *v49; // [esp+14h] [ebp-Ch]
  char *v50; // [esp+14h] [ebp-Ch]
  btQuantizedBvh *buffer; // [esp+18h] [ebp-8h]
  char *buffera; // [esp+18h] [ebp-8h]
  char *v54; // [esp+1Ch] [ebp-4h]
  char *v55; // [esp+1Ch] [ebp-4h]
  int v56; // [esp+28h] [ebp+8h]
  int v57; // [esp+28h] [ebp+8h]
  int v58; // [esp+28h] [ebp+8h]
  int v59; // [esp+28h] [ebp+8h]
  btAlignedObjectArray<btOptimizedBvhNode> *i; // [esp+30h] [ebp+10h]

  v5 = (btVector3 *)this;
  this->m_subtreeHeaderCount = this->m_SubtreeHeaders.m_size;
  if ( o_alignedDataBuffer )
    btQuantizedBvh::btQuantizedBvh(this, o_alignedDataBuffer);
  if ( i_swapEndian )
  {
    o_alignedDataBuffer->m_curNodeIndex = ((v5[4].mVec128.m128_i32[1] & 0xFF00 | (v5[4].mVec128.m128_i32[1] << 16)) << 8)
                                        | ((HIWORD(v5[4].mVec128.m128_i32[1])
                                          | (unsigned int)&s_ui_commands_allocator.m_buffer[1969824]
                                          & v5[4].mVec128.m128_i32[1]) >> 8);
    v6 = &o_alignedDataBuffer->m_bvhAabbMin.mVec128.m128_i8[3];
    v7 = &v5[1].mVec128.m128_i8[2];
    v8 = (char *)o_alignedDataBuffer - (char *)v5;
    v56 = 4;
    do
    {
      *(v6 - 3) = v7[1];
      *(v6 - 2) = *v7;
      v7[v8] = *(v7 - 1);
      *v6 = *(v7 - 2);
      v6 += 4;
      v7 += 4;
      --v56;
    }
    while ( v56 );
    v9 = &o_alignedDataBuffer->m_bvhAabbMax.mVec128.m128_i8[3];
    v10 = &v5[2].mVec128.m128_i8[2];
    v57 = 4;
    do
    {
      *(v9 - 3) = v10[1];
      *(v9 - 2) = *v10;
      v10[v8] = *(v10 - 1);
      *v9 = *(v10 - 2);
      v9 += 4;
      v10 += 4;
      --v57;
    }
    while ( v57 );
    v11 = &o_alignedDataBuffer->m_bvhQuantization.mVec128.m128_i8[3];
    v12 = &v5[3].mVec128.m128_i8[2];
    v58 = 4;
    do
    {
      *(v11 - 3) = v12[1];
      *(v11 - 2) = *v12;
      v12[v8] = *(v12 - 1);
      *v11 = *(v12 - 2);
      v11 += 4;
      v12 += 4;
      --v58;
    }
    while ( v58 );
    o_alignedDataBuffer->m_traversalMode = ((v5[9].mVec128.m128_i32[3] & 0xFF00 | (v5[9].mVec128.m128_i32[3] << 16)) << 8)
                                         | ((HIWORD(v5[9].mVec128.m128_i32[3])
                                           | (unsigned int)&s_ui_commands_allocator.m_buffer[1969824]
                                           & v5[9].mVec128.m128_i32[3]) >> 8);
    o_alignedDataBuffer->m_subtreeHeaderCount = ((v5[11].mVec128.m128_i32[1] & 0xFF00
                                                | (v5[11].mVec128.m128_i32[1] << 16)) << 8)
                                              | ((HIWORD(v5[11].mVec128.m128_i32[1])
                                                | (unsigned int)&s_ui_commands_allocator.m_buffer[1969824]
                                                & v5[11].mVec128.m128_i32[1]) >> 8);
  }
  else
  {
    o_alignedDataBuffer->m_curNodeIndex = v5[4].mVec128.m128_i32[1];
    o_alignedDataBuffer->m_bvhAabbMin = (btVector3)v5[1].mVec128;
    o_alignedDataBuffer->m_bvhAabbMax = this->m_bvhAabbMax;
    o_alignedDataBuffer->m_bvhQuantization = this->m_bvhQuantization;
    v5 = (btVector3 *)this;
    o_alignedDataBuffer->m_traversalMode = this->m_traversalMode;
    o_alignedDataBuffer->m_subtreeHeaderCount = this->m_subtreeHeaderCount;
  }
  o_alignedDataBuffer->m_useQuantization = v5[4].mVec128.m128_i8[8];
  v44 = v5[4].mVec128.m128_i32[1];
  v13 = (btAlignedObjectArray<btOptimizedBvhNode> *)&o_alignedDataBuffer[1];
  buffer = o_alignedDataBuffer + 1;
  v59 = v44;
  v43 = o_alignedDataBuffer + 1;
  if ( v5[4].mVec128.m128_i8[8] )
  {
    btAlignedObjectArray<btOptimizedBvhNode>::initializeFromBuffer(
      v13,
      (int)&o_alignedDataBuffer->m_quantizedContiguousNodes,
      v43,
      v44,
      v44);
    if ( i_swapEndian )
    {
      v14 = v59;
      if ( v59 <= 0 )
      {
LABEL_22:
        v19 = (btAlignedObjectArray<btOptimizedBvhNode> *)(16 * v14);
        buffera = (char *)buffer + (_DWORD)v19;
        btAlignedObjectArray<btOptimizedBvhNode>::initializeFromBuffer(
          v19,
          (int)&o_alignedDataBuffer->m_quantizedContiguousNodes,
          0,
          0,
          0);
        goto LABEL_37;
      }
      v15 = 0;
      v48 = v59;
      do
      {
        o_alignedDataBuffer->m_quantizedContiguousNodes.m_data[v15].m_quantizedAabbMin[0] = __ROL2__(
                                                                                              *(_WORD *)(v15 * 16 + v5[9].mVec128.m128_i32[1]),
                                                                                              8);
        o_alignedDataBuffer->m_quantizedContiguousNodes.m_data[v15].m_quantizedAabbMin[1] = __ROL2__(
                                                                                              *(_WORD *)(v15 * 16 + v5[9].mVec128.m128_i32[1] + 2),
                                                                                              8);
        o_alignedDataBuffer->m_quantizedContiguousNodes.m_data[v15].m_quantizedAabbMin[2] = __ROL2__(
                                                                                              *(_WORD *)(v15 * 16 + v5[9].mVec128.m128_i32[1] + 4),
                                                                                              8);
        o_alignedDataBuffer->m_quantizedContiguousNodes.m_data[v15].m_quantizedAabbMax[0] = __ROL2__(
                                                                                              *(_WORD *)(v15 * 16 + v5[9].mVec128.m128_i32[1] + 6),
                                                                                              8);
        o_alignedDataBuffer->m_quantizedContiguousNodes.m_data[v15].m_quantizedAabbMax[1] = __ROL2__(
                                                                                              *(_WORD *)(v15 * 16 + v5[9].mVec128.m128_i32[1] + 8),
                                                                                              8);
        o_alignedDataBuffer->m_quantizedContiguousNodes.m_data[v15].m_quantizedAabbMax[2] = __ROL2__(
                                                                                              *(_WORD *)(v15 * 16 + v5[9].mVec128.m128_i32[1] + 10),
                                                                                              8);
        v16 = *(_DWORD *)(v15 * 16 + v5[9].mVec128.m128_i32[1] + 12);
        o_alignedDataBuffer->m_quantizedContiguousNodes.m_data[v15++].m_escapeIndexOrTriangleIndex = ((v16 & 0xFF00 | (v16 << 16)) << 8) | ((HIWORD(v16) | (unsigned int)&s_ui_commands_allocator.m_buffer[1969824] & v16) >> 8);
        --v48;
      }
      while ( v48 );
    }
    else if ( v59 > 0 )
    {
      v17 = v59;
      v18 = 0;
      do
      {
        o_alignedDataBuffer->m_quantizedContiguousNodes.m_data[v18].m_quantizedAabbMin[0] = *(_WORD *)(v18 * 16 + v5[9].mVec128.m128_i32[1]);
        o_alignedDataBuffer->m_quantizedContiguousNodes.m_data[v18].m_quantizedAabbMin[1] = *(_WORD *)(v18 * 16 + v5[9].mVec128.m128_i32[1] + 2);
        o_alignedDataBuffer->m_quantizedContiguousNodes.m_data[v18].m_quantizedAabbMin[2] = *(_WORD *)(v18 * 16 + v5[9].mVec128.m128_i32[1] + 4);
        o_alignedDataBuffer->m_quantizedContiguousNodes.m_data[v18].m_quantizedAabbMax[0] = *(_WORD *)(v18 * 16 + v5[9].mVec128.m128_i32[1] + 6);
        o_alignedDataBuffer->m_quantizedContiguousNodes.m_data[v18].m_quantizedAabbMax[1] = *(_WORD *)(v18 * 16 + v5[9].mVec128.m128_i32[1] + 8);
        o_alignedDataBuffer->m_quantizedContiguousNodes.m_data[v18].m_quantizedAabbMax[2] = *(_WORD *)(v18 * 16 + v5[9].mVec128.m128_i32[1] + 10);
        o_alignedDataBuffer->m_quantizedContiguousNodes.m_data[v18].m_escapeIndexOrTriangleIndex = *(_DWORD *)(v18 * 16 + v5[9].mVec128.m128_i32[1] + 12);
        ++v18;
        --v17;
      }
      while ( v17 );
    }
    v14 = v59;
    goto LABEL_22;
  }
  btAlignedObjectArray<btOptimizedBvhNode>::initializeFromBuffer(
    v13,
    (int)&o_alignedDataBuffer->m_contiguousNodes,
    v43,
    v44,
    v44);
  if ( !i_swapEndian )
  {
    if ( v59 > 0 )
    {
      v31 = v59;
      v32 = 0;
      do
      {
        v33 = (int *)(v32 * 64 + v5[6].mVec128.m128_i32[3]);
        v34 = &o_alignedDataBuffer->m_contiguousNodes.m_data[v32];
        v34->m_aabbMinOrg.mVec128.m128_i32[0] = *v33++;
        v34 = (btOptimizedBvhNode *)((char *)v34 + 4);
        v34->m_aabbMinOrg.mVec128.m128_i32[0] = *v33++;
        v34 = (btOptimizedBvhNode *)((char *)v34 + 4);
        v34->m_aabbMinOrg.mVec128.m128_i32[0] = *v33;
        v34->m_aabbMinOrg.mVec128.m128_i32[1] = v33[1];
        p_m_aabbMaxOrg = &this->m_contiguousNodes.m_data[v32].m_aabbMaxOrg;
        v36 = &o_alignedDataBuffer->m_contiguousNodes.m_data[v32].m_aabbMaxOrg;
        v36->mVec128.m128_i32[0] = p_m_aabbMaxOrg->mVec128.m128_i32[0];
        p_m_aabbMaxOrg = (btVector3 *)((char *)p_m_aabbMaxOrg + 4);
        v36 = (btVector3 *)((char *)v36 + 4);
        v36->mVec128.m128_i32[0] = p_m_aabbMaxOrg->mVec128.m128_i32[0];
        p_m_aabbMaxOrg = (btVector3 *)((char *)p_m_aabbMaxOrg + 4);
        v36 = (btVector3 *)((char *)v36 + 4);
        v36->mVec128.m128_i32[0] = p_m_aabbMaxOrg->mVec128.m128_i32[0];
        v36->mVec128.m128_i32[1] = p_m_aabbMaxOrg->mVec128.m128_i32[1];
        o_alignedDataBuffer->m_contiguousNodes.m_data[v32].m_escapeIndex = this->m_contiguousNodes.m_data[v32].m_escapeIndex;
        o_alignedDataBuffer->m_contiguousNodes.m_data[v32].m_subPart = this->m_contiguousNodes.m_data[v32].m_subPart;
        v5 = (btVector3 *)this;
        o_alignedDataBuffer->m_contiguousNodes.m_data[v32].m_triangleIndex = this->m_contiguousNodes.m_data[v32].m_triangleIndex;
        ++v32;
        --v31;
      }
      while ( v31 );
    }
    goto LABEL_35;
  }
  v21 = v59;
  if ( v59 > 0 )
  {
    v22 = 0;
    v45 = v59;
    do
    {
      v23 = &o_alignedDataBuffer->m_contiguousNodes.m_data[v22 / 0x40];
      v24 = v22 + v5[6].mVec128.m128_i32[3];
      v49 = &v23->m_aabbMinOrg.mVec128.m128_i8[3];
      v54 = (char *)v23 - v24;
      v25 = &v23->m_aabbMinOrg.mVec128.m128_i8[3];
      v26 = (char *)(v24 + 2);
      v46 = 4;
      do
      {
        *(v25 - 3) = v26[1];
        *(v25 - 2) = *v26;
        v26[(_DWORD)v54] = *(v26 - 1);
        *v49 = *(v26 - 2);
        v25 = v49 + 4;
        v26 += 4;
        v27 = v46-- == 1;
        v49 += 4;
      }
      while ( !v27 );
      v55 = &o_alignedDataBuffer->m_contiguousNodes.m_data[v22 / 0x40].m_aabbMaxOrg.mVec128.m128_i8[3];
      v50 = (char *)o_alignedDataBuffer->m_contiguousNodes.m_data - v5[6].mVec128.m128_i32[3];
      v28 = v55;
      v29 = (char *)(v5[6].mVec128.m128_i32[3] + v22 + 18);
      v47 = 4;
      do
      {
        *(v28 - 3) = v29[1];
        *(v28 - 2) = *v29;
        v50[(_DWORD)v29] = *(v29 - 1);
        *v55 = *(v29 - 2);
        v28 = v55 + 4;
        v29 += 4;
        v27 = v47-- == 1;
        v55 += 4;
      }
      while ( !v27 );
      o_alignedDataBuffer->m_contiguousNodes.m_data[v22 / 0x40].m_escapeIndex = ((*(_DWORD *)(v5[6].mVec128.m128_i32[3]
                                                                                            + v22
                                                                                            + 32)
                                                                                & 0xFF00
                                                                                | (*(_DWORD *)(v5[6].mVec128.m128_i32[3]
                                                                                             + v22
                                                                                             + 32) << 16)) << 8)
                                                                              | ((HIWORD(*(_DWORD *)(v5[6].mVec128.m128_i32[3] + v22 + 32))
                                                                                | (unsigned int)&s_ui_commands_allocator.m_buffer[1969824]
                                                                                & *(_DWORD *)(v5[6].mVec128.m128_i32[3]
                                                                                            + v22
                                                                                            + 32)) >> 8);
      o_alignedDataBuffer->m_contiguousNodes.m_data[v22 / 0x40].m_subPart = ((*(_DWORD *)(v5[6].mVec128.m128_i32[3]
                                                                                        + v22
                                                                                        + 36)
                                                                            & 0xFF00
                                                                            | (*(_DWORD *)(v5[6].mVec128.m128_i32[3]
                                                                                         + v22
                                                                                         + 36) << 16)) << 8)
                                                                          | ((HIWORD(*(_DWORD *)(v5[6].mVec128.m128_i32[3]
                                                                                               + v22
                                                                                               + 36))
                                                                            | (unsigned int)&s_ui_commands_allocator.m_buffer[1969824]
                                                                            & *(_DWORD *)(v5[6].mVec128.m128_i32[3]
                                                                                        + v22
                                                                                        + 36)) >> 8);
      v30 = *(_DWORD *)(v5[6].mVec128.m128_i32[3] + v22 + 40);
      o_alignedDataBuffer->m_contiguousNodes.m_data[v22 / 0x40].m_triangleIndex = ((v30 & 0xFF00 | (v30 << 16)) << 8)
                                                                                | ((HIWORD(v30)
                                                                                  | (unsigned int)&s_ui_commands_allocator.m_buffer[1969824]
                                                                                  & v30) >> 8);
      v22 += 64;
      --v45;
    }
    while ( v45 );
LABEL_35:
    v21 = v59;
  }
  v37 = (btAlignedObjectArray<btOptimizedBvhNode> *)(v21 << 6);
  buffera = (char *)buffer + (_DWORD)v37;
  btAlignedObjectArray<btOptimizedBvhNode>::initializeFromBuffer(
    v37,
    (int)&o_alignedDataBuffer->m_contiguousNodes,
    0,
    0,
    0);
LABEL_37:
  btAlignedObjectArray<btOptimizedBvhNode>::initializeFromBuffer(
    v20,
    (int)&o_alignedDataBuffer->m_SubtreeHeaders,
    buffera,
    v5[11].mVec128.m128_i32[1],
    v5[11].mVec128.m128_i32[1]);
  if ( i_swapEndian )
  {
    v39 = 0;
    for ( i = 0; (int)i < v5[11].mVec128.m128_i32[1]; v39 += 32 )
    {
      o_alignedDataBuffer->m_SubtreeHeaders.m_data[v39 / 0x20].m_quantizedAabbMin[0] = __ROL2__(
                                                                                         *(_WORD *)(v39
                                                                                                  + v5[10].mVec128.m128_i32[3]),
                                                                                         8);
      o_alignedDataBuffer->m_SubtreeHeaders.m_data[v39 / 0x20].m_quantizedAabbMin[1] = __ROL2__(
                                                                                         *(_WORD *)(v39
                                                                                                  + v5[10].mVec128.m128_i32[3]
                                                                                                  + 2),
                                                                                         8);
      o_alignedDataBuffer->m_SubtreeHeaders.m_data[v39 / 0x20].m_quantizedAabbMin[2] = __ROL2__(
                                                                                         *(_WORD *)(v39
                                                                                                  + v5[10].mVec128.m128_i32[3]
                                                                                                  + 4),
                                                                                         8);
      o_alignedDataBuffer->m_SubtreeHeaders.m_data[v39 / 0x20].m_quantizedAabbMax[0] = __ROL2__(
                                                                                         *(_WORD *)(v39
                                                                                                  + v5[10].mVec128.m128_i32[3]
                                                                                                  + 6),
                                                                                         8);
      o_alignedDataBuffer->m_SubtreeHeaders.m_data[v39 / 0x20].m_quantizedAabbMax[1] = __ROL2__(
                                                                                         *(_WORD *)(v39
                                                                                                  + v5[10].mVec128.m128_i32[3]
                                                                                                  + 8),
                                                                                         8);
      o_alignedDataBuffer->m_SubtreeHeaders.m_data[v39 / 0x20].m_quantizedAabbMax[2] = __ROL2__(
                                                                                         *(_WORD *)(v39
                                                                                                  + v5[10].mVec128.m128_i32[3]
                                                                                                  + 10),
                                                                                         8);
      o_alignedDataBuffer->m_SubtreeHeaders.m_data[v39 / 0x20].m_rootNodeIndex = ((*(_DWORD *)(v39
                                                                                             + v5[10].mVec128.m128_i32[3]
                                                                                             + 12)
                                                                                 & 0xFF00
                                                                                 | (*(_DWORD *)(v39
                                                                                              + v5[10].mVec128.m128_i32[3]
                                                                                              + 12) << 16)) << 8)
                                                                               | ((HIWORD(*(_DWORD *)(v39 + v5[10].mVec128.m128_i32[3] + 12))
                                                                                 | (unsigned int)&s_ui_commands_allocator.m_buffer[1969824]
                                                                                 & *(_DWORD *)(v39
                                                                                             + v5[10].mVec128.m128_i32[3]
                                                                                             + 12)) >> 8);
      v40 = *(_DWORD *)(v39 + v5[10].mVec128.m128_i32[3] + 16);
      i = (btAlignedObjectArray<btOptimizedBvhNode> *)((char *)i + 1);
      o_alignedDataBuffer->m_SubtreeHeaders.m_data[v39 / 0x20].m_subtreeSize = ((v40 & 0xFF00 | (v40 << 16)) << 8)
                                                                             | ((HIWORD(v40)
                                                                               | (unsigned int)&s_ui_commands_allocator.m_buffer[1969824]
                                                                               & v40) >> 8);
      v38 = i;
    }
  }
  else
  {
    v38 = 0;
    if ( v5[11].mVec128.m128_i32[1] > 0 )
    {
      v41 = 0;
      do
      {
        o_alignedDataBuffer->m_SubtreeHeaders.m_data[v41].m_quantizedAabbMin[0] = *(_WORD *)(v41 * 32
                                                                                           + v5[10].mVec128.m128_i32[3]);
        o_alignedDataBuffer->m_SubtreeHeaders.m_data[v41].m_quantizedAabbMin[1] = *(_WORD *)(v41 * 32
                                                                                           + v5[10].mVec128.m128_i32[3]
                                                                                           + 2);
        o_alignedDataBuffer->m_SubtreeHeaders.m_data[v41].m_quantizedAabbMin[2] = *(_WORD *)(v41 * 32
                                                                                           + v5[10].mVec128.m128_i32[3]
                                                                                           + 4);
        o_alignedDataBuffer->m_SubtreeHeaders.m_data[v41].m_quantizedAabbMax[0] = *(_WORD *)(v41 * 32
                                                                                           + v5[10].mVec128.m128_i32[3]
                                                                                           + 6);
        o_alignedDataBuffer->m_SubtreeHeaders.m_data[v41].m_quantizedAabbMax[1] = *(_WORD *)(v41 * 32
                                                                                           + v5[10].mVec128.m128_i32[3]
                                                                                           + 8);
        o_alignedDataBuffer->m_SubtreeHeaders.m_data[v41].m_quantizedAabbMax[2] = *(_WORD *)(v41 * 32
                                                                                           + v5[10].mVec128.m128_i32[3]
                                                                                           + 10);
        o_alignedDataBuffer->m_SubtreeHeaders.m_data[v41].m_rootNodeIndex = *(_DWORD *)(v41 * 32
                                                                                      + v5[10].mVec128.m128_i32[3]
                                                                                      + 12);
        o_alignedDataBuffer->m_SubtreeHeaders.m_data[v41].m_subtreeSize = *(_DWORD *)(v41 * 32
                                                                                    + v5[10].mVec128.m128_i32[3]
                                                                                    + 16);
        o_alignedDataBuffer->m_SubtreeHeaders.m_data[v41].m_padding[0] = 0;
        o_alignedDataBuffer->m_SubtreeHeaders.m_data[v41].m_padding[1] = 0;
        o_alignedDataBuffer->m_SubtreeHeaders.m_data[v41].m_padding[2] = 0;
        v38 = (btAlignedObjectArray<btOptimizedBvhNode> *)((char *)v38 + 1);
        ++v41;
      }
      while ( (int)v38 < v5[11].mVec128.m128_i32[1] );
    }
  }
  btAlignedObjectArray<btOptimizedBvhNode>::initializeFromBuffer(
    v38,
    (int)&o_alignedDataBuffer->m_SubtreeHeaders,
    0,
    0,
    0);
  o_alignedDataBuffer->__vftable = 0;
  return 1;
}
