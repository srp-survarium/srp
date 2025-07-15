void __cdecl png_set_PLTE(int a1, int a2, const __m128i *src, unsigned int a4)
{
  if ( a1 && a2 )
  {
    if ( a4 <= 0x100 )
    {
      png_free_data(a1, a2, 4096, 0);
      *(_DWORD *)(a1 + 296) = png_calloc(a1, 0x300u);
      memcpy(*(_DWORD *)(a1 + 296), src, 3 * a4);
      *(_DWORD *)(a2 + 16) = *(_DWORD *)(a1 + 296);
      *(_WORD *)(a1 + 300) = a4;
      *(_WORD *)(a2 + 20) = a4;
      *(_DWORD *)(a2 + 184) |= 0x1000u;
      *(_DWORD *)(a2 + 8) |= 8u;
    }
    else
    {
      if ( *(_BYTE *)(a2 + 25) == 3 )
        png_error(a1, (int)"Invalid palette length");
      png_warning(a1, "Invalid palette length");
    }
  }
}
