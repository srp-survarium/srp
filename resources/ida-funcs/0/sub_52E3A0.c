_DWORD *__cdecl sub_52E3A0(int a1, int a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  _DWORD *result; // eax
  int j; // [esp+0h] [ebp-10h]
  unsigned int v7; // [esp+4h] [ebp-Ch]
  _BYTE *i; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]

  v9 = *(_DWORD *)(a1 + 356);
  *a3 = *(_DWORD *)(28 * a2 + *(_DWORD *)(v9 + 164));
  a3[1] = *(_DWORD *)(*(_DWORD *)(v9 + 164) + 28 * a2 + 4);
  if ( *a3 == 4 )
  {
    a3[2] = *a5;
    for ( i = *(_BYTE **)(*(_DWORD *)(v9 + 164) + 28 * a2 + 8); ; ++i )
    {
      *(_BYTE *)(*a5)++ = *i;
      if ( !*i )
        break;
    }
    a3[3] = 0;
    result = a3;
    a3[4] = 0;
  }
  else
  {
    a3[3] = *(_DWORD *)(*(_DWORD *)(v9 + 164) + 28 * a2 + 20);
    a3[4] = *a4;
    *a4 += 20 * a3[3];
    v7 = 0;
    for ( j = *(_DWORD *)(*(_DWORD *)(v9 + 164) + 28 * a2 + 12); ; j = *(_DWORD *)(*(_DWORD *)(v9 + 164) + 28 * j + 24) )
    {
      result = (_DWORD *)v7;
      if ( v7 >= a3[3] )
        break;
      sub_52E3A0(a1, j, a3[4] + 20 * v7++, a4, a5);
    }
    a3[2] = 0;
  }
  return result;
}
