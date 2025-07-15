unsigned __int8 *__cdecl sub_64F1E0(int a1, unsigned __int8 **a2, unsigned __int8 *a3, _DWORD *a4, int a5)
{
  unsigned __int8 *result; // eax
  unsigned __int8 v6; // [esp+9h] [ebp-7h]
  unsigned __int8 v7; // [esp+Ah] [ebp-6h]
  unsigned __int8 v8; // [esp+Bh] [ebp-5h]
  unsigned __int8 *v9; // [esp+Ch] [ebp-4h]

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
      v8 = *v9;
      v6 = v9[1];
      switch ( v6 )
      {
        case 0u:
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
        case 1u:
        case 2u:
        case 3u:
        case 4u:
        case 5u:
        case 6u:
        case 7u:
LABEL_9:
          if ( a5 - *a4 >= 2 )
          {
            *(_BYTE *)(*a4)++ = (4 * v6) | ((int)v8 >> 6) | 0xC0;
            *(_BYTE *)(*a4)++ = v8 & 0x3F | 0x80;
            goto LABEL_2;
          }
          result = (unsigned __int8 *)a2;
          *a2 = v9;
          break;
        case 0xD8u:
        case 0xD9u:
        case 0xDAu:
        case 0xDBu:
          if ( a5 - *a4 >= 4 )
          {
            *(_BYTE *)(*a4)++ = (((((int)v8 >> 6) & 3 | (4 * (v6 & 3))) + 1) >> 2) | 0xF0;
            *(_BYTE *)(*a4)++ = (16 * (((((int)v8 >> 6) & 3 | (4 * (v6 & 3))) + 1) & 3)) | ((int)v8 >> 2) & 0xF | 0x80;
            v9 += 2;
            v7 = *v9;
            *(_BYTE *)(*a4)++ = ((int)*v9 >> 6) | (4 * (v9[1] & 3)) | (16 * (v8 & 3)) | 0x80;
            *(_BYTE *)(*a4)++ = v7 & 0x3F | 0x80;
            goto LABEL_2;
          }
          result = (unsigned __int8 *)a2;
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
          result = (unsigned __int8 *)a2;
          *a2 = v9;
          break;
      }
    }
    return result;
  }
}
