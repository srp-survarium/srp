btConvexHullInternal::Edge *__usercall btConvexHullInternal::PoolArray<btConvexHullInternal::Edge>::init@<eax>(
        btConvexHullInternal::PoolArray<btConvexHullInternal::Edge> *this@<ecx>,
        _DWORD *a2@<esi>)
{
  int v2; // eax
  _DWORD *v3; // edx
  int v4; // ecx
  _DWORD *v5; // eax

  v2 = a2[1];
  v3 = (_DWORD *)*a2;
  v4 = 0;
  if ( v2 <= 0 )
    return (btConvexHullInternal::Edge *)*a2;
  do
  {
    if ( ++v4 >= v2 )
      v5 = 0;
    else
      v5 = v3 + 6;
    *v3 = v5;
    v2 = a2[1];
    v3 += 6;
  }
  while ( v4 < v2 );
  return (btConvexHullInternal::Edge *)*a2;
}
