void __thiscall btQuantizedBvh::deSerializeFloat(btQuantizedBvh *this, btQuantizedBvhFloatData *quantizedBvhFloatData)
{
  btVector3 *p_m_bvhAabbMax; // ecx
  btVector3FloatData *v4; // eax
  int v5; // edi
  double v6; // st7
  int v7; // ecx
  btVector3 *p_m_bvhAabbMin; // eax
  double v9; // st7
  btVector3 *p_m_bvhQuantization; // ecx
  btVector3FloatData *v11; // eax
  int v12; // edi
  double v13; // st7
  int m_numContiguousLeafNodes; // edi
  int m_size; // esi
  int v16; // eax
  btOptimizedBvhNode *v17; // edx
  int v18; // eax
  char *v19; // edx
  btOptimizedBvhNodeFloatData *m_contiguousNodesPtr; // ecx
  int v21; // edx
  btVector3 *p_m_aabbMaxOrg; // esi
  int v23; // edi
  float *m_floats; // eax
  double v25; // st7
  btOptimizedBvhNode *v26; // eax
  int v27; // esi
  int v28; // edi
  btQuantizedBvhFloatData *v29; // edx
  int m_numQuantizedContiguousNodes; // esi
  int v31; // edi
  int v32; // eax
  btQuantizedBvhNode *v33; // ecx
  int v34; // edx
  btQuantizedBvhNode *v35; // esi
  int v36; // eax
  int v37; // ecx
  btQuantizedBvhNode *v38; // edi
  unsigned __int16 *v39; // edi
  btQuantizedBvhNodeData *m_quantizedContiguousNodesPtr; // eax
  int v41; // ecx
  int m_numSubtreeHeaders; // edi
  int v43; // esi
  int v44; // eax
  btBvhSubtreeInfo *v45; // edx
  int v46; // eax
  btBvhSubtreeInfo *v47; // edx
  btBvhSubtreeInfoData *m_subTreeInfoPtr; // eax
  int v49; // ecx
  int v50; // [esp+10h] [ebp-50h]
  btBvhSubtreeInfo *v51; // [esp+10h] [ebp-50h]
  btOptimizedBvhNode *v52; // [esp+14h] [ebp-4Ch]
  int v53; // [esp+14h] [ebp-4Ch]
  btQuantizedBvhNode *v54; // [esp+14h] [ebp-4Ch]
  int v55; // [esp+14h] [ebp-4Ch]
  int v56; // [esp+14h] [ebp-4Ch]
  int v57; // [esp+18h] [ebp-48h]
  int v58; // [esp+18h] [ebp-48h]
  int v59; // [esp+18h] [ebp-48h]
  int v60; // [esp+18h] [ebp-48h]
  int v61; // [esp+18h] [ebp-48h]
  int v62; // [esp+1Ch] [ebp-44h]
  int v63; // [esp+1Ch] [ebp-44h]
  int v64; // [esp+1Ch] [ebp-44h]
  _DWORD v65[16]; // [esp+20h] [ebp-40h] BYREF

  p_m_bvhAabbMax = &this->m_bvhAabbMax;
  v4 = &quantizedBvhFloatData->m_bvhAabbMax;
  v5 = 4;
  do
  {
    v6 = v4->m_floats[0];
    v4 = (btVector3FloatData *)((char *)v4 + 4);
    p_m_bvhAabbMax->mVec128.m128_f32[0] = v6;
    p_m_bvhAabbMax = (btVector3 *)((char *)p_m_bvhAabbMax + 4);
    --v5;
  }
  while ( v5 );
  v7 = 0;
  p_m_bvhAabbMin = &this->m_bvhAabbMin;
  do
  {
    v9 = quantizedBvhFloatData->m_bvhAabbMin.m_floats[v7++];
    p_m_bvhAabbMin->mVec128.m128_f32[0] = v9;
    p_m_bvhAabbMin = (btVector3 *)((char *)p_m_bvhAabbMin + 4);
  }
  while ( v7 < 4 );
  p_m_bvhQuantization = &this->m_bvhQuantization;
  v11 = &quantizedBvhFloatData->m_bvhQuantization;
  v12 = 4;
  do
  {
    v13 = v11->m_floats[0];
    v11 = (btVector3FloatData *)((char *)v11 + 4);
    p_m_bvhQuantization->mVec128.m128_f32[0] = v13;
    p_m_bvhQuantization = (btVector3 *)((char *)p_m_bvhQuantization + 4);
    --v12;
  }
  while ( v12 );
  this->m_curNodeIndex = quantizedBvhFloatData->m_curNodeIndex;
  this->m_useQuantization = quantizedBvhFloatData->m_useQuantization != 0;
  m_numContiguousLeafNodes = quantizedBvhFloatData->m_numContiguousLeafNodes;
  m_size = this->m_contiguousNodes.m_size;
  v57 = m_numContiguousLeafNodes;
  v62 = m_size;
  if ( m_numContiguousLeafNodes >= m_size )
  {
    if ( m_numContiguousLeafNodes > m_size && this->m_contiguousNodes.m_capacity < m_numContiguousLeafNodes )
    {
      if ( m_numContiguousLeafNodes )
        v52 = (btOptimizedBvhNode *)btAlignedAllocInternal(m_numContiguousLeafNodes << 6);
      else
        v52 = 0;
      v16 = this->m_contiguousNodes.m_size;
      if ( v16 > 0 )
      {
        v50 = 0;
        v17 = v52;
        do
        {
          if ( v17 )
          {
            qmemcpy(v17, &this->m_contiguousNodes.m_data[v50], sizeof(btOptimizedBvhNode));
            m_size = v62;
            m_numContiguousLeafNodes = v57;
          }
          ++v50;
          ++v17;
          --v16;
        }
        while ( v16 );
      }
      if ( this->m_contiguousNodes.m_data )
      {
        if ( this->m_contiguousNodes.m_ownsMemory )
          btAlignedFreeInternal(this->m_contiguousNodes.m_data);
        this->m_contiguousNodes.m_data = 0;
      }
      this->m_contiguousNodes.m_ownsMemory = 1;
      this->m_contiguousNodes.m_data = v52;
      this->m_contiguousNodes.m_capacity = m_numContiguousLeafNodes;
    }
    if ( m_size < m_numContiguousLeafNodes )
    {
      v18 = m_size << 6;
      v53 = m_numContiguousLeafNodes - m_size;
      do
      {
        v19 = (char *)this->m_contiguousNodes.m_data + v18;
        if ( v19 )
        {
          qmemcpy(v19, v65, 0x40u);
          m_numContiguousLeafNodes = v57;
        }
        v18 += 64;
        --v53;
      }
      while ( v53 );
    }
  }
  this->m_contiguousNodes.m_size = m_numContiguousLeafNodes;
  if ( m_numContiguousLeafNodes )
  {
    m_contiguousNodesPtr = quantizedBvhFloatData->m_contiguousNodesPtr;
    if ( m_numContiguousLeafNodes > 0 )
    {
      v21 = 0;
      v58 = m_numContiguousLeafNodes;
      do
      {
        p_m_aabbMaxOrg = &this->m_contiguousNodes.m_data[v21].m_aabbMaxOrg;
        v23 = 0;
        m_floats = m_contiguousNodesPtr->m_aabbMaxOrg.m_floats;
        do
        {
          v25 = *m_floats++;
          p_m_aabbMaxOrg->mVec128.m128_f32[v23++] = v25;
        }
        while ( v23 < 4 );
        v26 = &this->m_contiguousNodes.m_data[v21];
        v27 = (char *)m_contiguousNodesPtr - (char *)v26;
        v28 = 4;
        do
        {
          v26->m_aabbMinOrg.mVec128.m128_f32[0] = *(float *)((char *)v26->m_aabbMinOrg.mVec128.m128_f32 + v27);
          v26 = (btOptimizedBvhNode *)((char *)v26 + 4);
          --v28;
        }
        while ( v28 );
        this->m_contiguousNodes.m_data[v21].m_escapeIndex = m_contiguousNodesPtr->m_escapeIndex;
        this->m_contiguousNodes.m_data[v21].m_subPart = m_contiguousNodesPtr->m_subPart;
        this->m_contiguousNodes.m_data[v21++].m_triangleIndex = m_contiguousNodesPtr->m_triangleIndex;
        ++m_contiguousNodesPtr;
        --v58;
      }
      while ( v58 );
    }
  }
  v29 = quantizedBvhFloatData;
  m_numQuantizedContiguousNodes = quantizedBvhFloatData->m_numQuantizedContiguousNodes;
  memset(v65, 0, 16);
  v31 = this->m_quantizedContiguousNodes.m_size;
  v59 = m_numQuantizedContiguousNodes;
  v63 = v31;
  if ( m_numQuantizedContiguousNodes >= v31 )
  {
    if ( m_numQuantizedContiguousNodes > v31
      && this->m_quantizedContiguousNodes.m_capacity < m_numQuantizedContiguousNodes )
    {
      if ( m_numQuantizedContiguousNodes )
        v54 = (btQuantizedBvhNode *)btAlignedAllocInternal(16 * m_numQuantizedContiguousNodes);
      else
        v54 = 0;
      v32 = this->m_quantizedContiguousNodes.m_size;
      if ( v32 > 0 )
      {
        v33 = v54;
        v34 = 0;
        do
        {
          if ( v33 )
          {
            v35 = &this->m_quantizedContiguousNodes.m_data[v34];
            *(_DWORD *)v33->m_quantizedAabbMin = *(_DWORD *)v35->m_quantizedAabbMin;
            v35 = (btQuantizedBvhNode *)((char *)v35 + 4);
            *(_DWORD *)&v33->m_quantizedAabbMin[2] = *(_DWORD *)v35->m_quantizedAabbMin;
            v35 = (btQuantizedBvhNode *)((char *)v35 + 4);
            *(_DWORD *)&v33->m_quantizedAabbMax[1] = *(_DWORD *)v35->m_quantizedAabbMin;
            v33->m_escapeIndexOrTriangleIndex = *(_DWORD *)&v35->m_quantizedAabbMin[2];
            v31 = v63;
            m_numQuantizedContiguousNodes = v59;
          }
          ++v34;
          ++v33;
          --v32;
        }
        while ( v32 );
      }
      if ( this->m_quantizedContiguousNodes.m_data )
      {
        if ( this->m_quantizedContiguousNodes.m_ownsMemory )
          btAlignedFreeInternal(this->m_quantizedContiguousNodes.m_data);
        this->m_quantizedContiguousNodes.m_data = 0;
      }
      v29 = quantizedBvhFloatData;
      this->m_quantizedContiguousNodes.m_ownsMemory = 1;
      this->m_quantizedContiguousNodes.m_data = v54;
      this->m_quantizedContiguousNodes.m_capacity = m_numQuantizedContiguousNodes;
    }
    if ( v31 < m_numQuantizedContiguousNodes )
    {
      v36 = v31;
      v37 = m_numQuantizedContiguousNodes - v31;
      do
      {
        v38 = &this->m_quantizedContiguousNodes.m_data[v36];
        if ( v38 )
        {
          v29 = quantizedBvhFloatData;
          *(_DWORD *)v38->m_quantizedAabbMin = v65[0];
          v39 = &v38->m_quantizedAabbMin[2];
          *(_DWORD *)v39 = v65[1];
          v39 += 2;
          *(_DWORD *)v39 = v65[2];
          *((_DWORD *)v39 + 1) = v65[3];
          m_numQuantizedContiguousNodes = v59;
        }
        ++v36;
        --v37;
      }
      while ( v37 );
    }
  }
  this->m_quantizedContiguousNodes.m_size = m_numQuantizedContiguousNodes;
  if ( m_numQuantizedContiguousNodes )
  {
    m_quantizedContiguousNodesPtr = v29->m_quantizedContiguousNodesPtr;
    if ( m_numQuantizedContiguousNodes > 0 )
    {
      v41 = 0;
      v60 = m_numQuantizedContiguousNodes;
      do
      {
        this->m_quantizedContiguousNodes.m_data[v41].m_escapeIndexOrTriangleIndex = m_quantizedContiguousNodesPtr->m_escapeIndexOrTriangleIndex;
        this->m_quantizedContiguousNodes.m_data[v41].m_quantizedAabbMax[0] = m_quantizedContiguousNodesPtr->m_quantizedAabbMax[0];
        this->m_quantizedContiguousNodes.m_data[v41].m_quantizedAabbMax[1] = m_quantizedContiguousNodesPtr->m_quantizedAabbMax[1];
        this->m_quantizedContiguousNodes.m_data[v41].m_quantizedAabbMax[2] = m_quantizedContiguousNodesPtr->m_quantizedAabbMax[2];
        this->m_quantizedContiguousNodes.m_data[v41].m_quantizedAabbMin[0] = m_quantizedContiguousNodesPtr->m_quantizedAabbMin[0];
        this->m_quantizedContiguousNodes.m_data[v41].m_quantizedAabbMin[1] = m_quantizedContiguousNodesPtr->m_quantizedAabbMin[1];
        this->m_quantizedContiguousNodes.m_data[v41++].m_quantizedAabbMin[2] = m_quantizedContiguousNodesPtr->m_quantizedAabbMin[2];
        ++m_quantizedContiguousNodesPtr;
        --v60;
      }
      while ( v60 );
    }
  }
  this->m_traversalMode = v29->m_traversalMode;
  m_numSubtreeHeaders = v29->m_numSubtreeHeaders;
  v43 = this->m_SubtreeHeaders.m_size;
  v61 = m_numSubtreeHeaders;
  v64 = v43;
  if ( m_numSubtreeHeaders >= v43 )
  {
    if ( m_numSubtreeHeaders > v43 && this->m_SubtreeHeaders.m_capacity < m_numSubtreeHeaders )
    {
      if ( m_numSubtreeHeaders )
        v51 = (btBvhSubtreeInfo *)btAlignedAllocInternal(32 * m_numSubtreeHeaders);
      else
        v51 = 0;
      v44 = this->m_SubtreeHeaders.m_size;
      if ( v44 > 0 )
      {
        v55 = 0;
        v45 = v51;
        do
        {
          if ( v45 )
          {
            qmemcpy(v45, &this->m_SubtreeHeaders.m_data[v55], sizeof(btBvhSubtreeInfo));
            v43 = v64;
            m_numSubtreeHeaders = v61;
          }
          ++v55;
          ++v45;
          --v44;
        }
        while ( v44 );
      }
      if ( this->m_SubtreeHeaders.m_data )
      {
        if ( this->m_SubtreeHeaders.m_ownsMemory )
          btAlignedFreeInternal(this->m_SubtreeHeaders.m_data);
        this->m_SubtreeHeaders.m_data = 0;
      }
      this->m_SubtreeHeaders.m_ownsMemory = 1;
      this->m_SubtreeHeaders.m_data = v51;
      this->m_SubtreeHeaders.m_capacity = m_numSubtreeHeaders;
    }
    if ( v43 < m_numSubtreeHeaders )
    {
      v46 = v43;
      v56 = m_numSubtreeHeaders - v43;
      do
      {
        v47 = &this->m_SubtreeHeaders.m_data[v46];
        if ( v47 )
        {
          qmemcpy(v47, v65, sizeof(btBvhSubtreeInfo));
          m_numSubtreeHeaders = v61;
        }
        ++v46;
        --v56;
      }
      while ( v56 );
    }
  }
  this->m_SubtreeHeaders.m_size = m_numSubtreeHeaders;
  if ( m_numSubtreeHeaders )
  {
    m_subTreeInfoPtr = quantizedBvhFloatData->m_subTreeInfoPtr;
    if ( m_numSubtreeHeaders > 0 )
    {
      v49 = 0;
      do
      {
        this->m_SubtreeHeaders.m_data[v49].m_quantizedAabbMax[0] = m_subTreeInfoPtr->m_quantizedAabbMax[0];
        this->m_SubtreeHeaders.m_data[v49].m_quantizedAabbMax[1] = m_subTreeInfoPtr->m_quantizedAabbMax[1];
        this->m_SubtreeHeaders.m_data[v49].m_quantizedAabbMax[2] = m_subTreeInfoPtr->m_quantizedAabbMax[2];
        this->m_SubtreeHeaders.m_data[v49].m_quantizedAabbMin[0] = m_subTreeInfoPtr->m_quantizedAabbMin[0];
        this->m_SubtreeHeaders.m_data[v49].m_quantizedAabbMin[1] = m_subTreeInfoPtr->m_quantizedAabbMin[1];
        this->m_SubtreeHeaders.m_data[v49].m_quantizedAabbMin[2] = m_subTreeInfoPtr->m_quantizedAabbMin[2];
        this->m_SubtreeHeaders.m_data[v49].m_rootNodeIndex = m_subTreeInfoPtr->m_rootNodeIndex;
        this->m_SubtreeHeaders.m_data[v49++].m_subtreeSize = m_subTreeInfoPtr->m_subtreeSize;
        ++m_subTreeInfoPtr;
        --m_numSubtreeHeaders;
      }
      while ( m_numSubtreeHeaders );
    }
  }
}
