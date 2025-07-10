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
