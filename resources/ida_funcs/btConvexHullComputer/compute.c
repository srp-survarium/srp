__int64 __userpurge btConvexHullComputer::compute@<xmm0>(
        btConvexHullComputer *this@<ecx>,
        int count@<eax>,
        char *coords,
        bool doubleCoords,
        int stride,
        float shrink,
        float shrinkClamp)
{
  btVector3 *v8; // eax
  btConvexHullComputer::Edge *v9; // eax
  int *v10; // eax
  __int64 v11; // xmm0_8
  int m_size; // esi
  btVector3 *m_data; // eax
  unsigned __int64 v14; // xmm0_8
  unsigned __int64 v15; // xmm1_8
  int v16; // esi
  btVector3 *v17; // eax
  int v18; // esi
  btConvexHullComputer::Edge *v19; // eax
  int v20; // edx
  unsigned __int64 v21; // xmm0_8
  int v22; // ecx
  btConvexHullComputer::Edge *v23; // eax
  int v24; // esi
  int *v25; // eax
  int v26; // ecx
  int *v27; // eax
  int edges; // ecx
  const btConvexHullInternal::Vertex *v29; // ebx
  btVector3 *Coordinates; // eax
  int m_capacity; // ecx
  btVector3 *v32; // edx
  int v33; // eax
  int v34; // eax
  btVector3 *v35; // ebx
  int v36; // edx
  btVector3 *v37; // ecx
  int v38; // esi
  btVector3 *v39; // eax
  btVector3 *v40; // eax
  btVector3 *v41; // eax
  int v42; // esi
  int v43; // eax
  int v44; // esi
  int v45; // ecx
  int v46; // eax
  btConvexHullComputer::Edge *v47; // ecx
  int v48; // edx
  int v49; // ebx
  btConvexHullComputer::Edge *v50; // eax
  btConvexHullComputer::Edge *v51; // eax
  btConvexHullComputer::Edge *v52; // eax
  int v53; // edx
  int v54; // ecx
  int v55; // eax
  int v56; // ebx
  btConvexHullComputer::Edge *v57; // ecx
  int v58; // edx
  int v59; // esi
  btConvexHullComputer::Edge *v60; // eax
  btConvexHullComputer::Edge *v61; // eax
  btConvexHullComputer::Edge *v62; // eax
  int v63; // ecx
  btConvexHullComputer::Edge *v64; // ebx
  int v65; // edx
  btConvexHullInternal::Edge *v66; // ebx
  int v67; // eax
  int v68; // esi
  int v69; // edx
  int v70; // eax
  int *v71; // ecx
  int *v72; // eax
  int *v73; // eax
  btConvexHullInternal::Edge *prev; // eax
  btConvexHullInternal::Edge *reverse; // edx
  btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *v76; // ecx
  btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *v77; // ecx
  btConvexHullInternal::Vertex *vertexList; // [esp+860h] [ebp-E4h]
  int v79; // [esp+864h] [ebp-E0h]
  int v80; // [esp+868h] [ebp-DCh]
  int v81; // [esp+878h] [ebp-CCh]
  btConvexHullComputer::Edge *v82; // [esp+878h] [ebp-CCh]
  btConvexHullComputer::Edge *v83; // [esp+878h] [ebp-CCh]
  int j; // [esp+878h] [ebp-CCh]
  btVector3 *v85; // [esp+87Ch] [ebp-C8h]
  int v86; // [esp+87Ch] [ebp-C8h]
  btConvexHullInternal::Edge *v87; // [esp+87Ch] [ebp-C8h]
  const btConvexHullInternal::Vertex *v88; // [esp+880h] [ebp-C4h]
  int v89; // [esp+880h] [ebp-C4h]
  btConvexHullInternal::Edge *v90; // [esp+880h] [ebp-C4h]
  int v91; // [esp+884h] [ebp-C0h]
  int *v92; // [esp+884h] [ebp-C0h]
  int i; // [esp+888h] [ebp-BCh]
  int v94; // [esp+88Ch] [ebp-B8h]
  btAlignedObjectArray<btConvexHullInternal::Vertex *> vertices; // [esp+890h] [ebp-B4h] BYREF
  btVector3 result; // [esp+8A4h] [ebp-A0h] BYREF
  int v97; // [esp+8BCh] [ebp-88h]
  int v98; // [esp+8C0h] [ebp-84h]
  btConvexHullInternal v99; // [esp+8C4h] [ebp-80h] BYREF

  if ( count > 0 )
  {
    memset(&v99.vertexPool, 0, 12);
    v99.vertexPool.arraySize = 256;
    memset(&v99.edgePool, 0, 12);
    v99.edgePool.arraySize = 256;
    memset(&v99.facePool, 0, 12);
    v99.facePool.arraySize = 256;
    v99.originalVertices.m_ownsMemory = 1;
    memset(&v99.originalVertices.m_size, 0, 12);
    btConvexHullInternal::compute((btConvexHullInternal *)0x100, &v99, coords, count, v79, v80);
    m_size = this->vertices.m_size;
    if ( m_size <= 0 )
    {
      if ( m_size < 0 && this->vertices.m_capacity < 0 )
      {
        m_data = this->vertices.m_data;
        if ( m_data )
        {
          if ( this->vertices.m_ownsMemory )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(m_data);
          }
          this->vertices.m_data = 0;
        }
        this->vertices.m_ownsMemory = 1;
        this->vertices.m_data = 0;
        this->vertices.m_capacity = 0;
      }
      if ( m_size < 0 )
      {
        v14 = result.mVec128.m128_u64[1];
        v15 = result.mVec128.m128_u64[0];
        v16 = m_size;
        do
        {
          v17 = &this->vertices.m_data[v16];
          if ( v17 )
          {
            v17->mVec128.m128_u64[0] = v15;
            v17->mVec128.m128_u64[1] = v14;
          }
          ++v16;
        }
        while ( v16 < 0 );
      }
    }
    this->vertices.m_size = 0;
    v18 = this->edges.m_size;
    if ( v18 <= 0 )
    {
      if ( v18 < 0 && this->edges.m_capacity < 0 )
      {
        v19 = this->edges.m_data;
        if ( v19 )
        {
          if ( this->edges.m_ownsMemory )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v19);
          }
          this->edges.m_data = 0;
        }
        this->edges.m_ownsMemory = 1;
        this->edges.m_data = 0;
        this->edges.m_capacity = 0;
      }
      if ( v18 < 0 )
      {
        v20 = result.mVec128.m128_i32[2];
        v21 = result.mVec128.m128_u64[0];
        v22 = v18;
        do
        {
          v23 = &this->edges.m_data[v22];
          if ( v23 )
          {
            *(_QWORD *)&v23->next = v21;
            v23->targetVertex = v20;
          }
          ++v22;
        }
        while ( v22 < 0 );
      }
    }
    this->edges.m_size = 0;
    v24 = this->faces.m_size;
    if ( v24 <= 0 )
    {
      if ( v24 < 0 && this->faces.m_capacity < 0 )
      {
        v25 = this->faces.m_data;
        if ( v25 )
        {
          if ( this->faces.m_ownsMemory )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v25);
          }
          this->faces.m_data = 0;
        }
        this->faces.m_ownsMemory = 1;
        this->faces.m_data = 0;
        this->faces.m_capacity = 0;
      }
      if ( v24 < 0 )
      {
        v26 = v24;
        do
        {
          v27 = &this->faces.m_data[v26];
          if ( v27 )
            *v27 = 0;
          ++v26;
        }
        while ( v26 < 0 );
      }
    }
    vertexList = v99.vertexList;
    this->faces.m_size = 0;
    vertices.m_ownsMemory = 1;
    memset(&vertices.m_size, 0, 12);
    getVertexCopy(&vertices, vertexList);
    for ( i = 0; i < vertices.m_size; ++i )
    {
      v88 = vertices.m_data[i];
      v29 = v88;
      Coordinates = btConvexHullInternal::getCoordinates((btConvexHullInternal *)i, (int)&v99, &result, v88);
      m_capacity = this->vertices.m_capacity;
      v32 = Coordinates;
      v33 = this->vertices.m_size;
      v85 = v32;
      if ( v33 == m_capacity )
      {
        v34 = v33 ? 2 * v33 : 1;
        v81 = v34;
        if ( m_capacity < v34 )
        {
          if ( v34 )
          {
            ++gNumAlignedAllocs;
            v35 = (btVector3 *)sAlignedAllocFunc(16 * v34, 16);
          }
          else
          {
            v35 = 0;
          }
          if ( this->vertices.m_size > 0 )
          {
            v36 = 0;
            v37 = v35;
            v38 = this->vertices.m_size;
            do
            {
              if ( v37 )
              {
                v39 = this->vertices.m_data;
                v37->mVec128.m128_u64[0] = v39[v36].mVec128.m128_u64[0];
                v37->mVec128.m128_u64[1] = v39[v36].mVec128.m128_u64[1];
              }
              ++v36;
              ++v37;
              --v38;
            }
            while ( v38 );
          }
          v40 = this->vertices.m_data;
          if ( v40 )
          {
            if ( this->vertices.m_ownsMemory )
            {
              ++gNumAlignedFree;
              sAlignedFreeFunc(v40);
            }
            this->vertices.m_data = 0;
          }
          v32 = v85;
          this->vertices.m_data = v35;
          v29 = v88;
          this->vertices.m_ownsMemory = 1;
          this->vertices.m_capacity = v81;
        }
      }
      v41 = &this->vertices.m_data[this->vertices.m_size];
      if ( v41 )
      {
        v41->mVec128.m128_u64[0] = v32->mVec128.m128_u64[0];
        v41->mVec128.m128_u64[1] = v32->mVec128.m128_u64[1];
      }
      ++this->vertices.m_size;
      edges = (int)v29->edges;
      v98 = edges;
      if ( edges )
      {
        v42 = -1;
        v43 = -1;
        v89 = -1;
        v86 = -1;
        v91 = edges;
        do
        {
          if ( *(int *)(edges + 20) < 0 )
          {
            v45 = this->edges.m_capacity;
            v97 = this->edges.m_size;
            v44 = v97;
            if ( v97 == v45 )
            {
              v46 = v97 ? 2 * v97 : 1;
              v94 = v46;
              if ( v45 < v46 )
              {
                if ( v46 )
                {
                  ++gNumAlignedAllocs;
                  v82 = (btConvexHullComputer::Edge *)sAlignedAllocFunc(12 * v46, 16);
                }
                else
                {
                  v82 = 0;
                }
                if ( this->edges.m_size > 0 )
                {
                  v47 = v82;
                  v48 = 0;
                  v49 = this->edges.m_size;
                  do
                  {
                    if ( v47 )
                    {
                      v50 = this->edges.m_data;
                      *(_QWORD *)&v47->next = *(_QWORD *)&v50[v48].next;
                      v47->targetVertex = v50[v48].targetVertex;
                    }
                    ++v48;
                    ++v47;
                    --v49;
                  }
                  while ( v49 );
                }
                v51 = this->edges.m_data;
                if ( v51 )
                {
                  if ( this->edges.m_ownsMemory )
                  {
                    ++gNumAlignedFree;
                    sAlignedFreeFunc(v51);
                  }
                  this->edges.m_data = 0;
                }
                this->edges.m_ownsMemory = 1;
                this->edges.m_data = v82;
                this->edges.m_capacity = v94;
              }
            }
            v52 = &this->edges.m_data[this->edges.m_size];
            if ( v52 )
            {
              v53 = result.mVec128.m128_i32[2];
              *(_QWORD *)&v52->next = result.mVec128.m128_u64[0];
              v52->targetVertex = v53;
            }
            ++this->edges.m_size;
            v54 = this->edges.m_capacity;
            v55 = this->edges.m_size;
            if ( v55 == v54 )
            {
              v56 = 2 * v55;
              if ( !v55 )
                v56 = 1;
              if ( v54 < v56 )
              {
                if ( v56 )
                {
                  ++gNumAlignedAllocs;
                  v83 = (btConvexHullComputer::Edge *)sAlignedAllocFunc(12 * v56, 16);
                }
                else
                {
                  v83 = 0;
                }
                if ( this->edges.m_size > 0 )
                {
                  v57 = v83;
                  v58 = 0;
                  v59 = this->edges.m_size;
                  do
                  {
                    if ( v57 )
                    {
                      v60 = this->edges.m_data;
                      *(_QWORD *)&v57->next = *(_QWORD *)&v60[v58].next;
                      v57->targetVertex = v60[v58].targetVertex;
                    }
                    ++v58;
                    ++v57;
                    --v59;
                  }
                  while ( v59 );
                  v44 = v97;
                }
                v61 = this->edges.m_data;
                if ( v61 )
                {
                  if ( this->edges.m_ownsMemory )
                  {
                    ++gNumAlignedFree;
                    sAlignedFreeFunc(v61);
                  }
                  this->edges.m_data = 0;
                }
                this->edges.m_ownsMemory = 1;
                this->edges.m_data = v83;
                this->edges.m_capacity = v56;
              }
            }
            v62 = &this->edges.m_data[this->edges.m_size];
            if ( v62 )
            {
              v63 = result.mVec128.m128_i32[2];
              *(_QWORD *)&v62->next = result.mVec128.m128_u64[0];
              v62->targetVertex = v63;
            }
            ++this->edges.m_size;
            v64 = &this->edges.m_data[v44];
            v65 = *(_DWORD *)(v91 + 8);
            *(_DWORD *)(v91 + 20) = v44;
            *(_DWORD *)(v65 + 20) = v44 + 1;
            v64->reverse = 1;
            v64[1].reverse = -1;
            v42 = v89;
            v64->targetVertex = getVertexCopy(&vertices, *(btConvexHullInternal::Vertex **)(v91 + 12));
            v43 = v86;
            v64[1].targetVertex = i;
            edges = v91;
          }
          if ( v43 < 0 )
          {
            v42 = *(_DWORD *)(edges + 20);
            v89 = v42;
          }
          else
          {
            this->edges.m_data[*(_DWORD *)(edges + 20)].next = v43 - *(_DWORD *)(edges + 20);
          }
          v43 = *(_DWORD *)(edges + 20);
          edges = *(_DWORD *)edges;
          v86 = v43;
          v91 = edges;
        }
        while ( edges != v98 );
        edges = 3 * v42;
        this->edges.m_data[v42].next = v43 - v42;
      }
    }
    for ( j = 0; j < i; ++j )
    {
      edges = j;
      v90 = vertices.m_data[j]->edges;
      if ( v90 )
      {
        v66 = vertices.m_data[j]->edges;
        v87 = v66;
        do
        {
          if ( v66->copy >= 0 )
          {
            edges = this->faces.m_capacity;
            v67 = this->faces.m_size;
            if ( v67 == edges )
            {
              v68 = 2 * v67;
              if ( !v67 )
                v68 = 1;
              if ( edges < v68 )
              {
                if ( v68 )
                {
                  ++gNumAlignedAllocs;
                  v92 = (int *)sAlignedAllocFunc(4 * v68, 16);
                }
                else
                {
                  v92 = 0;
                }
                v69 = this->faces.m_size;
                v70 = 0;
                if ( v69 > 0 )
                {
                  v71 = v92;
                  do
                  {
                    if ( v71 )
                    {
                      *v71 = this->faces.m_data[v70];
                      v66 = v87;
                    }
                    ++v70;
                    ++v71;
                  }
                  while ( v70 < v69 );
                }
                v72 = this->faces.m_data;
                if ( v72 )
                {
                  if ( this->faces.m_ownsMemory )
                  {
                    ++gNumAlignedFree;
                    sAlignedFreeFunc(v72);
                  }
                  this->faces.m_data = 0;
                }
                edges = (int)v92;
                this->faces.m_ownsMemory = 1;
                this->faces.m_data = v92;
                this->faces.m_capacity = v68;
              }
            }
            v73 = &this->faces.m_data[this->faces.m_size];
            if ( v73 )
            {
              edges = v66->copy;
              *v73 = edges;
            }
            ++this->faces.m_size;
            prev = v66;
            do
            {
              reverse = prev->reverse;
              prev->copy = -1;
              prev = reverse->prev;
            }
            while ( prev != v66 );
          }
          v66 = v66->next;
          v87 = v66;
        }
        while ( v66 != v90 );
      }
    }
    if ( vertices.m_data && vertices.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(vertices.m_data);
    }
    if ( v99.originalVertices.m_data && v99.originalVertices.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v99.originalVertices.m_data);
    }
    v99.originalVertices.m_ownsMemory = 1;
    memset(&v99.originalVertices.m_size, 0, 12);
    btConvexHullInternal::Pool<btConvexHullInternal::Face>::~Pool<btConvexHullInternal::Face>(
      (btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *)edges,
      (void ***)&v99.facePool);
    btConvexHullInternal::Pool<btConvexHullInternal::Face>::~Pool<btConvexHullInternal::Face>(
      v76,
      (void ***)&v99.edgePool);
    btConvexHullInternal::Pool<btConvexHullInternal::Face>::~Pool<btConvexHullInternal::Face>(
      v77,
      (void ***)&v99.vertexPool);
    return 0;
  }
  else
  {
    v8 = this->vertices.m_data;
    if ( v8 )
    {
      if ( this->vertices.m_ownsMemory )
      {
        ++gNumAlignedFree;
        sAlignedFreeFunc(v8);
      }
      this->vertices.m_data = 0;
    }
    this->vertices.m_ownsMemory = 1;
    this->vertices.m_data = 0;
    this->vertices.m_size = 0;
    this->vertices.m_capacity = 0;
    v9 = this->edges.m_data;
    if ( v9 )
    {
      if ( this->edges.m_ownsMemory )
      {
        ++gNumAlignedFree;
        sAlignedFreeFunc(v9);
      }
      this->edges.m_data = 0;
    }
    this->edges.m_ownsMemory = 1;
    this->edges.m_data = 0;
    this->edges.m_size = 0;
    this->edges.m_capacity = 0;
    v10 = this->faces.m_data;
    if ( v10 )
    {
      if ( this->faces.m_ownsMemory )
      {
        ++gNumAlignedFree;
        sAlignedFreeFunc(v10);
      }
      this->faces.m_data = 0;
    }
    v11 = 0;
    this->faces.m_ownsMemory = 1;
    this->faces.m_data = 0;
    this->faces.m_size = 0;
    this->faces.m_capacity = 0;
  }
  return v11;
}
