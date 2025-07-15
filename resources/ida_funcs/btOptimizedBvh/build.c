void __userpurge btOptimizedBvh::build(
        bool useQuantizedAabbCompression@<al>,
        const btVector3 *bvhAabbMax@<ecx>,
        btOptimizedBvh *this,
        btStridingMeshInterface *triangles,
        const btVector3 *bvhAabbMin)
{
  void (__thiscall *InternalProcessAllTriangles)(btStridingMeshInterface *, btInternalTriangleIndexCallback *, const btVector3 *, const btVector3 *); // edx
  int m_size; // eax
  int v7; // edi
  int v8; // esi
  btQuantizedBvhNode *v9; // ecx
  int v10; // edx
  int v11; // edi
  btQuantizedBvhNode *m_data; // eax
  btQuantizedBvhNode *v13; // eax
  __int64 v14; // xmm0_8
  int v15; // eax
  int v16; // edx
  btQuantizedBvhNode *v17; // ecx
  btStridingMeshInterface_vtbl *v18; // eax
  void (__thiscall *v19)(btStridingMeshInterface *, btInternalTriangleIndexCallback *, const btVector3 *, const btVector3 *); // edx
  int v20; // edi
  int v21; // esi
  int v22; // eax
  btOptimizedBvhNode *v23; // eax
  int v24; // edx
  btOptimizedBvhNode *v25; // eax
  int v26; // edx
  int v27; // eax
  char *v28; // edi
  btBvhSubtreeInfo *v29; // edi
  int v30; // esi
  int m_capacity; // eax
  int v32; // edx
  btBvhSubtreeInfo *v33; // ecx
  int v34; // esi
  btBvhSubtreeInfo *v35; // eax
  __int64 v36; // xmm0_8
  btBvhSubtreeInfo *v37; // eax
  btBvhSubtreeInfo *v38; // eax
  btBvhSubtreeInfo *v39; // eax
  int v40; // esi
  btBvhSubtreeInfo *v41; // eax
  btBvhSubtreeInfo *v42; // eax
  btQuantizedBvhNode *v43; // ecx
  int m_escapeIndexOrTriangleIndex; // ecx
  int v45; // ecx
  btQuantizedBvhNode *v46; // eax
  btOptimizedBvhNode *v47; // eax
  float v48; // [esp+240h] [ebp-A0h]
  btQuantizedBvhNode *v49; // [esp+254h] [ebp-8Ch]
  btOptimizedBvhNode *v50; // [esp+254h] [ebp-8Ch]
  int v51; // [esp+254h] [ebp-8Ch]
  int endIndex; // [esp+258h] [ebp-88h]
  int v53; // [esp+25Ch] [ebp-84h]
  int v54; // [esp+25Ch] [ebp-84h]
  int v55; // [esp+260h] [ebp-80h]
  int v56; // [esp+260h] [ebp-80h]
  int (__thiscall **v57)(void *, char); // [esp+264h] [ebp-7Ch] BYREF
  void *p_m_quantizedLeafNodes; // [esp+268h] [ebp-78h]
  btOptimizedBvh *v59; // [esp+26Ch] [ebp-74h]
  __int128 v60; // [esp+270h] [ebp-70h] BYREF
  __int64 v61; // [esp+280h] [ebp-60h]
  __int64 v62; // [esp+288h] [ebp-58h]
  _DWORD v63[4]; // [esp+290h] [ebp-50h] BYREF
  _BYTE v64[64]; // [esp+2A0h] [ebp-40h] BYREF

  this->m_useQuantization = useQuantizedAabbCompression;
  if ( useQuantizedAabbCompression )
  {
    btQuantizedBvh::setQuantizationValues(bvhAabbMin, bvhAabbMax, this, v48);
    InternalProcessAllTriangles = triangles->InternalProcessAllTriangles;
    p_m_quantizedLeafNodes = &this->m_quantizedLeafNodes;
    v57 = &`btOptimizedBvh::build'::`3'::QuantizedNodeTriangleCallback::`vftable';
    v59 = this;
    InternalProcessAllTriangles(
      triangles,
      (btInternalTriangleIndexCallback *)&v57,
      &this->m_bvhAabbMin,
      &this->m_bvhAabbMax);
    m_size = this->m_quantizedLeafNodes.m_size;
    v7 = this->m_quantizedContiguousNodes.m_size;
    v8 = 2 * m_size;
    endIndex = m_size;
    v60 = 0;
    v53 = v7;
    if ( 2 * m_size >= v7 )
    {
      if ( 2 * m_size > v7 && this->m_quantizedContiguousNodes.m_capacity < v8 )
      {
        if ( v8 )
        {
          ++gNumAlignedAllocs;
          v49 = (btQuantizedBvhNode *)sAlignedAllocFunc(32 * m_size, 16);
        }
        else
        {
          v49 = 0;
        }
        if ( this->m_quantizedContiguousNodes.m_size > 0 )
        {
          v9 = v49;
          v10 = 0;
          v11 = this->m_quantizedContiguousNodes.m_size;
          do
          {
            if ( v9 )
            {
              m_data = this->m_quantizedContiguousNodes.m_data;
              *(_QWORD *)v9->m_quantizedAabbMin = *(_QWORD *)m_data[v10].m_quantizedAabbMin;
              *(_QWORD *)&v9->m_quantizedAabbMax[1] = *(_QWORD *)&m_data[v10].m_quantizedAabbMax[1];
            }
            ++v10;
            ++v9;
            --v11;
          }
          while ( v11 );
          v7 = v53;
        }
        v13 = this->m_quantizedContiguousNodes.m_data;
        if ( v13 )
        {
          if ( this->m_quantizedContiguousNodes.m_ownsMemory )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v13);
          }
          this->m_quantizedContiguousNodes.m_data = 0;
        }
        this->m_quantizedContiguousNodes.m_ownsMemory = 1;
        this->m_quantizedContiguousNodes.m_data = v49;
        this->m_quantizedContiguousNodes.m_capacity = v8;
      }
      if ( v7 < v8 )
      {
        v14 = *((_QWORD *)&v60 + 1);
        v15 = v7;
        v16 = v8 - v7;
        do
        {
          v17 = &this->m_quantizedContiguousNodes.m_data[v15];
          if ( v17 )
          {
            *(_QWORD *)v17->m_quantizedAabbMin = v60;
            *(_QWORD *)&v17->m_quantizedAabbMax[1] = v14;
          }
          ++v15;
          --v16;
        }
        while ( v16 );
      }
    }
    this->m_quantizedContiguousNodes.m_size = v8;
  }
  else
  {
    v18 = triangles->__vftable;
    p_m_quantizedLeafNodes = &this->m_leafNodes;
    v19 = v18->InternalProcessAllTriangles;
    LODWORD(v60) = -581039253;
    *(_QWORD *)((char *)&v60 + 4) = 0xDD5E0B6BDD5E0B6BuLL;
    v57 = &`btOptimizedBvh::build'::`2'::NodeTriangleCallback::`vftable';
    HIDWORD(v60) = 0;
    v63[0] = 1566444395;
    v63[1] = 1566444395;
    v63[2] = 1566444395;
    v63[3] = 0;
    v19(triangles, (btInternalTriangleIndexCallback *)&v57, (const btVector3 *)&v60, (const btVector3 *)v63);
    v20 = this->m_leafNodes.m_size;
    v21 = this->m_contiguousNodes.m_size;
    v22 = 2 * v20;
    endIndex = v20;
    v55 = v21;
    if ( 2 * v20 >= v21 )
    {
      if ( 2 * v20 > v21 && this->m_contiguousNodes.m_capacity < v22 )
      {
        if ( v22 )
        {
          ++gNumAlignedAllocs;
          v50 = (btOptimizedBvhNode *)sAlignedAllocFunc(v20 << 7, 16);
        }
        else
        {
          v50 = 0;
        }
        if ( this->m_contiguousNodes.m_size > 0 )
        {
          v23 = v50;
          v24 = 0;
          v54 = this->m_contiguousNodes.m_size;
          do
          {
            if ( v23 )
            {
              qmemcpy(v23, &this->m_contiguousNodes.m_data[v24], sizeof(btOptimizedBvhNode));
              v21 = v55;
            }
            ++v24;
            ++v23;
            --v54;
          }
          while ( v54 );
        }
        v25 = this->m_contiguousNodes.m_data;
        if ( v25 )
        {
          if ( this->m_contiguousNodes.m_ownsMemory )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v25);
          }
          this->m_contiguousNodes.m_data = 0;
        }
        this->m_contiguousNodes.m_data = v50;
        v22 = 2 * v20;
        this->m_contiguousNodes.m_ownsMemory = 1;
        this->m_contiguousNodes.m_capacity = 2 * v20;
      }
      if ( v21 < v22 )
      {
        v26 = v21 << 6;
        v27 = v22 - v21;
        do
        {
          v28 = (char *)this->m_contiguousNodes.m_data + v26;
          if ( v28 )
            qmemcpy(v28, v64, 0x40u);
          v26 += 64;
          --v27;
        }
        while ( v27 );
      }
    }
    this->m_contiguousNodes.m_size = 2 * endIndex;
  }
  this->m_curNodeIndex = 0;
  btQuantizedBvh::buildTree(this, 0, endIndex);
  v29 = 0;
  if ( this->m_useQuantization && !this->m_SubtreeHeaders.m_size )
  {
    v30 = this->m_SubtreeHeaders.m_size;
    m_capacity = this->m_SubtreeHeaders.m_capacity;
    v56 = v30;
    if ( v30 == m_capacity )
    {
      v51 = v30 ? 2 * v30 : 1;
      if ( m_capacity < v51 )
      {
        if ( v51 )
        {
          ++gNumAlignedAllocs;
          v29 = (btBvhSubtreeInfo *)sAlignedAllocFunc(32 * v51, 16);
        }
        if ( this->m_SubtreeHeaders.m_size > 0 )
        {
          v32 = 0;
          v33 = v29;
          v34 = this->m_SubtreeHeaders.m_size;
          do
          {
            if ( v33 )
            {
              v35 = this->m_SubtreeHeaders.m_data;
              v36 = *(_QWORD *)v35[v32].m_quantizedAabbMin;
              v37 = &v35[v32];
              *(_QWORD *)v33->m_quantizedAabbMin = v36;
              *(_QWORD *)&v33->m_quantizedAabbMax[1] = *(_QWORD *)&v37->m_quantizedAabbMax[1];
              *(_QWORD *)&v33->m_subtreeSize = *(_QWORD *)&v37->m_subtreeSize;
              *(_QWORD *)&v33->m_padding[1] = *(_QWORD *)&v37->m_padding[1];
            }
            ++v32;
            ++v33;
            --v34;
          }
          while ( v34 );
          v30 = v56;
        }
        v38 = this->m_SubtreeHeaders.m_data;
        if ( v38 )
        {
          if ( this->m_SubtreeHeaders.m_ownsMemory )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v38);
          }
          this->m_SubtreeHeaders.m_data = 0;
        }
        this->m_SubtreeHeaders.m_data = v29;
        this->m_SubtreeHeaders.m_ownsMemory = 1;
        this->m_SubtreeHeaders.m_capacity = v51;
      }
    }
    v39 = this->m_SubtreeHeaders.m_data;
    ++this->m_SubtreeHeaders.m_size;
    v40 = v30;
    v41 = &v39[v40];
    if ( v41 )
    {
      *(_OWORD *)v41->m_quantizedAabbMin = v60;
      *(_QWORD *)&v41->m_subtreeSize = v61;
      *(_QWORD *)&v41->m_padding[1] = v62;
    }
    v42 = &this->m_SubtreeHeaders.m_data[v40];
    v43 = this->m_quantizedContiguousNodes.m_data;
    v42->m_quantizedAabbMin[0] = v43->m_quantizedAabbMin[0];
    v42->m_quantizedAabbMin[1] = v43->m_quantizedAabbMin[1];
    v42->m_quantizedAabbMin[2] = v43->m_quantizedAabbMin[2];
    v42->m_quantizedAabbMax[0] = v43->m_quantizedAabbMax[0];
    v42->m_quantizedAabbMax[1] = v43->m_quantizedAabbMax[1];
    v42->m_quantizedAabbMax[2] = v43->m_quantizedAabbMax[2];
    v42->m_rootNodeIndex = 0;
    m_escapeIndexOrTriangleIndex = this->m_quantizedContiguousNodes.m_data->m_escapeIndexOrTriangleIndex;
    if ( m_escapeIndexOrTriangleIndex < 0 )
      v45 = -m_escapeIndexOrTriangleIndex;
    else
      v45 = 1;
    v42->m_subtreeSize = v45;
  }
  this->m_subtreeHeaderCount = this->m_SubtreeHeaders.m_size;
  v46 = this->m_quantizedLeafNodes.m_data;
  if ( v46 )
  {
    if ( this->m_quantizedLeafNodes.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v46);
    }
    this->m_quantizedLeafNodes.m_data = 0;
  }
  this->m_quantizedLeafNodes.m_ownsMemory = 1;
  this->m_quantizedLeafNodes.m_data = 0;
  this->m_quantizedLeafNodes.m_size = 0;
  this->m_quantizedLeafNodes.m_capacity = 0;
  v47 = this->m_leafNodes.m_data;
  if ( v47 )
  {
    if ( this->m_leafNodes.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v47);
    }
    this->m_leafNodes.m_data = 0;
  }
  this->m_leafNodes.m_data = 0;
  this->m_leafNodes.m_size = 0;
  this->m_leafNodes.m_capacity = 0;
  this->m_leafNodes.m_ownsMemory = 1;
}
