int __cdecl sub_5125D0(unsigned __int8 *a1, int a2, int a3)
{
  int v4; // [esp+0h] [ebp-14h]
  unsigned __int8 *v5; // [esp+Ch] [ebp-8h]
  int v6; // [esp+10h] [ebp-4h]

  do
  {
    v5 = sub_510DD0(&a1[(unsigned __int8)_pcre_OP_lengths[*a1]], 0);
    v6 = *v5;
    switch ( v6 )
    {
      case 125:
      case 126:
      case 130:
      case 131:
        if ( !sub_5125D0(v5, a2, a3) )
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
        if ( !sub_5125D0(v5, v4 | a2, a3) )
          return 0;
        break;
      case 119:
      case 123:
      case 124:
      case 129:
        if ( !sub_5125D0(v5, a2, a3) )
          return 0;
        break;
      case 85:
      case 86:
      case 94:
        if ( v5[1] != 13 || (a3 & a2) != 0 )
          return 0;
        break;
      case 1:
      case 2:
      case 25:
        break;
      default:
        return 0;
    }
    a1 += a1[2] | (a1[1] << 8);
  }
  while ( *a1 == 113 );
  return 1;
}
