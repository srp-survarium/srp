int __cdecl sub_64C790(int a1, unsigned __int8 *a2, unsigned __int8 *a3, unsigned __int8 **a4)
{
  int result; // eax
  char v5; // [esp+10h] [ebp-14h]
  int v6; // [esp+20h] [ebp-4h]
  unsigned __int8 *v7; // [esp+30h] [ebp+Ch]
  unsigned __int8 *v8; // [esp+30h] [ebp+Ch]
  unsigned __int8 *v9; // [esp+30h] [ebp+Ch]
  unsigned __int8 *v10; // [esp+30h] [ebp+Ch]

  if ( a2 == a3 )
    return -4;
  switch ( *(_BYTE *)(a1 + *a2 + 76) )
  {
    case 2:
      v7 = a2 + 1;
      if ( v7 == a3 )
        return -1;
      switch ( *(_BYTE *)(a1 + *v7 + 76) )
      {
        case 5:
        case 6:
        case 7:
        case 0x16:
        case 0x18:
        case 0x1D:
          *a4 = v7 - 1;
          result = 29;
          break;
        case 0xF:
          result = sub_64B470((_BYTE *)a1, v7 + 1, a3, a4);
          break;
        case 0x10:
          result = sub_64D1F0(a1, v7 + 1, a3, a4);
          break;
        default:
          *a4 = v7;
          result = 0;
          break;
      }
      return result;
    case 4:
      v8 = a2 + 1;
      if ( v8 == a3 )
        return -26;
      if ( *v8 != 93 )
        goto LABEL_33;
      if ( v8 + 1 == a3 )
        return -1;
      if ( v8[1] == 62 )
      {
        *a4 = v8 + 2;
        return 34;
      }
      else
      {
LABEL_33:
        *a4 = v8;
        return 26;
      }
    case 5:
      if ( a3 - a2 < 2 )
        return -2;
      if ( (*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 344))(a1, a2) )
      {
        v10 = a2 + 2;
        v6 = 18;
        goto LABEL_69;
      }
      if ( (*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 332))(a1, a2) )
      {
        v10 = a2 + 2;
        v6 = 19;
        goto LABEL_69;
      }
      *a4 = a2;
      return 0;
    case 6:
      if ( a3 - a2 < 3 )
        return -2;
      if ( (*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 348))(a1, a2) )
      {
        v10 = a2 + 3;
        v6 = 18;
        goto LABEL_69;
      }
      if ( (*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 336))(a1, a2) )
      {
        v10 = a2 + 3;
        v6 = 19;
        goto LABEL_69;
      }
      *a4 = a2;
      return 0;
    case 7:
      if ( a3 - a2 < 4 )
        return -2;
      if ( (*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 352))(a1, a2) )
      {
        v10 = a2 + 4;
        v6 = 18;
        goto LABEL_69;
      }
      if ( !(*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 340))(a1, a2) )
      {
        *a4 = a2;
        return 0;
      }
      v10 = a2 + 4;
      v6 = 19;
LABEL_69:
      while ( 2 )
      {
        if ( v10 == a3 )
          return -v6;
        switch ( *(_BYTE *)(a1 + *v10 + 76) )
        {
          case 5:
            if ( a3 - v10 < 2 )
              return -2;
            if ( (*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 332))(a1, v10) )
            {
              v10 += 2;
              continue;
            }
            *a4 = v10;
            return 0;
          case 6:
            if ( a3 - v10 < 3 )
              return -2;
            if ( (*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 336))(a1, v10) )
            {
              v10 += 3;
              continue;
            }
            *a4 = v10;
            return 0;
          case 7:
            if ( a3 - v10 < 4 )
              return -2;
            if ( (*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 340))(a1, v10) )
            {
              v10 += 4;
              continue;
            }
            *a4 = v10;
            return 0;
          case 9:
          case 0xA:
          case 0xB:
          case 0x14:
          case 0x15:
          case 0x1E:
          case 0x20:
          case 0x23:
          case 0x24:
            *a4 = v10;
            return v6;
          case 0xF:
            if ( v6 == 19 )
            {
              *a4 = v10;
              return 0;
            }
            else
            {
              *a4 = v10 + 1;
              return 30;
            }
          case 0x16:
          case 0x18:
          case 0x19:
          case 0x1A:
          case 0x1B:
            ++v10;
            continue;
          case 0x17:
            ++v10;
            if ( v6 != 18 )
            {
              if ( v6 == 41 )
                v6 = 19;
              continue;
            }
            if ( v10 == a3 )
            {
              result = -1;
            }
            else
            {
              v6 = 41;
              switch ( *(_BYTE *)(a1 + *v10 + 76) )
              {
                case 5:
                  if ( a3 - v10 < 2 )
                    return -2;
                  if ( (*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 332))(a1, v10) )
                  {
                    v10 += 2;
                    continue;
                  }
                  *a4 = v10;
                  return 0;
                case 6:
                  if ( a3 - v10 < 3 )
                    return -2;
                  if ( (*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 336))(a1, v10) )
                  {
                    v10 += 3;
                    continue;
                  }
                  *a4 = v10;
                  return 0;
                case 7:
                  if ( a3 - v10 >= 4 )
                  {
                    if ( (*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 340))(a1, v10) )
                    {
                      v10 += 4;
                      continue;
                    }
                    *a4 = v10;
                    result = 0;
                  }
                  else
                  {
                    result = -2;
                  }
                  break;
                case 0x16:
                case 0x18:
                case 0x19:
                case 0x1A:
                case 0x1B:
                  ++v10;
                  continue;
                case 0x1D:
                  *a4 = v10;
                  return 0;
                default:
                  v6 = 19;
                  continue;
              }
            }
            break;
          case 0x1D:
            *a4 = v10;
            return 0;
          case 0x21:
            if ( v6 == 19 )
            {
              *a4 = v10;
              return 0;
            }
            else
            {
              *a4 = v10 + 1;
              return 31;
            }
          case 0x22:
            if ( v6 == 19 )
            {
              *a4 = v10;
              return 0;
            }
            else
            {
              *a4 = v10 + 1;
              return 32;
            }
          default:
            *a4 = v10;
            return 0;
        }
        break;
      }
      return result;
    case 9:
      if ( a2 + 1 != a3 )
        goto LABEL_14;
      *a4 = a3;
      return -15;
    case 0xA:
    case 0x15:
      goto LABEL_14;
    case 0xB:
      *a4 = a2 + 1;
      return 17;
    case 0xC:
      return sub_64DA40(12, a1, a2 + 1, a3, a4);
    case 0xD:
      return sub_64DA40(13, a1, a2 + 1, a3, a4);
    case 0x13:
      return sub_64D700(a1, a2 + 1, a3, a4);
    case 0x14:
      *a4 = a2 + 1;
      return 25;
    case 0x16:
    case 0x18:
      v6 = 18;
      v10 = a2 + 1;
      goto LABEL_69;
    case 0x17:
    case 0x19:
    case 0x1A:
    case 0x1B:
      v6 = 19;
      v10 = a2 + 1;
      goto LABEL_69;
    case 0x1E:
      return sub_64D3B0(a1, a2 + 1, a3, a4);
    case 0x1F:
      *a4 = a2 + 1;
      return 23;
    case 0x20:
      v9 = a2 + 1;
      if ( v9 == a3 )
        return -24;
      switch ( *(_BYTE *)(a1 + *v9 + 76) )
      {
        case 9:
        case 0xA:
        case 0xB:
        case 0x15:
        case 0x20:
        case 0x23:
        case 0x24:
          *a4 = v9;
          result = 24;
          break;
        case 0xF:
          *a4 = v9 + 1;
          result = 35;
          break;
        case 0x21:
          *a4 = v9 + 1;
          result = 36;
          break;
        case 0x22:
          *a4 = v9 + 1;
          result = 37;
          break;
        default:
          *a4 = v9;
          result = 0;
          break;
      }
      return result;
    case 0x23:
      *a4 = a2 + 1;
      return 38;
    case 0x24:
      *a4 = a2 + 1;
      return 21;
    default:
      *a4 = a2;
      return 0;
  }
  while ( 1 )
  {
LABEL_14:
    if ( ++a2 == a3 )
    {
      *a4 = a2;
      return 15;
    }
    v5 = *(_BYTE *)(a1 + *a2 + 76);
    if ( v5 == 9 )
    {
      if ( a2 + 1 == a3 )
        goto LABEL_20;
    }
    else if ( v5 != 10 && v5 != 21 )
    {
LABEL_20:
      *a4 = a2;
      return 15;
    }
  }
}
