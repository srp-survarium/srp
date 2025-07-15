int __cdecl sub_52F6D0(_BYTE *a1, unsigned __int8 *a2, unsigned __int8 *a3, unsigned __int8 **a4)
{
  int result; // eax
  char v5; // [esp+Ch] [ebp-Ch]
  int v6; // [esp+14h] [ebp-4h]
  unsigned __int8 *v7; // [esp+24h] [ebp+Ch]
  unsigned __int8 *v8; // [esp+24h] [ebp+Ch]
  unsigned __int8 *v9; // [esp+24h] [ebp+Ch]
  unsigned __int8 *v10; // [esp+24h] [ebp+Ch]
  unsigned __int8 *v11; // [esp+24h] [ebp+Ch]

  if ( a2 == a3 )
    return -1;
  switch ( a1[*a2 + 76] )
  {
    case 5:
      if ( a3 - a2 < 2 )
        return -2;
      if ( !(*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 86))(a1, a2) )
      {
        *a4 = a2;
        return 0;
      }
      v7 = a2 + 2;
      goto LABEL_30;
    case 6:
      if ( a3 - a2 < 3 )
        return -2;
      if ( !(*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 87))(a1, a2) )
      {
        *a4 = a2;
        return 0;
      }
      v7 = a2 + 3;
      goto LABEL_30;
    case 7:
      if ( a3 - a2 < 4 )
        return -2;
      if ( !(*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 88))(a1, a2) )
      {
        *a4 = a2;
        return 0;
      }
      v7 = a2 + 4;
LABEL_30:
      v6 = 0;
      break;
    case 0xF:
      return sub_5300E0(a1, a2 + 1, a3, a4);
    case 0x10:
      v8 = a2 + 1;
      if ( v8 == a3 )
        return -1;
      v5 = a1[*v8 + 76];
      if ( v5 == 20 )
        return sub_530720(a1, v8 + 1, a3, a4);
      if ( v5 == 27 )
        return sub_52FED0(a1, v8 + 1, a3, a4);
      *a4 = v8;
      return 0;
    case 0x11:
      return sub_530790(a1, a2 + 1, a3, a4);
    case 0x16:
    case 0x18:
      v7 = a2 + 1;
      goto LABEL_30;
    case 0x1D:
      *a4 = a2;
      return 0;
    default:
      *a4 = a2;
      return 0;
  }
  while ( v7 != a3 )
  {
    switch ( a1[*v7 + 76] )
    {
      case 5:
        if ( a3 - v7 < 2 )
          return -2;
        if ( !(*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 83))(a1, v7) )
        {
          *a4 = v7;
          return 0;
        }
        v7 += 2;
        continue;
      case 6:
        if ( a3 - v7 < 3 )
          return -2;
        if ( !(*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 84))(a1, v7) )
        {
          *a4 = v7;
          return 0;
        }
        v7 += 3;
        continue;
      case 7:
        if ( a3 - v7 < 4 )
          return -2;
        if ( !(*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 85))(a1, v7) )
        {
          *a4 = v7;
          return 0;
        }
        v7 += 4;
        continue;
      case 9:
      case 0xA:
      case 0x15:
        ++v7;
        while ( 2 )
        {
          if ( v7 == a3 )
            return -1;
          switch ( a1[*v7 + 76] )
          {
            case 5:
              if ( a3 - v7 < 2 )
                return -2;
              if ( !(*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 86))(a1, v7) )
              {
                *a4 = v7;
                return 0;
              }
              v10 = v7 + 2;
              goto LABEL_93;
            case 6:
              if ( a3 - v7 < 3 )
                return -2;
              if ( !(*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 87))(a1, v7) )
              {
                *a4 = v7;
                return 0;
              }
              v10 = v7 + 3;
              goto LABEL_93;
            case 7:
              if ( a3 - v7 >= 4 )
              {
                if ( (*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 88))(a1, v7) )
                {
                  v10 = v7 + 4;
LABEL_93:
                  result = sub_530B80(a1, v10, a3, a4);
                }
                else
                {
                  *a4 = v7;
                  result = 0;
                }
              }
              else
              {
                result = -2;
              }
              break;
            case 9:
            case 0xA:
            case 0x15:
              ++v7;
              continue;
            case 0xB:
              goto LABEL_95;
            case 0x11:
              goto LABEL_96;
            case 0x16:
            case 0x18:
              v10 = v7 + 1;
              goto LABEL_93;
            case 0x1D:
              *a4 = v7;
              return 0;
            default:
              *a4 = v7;
              return 0;
          }
          return result;
        }
      case 0xB:
LABEL_95:
        *a4 = v7 + 1;
        return 2;
      case 0x11:
LABEL_96:
        v11 = v7 + 1;
        if ( v11 == a3 )
          return -1;
        if ( *v11 == 62 )
        {
          *a4 = v11 + 1;
          return 4;
        }
        else
        {
          *a4 = v11;
          return 0;
        }
      case 0x16:
      case 0x18:
      case 0x19:
      case 0x1A:
      case 0x1B:
        ++v7;
        continue;
      case 0x17:
        if ( v6 )
        {
          *a4 = v7;
          return 0;
        }
        v6 = 1;
        v9 = v7 + 1;
        if ( v9 == a3 )
          return -1;
        break;
      case 0x1D:
        *a4 = v7;
        return 0;
      default:
        *a4 = v7;
        return 0;
    }
    switch ( a1[*v9 + 76] )
    {
      case 5:
        if ( a3 - v9 < 2 )
          return -2;
        if ( !(*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 86))(a1, v9) )
        {
          *a4 = v9;
          return 0;
        }
        v7 = v9 + 2;
        continue;
      case 6:
        if ( a3 - v9 < 3 )
          return -2;
        if ( !(*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 87))(a1, v9) )
        {
          *a4 = v9;
          return 0;
        }
        v7 = v9 + 3;
        continue;
      case 7:
        if ( a3 - v9 < 4 )
          return -2;
        if ( !(*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 88))(a1, v9) )
        {
          *a4 = v9;
          return 0;
        }
        v7 = v9 + 4;
        break;
      case 0x16:
      case 0x18:
        v7 = v9 + 1;
        continue;
      case 0x1D:
        *a4 = v9;
        return 0;
      default:
        *a4 = v9;
        return 0;
    }
  }
  return -1;
}
