btConvexHullInternal::Edge *__usercall btConvexHullInternal::Pool<btConvexHullInternal::Edge>::newObject@<eax>(
        btConvexHullInternal::Pool<btConvexHullInternal::Edge> *this@<ecx>,
        _DWORD *a2@<edi>)
{
  btConvexHullInternal::Edge *result; // eax
  int v3; // esi
  btConvexHullInternal::PoolArray<btConvexHullInternal::Edge> *v4; // ecx
  _DWORD *v5; // esi
  int v6; // eax
  btConvexHullInternal::PoolArray<btConvexHullInternal::Edge> *v7; // ecx

  result = (btConvexHullInternal::Edge *)a2[2];
  if ( !result )
  {
    v3 = a2[1];
    if ( v3 )
    {
      a2[1] = *(_DWORD *)(v3 + 8);
      result = btConvexHullInternal::PoolArray<btConvexHullInternal::Edge>::init((btConvexHullInternal::PoolArray<btConvexHullInternal::Edge> *)this);
      a2[2] = result->next;
      return result;
    }
    ++gNumAlignedAllocs;
    v5 = sAlignedAllocFunc(0xCu, 16);
    if ( v5 )
    {
      v6 = a2[3];
      ++gNumAlignedAllocs;
      v5[1] = v6;
      v5[2] = 0;
      *v5 = sAlignedAllocFunc(24 * v6, 16);
      v5[2] = *a2;
      *a2 = v5;
      result = btConvexHullInternal::PoolArray<btConvexHullInternal::Edge>::init(v7);
      a2[2] = result->next;
      return result;
    }
    MEMORY[8] = *a2;
    *a2 = 0;
    result = btConvexHullInternal::PoolArray<btConvexHullInternal::Edge>::init(v4);
  }
  a2[2] = result->next;
  return result;
}


btConvexHullInternal::Face *__usercall btConvexHullInternal::Pool<btConvexHullInternal::Face>::newObject@<eax>(
        btConvexHullInternal::Pool<btConvexHullInternal::Face> *this@<ecx>,
        _DWORD *a2@<edi>)
{
  btConvexHullInternal::Face *result; // eax
  int v3; // esi
  _DWORD *v4; // esi
  int v5; // eax

  result = (btConvexHullInternal::Face *)a2[2];
  if ( !result )
  {
    v3 = a2[1];
    if ( v3 )
    {
      a2[1] = *(_DWORD *)(v3 + 8);
    }
    else
    {
      ++gNumAlignedAllocs;
      v4 = sAlignedAllocFunc(0xCu, 16);
      if ( v4 )
      {
        v5 = a2[3];
        ++gNumAlignedAllocs;
        v4[1] = v5;
        v4[2] = 0;
        *v4 = sAlignedAllocFunc(60 * v5, 16);
      }
      else
      {
        v4 = 0;
      }
      v4[2] = *a2;
      *a2 = v4;
    }
    result = btConvexHullInternal::PoolArray<btConvexHullInternal::Face>::init((btConvexHullInternal::PoolArray<btConvexHullInternal::Face> *)this);
  }
  a2[2] = result->next;
  result->next = 0;
  result->nearbyVertex = 0;
  result->nextWithSameNearbyVertex = 0;
  return result;
}


btConvexHullInternal::Vertex *__usercall btConvexHullInternal::Pool<btConvexHullInternal::Vertex>::newObject@<eax>(
        btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *this@<ecx>,
        int a2@<edi>)
{
  btConvexHullInternal::Vertex *result; // eax
  int v3; // esi
  _DWORD *v4; // esi
  int v5; // eax

  result = *(btConvexHullInternal::Vertex **)(a2 + 8);
  if ( !result )
  {
    v3 = *(_DWORD *)(a2 + 4);
    if ( v3 )
    {
      *(_DWORD *)(a2 + 4) = *(_DWORD *)(v3 + 8);
    }
    else
    {
      ++gNumAlignedAllocs;
      v4 = sAlignedAllocFunc(0xCu, 16);
      if ( v4 )
      {
        v5 = *(_DWORD *)(a2 + 12);
        ++gNumAlignedAllocs;
        v4[1] = v5;
        v4[2] = 0;
        *v4 = sAlignedAllocFunc(112 * v5, 16);
      }
      else
      {
        v4 = 0;
      }
      this = *(btConvexHullInternal::Pool<btConvexHullInternal::Vertex> **)a2;
      v4[2] = *(_DWORD *)a2;
      *(_DWORD *)a2 = v4;
    }
    result = btConvexHullInternal::PoolArray<btConvexHullInternal::Vertex>::init((btConvexHullInternal::PoolArray<btConvexHullInternal::Vertex> *)this);
  }
  *(_DWORD *)(a2 + 8) = result->next;
  result->next = 0;
  result->prev = 0;
  result->edges = 0;
  result->firstNearbyFace = 0;
  result->lastNearbyFace = 0;
  result->copy = -1;
  return result;
}
