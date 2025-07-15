void __usercall btCollisionWorld::AllHitsRayResultCallback::~AllHitsRayResultCallback(
        btCollisionWorld::AllHitsRayResultCallback *this@<ecx>,
        int a2@<esi>)
{
  void *v2; // eax
  void *v3; // eax
  void *v4; // eax
  void *v5; // eax
  void *v6; // eax
  void *v7; // eax

  v2 = *(void **)(a2 + 172);
  if ( v2 )
  {
    if ( *(_BYTE *)(a2 + 176) )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v2);
    }
    *(_DWORD *)(a2 + 172) = 0;
  }
  *(_BYTE *)(a2 + 176) = 1;
  *(_DWORD *)(a2 + 172) = 0;
  *(_DWORD *)(a2 + 164) = 0;
  *(_DWORD *)(a2 + 168) = 0;
  v3 = *(void **)(a2 + 152);
  if ( v3 )
  {
    if ( *(_BYTE *)(a2 + 156) )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v3);
    }
    *(_DWORD *)(a2 + 152) = 0;
  }
  *(_BYTE *)(a2 + 156) = 1;
  *(_DWORD *)(a2 + 152) = 0;
  *(_DWORD *)(a2 + 144) = 0;
  *(_DWORD *)(a2 + 148) = 0;
  v4 = *(void **)(a2 + 132);
  if ( v4 )
  {
    if ( *(_BYTE *)(a2 + 136) )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v4);
    }
    *(_DWORD *)(a2 + 132) = 0;
  }
  *(_BYTE *)(a2 + 136) = 1;
  *(_DWORD *)(a2 + 132) = 0;
  *(_DWORD *)(a2 + 124) = 0;
  *(_DWORD *)(a2 + 128) = 0;
  v5 = *(void **)(a2 + 112);
  if ( v5 )
  {
    if ( *(_BYTE *)(a2 + 116) )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v5);
    }
    *(_DWORD *)(a2 + 112) = 0;
  }
  *(_BYTE *)(a2 + 116) = 1;
  *(_DWORD *)(a2 + 112) = 0;
  *(_DWORD *)(a2 + 104) = 0;
  *(_DWORD *)(a2 + 108) = 0;
  v6 = *(void **)(a2 + 92);
  if ( v6 )
  {
    if ( *(_BYTE *)(a2 + 96) )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v6);
    }
    *(_DWORD *)(a2 + 92) = 0;
  }
  *(_BYTE *)(a2 + 96) = 1;
  *(_DWORD *)(a2 + 92) = 0;
  *(_DWORD *)(a2 + 84) = 0;
  *(_DWORD *)(a2 + 88) = 0;
  v7 = *(void **)(a2 + 36);
  if ( v7 )
  {
    if ( *(_BYTE *)(a2 + 40) )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v7);
    }
    *(_DWORD *)(a2 + 36) = 0;
  }
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  *(_BYTE *)(a2 + 40) = 1;
  *(_DWORD *)a2 = &btCollisionWorld::RayResultCallback::`vftable';
}
