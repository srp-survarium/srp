int __cdecl sub_540AA0(
        int (__cdecl *a1)(int, int, int),
        int a2,
        int a3,
        int a4,
        int a5,
        _DWORD *a6,
        _DWORD *a7,
        _DWORD *a8,
        _DWORD *a9,
        int *a10,
        _DWORD *a11)
{
  int v12; // eax
  int v13; // eax
  int v14; // [esp+0h] [ebp-10h]
  int v15; // [esp+4h] [ebp-Ch] BYREF
  int v16; // [esp+8h] [ebp-8h] BYREF
  int v17; // [esp+Ch] [ebp-4h] BYREF

  v15 = 0;
  v16 = 0;
  v17 = 0;
  a4 += 5 * *(_DWORD *)(a3 + 68);
  a5 -= 2 * *(_DWORD *)(a3 + 68);
  if ( !sub_540E50(a3, a4, a5, &v16, &v17, &v15, &a4) || !v16 )
  {
    *a6 = a4;
    return 0;
  }
  if ( (*(int (__cdecl **)(int, int, int, const char *))(a3 + 28))(a3, v16, v17, "version") )
  {
    if ( a7 )
      *a7 = v15;
    if ( a8 )
      *a8 = a4;
    if ( !sub_540E50(a3, a4, a5, &v16, &v17, &v15, &a4) )
    {
      *a6 = a4;
      return 0;
    }
    if ( !v16 )
    {
      if ( !a2 )
        return 1;
      *a6 = a4;
      return 0;
    }
  }
  else if ( !a2 )
  {
    *a6 = v16;
    return 0;
  }
  if ( (*(int (__cdecl **)(int, int, int, const char *))(a3 + 28))(a3, v16, v17, "encoding") )
  {
    v14 = sub_540DA0(a3, v15, a5);
    if ( (v14 < 97 || v14 > 122) && (v14 < 65 || v14 > 90) )
    {
      *a6 = v15;
      return 0;
    }
    if ( a9 )
      *a9 = v15;
    if ( a10 )
    {
      v12 = a1(a3, v15, a4 - *(_DWORD *)(a3 + 68));
      *a10 = v12;
    }
    if ( !sub_540E50(a3, a4, a5, &v16, &v17, &v15, &a4) )
    {
      *a6 = a4;
      return 0;
    }
    if ( !v16 )
      return 1;
  }
  if ( !(*(int (__cdecl **)(int, int, int, const char *))(a3 + 28))(a3, v16, v17, "standalone") || a2 )
  {
    *a6 = v16;
    return 0;
  }
  if ( (*(int (__cdecl **)(int, int, int, const char *))(a3 + 28))(a3, v15, a4 - *(_DWORD *)(a3 + 68), "yes") )
  {
    if ( a11 )
      *a11 = 1;
  }
  else
  {
    if ( !(*(int (__cdecl **)(int, int, int, const char *))(a3 + 28))(a3, v15, a4 - *(_DWORD *)(a3 + 68), "no") )
    {
      *a6 = v15;
      return 0;
    }
    if ( a11 )
      *a11 = 0;
  }
  while ( 1 )
  {
    v13 = sub_540DA0(a3, a4, a5);
    if ( !sub_540DF0(v13) )
      break;
    a4 += *(_DWORD *)(a3 + 68);
  }
  if ( a4 == a5 )
    return 1;
  *a6 = a4;
  return 0;
}
