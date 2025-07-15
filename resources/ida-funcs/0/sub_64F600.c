_BYTE *__cdecl sub_64F600(int a1, _BYTE **a2, _BYTE *a3, _DWORD *a4, int a5)
{
  _BYTE *result; // eax
  unsigned __int8 v6; // [esp+9h] [ebp-7h]
  unsigned __int8 v7; // [esp+Ah] [ebp-6h]
  unsigned __int8 v8; // [esp+Bh] [ebp-5h]
  _BYTE *v9; // [esp+Ch] [ebp-4h]

  v9 = *a2;
  while ( 2 )
  {
    if ( v9 == a3 )
    {
      result = v9;
      *a2 = v9;
    }
    else
    {
      v8 = v9[1];
      v6 = *v9;
      switch ( *v9 )
      {
        case 0:
          if ( v8 >= 0x80u )
            goto LABEL_9;
          if ( *a4 != a5 )
          {
            *(_BYTE *)(*a4)++ = v8;
            goto LABEL_2;
          }
          result = v9;
          *a2 = v9;
          break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
LABEL_9:
          if ( a5 - *a4 >= 2 )
          {
            *(_BYTE *)(*a4)++ = (4 * v6) | ((int)v8 >> 6) | 0xC0;
            *(_BYTE *)(*a4)++ = v8 & 0x3F | 0x80;
            goto LABEL_2;
          }
          result = a2;
          *a2 = v9;
          break;
        case 0xD8:
        case 0xD9:
        case 0xDA:
        case 0xDB:
          if ( a5 - *a4 >= 4 )
          {
            *(_BYTE *)(*a4)++ = (((((int)v8 >> 6) & 3 | (4 * (v6 & 3))) + 1) >> 2) | 0xF0;
            *(_BYTE *)(*a4)++ = (16 * (((((int)v8 >> 6) & 3 | (4 * (v6 & 3))) + 1) & 3)) | ((int)v8 >> 2) & 0xF | 0x80;
            v9 += 2;
            v7 = v9[1];
            *(_BYTE *)(*a4)++ = ((int)v7 >> 6) | (4 * (*v9 & 3)) | (16 * (v8 & 3)) | 0x80;
            *(_BYTE *)(*a4)++ = v7 & 0x3F | 0x80;
            goto LABEL_2;
          }
          result = a2;
          *a2 = v9;
          break;
        default:
          if ( a5 - *a4 >= 3 )
          {
            *(_BYTE *)(*a4)++ = ((int)v6 >> 4) | 0xE0;
            *(_BYTE *)(*a4)++ = ((int)v8 >> 6) | (4 * (v6 & 0xF)) | 0x80;
            *(_BYTE *)(*a4)++ = v8 & 0x3F | 0x80;
LABEL_2:
            v9 += 2;
            continue;
          }
          result = a2;
          *a2 = v9;
          break;
      }
    }
    return result;
  }
}
