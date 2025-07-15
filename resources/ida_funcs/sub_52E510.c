_DWORD *__cdecl sub_52E510(int a1, int a2, int a3, int a4)
{
  _DWORD *v5; // [esp+0h] [ebp-Ch]
  int v6; // [esp+4h] [ebp-8h]
  _DWORD *v7; // [esp+8h] [ebp-4h]

  v7 = *(_DWORD **)(a1 + 356);
  v6 = sub_52DE00(v7 + 20, a2, a3, a4);
  if ( !v6 )
    return 0;
  v5 = (_DWORD *)sub_52D5B0(a1, (int)(v7 + 5), v6, 0x18u);
  if ( !v5 )
    return 0;
  if ( *v5 == v6 )
  {
    v7[24] = v7[23];
    if ( !sub_52C490(a1, (int)v5) )
      return 0;
  }
  else
  {
    v7[23] = v7[24];
  }
  return v5;
}
