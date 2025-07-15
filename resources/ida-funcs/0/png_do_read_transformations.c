unsigned int __cdecl png_do_read_transformations(int a1, int a2)
{
  unsigned int result; // eax
  unsigned int v3; // [esp+0h] [ebp-8h]

  if ( !*(_DWORD *)(a1 + 264) )
    png_error(a1, (int)"NULL row buffer");
  if ( (*(_DWORD *)(a1 + 112) & 0x4000) != 0 && (*(_DWORD *)(a1 + 112) & 0x40) == 0 )
    png_error(a1, (int)"Uninitialized row");
  if ( (*(_DWORD *)(a1 + 116) & 0x1000) != 0 )
  {
    if ( *(_BYTE *)(a2 + 8) == 3 )
    {
      png_do_expand_palette(
        a2,
        *(_DWORD *)(a1 + 264) + 1,
        *(_DWORD *)(a1 + 296),
        *(_DWORD *)(a1 + 420),
        *(unsigned __int16 *)(a1 + 308));
    }
    else if ( *(_WORD *)(a1 + 308) && (*(_DWORD *)(a1 + 116) & 0x2000000) != 0 )
    {
      png_do_expand(a2, *(_DWORD *)(a1 + 264) + 1, a1 + 424);
    }
    else
    {
      png_do_expand(a2, *(_DWORD *)(a1 + 264) + 1, 0);
    }
  }
  if ( (*(_DWORD *)(a1 + 116) & 0x40000) != 0
    && (*(_DWORD *)(a1 + 116) & 0x80) == 0
    && (*(_BYTE *)(a2 + 8) == 6 || *(_BYTE *)(a2 + 8) == 4) )
  {
    png_do_strip_channel(a2, *(_DWORD *)(a1 + 264) + 1, 0);
  }
  if ( ((unsigned int)&loc_600000 & *(_DWORD *)(a1 + 116)) != 0 && png_do_rgb_to_gray(a1, a2, *(_DWORD *)(a1 + 264) + 1) )
  {
    *(_BYTE *)(a1 + 593) = 1;
    if ( (_UNKNOWN *)((unsigned int)&loc_600000 & *(_DWORD *)(a1 + 116)) == &loc_400000 )
      png_warning(a1, "png_do_rgb_to_gray found nongray pixel");
    if ( (_UNKNOWN *)((unsigned int)&loc_600000 & *(_DWORD *)(a1 + 116)) == &loc_200000 )
      png_error(a1, (int)"png_do_rgb_to_gray found nongray pixel");
  }
  if ( (*(_DWORD *)(a1 + 116) & 0x4000) != 0 && (*(_DWORD *)(a1 + 108) & 0x800) == 0 )
    png_do_gray_to_rgb(a2, *(_DWORD *)(a1 + 264) + 1);
  if ( (*(_DWORD *)(a1 + 116) & 0x80) != 0 )
    png_do_compose(a2, *(_DWORD *)(a1 + 264) + 1, a1);
  if ( (*(_DWORD *)(a1 + 116) & 0x2000) != 0
    && ((unsigned int)&loc_600000 & *(_DWORD *)(a1 + 116)) == 0
    && ((*(_DWORD *)(a1 + 116) & 0x80) == 0 || !*(_WORD *)(a1 + 308) && (*(_BYTE *)(a1 + 315) & 4) == 0)
    && *(_BYTE *)(a1 + 315) != 3 )
  {
    png_do_gamma(a2, *(_DWORD *)(a1 + 264) + 1, a1);
  }
  if ( (*(_DWORD *)(a1 + 116) & 0x40000) != 0
    && (*(_DWORD *)(a1 + 116) & 0x80) != 0
    && (*(_BYTE *)(a2 + 8) == 6 || *(_BYTE *)(a2 + 8) == 4) )
  {
    png_do_strip_channel(a2, *(_DWORD *)(a1 + 264) + 1, 0);
  }
  if ( (*(_DWORD *)(a1 + 116) & 0x800000) != 0 && (*(_BYTE *)(a2 + 8) & 4) != 0 )
    png_do_encode_alpha(a2, *(_DWORD *)(a1 + 264) + 1, a1);
  if ( (*(_DWORD *)(a1 + 116) & 0x4000000) != 0 )
    png_do_scale_16_to_8(a2, *(_DWORD *)(a1 + 264) + 1);
  if ( (*(_DWORD *)(a1 + 116) & 0x400) != 0 )
    png_do_chop(a2, *(_DWORD *)(a1 + 264) + 1);
  if ( (*(_DWORD *)(a1 + 116) & 0x40) != 0 )
  {
    png_do_quantize(a2, *(_DWORD *)(a1 + 264) + 1, *(_DWORD *)(a1 + 504), *(_DWORD *)(a1 + 508));
    if ( !*(_DWORD *)(a2 + 4) )
      png_error(a1, (int)"png_do_quantize returned rowbytes=0");
  }
  if ( (*(_DWORD *)(a1 + 116) & 0x200) != 0 )
    png_do_expand_16(a2, *(_DWORD *)(a1 + 264) + 1);
  if ( (*(_DWORD *)(a1 + 116) & 0x4000) != 0 && (*(_DWORD *)(a1 + 108) & 0x800) != 0 )
    png_do_gray_to_rgb(a2, *(_DWORD *)(a1 + 264) + 1);
  if ( (*(_DWORD *)(a1 + 116) & 0x20) != 0 )
    png_do_invert(a2, *(_DWORD *)(a1 + 264) + 1);
  if ( (*(_DWORD *)(a1 + 116) & 8) != 0 )
    png_do_unshift(a2, *(_DWORD *)(a1 + 264) + 1, a1 + 413);
  if ( (*(_DWORD *)(a1 + 116) & 4) != 0 )
    png_do_unpack(a2, *(_DWORD *)(a1 + 264) + 1);
  if ( *(_BYTE *)(a2 + 8) == 3 && *(int *)(a1 + 304) >= 0 )
    png_do_check_palette_indexes(a1, a2);
  if ( (*(_DWORD *)(a1 + 116) & 1) != 0 )
    png_do_bgr(a2, *(_DWORD *)(a1 + 264) + 1);
  if ( ((unsigned int)&_sbh_sizeHeaderList & *(_DWORD *)(a1 + 116)) != 0 )
    png_do_packswap(a2, *(_DWORD *)(a1 + 264) + 1);
  if ( (*(_DWORD *)(a1 + 116) & 0x8000) != 0 )
    png_do_read_filler(a2, *(_DWORD *)(a1 + 264) + 1, *(unsigned __int16 *)(a1 + 330), *(_DWORD *)(a1 + 112));
  if ( (*(_DWORD *)(a1 + 116) & 0x80000) != 0 )
    png_do_read_invert_alpha(a2, *(_DWORD *)(a1 + 264) + 1);
  if ( ((unsigned int)&loc_20000 & *(_DWORD *)(a1 + 116)) != 0 )
    png_do_read_swap_alpha(a2, *(_DWORD *)(a1 + 264) + 1);
  if ( (*(_DWORD *)(a1 + 116) & 0x10) != 0 )
    png_do_swap(a2, *(_DWORD *)(a1 + 264) + 1);
  result = (unsigned int)&loc_100000 & *(_DWORD *)(a1 + 116);
  if ( result )
  {
    if ( *(_DWORD *)(a1 + 92) )
      (*(void (__cdecl **)(int, int, int))(a1 + 92))(a1, a2, *(_DWORD *)(a1 + 264) + 1);
    if ( *(_BYTE *)(a1 + 104) )
      *(_BYTE *)(a2 + 9) = *(_BYTE *)(a1 + 104);
    if ( *(_BYTE *)(a1 + 105) )
      *(_BYTE *)(a2 + 10) = *(_BYTE *)(a1 + 105);
    *(_BYTE *)(a2 + 11) = *(_BYTE *)(a2 + 10) * *(_BYTE *)(a2 + 9);
    if ( *(unsigned __int8 *)(a2 + 11) < 8u )
      v3 = (*(_DWORD *)a2 * (unsigned int)*(unsigned __int8 *)(a2 + 11) + 7) >> 3;
    else
      v3 = *(_DWORD *)a2 * (*(unsigned __int8 *)(a2 + 11) >> 3);
    result = v3;
    *(_DWORD *)(a2 + 4) = v3;
  }
  return result;
}
