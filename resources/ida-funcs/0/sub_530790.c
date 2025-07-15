int __cdecl sub_530790(_BYTE *a1, unsigned __int8 *a2, unsigned __int8 *a3, unsigned __int8 **a4)
{
  int result; // eax
  unsigned __int8 *v5; // [esp+18h] [ebp+Ch]
  unsigned __int8 *v6; // [esp+18h] [ebp+Ch]

  if ( a2 == a3 )
    return -1;
  switch ( a1[*a2 + 76] )
  {
    case 5:
      if ( a3 - a2 < 2 )
        return -2;
      if ( (*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 86))(a1, a2) )
      {
        v5 = a2 + 2;
        break;
      }
      *a4 = a2;
      return 0;
    case 6:
      if ( a3 - a2 < 3 )
        return -2;
      if ( (*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 87))(a1, a2) )
      {
        v5 = a2 + 3;
        break;
      }
      *a4 = a2;
      return 0;
    case 7:
      if ( a3 - a2 < 4 )
        return -2;
      if ( !(*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 88))(a1, a2) )
      {
        *a4 = a2;
        return 0;
      }
      v5 = a2 + 4;
      break;
    case 0x16:
    case 0x18:
      v5 = a2 + 1;
      break;
    case 0x1D:
      *a4 = a2;
      return 0;
    default:
      *a4 = a2;
      return 0;
  }
  while ( v5 != a3 )
  {
    switch ( a1[*v5 + 76] )
    {
      case 5:
        if ( a3 - v5 < 2 )
          return -2;
        if ( !(*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 83))(a1, v5) )
        {
          *a4 = v5;
          return 0;
        }
        v5 += 2;
        continue;
      case 6:
        if ( a3 - v5 < 3 )
          return -2;
        if ( !(*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 84))(a1, v5) )
        {
          *a4 = v5;
          return 0;
        }
        v5 += 3;
        continue;
      case 7:
        if ( a3 - v5 < 4 )
          return -2;
        if ( !(*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 85))(a1, v5) )
        {
          *a4 = v5;
          return 0;
        }
        v5 += 4;
        break;
      case 9:
      case 0xA:
      case 0x15:
        v6 = v5 + 1;
        while ( 2 )
        {
          if ( v6 == a3 )
            return -1;
          switch ( a1[*v6 + 76] )
          {
            case 9:
            case 0xA:
            case 0x15:
              ++v6;
              continue;
            case 0xB:
              *a4 = v6 + 1;
              result = 5;
              break;
            default:
              *a4 = v6;
              result = 0;
              break;
          }
          break;
        }
        return result;
      case 0xB:
        *a4 = v5 + 1;
        return 5;
      case 0x16:
      case 0x18:
      case 0x19:
      case 0x1A:
      case 0x1B:
        ++v5;
        continue;
      case 0x17:
        ++v5;
        continue;
      case 0x1D:
        *a4 = v5;
        return 0;
      default:
        *a4 = v5;
        return 0;
    }
  }
  return -1;
}
