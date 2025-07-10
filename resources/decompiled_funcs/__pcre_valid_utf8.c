int __cdecl _pcre_valid_utf8(_BYTE *a1, int a2, _DWORD *a3)
{
  int v3; // ecx
  int result; // eax
  int v5; // [esp+4h] [ebp-10h]
  int v6; // [esp+8h] [ebp-Ch]
  int v7; // [esp+Ch] [ebp-8h]
  _BYTE *i; // [esp+10h] [ebp-4h]
  _BYTE *j; // [esp+10h] [ebp-4h]
  _BYTE *v10; // [esp+10h] [ebp-4h]
  _BYTE *v11; // [esp+10h] [ebp-4h]
  _BYTE *v12; // [esp+10h] [ebp-4h]
  _BYTE *v13; // [esp+10h] [ebp-4h]
  _BYTE *v14; // [esp+10h] [ebp-4h]
  _BYTE *v15; // [esp+10h] [ebp-4h]

  if ( a2 < 0 )
  {
    for ( i = a1; *i; ++i )
      ;
    a2 = i - a1;
  }
  for ( j = a1; ; ++j )
  {
    v3 = a2--;
    if ( v3 <= 0 )
      return 0;
    v5 = (unsigned __int8)*j;
    if ( (unsigned int)v5 >= 0x80 )
      break;
LABEL_7:
    ;
  }
  if ( (unsigned __int8)*j >= 0xC0u )
  {
    if ( (unsigned __int8)*j < 0xFEu )
    {
      v7 = (unsigned __int8)_pcre_utf8_table4[v5 & 0x3F];
      if ( a2 >= v7 )
      {
        a2 -= v7;
        v6 = (unsigned __int8)*++j;
        if ( (v6 & 0xC0) == 0x80 )
        {
          switch ( v5 & 0x3F )
          {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 0xA:
            case 0xB:
            case 0xC:
            case 0xD:
            case 0xE:
            case 0xF:
            case 0x10:
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x14:
            case 0x15:
            case 0x16:
            case 0x17:
            case 0x18:
            case 0x19:
            case 0x1A:
            case 0x1B:
            case 0x1C:
            case 0x1D:
            case 0x1E:
            case 0x1F:
            case 0x54:
            case 0x58:
            case 0x5C:
            case 0x60:
            case 0x64:
              if ( (v5 & 0x3E) != 0 )
                goto LABEL_64;
              *a3 = j - a1 - 1;
              result = 15;
              break;
            case 0x20:
            case 0x21:
            case 0x22:
            case 0x23:
            case 0x24:
            case 0x25:
            case 0x26:
            case 0x27:
            case 0x28:
            case 0x29:
            case 0x2A:
            case 0x2B:
            case 0x2C:
            case 0x2D:
            case 0x2E:
            case 0x2F:
            case 0x68:
            case 0x6C:
            case 0x70:
              if ( (*++j & 0xC0) == 0x80 )
              {
                if ( v5 != 224 || (v6 & 0x20) != 0 )
                {
                  if ( v5 != 237 || v6 < 160 )
                    goto LABEL_64;
                  *a3 = j - a1 - 2;
                  result = 14;
                }
                else
                {
                  *a3 = j - a1 - 2;
                  result = 16;
                }
              }
              else
              {
                *a3 = j - a1 - 2;
                result = 7;
              }
              break;
            case 0x30:
            case 0x31:
            case 0x32:
            case 0x33:
            case 0x34:
            case 0x35:
            case 0x36:
            case 0x37:
            case 0x74:
            case 0x78:
            case 0x7C:
              v10 = j + 1;
              if ( (*v10 & 0xC0) == 0x80 )
              {
                j = v10 + 1;
                if ( (*j & 0xC0) == 0x80 )
                {
                  if ( v5 != 240 || (v6 & 0x30) != 0 )
                  {
                    if ( v5 <= 244 && (v5 != 244 || v6 <= 143) )
                      goto LABEL_64;
                    *a3 = j - a1 - 3;
                    result = 13;
                  }
                  else
                  {
                    *a3 = j - a1 - 3;
                    result = 17;
                  }
                }
                else
                {
                  *a3 = j - a1 - 3;
                  result = 8;
                }
              }
              else
              {
                *a3 = v10 - a1 - 2;
                result = 7;
              }
              break;
            case 0x38:
            case 0x39:
            case 0x3A:
            case 0x3B:
            case 0x80:
            case 0x84:
            case 0x88:
            case 0x8C:
            case 0x90:
            case 0x94:
            case 0x98:
              v11 = j + 1;
              if ( (*v11 & 0xC0) == 0x80 )
              {
                v12 = v11 + 1;
                if ( (*v12 & 0xC0) == 0x80 )
                {
                  j = v12 + 1;
                  if ( (*j & 0xC0) == 0x80 )
                  {
                    if ( v5 != 248 || (v6 & 0x38) != 0 )
                      goto LABEL_64;
                    *a3 = j - a1 - 4;
                    result = 18;
                  }
                  else
                  {
                    *a3 = j - a1 - 4;
                    result = 9;
                  }
                }
                else
                {
                  *a3 = v12 - a1 - 3;
                  result = 8;
                }
              }
              else
              {
                *a3 = v11 - a1 - 2;
                result = 7;
              }
              break;
            case 0x3C:
            case 0x3D:
            case 0x3E:
            case 0x3F:
            case 0x9C:
            case 0xA0:
            case 0xA4:
            case 0xA8:
              v13 = j + 1;
              if ( (*v13 & 0xC0) == 0x80 )
              {
                v14 = v13 + 1;
                if ( (*v14 & 0xC0) == 0x80 )
                {
                  v15 = v14 + 1;
                  if ( (*v15 & 0xC0) == 0x80 )
                  {
                    j = v15 + 1;
                    if ( (*j & 0xC0) == 0x80 )
                    {
                      if ( v5 != 252 || (v6 & 0x3C) != 0 )
                        goto LABEL_64;
                      *a3 = j - a1 - 5;
                      result = 19;
                    }
                    else
                    {
                      *a3 = j - a1 - 5;
                      result = 10;
                    }
                  }
                  else
                  {
                    *a3 = v15 - a1 - 4;
                    result = 9;
                  }
                }
                else
                {
                  *a3 = v14 - a1 - 3;
                  result = 8;
                }
              }
              else
              {
                *a3 = v13 - a1 - 2;
                result = 7;
              }
              break;
            default:
LABEL_64:
              if ( (unsigned __int8)_pcre_utf8_table4[v5 & 0x3F] <= 3u )
                goto LABEL_7;
              *a3 = j - a1 - v7;
              result = (v7 != 4) + 11;
              break;
          }
        }
        else
        {
          *a3 = j - a1 - 1;
          return 6;
        }
      }
      else
      {
        *a3 = j - a1;
        return v7 - a2;
      }
    }
    else
    {
      *a3 = j - a1;
      return 21;
    }
  }
  else
  {
    *a3 = j - a1;
    return 20;
  }
  return result;
}
