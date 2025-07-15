void __userpurge btConvexHullInternal::compute(
        btConvexHullInternal *this@<ecx>,
        btConvexHullInternal *a2@<esi>,
        char *coords,
        int doubleCoords,
        int stride,
        int count)
{
  float v6; // xmm3_4
  float v7; // xmm6_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm7_4
  int v11; // ecx
  float *v12; // eax
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm4_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  int v19; // ecx
  int v20; // eax
  int v21; // eax
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm4_4
  float v25; // xmm6_4
  float v26; // xmm5_4
  float v27; // xmm7_4
  __int64 v28; // xmm0_8
  __int64 v29; // xmm1_8
  int v30; // ecx
  int v31; // edx
  btConvexHullInternal::Point32 *v32; // eax
  int m_size; // eax
  int v34; // edx
  int v35; // eax
  float *v36; // ecx
  int medAxis; // edi
  unsigned int v38; // xmm1_4
  unsigned int v39; // xmm2_4
  btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *arrays; // ecx
  int v41; // ebx
  int v42; // edx
  int v43; // eax
  btConvexHullInternal::Vertex **m_data; // eax
  int i; // eax
  int v46; // ebx
  btConvexHullInternal::Vertex *v47; // eax
  btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *v48; // [esp+154h] [ebp-58h]
  int v49; // [esp+154h] [ebp-58h]
  int v50; // [esp+158h] [ebp-54h]
  __m128i v51; // [esp+15Ch] [ebp-50h]
  __m128i v52; // [esp+16Ch] [ebp-40h] BYREF
  btConvexHullInternal::IntermediateHull result; // [esp+17Ch] [ebp-30h] BYREF
  btAlignedObjectArray<btConvexHullInternal::Point32> v54; // [esp+198h] [ebp-14h] BYREF

  v6 = 1.0e30;
  v7 = 1.0e30;
  v8 = -1.0e30;
  v9 = -1.0e30;
  v52.m128i_i64[0] = 0x7149F2CA7149F2CALL;
  v52.m128i_i32[2] = 1900671690;
  result.minXy = (btConvexHullInternal::Vertex *)-246811958;
  result.maxXy = (btConvexHullInternal::Vertex *)-246811958;
  v10 = -1.0e30;
  if ( doubleCoords > 0 )
  {
    v11 = doubleCoords;
    v12 = (float *)(coords + 8);
    do
    {
      v13 = *(v12 - 2);
      v14 = *(v12 - 1);
      v15 = *v12;
      v12 += 4;
      if ( v6 > v13 )
        v6 = v13;
      if ( *(float *)&v52.m128i_i32[1] > v14 )
        *(float *)&v52.m128i_i32[1] = v14;
      v7 = *(float *)&v52.m128i_i32[2];
      if ( *(float *)&v52.m128i_i32[2] > v15 )
      {
        v7 = v15;
        *(float *)&v52.m128i_i32[2] = v15;
      }
      if ( v13 > v8 )
        v8 = v13;
      if ( v14 > v9 )
        v9 = v14;
      if ( v15 > v10 )
        v10 = v15;
      --v11;
    }
    while ( v11 );
    *(float *)&result.maxXy = v9;
    *(float *)&result.minXy = v8;
    *(float *)v52.m128i_i32 = v6;
  }
  v16 = v9 - *(float *)&v52.m128i_i32[1];
  v17 = v8 - v6;
  v18 = v10 - v7;
  v51.m128i_i32[3] = 0;
  if ( v16 <= (float)(v8 - v6) )
  {
    if ( v18 <= v17 )
      v19 = 0;
    else
      v19 = 2;
  }
  else if ( v18 <= v16 )
  {
    v19 = 1;
  }
  else
  {
    v19 = 2;
  }
  a2->maxAxis = v19;
  if ( v16 <= v17 )
  {
    v20 = 1;
    if ( v18 > v16 )
      goto LABEL_29;
  }
  else if ( v18 > v17 )
  {
    v20 = 0;
    goto LABEL_29;
  }
  v20 = 2;
LABEL_29:
  a2->minAxis = v20;
  if ( v20 == v19 )
    a2->minAxis = (v19 + 1) % 3;
  v21 = 3 - a2->minAxis - v19;
  a2->medAxis = v21;
  v22 = v17 * 0.00009788567;
  v23 = v18 * 0.00009788567;
  v24 = v22;
  v25 = v16 * 0.00009788567;
  v26 = v23;
  *(float *)v51.m128i_i32 = v22;
  *(float *)&v51.m128i_i32[1] = v16 * 0.00009788567;
  *(float *)&v51.m128i_i32[2] = v23;
  if ( (v21 + 1) % 3 != v19 )
  {
    v24 = v22 * -1.0;
    v25 = v25 * -1.0;
    v26 = v23 * -1.0;
    *(float *)v51.m128i_i32 = v22 * -1.0;
    *(float *)&v51.m128i_i32[1] = v25;
    *(float *)&v51.m128i_i32[2] = v23 * -1.0;
  }
  a2->scaling = (btVector3)v51;
  if ( v24 != 0.0 )
  {
    v24 = *(float *)&clear_value / v24;
    *(float *)v51.m128i_i32 = v24;
  }
  if ( v25 != 0.0 )
  {
    v25 = *(float *)&clear_value / v25;
    *(float *)&v51.m128i_i32[1] = v25;
  }
  if ( v26 != 0.0 )
  {
    v26 = *(float *)&clear_value / v26;
    *(float *)&v51.m128i_i32[2] = v26;
  }
  v27 = v10 + *(float *)&v52.m128i_i32[2];
  *(float *)&result.minXy = (float)(*(float *)&result.minXy + *(float *)v52.m128i_i32) * 0.5;
  result.maxYx = 0;
  *(float *)&result.maxXy = (float)(*(float *)&result.maxXy + *(float *)&v52.m128i_i32[1]) * 0.5;
  a2->center.mVec128.m128_u64[0] = *(_QWORD *)&result.minXy;
  *(float *)&result.minYx = v27 * 0.5;
  a2->center.mVec128.m128_u64[1] = *(_QWORD *)&result.minYx;
  v54.m_ownsMemory = 1;
  memset(&v54.m_size, 0, 12);
  if ( doubleCoords > 0 )
  {
    ++gNumAlignedAllocs;
    v26 = *(float *)&v51.m128i_i32[2];
    v25 = *(float *)&v51.m128i_i32[1];
    v24 = *(float *)v51.m128i_i32;
    v54.m_ownsMemory = 1;
    v54.m_data = (btConvexHullInternal::Point32 *)sAlignedAllocFunc(16 * doubleCoords, 16);
    v54.m_capacity = doubleCoords;
    v28 = *(_QWORD *)&result.minYx;
    v29 = *(_QWORD *)&result.minXy;
    v30 = 0;
    v31 = doubleCoords;
    do
    {
      v32 = &v54.m_data[v30];
      if ( &v54.m_data[v30] )
      {
        *(_QWORD *)&v32->x = v29;
        *(_QWORD *)&v32->z = v28;
      }
      ++v30;
      --v31;
    }
    while ( v31 );
  }
  m_size = doubleCoords;
  v34 = 0;
  v54.m_size = doubleCoords;
  if ( doubleCoords > 0 )
  {
    v35 = 0;
    v52.m128i_i32[3] = 0;
    v36 = (float *)(coords + 8);
    do
    {
      medAxis = a2->medAxis;
      *(float *)&v38 = (float)(*(v36 - 1) - a2->center.mVec128.m128_f32[1]) * v25;
      *(float *)&v39 = (float)(*v36 - a2->center.mVec128.m128_f32[2]) * v26;
      *(float *)v52.m128i_i32 = (float)(*(v36 - 2) - a2->center.mVec128.m128_f32[0]) * v24;
      *(__int64 *)((char *)v52.m128i_i64 + 4) = __PAIR64__(v39, v38);
      v51 = _mm_load_si128(&v52);
      v54.m_data[v35].x = (int)*(float *)&v51.m128i_i32[medAxis];
      v54.m_data[v35].y = (int)*(float *)&v51.m128i_i32[a2->maxAxis];
      v54.m_data[v35].z = (int)*(float *)&v51.m128i_i32[a2->minAxis];
      v54.m_data[v35].index = v34++;
      v36 += 4;
      ++v35;
    }
    while ( v34 < doubleCoords );
    m_size = v54.m_size;
  }
  if ( m_size > 1 )
    btAlignedObjectArray<btConvexHullInternal::Point32>::quickSortInternal<bool (__cdecl *)(btConvexHullInternal::Point32 const &,btConvexHullInternal::Point32 const &)>(
      &v54,
      (bool (__cdecl *)(const btConvexHullInternal::Point32 *, const btConvexHullInternal::Point32 *))pointCmp,
      0,
      m_size - 1);
  arrays = (btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *)a2->vertexPool.arrays;
  a2->vertexPool.nextArray = (btConvexHullInternal::PoolArray<btConvexHullInternal::Vertex> *)arrays;
  a2->vertexPool.freeObjects = 0;
  a2->vertexPool.arraySize = doubleCoords;
  v41 = a2->originalVertices.m_size;
  v50 = v41;
  if ( doubleCoords >= v41 )
  {
    if ( doubleCoords > v41 && a2->originalVertices.m_capacity < doubleCoords )
    {
      if ( doubleCoords )
      {
        ++gNumAlignedAllocs;
        v48 = (btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *)sAlignedAllocFunc(4 * doubleCoords, 16);
      }
      else
      {
        v48 = 0;
      }
      v42 = a2->originalVertices.m_size;
      v43 = 0;
      if ( v42 > 0 )
      {
        arrays = v48;
        do
        {
          if ( arrays )
          {
            arrays->arrays = (btConvexHullInternal::PoolArray<btConvexHullInternal::Vertex> *)a2->originalVertices.m_data[v43];
            v41 = v50;
          }
          ++v43;
          arrays = (btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *)((char *)arrays + 4);
        }
        while ( v43 < v42 );
      }
      m_data = a2->originalVertices.m_data;
      if ( m_data )
      {
        if ( a2->originalVertices.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(m_data);
        }
        a2->originalVertices.m_data = 0;
      }
      a2->originalVertices.m_ownsMemory = 1;
      a2->originalVertices.m_data = (btConvexHullInternal::Vertex **)v48;
      a2->originalVertices.m_capacity = doubleCoords;
    }
    for ( i = v41; i < doubleCoords; ++i )
    {
      arrays = (btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *)&a2->originalVertices.m_data[i];
      if ( arrays )
        arrays->arrays = 0;
    }
  }
  v46 = 0;
  a2->originalVertices.m_size = doubleCoords;
  if ( doubleCoords > 0 )
  {
    v49 = 0;
    do
    {
      v47 = btConvexHullInternal::Pool<btConvexHullInternal::Vertex>::newObject(arrays, (int)&a2->vertexPool);
      v47->edges = 0;
      v47->point = v54.m_data[v49];
      v47->copy = -1;
      arrays = (btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *)a2->originalVertices.m_data;
      *((_DWORD *)&arrays->arrays + v46++) = v47;
      ++v49;
    }
    while ( v46 < doubleCoords );
  }
  if ( v54.m_data && v54.m_ownsMemory )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(v54.m_data);
  }
  a2->edgePool.nextArray = a2->edgePool.arrays;
  a2->edgePool.freeObjects = 0;
  a2->edgePool.arraySize = 6 * doubleCoords;
  v54.m_ownsMemory = 1;
  memset(&v54.m_size, 0, 12);
  a2->usedEdgePairs = 0;
  a2->maxUsedEdgePairs = 0;
  a2->mergeStamp = -3;
  memset(&result, 0, sizeof(result));
  btConvexHullInternal::computeInternal(a2, 0, doubleCoords, &result);
  a2->vertexList = result.minXy;
  if ( v54.m_data )
  {
    if ( v54.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v54.m_data);
    }
  }
}
