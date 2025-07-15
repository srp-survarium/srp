int __cdecl sub_52E9F0(_BYTE *a1, unsigned __int8 *a2, unsigned __int8 *a3, unsigned __int8 **a4)
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
    case 4:
      v5 = a2 + 1;
      if ( v5 == a3 )
        return -1;
      if ( *v5 != 93 )
        break;
      v6 = v5 + 1;
      if ( v6 == a3 )
        return -1;
      if ( *v6 != 62 )
      {
        v5 = v6 - 1;
        break;
      }
      *a4 = v6 + 1;
      return 40;
    case 5:
      if ( a3 - a2 < 2 )
        return -2;
      if ( !(*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 89))(a1, a2) )
      {
        v5 = a2 + 2;
        break;
      }
      *a4 = a2;
      return 0;
    case 6:
      if ( a3 - a2 < 3 )
        return -2;
      if ( !(*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 90))(a1, a2) )
      {
        v5 = a2 + 3;
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
      v5 = a2 + 4;
      break;
    case 9:
      v7 = a2 + 1;
      if ( v7 == a3 )
        return -1;
      if ( a1[*v7 + 76] == 10 )
        ++v7;
      *a4 = v7;
      return 7;
    case 0xA:
      *a4 = a2 + 1;
      return 7;
    default:
      v5 = a2 + 1;
      break;
  }
  while ( v5 != a3 )
  {
    switch ( a1[*v5 + 76] )
    {
      case 0:
      case 1:
      case 4:
      case 8:
      case 9:
      case 0xA:
        *a4 = v5;
        return 6;
      case 5:
        if ( a3 - v5 < 2 || (*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 89))(a1, v5) )
        {
          *a4 = v5;
          return 6;
        }
        v5 += 2;
        continue;
      case 6:
        if ( a3 - v5 < 3 || (*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 90))(a1, v5) )
        {
          *a4 = v5;
          return 6;
        }
        v5 += 3;
        continue;
      case 7:
        if ( a3 - v5 < 4 || (*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 91))(a1, v5) )
        {
          *a4 = v5;
          return 6;
        }
        v5 += 4;
        break;
      default:
        ++v5;
        continue;
    }
  }
  *a4 = v5;
  return 6;
}
