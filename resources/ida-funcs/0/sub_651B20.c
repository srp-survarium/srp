int __cdecl sub_651B20(int a1, unsigned __int8 *a2, unsigned __int8 *a3, unsigned __int8 **a4)
{
  int result; // eax
  int v5; // [esp+4h] [ebp-14h]
  int v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+14h] [ebp-4h]
  unsigned __int8 *v8; // [esp+24h] [ebp+Ch]
  unsigned __int8 *v9; // [esp+24h] [ebp+Ch]

  if ( a2 == a3 )
    return -1;
  if ( a2[1] )
    v7 = sub_64FDE0(a2[1], *a2);
  else
    v7 = *(unsigned __int8 *)(a1 + *a2 + 76);
  switch ( v7 )
  {
    case 5:
      if ( a3 - a2 < 2 )
        return -2;
      *a4 = a2;
      return 0;
    case 6:
      if ( a3 - a2 < 3 )
        return -2;
      *a4 = a2;
      return 0;
    case 7:
      if ( a3 - a2 < 4 )
        return -2;
      *a4 = a2;
      return 0;
    case 22:
    case 24:
      goto LABEL_9;
    case 29:
      if ( (dword_72DD78[8 * (unsigned __int8)byte_72E278[a2[1]] + ((int)*a2 >> 5)] & (1 << (*a2 & 0x1F))) == 0 )
      {
        *a4 = a2;
        return 0;
      }
LABEL_9:
      v8 = a2 + 2;
      break;
    default:
      *a4 = a2;
      return 0;
  }
  while ( v8 != a3 )
  {
    if ( v8[1] )
      v6 = sub_64FDE0(v8[1], *v8);
    else
      v6 = *(unsigned __int8 *)(a1 + *v8 + 76);
    switch ( v6 )
    {
      case 5:
        if ( a3 - v8 < 2 )
          return -2;
        *a4 = v8;
        return 0;
      case 6:
        if ( a3 - v8 < 3 )
          return -2;
        *a4 = v8;
        return 0;
      case 7:
        if ( a3 - v8 < 4 )
          return -2;
        *a4 = v8;
        return 0;
      case 9:
      case 10:
      case 21:
        v9 = v8 + 2;
        while ( 2 )
        {
          if ( v9 == a3 )
            return -1;
          if ( v9[1] )
            v5 = sub_64FDE0(v9[1], *v9);
          else
            v5 = *(unsigned __int8 *)(a1 + *v9 + 76);
          switch ( v5 )
          {
            case 9:
            case 10:
            case 21:
              v9 += 2;
              continue;
            case 11:
              *a4 = v9 + 2;
              result = 5;
              break;
            default:
              *a4 = v9;
              result = 0;
              break;
          }
          break;
        }
        return result;
      case 11:
        *a4 = v8 + 2;
        return 5;
      case 22:
      case 24:
      case 25:
      case 26:
      case 27:
        goto LABEL_27;
      case 23:
        v8 += 2;
        continue;
      case 29:
        if ( (dword_72DD78[8 * (unsigned __int8)byte_72E378[v8[1]] + ((int)*v8 >> 5)] & (1 << (*v8 & 0x1F))) == 0 )
        {
          *a4 = v8;
          return 0;
        }
LABEL_27:
        v8 += 2;
        break;
      default:
        *a4 = v8;
        return 0;
    }
  }
  return -1;
}
