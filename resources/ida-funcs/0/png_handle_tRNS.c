void __cdecl png_handle_tRNS(int a1, int a2, unsigned int a3)
{
  unsigned __int8 v3[8]; // [esp+0h] [ebp-114h] BYREF
  unsigned __int8 buf[4]; // [esp+8h] [ebp-10Ch] BYREF
  unsigned __int8 src[260]; // [esp+Ch] [ebp-108h] BYREF

  if ( (*(_DWORD *)(a1 + 108) & 1) == 0 )
    png_error(a1, (int)"Missing IHDR before tRNS");
  if ( (*(_DWORD *)(a1 + 108) & 4) != 0 )
  {
    png_warning(a1, "Invalid tRNS after IDAT");
    png_crc_finish(a1, a3);
    return;
  }
  if ( a2 && (*(_DWORD *)(a2 + 8) & 0x10) != 0 )
  {
    png_warning(a1, "Duplicate tRNS chunk");
    png_crc_finish(a1, a3);
    return;
  }
  if ( *(_BYTE *)(a1 + 315) )
  {
    if ( *(_BYTE *)(a1 + 315) == 2 )
    {
      if ( a3 != 6 )
        goto LABEL_10;
      png_crc_read((_DWORD *)a1, v3, 6);
      *(_WORD *)(a1 + 308) = 1;
      *(_WORD *)(a1 + 426) = v3[1] + (v3[0] << 8);
      *(_WORD *)(a1 + 428) = v3[3] + (v3[2] << 8);
      *(_WORD *)(a1 + 430) = v3[5] + (v3[4] << 8);
    }
    else
    {
      if ( *(_BYTE *)(a1 + 315) != 3 )
      {
        png_warning(a1, "tRNS chunk not allowed with alpha channel");
        png_crc_finish(a1, a3);
        return;
      }
      if ( (*(_DWORD *)(a1 + 108) & 2) == 0 )
        png_warning(a1, "Missing PLTE before tRNS");
      if ( a3 > *(unsigned __int16 *)(a1 + 300) || a3 > 0x100 )
        goto LABEL_10;
      if ( !a3 )
      {
        png_warning(a1, "Zero length tRNS chunk");
        png_crc_finish(a1, 0);
        return;
      }
      png_crc_read((_DWORD *)a1, src, a3);
      *(_WORD *)(a1 + 308) = a3;
    }
  }
  else
  {
    if ( a3 != 2 )
    {
LABEL_10:
      png_warning(a1, "Incorrect tRNS chunk length");
      png_crc_finish(a1, a3);
      return;
    }
    png_crc_read((_DWORD *)a1, buf, 2);
    *(_WORD *)(a1 + 308) = 1;
    *(_WORD *)(a1 + 432) = buf[1] + (buf[0] << 8);
  }
  if ( png_crc_finish(a1, 0) )
    *(_WORD *)(a1 + 308) = 0;
  else
    png_set_tRNS(a1, a2, src, *(unsigned __int16 *)(a1 + 308), (unsigned __int8 *)(a1 + 424));
}
