int __cdecl sub_642D30(int a1, _DWORD *a2, int a3, const __m128i *src, _DWORD *a5)
{
  bool v6; // [esp+0h] [ebp-18h]
  char v7; // [esp+4h] [ebp-14h]
  int v8; // [esp+8h] [ebp-10h]
  char v9; // [esp+Dh] [ebp-Bh]
  char v10; // [esp+Eh] [ebp-Ah]
  char v11; // [esp+Fh] [ebp-9h]
  _DWORD *v12; // [esp+10h] [ebp-8h]
  int count; // [esp+14h] [ebp-4h]

  v9 = 0;
  v10 = 1;
  v11 = 1;
  if ( !src->m128i_i8[0] && *a2 )
    return 28;
  if ( *a2 && *(_BYTE *)*a2 == 120 && *(_BYTE *)(*a2 + 1) == 109 && *(_BYTE *)(*a2 + 2) == 108 )
  {
    if ( *(_BYTE *)(*a2 + 3) == 110 && *(_BYTE *)(*a2 + 4) == 115 && !*(_BYTE *)(*a2 + 5) )
      return 39;
    if ( !*(_BYTE *)(*a2 + 3) )
      v9 = 1;
  }
  for ( count = 0; src->m128i_i8[count]; ++count )
  {
    if ( v10 && (count > 36 || src->m128i_i8[count] != byte_72DCD0[count]) )
      v10 = 0;
    if ( !v9 && v11 && (count > 29 || src->m128i_i8[count] != byte_72DCF8[count]) )
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
    v12 = *(_DWORD **)(a1 + 376);
    if ( count > v12[6] )
    {
      v8 = (*(int (__cdecl **)(_DWORD, int))(a1 + 16))(v12[4], count + 24);
      if ( !v8 )
        return 1;
      v12[4] = v8;
      v12[6] = count + 24;
    }
    *(_DWORD *)(a1 + 376) = v12[1];
  }
  else
  {
    v12 = (_DWORD *)(*(int (__cdecl **)(int))(a1 + 12))(28);
    if ( !v12 )
      return 1;
    v12[4] = (*(int (__cdecl **)(int))(a1 + 12))(count + 24);
    if ( !v12[4] )
    {
      (*(void (__cdecl **)(_DWORD *))(a1 + 20))(v12);
      return 1;
    }
    v12[6] = count + 24;
  }
  v12[5] = count;
  memcpy(v12[4], src, count);
  if ( *(_BYTE *)(a1 + 472) )
    *(_BYTE *)(count + v12[4] - 1) = *(_BYTE *)(a1 + 472);
  *v12 = a2;
  v12[3] = a3;
  v12[2] = a2[1];
  if ( src->m128i_i8[0] || a2 != (_DWORD *)(*(_DWORD *)(a1 + 356) + 152) )
    a2[1] = v12;
  else
    a2[1] = 0;
  v12[1] = *a5;
  *a5 = v12;
  if ( a3 && *(_DWORD *)(a1 + 100) )
    (*(void (__cdecl **)(_DWORD, _DWORD, unsigned __int8 *))(a1 + 100))(
      *(_DWORD *)(a1 + 4),
      *a2,
      a2[1] != 0 ? (unsigned __int8 *)src : 0);
  return 0;
}
