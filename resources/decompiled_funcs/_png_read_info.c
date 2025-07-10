void __cdecl png_read_info(int a1, int a2)
{
  int v2; // [esp+0h] [ebp-8h]
  unsigned int size; // [esp+4h] [ebp-4h]

  if ( a1 && a2 )
  {
    png_read_sig(a1, a2);
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            while ( 1 )
            {
              size = png_read_chunk_header(a1);
              v2 = *(_DWORD *)(a1 + 256);
              if ( v2 == 1229209940 && (*(_DWORD *)(a1 + 108) & 8) != 0 )
                *(_DWORD *)(a1 + 108) |= 0x2000u;
              if ( v2 != 1229472850 )
                break;
              png_handle_IHDR(a1, a2, size);
            }
            if ( v2 != 1229278788 )
              break;
            png_handle_IEND(a1, a2, size);
          }
          if ( !png_chunk_unknown_handling(a1, v2) )
            break;
          if ( v2 == 1229209940 )
            *(_DWORD *)(a1 + 108) |= 4u;
          png_handle_unknown(a1, a2, size);
          if ( v2 == 1347179589 )
          {
            *(_DWORD *)(a1 + 108) |= 2u;
          }
          else if ( v2 == 1229209940 )
          {
            if ( (*(_DWORD *)(a1 + 108) & 1) == 0 )
              png_error(a1, (int)"Missing IHDR before IDAT");
            if ( *(_BYTE *)(a1 + 315) == 3 && (*(_DWORD *)(a1 + 108) & 2) == 0 )
              png_error(a1, (int)"Missing PLTE before IDAT");
            return;
          }
        }
        if ( v2 != 1347179589 )
          break;
        png_handle_PLTE(a1, a2, size);
      }
      if ( v2 == 1229209940 )
        break;
      switch ( v2 )
      {
        case 1649100612:
          png_handle_bKGD(a1, a2, size);
          break;
        case 1665684045:
          png_handle_cHRM(a1, a2, size);
          break;
        case 1732332865:
          png_handle_gAMA(a1, a2, size);
          break;
        case 1749635924:
          png_handle_hIST(a1, a2, size);
          break;
        case 1866876531:
          png_handle_oFFs(a1, a2, size);
          break;
        case 1883455820:
          png_handle_pCAL(a1, a2, size);
          break;
        case 1933787468:
          png_handle_sCAL(a1, a2, size);
          break;
        case 1883789683:
          png_handle_pHYs(a1, a2, size);
          break;
        case 1933723988:
          png_handle_sBIT(a1, a2, size);
          break;
        case 1934772034:
          png_handle_sRGB(a1, a2, size);
          break;
        case 1766015824:
          png_handle_iCCP(a1, a2, size);
          break;
        case 1934642260:
          png_handle_sPLT(a1, a2, size);
          break;
        case 1950701684:
          png_handle_tEXt(a1, a2, size);
          break;
        case 1950960965:
          png_handle_tIME(a1, a2, size);
          break;
        case 1951551059:
          png_handle_tRNS(a1, a2, size);
          break;
        case 2052348020:
          png_handle_zTXt(a1, a2, size);
          break;
        case 1767135348:
          png_handle_iTXt(a1, a2, size);
          break;
        default:
          png_handle_unknown(a1, a2, size);
          break;
      }
    }
    if ( (*(_DWORD *)(a1 + 108) & 1) == 0 )
      png_error(a1, (int)"Missing IHDR before IDAT");
    if ( *(_BYTE *)(a1 + 315) == 3 && (*(_DWORD *)(a1 + 108) & 2) == 0 )
      png_error(a1, (int)"Missing PLTE before IDAT");
    *(_DWORD *)(a1 + 288) = size;
    *(_DWORD *)(a1 + 108) |= 4u;
  }
}
