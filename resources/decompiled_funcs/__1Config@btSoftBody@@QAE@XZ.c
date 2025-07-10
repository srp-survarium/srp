void __usercall btSoftBody::Config::~Config(btSoftBody::Config *this@<ecx>, int a2@<esi>)
{
  void *v2; // eax
  void *v3; // eax
  void *v4; // eax

  v2 = *(void **)(a2 + 156);
  if ( v2 )
  {
    if ( *(_BYTE *)(a2 + 160) )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v2);
    }
    *(_DWORD *)(a2 + 156) = 0;
  }
  *(_BYTE *)(a2 + 160) = 1;
  *(_DWORD *)(a2 + 156) = 0;
  *(_DWORD *)(a2 + 148) = 0;
  *(_DWORD *)(a2 + 152) = 0;
  v3 = *(void **)(a2 + 136);
  if ( v3 )
  {
    if ( *(_BYTE *)(a2 + 140) )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v3);
    }
    *(_DWORD *)(a2 + 136) = 0;
  }
  *(_BYTE *)(a2 + 140) = 1;
  *(_DWORD *)(a2 + 136) = 0;
  *(_DWORD *)(a2 + 128) = 0;
  *(_DWORD *)(a2 + 132) = 0;
  v4 = *(void **)(a2 + 116);
  if ( v4 )
  {
    if ( *(_BYTE *)(a2 + 120) )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v4);
    }
    *(_DWORD *)(a2 + 116) = 0;
  }
  *(_DWORD *)(a2 + 116) = 0;
  *(_DWORD *)(a2 + 108) = 0;
  *(_DWORD *)(a2 + 112) = 0;
  *(_BYTE *)(a2 + 120) = 1;
}
