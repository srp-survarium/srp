BOOL __cdecl png_check_fp_number(int a1, unsigned int a2, int *a3, unsigned int *a4)
{
  int v5; // [esp+8h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-8h]
  unsigned int v7; // [esp+10h] [ebp-4h]

  v6 = *a3;
  v7 = *a4;
  while ( 2 )
  {
    if ( v7 < a2 )
    {
      switch ( *(_BYTE *)(v7 + a1) )
      {
        case '+':
          v5 = 4;
          goto LABEL_10;
        case '-':
          v5 = 132;
          goto LABEL_10;
        case '.':
          v5 = 16;
          goto LABEL_10;
        case '0':
          v5 = 8;
          goto LABEL_10;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
          v5 = 264;
          goto LABEL_10;
        case 'E':
        case 'e':
          v5 = 32;
LABEL_10:
          switch ( (v5 & 0x3C) + (v6 & 3) )
          {
            case 4:
              if ( (v6 & 0x3C) == 0 )
              {
                v6 |= v5;
                break;
              }
              goto LABEL_29;
            case 6:
              if ( (v6 & 0x3C) == 0 )
              {
                v6 |= 4u;
                break;
              }
              goto LABEL_29;
            case 8:
              if ( (v6 & 0x10) != 0 )
                v6 = v6 & 0x1C0 | 0x11;
              v6 |= v5 | 0x40;
              break;
            case 9:
              v6 |= v5 | 0x40;
              break;
            case 0xA:
              v6 |= 0x48u;
              break;
            case 0x10:
              if ( (v6 & 0x10) != 0 )
                goto LABEL_29;
              if ( (v6 & 8) != 0 )
                v6 |= v5;
              else
                v6 = v6 & 0x1C0 | v5 | 1;
              break;
            case 0x20:
              if ( (v6 & 8) == 0 )
                goto LABEL_29;
              v6 = v6 & 0x1C0 | 2;
              break;
            case 0x21:
              if ( (v6 & 8) == 0 )
                goto LABEL_29;
              v6 = v6 & 0x1C0 | 2;
              break;
            default:
              goto LABEL_29;
          }
          ++v7;
          continue;
        default:
          goto LABEL_29;
      }
    }
    break;
  }
LABEL_29:
  *a3 = v6;
  *a4 = v7;
  return (v6 & 8) != 0;
}
