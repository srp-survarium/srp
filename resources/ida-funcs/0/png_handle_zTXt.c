int __cdecl png_handle_zTXt(int a1, _DWORD *a2, int a3)
{
  int result; // eax
  int *pointer; // [esp+0h] [ebp-1Ch]
  int v5; // [esp+4h] [ebp-18h]
  int count; // [esp+8h] [ebp-14h]
  _BYTE *i; // [esp+Ch] [ebp-10h]
  _BYTE *v8; // [esp+Ch] [ebp-10h]
  int v9; // [esp+10h] [ebp-Ch]
  int v10; // [esp+18h] [ebp-4h] BYREF

  if ( !*(_DWORD *)(a1 + 648) )
    goto LABEL_6;
  if ( *(_DWORD *)(a1 + 648) == 1 )
    return png_crc_finish(a1, a3);
  if ( --*(_DWORD *)(a1 + 648) == 1 )
  {
    png_warning(a1, "No space in chunk cache for zTXt");
    return png_crc_finish(a1, a3);
  }
  else
  {
LABEL_6:
    if ( (*(_DWORD *)(a1 + 108) & 1) == 0 )
      png_error(a1, (int)"Missing IHDR before zTXt");
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
        if ( (unsigned int)i < *(_DWORD *)(a1 + 680) + a3 - 2 )
        {
          v8 = i + 1;
          v9 = (char)*v8;
          if ( *v8 )
          {
            png_warning(a1, "Unknown compression type in zTXt chunk");
            v9 = 0;
          }
          count = (int)&v8[-*(_DWORD *)(a1 + 680) + 1];
          png_decompress_chunk(a1, v9, a3, count, &v10);
          pointer = (int *)png_malloc_warn(a1, 0x1Cu);
          if ( pointer )
          {
            *pointer = v9;
            pointer[1] = *(_DWORD *)(a1 + 680);
            pointer[5] = 0;
            pointer[6] = 0;
            pointer[4] = 0;
            pointer[2] = count + *(_DWORD *)(a1 + 680);
            pointer[3] = v10;
            v5 = png_set_text_2(a1, a2, (int)pointer, 1);
            png_free(a1, pointer);
            result = png_free(a1, *(void **)(a1 + 680));
            *(_DWORD *)(a1 + 680) = 0;
            if ( v5 )
              png_error(a1, (int)"Insufficient memory to store zTXt chunk");
          }
          else
          {
            png_warning(a1, "Not enough memory to process zTXt chunk");
            png_free(a1, *(void **)(a1 + 680));
            result = a1;
            *(_DWORD *)(a1 + 680) = 0;
          }
        }
        else
        {
          png_warning(a1, "Truncated zTXt chunk");
          png_free(a1, *(void **)(a1 + 680));
          result = a1;
          *(_DWORD *)(a1 + 680) = 0;
        }
      }
    }
    else
    {
      return png_warning(a1, "Out of memory processing zTXt chunk");
    }
  }
  return result;
}
