void __thiscall btQuantizedBvh::deSerializeDouble(
        btQuantizedBvh *this,
        btQuantizedBvhDoubleData *quantizedBvhDoubleData)
{
  btVector3 *p_m_bvhAabbMax; // ecx
  btVector3DoubleData *v4; // eax
  int v5; // edi
  int v6; // ecx
  btVector3 *p_m_bvhAabbMin; // eax
  btVector3 *p_m_bvhQuantization; // ecx
  btVector3DoubleData *v9; // eax
  int v10; // edi
  int m_numContiguousLeafNodes; // edi
  int m_size; // esi
  int v13; // eax
  btOptimizedBvhNode *v14; // edx
  int v15; // eax
  char *v16; // edx
  btQuantizedBvhDoubleData *v17; // edx
  int m_numQuantizedContiguousNodes; // esi
  int v19; // edi
  int v20; // eax
  btQuantizedBvhNode *v21; // ecx
  int v22; // edx
  btQuantizedBvhNode *v23; // esi
  int v24; // eax
  int v25; // ecx
  btQuantizedBvhNode *v26; // edi
  unsigned __int16 *v27; // edi
  btQuantizedBvhNodeData *m_quantizedContiguousNodesPtr; // eax
  int v29; // ecx
  int m_numSubtreeHeaders; // edi
  int v31; // esi
  int v32; // eax
  btBvhSubtreeInfo *v33; // edx
  int v34; // eax
  btBvhSubtreeInfo *v35; // edx
  btBvhSubtreeInfoData *m_subTreeInfoPtr; // eax
  int v37; // ecx
  int v38; // [esp+10h] [ebp-50h]
  btBvhSubtreeInfo *v39; // [esp+10h] [ebp-50h]
  btOptimizedBvhNode *v40; // [esp+14h] [ebp-4Ch]
  int v41; // [esp+14h] [ebp-4Ch]
  btQuantizedBvhNode *v42; // [esp+14h] [ebp-4Ch]
  int v43; // [esp+14h] [ebp-4Ch]
  int v44; // [esp+14h] [ebp-4Ch]
  int v45; // [esp+18h] [ebp-48h]
  int v46; // [esp+18h] [ebp-48h]
  int v47; // [esp+18h] [ebp-48h]
  int v48; // [esp+18h] [ebp-48h]
  int v49; // [esp+1Ch] [ebp-44h]
  int v50; // [esp+1Ch] [ebp-44h]
  int v51; // [esp+1Ch] [ebp-44h]
  _DWORD v52[16]; // [esp+20h] [ebp-40h] BYREF

  p_m_bvhAabbMax = &this->m_bvhAabbMax;
  v4 = &quantizedBvhDoubleData->m_bvhAabbMax;
  v5 = 4;
  do
  {
    p_m_bvhAabbMax->mVec128.m128_f32[0] = v4->m_floats[0];
    v4 = (btVector3DoubleData *)((char *)v4 + 8);
    p_m_bvhAabbMax = (btVector3 *)((char *)p_m_bvhAabbMax + 4);
    --v5;
  }
  while ( v5 );
  v6 = 0;
  p_m_bvhAabbMin = &this->m_bvhAabbMin;
  do
  {
    p_m_bvhAabbMin->mVec128.m128_f32[0] = quantizedBvhDoubleData->m_bvhAabbMin.m_floats[v6++];
    p_m_bvhAabbMin = (btVector3 *)((char *)p_m_bvhAabbMin + 4);
  }
  while ( v6 < 4 );
  p_m_bvhQuantization = &this->m_bvhQuantization;
  v9 = &quantizedBvhDoubleData->m_bvhQuantization;
  v10 = 4;
  do
  {
    p_m_bvhQuantization->mVec128.m128_f32[0] = v9->m_floats[0];
    v9 = (btVector3DoubleData *)((char *)v9 + 8);
    p_m_bvhQuantization = (btVector3 *)((char *)p_m_bvhQuantization + 4);
    --v10;
  }
  while ( v10 );
  this->m_curNodeIndex = quantizedBvhDoubleData->m_curNodeIndex;
  this->m_useQuantization = quantizedBvhDoubleData->m_useQuantization != 0;
  m_numContiguousLeafNodes = quantizedBvhDoubleData->m_numContiguousLeafNodes;
  m_size = this->m_contiguousNodes.m_size;
  v45 = m_numContiguousLeafNodes;
  v49 = m_size;
  if ( m_numContiguousLeafNodes >= m_size )
  {
    if ( m_numContiguousLeafNodes > m_size && this->m_contiguousNodes.m_capacity < m_numContiguousLeafNodes )
    {
      if ( m_numContiguousLeafNodes )
        v40 = (btOptimizedBvhNode *)btAlignedAllocInternal(m_numContiguousLeafNodes << 6);
      else
        v40 = 0;
      v13 = this->m_contiguousNodes.m_size;
      if ( v13 > 0 )
      {
        v38 = 0;
        v14 = v40;
        do
        {
          if ( v14 )
          {
            qmemcpy(v14, &this->m_contiguousNodes.m_data[v38], sizeof(btOptimizedBvhNode));
            m_size = v49;
            m_numContiguousLeafNodes = v45;
          }
          ++v38;
          ++v14;
          --v13;
        }
        while ( v13 );
      }
      if ( this->m_contiguousNodes.m_data )
      {
        if ( this->m_contiguousNodes.m_ownsMemory )
          btAlignedFreeInternal(this->m_contiguousNodes.m_data);
        this->m_contiguousNodes.m_data = 0;
      }
      this->m_contiguousNodes.m_ownsMemory = 1;
      this->m_contiguousNodes.m_data = v40;
      this->m_contiguousNodes.m_capacity = m_numContiguousLeafNodes;
    }
    if ( m_size < m_numContiguousLeafNodes )
    {
      v15 = m_size << 6;
      v41 = m_numContiguousLeafNodes - m_size;
      do
      {
        v16 = (char *)this->m_contiguousNodes.m_data + v15;
        if ( v16 )
        {
          qmemcpy(v16, v52, 0x40u);
          m_numContiguousLeafNodes = v45;
        }
        v15 += 64;
        --v41;
      }
      while ( v41 );
    }
  }
  this->m_contiguousNodes.m_size = m_numContiguousLeafNodes;
  if ( m_numContiguousLeafNodes )
    JUMPOUT(0x96154);
  v17 = quantizedBvhDoubleData;
  m_numQuantizedContiguousNodes = quantizedBvhDoubleData->m_numQuantizedContiguousNodes;
  memset(v52, 0, 16);
  v19 = this->m_quantizedContiguousNodes.m_size;
  v46 = m_numQuantizedContiguousNodes;
  v50 = v19;
  if ( m_numQuantizedContiguousNodes >= v19 )
  {
    if ( m_numQuantizedContiguousNodes > v19
      && this->m_quantizedContiguousNodes.m_capacity < m_numQuantizedContiguousNodes )
    {
      if ( m_numQuantizedContiguousNodes )
        v42 = (btQuantizedBvhNode *)btAlignedAllocInternal(16 * m_numQuantizedContiguousNodes);
      else
        v42 = 0;
      v20 = this->m_quantizedContiguousNodes.m_size;
      if ( v20 > 0 )
      {
        v21 = v42;
        v22 = 0;
        do
        {
          if ( v21 )
          {
            v23 = &this->m_quantizedContiguousNodes.m_data[v22];
            *(_DWORD *)v21->m_quantizedAabbMin = *(_DWORD *)v23->m_quantizedAabbMin;
            v23 = (btQuantizedBvhNode *)((char *)v23 + 4);
            *(_DWORD *)&v21->m_quantizedAabbMin[2] = *(_DWORD *)v23->m_quantizedAabbMin;
            v23 = (btQuantizedBvhNode *)((char *)v23 + 4);
            *(_DWORD *)&v21->m_quantizedAabbMax[1] = *(_DWORD *)v23->m_quantizedAabbMin;
            v21->m_escapeIndexOrTriangleIndex = *(_DWORD *)&v23->m_quantizedAabbMin[2];
            v19 = v50;
            m_numQuantizedContiguousNodes = v46;
          }
          ++v22;
          ++v21;
          --v20;
        }
        while ( v20 );
      }
      if ( this->m_quantizedContiguousNodes.m_data )
      {
        if ( this->m_quantizedContiguousNodes.m_ownsMemory )
          btAlignedFreeInternal(this->m_quantizedContiguousNodes.m_data);
        this->m_quantizedContiguousNodes.m_data = 0;
      }
      v17 = quantizedBvhDoubleData;
      this->m_quantizedContiguousNodes.m_ownsMemory = 1;
      this->m_quantizedContiguousNodes.m_data = v42;
      this->m_quantizedContiguousNodes.m_capacity = m_numQuantizedContiguousNodes;
    }
    if ( v19 < m_numQuantizedContiguousNodes )
    {
      v24 = v19;
      v25 = m_numQuantizedContiguousNodes - v19;
      do
      {
        v26 = &this->m_quantizedContiguousNodes.m_data[v24];
        if ( v26 )
        {
          v17 = quantizedBvhDoubleData;
          *(_DWORD *)v26->m_quantizedAabbMin = v52[0];
          v27 = &v26->m_quantizedAabbMin[2];
          *(_DWORD *)v27 = v52[1];
          v27 += 2;
          *(_DWORD *)v27 = v52[2];
          *((_DWORD *)v27 + 1) = v52[3];
          m_numQuantizedContiguousNodes = v46;
        }
        ++v24;
        --v25;
      }
      while ( v25 );
    }
  }
  this->m_quantizedContiguousNodes.m_size = m_numQuantizedContiguousNodes;
  if ( m_numQuantizedContiguousNodes )
  {
    m_quantizedContiguousNodesPtr = v17->m_quantizedContiguousNodesPtr;
    if ( m_numQuantizedContiguousNodes > 0 )
    {
      v29 = 0;
      v47 = m_numQuantizedContiguousNodes;
      do
      {
        this->m_quantizedContiguousNodes.m_data[v29].m_escapeIndexOrTriangleIndex = m_quantizedContiguousNodesPtr->m_escapeIndexOrTriangleIndex;
        this->m_quantizedContiguousNodes.m_data[v29].m_quantizedAabbMax[0] = m_quantizedContiguousNodesPtr->m_quantizedAabbMax[0];
        this->m_quantizedContiguousNodes.m_data[v29].m_quantizedAabbMax[1] = m_quantizedContiguousNodesPtr->m_quantizedAabbMax[1];
        this->m_quantizedContiguousNodes.m_data[v29].m_quantizedAabbMax[2] = m_quantizedContiguousNodesPtr->m_quantizedAabbMax[2];
        this->m_quantizedContiguousNodes.m_data[v29].m_quantizedAabbMin[0] = m_quantizedContiguousNodesPtr->m_quantizedAabbMin[0];
        this->m_quantizedContiguousNodes.m_data[v29].m_quantizedAabbMin[1] = m_quantizedContiguousNodesPtr->m_quantizedAabbMin[1];
        this->m_quantizedContiguousNodes.m_data[v29++].m_quantizedAabbMin[2] = m_quantizedContiguousNodesPtr->m_quantizedAabbMin[2];
        ++m_quantizedContiguousNodesPtr;
        --v47;
      }
      while ( v47 );
    }
  }
  this->m_traversalMode = v17->m_traversalMode;
  m_numSubtreeHeaders = v17->m_numSubtreeHeaders;
  v31 = this->m_SubtreeHeaders.m_size;
  v48 = m_numSubtreeHeaders;
  v51 = v31;
  if ( m_numSubtreeHeaders >= v31 )
  {
    if ( m_numSubtreeHeaders > v31 && this->m_SubtreeHeaders.m_capacity < m_numSubtreeHeaders )
    {
      if ( m_numSubtreeHeaders )
        v39 = (btBvhSubtreeInfo *)btAlignedAllocInternal(32 * m_numSubtreeHeaders);
      else
        v39 = 0;
      v32 = this->m_SubtreeHeaders.m_size;
      if ( v32 > 0 )
      {
        v43 = 0;
        v33 = v39;
        do
        {
          if ( v33 )
          {
            qmemcpy(v33, &this->m_SubtreeHeaders.m_data[v43], sizeof(btBvhSubtreeInfo));
            v31 = v51;
            m_numSubtreeHeaders = v48;
          }
          ++v43;
          ++v33;
          --v32;
        }
        while ( v32 );
      }
      if ( this->m_SubtreeHeaders.m_data )
      {
        if ( this->m_SubtreeHeaders.m_ownsMemory )
          btAlignedFreeInternal(this->m_SubtreeHeaders.m_data);
        this->m_SubtreeHeaders.m_data = 0;
      }
      this->m_SubtreeHeaders.m_ownsMemory = 1;
      this->m_SubtreeHeaders.m_data = v39;
      this->m_SubtreeHeaders.m_capacity = m_numSubtreeHeaders;
    }
    if ( v31 < m_numSubtreeHeaders )
    {
      v34 = v31;
      v44 = m_numSubtreeHeaders - v31;
      do
      {
        v35 = &this->m_SubtreeHeaders.m_data[v34];
        if ( v35 )
        {
          qmemcpy(v35, v52, sizeof(btBvhSubtreeInfo));
          m_numSubtreeHeaders = v48;
        }
        ++v34;
        --v44;
      }
      while ( v44 );
    }
  }
  this->m_SubtreeHeaders.m_size = m_numSubtreeHeaders;
  if ( m_numSubtreeHeaders )
  {
    m_subTreeInfoPtr = quantizedBvhDoubleData->m_subTreeInfoPtr;
    if ( m_numSubtreeHeaders > 0 )
    {
      v37 = 0;
      do
      {
        this->m_SubtreeHeaders.m_data[v37].m_quantizedAabbMax[0] = m_subTreeInfoPtr->m_quantizedAabbMax[0];
        this->m_SubtreeHeaders.m_data[v37].m_quantizedAabbMax[1] = m_subTreeInfoPtr->m_quantizedAabbMax[1];
        this->m_SubtreeHeaders.m_data[v37].m_quantizedAabbMax[2] = m_subTreeInfoPtr->m_quantizedAabbMax[2];
        this->m_SubtreeHeaders.m_data[v37].m_quantizedAabbMin[0] = m_subTreeInfoPtr->m_quantizedAabbMin[0];
        this->m_SubtreeHeaders.m_data[v37].m_quantizedAabbMin[1] = m_subTreeInfoPtr->m_quantizedAabbMin[1];
        this->m_SubtreeHeaders.m_data[v37].m_quantizedAabbMin[2] = m_subTreeInfoPtr->m_quantizedAabbMin[2];
        this->m_SubtreeHeaders.m_data[v37].m_rootNodeIndex = m_subTreeInfoPtr->m_rootNodeIndex;
        this->m_SubtreeHeaders.m_data[v37++].m_subtreeSize = m_subTreeInfoPtr->m_subtreeSize;
        ++m_subTreeInfoPtr;
        --m_numSubtreeHeaders;
      }
      while ( m_numSubtreeHeaders );
    }
  }
}
