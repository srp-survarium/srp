int __cdecl sub_53AA50(int a1, unsigned __int8 *a2, unsigned __int8 *a3, _DWORD *a4)
{
  int v5; // [esp+4h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-4h]
  char *v7; // [esp+1Ch] [ebp+Ch]

  if ( a2 == a3 )
    return -1;
  if ( *a2 )
    v6 = sub_534A50(*a2, a2[1]);
  else
    v6 = *(unsigned __int8 *)(a1 + a2[1] + 76);
  switch ( v6 )
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
    case 19:
      return sub_53ADF0(a1, a2 + 2, a3, a4);
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
      v7 = (char *)(a2 + 2);
      break;
    default:
      *a4 = a2;
      return 0;
  }
  while ( v7 != (char *)a3 )
  {
    if ( *v7 )
      v5 = sub_534A50(*v7, v7[1]);
    else
      v5 = *(unsigned __int8 *)(a1 + (unsigned __int8)v7[1] + 76);
    switch ( v5 )
    {
      case 5:
        if ( a3 - (unsigned __int8 *)v7 < 2 )
          return -2;
        *a4 = v7;
        return 0;
      case 6:
        if ( a3 - (unsigned __int8 *)v7 < 3 )
          return -2;
        *a4 = v7;
        return 0;
      case 7:
        if ( a3 - (unsigned __int8 *)v7 < 4 )
          return -2;
        *a4 = v7;
        return 0;
      case 18:
        *a4 = v7 + 2;
        return 9;
      case 22:
      case 24:
      case 25:
      case 26:
      case 27:
        goto LABEL_28;
      case 29:
        if ( (dword_88A300[8 * (unsigned __int8)byte_88A900[(unsigned __int8)*v7] + ((int)(unsigned __int8)v7[1] >> 5)]
            & (1 << (v7[1] & 0x1F))) == 0 )
        {
          *a4 = v7;
          return 0;
        }
LABEL_28:
        v7 += 2;
        break;
      default:
        *a4 = v7;
        return 0;
    }
  }
  return -1;
}
