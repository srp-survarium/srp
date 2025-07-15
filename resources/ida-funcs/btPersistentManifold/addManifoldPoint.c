int __userpurge btPersistentManifold::addManifoldPoint@<eax>(
        btPersistentManifold *this@<ecx>,
        int a2@<eax>,
        btPersistentManifold *newPoint)
{
  int v4; // ebx

  v4 = *(_DWORD *)(a2 + 1176);
  if ( v4 == 4 )
  {
    v4 = btPersistentManifold::sortCachedPoints(newPoint, (float *)a2);
    if ( *(_DWORD *)(288 * v4 + a2 + 124) )
      btPersistentManifold::clearUserCache((btManifoldPoint *)(288 * v4 + a2 + 16));
  }
  else
  {
    *(_DWORD *)(a2 + 1176) = v4 + 1;
  }
  if ( v4 < 0 )
    v4 = 0;
  qmemcpy((void *)(288 * v4 + a2 + 16), newPoint, 0x120u);
  return v4;
}
