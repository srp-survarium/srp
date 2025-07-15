void __cdecl png_handle_PLTE(int a1, int a2, unsigned int a3)
{
  unsigned __int8 buf[4]; // [esp+0h] [ebp-314h] BYREF
  __m128i src[48]; // [esp+4h] [ebp-310h] BYREF
  int v5; // [esp+308h] [ebp-Ch]
  int v6; // [esp+30Ch] [ebp-8h]
  __m128i *v7; // [esp+310h] [ebp-4h]

  if ( (*(_DWORD *)(a1 + 108) & 1) == 0 )
    png_error(a1, (int)"Missing IHDR before PLTE");
  if ( (*(_DWORD *)(a1 + 108) & 4) != 0 )
  {
    png_warning(a1, "Invalid PLTE after IDAT");
    png_crc_finish(a1, a3);
  }
  else
  {
    if ( (*(_DWORD *)(a1 + 108) & 2) != 0 )
      png_error(a1, (int)"Duplicate PLTE chunk");
    *(_DWORD *)(a1 + 108) |= 2u;
    if ( (*(_BYTE *)(a1 + 315) & 2) != 0 )
    {
      if ( a3 > 0x300 || a3 % 3 )
      {
        if ( *(_BYTE *)(a1 + 315) == 3 )
          png_error(a1, (int)"Invalid palette chunk");
        png_warning(a1, "Invalid palette chunk");
        png_crc_finish(a1, a3);
      }
      else
      {
        v5 = (int)a3 / 3;
        v6 = 0;
        v7 = src;
        while ( v6 < v5 )
        {
          png_crc_read((_DWORD *)a1, buf, 3);
          v7->m128i_i8[0] = buf[0];
          v7->m128i_i8[1] = buf[1];
          v7->m128i_i8[2] = buf[2];
          ++v6;
          v7 = (__m128i *)((char *)v7 + 3);
        }
        png_crc_finish(a1, 0);
        png_set_PLTE(a1, a2, src, v5);
        if ( *(_BYTE *)(a1 + 315) == 3 && a2 && (*(_DWORD *)(a2 + 8) & 0x10) != 0 )
        {
          if ( *(unsigned __int16 *)(a1 + 308) > (int)(unsigned __int16)v5 )
          {
            png_warning(a1, "Truncating incorrect tRNS chunk length");
            *(_WORD *)(a1 + 308) = v5;
          }
          if ( *(unsigned __int16 *)(a2 + 22) > (int)(unsigned __int16)v5 )
          {
            png_warning(a1, "Truncating incorrect info tRNS chunk length");
            *(_WORD *)(a2 + 22) = v5;
          }
        }
      }
    }
    else
    {
      png_warning(a1, "Ignoring PLTE chunk in grayscale PNG");
      png_crc_finish(a1, a3);
    }
  }
}
