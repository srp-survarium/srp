int __cdecl png_handle_sPLT(int a1, int a2, unsigned int a3)
{
  int result; // eax
  _BYTE *i; // [esp+0h] [ebp-34h]
  _BYTE *v5; // [esp+0h] [ebp-34h]
  unsigned __int8 *v6; // [esp+0h] [ebp-34h]
  unsigned __int8 *v7; // [esp+0h] [ebp-34h]
  unsigned __int8 *v8; // [esp+0h] [ebp-34h]
  unsigned __int8 *v9; // [esp+0h] [ebp-34h]
  int v10; // [esp+4h] [ebp-30h] BYREF
  char v11; // [esp+8h] [ebp-2Ch]
  void *pointer; // [esp+Ch] [ebp-28h]
  int v13; // [esp+10h] [ebp-24h]
  unsigned int v14; // [esp+14h] [ebp-20h]
  int v15; // [esp+18h] [ebp-1Ch]
  unsigned int v16; // [esp+1Ch] [ebp-18h]
  int v17; // [esp+20h] [ebp-14h]
  _WORD *v18; // [esp+24h] [ebp-10h]
  unsigned int v19; // [esp+28h] [ebp-Ch]
  int j; // [esp+2Ch] [ebp-8h]
  int v21; // [esp+30h] [ebp-4h]

  v14 = 0;
  if ( !*(_DWORD *)(a1 + 648) )
    goto LABEL_6;
  if ( *(_DWORD *)(a1 + 648) == 1 )
    return png_crc_finish(a1, a3);
  if ( --*(_DWORD *)(a1 + 648) == 1 )
  {
    png_warning(a1, "No space in chunk cache for sPLT");
    return png_crc_finish(a1, a3);
  }
  else
  {
LABEL_6:
    if ( (*(_DWORD *)(a1 + 108) & 1) == 0 )
      png_error(a1, (int)"Missing IHDR before sPLT");
    if ( (*(_DWORD *)(a1 + 108) & 4) != 0 )
    {
      png_warning(a1, "Invalid sPLT after IDAT");
      return png_crc_finish(a1, a3);
    }
    else
    {
      png_free(a1, *(void **)(a1 + 680));
      *(_DWORD *)(a1 + 680) = png_malloc(a1, a3 + 1);
      v21 = a3;
      png_crc_read((_DWORD *)a1, *(unsigned __int8 **)(a1 + 680), a3);
      if ( png_crc_finish(a1, v14) )
      {
        png_free(a1, *(void **)(a1 + 680));
        result = a1;
        *(_DWORD *)(a1 + 680) = 0;
      }
      else
      {
        *(_BYTE *)(*(_DWORD *)(a1 + 680) + v21) = 0;
        for ( i = *(_BYTE **)(a1 + 680); *i; ++i )
          ;
        v5 = i + 1;
        if ( (unsigned int)v5 <= *(_DWORD *)(a1 + 680) + v21 - 2 )
        {
          v11 = *v5;
          v6 = v5 + 1;
          v16 = 4 * (v11 != 8) + 6;
          v19 = a3 - (_DWORD)&v6[-*(_DWORD *)(a1 + 680)];
          if ( v19 % v16 )
          {
            png_free(a1, *(void **)(a1 + 680));
            *(_DWORD *)(a1 + 680) = 0;
            return png_warning(a1, "sPLT chunk has bad length");
          }
          else
          {
            v15 = v19 / v16;
            v17 = 429496729;
            if ( v19 / v16 <= 0x19999999 )
            {
              v13 = v19 / v16;
              pointer = (void *)png_malloc_warn(a1, 10 * (v19 / v16));
              if ( pointer )
              {
                for ( j = 0; j < v13; ++j )
                {
                  v18 = (char *)pointer + 10 * j;
                  if ( v11 == 8 )
                  {
                    *v18 = *v6;
                    v7 = v6 + 1;
                    v18[1] = *v7++;
                    v18[2] = *v7++;
                    v18[3] = *v7;
                    v8 = v7 + 1;
                  }
                  else
                  {
                    *v18 = v6[1] + (*v6 << 8);
                    v9 = v6 + 2;
                    v18[1] = v9[1] + (*v9 << 8);
                    v9 += 2;
                    v18[2] = v9[1] + (*v9 << 8);
                    v9 += 2;
                    v18[3] = v9[1] + (*v9 << 8);
                    v8 = v9 + 2;
                  }
                  v18[4] = v8[1] + (*v8 << 8);
                  v6 = v8 + 2;
                }
                v10 = *(_DWORD *)(a1 + 680);
                png_set_sPLT(a1, a2, (int)&v10, 1);
                png_free(a1, *(void **)(a1 + 680));
                *(_DWORD *)(a1 + 680) = 0;
                return png_free(a1, pointer);
              }
              else
              {
                return png_warning(a1, aSpltChunkRequi);
              }
            }
            else
            {
              return png_warning(a1, "sPLT chunk too long");
            }
          }
        }
        else
        {
          png_free(a1, *(void **)(a1 + 680));
          *(_DWORD *)(a1 + 680) = 0;
          return png_warning(a1, "malformed sPLT chunk");
        }
      }
    }
  }
  return result;
}
