btConvexHullInternal::Face *__usercall btConvexHullInternal::PoolArray<btConvexHullInternal::Face>::init@<eax>(
        btConvexHullInternal::PoolArray<btConvexHullInternal::Face> *this@<ecx>,
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
    return (btConvexHullInternal::Face *)*a2;
  do
  {
    if ( ++v4 >= v2 )
      v5 = 0;
    else
      v5 = v3 + 15;
    *v3 = v5;
    v2 = a2[1];
    v3 += 15;
  }
  while ( v4 < v2 );
  return (btConvexHullInternal::Face *)*a2;
}
