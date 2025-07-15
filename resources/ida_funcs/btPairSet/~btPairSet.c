void __usercall btPairSet::~btPairSet(btPairSet *this@<ecx>, int a2@<esi>)
{
  void *v2; // eax

  v2 = *(void **)(a2 + 12);
  if ( v2 )
  {
    if ( *(_BYTE *)(a2 + 16) )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v2);
    }
    *(_DWORD *)(a2 + 12) = 0;
  }
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_BYTE *)(a2 + 16) = 1;
}
