btConvexHullShape *__userpurge btConvexHullShape::btConvexHullShape@<eax>(
        btConvexHullShape *this@<ecx>,
        btConvexHullShape *points,
        int numPoints,
        int stride)
{
  int m_size; // edi
  btVector3 *v5; // ecx
  int v6; // eax
  int v7; // edx
  btVector3 *v8; // esi
  int v9; // eax
  btVector3 *v10; // edi
  int *v11; // edi
  int v12; // ecx
  int *v13; // eax
  btVector3 *v14; // edi
  int v16; // [esp+0h] [ebp-30h]
  int v17; // [esp+4h] [ebp-2Ch]
  int v18; // [esp+8h] [ebp-28h]
  int v19; // [esp+Ch] [ebp-24h]
  int v20; // [esp+10h] [ebp-20h]
  int v21; // [esp+14h] [ebp-1Ch]
  int v22; // [esp+18h] [ebp-18h]
  btVector3 *v23; // [esp+1Ch] [ebp-14h]
  int v24; // [esp+20h] [ebp-10h]
  int v25; // [esp+20h] [ebp-10h]
  int v26; // [esp+24h] [ebp-Ch]
  int v27; // [esp+24h] [ebp-Ch]
  int v28; // [esp+28h] [ebp-8h]
  int v29; // [esp+28h] [ebp-8h]
  int v30; // [esp+2Ch] [ebp-4h]

  btPolyhedralConvexAabbCachingShape::btPolyhedralConvexAabbCachingShape(this, points);
  points->__vftable = (btConvexHullShape_vtbl *)&btConvexHullShape::`vftable';
  points->m_unscaledPoints.m_ownsMemory = 1;
  points->m_unscaledPoints.m_data = 0;
  points->m_unscaledPoints.m_size = 0;
  points->m_unscaledPoints.m_capacity = 0;
  points->m_shapeType = 4;
  m_size = points->m_unscaledPoints.m_size;
  v22 = m_size;
  if ( m_size <= 6 )
  {
    if ( m_size < 6 && points->m_unscaledPoints.m_capacity < 6 )
    {
      v5 = (btVector3 *)btAlignedAllocInternal(0x60u);
      v6 = points->m_unscaledPoints.m_size;
      v23 = v5;
      if ( v6 > 0 )
      {
        v7 = 0;
        do
        {
          if ( v5 )
          {
            v8 = &points->m_unscaledPoints.m_data[v7];
            v5->mVec128.m128_i32[0] = v8->mVec128.m128_i32[0];
            v8 = (btVector3 *)((char *)v8 + 4);
            v5->mVec128.m128_i32[1] = v8->mVec128.m128_i32[0];
            v8 = (btVector3 *)((char *)v8 + 4);
            v5->mVec128.m128_i32[2] = v8->mVec128.m128_i32[0];
            v5->mVec128.m128_i32[3] = v8->mVec128.m128_i32[1];
            m_size = v22;
          }
          ++v7;
          ++v5;
          --v6;
        }
        while ( v6 );
      }
      if ( points->m_unscaledPoints.m_data )
      {
        if ( points->m_unscaledPoints.m_ownsMemory )
          btAlignedFreeInternal(points->m_unscaledPoints.m_data);
        points->m_unscaledPoints.m_data = 0;
      }
      points->m_unscaledPoints.m_ownsMemory = 1;
      points->m_unscaledPoints.m_data = v23;
      points->m_unscaledPoints.m_capacity = 6;
    }
    if ( m_size < 6 )
    {
      v9 = m_size;
      do
      {
        v10 = &points->m_unscaledPoints.m_data[v9];
        if ( v10 )
        {
          v10->mVec128.m128_i32[0] = v24;
          v11 = &v10->mVec128.m128_i32[1];
          *v11++ = v26;
          *v11 = v28;
          v11[1] = v30;
        }
        ++v9;
      }
      while ( v9 < 6 );
    }
  }
  v12 = 0;
  points->m_unscaledPoints.m_size = 6;
  v13 = (int *)(numPoints + 8);
  do
  {
    v25 = *(v13 - 2);
    v27 = *(v13 - 1);
    v14 = &points->m_unscaledPoints.m_data[v12];
    v29 = *v13;
    v14->mVec128.m128_i32[0] = v25;
    v14 = (btVector3 *)((char *)v14 + 4);
    v14->mVec128.m128_i32[0] = v27;
    v14 = (btVector3 *)((char *)v14 + 4);
    v14->mVec128.m128_i32[0] = v29;
    ++v12;
    v13 += 4;
    v14->mVec128.m128_i32[1] = 0;
  }
  while ( v12 < 6 );
  btPolyhedralConvexAabbCachingShape::recalcLocalAabb(
    (btPolyhedralConvexAabbCachingShape *)(v12 * 16),
    (int *)points,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    (int)v23,
    v25,
    v27,
    v29);
  return points;
}
