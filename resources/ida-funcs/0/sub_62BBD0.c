int __cdecl sub_62BBD0(unsigned __int8 *a1, unsigned int a2, int a3, _DWORD *a4)
{
  int result; // eax
  BOOL v5; // [esp+8h] [ebp-14h]
  unsigned __int8 *j; // [esp+Ch] [ebp-10h]
  _BYTE *v7; // [esp+Ch] [ebp-10h]
  int v8; // [esp+10h] [ebp-Ch]
  _BYTE *v9; // [esp+14h] [ebp-8h]
  int v10; // [esp+18h] [ebp-4h]
  unsigned __int8 *i; // [esp+24h] [ebp+8h]

  for ( i = (unsigned __int8 *)sub_62C170(&a1[(unsigned __int8)_pcre_OP_lengths[*a1]], 1);
        ;
        i = (unsigned __int8 *)sub_62C170(&i[(unsigned __int8)_pcre_OP_lengths[v10]], 1) )
  {
    if ( (unsigned int)i >= a2 )
      return 1;
    v10 = *i;
    switch ( v10 )
    {
      case 119:
        do
          i += i[2] | (i[1] << 8);
        while ( *i == 113 );
        v10 = *i;
        continue;
      case 111:
        for ( j = (unsigned __int8 *)a4[4]; (unsigned int)j < a4[9]; j += 2 )
        {
          if ( (unsigned __int8 *)(j[1] | (*j << 8)) == &i[-a4[5] + 1] )
            return 1;
        }
        v8 = 0;
        v7 = (_BYTE *)(a4[5] + (i[2] | (i[1] << 8)));
        if ( !((unsigned __int8)v7[2] | ((unsigned __int8)v7[1] << 8)) )
          return 1;
        while ( !sub_62BBD0(v7, a2, a3, a4) )
        {
          v7 += (unsigned __int8)v7[2] | ((unsigned __int8)v7[1] << 8);
          if ( *v7 != 113 )
            goto LABEL_18;
        }
        v8 = 1;
LABEL_18:
        if ( !v8 )
          return 0;
        continue;
      case 140:
      case 141:
      case 155:
      case 142:
        i += (unsigned __int8)_pcre_OP_lengths[v10];
        do
          i += i[2] | (i[1] << 8);
        while ( *i == 113 );
        v10 = *i;
        continue;
      case 130:
      case 131:
      case 132:
      case 133:
        do
          i += i[2] | (i[1] << 8);
        while ( *i == 113 );
        v10 = *i;
        continue;
    }
    if ( v10 != 125 && v10 != 126 && v10 != 127 && v10 != 128 && v10 != 123 && v10 != 124 && v10 != 129 )
      break;
    if ( !(i[2] | (i[1] << 8)) )
      return 1;
    if ( v10 != 129 || i[i[2] | (i[1] << 8)] == 113 )
    {
      v5 = 0;
      do
      {
        if ( !v5 )
          v5 = sub_62BBD0(i, a2, a3, a4) != 0;
        i += i[2] | (i[1] << 8);
      }
      while ( *i == 113 );
      if ( !v5 )
        return 0;
    }
    else
    {
      i += i[2] | (i[1] << 8);
    }
    v10 = *i;
LABEL_2:
    ;
  }
  switch ( *i )
  {
    case 6u:
    case 7u:
    case 8u:
    case 9u:
    case 0xAu:
    case 0xBu:
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
    case 0x10u:
    case 0x16u:
    case 0x1Du:
    case 0x1Eu:
    case 0x1Fu:
    case 0x20u:
    case 0x23u:
    case 0x24u:
    case 0x29u:
    case 0x2Bu:
    case 0x3Du:
    case 0x3Eu:
    case 0x43u:
    case 0x45u:
    case 0x57u:
    case 0x58u:
    case 0x5Du:
    case 0x5Fu:
      return 0;
    case 0x21u:
    case 0x22u:
    case 0x25u:
    case 0x26u:
    case 0x2Au:
    case 0x2Cu:
    case 0x2Eu:
    case 0x2Fu:
    case 0x32u:
    case 0x33u:
    case 0x37u:
    case 0x39u:
      if ( a3 && i[1] >= 0xC0u )
        i += (unsigned __int8)_pcre_utf8_table4[i[1] & 0x3F];
      goto LABEL_2;
    case 0x27u:
    case 0x28u:
    case 0x2Du:
    case 0x34u:
    case 0x35u:
    case 0x3Au:
      if ( a3 && i[3] >= 0xC0u )
        i += (unsigned __int8)_pcre_utf8_table4[i[3] & 0x3F];
      goto LABEL_2;
    case 0x55u:
    case 0x56u:
    case 0x59u:
    case 0x5Au:
    case 0x5Eu:
    case 0x60u:
      if ( i[1] == 16 || i[1] == 15 )
        i += 2;
      goto LABEL_2;
    case 0x5Bu:
    case 0x5Cu:
    case 0x61u:
      if ( i[3] == 16 || i[3] == 15 )
        i += 2;
      goto LABEL_2;
    case 0x6Au:
    case 0x6Bu:
      v9 = i + 33;
      goto LABEL_56;
    case 0x6Cu:
      i += i[2] | (i[1] << 8);
      v9 = i;
LABEL_56:
      switch ( *v9 )
      {
        case 'b':
        case 'c':
        case 'f':
        case 'g':
          goto LABEL_2;
        case 'h':
        case 'i':
          if ( ((unsigned __int8)v9[2] | ((unsigned __int8)v9[1] << 8)) <= 0 )
            goto LABEL_2;
          result = 0;
          break;
        default:
          result = 0;
          break;
      }
      break;
    case 0x71u:
    case 0x72u:
    case 0x73u:
    case 0x74u:
    case 0x75u:
      result = 1;
      break;
    case 0x8Fu:
    case 0x91u:
    case 0x93u:
      i += i[1];
      goto LABEL_2;
    case 0x95u:
      i += i[1];
      goto LABEL_2;
    default:
      goto LABEL_2;
  }
  return result;
}
