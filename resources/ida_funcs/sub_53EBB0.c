int __cdecl sub_53EBB0(int a1, int a2, int a3, _DWORD *a4)
{
  int v5; // [esp+4h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-4h]

  v6 = 0;
  if ( (((_BYTE)a3 - (_BYTE)a2) & 1) != 0 )
    a3 = ((a3 - a2) & 0xFFFFFFFE) + a2;
  while ( a2 != a3 )
  {
    if ( *(_BYTE *)a2 )
      v5 = sub_534A50(*(_BYTE *)a2, *(_BYTE *)(a2 + 1));
    else
      v5 = *(unsigned __int8 *)(a1 + *(unsigned __int8 *)(a2 + 1) + 76);
    switch ( v5 )
    {
      case 0:
      case 1:
      case 8:
        *a4 = a2;
        return 0;
      case 2:
        a2 += 2;
        if ( a2 == a3 )
          return -1;
        if ( *(_BYTE *)a2 || *(_BYTE *)(a2 + 1) != 33 )
          continue;
        a2 += 2;
        if ( a2 == a3 )
          return -1;
        if ( !*(_BYTE *)a2 && *(_BYTE *)(a2 + 1) == 91 )
        {
          ++v6;
          a2 += 2;
        }
        continue;
      case 4:
        a2 += 2;
        if ( a2 == a3 )
          return -1;
        if ( *(_BYTE *)a2 || *(_BYTE *)(a2 + 1) != 93 )
          continue;
        a2 += 2;
        if ( a2 == a3 )
          return -1;
        if ( *(_BYTE *)a2 || *(_BYTE *)(a2 + 1) != 62 )
          continue;
        a2 += 2;
        if ( !v6 )
        {
          *a4 = a2;
          return 42;
        }
        --v6;
        break;
      case 5:
        if ( a3 - a2 < 2 )
          return -2;
        a2 += 2;
        continue;
      case 6:
        if ( a3 - a2 < 3 )
          return -2;
        a2 += 3;
        continue;
      case 7:
        if ( a3 - a2 < 4 )
          return -2;
        a2 += 4;
        continue;
      default:
        a2 += 2;
        continue;
    }
  }
  return -1;
}
