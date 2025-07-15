void __usercall btConvexHullShape::~btConvexHullShape(btConvexHullShape *this@<ecx>, int a2@<esi>)
{
  void *v2; // eax
  void *v3; // eax

  v2 = *(void **)(a2 + 140);
  if ( v2 )
  {
    if ( *(_BYTE *)(a2 + 144) )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v2);
    }
    *(_DWORD *)(a2 + 140) = 0;
  }
  *(_DWORD *)(a2 + 140) = 0;
  *(_DWORD *)(a2 + 132) = 0;
  *(_DWORD *)(a2 + 136) = 0;
  *(_BYTE *)(a2 + 144) = 1;
  v3 = *(void **)(a2 + 64);
  *(_DWORD *)a2 = &btPolyhedralConvexShape::`vftable';
  if ( v3 )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(v3);
  }
  *(_DWORD *)a2 = &btCollisionShape::`vftable';
}
