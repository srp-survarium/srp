void __usercall btHashMap<btHashKey<btTriIndex>,btTriIndex>::clear(
        btHashMap<btHashKey<btTriIndex>,btTriIndex> *this@<ecx>,
        int a2@<esi>)
{
  if ( *(_DWORD *)(a2 + 12) )
  {
    if ( *(_BYTE *)(a2 + 16) )
      btAlignedFreeInternal(*(void **)(a2 + 12));
    *(_DWORD *)(a2 + 12) = 0;
  }
  *(_BYTE *)(a2 + 16) = 1;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  if ( *(_DWORD *)(a2 + 32) )
  {
    if ( *(_BYTE *)(a2 + 36) )
      btAlignedFreeInternal(*(void **)(a2 + 32));
    *(_DWORD *)(a2 + 32) = 0;
  }
  *(_BYTE *)(a2 + 36) = 1;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  if ( *(_DWORD *)(a2 + 52) )
  {
    if ( *(_BYTE *)(a2 + 56) )
      btAlignedFreeInternal(*(void **)(a2 + 52));
    *(_DWORD *)(a2 + 52) = 0;
  }
  *(_BYTE *)(a2 + 56) = 1;
  *(_DWORD *)(a2 + 52) = 0;
  *(_DWORD *)(a2 + 44) = 0;
  *(_DWORD *)(a2 + 48) = 0;
  if ( *(_DWORD *)(a2 + 72) )
  {
    if ( *(_BYTE *)(a2 + 76) )
      btAlignedFreeInternal(*(void **)(a2 + 72));
    *(_DWORD *)(a2 + 72) = 0;
  }
  *(_DWORD *)(a2 + 72) = 0;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 68) = 0;
  *(_BYTE *)(a2 + 76) = 1;
}
