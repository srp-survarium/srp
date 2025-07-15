int __cdecl sub_62DB10(unsigned __int8 *a1, int a2, int a3)
{
  int v4; // [esp+0h] [ebp-18h]
  unsigned __int8 *v5; // [esp+10h] [ebp-8h]
  _BYTE *v6; // [esp+10h] [ebp-8h]
  int v7; // [esp+14h] [ebp-4h]

  do
  {
    v5 = sub_62C170(&a1[(unsigned __int8)_pcre_OP_lengths[*a1]], 0);
    v7 = *v5;
    if ( v7 == 129 )
    {
      v6 = v5 + 3;
      if ( *v6 == 112 )
        v6 += 6;
      if ( *v6 >= 0x87u && *v6 <= 0x8Bu )
        return 0;
      if ( !sub_62DB10(v6, a2, a3) )
        return 0;
      do
        v6 += (unsigned __int8)v6[2] | ((unsigned __int8)v6[1] << 8);
      while ( *v6 == 113 );
      v5 = sub_62C170(v6 + 3, 0);
      v7 = *v5;
    }
    switch ( v7 )
    {
      case 125:
      case 126:
      case 130:
      case 131:
        if ( !sub_62DB10(v5, a2, a3) )
          return 0;
        break;
      case 127:
      case 128:
      case 132:
      case 133:
        if ( (v5[4] | (v5[3] << 8)) >= 32 )
          v4 = 1;
        else
          v4 = 1 << v5[4];
        if ( !sub_62DB10(v5, v4 | a2, a3) )
          return 0;
        break;
      case 119:
      case 123:
      case 124:
        if ( !sub_62DB10(v5, a2, a3) )
          return 0;
        break;
      case 85:
      case 86:
      case 94:
        if ( v5[1] != 12 || (a3 & a2) != 0 )
          return 0;
        break;
      case 25:
      case 26:
        break;
      default:
        return 0;
    }
    a1 += a1[2] | (a1[1] << 8);
  }
  while ( *a1 == 113 );
  return 1;
}
