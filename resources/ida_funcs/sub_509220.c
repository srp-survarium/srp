int __cdecl sub_509220(int a1, int a2, int a3, int a4)
{
  int v5; // [esp+Ch] [ebp-18h]
  int v6; // [esp+Ch] [ebp-18h]
  unsigned __int8 *v7; // [esp+10h] [ebp-14h]
  unsigned __int8 *v8; // [esp+14h] [ebp-10h]
  int v9; // [esp+18h] [ebp-Ch]
  int v10; // [esp+1Ch] [ebp-8h]
  unsigned __int8 *v11; // [esp+20h] [ebp-4h]

  v10 = -1;
  v9 = 0;
  v11 = (unsigned __int8 *)(a1 + 3);
  while ( 2 )
  {
    while ( 2 )
    {
      switch ( *v11 )
      {
        case 0u:
        case 0x71u:
        case 0x72u:
        case 0x98u:
        case 0x99u:
          if ( v10 >= 0 )
          {
            if ( v10 != v9 )
              return -1;
          }
          else
          {
            v10 = v9;
          }
          if ( *v11 != 113 )
            return v10;
          v11 += 3;
          v9 = 0;
          continue;
        case 1u:
        case 2u:
        case 3u:
        case 4u:
        case 5u:
        case 0x17u:
        case 0x18u:
        case 0x19u:
        case 0x1Au:
        case 0x1Bu:
        case 0x1Cu:
        case 0x70u:
        case 0x76u:
        case 0x87u:
        case 0x88u:
        case 0x89u:
        case 0x8Au:
        case 0x8Bu:
        case 0x90u:
        case 0x92u:
        case 0x94u:
        case 0x96u:
        case 0x97u:
        case 0x9Au:
          v11 += (unsigned __int8)_pcre_OP_lengths[*v11];
          continue;
        case 6u:
        case 7u:
        case 8u:
        case 9u:
        case 0xAu:
        case 0xBu:
        case 0xCu:
        case 0xDu:
        case 0x12u:
        case 0x13u:
        case 0x14u:
        case 0x15u:
          goto LABEL_41;
        case 0xEu:
          return -2;
        case 0xFu:
        case 0x10u:
          v11 += 2;
LABEL_41:
          ++v9;
          ++v11;
          continue;
        case 0x11u:
        case 0x16u:
        case 0x21u:
        case 0x22u:
        case 0x23u:
        case 0x24u:
        case 0x25u:
        case 0x26u:
        case 0x27u:
        case 0x28u:
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
        case 0x37u:
        case 0x38u:
        case 0x39u:
        case 0x3Au:
        case 0x3Bu:
        case 0x3Cu:
        case 0x3Du:
        case 0x3Eu:
        case 0x3Fu:
        case 0x40u:
        case 0x41u:
        case 0x42u:
        case 0x44u:
        case 0x45u:
        case 0x46u:
        case 0x47u:
        case 0x48u:
        case 0x49u:
        case 0x4Au:
        case 0x4Bu:
        case 0x4Cu:
        case 0x4Du:
        case 0x4Eu:
        case 0x4Fu:
        case 0x51u:
        case 0x52u:
        case 0x53u:
        case 0x54u:
        case 0x55u:
        case 0x56u:
        case 0x57u:
        case 0x58u:
        case 0x59u:
        case 0x5Au:
        case 0x5Bu:
        case 0x5Cu:
        case 0x5Eu:
        case 0x5Fu:
        case 0x60u:
        case 0x61u:
        case 0x6Du:
        case 0x6Eu:
        case 0x73u:
        case 0x74u:
        case 0x75u:
        case 0x7Eu:
        case 0x80u:
        case 0x82u:
        case 0x83u:
        case 0x84u:
        case 0x85u:
        case 0x86u:
        case 0x8Cu:
        case 0x8Du:
        case 0x8Eu:
        case 0x9Bu:
          return -1;
        case 0x1Du:
        case 0x1Eu:
        case 0x1Fu:
        case 0x20u:
          ++v9;
          v11 += 2;
          if ( a2 )
          {
            if ( *(v11 - 1) >= 0xC0u )
              v11 += (unsigned __int8)_pcre_utf8_table4[*(v11 - 1) & 0x3F];
          }
          continue;
        case 0x29u:
        case 0x36u:
        case 0x43u:
        case 0x50u:
          v9 += v11[2] | (v11[1] << 8);
          v11 += 4;
          if ( a2 && *(v11 - 1) >= 0xC0u )
            v11 += (unsigned __int8)_pcre_utf8_table4[*(v11 - 1) & 0x3F];
          continue;
        case 0x5Du:
          v9 += v11[2] | (v11[1] << 8);
          if ( v11[3] == 16 || v11[3] == 15 )
            v11 += 2;
          v11 += 4;
          continue;
        case 0x6Au:
        case 0x6Bu:
          goto LABEL_44;
        case 0x6Cu:
          v11 = &v11[(v11[2] | (v11[1] << 8)) - 33];
          break;
        case 0x6Fu:
          if ( !a3 )
            return -3;
          v7 = (unsigned __int8 *)(*(_DWORD *)(a4 + 20) + (v11[2] | (v11[1] << 8)));
          v8 = v7;
          do
            v7 += v7[2] | (v7[1] << 8);
          while ( *v7 == 113 );
          if ( v11 > v8 && v11 < v7 )
            return -1;
          v6 = sub_509220(v8 + 2, a2, a3, a4);
          if ( v6 < 0 )
            return v6;
          v9 += v6;
          v11 += 3;
          continue;
        case 0x77u:
        case 0x78u:
        case 0x79u:
        case 0x7Au:
          do
            v11 += v11[2] | (v11[1] << 8);
          while ( *v11 == 113 );
          goto LABEL_26;
        case 0x7Bu:
        case 0x7Cu:
        case 0x7Du:
        case 0x7Fu:
        case 0x81u:
          v5 = sub_509220(&v11[*v11 != 127 ? 0 : 2], a2, a3, a4);
          if ( v5 < 0 )
            return v5;
          v9 += v5;
          do
            v11 += v11[2] | (v11[1] << 8);
          while ( *v11 == 113 );
          v11 += 3;
          continue;
        case 0x8Fu:
        case 0x91u:
        case 0x93u:
        case 0x95u:
LABEL_26:
          v11 += v11[1] + (unsigned __int8)_pcre_OP_lengths[*v11];
          continue;
        default:
          return -4;
      }
      break;
    }
LABEL_44:
    v11 += 33;
    switch ( *v11 )
    {
      case 'b':
      case 'c':
      case 'd':
      case 'e':
      case 'f':
      case 'g':
        return -1;
      case 'h':
      case 'i':
        if ( (v11[2] | (v11[1] << 8)) == (v11[4] | (v11[3] << 8)) )
        {
          v9 += v11[2] | (v11[1] << 8);
          v11 += 5;
          continue;
        }
        return -1;
      default:
        ++v9;
        continue;
    }
  }
}
