int __cdecl sub_535E10(int a1, unsigned __int8 *a2, unsigned __int8 *a3, unsigned __int8 **a4)
{
  int result; // eax
  int v5; // [esp+4h] [ebp-4h]
  unsigned __int8 *v6; // [esp+14h] [ebp+Ch]
  unsigned __int8 *v7; // [esp+14h] [ebp+Ch]

  if ( a2 == a3 )
    return -1;
  if ( a2[1] || *a2 != 45 )
  {
    *a4 = a2;
    return 0;
  }
  v6 = a2 + 2;
  while ( 2 )
  {
    if ( v6 == a3 )
      return -1;
    if ( v6[1] )
      v5 = sub_534A50(v6[1], *v6);
    else
      v5 = *(unsigned __int8 *)(a1 + *v6 + 76);
    switch ( v5 )
    {
      case 0:
      case 1:
      case 8:
        *a4 = v6;
        return 0;
      case 5:
        if ( a3 - v6 < 2 )
          return -2;
        v6 += 2;
        continue;
      case 6:
        if ( a3 - v6 < 3 )
          return -2;
        v6 += 3;
        continue;
      case 7:
        if ( a3 - v6 < 4 )
          return -2;
        v6 += 4;
        continue;
      case 27:
        v6 += 2;
        if ( v6 == a3 )
          return -1;
        if ( v6[1] || *v6 != 45 )
          continue;
        v7 = v6 + 2;
        if ( v7 == a3 )
        {
          result = -1;
        }
        else if ( !v7[1] && *v7 == 62 )
        {
          *a4 = v7 + 2;
          result = 13;
        }
        else
        {
          *a4 = v7;
          result = 0;
        }
        break;
      default:
        v6 += 2;
        continue;
    }
    break;
  }
  return result;
}
