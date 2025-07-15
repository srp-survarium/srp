void __cdecl png_write_info_before_PLTE(_DWORD *a1, int a2)
{
  int v2; // [esp+0h] [ebp-8h]
  char *lhs; // [esp+4h] [ebp-4h]

  if ( a1 && a2 && (a1[27] & 0x400) == 0 )
  {
    png_write_sig(a1);
    if ( (a1[27] & 0x1000) != 0 && a1[150] )
    {
      png_warning((int)a1, "MNG features are not allowed in a PNG datastream");
      a1[150] = 0;
    }
    png_write_IHDR(
      a1,
      *(_DWORD *)a2,
      *(_DWORD *)(a2 + 4),
      *(unsigned __int8 *)(a2 + 24),
      *(unsigned __int8 *)(a2 + 25),
      *(unsigned __int8 *)(a2 + 26),
      *(unsigned __int8 *)(a2 + 27),
      *(unsigned __int8 *)(a2 + 28));
    if ( (*(_DWORD *)(a2 + 8) & 1) != 0 )
      png_write_gAMA_fixed(a1, *(_DWORD *)(a2 + 40));
    if ( (*(_DWORD *)(a2 + 8) & 0x800) != 0 )
      png_write_sRGB(a1, *(unsigned __int8 *)(a2 + 44));
    if ( (*(_DWORD *)(a2 + 8) & 0x1000) != 0 )
      png_write_iCCP((int)a1, *(LPCSTR *)(a2 + 196), 0, *(_DWORD *)(a2 + 200), *(_DWORD *)(a2 + 204));
    if ( (*(_DWORD *)(a2 + 8) & 2) != 0 )
      png_write_sBIT(a1, a2 + 68, *(unsigned __int8 *)(a2 + 25));
    if ( (*(_DWORD *)(a2 + 8) & 4) != 0 )
      png_write_cHRM_fixed(
        a1,
        *(_DWORD *)(a2 + 128),
        *(_DWORD *)(a2 + 132),
        *(_DWORD *)(a2 + 136),
        *(_DWORD *)(a2 + 140),
        *(_DWORD *)(a2 + 144),
        *(_DWORD *)(a2 + 148),
        *(_DWORD *)(a2 + 152),
        *(_DWORD *)(a2 + 156));
    if ( *(_DWORD *)(a2 + 192) )
    {
      for ( lhs = *(char **)(a2 + 188); (unsigned int)lhs < *(_DWORD *)(a2 + 188) + 20 * *(_DWORD *)(a2 + 192); lhs += 20 )
      {
        v2 = png_handle_as_unknown((int)a1, (unsigned __int8 *)lhs);
        if ( v2 != 1
          && lhs[16]
          && (lhs[16] & 2) == 0
          && (lhs[16] & 4) == 0
          && (lhs[16] & 8) == 0
          && ((lhs[3] & 0x20) != 0 || v2 == 3 || ((unsigned int)&_sbh_sizeHeaderList & a1[28]) != 0) )
        {
          if ( !*((_DWORD *)lhs + 3) )
            png_warning((int)a1, "Writing zero-length unknown chunk");
          png_write_chunk((int)a1, (int)lhs, *((unsigned __int8 **)lhs + 2), *((_DWORD *)lhs + 3));
        }
      }
    }
    a1[27] |= 0x400u;
  }
}
