void __userpurge btOptimizedBvh::build(
        bool useQuantizedAabbCompression@<al>,
        const btVector3 *bvhAabbMax@<ecx>,
        btOptimizedBvh *this,
        btStridingMeshInterface *triangles,
        const btVector3 *bvhAabbMin)
{
  btStridingMeshInterface_vtbl *v5; // eax
  int m_size; // esi
  int v7; // edi
  int v8; // eax
  int v9; // eax
  btQuantizedBvhNode *v10; // ecx
  int v11; // edx
  btQuantizedBvhNode *v12; // esi
  int v13; // ecx
  int v14; // eax
  btQuantizedBvhNode *v15; // edi
  unsigned __int16 *v16; // edi
  btStridingMeshInterface_vtbl *v17; // eax
  int v18; // esi
  int v19; // edi
  int v20; // eax
  int v21; // eax
  btOptimizedBvhNode *v22; // edx
  int v23; // edx
  int v24; // eax
  char *v25; // edi
  int v26; // eax
  int v27; // edi
  int m_capacity; // eax
  int v29; // eax
  btBvhSubtreeInfo *v30; // edx
  int v31; // edx
  btBvhSubtreeInfo *v32; // edi
  btBvhSubtreeInfo *v33; // esi
  int m_escapeIndexOrTriangleIndex; // eax
  int v35; // eax
  float v36; // [esp+0h] [ebp-A0h]
  int v37; // [esp+14h] [ebp-8Ch]
  int v38; // [esp+14h] [ebp-8Ch]
  int v39; // [esp+14h] [ebp-8Ch]
  btQuantizedBvhNode *v40; // [esp+18h] [ebp-88h]
  int v41; // [esp+18h] [ebp-88h]
  btBvhSubtreeInfo *v42; // [esp+18h] [ebp-88h]
  int v43; // [esp+1Ch] [ebp-84h]
  btOptimizedBvhNode *v44; // [esp+1Ch] [ebp-84h]
  int v45; // [esp+1Ch] [ebp-84h]
  int v46; // [esp+20h] [ebp-80h]
  int v47; // [esp+20h] [ebp-80h]
  int (__stdcall **v48)(int); // [esp+24h] [ebp-7Ch] BYREF
  _DWORD v49[2]; // [esp+28h] [ebp-78h] BYREF
  _DWORD v50[4]; // [esp+30h] [ebp-70h] BYREF
  _DWORD v51[8]; // [esp+40h] [ebp-60h] BYREF
  _BYTE v52[64]; // [esp+60h] [ebp-40h] BYREF

  this->m_useQuantization = useQuantizedAabbCompression;
  if ( useQuantizedAabbCompression )
  {
    btQuantizedBvh::setQuantizationValues(bvhAabbMin, bvhAabbMax, this, v36);
    v49[1] = &this->m_quantizedLeafNodes;
    v5 = triangles->__vftable;
    v49[0] = &`btOptimizedBvh::build'::`3'::QuantizedNodeTriangleCallback::`vftable';
    v50[0] = this;
    ((void (__thiscall *)(btStridingMeshInterface *, _DWORD *, btVector3 *))v5->InternalProcessAllTriangles)(
      triangles,
      v49,
      &this->m_bvhAabbMin);
    m_size = this->m_quantizedLeafNodes.m_size;
    memset(v51, 0, 16);
    v7 = this->m_quantizedContiguousNodes.m_size;
    v8 = 2 * m_size;
    v37 = m_size;
    v43 = v7;
    if ( 2 * m_size >= v7 )
    {
      if ( 2 * m_size > v7 && this->m_quantizedContiguousNodes.m_capacity < v8 )
      {
        if ( v8 )
          v40 = (btQuantizedBvhNode *)btAlignedAllocInternal(32 * m_size);
        else
          v40 = 0;
        v9 = this->m_quantizedContiguousNodes.m_size;
        if ( v9 > 0 )
        {
          v10 = v40;
          v11 = 0;
          do
          {
            if ( v10 )
            {
              v12 = &this->m_quantizedContiguousNodes.m_data[v11];
              *(_DWORD *)v10->m_quantizedAabbMin = *(_DWORD *)v12->m_quantizedAabbMin;
              v12 = (btQuantizedBvhNode *)((char *)v12 + 4);
              *(_DWORD *)&v10->m_quantizedAabbMin[2] = *(_DWORD *)v12->m_quantizedAabbMin;
              v12 = (btQuantizedBvhNode *)((char *)v12 + 4);
              *(_DWORD *)&v10->m_quantizedAabbMax[1] = *(_DWORD *)v12->m_quantizedAabbMin;
              v10->m_escapeIndexOrTriangleIndex = *(_DWORD *)&v12->m_quantizedAabbMin[2];
              v7 = v43;
              m_size = v37;
            }
            ++v11;
            ++v10;
            --v9;
          }
          while ( v9 );
        }
        if ( this->m_quantizedContiguousNodes.m_data )
        {
          if ( this->m_quantizedContiguousNodes.m_ownsMemory )
            btAlignedFreeInternal(this->m_quantizedContiguousNodes.m_data);
          this->m_quantizedContiguousNodes.m_data = 0;
        }
        this->m_quantizedContiguousNodes.m_data = v40;
        v8 = 2 * m_size;
        this->m_quantizedContiguousNodes.m_ownsMemory = 1;
        this->m_quantizedContiguousNodes.m_capacity = 2 * m_size;
      }
      if ( v7 < v8 )
      {
        v13 = v7;
        v14 = v8 - v7;
        do
        {
          v15 = &this->m_quantizedContiguousNodes.m_data[v13];
          if ( v15 )
          {
            *(_DWORD *)v15->m_quantizedAabbMin = v51[0];
            v16 = &v15->m_quantizedAabbMin[2];
            *(_DWORD *)v16 = v51[1];
            v16 += 2;
            *(_DWORD *)v16 = v51[2];
            *((_DWORD *)v16 + 1) = v51[3];
            m_size = v37;
          }
          ++v13;
          --v14;
        }
        while ( v14 );
      }
    }
    this->m_quantizedContiguousNodes.m_size = 2 * m_size;
  }
  else
  {
    v49[0] = &this->m_leafNodes;
    v17 = triangles->__vftable;
    *(float *)v51 = FLOAT_N9_9999998e17;
    *(float *)&v51[1] = FLOAT_N9_9999998e17;
    *(float *)&v51[2] = FLOAT_N9_9999998e17;
    v48 = &`btOptimizedBvh::build'::`2'::NodeTriangleCallback::`vftable';
    v51[3] = 0;
    *(float *)v50 = FLOAT_9_9999998e17;
    *(float *)&v50[1] = FLOAT_9_9999998e17;
    *(float *)&v50[2] = FLOAT_9_9999998e17;
    v50[3] = 0;
    v17->InternalProcessAllTriangles(
      triangles,
      (btInternalTriangleIndexCallback *)&v48,
      (const btVector3 *)v51,
      (const btVector3 *)v50);
    v18 = this->m_leafNodes.m_size;
    v19 = this->m_contiguousNodes.m_size;
    v20 = 2 * v18;
    v38 = v18;
    v46 = v19;
    if ( 2 * v18 >= v19 )
    {
      if ( 2 * v18 > v19 && this->m_contiguousNodes.m_capacity < v20 )
      {
        if ( v20 )
          v44 = (btOptimizedBvhNode *)btAlignedAllocInternal(v18 << 7);
        else
          v44 = 0;
        v21 = this->m_contiguousNodes.m_size;
        if ( v21 > 0 )
        {
          v41 = 0;
          v22 = v44;
          do
          {
            if ( v22 )
            {
              qmemcpy(v22, &this->m_contiguousNodes.m_data[v41], sizeof(btOptimizedBvhNode));
              v19 = v46;
              v18 = v38;
            }
            ++v41;
            ++v22;
            --v21;
          }
          while ( v21 );
        }
        if ( this->m_contiguousNodes.m_data )
        {
          if ( this->m_contiguousNodes.m_ownsMemory )
            btAlignedFreeInternal(this->m_contiguousNodes.m_data);
          this->m_contiguousNodes.m_data = 0;
        }
        this->m_contiguousNodes.m_data = v44;
        v20 = 2 * v18;
        this->m_contiguousNodes.m_ownsMemory = 1;
        this->m_contiguousNodes.m_capacity = 2 * v18;
      }
      if ( v19 < v20 )
      {
        v23 = v19 << 6;
        v24 = v20 - v19;
        do
        {
          v25 = (char *)this->m_contiguousNodes.m_data + v23;
          if ( v25 )
          {
            qmemcpy(v25, v52, 0x40u);
            v18 = v38;
          }
          v23 += 64;
          --v24;
        }
        while ( v24 );
      }
    }
    v26 = 2 * v18;
    m_size = v38;
    this->m_contiguousNodes.m_size = v26;
  }
  this->m_curNodeIndex = 0;
  btQuantizedBvh::buildTree(this, 0, m_size);
  if ( this->m_useQuantization && !this->m_SubtreeHeaders.m_size )
  {
    v27 = this->m_SubtreeHeaders.m_size;
    m_capacity = this->m_SubtreeHeaders.m_capacity;
    v47 = v27;
    if ( v27 == m_capacity )
    {
      v39 = v27 ? 2 * v27 : 1;
      if ( m_capacity < v39 )
      {
        if ( v39 )
          v42 = (btBvhSubtreeInfo *)btAlignedAllocInternal(32 * v39);
        else
          v42 = 0;
        v29 = this->m_SubtreeHeaders.m_size;
        if ( v29 > 0 )
        {
          v30 = v42;
          v45 = 0;
          do
          {
            if ( v30 )
            {
              qmemcpy(v30, &this->m_SubtreeHeaders.m_data[v45], sizeof(btBvhSubtreeInfo));
              v27 = v47;
            }
            ++v45;
            ++v30;
            --v29;
          }
          while ( v29 );
        }
        if ( this->m_SubtreeHeaders.m_data )
        {
          if ( this->m_SubtreeHeaders.m_ownsMemory )
            btAlignedFreeInternal(this->m_SubtreeHeaders.m_data);
          this->m_SubtreeHeaders.m_data = 0;
        }
        this->m_SubtreeHeaders.m_data = v42;
        this->m_SubtreeHeaders.m_ownsMemory = 1;
        this->m_SubtreeHeaders.m_capacity = v39;
      }
    }
    ++this->m_SubtreeHeaders.m_size;
    v31 = v27;
    v32 = &this->m_SubtreeHeaders.m_data[v27];
    if ( v32 )
      qmemcpy(v32, v51, sizeof(btBvhSubtreeInfo));
    v33 = &this->m_SubtreeHeaders.m_data[v31];
    btBvhSubtreeInfo::setAabbFromQuantizeNode(v33, this->m_quantizedContiguousNodes.m_data);
    v33->m_rootNodeIndex = 0;
    m_escapeIndexOrTriangleIndex = this->m_quantizedContiguousNodes.m_data->m_escapeIndexOrTriangleIndex;
    if ( m_escapeIndexOrTriangleIndex < 0 )
      v35 = -m_escapeIndexOrTriangleIndex;
    else
      v35 = 1;
    v33->m_subtreeSize = v35;
  }
  this->m_subtreeHeaderCount = this->m_SubtreeHeaders.m_size;
  if ( this->m_quantizedLeafNodes.m_data )
  {
    if ( this->m_quantizedLeafNodes.m_ownsMemory )
      btAlignedFreeInternal(this->m_quantizedLeafNodes.m_data);
    this->m_quantizedLeafNodes.m_data = 0;
  }
  this->m_quantizedLeafNodes.m_ownsMemory = 1;
  this->m_quantizedLeafNodes.m_data = 0;
  this->m_quantizedLeafNodes.m_size = 0;
  this->m_quantizedLeafNodes.m_capacity = 0;
  if ( this->m_leafNodes.m_data )
  {
    if ( this->m_leafNodes.m_ownsMemory )
      btAlignedFreeInternal(this->m_leafNodes.m_data);
    this->m_leafNodes.m_data = 0;
  }
  this->m_leafNodes.m_data = 0;
  this->m_leafNodes.m_size = 0;
  this->m_leafNodes.m_capacity = 0;
  this->m_leafNodes.m_ownsMemory = 1;
}
