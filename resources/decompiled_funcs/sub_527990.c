int __cdecl sub_527990(int a1, _DWORD *a2, int a3, unsigned __int8 *src, int *a5)
{
  bool v6; // [esp+0h] [ebp-18h]
  char v7; // [esp+4h] [ebp-14h]
  int v8; // [esp+8h] [ebp-10h]
  char v9; // [esp+Dh] [ebp-Bh]
  char v10; // [esp+Eh] [ebp-Ah]
  char v11; // [esp+Fh] [ebp-9h]
  int v12; // [esp+10h] [ebp-8h]
  int count; // [esp+14h] [ebp-4h]

  v9 = 0;
  v10 = 1;
  v11 = 1;
  if ( !*src && *a2 )
    return 28;
  if ( *a2 && *(_BYTE *)*a2 == 120 && *(_BYTE *)(*a2 + 1) == 109 && *(_BYTE *)(*a2 + 2) == 108 )
  {
    if ( *(_BYTE *)(*a2 + 3) == 110 && *(_BYTE *)(*a2 + 4) == 115 && !*(_BYTE *)(*a2 + 5) )
      return 39;
    if ( !*(_BYTE *)(*a2 + 3) )
      v9 = 1;
  }
  for ( count = 0; src[count]; ++count )
  {
    if ( v10 && (count > 36 || (char)src[count] != byte_88A258[count]) )
      v10 = 0;
    if ( !v9 && v11 && (count > 29 || (char)src[count] != byte_88A280[count]) )
      v11 = 0;
  }
  v7 = v10 && count == 36;
  v6 = v11 && count == 29;
  if ( v9 != v7 )
    return v9 != 0 ? 38 : 40;
  if ( v6 )
    return 40;
  if ( *(_BYTE *)(a1 + 472) )
    ++count;
  if ( *(_DWORD *)(a1 + 376) )
  {
    v12 = *(_DWORD *)(a1 + 376);
    if ( count > *(_DWORD *)(v12 + 24) )
    {
      v8 = (*(int (__cdecl **)(_DWORD, int))(a1 + 16))(*(_DWORD *)(v12 + 16), count + 24);
      if ( !v8 )
        return 1;
      *(_DWORD *)(v12 + 16) = v8;
      *(_DWORD *)(v12 + 24) = count + 24;
    }
    *(_DWORD *)(a1 + 376) = *(_DWORD *)(v12 + 4);
  }
  else
  {
    v12 = (*(int (__cdecl **)(int))(a1 + 12))(28);
    if ( !v12 )
      return 1;
    *(_DWORD *)(v12 + 16) = (*(int (__cdecl **)(int))(a1 + 12))(count + 24);
    if ( !*(_DWORD *)(v12 + 16) )
    {
      (*(void (__cdecl **)(int))(a1 + 20))(v12);
      return 1;
    }
    *(_DWORD *)(v12 + 24) = count + 24;
  }
  *(_DWORD *)(v12 + 20) = count;
  memcpy(*(unsigned __int8 **)(v12 + 16), src, count);
  if ( *(_BYTE *)(a1 + 472) )
    *(_BYTE *)(count + *(_DWORD *)(v12 + 16) - 1) = *(_BYTE *)(a1 + 472);
  *(_DWORD *)v12 = a2;
  *(_DWORD *)(v12 + 12) = a3;
  *(_DWORD *)(v12 + 8) = a2[1];
  if ( *src || a2 != (_DWORD *)(*(_DWORD *)(a1 + 356) + 152) )
    a2[1] = v12;
  else
    a2[1] = 0;
  *(_DWORD *)(v12 + 4) = *a5;
  *a5 = v12;
  if ( a3 && *(_DWORD *)(a1 + 100) )
    (*(void (__cdecl **)(_DWORD, _DWORD, unsigned __int8 *))(a1 + 100))(*(_DWORD *)(a1 + 4), *a2, a2[1] != 0 ? src : 0);
  return 0;
}
