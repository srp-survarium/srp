void __cdecl png_set_sig_bytes(int a1, int a2)
{
  if ( a1 )
  {
    if ( a2 > 8 )
      png_error(a1, (int)"Too many bytes for PNG signature");
    *(_BYTE *)(a1 + 321) = a2 < 0 ? 0 : a2;
  }
}
