int __cdecl sub_52C330(_DWORD *a1, int a2, char a3, char a4, int a5, int a6)
{
  int v7; // [esp+0h] [ebp-10h]
  int v8; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  int v10; // [esp+Ch] [ebp-4h]

  if ( a5 || a4 )
  {
    for ( i = 0; i < a1[3]; ++i )
    {
      if ( a2 == *(_DWORD *)(12 * i + a1[5]) )
        return 1;
    }
    if ( a4 && !a1[2] && !*(_BYTE *)(a2 + 9) )
      a1[2] = a2;
  }
  if ( a1[3] == a1[4] )
  {
    if ( a1[4] )
    {
      v8 = 2 * a1[4];
      v7 = (*(int (__cdecl **)(_DWORD, int))(a6 + 16))(a1[5], 24 * a1[4]);
      if ( !v7 )
        return 0;
      a1[4] = v8;
      a1[5] = v7;
    }
    else
    {
      a1[4] = 8;
      a1[5] = (*(int (__cdecl **)(int))(a6 + 12))(12 * a1[4]);
      if ( !a1[5] )
        return 0;
    }
  }
  v10 = a1[5] + 12 * a1[3];
  *(_DWORD *)v10 = a2;
  *(_DWORD *)(v10 + 8) = a5;
  *(_BYTE *)(v10 + 4) = a3;
  if ( !a3 )
    *(_BYTE *)(a2 + 8) = 1;
  ++a1[3];
  return 1;
}
