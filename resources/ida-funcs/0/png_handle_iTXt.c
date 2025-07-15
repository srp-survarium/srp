int __cdecl png_handle_iTXt(int a1, _DWORD *a2, int a3)
{
  int result; // eax
  _DWORD *pointer; // [esp+0h] [ebp-2Ch]
  char *j; // [esp+4h] [ebp-28h]
  unsigned int v6; // [esp+4h] [ebp-28h]
  int v7; // [esp+8h] [ebp-24h]
  int v8; // [esp+Ch] [ebp-20h]
  int v9; // [esp+10h] [ebp-1Ch]
  _BYTE *i; // [esp+14h] [ebp-18h]
  char *v11; // [esp+14h] [ebp-18h]
  char *v12; // [esp+14h] [ebp-18h]
  char *v13; // [esp+14h] [ebp-18h]
  unsigned int count; // [esp+18h] [ebp-14h]
  _BYTE *k; // [esp+1Ch] [ebp-10h]
  const char *v16; // [esp+1Ch] [ebp-10h]
  int v17; // [esp+20h] [ebp-Ch]
  int v18; // [esp+28h] [ebp-4h]

  if ( !*(_DWORD *)(a1 + 648) )
    goto LABEL_6;
  if ( *(_DWORD *)(a1 + 648) == 1 )
    return png_crc_finish(a1, a3);
  if ( --*(_DWORD *)(a1 + 648) == 1 )
  {
    png_warning(a1, "No space in chunk cache for iTXt");
    return png_crc_finish(a1, a3);
  }
  else
  {
LABEL_6:
    if ( (*(_DWORD *)(a1 + 108) & 1) == 0 )
      png_error(a1, (int)"Missing IHDR before iTXt");
    if ( (*(_DWORD *)(a1 + 108) & 4) != 0 )
      *(_DWORD *)(a1 + 108) |= 8u;
    png_free(a1, *(void **)(a1 + 680));
    *(_DWORD *)(a1 + 680) = png_malloc_warn(a1, a3 + 1);
    if ( *(_DWORD *)(a1 + 680) )
    {
      png_crc_read((_DWORD *)a1, *(unsigned __int8 **)(a1 + 680), a3);
      if ( png_crc_finish(a1, 0) )
      {
        result = png_free(a1, *(void **)(a1 + 680));
        *(_DWORD *)(a1 + 680) = 0;
      }
      else
      {
        *(_BYTE *)(*(_DWORD *)(a1 + 680) + a3) = 0;
        for ( i = *(_BYTE **)(a1 + 680); *i; ++i )
          ;
        v11 = i + 1;
        if ( (unsigned int)v11 < *(_DWORD *)(a1 + 680) + a3 - 3 )
        {
          v8 = *v11;
          v12 = v11 + 1;
          v17 = *v12;
          v13 = v12 + 1;
          if ( v17 || v8 )
          {
            png_warning(a1, "Unknown iTXt compression type or method");
            png_free(a1, *(void **)(a1 + 680));
            result = a1;
            *(_DWORD *)(a1 + 680) = 0;
          }
          else
          {
            for ( j = v13; *j; ++j )
              ;
            v6 = (unsigned int)(j + 1);
            if ( v6 < a3 + *(_DWORD *)(a1 + 680) )
            {
              for ( k = (_BYTE *)v6; *k; ++k )
                ;
              v16 = k + 1;
              if ( (unsigned int)v16 < a3 + *(_DWORD *)(a1 + 680) )
              {
                count = (unsigned int)&v16[-*(_DWORD *)(a1 + 680)];
                v9 = *(_DWORD *)(a1 + 680);
                v18 = lstrlenA(v16);
                pointer = (_DWORD *)png_malloc_warn(a1, 0x1Cu);
                if ( pointer )
                {
                  *pointer = 1;
                  pointer[6] = *(_DWORD *)(a1 + 680) + v6 - v9;
                  pointer[5] = &v13[*(_DWORD *)(a1 + 680) - v9];
                  pointer[4] = v18;
                  pointer[3] = 0;
                  pointer[1] = *(_DWORD *)(a1 + 680);
                  pointer[2] = count + *(_DWORD *)(a1 + 680);
                  v7 = png_set_text_2(a1, a2, (int)pointer, 1);
                  png_free(a1, pointer);
                  result = png_free(a1, *(void **)(a1 + 680));
                  *(_DWORD *)(a1 + 680) = 0;
                  if ( v7 )
                    png_error(a1, (int)"Insufficient memory to store iTXt chunk");
                }
                else
                {
                  png_warning(a1, "Not enough memory to process iTXt chunk");
                  result = png_free(a1, *(void **)(a1 + 680));
                  *(_DWORD *)(a1 + 680) = 0;
                }
              }
              else
              {
                png_warning(a1, "Malformed iTXt chunk");
                png_free(a1, *(void **)(a1 + 680));
                result = a1;
                *(_DWORD *)(a1 + 680) = 0;
              }
            }
            else
            {
              png_warning(a1, "Truncated iTXt chunk");
              png_free(a1, *(void **)(a1 + 680));
              result = a1;
              *(_DWORD *)(a1 + 680) = 0;
            }
          }
        }
        else
        {
          png_warning(a1, "Truncated iTXt chunk");
          result = png_free(a1, *(void **)(a1 + 680));
          *(_DWORD *)(a1 + 680) = 0;
        }
      }
    }
    else
    {
      return png_warning(a1, "No memory to process iTXt chunk");
    }
  }
  return result;
}
