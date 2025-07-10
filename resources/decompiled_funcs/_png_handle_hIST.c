void __cdecl png_handle_hIST(int a1, int a2, unsigned int a3)
{
  unsigned __int8 buf[4]; // [esp+0h] [ebp-214h] BYREF
  _WORD v4[258]; // [esp+4h] [ebp-210h] BYREF
  unsigned int v5; // [esp+20Ch] [ebp-8h]
  unsigned int i; // [esp+210h] [ebp-4h]

  if ( (*(_DWORD *)(a1 + 108) & 1) == 0 )
    png_error(a1, (int)"Missing IHDR before hIST");
  if ( (*(_DWORD *)(a1 + 108) & 4) != 0 )
  {
    png_warning(a1, "Invalid hIST after IDAT");
    png_crc_finish(a1, a3);
  }
  else if ( (*(_DWORD *)(a1 + 108) & 2) != 0 )
  {
    if ( a2 && (*(_DWORD *)(a2 + 8) & 0x40) != 0 )
    {
      png_warning(a1, "Duplicate hIST chunk");
      png_crc_finish(a1, a3);
    }
    else if ( a3 <= 0x200 && a3 == 2 * *(unsigned __int16 *)(a1 + 300) )
    {
      v5 = a3 >> 1;
      for ( i = 0; i < v5; ++i )
      {
        png_crc_read((_DWORD *)a1, buf, 2);
        v4[i] = buf[1] + (buf[0] << 8);
      }
      if ( !png_crc_finish(a1, 0) )
        png_set_hIST(a1, a2, (int)v4);
    }
    else
    {
      png_warning(a1, "Incorrect hIST chunk length");
      png_crc_finish(a1, a3);
    }
  }
  else
  {
    png_warning(a1, "Missing PLTE before hIST");
    png_crc_finish(a1, a3);
  }
}
