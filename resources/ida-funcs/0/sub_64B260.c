int __cdecl sub_64B260(_BYTE *a1, _BYTE *a2, _BYTE *a3, _DWORD *a4)
{
  int result; // eax
  _BYTE *v5; // [esp+10h] [ebp+Ch]
  _BYTE *v6; // [esp+10h] [ebp+Ch]

  if ( a2 == a3 )
    return -1;
  if ( *a2 != 45 )
  {
    *a4 = a2;
    return 0;
  }
  v5 = a2 + 1;
  while ( 2 )
  {
    if ( v5 == a3 )
      return -1;
    switch ( a1[(unsigned __int8)*v5 + 76] )
    {
      case 0:
      case 1:
      case 8:
        *a4 = v5;
        return 0;
      case 5:
        if ( a3 - v5 < 2 )
          return -2;
        if ( (*((int (__cdecl **)(_BYTE *, _BYTE *))a1 + 89))(a1, v5) )
        {
          *a4 = v5;
          return 0;
        }
        v5 += 2;
        continue;
      case 6:
        if ( a3 - v5 < 3 )
          return -2;
        if ( (*((int (__cdecl **)(_BYTE *, _BYTE *))a1 + 90))(a1, v5) )
        {
          *a4 = v5;
          return 0;
        }
        v5 += 3;
        continue;
      case 7:
        if ( a3 - v5 < 4 )
          return -2;
        if ( (*((int (__cdecl **)(_BYTE *, _BYTE *))a1 + 91))(a1, v5) )
        {
          *a4 = v5;
          return 0;
        }
        v5 += 4;
        continue;
      case 0x1B:
        if ( ++v5 == a3 )
          return -1;
        if ( *v5 != 45 )
          continue;
        v6 = v5 + 1;
        if ( v6 == a3 )
        {
          result = -1;
        }
        else if ( *v6 == 62 )
        {
          *a4 = v6 + 1;
          result = 13;
        }
        else
        {
          *a4 = v6;
          result = 0;
        }
        break;
      default:
        ++v5;
        continue;
    }
    break;
  }
  return result;
}
