int __cdecl sub_53C270(int a1, unsigned __int8 *a2, unsigned __int8 *a3, _DWORD *a4)
{
  int result; // eax
  int v5; // [esp+4h] [ebp-14h]
  int v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+14h] [ebp-4h]
  char *v8; // [esp+24h] [ebp+Ch]
  unsigned __int8 *v9; // [esp+24h] [ebp+Ch]

  if ( a2 == a3 )
    return -1;
  if ( *a2 )
    v7 = sub_534A50(*a2, a2[1]);
  else
    v7 = *(unsigned __int8 *)(a1 + a2[1] + 76);
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
      if ( (dword_88A300[8 * (unsigned __int8)byte_88A800[*a2] + ((int)a2[1] >> 5)] & (1 << (a2[1] & 0x1F))) == 0 )
      {
        *a4 = a2;
        return 0;
      }
LABEL_9:
      v8 = (char *)(a2 + 2);
      break;
    default:
      *a4 = a2;
      return 0;
  }
  while ( v8 != (char *)a3 )
  {
    if ( *v8 )
      v6 = sub_534A50(*v8, v8[1]);
    else
      v6 = *(unsigned __int8 *)(a1 + (unsigned __int8)v8[1] + 76);
    switch ( v6 )
    {
      case 5:
        if ( a3 - (unsigned __int8 *)v8 < 2 )
          return -2;
        *a4 = v8;
        return 0;
      case 6:
        if ( a3 - (unsigned __int8 *)v8 < 3 )
          return -2;
        *a4 = v8;
        return 0;
      case 7:
        if ( a3 - (unsigned __int8 *)v8 < 4 )
          return -2;
        *a4 = v8;
        return 0;
      case 9:
      case 10:
      case 21:
        v9 = (unsigned __int8 *)(v8 + 2);
        while ( 2 )
        {
          if ( v9 == a3 )
            return -1;
          if ( *v9 )
            v5 = sub_534A50(*v9, v9[1]);
          else
            v5 = *(unsigned __int8 *)(a1 + v9[1] + 76);
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
        if ( (dword_88A300[8 * (unsigned __int8)byte_88A900[(unsigned __int8)*v8] + ((int)(unsigned __int8)v8[1] >> 5)]
            & (1 << (v8[1] & 0x1F))) == 0 )
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
