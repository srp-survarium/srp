void __usercall btUnionFind::~btUnionFind(btUnionFind *this@<ecx>, int a2@<eax>)
{
  void *v3; // eax
  btUnionFind *v4; // [esp-4h] [ebp-Ch]

  v3 = *(void **)(a2 + 12);
  if ( v3 )
  {
    if ( *(_BYTE *)(a2 + 16) )
    {
      btAlignedFreeInternal(v3);
      this = v4;
    }
    *(_DWORD *)(a2 + 12) = 0;
  }
  *(_BYTE *)(a2 + 16) = 1;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)this,
    a2);
}
