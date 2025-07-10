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
