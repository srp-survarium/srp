void __cdecl png_write_info(_DWORD *a1, int a2)
{
  int v2; // [esp+0h] [ebp-10h]
  char *lhs; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  int j; // [esp+Ch] [ebp-4h]
  int k; // [esp+Ch] [ebp-4h]

  if ( a1 && a2 )
  {
    png_write_info_before_PLTE(a1, a2);
    if ( (*(_DWORD *)(a2 + 8) & 8) != 0 )
    {
      png_write_PLTE(a1, *(_DWORD *)(a2 + 16), *(unsigned __int16 *)(a2 + 20));
    }
    else if ( *(_BYTE *)(a2 + 25) == 3 )
    {
      png_error((int)a1, (int)"Valid palette required for paletted images");
    }
    if ( (*(_DWORD *)(a2 + 8) & 0x10) != 0 )
    {
      if ( (a1[29] & 0x80000) != 0 && *(_BYTE *)(a2 + 25) == 3 )
      {
        for ( i = 0; i < *(unsigned __int16 *)(a2 + 22); ++i )
          *(_BYTE *)(*(_DWORD *)(a2 + 76) + i) = -1 - *(_BYTE *)(*(_DWORD *)(a2 + 76) + i);
      }
      png_write_tRNS(
        (int)a1,
        *(unsigned __int8 **)(a2 + 76),
        a2 + 80,
        *(unsigned __int16 *)(a2 + 22),
        *(unsigned __int8 *)(a2 + 25));
    }
    if ( (*(_DWORD *)(a2 + 8) & 0x20) != 0 )
      png_write_bKGD(a1, a2 + 90, *(unsigned __int8 *)(a2 + 25));
    if ( (*(_DWORD *)(a2 + 8) & 0x40) != 0 )
      png_write_hIST(a1, *(_DWORD *)(a2 + 124), *(unsigned __int16 *)(a2 + 20));
    if ( (*(_DWORD *)(a2 + 8) & 0x100) != 0 )
      png_write_oFFs(a1, *(_DWORD *)(a2 + 100), *(_DWORD *)(a2 + 104), *(unsigned __int8 *)(a2 + 108));
    if ( (*(_DWORD *)(a2 + 8) & 0x400) != 0 )
      png_write_pCAL(
        (int)a1,
        *(LPCSTR *)(a2 + 160),
        *(_DWORD *)(a2 + 164),
        *(_DWORD *)(a2 + 168),
        *(unsigned __int8 *)(a2 + 180),
        *(unsigned __int8 *)(a2 + 181),
        *(LPCSTR *)(a2 + 172),
        *(_DWORD *)(a2 + 176));
    if ( (*(_DWORD *)(a2 + 8) & 0x4000) != 0 )
      png_write_sCAL_s((int)a1, *(_BYTE *)(a2 + 220), *(LPCSTR *)(a2 + 224), *(LPCSTR *)(a2 + 228));
    if ( (*(_DWORD *)(a2 + 8) & 0x80) != 0 )
      png_write_pHYs(a1, *(_DWORD *)(a2 + 112), *(_DWORD *)(a2 + 116), *(unsigned __int8 *)(a2 + 120));
    if ( (*(_DWORD *)(a2 + 8) & 0x200) != 0 )
    {
      png_write_tIME(a1, a2 + 60);
      a1[27] |= 0x200u;
    }
    if ( (*(_DWORD *)(a2 + 8) & 0x2000) != 0 )
    {
      for ( j = 0; j < *(_DWORD *)(a2 + 216); ++j )
        png_write_sPLT(a1, *(_DWORD *)(a2 + 212) + 16 * j);
    }
    for ( k = 0; k < *(_DWORD *)(a2 + 48); ++k )
    {
      if ( *(int *)(28 * k + *(_DWORD *)(a2 + 56)) <= 0 )
      {
        if ( *(_DWORD *)(28 * k + *(_DWORD *)(a2 + 56)) )
        {
          if ( *(_DWORD *)(28 * k + *(_DWORD *)(a2 + 56)) == -1 )
          {
            png_write_tEXt(
              (int)a1,
              *(LPCSTR *)(*(_DWORD *)(a2 + 56) + 28 * k + 4),
              *(LPCSTR *)(*(_DWORD *)(a2 + 56) + 28 * k + 8),
              0);
            *(_DWORD *)(28 * k + *(_DWORD *)(a2 + 56)) = -3;
          }
        }
        else
        {
          png_write_zTXt(
            (int)a1,
            *(LPCSTR *)(*(_DWORD *)(a2 + 56) + 28 * k + 4),
            *(LPCSTR *)(*(_DWORD *)(a2 + 56) + 28 * k + 8),
            0,
            *(_DWORD *)(*(_DWORD *)(a2 + 56) + 28 * k));
          *(_DWORD *)(28 * k + *(_DWORD *)(a2 + 56)) = -2;
        }
      }
      else
      {
        png_write_iTXt(
          (int)a1,
          *(_DWORD *)(*(_DWORD *)(a2 + 56) + 28 * k),
          *(LPCSTR *)(*(_DWORD *)(a2 + 56) + 28 * k + 4),
          *(LPCSTR *)(*(_DWORD *)(a2 + 56) + 28 * k + 20),
          *(LPCSTR *)(*(_DWORD *)(a2 + 56) + 28 * k + 24),
          *(LPCSTR *)(*(_DWORD *)(a2 + 56) + 28 * k + 8));
        *(_DWORD *)(28 * k + *(_DWORD *)(a2 + 56)) = -3;
      }
    }
    if ( *(_DWORD *)(a2 + 192) )
    {
      for ( lhs = *(char **)(a2 + 188); (unsigned int)lhs < *(_DWORD *)(a2 + 188) + 20 * *(_DWORD *)(a2 + 192); lhs += 20 )
      {
        v2 = png_handle_as_unknown((int)a1, (unsigned __int8 *)lhs);
        if ( v2 != 1
          && lhs[16]
          && (lhs[16] & 2) != 0
          && (lhs[16] & 4) == 0
          && (lhs[16] & 8) == 0
          && ((lhs[3] & 0x20) != 0 || v2 == 3 || ((unsigned int)&_sbh_sizeHeaderList & a1[28]) != 0) )
        {
          png_write_chunk((int)a1, (int)lhs, *((unsigned __int8 **)lhs + 2), *((_DWORD *)lhs + 3));
        }
      }
    }
  }
}
