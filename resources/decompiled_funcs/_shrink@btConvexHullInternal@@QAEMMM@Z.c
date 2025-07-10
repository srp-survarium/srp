float __userpurge btConvexHullInternal::shrink@<st0>(
        btConvexHullInternal *this@<ecx>,
        btConvexHullInternal *clampAmount,
        float hullCenterX)
{
  btConvexHullInternal::Vertex *vertexList; // eax
  int v4; // ecx
  btConvexHullInternal::Vertex **v5; // eax
  btConvexHullInternal::Vertex *v6; // eax
  btConvexHullInternal::Vertex *v7; // ecx
  btConvexHullInternal::Edge *edges; // ebx
  btConvexHullInternal::Vertex *target; // eax
  int v10; // edx
  int m_size; // ecx
  int v12; // edi
  btConvexHullInternal::Vertex **v13; // esi
  int v14; // ecx
  btConvexHullInternal::Vertex **v15; // eax
  char *v16; // edx
  btConvexHullInternal::Vertex **v17; // eax
  btConvexHullInternal::Face *v18; // esi
  btConvexHullInternal::Vertex *v19; // eax
  int v20; // edi
  _DWORD *v21; // esi
  int v22; // ecx
  _DWORD *v23; // eax
  char *v24; // edx
  btConvexHullInternal::Face **v25; // eax
  btConvexHullInternal::Vertex *v26; // edi
  btConvexHullInternal::Edge *prev; // eax
  btConvexHullInternal::Vertex *v28; // ecx
  int v29; // esi
  int v30; // ebx
  int v31; // ecx
  int v32; // esi
  __int64 v33; // rax
  int v34; // ecx
  int v35; // ecx
  int v36; // esi
  int v37; // ebx
  int v38; // edi
  signed __int64 v39; // rax
  int v40; // ecx
  unsigned __int64 v41; // rax
  signed __int64 v42; // rax
  int v43; // ecx
  int v44; // edi
  unsigned __int64 v45; // rax
  signed __int64 v46; // rax
  int v47; // edi
  int v48; // ebx
  unsigned __int64 v49; // rax
  int v50; // ebx
  unsigned __int64 v51; // kr10_8
  bool v52; // cf
  btConvexHullInternal::Vertex **m_data; // eax
  double v54; // st7
  int v55; // edi
  _DWORD *v56; // ebx
  int v57; // ecx
  unsigned int v58; // esi
  int v59; // edx
  int v60; // edi
  _DWORD *v61; // eax
  int v62; // edx
  bool v63; // cc
  int v64; // edi
  btConvexHullInternal *v65; // ecx
  btAlignedObjectArray<btConvexHullInternal::Vertex *> v67; // [esp+A68h] [ebp-144h] BYREF
  unsigned __int64 v68; // [esp+A94h] [ebp-118h]
  __int64 v69; // [esp+A9Ch] [ebp-110h]
  btAlignedObjectArray<btConvexHullInternal::Vertex *> otherArray; // [esp+AA4h] [ebp-108h] BYREF
  int v71; // [esp+ABCh] [ebp-F0h]
  int v72; // [esp+AC0h] [ebp-ECh]
  void *ptr; // [esp+AC4h] [ebp-E8h]
  btConvexHullInternal::Vertex *v74; // [esp+ACCh] [ebp-E0h]
  btConvexHullInternal::Edge *v75; // [esp+AD0h] [ebp-DCh]
  btConvexHullInternal::Int128 v76; // [esp+AD4h] [ebp-D8h] BYREF
  btConvexHullInternal::Int128 v77; // [esp+AE4h] [ebp-C8h] BYREF
  btConvexHullInternal::Int128 v78; // [esp+AF4h] [ebp-B8h] BYREF
  btConvexHullInternal::Vertex *v79; // [esp+B04h] [ebp-A8h]
  int v80; // [esp+B08h] [ebp-A4h]
  __int64 v81; // [esp+B0Ch] [ebp-A0h]
  __int64 v82; // [esp+B14h] [ebp-98h]
  unsigned int v83; // [esp+B1Ch] [ebp-90h]
  btConvexHullInternal::Edge *v84; // [esp+B24h] [ebp-88h]
  btConvexHullInternal::Face *v85; // [esp+B28h] [ebp-84h]
  __int64 v86; // [esp+B2Ch] [ebp-80h]
  __int64 v87; // [esp+B34h] [ebp-78h]
  __int64 v88; // [esp+B3Ch] [ebp-70h]
  int v89; // [esp+B44h] [ebp-68h]
  float v90[3]; // [esp+B4Ch] [ebp-60h]
  int v91; // [esp+B58h] [ebp-54h]
  int v92; // [esp+B5Ch] [ebp-50h]
  int v93; // [esp+B64h] [ebp-48h]
  int v94; // [esp+B70h] [ebp-3Ch]
  int v95; // [esp+B74h] [ebp-38h]
  int v96; // [esp+B80h] [ebp-2Ch]
  int v97; // [esp+B98h] [ebp-14h]
  int v98; // [esp+BA4h] [ebp-8h]

  vertexList = clampAmount->vertexList;
  if ( vertexList )
  {
    v4 = --clampAmount->mergeStamp;
    ++gNumAlignedAllocs;
    *(_QWORD *)&v67.m_data = 0x1000000004LL;
    v80 = v4;
    vertexList->copy = v4;
    v5 = (btConvexHullInternal::Vertex **)sAlignedAllocFunc((unsigned int)v67.m_data, *(int *)&v67.m_ownsMemory);
    otherArray.m_ownsMemory = 1;
    otherArray.m_data = v5;
    otherArray.m_capacity = 1;
    if ( v5 )
      *v5 = clampAmount->vertexList;
    v6 = clampAmount->vertexList;
    v81 = *(_QWORD *)&v6->point.x;
    otherArray.m_size = 1;
    ptr = 0;
    v71 = 0;
    v72 = 0;
    v82 = *(_QWORD *)&v6->point.z;
    memset(&v78, 0, sizeof(v78));
    memset(&v76, 0, sizeof(v76));
    memset(&v77, 0, sizeof(v77));
    v68 = 0;
    v69 = 0;
    do
    {
      v7 = otherArray.m_data[otherArray.m_size - 1];
      edges = v7->edges;
      v79 = v7;
      --otherArray.m_size;
      v75 = edges;
      if ( edges )
      {
        do
        {
          target = edges->target;
          v10 = v80;
          if ( target->copy != v80 )
          {
            m_size = otherArray.m_size;
            target->copy = v80;
            if ( m_size == otherArray.m_capacity )
            {
              v12 = 2 * m_size;
              if ( !m_size )
                v12 = 1;
              if ( otherArray.m_capacity < v12 )
              {
                if ( v12 )
                {
                  ++gNumAlignedAllocs;
                  v13 = (btConvexHullInternal::Vertex **)sAlignedAllocFunc(4 * v12, 16);
                }
                else
                {
                  v13 = 0;
                }
                if ( otherArray.m_size > 0 )
                {
                  v14 = otherArray.m_size;
                  v15 = v13;
                  v16 = (char *)((char *)otherArray.m_data - (char *)v13);
                  do
                  {
                    if ( v15 )
                    {
                      *v15 = *(btConvexHullInternal::Vertex **)((char *)v15 + (_DWORD)v16);
                      edges = v75;
                    }
                    ++v15;
                    --v14;
                  }
                  while ( v14 );
                }
                if ( otherArray.m_data )
                {
                  ++gNumAlignedFree;
                  sAlignedFreeFunc(otherArray.m_data);
                }
                v10 = v80;
                m_size = otherArray.m_size;
                otherArray.m_ownsMemory = 1;
                otherArray.m_data = v13;
                otherArray.m_capacity = v12;
              }
            }
            v17 = &otherArray.m_data[m_size];
            if ( v17 )
              *v17 = edges->target;
            v7 = (btConvexHullInternal::Vertex *)(m_size + 1);
            otherArray.m_size = (int)v7;
          }
          if ( edges->copy != v10 )
          {
            v18 = btConvexHullInternal::Pool<btConvexHullInternal::Face>::newObject(
                    (btConvexHullInternal::Pool<btConvexHullInternal::Face> *)v7,
                    &clampAmount->facePool.arrays);
            *(_DWORD *)&v67.m_ownsMemory = edges->reverse->prev->target;
            v19 = edges->target;
            v85 = v18;
            btConvexHullInternal::Face::init(v19, v79, v18, *(btConvexHullInternal::Vertex **)&v67.m_ownsMemory);
            if ( v71 == v72 )
            {
              v20 = 2 * v71;
              if ( !v71 )
                v20 = 1;
              if ( v72 < v20 )
              {
                if ( v20 )
                {
                  ++gNumAlignedAllocs;
                  v21 = sAlignedAllocFunc(4 * v20, 16);
                }
                else
                {
                  v21 = 0;
                }
                if ( v71 > 0 )
                {
                  v22 = v71;
                  v23 = v21;
                  v24 = (char *)((_BYTE *)ptr - (_BYTE *)v21);
                  do
                  {
                    if ( v23 )
                    {
                      *v23 = *(_DWORD *)((char *)v23 + (_DWORD)v24);
                      edges = v75;
                    }
                    ++v23;
                    --v22;
                  }
                  while ( v22 );
                }
                if ( ptr )
                {
                  ++gNumAlignedFree;
                  sAlignedFreeFunc(ptr);
                }
                ptr = v21;
                v18 = v85;
                v72 = v20;
              }
            }
            v25 = (btConvexHullInternal::Face **)((char *)ptr + 4 * v71);
            if ( v25 )
              *v25 = v18;
            ++v71;
            v26 = 0;
            prev = edges;
            v28 = 0;
            v84 = edges;
            v74 = 0;
            do
            {
              if ( v26 && v28 )
              {
                v29 = v26->point.x - v81;
                v30 = v74->point.x - v81;
                v96 = v74->point.y - HIDWORD(v81);
                v31 = v74->point.z - v82;
                v92 = v29;
                v32 = v26->point.y - HIDWORD(v81);
                v93 = v26->point.z - v82;
                v33 = v31 * v32 - v96 * v93;
                v86 = v33;
                LODWORD(v33) = v30 * v93 - v92 * v31;
                v34 = v79->point.y - HIDWORD(v81);
                v87 = (int)v33;
                v94 = v34;
                v35 = v79->point.z - v82;
                v88 = v92 * v96 - v30 * v32;
                LODWORD(v33) = v79->point.x - v81;
                v95 = v35;
                v89 = v35 * v88 + v33 * v86;
                *(_QWORD *)&v67.m_data = v87;
                *(_QWORD *)&v67.m_size = v94;
                v36 = (v94 * v87 + v35 * v88 + (int)v33 * __PAIR64__(HIDWORD(v33), v86)) >> 32;
                v83 = v94 * v87 + v89;
                v37 = v26->point.x + v79->point.x + v74->point.x;
                HIDWORD(v33) = v79->point.z + v26->point.z + v74->point.z;
                v38 = v79->point.y + v26->point.y + v74->point.y + HIDWORD(v81);
                v98 = v82 + HIDWORD(v33);
                *(_QWORD *)&v67.m_data = __PAIR64__(v36, v83);
                v39 = ((int)v81 + v37) * __PAIR64__(v36, v83);
                if ( v39 < 0 )
                {
                  v40 = -1;
                  v97 = -1;
                }
                else
                {
                  v40 = 0;
                  v97 = 0;
                }
                v41 = v78.low + v39;
                if ( v41 < v78.low )
                  ++v78.high;
                v78.high += __PAIR64__(v97, v40);
                v78.low = v41;
                *(_QWORD *)&v67.m_data = __PAIR64__(v36, v83);
                *(_QWORD *)&v67.m_size = v38;
                v42 = v38 * __PAIR64__(v36, v83);
                if ( v42 < 0 )
                {
                  v43 = -1;
                  v44 = -1;
                }
                else
                {
                  v43 = 0;
                  v44 = 0;
                }
                v45 = v76.low + v42;
                if ( v45 < v76.low )
                  ++v76.high;
                v76.low = v45;
                v76.high += __PAIR64__(v44, v43);
                *(_QWORD *)&v67.m_data = __PAIR64__(v36, v83);
                *(_QWORD *)&v67.m_size = v98;
                v46 = v98 * __PAIR64__(v36, v83);
                if ( v46 < 0 )
                {
                  v47 = -1;
                  v48 = -1;
                }
                else
                {
                  v47 = 0;
                  v48 = 0;
                }
                v49 = v77.low + v46;
                if ( v49 < v77.low )
                  ++v77.high;
                v77.low = v49;
                v77.high += __PAIR64__(v48, v47);
                v50 = 0;
                if ( v36 < 0 )
                  v50 = -1;
                v51 = __PAIR64__(v36, v83) + v68;
                v91 = v50;
                if ( __PAIR64__(v36, v83) + v68 < v68 )
                  ++v69;
                v52 = __CFADD__(v50, (_DWORD)v69);
                LODWORD(v69) = v50 + v69;
                edges = v75;
                HIDWORD(v69) += v91 + v52;
                v18 = v85;
                v68 = v51;
                v28 = v74;
                prev = v84;
              }
              prev->copy = v80;
              prev->face = v18;
              v26 = v28;
              v28 = prev->target;
              prev = prev->reverse->prev;
              v74 = v28;
              v84 = prev;
            }
            while ( prev != edges );
          }
          edges = edges->next;
          v7 = v79;
          v75 = edges;
        }
        while ( edges != v79->edges );
      }
    }
    while ( otherArray.m_size > 0 );
    if ( v69 >= 0 && (v69 || v68) )
    {
      v90[clampAmount->medAxis] = btConvexHullInternal::Int128::toScalar(&v78);
      v90[clampAmount->maxAxis] = btConvexHullInternal::Int128::toScalar(&v76);
      v54 = btConvexHullInternal::Int128::toScalar(&v77);
      v55 = v71;
      v90[clampAmount->minAxis] = v54;
      v56 = ptr;
      v57 = 0;
      v58 = (unsigned int)&loc_3B7F4 + 3;
      if ( v55 > 0 )
      {
        do
        {
          v59 = v58 % v55;
          v60 = v56[v58 % v55];
          ++v57;
          v58 = 1664525 * v58 + 1013904223;
          v61 = &v56[v59];
          v62 = v56[v57 - 1];
          v56[v57 - 1] = v60;
          v55 = v71;
          v63 = v57 < v71;
          *v61 = v62;
        }
        while ( v63 );
      }
      v64 = 0;
      if ( v71 <= 0 )
      {
LABEL_81:
        if ( v56 )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v56);
        }
        m_data = otherArray.m_data;
        if ( otherArray.m_data )
          goto LABEL_84;
      }
      else
      {
        while ( 1 )
        {
          btAlignedObjectArray<int>::btAlignedObjectArray<int>(&otherArray, &v67, &otherArray);
          if ( !btConvexHullInternal::shiftFace(
                  v65,
                  (btConvexHullInternal::Face *)v64,
                  0.0,
                  clampAmount,
                  (btConvexHullInternal::Face *)v56[v64],
                  v67) )
            break;
          if ( ++v64 >= v71 )
            goto LABEL_81;
        }
        if ( v56 )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v56);
        }
        if ( otherArray.m_data )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(otherArray.m_data);
        }
      }
    }
    else
    {
      if ( ptr )
      {
        ++gNumAlignedFree;
        sAlignedFreeFunc(ptr);
      }
      if ( otherArray.m_data )
      {
        m_data = otherArray.m_data;
LABEL_84:
        ++gNumAlignedFree;
        sAlignedFreeFunc(m_data);
      }
    }
  }
  return v54;
}
