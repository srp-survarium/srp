btDbvtBroadphase *__userpurge btDbvtBroadphase::btDbvtBroadphase@<eax>(
        btDbvtBroadphase *this@<ecx>,
        int a2@<esi>,
        btHashedOverlappingPairCache *paircache)
{
  btDbvt *v3; // edi
  int i; // ebx
  int v5; // edx
  btHashedOverlappingPairCache *v6; // eax
  btHashedOverlappingPairCache *v7; // eax
  btHashedOverlappingPairCache *v9; // [esp-4h] [ebp-Ch]

  *(_DWORD *)a2 = &btDbvtBroadphase::`vftable';
  v3 = (btDbvt *)(a2 + 4);
  for ( i = 1; i >= 0; --i )
    btDbvt::btDbvt(v3++);
  v6 = paircache;
  *(_BYTE *)(a2 + 153) = 0;
  *(_BYTE *)(a2 + 154) = v5;
  *(_BYTE *)(a2 + 152) = paircache == 0;
  *(_DWORD *)(a2 + 100) = 0;
  *(_DWORD *)(a2 + 104) = 0;
  *(_DWORD *)(a2 + 124) = 0;
  *(_DWORD *)(a2 + 108) = v5;
  *(_DWORD *)(a2 + 112) = 0;
  *(_DWORD *)(a2 + 116) = 10;
  *(_DWORD *)(a2 + 120) = v5;
  *(_DWORD *)(a2 + 128) = 0;
  *(_DWORD *)(a2 + 132) = 0;
  *(_DWORD *)(a2 + 136) = 0;
  if ( !paircache )
  {
    v7 = (btHashedOverlappingPairCache *)btAlignedAllocInternal(0x4Cu);
    if ( v7 )
      v6 = btHashedOverlappingPairCache::btHashedOverlappingPairCache(v9, v7);
    else
      v6 = 0;
  }
  *(_DWORD *)(a2 + 96) = v6;
  *(_DWORD *)(a2 + 148) = 0;
  *(_DWORD *)(a2 + 140) = 0;
  *(_DWORD *)(a2 + 144) = 0;
  *(_DWORD *)(a2 + 84) = 0;
  *(_DWORD *)(a2 + 88) = 0;
  *(_DWORD *)(a2 + 92) = 0;
  return (btDbvtBroadphase *)a2;
}
