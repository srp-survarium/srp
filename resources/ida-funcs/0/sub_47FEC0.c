char __fastcall sub_47FEC0(int a1, int a2)
{
  _DWORD *v2; // ecx
  char result; // al
  int v4; // esi
  int v5; // edx

  if ( *(_BYTE *)(a2 + 72) || *(_BYTE *)(a2 + 266) )
    return 0;
  if ( *(_DWORD *)(a2 + 40) != 3 )
    return 0;
  if ( *(_DWORD *)(a2 + 36) != 3 )
    return 0;
  if ( *(_DWORD *)(a2 + 44) != 2 )
    return 0;
  if ( *(_DWORD *)(a2 + 100) != 3 )
    return 0;
  v2 = *(_DWORD **)(a2 + 196);
  if ( v2[2] != 2 )
    return 0;
  result = 1;
  if ( v2[24] != 1 )
    return 0;
  if ( v2[46] != 1 )
    return 0;
  if ( (int)v2[3] > 2 )
    return 0;
  if ( v2[25] != 1 )
    return 0;
  if ( v2[47] != 1 )
    return 0;
  v4 = *(_DWORD *)(a2 + 280);
  if ( v2[9] != v4 )
    return 0;
  if ( v2[31] != v4 )
    return 0;
  if ( v2[53] != v4 )
    return 0;
  v5 = *(_DWORD *)(a2 + 284);
  if ( v2[10] != v5 || v2[32] != v5 || v2[54] != v5 )
    return 0;
  return result;
}
