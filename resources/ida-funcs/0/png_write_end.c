void __cdecl png_write_end(int a1, _DWORD *a2)
{
  int v2; // [esp+0h] [ebp-Ch]
  char *lhs; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  if ( a1 )
  {
    if ( (*(_DWORD *)(a1 + 108) & 4) == 0 )
      png_error(a1, (int)"No IDATs written into file");
    if ( *(_DWORD *)(a1 + 304) > (int)*(unsigned __int16 *)(a1 + 300) )
      png_benign_error(a1, "Wrote palette index exceeding num_palette");
    if ( a2 )
    {
      if ( (a2[2] & 0x200) != 0 && (*(_DWORD *)(a1 + 108) & 0x200) == 0 )
        png_write_tIME(a1, a2 + 15);
      for ( i = 0; i < a2[12]; ++i )
      {
        if ( *(int *)(28 * i + a2[14]) <= 0 )
        {
          if ( *(int *)(28 * i + a2[14]) < 0 )
          {
            if ( *(_DWORD *)(28 * i + a2[14]) == -1 )
            {
              png_write_tEXt(a1, *(LPCSTR *)(a2[14] + 28 * i + 4), *(LPCSTR *)(a2[14] + 28 * i + 8), 0);
              *(_DWORD *)(28 * i + a2[14]) = -3;
            }
          }
          else
          {
            png_write_zTXt(
              a1,
              *(LPCSTR *)(a2[14] + 28 * i + 4),
              *(LPCSTR *)(a2[14] + 28 * i + 8),
              0,
              *(_DWORD *)(a2[14] + 28 * i));
            *(_DWORD *)(28 * i + a2[14]) = -2;
          }
        }
        else
        {
          png_write_iTXt(
            a1,
            *(_DWORD *)(a2[14] + 28 * i),
            *(LPCSTR *)(a2[14] + 28 * i + 4),
            *(LPCSTR *)(a2[14] + 28 * i + 20),
            *(LPCSTR *)(a2[14] + 28 * i + 24),
            *(LPCSTR *)(a2[14] + 28 * i + 8));
          *(_DWORD *)(28 * i + a2[14]) = -3;
        }
      }
      if ( a2[48] )
      {
        for ( lhs = (char *)a2[47]; (unsigned int)lhs < a2[47] + 20 * a2[48]; lhs += 20 )
        {
          v2 = png_handle_as_unknown(a1, (unsigned __int8 *)lhs);
          if ( v2 != 1
            && lhs[16]
            && (lhs[16] & 8) != 0
            && ((lhs[3] & 0x20) != 0 || v2 == 3 || ((unsigned int)&_sbh_sizeHeaderList & *(_DWORD *)(a1 + 112)) != 0) )
          {
            png_write_chunk(a1, (int)lhs, *((unsigned __int8 **)lhs + 2), *((_DWORD *)lhs + 3));
          }
        }
      }
    }
    *(_DWORD *)(a1 + 108) |= 8u;
    png_write_IEND(a1);
  }
}
