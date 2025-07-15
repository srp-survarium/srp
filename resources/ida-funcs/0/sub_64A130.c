int __cdecl sub_64A130(_BYTE *a1, unsigned __int8 *a2, unsigned __int8 *a3, unsigned __int8 **a4)
{
  unsigned __int8 *v5; // [esp+18h] [ebp+Ch]
  unsigned __int8 *v6; // [esp+18h] [ebp+Ch]
  unsigned __int8 *v7; // [esp+18h] [ebp+Ch]

  if ( a2 == a3 )
    return -4;
  switch ( a1[*a2 + 76] )
  {
    case 0:
    case 1:
    case 8:
      *a4 = a2;
      return 0;
    case 2:
      return sub_64AA60(a1, a2 + 1, a3, a4);
    case 3:
      return sub_64A580(a1, a2 + 1, a3, a4);
    case 4:
      v6 = a2 + 1;
      if ( v6 == a3 )
        return -5;
      if ( *v6 != 93 )
        break;
      v7 = v6 + 1;
      if ( v7 == a3 )
        return -5;
      if ( *v7 != 62 )
      {
        v6 = v7 - 1;
        break;
      }
      *a4 = v7;
      return 0;
    case 5:
      if ( a3 - a2 < 2 )
        return -2;
      if ( !(*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 89))(a1, a2) )
      {
        v6 = a2 + 2;
        break;
      }
      *a4 = a2;
      return 0;
    case 6:
      if ( a3 - a2 < 3 )
        return -2;
      if ( !(*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 90))(a1, a2) )
      {
        v6 = a2 + 3;
        break;
      }
      *a4 = a2;
      return 0;
    case 7:
      if ( a3 - a2 < 4 )
        return -2;
      if ( (*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 91))(a1, a2) )
      {
        *a4 = a2;
        return 0;
      }
      v6 = a2 + 4;
      break;
    case 9:
      v5 = a2 + 1;
      if ( v5 == a3 )
        return -3;
      if ( a1[*v5 + 76] == 10 )
        ++v5;
      *a4 = v5;
      return 7;
    case 0xA:
      *a4 = a2 + 1;
      return 7;
    default:
      v6 = a2 + 1;
      break;
  }
  while ( v6 != a3 )
  {
    switch ( a1[*v6 + 76] )
    {
      case 0:
      case 1:
      case 2:
      case 3:
      case 8:
      case 9:
      case 0xA:
        goto LABEL_58;
      case 4:
        if ( v6 + 1 == a3 )
          goto LABEL_58;
        if ( v6[1] == 93 )
        {
          if ( v6 + 2 == a3 )
          {
LABEL_58:
            *a4 = v6;
            return 6;
          }
          if ( v6[2] == 62 )
          {
            *a4 = v6 + 2;
            return 0;
          }
          ++v6;
        }
        else
        {
          ++v6;
        }
        break;
      case 5:
        if ( a3 - v6 < 2 || (*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 89))(a1, v6) )
        {
          *a4 = v6;
          return 6;
        }
        v6 += 2;
        continue;
      case 6:
        if ( a3 - v6 < 3 || (*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 90))(a1, v6) )
        {
          *a4 = v6;
          return 6;
        }
        v6 += 3;
        continue;
      case 7:
        if ( a3 - v6 < 4 || (*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 91))(a1, v6) )
        {
          *a4 = v6;
          return 6;
        }
        v6 += 4;
        continue;
      default:
        ++v6;
        continue;
    }
  }
  *a4 = v6;
  return 6;
}
