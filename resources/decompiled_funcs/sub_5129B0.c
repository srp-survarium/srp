int __cdecl sub_5129B0(unsigned __int8 *a1, int a2)
{
  int v3; // [esp+4h] [ebp-18h]
  unsigned __int8 *v4; // [esp+8h] [ebp-14h]
  int v5; // [esp+10h] [ebp-Ch]
  int v6; // [esp+18h] [ebp-4h]

  v6 = -1;
  while ( 2 )
  {
    if ( *a1 == 127 || *a1 == 132 || *a1 == 128 || *a1 == 133 )
      v3 = 2;
    else
      v3 = 0;
    v4 = sub_510DD0(&a1[v3 + 3], 1);
    switch ( *v4 )
    {
      case 0x1Du:
      case 0x23u:
      case 0x24u:
      case 0x2Bu:
        goto LABEL_17;
      case 0x1Eu:
      case 0x30u:
      case 0x31u:
      case 0x38u:
        goto LABEL_25;
      case 0x29u:
        v4 += 2;
LABEL_17:
        if ( !a2 )
          return -1;
        if ( v6 >= 0 )
        {
          if ( v6 != v4[1] )
            return -1;
        }
        else
        {
          v6 = v4[1];
        }
        goto LABEL_31;
      case 0x36u:
        v4 += 2;
LABEL_25:
        if ( !a2 )
          return -1;
        if ( v6 >= 0 )
        {
          if ( v6 != v4[1] )
            return -1;
        }
        else
        {
          v6 = v4[1] | 0x100;
        }
LABEL_31:
        a1 += a1[2] | (a1[1] << 8);
        if ( *a1 == 113 )
          continue;
        return v6;
      case 0x77u:
      case 0x7Bu:
      case 0x7Cu:
      case 0x7Du:
      case 0x7Eu:
      case 0x7Fu:
      case 0x80u:
      case 0x81u:
      case 0x84u:
      case 0x85u:
        v5 = sub_5129B0(v4, *v4 == 119);
        if ( v5 < 0 )
          return -1;
        if ( v6 >= 0 )
        {
          if ( v6 != v5 )
            return -1;
        }
        else
        {
          v6 = v5;
        }
        goto LABEL_31;
      default:
        return -1;
    }
  }
}
