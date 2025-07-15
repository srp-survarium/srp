void __usercall btHashMap<btHashPtr,int>::~btHashMap<btHashPtr,int>(
        btHashMap<btInternalVertexPair,btInternalEdge> *this@<ecx>,
        int a2@<esi>)
{
  void *v2; // eax
  void *v3; // eax
  void *v4; // eax
  void *v5; // eax

  v2 = *(void **)(a2 + 72);
  if ( v2 )
  {
    if ( *(_BYTE *)(a2 + 76) )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v2);
    }
    *(_DWORD *)(a2 + 72) = 0;
  }
  *(_BYTE *)(a2 + 76) = 1;
  *(_DWORD *)(a2 + 72) = 0;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 68) = 0;
  v3 = *(void **)(a2 + 52);
  if ( v3 )
  {
    if ( *(_BYTE *)(a2 + 56) )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v3);
    }
    *(_DWORD *)(a2 + 52) = 0;
  }
  *(_BYTE *)(a2 + 56) = 1;
  *(_DWORD *)(a2 + 52) = 0;
  *(_DWORD *)(a2 + 44) = 0;
  *(_DWORD *)(a2 + 48) = 0;
  v4 = *(void **)(a2 + 32);
  if ( v4 )
  {
    if ( *(_BYTE *)(a2 + 36) )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v4);
    }
    *(_DWORD *)(a2 + 32) = 0;
  }
  *(_BYTE *)(a2 + 36) = 1;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  v5 = *(void **)(a2 + 12);
  if ( v5 )
  {
    if ( *(_BYTE *)(a2 + 16) )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v5);
    }
    *(_DWORD *)(a2 + 12) = 0;
  }
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_BYTE *)(a2 + 16) = 1;
}
