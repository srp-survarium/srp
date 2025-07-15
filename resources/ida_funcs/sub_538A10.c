int __cdecl sub_538A10(int a1, int a2, unsigned __int8 *a3, unsigned __int8 *a4, unsigned __int8 **a5)
{
  int result; // eax
  int v6; // [esp+4h] [ebp-10h]
  int v7; // [esp+Ch] [ebp-8h]

  while ( a3 != a4 )
  {
    if ( a3[1] )
      v7 = sub_534A50(a3[1], *a3);
    else
      v7 = *(unsigned __int8 *)(a2 + *a3 + 76);
    switch ( v7 )
    {
      case 0:
      case 1:
      case 8:
        *a5 = a3;
        return 0;
      case 5:
        if ( a4 - a3 < 2 )
          return -2;
        a3 += 2;
        continue;
      case 6:
        if ( a4 - a3 < 3 )
          return -2;
        a3 += 3;
        continue;
      case 7:
        if ( a4 - a3 < 4 )
          return -2;
        a3 += 4;
        break;
      case 12:
      case 13:
        a3 += 2;
        if ( v7 != a1 )
          continue;
        if ( a3 == a4 )
          return -27;
        *a5 = a3;
        if ( a3[1] )
          v6 = sub_534A50(a3[1], *a3);
        else
          v6 = *(unsigned __int8 *)(a2 + *a3 + 76);
        switch ( v6 )
        {
          case 9:
          case 10:
          case 11:
          case 20:
          case 21:
          case 30:
            result = 27;
            break;
          default:
            result = 0;
            break;
        }
        return result;
      default:
        a3 += 2;
        continue;
    }
  }
  return -1;
}
