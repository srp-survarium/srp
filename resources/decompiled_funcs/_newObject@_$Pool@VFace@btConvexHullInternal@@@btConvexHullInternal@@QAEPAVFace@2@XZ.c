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
