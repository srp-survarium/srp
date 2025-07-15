void __userpurge btConvexHullComputer::compute(
        btConvexHullComputer *this@<ecx>,
        const void *coords,
        int doubleCoords,
        int stride,
        int count,
        float shrink,
        float shrinkClamp)
{
  int v7; // esi
  int v8; // ecx
  btVector3 *v9; // eax
  int v10; // esi
  int v11; // ecx
  int v12; // eax
  int v13; // esi
  int v14; // ecx
  _DWORD *v15; // eax
  btConvexHullInternal::Vertex **edges; // ecx
  btVector3 *Coordinates; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // esi
  int v21; // eax
  _DWORD *v22; // ecx
  int v23; // edx
  _DWORD *v24; // esi
  _DWORD *v25; // edi
  _DWORD *v26; // edi
  int v27; // esi
  int v28; // eax
  btConvexHullInternal::Vertex *v29; // eax
  int v30; // ecx
  int v31; // esi
  int v32; // eax
  _DWORD *v33; // ecx
  int v34; // edx
  _DWORD *v35; // esi
  int v36; // edi
  int v37; // ecx
  int v38; // eax
  int v39; // esi
  int v40; // eax
  _DWORD *v41; // ecx
  int v42; // edx
  _DWORD *v43; // esi
  int v44; // edi
  btConvexHullInternal::Vertex *v45; // ecx
  _DWORD *v46; // edi
  btConvexHullInternal::Vertex *v47; // edx
  int v48; // eax
  btConvexHullInternal::Edge *v49; // edx
  int v50; // ecx
  int v51; // eax
  int v52; // esi
  int v53; // edx
  int v54; // eax
  _DWORD *v55; // ecx
  btConvexHullInternal::Vertex ***v56; // eax
  btConvexHullInternal::Edge *prev; // eax
  btAlignedObjectArray<GrahamVector2> *v58; // ecx
  btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *v59; // ecx
  btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *v60; // ecx
  btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *v61; // ecx
  btConvexHullInternal::Vertex *vertexList; // [esp-4h] [ebp-D4h]
  btConvexHullInternal::Vertex **v63; // [esp-4h] [ebp-D4h]
  int v64; // [esp+0h] [ebp-D0h]
  __m128 *p_mVec128; // [esp+Ch] [ebp-C4h]
  int v66; // [esp+Ch] [ebp-C4h]
  int v67; // [esp+Ch] [ebp-C4h]
  _DWORD *v68; // [esp+10h] [ebp-C0h]
  _DWORD *v69; // [esp+10h] [ebp-C0h]
  _DWORD *v70; // [esp+10h] [ebp-C0h]
  int v71; // [esp+14h] [ebp-BCh]
  btConvexHullInternal::Vertex **v72; // [esp+14h] [ebp-BCh]
  _DWORD *v73; // [esp+14h] [ebp-BCh]
  int v74; // [esp+18h] [ebp-B8h]
  int v75; // [esp+18h] [ebp-B8h]
  int j; // [esp+18h] [ebp-B8h]
  int i; // [esp+1Ch] [ebp-B4h]
  btConvexHullInternal::Vertex *v78; // [esp+20h] [ebp-B0h]
  int v79; // [esp+20h] [ebp-B0h]
  btConvexHullInternal::Edge *v80; // [esp+20h] [ebp-B0h]
  btConvexHullInternal::Vertex **v81; // [esp+24h] [ebp-ACh]
  btConvexHullInternal::Edge *v82; // [esp+24h] [ebp-ACh]
  btAlignedObjectArray<btConvexHullInternal::Vertex *> v83; // [esp+28h] [ebp-A8h] BYREF
  btConvexHullInternal::Vertex *v84; // [esp+3Ch] [ebp-94h]
  btVector3 v85; // [esp+40h] [ebp-90h] BYREF
  btConvexHullInternal v86; // [esp+50h] [ebp-80h] BYREF

  if ( stride > 0 )
  {
    v86.vertexPool.arraySize = 256;
    v86.edgePool.arraySize = 256;
    v86.facePool.arraySize = 256;
    memset(&v86.vertexPool, 0, 12);
    memset(&v86.edgePool, 0, 12);
    memset(&v86.facePool, 0, 12);
    v86.originalVertices.m_ownsMemory = 1;
    memset(&v86.originalVertices.m_size, 0, 12);
    btConvexHullInternal::compute((btConvexHullInternal *)this, &v86, doubleCoords, stride, v64);
    v7 = *((_DWORD *)coords + 1);
    if ( v7 <= 0 )
    {
      if ( v7 < 0 && *((int *)coords + 2) < 0 )
      {
        if ( *((_DWORD *)coords + 3) )
        {
          if ( *((_BYTE *)coords + 16) )
            btAlignedFreeInternal(*((void **)coords + 3));
          *((_DWORD *)coords + 3) = 0;
        }
        *((_BYTE *)coords + 16) = 1;
        *((_DWORD *)coords + 3) = 0;
        *((_DWORD *)coords + 2) = 0;
      }
      if ( v7 < 0 )
      {
        v8 = 16 * v7;
        do
        {
          v9 = (btVector3 *)(v8 + *((_DWORD *)coords + 3));
          if ( v9 )
            *v9 = (btVector3)v85.mVec128;
          v8 += 16;
        }
        while ( v8 < 0 );
      }
    }
    *((_DWORD *)coords + 1) = 0;
    v10 = *((_DWORD *)coords + 6);
    if ( v10 <= 0 )
    {
      if ( v10 < 0 && *((int *)coords + 7) < 0 )
      {
        if ( *((_DWORD *)coords + 8) )
        {
          if ( *((_BYTE *)coords + 36) )
            btAlignedFreeInternal(*((void **)coords + 8));
          *((_DWORD *)coords + 8) = 0;
        }
        *((_BYTE *)coords + 36) = 1;
        *((_DWORD *)coords + 8) = 0;
        *((_DWORD *)coords + 7) = 0;
      }
      if ( v10 < 0 )
      {
        v11 = 12 * v10;
        do
        {
          v12 = v11 + *((_DWORD *)coords + 8);
          if ( v12 )
          {
            *(_QWORD *)v12 = v85.mVec128.m128_u64[0];
            *(_DWORD *)(v12 + 8) = v85.mVec128.m128_i32[2];
          }
          v11 += 12;
        }
        while ( v11 < 0 );
      }
    }
    *((_DWORD *)coords + 6) = 0;
    v13 = *((_DWORD *)coords + 11);
    if ( v13 <= 0 )
    {
      if ( v13 < 0 && *((int *)coords + 12) < 0 )
      {
        if ( *((_DWORD *)coords + 13) )
        {
          if ( *((_BYTE *)coords + 56) )
            btAlignedFreeInternal(*((void **)coords + 13));
          *((_DWORD *)coords + 13) = 0;
        }
        *((_BYTE *)coords + 56) = 1;
        *((_DWORD *)coords + 13) = 0;
        *((_DWORD *)coords + 12) = 0;
      }
      if ( v13 < 0 )
      {
        v14 = 4 * v13;
        do
        {
          v15 = (_DWORD *)(v14 + *((_DWORD *)coords + 13));
          if ( v15 )
            *v15 = 0;
          v14 += 4;
        }
        while ( v14 < 0 );
      }
    }
    vertexList = v86.vertexList;
    *((_DWORD *)coords + 11) = 0;
    v83.m_ownsMemory = 1;
    memset(&v83.m_size, 0, 12);
    getVertexCopy(&v83, vertexList);
    edges = v63;
    for ( i = 0; i < v83.m_size; ++i )
    {
      v78 = v83.m_data[i];
      Coordinates = btConvexHullInternal::getCoordinates(&v86, v78, &v85);
      v18 = *((_DWORD *)coords + 2);
      p_mVec128 = &Coordinates->mVec128;
      v19 = *((_DWORD *)coords + 1);
      if ( v19 == v18 )
      {
        v20 = v19 ? 2 * v19 : 1;
        v71 = v20;
        if ( v18 < v20 )
        {
          if ( v20 )
            v68 = btAlignedAllocInternal(16 * v20);
          else
            v68 = 0;
          v21 = *((_DWORD *)coords + 1);
          if ( v21 > 0 )
          {
            v22 = v68;
            v23 = 0;
            do
            {
              if ( v22 )
              {
                v24 = (_DWORD *)(v23 + *((_DWORD *)coords + 3));
                *v22 = *v24++;
                v22[1] = *v24++;
                v22[2] = *v24;
                v22[3] = v24[1];
                v20 = v71;
              }
              v23 += 16;
              v22 += 4;
              --v21;
            }
            while ( v21 );
          }
          if ( *((_DWORD *)coords + 3) )
          {
            if ( *((_BYTE *)coords + 16) )
              btAlignedFreeInternal(*((void **)coords + 3));
            *((_DWORD *)coords + 3) = 0;
          }
          *((_BYTE *)coords + 16) = 1;
          *((_DWORD *)coords + 3) = v68;
          *((_DWORD *)coords + 2) = v20;
        }
      }
      v25 = (_DWORD *)(*((_DWORD *)coords + 3) + 16 * *((_DWORD *)coords + 1));
      if ( v25 )
      {
        *v25 = p_mVec128->m128_i32[0];
        v26 = v25 + 1;
        *v26++ = p_mVec128->m128_i32[1];
        *v26 = p_mVec128->m128_i32[2];
        v26[1] = p_mVec128->m128_i32[3];
      }
      ++*((_DWORD *)coords + 1);
      edges = (btConvexHullInternal::Vertex **)v78->edges;
      v81 = edges;
      if ( edges )
      {
        v27 = -1;
        v79 = -1;
        v28 = -1;
        v66 = -1;
        v72 = edges;
        do
        {
          if ( (int)edges[5] < 0 )
          {
            v29 = (btConvexHullInternal::Vertex *)*((_DWORD *)coords + 6);
            v30 = *((_DWORD *)coords + 7);
            v84 = v29;
            if ( v29 == (btConvexHullInternal::Vertex *)v30 )
            {
              v31 = v29 ? 2 * (_DWORD)v29 : 1;
              v74 = v31;
              if ( v30 < v31 )
              {
                if ( v31 )
                  v69 = btAlignedAllocInternal(12 * v31);
                else
                  v69 = 0;
                v32 = *((_DWORD *)coords + 6);
                if ( v32 > 0 )
                {
                  v33 = v69;
                  v34 = 0;
                  do
                  {
                    if ( v33 )
                    {
                      v35 = (_DWORD *)(v34 + *((_DWORD *)coords + 8));
                      *v33 = *v35++;
                      v33[1] = *v35;
                      v33[2] = v35[1];
                      v31 = v74;
                    }
                    v34 += 12;
                    v33 += 3;
                    --v32;
                  }
                  while ( v32 );
                }
                if ( *((_DWORD *)coords + 8) )
                {
                  if ( *((_BYTE *)coords + 36) )
                    btAlignedFreeInternal(*((void **)coords + 8));
                  *((_DWORD *)coords + 8) = 0;
                }
                *((_BYTE *)coords + 36) = 1;
                *((_DWORD *)coords + 8) = v69;
                *((_DWORD *)coords + 7) = v31;
              }
            }
            v36 = *((_DWORD *)coords + 8) + 12 * *((_DWORD *)coords + 6);
            if ( v36 )
            {
              *(_DWORD *)v36 = v85.mVec128.m128_i32[0];
              *(_QWORD *)(v36 + 4) = *(unsigned __int64 *)((char *)v85.mVec128.m128_u64 + 4);
            }
            ++*((_DWORD *)coords + 6);
            v37 = *((_DWORD *)coords + 7);
            v38 = *((_DWORD *)coords + 6);
            if ( v38 == v37 )
            {
              v39 = v38 ? 2 * v38 : 1;
              v75 = v39;
              if ( v37 < v39 )
              {
                if ( v39 )
                  v70 = btAlignedAllocInternal(12 * v39);
                else
                  v70 = 0;
                v40 = *((_DWORD *)coords + 6);
                if ( v40 > 0 )
                {
                  v41 = v70;
                  v42 = 0;
                  do
                  {
                    if ( v41 )
                    {
                      v43 = (_DWORD *)(v42 + *((_DWORD *)coords + 8));
                      *v41 = *v43++;
                      v41[1] = *v43;
                      v41[2] = v43[1];
                      v39 = v75;
                    }
                    v42 += 12;
                    v41 += 3;
                    --v40;
                  }
                  while ( v40 );
                }
                if ( *((_DWORD *)coords + 8) )
                {
                  if ( *((_BYTE *)coords + 36) )
                    btAlignedFreeInternal(*((void **)coords + 8));
                  *((_DWORD *)coords + 8) = 0;
                }
                *((_BYTE *)coords + 36) = 1;
                *((_DWORD *)coords + 8) = v70;
                *((_DWORD *)coords + 7) = v39;
              }
            }
            v44 = *((_DWORD *)coords + 8) + 12 * *((_DWORD *)coords + 6);
            if ( v44 )
            {
              *(_DWORD *)v44 = v85.mVec128.m128_i32[0];
              *(_QWORD *)(v44 + 4) = *(unsigned __int64 *)((char *)v85.mVec128.m128_u64 + 4);
            }
            v45 = v84;
            ++*((_DWORD *)coords + 6);
            v46 = (_DWORD *)(12 * (_DWORD)v45 + *((_DWORD *)coords + 8));
            v47 = v72[2];
            v72[5] = v45;
            *((_DWORD *)&v47->lastNearbyFace + 1) = (char *)&v45->next + 1;
            v46[1] = 1;
            v46[4] = -1;
            v27 = v79;
            v46[2] = getVertexCopy(&v83, v72[3]);
            edges = v72;
            v46[5] = i;
            v28 = v66;
          }
          if ( v28 < 0 )
          {
            v27 = (int)edges[5];
            v79 = v27;
          }
          else
          {
            *(_DWORD *)(12 * (_DWORD)edges[5] + *((_DWORD *)coords + 8)) = v28 - (_DWORD)edges[5];
          }
          v28 = (int)edges[5];
          edges = (btConvexHullInternal::Vertex **)*edges;
          v66 = v28;
          v72 = edges;
        }
        while ( edges != v81 );
        edges = (btConvexHullInternal::Vertex **)*((_DWORD *)coords + 8);
        edges[3 * v27] = (btConvexHullInternal::Vertex *)(v28 - v27);
      }
    }
    v48 = 0;
    for ( j = 0; j < i; ++j )
    {
      edges = v83.m_data;
      v49 = v83.m_data[v48]->edges;
      v82 = v49;
      if ( v49 )
      {
        v80 = v83.m_data[v48]->edges;
        do
        {
          if ( v49->copy >= 0 )
          {
            v50 = *((_DWORD *)coords + 12);
            v51 = *((_DWORD *)coords + 11);
            if ( v51 == v50 )
            {
              v52 = v51 ? 2 * v51 : 1;
              v67 = v52;
              if ( v50 < v52 )
              {
                if ( v52 )
                  v73 = btAlignedAllocInternal(4 * v52);
                else
                  v73 = 0;
                v53 = *((_DWORD *)coords + 11);
                v54 = 0;
                if ( v53 > 0 )
                {
                  v55 = v73;
                  do
                  {
                    if ( v55 )
                    {
                      *v55 = *(_DWORD *)(*((_DWORD *)coords + 13) + 4 * v54);
                      v52 = v67;
                    }
                    ++v54;
                    ++v55;
                  }
                  while ( v54 < v53 );
                }
                if ( *((_DWORD *)coords + 13) )
                {
                  if ( *((_BYTE *)coords + 56) )
                    btAlignedFreeInternal(*((void **)coords + 13));
                  *((_DWORD *)coords + 13) = 0;
                }
                v49 = v80;
                *((_BYTE *)coords + 56) = 1;
                *((_DWORD *)coords + 13) = v73;
                *((_DWORD *)coords + 12) = v52;
              }
            }
            edges = (btConvexHullInternal::Vertex **)*((_DWORD *)coords + 13);
            v56 = (btConvexHullInternal::Vertex ***)&edges[*((_DWORD *)coords + 11)];
            if ( v56 )
            {
              edges = (btConvexHullInternal::Vertex **)v49->copy;
              *v56 = edges;
            }
            ++*((_DWORD *)coords + 11);
            prev = v49;
            do
            {
              prev->copy = -1;
              prev = prev->reverse->prev;
            }
            while ( prev != v49 );
          }
          v49 = v49->next;
          v80 = v49;
        }
        while ( v49 != v82 );
      }
      v48 = j + 1;
    }
    btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
      (btAlignedObjectArray<GrahamVector2> *)edges,
      (int)&v83);
    btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v58, (int)&v86.originalVertices);
    btConvexHullInternal::Pool<btConvexHullInternal::Face>::~Pool<btConvexHullInternal::Face>(
      v59,
      (void ***)&v86.facePool);
    btConvexHullInternal::Pool<btConvexHullInternal::Face>::~Pool<btConvexHullInternal::Face>(
      v60,
      (void ***)&v86.edgePool);
    btConvexHullInternal::Pool<btConvexHullInternal::Face>::~Pool<btConvexHullInternal::Face>(
      v61,
      (void ***)&v86.vertexPool);
  }
  else
  {
    if ( *((_DWORD *)coords + 3) )
    {
      if ( *((_BYTE *)coords + 16) )
        btAlignedFreeInternal(*((void **)coords + 3));
      *((_DWORD *)coords + 3) = 0;
    }
    *((_BYTE *)coords + 16) = 1;
    *((_DWORD *)coords + 3) = 0;
    *((_DWORD *)coords + 1) = 0;
    *((_DWORD *)coords + 2) = 0;
    if ( *((_DWORD *)coords + 8) )
    {
      if ( *((_BYTE *)coords + 36) )
        btAlignedFreeInternal(*((void **)coords + 8));
      *((_DWORD *)coords + 8) = 0;
    }
    *((_BYTE *)coords + 36) = 1;
    *((_DWORD *)coords + 8) = 0;
    *((_DWORD *)coords + 6) = 0;
    *((_DWORD *)coords + 7) = 0;
    if ( *((_DWORD *)coords + 13) )
    {
      if ( *((_BYTE *)coords + 56) )
        btAlignedFreeInternal(*((void **)coords + 13));
      *((_DWORD *)coords + 13) = 0;
    }
    *((_BYTE *)coords + 56) = 1;
    *((_DWORD *)coords + 13) = 0;
    *((_DWORD *)coords + 11) = 0;
    *((_DWORD *)coords + 12) = 0;
  }
}
