int __cdecl sub_64E010(_BYTE *a1, _BYTE *a2, _BYTE *a3, _DWORD *a4)
{
  int v5; // [esp+8h] [ebp-4h]

  v5 = 0;
  while ( a2 != a3 )
  {
    switch ( a1[(unsigned __int8)*a2 + 76] )
    {
      case 0:
      case 1:
      case 8:
        *a4 = a2;
        return 0;
      case 2:
        if ( ++a2 == a3 )
          return -1;
        if ( *a2 != 33 )
          continue;
        if ( ++a2 == a3 )
          return -1;
        if ( *a2 == 91 )
        {
          ++v5;
          ++a2;
        }
        continue;
      case 4:
        if ( ++a2 == a3 )
          return -1;
        if ( *a2 != 93 )
          continue;
        if ( ++a2 == a3 )
          return -1;
        if ( *a2 != 62 )
          continue;
        ++a2;
        if ( !v5 )
        {
          *a4 = a2;
          return 42;
        }
        --v5;
        break;
      case 5:
        if ( a3 - a2 < 2 )
          return -2;
        if ( (*((int (__cdecl **)(_BYTE *, _BYTE *))a1 + 89))(a1, a2) )
        {
          *a4 = a2;
          return 0;
        }
        a2 += 2;
        continue;
      case 6:
        if ( a3 - a2 < 3 )
          return -2;
        if ( (*((int (__cdecl **)(_BYTE *, _BYTE *))a1 + 90))(a1, a2) )
        {
          *a4 = a2;
          return 0;
        }
        a2 += 3;
        continue;
      case 7:
        if ( a3 - a2 < 4 )
          return -2;
        if ( (*((int (__cdecl **)(_BYTE *, _BYTE *))a1 + 91))(a1, a2) )
        {
          *a4 = a2;
          return 0;
        }
        a2 += 4;
        continue;
      default:
        ++a2;
        continue;
    }
  }
  return -1;
}
