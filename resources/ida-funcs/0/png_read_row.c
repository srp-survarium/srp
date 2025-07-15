void __cdecl png_read_row(int a1, unsigned __int8 *a2, unsigned __int8 *dst)
{
  unsigned int v3; // [esp+4h] [ebp-1Ch]
  unsigned int v4; // [esp+Ch] [ebp-14h]
  int v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v7; // [esp+18h] [ebp-8h]
  char v8; // [esp+1Ch] [ebp-4h]
  char v9; // [esp+1Dh] [ebp-3h]
  char v10; // [esp+1Eh] [ebp-2h]
  unsigned __int8 v11; // [esp+1Fh] [ebp-1h]

  if ( a1 )
  {
    if ( (*(_DWORD *)(a1 + 112) & 0x40) == 0 )
      png_read_start_row(a1);
    v6 = *(_DWORD *)(a1 + 248);
    v8 = *(_BYTE *)(a1 + 315);
    v9 = *(_BYTE *)(a1 + 316);
    v10 = *(_BYTE *)(a1 + 319);
    v11 = *(_BYTE *)(a1 + 318);
    if ( v11 < 8u )
      v4 = (v6 * (unsigned int)v11 + 7) >> 3;
    else
      v4 = v6 * (v11 >> 3);
    v7 = v4;
    if ( *(_BYTE *)(a1 + 312) && (*(_DWORD *)(a1 + 116) & 2) != 0 )
    {
      switch ( *(_BYTE *)(a1 + 313) )
      {
        case 0:
          if ( (*(_DWORD *)(a1 + 252) & 7) == 0 )
            goto LABEL_47;
          if ( dst )
            png_combine_row(a1, dst, 1);
          break;
        case 1:
          if ( (*(_DWORD *)(a1 + 252) & 7) == 0 && *(_DWORD *)(a1 + 228) >= 5u )
            goto LABEL_47;
          if ( dst )
            png_combine_row(a1, dst, 1);
          break;
        case 2:
          if ( (*(_DWORD *)(a1 + 252) & 7) == 4 )
            goto LABEL_47;
          if ( dst && (*(_DWORD *)(a1 + 252) & 4) != 0 )
            png_combine_row(a1, dst, 1);
          break;
        case 3:
          if ( (*(_DWORD *)(a1 + 252) & 3) == 0 && *(_DWORD *)(a1 + 228) >= 3u )
            goto LABEL_47;
          if ( dst )
            png_combine_row(a1, dst, 1);
          break;
        case 4:
          if ( (*(_DWORD *)(a1 + 252) & 3) == 2 )
            goto LABEL_47;
          if ( dst && (*(_DWORD *)(a1 + 252) & 2) != 0 )
            png_combine_row(a1, dst, 1);
          break;
        case 5:
          if ( (*(_DWORD *)(a1 + 252) & 1) == 0 && *(_DWORD *)(a1 + 228) >= 2u )
            goto LABEL_47;
          if ( dst )
            png_combine_row(a1, dst, 1);
          break;
        default:
          if ( (*(_DWORD *)(a1 + 252) & 1) != 0 )
            goto LABEL_47;
          break;
      }
      png_read_finish_row(a1);
    }
    else
    {
LABEL_47:
      if ( (*(_DWORD *)(a1 + 108) & 4) == 0 )
        png_error(a1, (int)"Invalid attempt to read row data");
      *(_DWORD *)(a1 + 132) = *(_DWORD *)(a1 + 264);
      if ( *(unsigned __int8 *)(a1 + 318) < 8u )
        v3 = (*(_DWORD *)(a1 + 248) * (unsigned int)*(unsigned __int8 *)(a1 + 318) + 7) >> 3;
      else
        v3 = *(_DWORD *)(a1 + 248) * (*(unsigned __int8 *)(a1 + 318) >> 3);
      *(_DWORD *)(a1 + 136) = v3 + 1;
      while ( 1 )
      {
        if ( !*(_DWORD *)(a1 + 124) )
        {
          while ( !*(_DWORD *)(a1 + 288) )
          {
            png_crc_finish(a1, 0);
            *(_DWORD *)(a1 + 288) = png_read_chunk_header(a1);
            if ( *(_DWORD *)(a1 + 256) != 1229209940 )
              png_error(a1, (int)"Not enough image data");
          }
          *(_DWORD *)(a1 + 124) = *(_DWORD *)(a1 + 180);
          *(_DWORD *)(a1 + 120) = *(_DWORD *)(a1 + 176);
          if ( *(_DWORD *)(a1 + 180) > *(_DWORD *)(a1 + 288) )
            *(_DWORD *)(a1 + 124) = *(_DWORD *)(a1 + 288);
          png_crc_read(a1, *(unsigned __int8 **)(a1 + 176), *(_DWORD *)(a1 + 124));
          *(_DWORD *)(a1 + 288) -= *(_DWORD *)(a1 + 124);
        }
        v5 = inflate((z_stream_s *)(a1 + 120), 1);
        if ( v5 == 1 )
          break;
        if ( v5 )
        {
          if ( *(_DWORD *)(a1 + 144) )
            png_error(a1, *(_DWORD *)(a1 + 144));
          png_error(a1, (int)"Decompression error");
        }
        if ( !*(_DWORD *)(a1 + 136) )
          goto LABEL_72;
      }
      if ( *(_DWORD *)(a1 + 136) || *(_DWORD *)(a1 + 124) || *(_DWORD *)(a1 + 288) )
        png_benign_error(a1, "Extra compressed data");
      *(_DWORD *)(a1 + 108) |= 8u;
      *(_DWORD *)(a1 + 112) |= 0x20u;
LABEL_72:
      if ( **(_BYTE **)(a1 + 264) )
      {
        if ( **(unsigned __int8 **)(a1 + 264) >= 5u )
          png_error(a1, (int)"bad adaptive filter value");
        png_read_filter_row(
          a1,
          &v6,
          *(_DWORD *)(a1 + 264) + 1,
          *(_DWORD *)(a1 + 260) + 1,
          **(unsigned __int8 **)(a1 + 264));
      }
      memcpy(*(_DWORD *)(a1 + 260), *(const __m128i **)(a1 + 264), v7 + 1);
      if ( (*(_DWORD *)(a1 + 600) & 4) != 0 && *(_BYTE *)(a1 + 604) == 64 )
        png_do_read_intrapixel(&v6, *(_DWORD *)(a1 + 264) + 1);
      if ( *(_DWORD *)(a1 + 116) )
        png_do_read_transformations(a1, &v6);
      if ( *(_BYTE *)(a1 + 323) )
      {
        if ( *(unsigned __int8 *)(a1 + 323) != v11 )
          png_error(a1, (int)"internal sequential row size calculation error");
      }
      else
      {
        *(_BYTE *)(a1 + 323) = v11;
        if ( v11 > (int)*(unsigned __int8 *)(a1 + 322) )
          png_error(a1, (int)"sequential row overflow");
      }
      if ( *(_BYTE *)(a1 + 312) && (*(_DWORD *)(a1 + 116) & 2) != 0 )
      {
        if ( *(unsigned __int8 *)(a1 + 313) < 6u )
          png_do_read_interlace(&v6, *(_DWORD *)(a1 + 264) + 1, *(unsigned __int8 *)(a1 + 313), *(_DWORD *)(a1 + 116));
        if ( dst )
          png_combine_row(a1, dst, 1);
        if ( a2 )
          png_combine_row(a1, a2, 0);
      }
      else
      {
        if ( a2 )
          png_combine_row(a1, a2, -1);
        if ( dst )
          png_combine_row(a1, dst, -1);
      }
      png_read_finish_row(a1);
      if ( *(_DWORD *)(a1 + 436) )
        (*(void (__cdecl **)(int, _DWORD, _DWORD))(a1 + 436))(a1, *(_DWORD *)(a1 + 252), *(unsigned __int8 *)(a1 + 313));
    }
  }
}
