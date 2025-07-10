unsigned int __cdecl png_read_finish_row(int a1)
{
  unsigned int result; // eax
  int v2; // [esp+4h] [ebp-8h]
  char v3; // [esp+Bh] [ebp-1h] BYREF

  ++*(_DWORD *)(a1 + 252);
  result = a1;
  if ( *(_DWORD *)(a1 + 252) >= *(_DWORD *)(a1 + 236) )
  {
    if ( !*(_BYTE *)(a1 + 312) )
      goto LABEL_11;
    *(_DWORD *)(a1 + 252) = 0;
    memset(*(_DWORD *)(a1 + 260), 0, *(_DWORD *)(a1 + 244) + 1);
    do
    {
      if ( (unsigned __int8)++*(_BYTE *)(a1 + 313) >= 7u )
        break;
      *(_DWORD *)(a1 + 248) = (*(_DWORD *)(a1 + 228)
                             + (unsigned __int8)byte_85F3B4[*(unsigned __int8 *)(a1 + 313)]
                             - 1
                             - (unsigned int)(unsigned __int8)byte_85F3AC[*(unsigned __int8 *)(a1 + 313)])
                            / (unsigned __int8)byte_85F3B4[*(unsigned __int8 *)(a1 + 313)];
      if ( (*(_DWORD *)(a1 + 116) & 2) != 0 )
        break;
      *(_DWORD *)(a1 + 236) = (*(_DWORD *)(a1 + 232)
                             + (unsigned __int8)byte_85F3C4[*(unsigned __int8 *)(a1 + 313)]
                             - 1
                             - (unsigned int)(unsigned __int8)byte_85F3BC[*(unsigned __int8 *)(a1 + 313)])
                            / (unsigned __int8)byte_85F3C4[*(unsigned __int8 *)(a1 + 313)];
    }
    while ( !*(_DWORD *)(a1 + 236) || !*(_DWORD *)(a1 + 248) );
    result = *(unsigned __int8 *)(a1 + 313);
    if ( result >= 7 )
    {
LABEL_11:
      if ( (*(_DWORD *)(a1 + 112) & 0x20) == 0 )
      {
        *(_DWORD *)(a1 + 132) = &v3;
        *(_DWORD *)(a1 + 136) = 1;
        while ( 1 )
        {
          if ( !*(_DWORD *)(a1 + 124) )
          {
            while ( !*(_DWORD *)(a1 + 288) )
            {
              png_crc_finish(a1, 0);
              *(_DWORD *)(a1 + 288) = png_read_chunk_header((_DWORD *)a1);
              if ( *(_DWORD *)(a1 + 256) != 1229209940 )
                png_error(a1, (int)"Not enough image data");
            }
            *(_DWORD *)(a1 + 124) = *(_DWORD *)(a1 + 180);
            *(_DWORD *)(a1 + 120) = *(_DWORD *)(a1 + 176);
            if ( *(_DWORD *)(a1 + 180) > *(_DWORD *)(a1 + 288) )
              *(_DWORD *)(a1 + 124) = *(_DWORD *)(a1 + 288);
            png_crc_read((_DWORD *)a1, *(unsigned __int8 **)(a1 + 176), *(_DWORD *)(a1 + 124));
            *(_DWORD *)(a1 + 288) -= *(_DWORD *)(a1 + 124);
          }
          v2 = inflate((z_stream_s *)(a1 + 120), 1);
          if ( v2 == 1 )
            break;
          if ( v2 )
          {
            if ( *(_DWORD *)(a1 + 144) )
              png_error(a1, *(_DWORD *)(a1 + 144));
            png_error(a1, (int)"Decompression Error");
          }
          if ( !*(_DWORD *)(a1 + 136) )
          {
            png_warning(a1, "Extra compressed data");
            *(_DWORD *)(a1 + 108) |= 8u;
            *(_DWORD *)(a1 + 112) |= 0x20u;
            goto LABEL_34;
          }
        }
        if ( !*(_DWORD *)(a1 + 136) || *(_DWORD *)(a1 + 124) || *(_DWORD *)(a1 + 288) )
          png_warning(a1, "Extra compressed data");
        *(_DWORD *)(a1 + 108) |= 8u;
        *(_DWORD *)(a1 + 112) |= 0x20u;
LABEL_34:
        *(_DWORD *)(a1 + 136) = 0;
      }
      if ( *(_DWORD *)(a1 + 288) || *(_DWORD *)(a1 + 124) )
        png_warning(a1, "Extra compression data");
      inflateReset((z_stream_s *)(a1 + 120));
      result = a1;
      *(_DWORD *)(a1 + 108) |= 8u;
    }
  }
  return result;
}
