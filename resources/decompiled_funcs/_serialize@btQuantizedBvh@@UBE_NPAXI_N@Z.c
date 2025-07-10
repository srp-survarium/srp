char __thiscall btQuantizedBvh::serialize(
        btQuantizedBvh *this,
        unsigned __int8 *o_alignedDataBuffer,
        unsigned int __formal,
        bool i_swapEndian)
{
  int v6; // ebp
  int m_curNodeIndex; // ebx
  void *v8; // eax
  int v9; // eax
  unsigned int m_escapeIndexOrTriangleIndex; // ecx
  int v11; // eax
  int v12; // ecx
  void *v13; // eax
  void *v14; // eax
  int v15; // edx
  btOptimizedBvhNode *m_data; // ecx
  int v17; // eax
  char v18; // bl
  btOptimizedBvhNode *v19; // ecx
  _BYTE *v20; // eax
  btOptimizedBvhNode *v21; // ecx
  int v22; // eax
  char v23; // bl
  btVector3 *p_m_aabbMaxOrg; // ecx
  _BYTE *v25; // eax
  unsigned int m_escapeIndex; // eax
  unsigned int m_triangleIndex; // eax
  int v28; // eax
  int v29; // ebp
  btOptimizedBvhNode *v30; // eoff
  int v31; // edx
  btOptimizedBvhNode *v32; // ecx
  int v33; // edx
  void *v34; // eax
  void *v35; // eax
  int m_subtreeHeaderCount; // ebx
  int v37; // edx
  int v38; // eax
  unsigned int m_subtreeSize; // ecx
  int v40; // ecx
  unsigned int v41; // eax
  void *v42; // eax
  int nodeCount; // [esp+Ch] [ebp-4h]
  int nodeCounta; // [esp+Ch] [ebp-4h]
  unsigned __int8 *nodeData; // [esp+14h] [ebp+4h]
  unsigned __int8 *nodeDataa; // [esp+14h] [ebp+4h]

  v6 = 0;
  this->m_subtreeHeaderCount = this->m_SubtreeHeaders.m_size;
  if ( o_alignedDataBuffer )
    btQuantizedBvh::btQuantizedBvh(this, (btQuantizedBvh *)o_alignedDataBuffer);
  if ( i_swapEndian )
  {
    *((_DWORD *)o_alignedDataBuffer + 17) = ((this->m_curNodeIndex & 0xFF00 | (this->m_curNodeIndex << 16)) << 8)
                                          | ((HIWORD(this->m_curNodeIndex)
                                            | (unsigned int)&vostok::memory::s_CRT_arena[5508664] & this->m_curNodeIndex) >> 8);
    o_alignedDataBuffer[16] = this->m_bvhAabbMin.mVec128.m128_u8[3];
    o_alignedDataBuffer[17] = this->m_bvhAabbMin.mVec128.m128_u8[2];
    o_alignedDataBuffer[18] = this->m_bvhAabbMin.mVec128.m128_u8[1];
    o_alignedDataBuffer[19] = this->m_bvhAabbMin.mVec128.m128_u8[0];
    o_alignedDataBuffer[20] = this->m_bvhAabbMin.mVec128.m128_u8[7];
    o_alignedDataBuffer[21] = this->m_bvhAabbMin.mVec128.m128_u8[6];
    o_alignedDataBuffer[22] = this->m_bvhAabbMin.mVec128.m128_u8[5];
    o_alignedDataBuffer[23] = this->m_bvhAabbMin.mVec128.m128_u8[4];
    o_alignedDataBuffer[24] = this->m_bvhAabbMin.mVec128.m128_u8[11];
    o_alignedDataBuffer[25] = this->m_bvhAabbMin.mVec128.m128_u8[10];
    o_alignedDataBuffer[26] = this->m_bvhAabbMin.mVec128.m128_u8[9];
    o_alignedDataBuffer[27] = this->m_bvhAabbMin.mVec128.m128_u8[8];
    o_alignedDataBuffer[28] = this->m_bvhAabbMin.mVec128.m128_u8[15];
    o_alignedDataBuffer[29] = this->m_bvhAabbMin.mVec128.m128_u8[14];
    o_alignedDataBuffer[30] = this->m_bvhAabbMin.mVec128.m128_u8[13];
    o_alignedDataBuffer[31] = this->m_bvhAabbMin.mVec128.m128_u8[12];
    o_alignedDataBuffer[32] = this->m_bvhAabbMax.mVec128.m128_u8[3];
    o_alignedDataBuffer[33] = this->m_bvhAabbMax.mVec128.m128_u8[2];
    o_alignedDataBuffer[34] = this->m_bvhAabbMax.mVec128.m128_u8[1];
    o_alignedDataBuffer[35] = this->m_bvhAabbMax.mVec128.m128_u8[0];
    o_alignedDataBuffer[36] = this->m_bvhAabbMax.mVec128.m128_u8[7];
    o_alignedDataBuffer[37] = this->m_bvhAabbMax.mVec128.m128_u8[6];
    o_alignedDataBuffer[38] = this->m_bvhAabbMax.mVec128.m128_u8[5];
    o_alignedDataBuffer[39] = this->m_bvhAabbMax.mVec128.m128_u8[4];
    o_alignedDataBuffer[40] = this->m_bvhAabbMax.mVec128.m128_u8[11];
    o_alignedDataBuffer[41] = this->m_bvhAabbMax.mVec128.m128_u8[10];
    o_alignedDataBuffer[42] = this->m_bvhAabbMax.mVec128.m128_u8[9];
    o_alignedDataBuffer[43] = this->m_bvhAabbMax.mVec128.m128_u8[8];
    o_alignedDataBuffer[44] = this->m_bvhAabbMax.mVec128.m128_u8[15];
    o_alignedDataBuffer[45] = this->m_bvhAabbMax.mVec128.m128_u8[14];
    o_alignedDataBuffer[46] = this->m_bvhAabbMax.mVec128.m128_u8[13];
    o_alignedDataBuffer[47] = this->m_bvhAabbMax.mVec128.m128_u8[12];
    o_alignedDataBuffer[48] = this->m_bvhQuantization.mVec128.m128_u8[3];
    o_alignedDataBuffer[49] = this->m_bvhQuantization.mVec128.m128_u8[2];
    o_alignedDataBuffer[50] = this->m_bvhQuantization.mVec128.m128_u8[1];
    o_alignedDataBuffer[51] = this->m_bvhQuantization.mVec128.m128_u8[0];
    o_alignedDataBuffer[52] = this->m_bvhQuantization.mVec128.m128_u8[7];
    o_alignedDataBuffer[53] = this->m_bvhQuantization.mVec128.m128_u8[6];
    o_alignedDataBuffer[54] = this->m_bvhQuantization.mVec128.m128_u8[5];
    o_alignedDataBuffer[55] = this->m_bvhQuantization.mVec128.m128_u8[4];
    o_alignedDataBuffer[56] = this->m_bvhQuantization.mVec128.m128_u8[11];
    o_alignedDataBuffer[57] = this->m_bvhQuantization.mVec128.m128_u8[10];
    o_alignedDataBuffer[58] = this->m_bvhQuantization.mVec128.m128_u8[9];
    o_alignedDataBuffer[59] = this->m_bvhQuantization.mVec128.m128_u8[8];
    o_alignedDataBuffer[60] = this->m_bvhQuantization.mVec128.m128_u8[15];
    o_alignedDataBuffer[61] = this->m_bvhQuantization.mVec128.m128_u8[14];
    o_alignedDataBuffer[62] = this->m_bvhQuantization.mVec128.m128_u8[13];
    o_alignedDataBuffer[63] = this->m_bvhQuantization.mVec128.m128_u8[12];
    *((_DWORD *)o_alignedDataBuffer + 39) = ((this->m_traversalMode & 0xFF00 | (this->m_traversalMode << 16)) << 8)
                                          | ((((unsigned int)this->m_traversalMode >> 16)
                                            | (unsigned int)&vostok::memory::s_CRT_arena[5508664]
                                            & this->m_traversalMode) >> 8);
    *((_DWORD *)o_alignedDataBuffer + 45) = ((this->m_subtreeHeaderCount & 0xFF00 | (this->m_subtreeHeaderCount << 16)) << 8)
                                          | ((HIWORD(this->m_subtreeHeaderCount)
                                            | (unsigned int)&vostok::memory::s_CRT_arena[5508664]
                                            & this->m_subtreeHeaderCount) >> 8);
  }
  else
  {
    *((_DWORD *)o_alignedDataBuffer + 17) = this->m_curNodeIndex;
    *((_QWORD *)o_alignedDataBuffer + 2) = this->m_bvhAabbMin.mVec128.m128_u64[0];
    *((_QWORD *)o_alignedDataBuffer + 3) = this->m_bvhAabbMin.mVec128.m128_u64[1];
    *((_QWORD *)o_alignedDataBuffer + 4) = this->m_bvhAabbMax.mVec128.m128_u64[0];
    *((_QWORD *)o_alignedDataBuffer + 5) = this->m_bvhAabbMax.mVec128.m128_u64[1];
    *((_QWORD *)o_alignedDataBuffer + 6) = this->m_bvhQuantization.mVec128.m128_u64[0];
    *((_QWORD *)o_alignedDataBuffer + 7) = this->m_bvhQuantization.mVec128.m128_u64[1];
    *((_DWORD *)o_alignedDataBuffer + 39) = this->m_traversalMode;
    *((_DWORD *)o_alignedDataBuffer + 45) = this->m_subtreeHeaderCount;
  }
  o_alignedDataBuffer[72] = this->m_useQuantization;
  m_curNodeIndex = this->m_curNodeIndex;
  nodeData = o_alignedDataBuffer + 192;
  nodeCount = m_curNodeIndex;
  if ( this->m_useQuantization )
  {
    v8 = (void *)*((_DWORD *)o_alignedDataBuffer + 37);
    if ( v8 )
    {
      if ( o_alignedDataBuffer[152] )
      {
        ++gNumAlignedFree;
        sAlignedFreeFunc(v8);
      }
      *((_DWORD *)o_alignedDataBuffer + 37) = 0;
    }
    o_alignedDataBuffer[152] = 0;
    *((_DWORD *)o_alignedDataBuffer + 37) = nodeData;
    *((_DWORD *)o_alignedDataBuffer + 35) = m_curNodeIndex;
    *((_DWORD *)o_alignedDataBuffer + 36) = m_curNodeIndex;
    if ( i_swapEndian )
    {
      if ( m_curNodeIndex > 0 )
      {
        v9 = 0;
        nodeCounta = m_curNodeIndex;
        do
        {
          *(_WORD *)(v9 * 16 + *((_DWORD *)o_alignedDataBuffer + 37)) = __ROL2__(
                                                                          this->m_quantizedContiguousNodes.m_data[v9].m_quantizedAabbMin[0],
                                                                          8);
          *(_WORD *)(v9 * 16 + *((_DWORD *)o_alignedDataBuffer + 37) + 2) = __ROL2__(
                                                                              this->m_quantizedContiguousNodes.m_data[v9].m_quantizedAabbMin[1],
                                                                              8);
          *(_WORD *)(v9 * 16 + *((_DWORD *)o_alignedDataBuffer + 37) + 4) = __ROL2__(
                                                                              this->m_quantizedContiguousNodes.m_data[v9].m_quantizedAabbMin[2],
                                                                              8);
          *(_WORD *)(v9 * 16 + *((_DWORD *)o_alignedDataBuffer + 37) + 6) = __ROL2__(
                                                                              this->m_quantizedContiguousNodes.m_data[v9].m_quantizedAabbMax[0],
                                                                              8);
          *(_WORD *)(v9 * 16 + *((_DWORD *)o_alignedDataBuffer + 37) + 8) = __ROL2__(
                                                                              this->m_quantizedContiguousNodes.m_data[v9].m_quantizedAabbMax[1],
                                                                              8);
          *(_WORD *)(v9 * 16 + *((_DWORD *)o_alignedDataBuffer + 37) + 10) = __ROL2__(
                                                                               this->m_quantizedContiguousNodes.m_data[v9].m_quantizedAabbMax[2],
                                                                               8);
          m_escapeIndexOrTriangleIndex = this->m_quantizedContiguousNodes.m_data[v9].m_escapeIndexOrTriangleIndex;
          *(_DWORD *)(v9 * 16 + *((_DWORD *)o_alignedDataBuffer + 37) + 12) = ((m_escapeIndexOrTriangleIndex & 0xFF00
                                                                              | (m_escapeIndexOrTriangleIndex << 16)) << 8)
                                                                            | ((HIWORD(m_escapeIndexOrTriangleIndex)
                                                                              | (unsigned int)&vostok::memory::s_CRT_arena[5508664]
                                                                              & m_escapeIndexOrTriangleIndex) >> 8);
          ++v9;
          --nodeCounta;
        }
        while ( nodeCounta );
      }
    }
    else if ( m_curNodeIndex > 0 )
    {
      v11 = 0;
      v12 = m_curNodeIndex;
      do
      {
        *(_WORD *)(v11 * 16 + *((_DWORD *)o_alignedDataBuffer + 37)) = this->m_quantizedContiguousNodes.m_data[v11].m_quantizedAabbMin[0];
        *(_WORD *)(v11 * 16 + *((_DWORD *)o_alignedDataBuffer + 37) + 2) = this->m_quantizedContiguousNodes.m_data[v11].m_quantizedAabbMin[1];
        *(_WORD *)(v11 * 16 + *((_DWORD *)o_alignedDataBuffer + 37) + 4) = this->m_quantizedContiguousNodes.m_data[v11].m_quantizedAabbMin[2];
        *(_WORD *)(v11 * 16 + *((_DWORD *)o_alignedDataBuffer + 37) + 6) = this->m_quantizedContiguousNodes.m_data[v11].m_quantizedAabbMax[0];
        *(_WORD *)(v11 * 16 + *((_DWORD *)o_alignedDataBuffer + 37) + 8) = this->m_quantizedContiguousNodes.m_data[v11].m_quantizedAabbMax[1];
        *(_WORD *)(v11 * 16 + *((_DWORD *)o_alignedDataBuffer + 37) + 10) = this->m_quantizedContiguousNodes.m_data[v11].m_quantizedAabbMax[2];
        *(_DWORD *)(v11 * 16 + *((_DWORD *)o_alignedDataBuffer + 37) + 12) = this->m_quantizedContiguousNodes.m_data[v11].m_escapeIndexOrTriangleIndex;
        ++v11;
        --v12;
      }
      while ( v12 );
    }
    v13 = (void *)*((_DWORD *)o_alignedDataBuffer + 37);
    nodeDataa = &nodeData[16 * m_curNodeIndex];
    if ( v13 )
    {
      if ( o_alignedDataBuffer[152] )
      {
        ++gNumAlignedFree;
        sAlignedFreeFunc(v13);
      }
      *((_DWORD *)o_alignedDataBuffer + 37) = 0;
    }
    o_alignedDataBuffer[152] = 0;
    *((_DWORD *)o_alignedDataBuffer + 37) = 0;
    *((_DWORD *)o_alignedDataBuffer + 35) = 0;
    *((_DWORD *)o_alignedDataBuffer + 36) = 0;
  }
  else
  {
    v14 = (void *)*((_DWORD *)o_alignedDataBuffer + 27);
    if ( v14 )
    {
      if ( o_alignedDataBuffer[112] )
      {
        ++gNumAlignedFree;
        sAlignedFreeFunc(v14);
      }
      *((_DWORD *)o_alignedDataBuffer + 27) = 0;
    }
    o_alignedDataBuffer[112] = 0;
    *((_DWORD *)o_alignedDataBuffer + 27) = nodeData;
    *((_DWORD *)o_alignedDataBuffer + 25) = m_curNodeIndex;
    *((_DWORD *)o_alignedDataBuffer + 26) = m_curNodeIndex;
    if ( i_swapEndian )
    {
      if ( m_curNodeIndex > 0 )
      {
        v15 = m_curNodeIndex;
        do
        {
          m_data = this->m_contiguousNodes.m_data;
          v17 = *((_DWORD *)o_alignedDataBuffer + 27);
          *(_BYTE *)(v17 + v6 * 64) = m_data[v6].m_aabbMinOrg.mVec128.m128_i8[3];
          *(_BYTE *)(v17 + v6 * 64 + 1) = m_data[v6].m_aabbMinOrg.mVec128.m128_i8[2];
          *(_BYTE *)(v17 + v6 * 64 + 2) = m_data[v6].m_aabbMinOrg.mVec128.m128_i8[1];
          *(_BYTE *)(v17 + v6 * 64 + 3) = m_data[v6].m_aabbMinOrg.mVec128.m128_i8[0];
          *(_BYTE *)(v17 + v6 * 64 + 4) = m_data[v6].m_aabbMinOrg.mVec128.m128_i8[7];
          *(_BYTE *)(v17 + v6 * 64 + 5) = m_data[v6].m_aabbMinOrg.mVec128.m128_i8[6];
          v18 = m_data[v6].m_aabbMinOrg.mVec128.m128_i8[5];
          v19 = &m_data[v6];
          *(_BYTE *)(v17 + v6 * 64 + 6) = v18;
          v20 = (_BYTE *)(v6 * 64 + v17);
          v20[7] = v19->m_aabbMinOrg.mVec128.m128_i8[4];
          v20[8] = v19->m_aabbMinOrg.mVec128.m128_i8[11];
          v20[9] = v19->m_aabbMinOrg.mVec128.m128_i8[10];
          v20[10] = v19->m_aabbMinOrg.mVec128.m128_i8[9];
          v20[11] = v19->m_aabbMinOrg.mVec128.m128_i8[8];
          v20[12] = v19->m_aabbMinOrg.mVec128.m128_i8[15];
          v20[13] = v19->m_aabbMinOrg.mVec128.m128_i8[14];
          v20[14] = v19->m_aabbMinOrg.mVec128.m128_i8[13];
          v20[15] = v19->m_aabbMinOrg.mVec128.m128_i8[12];
          v21 = this->m_contiguousNodes.m_data;
          v22 = *((_DWORD *)o_alignedDataBuffer + 27);
          *(_BYTE *)(v22 + v6 * 64 + 16) = v21[v6].m_aabbMaxOrg.mVec128.m128_i8[3];
          v23 = v21[v6].m_aabbMaxOrg.mVec128.m128_i8[2];
          p_m_aabbMaxOrg = &v21[v6].m_aabbMaxOrg;
          *(_BYTE *)(v22 + v6 * 64 + 17) = v23;
          v25 = (_BYTE *)(v22 + v6 * 64 + 16);
          v25[2] = p_m_aabbMaxOrg->mVec128.m128_i8[1];
          v25[3] = p_m_aabbMaxOrg->mVec128.m128_i8[0];
          v25[4] = p_m_aabbMaxOrg->mVec128.m128_i8[7];
          v25[5] = p_m_aabbMaxOrg->mVec128.m128_i8[6];
          v25[6] = p_m_aabbMaxOrg->mVec128.m128_i8[5];
          v25[7] = p_m_aabbMaxOrg->mVec128.m128_i8[4];
          v25[8] = p_m_aabbMaxOrg->mVec128.m128_i8[11];
          v25[9] = p_m_aabbMaxOrg->mVec128.m128_i8[10];
          v25[10] = p_m_aabbMaxOrg->mVec128.m128_i8[9];
          v25[11] = p_m_aabbMaxOrg->mVec128.m128_i8[8];
          v25[12] = p_m_aabbMaxOrg->mVec128.m128_i8[15];
          v25[13] = p_m_aabbMaxOrg->mVec128.m128_i8[14];
          v25[14] = p_m_aabbMaxOrg->mVec128.m128_i8[13];
          v25[15] = p_m_aabbMaxOrg->mVec128.m128_i8[12];
          m_escapeIndex = this->m_contiguousNodes.m_data[v6].m_escapeIndex;
          *(_DWORD *)(*((_DWORD *)o_alignedDataBuffer + 27) + v6 * 64 + 32) = ((m_escapeIndex & 0xFF00
                                                                              | (m_escapeIndex << 16)) << 8)
                                                                            | ((HIWORD(m_escapeIndex)
                                                                              | (unsigned int)&vostok::memory::s_CRT_arena[5508664]
                                                                              & m_escapeIndex) >> 8);
          *(_DWORD *)(*((_DWORD *)o_alignedDataBuffer + 27) + v6 * 64 + 36) = ((this->m_contiguousNodes.m_data[v6].m_subPart
                                                                              & 0xFF00
                                                                              | (this->m_contiguousNodes.m_data[v6].m_subPart << 16)) << 8)
                                                                            | ((HIWORD(this->m_contiguousNodes.m_data[v6].m_subPart)
                                                                              | (unsigned int)&vostok::memory::s_CRT_arena[5508664]
                                                                              & this->m_contiguousNodes.m_data[v6].m_subPart) >> 8);
          m_triangleIndex = this->m_contiguousNodes.m_data[v6].m_triangleIndex;
          *(_DWORD *)(*((_DWORD *)o_alignedDataBuffer + 27) + v6 * 64 + 40) = ((m_triangleIndex & 0xFF00
                                                                              | (m_triangleIndex << 16)) << 8)
                                                                            | ((HIWORD(m_triangleIndex)
                                                                              | (unsigned int)&vostok::memory::s_CRT_arena[5508664]
                                                                              & m_triangleIndex) >> 8);
          ++v6;
          --v15;
        }
        while ( v15 );
        m_curNodeIndex = nodeCount;
      }
    }
    else if ( m_curNodeIndex > 0 )
    {
      v28 = 0;
      v29 = m_curNodeIndex;
      do
      {
        v30 = &this->m_contiguousNodes.m_data[v28];
        v31 = *((_DWORD *)o_alignedDataBuffer + 27);
        *(_QWORD *)(v31 + v28 * 64) = v30->m_aabbMinOrg.mVec128.m128_u64[0];
        *(_QWORD *)(v31 + v28 * 64 + 8) = v30->m_aabbMinOrg.mVec128.m128_u64[1];
        v32 = this->m_contiguousNodes.m_data;
        v33 = *((_DWORD *)o_alignedDataBuffer + 27);
        *(_QWORD *)(v33 + v28 * 64 + 16) = v32[v28].m_aabbMaxOrg.mVec128.m128_u64[0];
        *(_QWORD *)(v33 + v28 * 64 + 24) = v32[v28].m_aabbMaxOrg.mVec128.m128_u64[1];
        *(_DWORD *)(*((_DWORD *)o_alignedDataBuffer + 27) + v28 * 64 + 32) = this->m_contiguousNodes.m_data[v28].m_escapeIndex;
        *(_DWORD *)(*((_DWORD *)o_alignedDataBuffer + 27) + v28 * 64 + 36) = this->m_contiguousNodes.m_data[v28].m_subPart;
        *(_DWORD *)(*((_DWORD *)o_alignedDataBuffer + 27) + v28 * 64 + 40) = this->m_contiguousNodes.m_data[v28].m_triangleIndex;
        ++v28;
        --v29;
      }
      while ( v29 );
    }
    v34 = (void *)*((_DWORD *)o_alignedDataBuffer + 27);
    nodeDataa = &nodeData[64 * m_curNodeIndex];
    if ( v34 )
    {
      if ( o_alignedDataBuffer[112] )
      {
        ++gNumAlignedFree;
        sAlignedFreeFunc(v34);
      }
      *((_DWORD *)o_alignedDataBuffer + 27) = 0;
    }
    o_alignedDataBuffer[112] = 0;
    *((_DWORD *)o_alignedDataBuffer + 27) = 0;
    *((_DWORD *)o_alignedDataBuffer + 25) = 0;
    *((_DWORD *)o_alignedDataBuffer + 26) = 0;
  }
  v35 = (void *)*((_DWORD *)o_alignedDataBuffer + 43);
  m_subtreeHeaderCount = this->m_subtreeHeaderCount;
  if ( v35 )
  {
    if ( o_alignedDataBuffer[176] )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v35);
    }
    *((_DWORD *)o_alignedDataBuffer + 43) = 0;
  }
  o_alignedDataBuffer[176] = 0;
  *((_DWORD *)o_alignedDataBuffer + 43) = nodeDataa;
  *((_DWORD *)o_alignedDataBuffer + 41) = m_subtreeHeaderCount;
  *((_DWORD *)o_alignedDataBuffer + 42) = m_subtreeHeaderCount;
  if ( i_swapEndian )
  {
    v37 = 0;
    if ( this->m_subtreeHeaderCount > 0 )
    {
      v38 = 0;
      do
      {
        *(_WORD *)(v38 * 32 + *((_DWORD *)o_alignedDataBuffer + 43)) = __ROL2__(
                                                                         this->m_SubtreeHeaders.m_data[v38].m_quantizedAabbMin[0],
                                                                         8);
        *(_WORD *)(v38 * 32 + *((_DWORD *)o_alignedDataBuffer + 43) + 2) = __ROL2__(
                                                                             this->m_SubtreeHeaders.m_data[v38].m_quantizedAabbMin[1],
                                                                             8);
        *(_WORD *)(v38 * 32 + *((_DWORD *)o_alignedDataBuffer + 43) + 4) = __ROL2__(
                                                                             this->m_SubtreeHeaders.m_data[v38].m_quantizedAabbMin[2],
                                                                             8);
        *(_WORD *)(v38 * 32 + *((_DWORD *)o_alignedDataBuffer + 43) + 6) = __ROL2__(
                                                                             this->m_SubtreeHeaders.m_data[v38].m_quantizedAabbMax[0],
                                                                             8);
        *(_WORD *)(v38 * 32 + *((_DWORD *)o_alignedDataBuffer + 43) + 8) = __ROL2__(
                                                                             this->m_SubtreeHeaders.m_data[v38].m_quantizedAabbMax[1],
                                                                             8);
        *(_WORD *)(v38 * 32 + *((_DWORD *)o_alignedDataBuffer + 43) + 10) = __ROL2__(
                                                                              this->m_SubtreeHeaders.m_data[v38].m_quantizedAabbMax[2],
                                                                              8);
        *(_DWORD *)(v38 * 32 + *((_DWORD *)o_alignedDataBuffer + 43) + 12) = ((this->m_SubtreeHeaders.m_data[v38].m_rootNodeIndex
                                                                             & 0xFF00
                                                                             | (this->m_SubtreeHeaders.m_data[v38].m_rootNodeIndex << 16)) << 8)
                                                                           | ((HIWORD(this->m_SubtreeHeaders.m_data[v38].m_rootNodeIndex)
                                                                             | (unsigned int)&vostok::memory::s_CRT_arena[5508664]
                                                                             & this->m_SubtreeHeaders.m_data[v38].m_rootNodeIndex) >> 8);
        m_subtreeSize = this->m_SubtreeHeaders.m_data[v38].m_subtreeSize;
        *(_DWORD *)(v38 * 32 + *((_DWORD *)o_alignedDataBuffer + 43) + 16) = ((m_subtreeSize & 0xFF00
                                                                             | (m_subtreeSize << 16)) << 8)
                                                                           | ((HIWORD(m_subtreeSize)
                                                                             | (unsigned int)&vostok::memory::s_CRT_arena[5508664]
                                                                             & m_subtreeSize) >> 8);
        ++v37;
        ++v38;
      }
      while ( v37 < this->m_subtreeHeaderCount );
    }
  }
  else
  {
    v40 = 0;
    if ( this->m_subtreeHeaderCount > 0 )
    {
      v41 = 0;
      do
      {
        *(_WORD *)(v41 + *((_DWORD *)o_alignedDataBuffer + 43)) = this->m_SubtreeHeaders.m_data[v41 / 0x20].m_quantizedAabbMin[0];
        *(_WORD *)(v41 + *((_DWORD *)o_alignedDataBuffer + 43) + 2) = this->m_SubtreeHeaders.m_data[v41 / 0x20].m_quantizedAabbMin[1];
        *(_WORD *)(v41 + *((_DWORD *)o_alignedDataBuffer + 43) + 4) = this->m_SubtreeHeaders.m_data[v41 / 0x20].m_quantizedAabbMin[2];
        *(_WORD *)(v41 + *((_DWORD *)o_alignedDataBuffer + 43) + 6) = this->m_SubtreeHeaders.m_data[v41 / 0x20].m_quantizedAabbMax[0];
        *(_WORD *)(v41 + *((_DWORD *)o_alignedDataBuffer + 43) + 8) = this->m_SubtreeHeaders.m_data[v41 / 0x20].m_quantizedAabbMax[1];
        *(_WORD *)(v41 + *((_DWORD *)o_alignedDataBuffer + 43) + 10) = this->m_SubtreeHeaders.m_data[v41 / 0x20].m_quantizedAabbMax[2];
        *(_DWORD *)(v41 + *((_DWORD *)o_alignedDataBuffer + 43) + 12) = this->m_SubtreeHeaders.m_data[v41 / 0x20].m_rootNodeIndex;
        *(_DWORD *)(v41 + *((_DWORD *)o_alignedDataBuffer + 43) + 16) = this->m_SubtreeHeaders.m_data[v41 / 0x20].m_subtreeSize;
        *(_DWORD *)(v41 + *((_DWORD *)o_alignedDataBuffer + 43) + 20) = 0;
        *(_DWORD *)(v41 + *((_DWORD *)o_alignedDataBuffer + 43) + 24) = 0;
        *(_DWORD *)(v41 + *((_DWORD *)o_alignedDataBuffer + 43) + 28) = 0;
        ++v40;
        v41 += 32;
      }
      while ( v40 < this->m_subtreeHeaderCount );
    }
  }
  v42 = (void *)*((_DWORD *)o_alignedDataBuffer + 43);
  if ( v42 )
  {
    if ( o_alignedDataBuffer[176] )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v42);
    }
    *((_DWORD *)o_alignedDataBuffer + 43) = 0;
  }
  *((_DWORD *)o_alignedDataBuffer + 43) = 0;
  *((_DWORD *)o_alignedDataBuffer + 41) = 0;
  *((_DWORD *)o_alignedDataBuffer + 42) = 0;
  o_alignedDataBuffer[176] = 0;
  *(_DWORD *)o_alignedDataBuffer = 0;
  return 1;
}
