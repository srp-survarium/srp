int __cdecl png_handle_IEND(int a1, int a2, unsigned int a3)
{
  if ( (*(_DWORD *)(a1 + 108) & 1) == 0 || (*(_DWORD *)(a1 + 108) & 4) == 0 )
    png_error(a1, (int)"No image in file");
  *(_DWORD *)(a1 + 108) |= 0x18u;
  if ( a3 )
    png_warning(a1, "Incorrect IEND chunk length");
  return png_crc_finish(a1, a3);
}
