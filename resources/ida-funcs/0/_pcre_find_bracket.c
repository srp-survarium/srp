unsigned __int8 *__usercall _pcre_find_bracket@<eax>(unsigned __int8 *a1@<edx>, unsigned __int8 *a2, int a3, int a4)
{
  unsigned __int8 *v5; // kr00_4
  unsigned __int8 *v6; // [esp+Ch] [ebp-4h]

  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
LABEL_1:
          v6 = (unsigned __int8 *)*a2;
          if ( !*a2 )
            return 0;
          if ( v6 != (unsigned __int8 *)108 )
            break;
          a1 = (unsigned __int8 *)a2[2];
          a2 += (unsigned int)a1 | (a2[1] << 8);
        }
        if ( v6 != (unsigned __int8 *)118 )
          break;
        if ( a4 < 0 )
          return a2;
        a2 += unk_888F56;
      }
      if ( v6 == (unsigned __int8 *)127
        || v6 == (unsigned __int8 *)132
        || v6 == (unsigned __int8 *)128
        || v6 == (unsigned __int8 *)133 )
      {
        break;
      }
      v5 = a1;
      a1 = v6 - 85;
      switch ( *a2 )
      {
        case 0x55u:
        case 0x56u:
        case 0x57u:
        case 0x58u:
        case 0x59u:
        case 0x5Au:
        case 0x5Eu:
        case 0x5Fu:
        case 0x60u:
          a1 = (unsigned __int8 *)a2[1];
          if ( a1 == (unsigned __int8 *)16 || a2[1] == 15 )
          {
            a1 = a2 + 2;
            a2 += 2;
          }
          break;
        case 0x5Bu:
        case 0x5Cu:
        case 0x5Du:
        case 0x61u:
          if ( a2[3] == 16 || (a1 = a2, a2[3] == 15) )
            a2 += 2;
          break;
        case 0x8Fu:
        case 0x91u:
        case 0x93u:
          a1 = a2;
          a2 += a2[1];
          break;
        case 0x95u:
          a1 = &a2[a2[1]];
          a2 = a1;
          break;
        default:
          a1 = v5;
          break;
      }
      a2 += (unsigned __int8)_pcre_OP_lengths[(_DWORD)v6];
      if ( a3 )
      {
        a1 = v6;
        switch ( (unsigned int)v6 )
        {
          case 0x1Du:
          case 0x1Eu:
          case 0x21u:
          case 0x22u:
          case 0x23u:
          case 0x24u:
          case 0x25u:
          case 0x26u:
          case 0x27u:
          case 0x28u:
          case 0x29u:
          case 0x2Au:
          case 0x2Bu:
          case 0x2Cu:
          case 0x2Du:
          case 0x2Eu:
          case 0x2Fu:
          case 0x30u:
          case 0x31u:
          case 0x32u:
          case 0x33u:
          case 0x34u:
          case 0x35u:
          case 0x36u:
          case 0x37u:
          case 0x38u:
          case 0x39u:
          case 0x3Au:
            if ( *(a2 - 1) >= 0xC0u )
            {
              a1 = a2;
              a2 += (unsigned __int8)_pcre_utf8_table4[*(a2 - 1) & 0x3F];
            }
            break;
          default:
            goto LABEL_1;
        }
      }
    }
    if ( (a2[4] | (a2[3] << 8)) == a4 )
      return a2;
    a1 = &a2[(unsigned __int8)_pcre_OP_lengths[(_DWORD)v6]];
    a2 = a1;
  }
}
