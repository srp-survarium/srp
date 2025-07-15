void __userpurge btConvexHullInternal::compute(
        btConvexHullInternal *this@<ecx>,
        btConvexHullInternal *coords,
        int doubleCoords,
        int stride,
        int count)
{
  btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *v5; // ecx
  float v6; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm4_4
  float *v9; // eax
  int v10; // edx
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  int v17; // eax
  int v18; // esi
  btConvexHullInternal::Vertex *v19; // eax
  float v20; // xmm3_4
  float v21; // xmm0_4
  int v22; // eax
  int v23; // edx
  btConvexHullInternal::Point32 *v24; // edi
  float *p_y; // edi
  int v26; // edx
  int v27; // eax
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  btConvexHullInternal::Vertex *v33; // eax
  btConvexHullInternal::Vertex *v34; // esi
  btConvexHullInternal::Vertex *m_size; // edi
  btConvexHullInternal::Vertex *v36; // edx
  btConvexHullInternal::Vertex *v37; // eax
  btConvexHullInternal::Vertex *i; // edx
  btConvexHullInternal::Vertex *v39; // eax
  int v40; // edx
  _DWORD *v41; // esi
  btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *v42; // [esp-10h] [ebp-84h]
  int v43; // [esp+Ch] [ebp-68h]
  btConvexHullInternal::Vertex *v44; // [esp+10h] [ebp-64h]
  btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *v45; // [esp+10h] [ebp-64h]
  float v46; // [esp+14h] [ebp-60h]
  float v47; // [esp+18h] [ebp-5Ch]
  float v48; // [esp+1Ch] [ebp-58h]
  float v49; // [esp+24h] [ebp-50h]
  float v50; // [esp+28h] [ebp-4Ch]
  float v51; // [esp+2Ch] [ebp-48h]
  int v52; // [esp+30h] [ebp-44h]
  btConvexHullInternal::IntermediateHull result; // [esp+34h] [ebp-40h] BYREF
  float v54; // [esp+44h] [ebp-30h]
  float v55; // [esp+48h] [ebp-2Ch]
  float v56; // [esp+4Ch] [ebp-28h]
  int v57; // [esp+50h] [ebp-24h]
  btAlignedObjectArray<btConvexHullInternal::Point32> v58; // [esp+60h] [ebp-14h] BYREF

  v5 = (btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *)stride;
  v49 = FLOAT_1_0e30;
  v50 = FLOAT_1_0e30;
  v51 = FLOAT_1_0e30;
  v6 = FLOAT_N1_0e30;
  v7 = FLOAT_N1_0e30;
  v8 = FLOAT_N1_0e30;
  if ( stride > 0 )
  {
    v9 = (float *)(doubleCoords + 8);
    v10 = stride;
    do
    {
      v11 = *(v9 - 2);
      v12 = *(v9 - 1);
      v13 = *v9;
      v9 += 4;
      if ( v49 > v11 )
        v49 = v11;
      if ( v50 > v12 )
        v50 = v12;
      if ( v51 > v13 )
        v51 = v13;
      if ( v11 > v6 )
        v6 = v11;
      if ( v12 > v7 )
        v7 = v12;
      if ( v13 > v8 )
        v8 = v13;
      --v10;
    }
    while ( v10 );
  }
  v14 = v6 - v49;
  v15 = v7 - v50;
  v16 = v8 - v51;
  v17 = 2;
  if ( (float)(v7 - v50) > (float)(v6 - v49) )
  {
    if ( v16 <= v15 )
    {
      v18 = 1;
      goto LABEL_22;
    }
    goto LABEL_20;
  }
  if ( v16 > v14 )
  {
LABEL_20:
    v18 = 2;
    goto LABEL_22;
  }
  v18 = 0;
LABEL_22:
  coords->maxAxis = v18;
  if ( v15 <= v14 )
  {
    if ( v16 > v15 )
      v17 = 1;
  }
  else if ( v16 > v14 )
  {
    v17 = 0;
  }
  coords->minAxis = v17;
  if ( v17 == v18 )
    coords->minAxis = (v18 + 1) % 3;
  v19 = (btConvexHullInternal::Vertex *)(3 - coords->minAxis - v18);
  coords->medAxis = (int)v19;
  v46 = v14 * 0.00009788567;
  v20 = v16 * 0.00009788567;
  v47 = v15 * 0.00009788567;
  v48 = v16 * 0.00009788567;
  if ( ((int)&v19->next + 1) % 3 != v18 )
  {
    v46 = v46 * -1.0;
    v20 = v20 * -1.0;
    v47 = v47 * -1.0;
    v48 = v20;
  }
  v21 = s_bm_current_air_resistance;
  coords->scaling.mVec128.m128_f32[0] = v46;
  coords->scaling.mVec128.m128_f32[1] = v47;
  coords->scaling.mVec128.m128_f32[2] = v48;
  coords->scaling.mVec128.m128_i32[3] = 0;
  if ( v46 != 0.0 )
    v46 = v21 / v46;
  if ( v47 != 0.0 )
    v47 = v21 / v47;
  if ( v20 != 0.0 )
    v48 = v21 / v20;
  result.maxYx = 0;
  *(float *)&result.minXy = (float)(v6 + v49) * 0.5;
  *(float *)&result.maxXy = (float)(v7 + v50) * 0.5;
  *(float *)&result.minYx = (float)(v8 + v51) * 0.5;
  coords->center = (btVector3)result;
  v58.m_ownsMemory = 1;
  memset(&v58.m_size, 0, 12);
  if ( stride > 0 )
  {
    v58.m_data = (btConvexHullInternal::Point32 *)btAlignedAllocInternal(16 * stride);
    v5 = (btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *)stride;
    v58.m_ownsMemory = 1;
    v58.m_capacity = stride;
    v22 = 0;
    v23 = stride;
    do
    {
      v24 = &v58.m_data[v22];
      if ( &v58.m_data[v22] )
      {
        *(float *)&v24->x = v54;
        p_y = (float *)&v24->y;
        *p_y++ = v55;
        *p_y = v56;
        *((_DWORD *)p_y + 1) = v57;
      }
      ++v22;
      --v23;
    }
    while ( v23 );
  }
  v26 = 0;
  v58.m_size = (int)v5;
  if ( (int)v5 > 0 )
  {
    v27 = 0;
    v57 = 0;
    v5 = (btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *)(doubleCoords + 8);
    do
    {
      v28 = *(float *)&v5[-1].arraySize;
      v29 = *(float *)&v5->arrays;
      v49 = *(float *)&v5[-1].freeObjects;
      v30 = (float)(v49 - coords->center.mVec128.m128_f32[0]) * v46;
      v50 = v28;
      v31 = (float)(v28 - coords->center.mVec128.m128_f32[1]) * v47;
      v51 = v29;
      v32 = (float)(v29 - coords->center.mVec128.m128_f32[2]) * v48;
      v54 = v30;
      v55 = v31;
      v56 = v32;
      v49 = v30;
      v50 = v31;
      v51 = v32;
      v52 = v57;
      v58.m_data[v27].x = (int)*(&v49 + coords->medAxis);
      v58.m_data[v27].y = (int)*(&v49 + coords->maxAxis);
      v58.m_data[v27].z = (int)*(&v49 + coords->minAxis);
      ++v5;
      v58.m_data[v27++].index = v26++;
    }
    while ( v26 < stride );
  }
  if ( v58.m_size > 1 )
    btAlignedObjectArray<btConvexHullInternal::Point32>::quickSortInternal<bool (__cdecl *)(btConvexHullInternal::Point32 const &,btConvexHullInternal::Point32 const &)>(
      &v58,
      (bool (__cdecl *)(const btConvexHullInternal::Point32 *, const btConvexHullInternal::Point32 *))pointCmp,
      0,
      v58.m_size - 1);
  coords->vertexPool.nextArray = coords->vertexPool.arrays;
  v33 = (btConvexHullInternal::Vertex *)stride;
  v34 = 0;
  coords->vertexPool.freeObjects = 0;
  coords->vertexPool.arraySize = stride;
  m_size = (btConvexHullInternal::Vertex *)coords->originalVertices.m_size;
  v44 = m_size;
  if ( stride >= (int)m_size )
  {
    if ( stride > (int)m_size && coords->originalVertices.m_capacity < stride )
    {
      if ( stride )
        v34 = (btConvexHullInternal::Vertex *)btAlignedAllocInternal(4 * stride);
      v36 = (btConvexHullInternal::Vertex *)coords->originalVertices.m_size;
      v5 = 0;
      if ( (int)v36 > 0 )
      {
        v37 = v34;
        do
        {
          if ( v37 )
          {
            v37->next = coords->originalVertices.m_data[(_DWORD)v5];
            m_size = v44;
          }
          v5 = (btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *)((char *)v5 + 1);
          v37 = (btConvexHullInternal::Vertex *)((char *)v37 + 4);
        }
        while ( (int)v5 < (int)v36 );
      }
      if ( coords->originalVertices.m_data )
      {
        if ( coords->originalVertices.m_ownsMemory )
        {
          btAlignedFreeInternal(coords->originalVertices.m_data);
          v5 = v42;
        }
        coords->originalVertices.m_data = 0;
      }
      v33 = (btConvexHullInternal::Vertex *)stride;
      coords->originalVertices.m_ownsMemory = 1;
      coords->originalVertices.m_data = &v34->next;
      coords->originalVertices.m_capacity = stride;
    }
    for ( i = m_size; (int)i < (int)v33; i = (btConvexHullInternal::Vertex *)((char *)i + 1) )
    {
      v5 = (btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *)&coords->originalVertices.m_data[(_DWORD)i];
      if ( v5 )
        v5->arrays = 0;
    }
  }
  v45 = 0;
  coords->originalVertices.m_size = (int)v33;
  if ( (int)v33 > 0 )
  {
    v43 = 0;
    do
    {
      v39 = btConvexHullInternal::Pool<btConvexHullInternal::Vertex>::newObject(
              v5,
              (btConvexHullInternal::Vertex ***)&coords->vertexPool);
      v39->edges = 0;
      v40 = v43;
      v43 += 16;
      v41 = (int *)((char *)&v58.m_data->x + v40);
      v39->point.x = *(int *)((char *)&v58.m_data->x + v40);
      v39->point.y = *++v41;
      v39->point.z = *++v41;
      v39->point.index = v41[1];
      v39->copy = -1;
      coords->originalVertices.m_data[(_DWORD)v45] = v39;
      v5 = (btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *)((char *)&v45->arrays + 1);
      v45 = v5;
    }
    while ( (int)v5 < stride );
  }
  if ( v58.m_data && v58.m_ownsMemory )
    btAlignedFreeInternal(v58.m_data);
  coords->edgePool.nextArray = coords->edgePool.arrays;
  coords->edgePool.freeObjects = 0;
  coords->edgePool.arraySize = 6 * stride;
  v58.m_ownsMemory = 1;
  memset(&v58.m_size, 0, 12);
  coords->usedEdgePairs = 0;
  coords->maxUsedEdgePairs = 0;
  coords->mergeStamp = -3;
  memset(&result, 0, sizeof(result));
  btConvexHullInternal::computeInternal(coords, 0, stride, &result);
  coords->vertexList = result.minXy;
  if ( v58.m_data )
  {
    if ( v58.m_ownsMemory )
      btAlignedFreeInternal(v58.m_data);
  }
}
