int __cdecl sub_64B470(_BYTE *a1, unsigned __int8 *a2, unsigned __int8 *a3, unsigned __int8 **a4)
{
  int result; // eax
  int v6; // [esp+10h] [ebp-4h] BYREF
  unsigned __int8 *v7; // [esp+20h] [ebp+Ch]
  unsigned __int8 *v8; // [esp+20h] [ebp+Ch]

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
      break;
    case 6:
      if ( a3 - a2 < 3 )
        return -2;
      if ( !(*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 87))(a1, a2) )
      {
        *a4 = a2;
        return 0;
      }
      v7 = a2 + 3;
      break;
    case 7:
      if ( a3 - a2 < 4 )
        return -2;
      if ( !(*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 88))(a1, a2) )
      {
        *a4 = a2;
        return 0;
      }
      v7 = a2 + 4;
      break;
    case 0x16:
    case 0x18:
      v7 = a2 + 1;
      break;
    case 0x1D:
      *a4 = a2;
      return 0;
    default:
      *a4 = a2;
      return 0;
  }
  while ( 2 )
  {
    if ( v7 == a3 )
      return -1;
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
        if ( !sub_64B9D0(a1, a2, v7, &v6) )
        {
          *a4 = v7;
          return 0;
        }
        v8 = v7 + 1;
        break;
      case 0xF:
        if ( sub_64B9D0(a1, a2, v7, &v6) )
        {
          if ( ++v7 == a3 )
          {
            return -1;
          }
          else if ( *v7 == 62 )
          {
            *a4 = v7 + 1;
            return v6;
          }
          else
          {
LABEL_74:
            *a4 = v7;
            return 0;
          }
        }
        else
        {
          *a4 = v7;
          return 0;
        }
      case 0x16:
      case 0x18:
      case 0x19:
      case 0x1A:
      case 0x1B:
        ++v7;
        continue;
      case 0x1D:
        *a4 = v7;
        return 0;
      default:
        goto LABEL_74;
    }
    break;
  }
  while ( 2 )
  {
    if ( v8 == a3 )
      return -1;
    switch ( a1[*v8 + 76] )
    {
      case 0:
      case 1:
      case 8:
        *a4 = v8;
        return 0;
      case 5:
        if ( a3 - v8 < 2 )
          return -2;
        if ( (*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 89))(a1, v8) )
        {
          *a4 = v8;
          return 0;
        }
        v8 += 2;
        continue;
      case 6:
        if ( a3 - v8 < 3 )
          return -2;
        if ( (*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 90))(a1, v8) )
        {
          *a4 = v8;
          return 0;
        }
        v8 += 3;
        continue;
      case 7:
        if ( a3 - v8 < 4 )
          return -2;
        if ( (*((int (__cdecl **)(_BYTE *, unsigned __int8 *))a1 + 91))(a1, v8) )
        {
          *a4 = v8;
          return 0;
        }
        v8 += 4;
        continue;
      case 0xF:
        if ( ++v8 == a3 )
          return -1;
        if ( *v8 != 62 )
          continue;
        *a4 = v8 + 1;
        result = v6;
        break;
      default:
        ++v8;
        continue;
    }
    break;
  }
  return result;
}
