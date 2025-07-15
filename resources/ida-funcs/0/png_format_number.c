_BYTE *__cdecl png_format_number(unsigned int a1, int a2, int a3, unsigned int a4)
{
  int v5; // [esp+4h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-8h]
  int v7; // [esp+Ch] [ebp-4h]
  _BYTE *v8; // [esp+1Ch] [ebp+Ch]

  v7 = 0;
  v5 = 1;
  v6 = 0;
  v8 = (_BYTE *)(a2 - 1);
  *v8 = 0;
  while ( (unsigned int)v8 > a1 && (a4 || v7 < v5) )
  {
    switch ( a3 )
    {
      case 1:
        goto LABEL_11;
      case 2:
        v5 = 2;
LABEL_11:
        *--v8 = byte_6F1F74[a4 % 0xA];
        a4 /= 0xAu;
        break;
      case 3:
        goto LABEL_13;
      case 4:
        v5 = 2;
LABEL_13:
        *--v8 = byte_6F1F74[a4 & 0xF];
        a4 >>= 4;
        break;
      case 5:
        v5 = 5;
        if ( v6 || a4 % 0xA )
        {
          *--v8 = byte_6F1F74[a4 % 0xA];
          v6 = 1;
        }
        a4 /= 0xAu;
        break;
      default:
        a4 = 0;
        break;
    }
    ++v7;
    if ( a3 == 5 && v7 == 5 && (unsigned int)v8 > a1 )
    {
      if ( v6 )
      {
        *--v8 = 46;
      }
      else if ( !a4 )
      {
        *--v8 = 48;
      }
    }
  }
  return v8;
}
