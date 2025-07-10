int __cdecl png_handle_unknown(int a1, int a2, unsigned int size)
{
  int v4; // [esp+0h] [ebp-8h]
  unsigned int v5; // [esp+4h] [ebp-4h]

  v5 = 0;
  if ( !*(_DWORD *)(a1 + 648) )
    goto LABEL_7;
  if ( *(_DWORD *)(a1 + 648) == 1 )
    return png_crc_finish(a1, size);
  if ( --*(_DWORD *)(a1 + 648) == 1 )
  {
    png_warning(a1, "No space in chunk cache for unknown chunk");
    return png_crc_finish(a1, size);
  }
  else
  {
LABEL_7:
    if ( (*(_DWORD *)(a1 + 108) & 4) != 0 && *(_DWORD *)(a1 + 256) != 1229209940 )
      *(_DWORD *)(a1 + 108) |= 8u;
    if ( ((*(_DWORD *)(a1 + 256) >> 29) & 1) == 0
      && png_chunk_unknown_handling(a1, *(_DWORD *)(a1 + 256)) != 3
      && !*(_DWORD *)(a1 + 580) )
    {
      png_chunk_error(a1, (int)"unknown critical chunk");
    }
    if ( (*(_DWORD *)(a1 + 112) & 0x8000) != 0 || *(_DWORD *)(a1 + 580) )
    {
      *(_BYTE *)(a1 + 656) = HIBYTE(*(_DWORD *)(a1 + 256));
      *(_BYTE *)(a1 + 657) = BYTE2(*(_DWORD *)(a1 + 256));
      *(_BYTE *)(a1 + 658) = BYTE1(*(_DWORD *)(a1 + 256));
      *(_BYTE *)(a1 + 659) = *(_BYTE *)(a1 + 256);
      *(_BYTE *)(a1 + 660) = 0;
      *(_DWORD *)(a1 + 668) = size;
      if ( size )
      {
        *(_DWORD *)(a1 + 664) = png_malloc(a1, size);
        png_crc_read((_DWORD *)a1, *(unsigned __int8 **)(a1 + 664), size);
      }
      else
      {
        *(_DWORD *)(a1 + 664) = 0;
      }
      if ( *(_DWORD *)(a1 + 580) )
      {
        v4 = (*(int (__cdecl **)(int, int))(a1 + 580))(a1, a1 + 656);
        if ( v4 < 0 )
          png_chunk_error(a1, (int)"error in user chunk");
        if ( !v4 )
        {
          if ( ((*(_DWORD *)(a1 + 256) >> 29) & 1) == 0 && png_chunk_unknown_handling(a1, *(_DWORD *)(a1 + 256)) != 3 )
            png_chunk_error(a1, (int)"unknown critical chunk");
          png_set_unknown_chunks(a1, a2, a1 + 656, 1);
        }
      }
      else
      {
        png_set_unknown_chunks(a1, a2, a1 + 656, 1);
      }
      png_free(a1, *(void **)(a1 + 664));
      *(_DWORD *)(a1 + 664) = 0;
    }
    else
    {
      v5 = size;
    }
    return png_crc_finish(a1, v5);
  }
}
