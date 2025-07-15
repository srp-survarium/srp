void __thiscall btQuantizedBvh::deSerializeFloat(btQuantizedBvh *this, btQuantizedBvhFloatData *quantizedBvhFloatData)
{
  btQuantizedBvhFloatData *v3; // edi
  int m_numContiguousLeafNodes; // esi
  int m_size; // ecx
  btOptimizedBvhNode *v6; // eax
  int v7; // edx
  btOptimizedBvhNode *m_data; // eax
  int v9; // eax
  int v10; // edx
  char *v11; // edi
  btOptimizedBvhNodeFloatData *m_contiguousNodesPtr; // eax
  int v13; // edx
  int v14; // edi
  btOptimizedBvhNode *v15; // ecx
  float *m128_f32; // ecx
  double v17; // st7
  btOptimizedBvhNode *v18; // ecx
  int v19; // ecx
  int m_numQuantizedContiguousNodes; // esi
  btQuantizedBvhNode *v21; // eax
  btQuantizedBvhNode *v22; // ecx
  int v23; // edx
  int v24; // edi
  btQuantizedBvhNode *v25; // eax
  btQuantizedBvhNode *v26; // eax
  __int64 v27; // xmm0_8
  int v28; // eax
  int v29; // edx
  btQuantizedBvhNode *v30; // ecx
  btQuantizedBvhNodeData *m_quantizedContiguousNodesPtr; // ecx
  int v32; // eax
  int v33; // edx
  int v34; // eax
  int m_numSubtreeHeaders; // esi
  btBvhSubtreeInfo *v36; // ecx
  int v37; // edx
  int v38; // edi
  btBvhSubtreeInfo *v39; // eax
  __int64 v40; // xmm0_8
  btBvhSubtreeInfo *v41; // eax
  btBvhSubtreeInfo *v42; // eax
  __int64 v43; // xmm0_8
  __int64 v44; // xmm1_8
  __int64 v45; // xmm2_8
  __int64 v46; // xmm3_8
  int v47; // ecx
  int v48; // edx
  btBvhSubtreeInfo *v49; // eax
  btBvhSubtreeInfoData *m_subTreeInfoPtr; // ecx
  int v51; // eax
  int v52; // edx
  btOptimizedBvhNode *v53; // [esp+58h] [ebp-50h]
  int v54; // [esp+58h] [ebp-50h]
  int v55; // [esp+5Ch] [ebp-4Ch]
  btQuantizedBvhNode *v56; // [esp+5Ch] [ebp-4Ch]
  btBvhSubtreeInfo *v57; // [esp+5Ch] [ebp-4Ch]
  int v58; // [esp+60h] [ebp-48h]
  int v59; // [esp+64h] [ebp-44h]
  int v60; // [esp+64h] [ebp-44h]
  _OWORD v61[4]; // [esp+68h] [ebp-40h] BYREF

  v3 = quantizedBvhFloatData;
  this->m_bvhAabbMax = (btVector3)quantizedBvhFloatData->m_bvhAabbMax;
  this->m_bvhAabbMin = (btVector3)quantizedBvhFloatData->m_bvhAabbMin;
  this->m_bvhQuantization = (btVector3)quantizedBvhFloatData->m_bvhQuantization;
  this->m_curNodeIndex = quantizedBvhFloatData->m_curNodeIndex;
  this->m_useQuantization = quantizedBvhFloatData->m_useQuantization != 0;
  m_numContiguousLeafNodes = quantizedBvhFloatData->m_numContiguousLeafNodes;
  m_size = this->m_contiguousNodes.m_size;
  v58 = m_numContiguousLeafNodes;
  v59 = m_size;
  if ( m_numContiguousLeafNodes >= m_size )
  {
    if ( m_numContiguousLeafNodes > m_size && this->m_contiguousNodes.m_capacity < m_numContiguousLeafNodes )
    {
      if ( m_numContiguousLeafNodes )
      {
        ++gNumAlignedAllocs;
        v53 = (btOptimizedBvhNode *)sAlignedAllocFunc(m_numContiguousLeafNodes << 6, 16);
      }
      else
      {
        v53 = 0;
      }
      if ( this->m_contiguousNodes.m_size > 0 )
      {
        v6 = v53;
        v7 = 0;
        v55 = this->m_contiguousNodes.m_size;
        do
        {
          if ( v6 )
          {
            qmemcpy(v6, &this->m_contiguousNodes.m_data[v7], sizeof(btOptimizedBvhNode));
            m_numContiguousLeafNodes = v58;
            v3 = quantizedBvhFloatData;
          }
          ++v7;
          ++v6;
          --v55;
        }
        while ( v55 );
      }
      m_data = this->m_contiguousNodes.m_data;
      if ( m_data )
      {
        if ( this->m_contiguousNodes.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(m_data);
        }
        this->m_contiguousNodes.m_data = 0;
      }
      m_size = v59;
      this->m_contiguousNodes.m_ownsMemory = 1;
      this->m_contiguousNodes.m_data = v53;
      this->m_contiguousNodes.m_capacity = m_numContiguousLeafNodes;
    }
    if ( m_size < m_numContiguousLeafNodes )
    {
      v9 = m_size << 6;
      v10 = m_numContiguousLeafNodes - m_size;
      do
      {
        v11 = (char *)this->m_contiguousNodes.m_data + v9;
        if ( v11 )
        {
          qmemcpy(v11, v61, 0x40u);
          m_numContiguousLeafNodes = v58;
        }
        v9 += 64;
        --v10;
      }
      while ( v10 );
      v3 = quantizedBvhFloatData;
    }
  }
  this->m_contiguousNodes.m_size = m_numContiguousLeafNodes;
  if ( m_numContiguousLeafNodes )
  {
    m_contiguousNodesPtr = v3->m_contiguousNodesPtr;
    if ( m_numContiguousLeafNodes > 0 )
    {
      v13 = 0;
      v14 = m_numContiguousLeafNodes;
      do
      {
        v15 = this->m_contiguousNodes.m_data;
        v15[v13].m_aabbMaxOrg.mVec128.m128_f32[0] = m_contiguousNodesPtr->m_aabbMaxOrg.m_floats[0];
        m128_f32 = v15[v13].m_aabbMaxOrg.mVec128.m128_f32;
        v17 = m_contiguousNodesPtr->m_aabbMaxOrg.m_floats[1];
        ++m_contiguousNodesPtr;
        m128_f32[1] = v17;
        m128_f32[2] = m_contiguousNodesPtr[-1].m_aabbMaxOrg.m_floats[2];
        m128_f32[3] = m_contiguousNodesPtr[-1].m_aabbMaxOrg.m_floats[3];
        v18 = &this->m_contiguousNodes.m_data[v13];
        v18->m_aabbMinOrg.mVec128.m128_f32[0] = m_contiguousNodesPtr[-1].m_aabbMinOrg.m_floats[0];
        ++v13;
        --v14;
        v18->m_aabbMinOrg.mVec128.m128_f32[1] = m_contiguousNodesPtr[-1].m_aabbMinOrg.m_floats[1];
        v18->m_aabbMinOrg.mVec128.m128_f32[2] = m_contiguousNodesPtr[-1].m_aabbMinOrg.m_floats[2];
        v18->m_aabbMinOrg.mVec128.m128_f32[3] = m_contiguousNodesPtr[-1].m_aabbMinOrg.m_floats[3];
        this->m_contiguousNodes.m_data[v13 - 1].m_escapeIndex = m_contiguousNodesPtr[-1].m_escapeIndex;
        this->m_contiguousNodes.m_data[v13 - 1].m_subPart = m_contiguousNodesPtr[-1].m_subPart;
        this->m_contiguousNodes.m_data[v13 - 1].m_triangleIndex = m_contiguousNodesPtr[-1].m_triangleIndex;
      }
      while ( v14 );
      v3 = quantizedBvhFloatData;
    }
  }
  v19 = this->m_quantizedContiguousNodes.m_size;
  m_numQuantizedContiguousNodes = v3->m_numQuantizedContiguousNodes;
  v61[0] = 0;
  v54 = v19;
  if ( m_numQuantizedContiguousNodes >= v19 )
  {
    if ( m_numQuantizedContiguousNodes > v19
      && this->m_quantizedContiguousNodes.m_capacity < m_numQuantizedContiguousNodes )
    {
      if ( m_numQuantizedContiguousNodes )
      {
        ++gNumAlignedAllocs;
        v21 = (btQuantizedBvhNode *)sAlignedAllocFunc(16 * m_numQuantizedContiguousNodes, 16);
        v19 = v54;
        v56 = v21;
      }
      else
      {
        v56 = 0;
      }
      if ( this->m_quantizedContiguousNodes.m_size > 0 )
      {
        v22 = v56;
        v23 = 0;
        v24 = this->m_quantizedContiguousNodes.m_size;
        do
        {
          if ( v22 )
          {
            v25 = this->m_quantizedContiguousNodes.m_data;
            *(_QWORD *)v22->m_quantizedAabbMin = *(_QWORD *)v25[v23].m_quantizedAabbMin;
            *(_QWORD *)&v22->m_quantizedAabbMax[1] = *(_QWORD *)&v25[v23].m_quantizedAabbMax[1];
          }
          ++v23;
          ++v22;
          --v24;
        }
        while ( v24 );
        v3 = quantizedBvhFloatData;
        v19 = v54;
      }
      v26 = this->m_quantizedContiguousNodes.m_data;
      if ( v26 )
      {
        if ( this->m_quantizedContiguousNodes.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v26);
          v19 = v54;
        }
        this->m_quantizedContiguousNodes.m_data = 0;
      }
      this->m_quantizedContiguousNodes.m_ownsMemory = 1;
      this->m_quantizedContiguousNodes.m_data = v56;
      this->m_quantizedContiguousNodes.m_capacity = m_numQuantizedContiguousNodes;
    }
    if ( v19 < m_numQuantizedContiguousNodes )
    {
      v27 = *((_QWORD *)&v61[0] + 1);
      v28 = v19;
      v29 = m_numQuantizedContiguousNodes - v19;
      do
      {
        v30 = &this->m_quantizedContiguousNodes.m_data[v28];
        if ( v30 )
        {
          *(_QWORD *)v30->m_quantizedAabbMin = *(_QWORD *)&v61[0];
          *(_QWORD *)&v30->m_quantizedAabbMax[1] = v27;
        }
        ++v28;
        --v29;
      }
      while ( v29 );
    }
  }
  this->m_quantizedContiguousNodes.m_size = m_numQuantizedContiguousNodes;
  if ( m_numQuantizedContiguousNodes )
  {
    m_quantizedContiguousNodesPtr = v3->m_quantizedContiguousNodesPtr;
    if ( m_numQuantizedContiguousNodes > 0 )
    {
      v32 = 0;
      v33 = m_numQuantizedContiguousNodes;
      do
      {
        this->m_quantizedContiguousNodes.m_data[v32].m_escapeIndexOrTriangleIndex = m_quantizedContiguousNodesPtr->m_escapeIndexOrTriangleIndex;
        this->m_quantizedContiguousNodes.m_data[v32].m_quantizedAabbMax[0] = m_quantizedContiguousNodesPtr->m_quantizedAabbMax[0];
        this->m_quantizedContiguousNodes.m_data[v32].m_quantizedAabbMax[1] = m_quantizedContiguousNodesPtr->m_quantizedAabbMax[1];
        this->m_quantizedContiguousNodes.m_data[v32].m_quantizedAabbMax[2] = m_quantizedContiguousNodesPtr->m_quantizedAabbMax[2];
        this->m_quantizedContiguousNodes.m_data[v32].m_quantizedAabbMin[0] = m_quantizedContiguousNodesPtr->m_quantizedAabbMin[0];
        this->m_quantizedContiguousNodes.m_data[v32].m_quantizedAabbMin[1] = m_quantizedContiguousNodesPtr->m_quantizedAabbMin[1];
        this->m_quantizedContiguousNodes.m_data[v32++].m_quantizedAabbMin[2] = m_quantizedContiguousNodesPtr->m_quantizedAabbMin[2];
        ++m_quantizedContiguousNodesPtr;
        --v33;
      }
      while ( v33 );
      v3 = quantizedBvhFloatData;
    }
  }
  this->m_traversalMode = v3->m_traversalMode;
  v34 = this->m_SubtreeHeaders.m_size;
  m_numSubtreeHeaders = v3->m_numSubtreeHeaders;
  v60 = v34;
  if ( m_numSubtreeHeaders >= v34 )
  {
    if ( m_numSubtreeHeaders > v34 && this->m_SubtreeHeaders.m_capacity < m_numSubtreeHeaders )
    {
      if ( m_numSubtreeHeaders )
      {
        ++gNumAlignedAllocs;
        v57 = (btBvhSubtreeInfo *)sAlignedAllocFunc(32 * m_numSubtreeHeaders, 16);
      }
      else
      {
        v57 = 0;
      }
      if ( this->m_SubtreeHeaders.m_size > 0 )
      {
        v36 = v57;
        v37 = 0;
        v38 = this->m_SubtreeHeaders.m_size;
        do
        {
          if ( v36 )
          {
            v39 = this->m_SubtreeHeaders.m_data;
            v40 = *(_QWORD *)v39[v37].m_quantizedAabbMin;
            v41 = &v39[v37];
            *(_QWORD *)v36->m_quantizedAabbMin = v40;
            *(_QWORD *)&v36->m_quantizedAabbMax[1] = *(_QWORD *)&v41->m_quantizedAabbMax[1];
            *(_QWORD *)&v36->m_subtreeSize = *(_QWORD *)&v41->m_subtreeSize;
            *(_QWORD *)&v36->m_padding[1] = *(_QWORD *)&v41->m_padding[1];
          }
          ++v37;
          ++v36;
          --v38;
        }
        while ( v38 );
        v3 = quantizedBvhFloatData;
      }
      v42 = this->m_SubtreeHeaders.m_data;
      if ( v42 )
      {
        if ( this->m_SubtreeHeaders.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v42);
        }
        this->m_SubtreeHeaders.m_data = 0;
      }
      this->m_SubtreeHeaders.m_data = v57;
      v34 = v60;
      this->m_SubtreeHeaders.m_ownsMemory = 1;
      this->m_SubtreeHeaders.m_capacity = m_numSubtreeHeaders;
    }
    if ( v34 < m_numSubtreeHeaders )
    {
      v43 = *((_QWORD *)&v61[1] + 1);
      v44 = *(_QWORD *)&v61[1];
      v45 = *((_QWORD *)&v61[0] + 1);
      v46 = *(_QWORD *)&v61[0];
      v47 = v34;
      v48 = m_numSubtreeHeaders - v34;
      do
      {
        v49 = &this->m_SubtreeHeaders.m_data[v47];
        if ( v49 )
        {
          *(_QWORD *)v49->m_quantizedAabbMin = v46;
          *(_QWORD *)&v49->m_quantizedAabbMax[1] = v45;
          *(_QWORD *)&v49->m_subtreeSize = v44;
          *(_QWORD *)&v49->m_padding[1] = v43;
        }
        ++v47;
        --v48;
      }
      while ( v48 );
    }
  }
  this->m_SubtreeHeaders.m_size = m_numSubtreeHeaders;
  if ( m_numSubtreeHeaders )
  {
    m_subTreeInfoPtr = v3->m_subTreeInfoPtr;
    if ( m_numSubtreeHeaders > 0 )
    {
      v51 = 0;
      v52 = m_numSubtreeHeaders;
      do
      {
        this->m_SubtreeHeaders.m_data[v51].m_quantizedAabbMax[0] = m_subTreeInfoPtr->m_quantizedAabbMax[0];
        this->m_SubtreeHeaders.m_data[v51].m_quantizedAabbMax[1] = m_subTreeInfoPtr->m_quantizedAabbMax[1];
        this->m_SubtreeHeaders.m_data[v51].m_quantizedAabbMax[2] = m_subTreeInfoPtr->m_quantizedAabbMax[2];
        this->m_SubtreeHeaders.m_data[v51].m_quantizedAabbMin[0] = m_subTreeInfoPtr->m_quantizedAabbMin[0];
        this->m_SubtreeHeaders.m_data[v51].m_quantizedAabbMin[1] = m_subTreeInfoPtr->m_quantizedAabbMin[1];
        this->m_SubtreeHeaders.m_data[v51].m_quantizedAabbMin[2] = m_subTreeInfoPtr->m_quantizedAabbMin[2];
        this->m_SubtreeHeaders.m_data[v51].m_rootNodeIndex = m_subTreeInfoPtr->m_rootNodeIndex;
        this->m_SubtreeHeaders.m_data[v51++].m_subtreeSize = m_subTreeInfoPtr->m_subtreeSize;
        ++m_subTreeInfoPtr;
        --v52;
      }
      while ( v52 );
    }
  }
}
