int __cdecl sub_64DA40(int a1, _BYTE *a2, unsigned __int8 *a3, unsigned __int8 *a4, unsigned __int8 **a5)
{
  int result; // eax
  int v6; // [esp+8h] [ebp-4h]

  while ( a3 != a4 )
  {
    v6 = (unsigned __int8)a2[*a3 + 76];
    switch ( a2[*a3 + 76] )
    {
      case 0:
      case 1:
      case 8:
        *a5 = a3;
        return 0;
      case 5:
        if ( a4 - a3 < 2 )
          return -2;
        if ( (*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a2 + 89))(a2, a3) )
        {
          *a5 = a3;
          return 0;
        }
        a3 += 2;
        continue;
      case 6:
        if ( a4 - a3 < 3 )
          return -2;
        if ( (*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a2 + 90))(a2, a3) )
        {
          *a5 = a3;
          return 0;
        }
        a3 += 3;
        continue;
      case 7:
        if ( a4 - a3 < 4 )
          return -2;
        if ( (*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a2 + 91))(a2, a3) )
        {
          *a5 = a3;
          return 0;
        }
        a3 += 4;
        break;
      case 0xC:
      case 0xD:
        ++a3;
        if ( v6 != a1 )
          continue;
        if ( a3 == a4 )
          return -27;
        *a5 = a3;
        switch ( a2[*a3 + 76] )
        {
          case 9:
          case 0xA:
          case 0xB:
          case 0x14:
          case 0x15:
          case 0x1E:
            result = 27;
            break;
          default:
            result = 0;
            break;
        }
        return result;
      default:
        ++a3;
        continue;
    }
  }
  return -1;
}
