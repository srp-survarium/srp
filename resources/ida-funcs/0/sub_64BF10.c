int __cdecl sub_64BF10(int a1, unsigned __int8 *a2, unsigned __int8 *a3, unsigned __int8 **a4)
{
  int v5; // [esp+1Ch] [ebp-14h]
  int v6; // [esp+24h] [ebp-Ch]
  int v7; // [esp+28h] [ebp-8h]
  int v8; // [esp+2Ch] [ebp-4h]

  v8 = 0;
  while ( a2 != a3 )
  {
    switch ( *(_BYTE *)(a1 + *a2 + 76) )
    {
      case 5:
        if ( a3 - a2 < 2 )
          return -2;
        if ( !(*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 332))(a1, a2) )
        {
          *a4 = a2;
          return 0;
        }
        a2 += 2;
        continue;
      case 6:
        if ( a3 - a2 < 3 )
          return -2;
        if ( !(*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 336))(a1, a2) )
        {
          *a4 = a2;
          return 0;
        }
        a2 += 3;
        continue;
      case 7:
        if ( a3 - a2 < 4 )
          return -2;
        if ( !(*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 340))(a1, a2) )
        {
          *a4 = a2;
          return 0;
        }
        a2 += 4;
        continue;
      case 9:
      case 0xA:
      case 0x15:
        goto LABEL_43;
      case 0xE:
        goto LABEL_51;
      case 0x16:
      case 0x18:
      case 0x19:
      case 0x1A:
      case 0x1B:
        ++a2;
        continue;
      case 0x17:
        if ( v8 )
        {
          *a4 = a2;
          return 0;
        }
        v8 = 1;
        if ( ++a2 == a3 )
          return -1;
        switch ( *(_BYTE *)(a1 + *a2 + 76) )
        {
          case 5:
            if ( a3 - a2 < 2 )
              return -2;
            if ( !(*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 344))(a1, a2) )
            {
              *a4 = a2;
              return 0;
            }
            a2 += 2;
            continue;
          case 6:
            if ( a3 - a2 < 3 )
              return -2;
            if ( !(*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 348))(a1, a2) )
            {
              *a4 = a2;
              return 0;
            }
            a2 += 3;
            continue;
          case 7:
            if ( a3 - a2 < 4 )
              return -2;
            if ( !(*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 352))(a1, a2) )
            {
              *a4 = a2;
              return 0;
            }
            a2 += 4;
            break;
          case 0x16:
          case 0x18:
            ++a2;
            continue;
          case 0x1D:
            *a4 = a2;
            return 0;
          default:
            *a4 = a2;
            return 0;
        }
        continue;
      case 0x1D:
        *a4 = a2;
        return 0;
      default:
        *a4 = a2;
        return 0;
    }
    while ( 1 )
    {
LABEL_43:
      if ( ++a2 == a3 )
        return -1;
      v7 = *(unsigned __int8 *)(a1 + *a2 + 76);
      if ( v7 == 14 )
        break;
      if ( *(unsigned __int8 *)(a1 + *a2 + 76) < 9u || *(unsigned __int8 *)(a1 + *a2 + 76) > 0xAu && v7 != 21 )
      {
        *a4 = a2;
        return 0;
      }
    }
LABEL_51:
    v8 = 0;
    while ( 1 )
    {
      if ( ++a2 == a3 )
        return -1;
      v6 = *(unsigned __int8 *)(a1 + *a2 + 76);
      if ( v6 == 12 || v6 == 13 )
        break;
      if ( *(unsigned __int8 *)(a1 + *a2 + 76) < 9u || *(unsigned __int8 *)(a1 + *a2 + 76) > 0xAu && v6 != 21 )
      {
        *a4 = a2;
        return 0;
      }
    }
    ++a2;
    while ( 1 )
    {
      if ( a2 == a3 )
        return -1;
      if ( *(unsigned __int8 *)(a1 + *a2 + 76) == v6 )
        break;
      switch ( *(_BYTE *)(a1 + *a2 + 76) )
      {
        case 0:
        case 1:
        case 8:
          *a4 = a2;
          return 0;
        case 2:
          *a4 = a2;
          return 0;
        case 3:
          v5 = sub_64A580((_BYTE *)a1, a2 + 1, a3, &a2);
          if ( v5 > 0 )
            continue;
          if ( !v5 )
            *a4 = a2;
          return v5;
        case 5:
          if ( a3 - a2 < 2 )
            return -2;
          if ( (*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 356))(a1, a2) )
          {
            *a4 = a2;
            return 0;
          }
          a2 += 2;
          continue;
        case 6:
          if ( a3 - a2 < 3 )
            return -2;
          if ( (*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 360))(a1, a2) )
          {
            *a4 = a2;
            return 0;
          }
          a2 += 3;
          continue;
        case 7:
          if ( a3 - a2 < 4 )
            return -2;
          if ( (*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 364))(a1, a2) )
          {
            *a4 = a2;
            return 0;
          }
          a2 += 4;
          break;
        default:
          ++a2;
          continue;
      }
    }
    if ( ++a2 == a3 )
      return -1;
    switch ( *(_BYTE *)(a1 + *a2 + 76) )
    {
      case 9:
      case 0xA:
      case 0x15:
LABEL_92:
        if ( ++a2 == a3 )
          return -1;
        break;
      case 0xB:
LABEL_112:
        *a4 = a2 + 1;
        return 1;
      case 0x11:
LABEL_113:
        if ( ++a2 == a3 )
          return -1;
        if ( *a2 == 62 )
        {
          *a4 = a2 + 1;
          return 3;
        }
        else
        {
          *a4 = a2;
          return 0;
        }
      default:
        *a4 = a2;
        return 0;
    }
    switch ( *(_BYTE *)(a1 + *a2 + 76) )
    {
      case 5:
        if ( a3 - a2 < 2 )
          return -2;
        if ( !(*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 344))(a1, a2) )
        {
          *a4 = a2;
          return 0;
        }
        a2 += 2;
        continue;
      case 6:
        if ( a3 - a2 < 3 )
          return -2;
        if ( !(*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 348))(a1, a2) )
        {
          *a4 = a2;
          return 0;
        }
        a2 += 3;
        continue;
      case 7:
        if ( a3 - a2 < 4 )
          return -2;
        if ( !(*(int (__cdecl **)(int, unsigned __int8 *))(a1 + 352))(a1, a2) )
        {
          *a4 = a2;
          return 0;
        }
        a2 += 4;
        break;
      case 9:
      case 0xA:
      case 0x15:
        goto LABEL_92;
      case 0xB:
        goto LABEL_112;
      case 0x11:
        goto LABEL_113;
      case 0x16:
      case 0x18:
        ++a2;
        continue;
      case 0x1D:
        *a4 = a2;
        return 0;
      default:
        *a4 = a2;
        return 0;
    }
  }
  return -1;
}
