int __cdecl sub_53B030(int a1, unsigned __int8 *a2, unsigned __int8 *a3, _DWORD *a4)
{
  int result; // eax
  int v5; // [esp+4h] [ebp-28h]
  int v6; // [esp+Ch] [ebp-20h]
  int v7; // [esp+14h] [ebp-18h]
  int v8; // [esp+1Ch] [ebp-10h]
  int v9; // [esp+24h] [ebp-8h]
  int v10; // [esp+28h] [ebp-4h]
  char *v11; // [esp+38h] [ebp+Ch]
  unsigned __int8 *v12; // [esp+38h] [ebp+Ch]
  unsigned __int8 *v13; // [esp+38h] [ebp+Ch]
  unsigned __int8 *v14; // [esp+38h] [ebp+Ch]

  if ( a2 == a3 )
    return -1;
  if ( *a2 )
    v9 = sub_534A50(*a2, a2[1]);
  else
    v9 = *(unsigned __int8 *)(a1 + a2[1] + 76);
  switch ( v9 )
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
    case 15:
      return sub_53BB10(a1, a2 + 2, a3, a4);
    case 16:
      v12 = a2 + 2;
      if ( v12 == a3 )
        return -1;
      if ( *v12 )
        v8 = sub_534A50(*v12, v12[1]);
      else
        v8 = *(unsigned __int8 *)(a1 + v12[1] + 76);
      if ( v8 == 20 )
        return sub_53C1F0(a1, v12 + 2, a3, a4);
      if ( v8 == 27 )
        return sub_53B8F0(a1, v12 + 2, a3, a4);
      *a4 = v12;
      return 0;
    case 17:
      return sub_53C270(a1, a2 + 2, a3, a4);
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
      v11 = (char *)(a2 + 2);
      v10 = 0;
      break;
    default:
      *a4 = a2;
      return 0;
  }
  while ( v11 != (char *)a3 )
  {
    if ( *v11 )
      v7 = sub_534A50(*v11, v11[1]);
    else
      v7 = *(unsigned __int8 *)(a1 + (unsigned __int8)v11[1] + 76);
    switch ( v7 )
    {
      case 5:
        if ( a3 - (unsigned __int8 *)v11 < 2 )
          return -2;
        *a4 = v11;
        return 0;
      case 6:
        if ( a3 - (unsigned __int8 *)v11 < 3 )
          return -2;
        *a4 = v11;
        return 0;
      case 7:
        if ( a3 - (unsigned __int8 *)v11 < 4 )
          return -2;
        *a4 = v11;
        return 0;
      case 9:
      case 10:
      case 21:
        v11 += 2;
        while ( 2 )
        {
          if ( v11 == (char *)a3 )
            return -1;
          if ( *v11 )
            v5 = sub_534A50(*v11, v11[1]);
          else
            v5 = *(unsigned __int8 *)(a1 + (unsigned __int8)v11[1] + 76);
          switch ( v5 )
          {
            case 5:
              if ( a3 - (unsigned __int8 *)v11 < 2 )
                return -2;
              *a4 = v11;
              return 0;
            case 6:
              if ( a3 - (unsigned __int8 *)v11 < 3 )
                return -2;
              *a4 = v11;
              return 0;
            case 7:
              if ( a3 - (unsigned __int8 *)v11 < 4 )
                return -2;
              *a4 = v11;
              return 0;
            case 9:
            case 10:
            case 21:
              v11 += 2;
              continue;
            case 11:
              goto LABEL_91;
            case 17:
              goto LABEL_92;
            case 22:
            case 24:
              goto LABEL_78;
            case 29:
              if ( (dword_88A300[8 * (unsigned __int8)byte_88A800[(unsigned __int8)*v11]
                               + ((int)(unsigned __int8)v11[1] >> 5)]
                  & (1 << (v11[1] & 0x1F))) != 0 )
              {
LABEL_78:
                result = sub_53C6D0(a1, v11 + 2, a3, a4);
              }
              else
              {
                *a4 = v11;
                result = 0;
              }
              break;
            default:
              *a4 = v11;
              result = 0;
              break;
          }
          return result;
        }
      case 11:
LABEL_91:
        *a4 = v11 + 2;
        return 2;
      case 17:
LABEL_92:
        v14 = (unsigned __int8 *)(v11 + 2);
        if ( v14 == a3 )
          return -1;
        if ( !*v14 && v14[1] == 62 )
        {
          *a4 = v14 + 2;
          return 4;
        }
        else
        {
          *a4 = v14;
          return 0;
        }
      case 22:
      case 24:
      case 25:
      case 26:
      case 27:
        goto LABEL_39;
      case 23:
        if ( v10 )
        {
          *a4 = v11;
          return 0;
        }
        v10 = 1;
        v13 = (unsigned __int8 *)(v11 + 2);
        if ( v13 == a3 )
          return -1;
        if ( *v13 )
          v6 = sub_534A50(*v13, v13[1]);
        else
          v6 = *(unsigned __int8 *)(a1 + v13[1] + 76);
        break;
      case 29:
        if ( (dword_88A300[8 * (unsigned __int8)byte_88A900[(unsigned __int8)*v11] + ((int)(unsigned __int8)v11[1] >> 5)]
            & (1 << (v11[1] & 0x1F))) == 0 )
        {
          *a4 = v11;
          return 0;
        }
LABEL_39:
        v11 += 2;
        continue;
      default:
        *a4 = v11;
        return 0;
    }
    switch ( v6 )
    {
      case 5:
        if ( a3 - v13 < 2 )
          return -2;
        *a4 = v13;
        return 0;
      case 6:
        if ( a3 - v13 < 3 )
          return -2;
        *a4 = v13;
        return 0;
      case 7:
        if ( a3 - v13 < 4 )
          return -2;
        *a4 = v13;
        return 0;
      case 22:
      case 24:
        goto LABEL_59;
      case 29:
        if ( (dword_88A300[8 * (unsigned __int8)byte_88A800[*v13] + ((int)v13[1] >> 5)] & (1 << (v13[1] & 0x1F))) == 0 )
        {
          *a4 = v13;
          return 0;
        }
LABEL_59:
        v11 = (char *)(v13 + 2);
        break;
      default:
        *a4 = v13;
        return 0;
    }
  }
  return -1;
}
