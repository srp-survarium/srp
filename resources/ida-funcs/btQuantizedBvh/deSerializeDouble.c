void __thiscall btQuantizedBvh::deSerializeDouble(
        btQuantizedBvh *this,
        btQuantizedBvhDoubleData *quantizedBvhDoubleData)
{
  btQuantizedBvhDoubleData *v3; // edi
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  int m_numContiguousLeafNodes; // esi
  int m_size; // ecx
  btOptimizedBvhNode *v17; // eax
  int v18; // edx
  btOptimizedBvhNode *m_data; // eax
  int v20; // eax
  int v21; // edx
  char *v22; // edi
  btOptimizedBvhNodeDoubleData *m_contiguousNodesPtr; // eax
  int v24; // edx
  int v25; // edi
  btOptimizedBvhNode *v26; // ecx
  float v27; // xmm0_4
  float *m128_f32; // ecx
  float v29; // xmm0_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  btOptimizedBvhNode *v32; // ecx
  float v33; // xmm0_4
  float v34; // xmm0_4
  float v35; // xmm0_4
  int v36; // ecx
  int m_numQuantizedContiguousNodes; // esi
  btQuantizedBvhNode *v38; // eax
  btQuantizedBvhNode *v39; // ecx
  int v40; // edx
  int v41; // edi
  btQuantizedBvhNode *v42; // eax
  btQuantizedBvhNode *v43; // eax
  __int64 v44; // xmm0_8
  int v45; // eax
  int v46; // edx
  btQuantizedBvhNode *v47; // ecx
  btQuantizedBvhNodeData *m_quantizedContiguousNodesPtr; // ecx
  int v49; // eax
  int v50; // edx
  int v51; // eax
  int m_numSubtreeHeaders; // esi
  btBvhSubtreeInfo *v53; // ecx
  int v54; // edx
  int v55; // edi
  btBvhSubtreeInfo *v56; // eax
  __int64 v57; // xmm0_8
  btBvhSubtreeInfo *v58; // eax
  btBvhSubtreeInfo *v59; // eax
  __int64 v60; // xmm0_8
  __int64 v61; // xmm1_8
  __int64 v62; // xmm2_8
  __int64 v63; // xmm3_8
  int v64; // ecx
  int v65; // edx
  btBvhSubtreeInfo *v66; // eax
  btBvhSubtreeInfoData *m_subTreeInfoPtr; // ecx
  int v68; // eax
  int v69; // edx
  btOptimizedBvhNode *v70; // [esp+58h] [ebp-50h]
  int v71; // [esp+58h] [ebp-50h]
  int v72; // [esp+5Ch] [ebp-4Ch]
  btQuantizedBvhNode *v73; // [esp+5Ch] [ebp-4Ch]
  btBvhSubtreeInfo *v74; // [esp+5Ch] [ebp-4Ch]
  int v75; // [esp+60h] [ebp-48h]
  int v76; // [esp+64h] [ebp-44h]
  int v77; // [esp+64h] [ebp-44h]
  _OWORD v78[4]; // [esp+68h] [ebp-40h] BYREF

  v3 = quantizedBvhDoubleData;
  v4 = quantizedBvhDoubleData->m_bvhAabbMax.m_floats[0];
  this->m_bvhAabbMax.mVec128.m128_f32[0] = v4;
  v5 = quantizedBvhDoubleData->m_bvhAabbMax.m_floats[1];
  this->m_bvhAabbMax.mVec128.m128_f32[1] = v5;
  v6 = quantizedBvhDoubleData->m_bvhAabbMax.m_floats[2];
  this->m_bvhAabbMax.mVec128.m128_f32[2] = v6;
  v7 = quantizedBvhDoubleData->m_bvhAabbMax.m_floats[3];
  this->m_bvhAabbMax.mVec128.m128_f32[3] = v7;
  v8 = quantizedBvhDoubleData->m_bvhAabbMin.m_floats[0];
  this->m_bvhAabbMin.mVec128.m128_f32[0] = v8;
  v9 = quantizedBvhDoubleData->m_bvhAabbMin.m_floats[1];
  this->m_bvhAabbMin.mVec128.m128_f32[1] = v9;
  v10 = quantizedBvhDoubleData->m_bvhAabbMin.m_floats[2];
  this->m_bvhAabbMin.mVec128.m128_f32[2] = v10;
  v11 = quantizedBvhDoubleData->m_bvhAabbMin.m_floats[3];
  this->m_bvhAabbMin.mVec128.m128_f32[3] = v11;
  v12 = quantizedBvhDoubleData->m_bvhQuantization.m_floats[0];
  this->m_bvhQuantization.mVec128.m128_f32[0] = v12;
  v13 = quantizedBvhDoubleData->m_bvhQuantization.m_floats[1];
  this->m_bvhQuantization.mVec128.m128_f32[1] = v13;
  v14 = quantizedBvhDoubleData->m_bvhQuantization.m_floats[2];
  this->m_bvhQuantization.mVec128.m128_f32[2] = v14;
  this->m_bvhQuantization.mVec128.m128_f32[3] = quantizedBvhDoubleData->m_bvhQuantization.m_floats[3];
  this->m_curNodeIndex = quantizedBvhDoubleData->m_curNodeIndex;
  this->m_useQuantization = quantizedBvhDoubleData->m_useQuantization != 0;
  m_numContiguousLeafNodes = quantizedBvhDoubleData->m_numContiguousLeafNodes;
  m_size = this->m_contiguousNodes.m_size;
  v75 = m_numContiguousLeafNodes;
  v76 = m_size;
  if ( m_numContiguousLeafNodes >= m_size )
  {
    if ( m_numContiguousLeafNodes > m_size && this->m_contiguousNodes.m_capacity < m_numContiguousLeafNodes )
    {
      if ( m_numContiguousLeafNodes )
      {
        ++gNumAlignedAllocs;
        v70 = (btOptimizedBvhNode *)sAlignedAllocFunc(m_numContiguousLeafNodes << 6, 16);
      }
      else
      {
        v70 = 0;
      }
      if ( this->m_contiguousNodes.m_size > 0 )
      {
        v17 = v70;
        v18 = 0;
        v72 = this->m_contiguousNodes.m_size;
        do
        {
          if ( v17 )
          {
            qmemcpy(v17, &this->m_contiguousNodes.m_data[v18], sizeof(btOptimizedBvhNode));
            m_numContiguousLeafNodes = v75;
            v3 = quantizedBvhDoubleData;
          }
          ++v18;
          ++v17;
          --v72;
        }
        while ( v72 );
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
      m_size = v76;
      this->m_contiguousNodes.m_ownsMemory = 1;
      this->m_contiguousNodes.m_data = v70;
      this->m_contiguousNodes.m_capacity = m_numContiguousLeafNodes;
    }
    if ( m_size < m_numContiguousLeafNodes )
    {
      v20 = m_size << 6;
      v21 = m_numContiguousLeafNodes - m_size;
      do
      {
        v22 = (char *)this->m_contiguousNodes.m_data + v20;
        if ( v22 )
        {
          qmemcpy(v22, v78, 0x40u);
          m_numContiguousLeafNodes = v75;
        }
        v20 += 64;
        --v21;
      }
      while ( v21 );
      v3 = quantizedBvhDoubleData;
    }
  }
  this->m_contiguousNodes.m_size = m_numContiguousLeafNodes;
  if ( m_numContiguousLeafNodes )
  {
    m_contiguousNodesPtr = v3->m_contiguousNodesPtr;
    if ( m_numContiguousLeafNodes > 0 )
    {
      v24 = 0;
      v25 = m_numContiguousLeafNodes;
      do
      {
        v26 = this->m_contiguousNodes.m_data;
        v27 = m_contiguousNodesPtr->m_aabbMaxOrg.m_floats[0];
        v26[v24].m_aabbMaxOrg.mVec128.m128_f32[0] = v27;
        m128_f32 = v26[v24].m_aabbMaxOrg.mVec128.m128_f32;
        v29 = m_contiguousNodesPtr->m_aabbMaxOrg.m_floats[1];
        m128_f32[1] = v29;
        v30 = m_contiguousNodesPtr->m_aabbMaxOrg.m_floats[2];
        m128_f32[2] = v30;
        v31 = m_contiguousNodesPtr->m_aabbMaxOrg.m_floats[3];
        m128_f32[3] = v31;
        v32 = &this->m_contiguousNodes.m_data[v24];
        v33 = m_contiguousNodesPtr->m_aabbMinOrg.m_floats[0];
        v32->m_aabbMinOrg.mVec128.m128_f32[0] = v33;
        v34 = m_contiguousNodesPtr->m_aabbMinOrg.m_floats[1];
        v32->m_aabbMinOrg.mVec128.m128_f32[1] = v34;
        v35 = m_contiguousNodesPtr->m_aabbMinOrg.m_floats[2];
        v32->m_aabbMinOrg.mVec128.m128_f32[2] = v35;
        v32->m_aabbMinOrg.mVec128.m128_f32[3] = m_contiguousNodesPtr->m_aabbMinOrg.m_floats[3];
        this->m_contiguousNodes.m_data[v24].m_escapeIndex = m_contiguousNodesPtr->m_escapeIndex;
        this->m_contiguousNodes.m_data[v24].m_subPart = m_contiguousNodesPtr->m_subPart;
        this->m_contiguousNodes.m_data[v24++].m_triangleIndex = m_contiguousNodesPtr->m_triangleIndex;
        ++m_contiguousNodesPtr;
        --v25;
      }
      while ( v25 );
      v3 = quantizedBvhDoubleData;
    }
  }
  v36 = this->m_quantizedContiguousNodes.m_size;
  m_numQuantizedContiguousNodes = v3->m_numQuantizedContiguousNodes;
  v78[0] = 0;
  v71 = v36;
  if ( m_numQuantizedContiguousNodes >= v36 )
  {
    if ( m_numQuantizedContiguousNodes > v36
      && this->m_quantizedContiguousNodes.m_capacity < m_numQuantizedContiguousNodes )
    {
      if ( m_numQuantizedContiguousNodes )
      {
        ++gNumAlignedAllocs;
        v38 = (btQuantizedBvhNode *)sAlignedAllocFunc(16 * m_numQuantizedContiguousNodes, 16);
        v36 = v71;
        v73 = v38;
      }
      else
      {
        v73 = 0;
      }
      if ( this->m_quantizedContiguousNodes.m_size > 0 )
      {
        v39 = v73;
        v40 = 0;
        v41 = this->m_quantizedContiguousNodes.m_size;
        do
        {
          if ( v39 )
          {
            v42 = this->m_quantizedContiguousNodes.m_data;
            *(_QWORD *)v39->m_quantizedAabbMin = *(_QWORD *)v42[v40].m_quantizedAabbMin;
            *(_QWORD *)&v39->m_quantizedAabbMax[1] = *(_QWORD *)&v42[v40].m_quantizedAabbMax[1];
          }
          ++v40;
          ++v39;
          --v41;
        }
        while ( v41 );
        v3 = quantizedBvhDoubleData;
        v36 = v71;
      }
      v43 = this->m_quantizedContiguousNodes.m_data;
      if ( v43 )
      {
        if ( this->m_quantizedContiguousNodes.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v43);
          v36 = v71;
        }
        this->m_quantizedContiguousNodes.m_data = 0;
      }
      this->m_quantizedContiguousNodes.m_ownsMemory = 1;
      this->m_quantizedContiguousNodes.m_data = v73;
      this->m_quantizedContiguousNodes.m_capacity = m_numQuantizedContiguousNodes;
    }
    if ( v36 < m_numQuantizedContiguousNodes )
    {
      v44 = *((_QWORD *)&v78[0] + 1);
      v45 = v36;
      v46 = m_numQuantizedContiguousNodes - v36;
      do
      {
        v47 = &this->m_quantizedContiguousNodes.m_data[v45];
        if ( v47 )
        {
          *(_QWORD *)v47->m_quantizedAabbMin = *(_QWORD *)&v78[0];
          *(_QWORD *)&v47->m_quantizedAabbMax[1] = v44;
        }
        ++v45;
        --v46;
      }
      while ( v46 );
    }
  }
  this->m_quantizedContiguousNodes.m_size = m_numQuantizedContiguousNodes;
  if ( m_numQuantizedContiguousNodes )
  {
    m_quantizedContiguousNodesPtr = v3->m_quantizedContiguousNodesPtr;
    if ( m_numQuantizedContiguousNodes > 0 )
    {
      v49 = 0;
      v50 = m_numQuantizedContiguousNodes;
      do
      {
        this->m_quantizedContiguousNodes.m_data[v49].m_escapeIndexOrTriangleIndex = m_quantizedContiguousNodesPtr->m_escapeIndexOrTriangleIndex;
        this->m_quantizedContiguousNodes.m_data[v49].m_quantizedAabbMax[0] = m_quantizedContiguousNodesPtr->m_quantizedAabbMax[0];
        this->m_quantizedContiguousNodes.m_data[v49].m_quantizedAabbMax[1] = m_quantizedContiguousNodesPtr->m_quantizedAabbMax[1];
        this->m_quantizedContiguousNodes.m_data[v49].m_quantizedAabbMax[2] = m_quantizedContiguousNodesPtr->m_quantizedAabbMax[2];
        this->m_quantizedContiguousNodes.m_data[v49].m_quantizedAabbMin[0] = m_quantizedContiguousNodesPtr->m_quantizedAabbMin[0];
        this->m_quantizedContiguousNodes.m_data[v49].m_quantizedAabbMin[1] = m_quantizedContiguousNodesPtr->m_quantizedAabbMin[1];
        this->m_quantizedContiguousNodes.m_data[v49++].m_quantizedAabbMin[2] = m_quantizedContiguousNodesPtr->m_quantizedAabbMin[2];
        ++m_quantizedContiguousNodesPtr;
        --v50;
      }
      while ( v50 );
      v3 = quantizedBvhDoubleData;
    }
  }
  this->m_traversalMode = v3->m_traversalMode;
  v51 = this->m_SubtreeHeaders.m_size;
  m_numSubtreeHeaders = v3->m_numSubtreeHeaders;
  v77 = v51;
  if ( m_numSubtreeHeaders >= v51 )
  {
    if ( m_numSubtreeHeaders > v51 && this->m_SubtreeHeaders.m_capacity < m_numSubtreeHeaders )
    {
      if ( m_numSubtreeHeaders )
      {
        ++gNumAlignedAllocs;
        v74 = (btBvhSubtreeInfo *)sAlignedAllocFunc(32 * m_numSubtreeHeaders, 16);
      }
      else
      {
        v74 = 0;
      }
      if ( this->m_SubtreeHeaders.m_size > 0 )
      {
        v53 = v74;
        v54 = 0;
        v55 = this->m_SubtreeHeaders.m_size;
        do
        {
          if ( v53 )
          {
            v56 = this->m_SubtreeHeaders.m_data;
            v57 = *(_QWORD *)v56[v54].m_quantizedAabbMin;
            v58 = &v56[v54];
            *(_QWORD *)v53->m_quantizedAabbMin = v57;
            *(_QWORD *)&v53->m_quantizedAabbMax[1] = *(_QWORD *)&v58->m_quantizedAabbMax[1];
            *(_QWORD *)&v53->m_subtreeSize = *(_QWORD *)&v58->m_subtreeSize;
            *(_QWORD *)&v53->m_padding[1] = *(_QWORD *)&v58->m_padding[1];
          }
          ++v54;
          ++v53;
          --v55;
        }
        while ( v55 );
        v3 = quantizedBvhDoubleData;
      }
      v59 = this->m_SubtreeHeaders.m_data;
      if ( v59 )
      {
        if ( this->m_SubtreeHeaders.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v59);
        }
        this->m_SubtreeHeaders.m_data = 0;
      }
      this->m_SubtreeHeaders.m_data = v74;
      v51 = v77;
      this->m_SubtreeHeaders.m_ownsMemory = 1;
      this->m_SubtreeHeaders.m_capacity = m_numSubtreeHeaders;
    }
    if ( v51 < m_numSubtreeHeaders )
    {
      v60 = *((_QWORD *)&v78[1] + 1);
      v61 = *(_QWORD *)&v78[1];
      v62 = *((_QWORD *)&v78[0] + 1);
      v63 = *(_QWORD *)&v78[0];
      v64 = v51;
      v65 = m_numSubtreeHeaders - v51;
      do
      {
        v66 = &this->m_SubtreeHeaders.m_data[v64];
        if ( v66 )
        {
          *(_QWORD *)v66->m_quantizedAabbMin = v63;
          *(_QWORD *)&v66->m_quantizedAabbMax[1] = v62;
          *(_QWORD *)&v66->m_subtreeSize = v61;
          *(_QWORD *)&v66->m_padding[1] = v60;
        }
        ++v64;
        --v65;
      }
      while ( v65 );
    }
  }
  this->m_SubtreeHeaders.m_size = m_numSubtreeHeaders;
  if ( m_numSubtreeHeaders )
  {
    m_subTreeInfoPtr = v3->m_subTreeInfoPtr;
    if ( m_numSubtreeHeaders > 0 )
    {
      v68 = 0;
      v69 = m_numSubtreeHeaders;
      do
      {
        this->m_SubtreeHeaders.m_data[v68].m_quantizedAabbMax[0] = m_subTreeInfoPtr->m_quantizedAabbMax[0];
        this->m_SubtreeHeaders.m_data[v68].m_quantizedAabbMax[1] = m_subTreeInfoPtr->m_quantizedAabbMax[1];
        this->m_SubtreeHeaders.m_data[v68].m_quantizedAabbMax[2] = m_subTreeInfoPtr->m_quantizedAabbMax[2];
        this->m_SubtreeHeaders.m_data[v68].m_quantizedAabbMin[0] = m_subTreeInfoPtr->m_quantizedAabbMin[0];
        this->m_SubtreeHeaders.m_data[v68].m_quantizedAabbMin[1] = m_subTreeInfoPtr->m_quantizedAabbMin[1];
        this->m_SubtreeHeaders.m_data[v68].m_quantizedAabbMin[2] = m_subTreeInfoPtr->m_quantizedAabbMin[2];
        this->m_SubtreeHeaders.m_data[v68].m_rootNodeIndex = m_subTreeInfoPtr->m_rootNodeIndex;
        this->m_SubtreeHeaders.m_data[v68++].m_subtreeSize = m_subTreeInfoPtr->m_subtreeSize;
        ++m_subTreeInfoPtr;
        --v69;
      }
      while ( v69 );
    }
  }
}
