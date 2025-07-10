_BYTE *__cdecl png_do_write_transformations(int a1, unsigned int *a2)
{
  _BYTE *result; // eax

  if ( a1 )
  {
    if ( (*(_DWORD *)(a1 + 116) & 0x100000) != 0 && *(_DWORD *)(a1 + 96) )
      (*(void (__cdecl **)(int, unsigned int *, int))(a1 + 96))(a1, a2, *(_DWORD *)(a1 + 264) + 1);
    if ( (*(_DWORD *)(a1 + 116) & 0x8000) != 0 )
    {
      if ( (*(_BYTE *)(a1 + 315) & 5) != 0 )
      {
        png_warning(a1, "incorrect png_set_filler call ignored");
        *(_DWORD *)(a1 + 116) &= ~0x8000u;
      }
      else
      {
        png_do_strip_channel((int)a2, (_BYTE *)(*(_DWORD *)(a1 + 264) + 1), (*(_DWORD *)(a1 + 112) & 0x80) == 0);
      }
    }
    if ( ((unsigned int)&_sbh_sizeHeaderList & *(_DWORD *)(a1 + 116)) != 0 )
      png_do_packswap((int)a2, (_BYTE *)(*(_DWORD *)(a1 + 264) + 1));
    if ( (*(_DWORD *)(a1 + 116) & 4) != 0 )
      png_do_pack(a2, *(_DWORD *)(a1 + 264) + 1, *(unsigned __int8 *)(a1 + 316));
    if ( (*(_DWORD *)(a1 + 116) & 0x10) != 0 )
      png_do_swap((unsigned int)a2, (char *)(*(_DWORD *)(a1 + 264) + 1));
    if ( (*(_DWORD *)(a1 + 116) & 8) != 0 )
      png_do_shift(a2, *(_DWORD *)(a1 + 264) + 1, a1 + 413);
    if ( ((unsigned int)&loc_20000 & *(_DWORD *)(a1 + 116)) != 0 )
      png_do_write_swap_alpha(a2, *(_DWORD *)(a1 + 264) + 1);
    if ( (*(_DWORD *)(a1 + 116) & 0x80000) != 0 )
      png_do_write_invert_alpha(a2, *(_DWORD *)(a1 + 264) + 1);
    if ( (*(_DWORD *)(a1 + 116) & 1) != 0 )
      png_do_bgr(a2, (char *)(*(_DWORD *)(a1 + 264) + 1));
    result = (_BYTE *)a1;
    if ( (*(_DWORD *)(a1 + 116) & 0x20) != 0 )
      return png_do_invert((int)a2, (_BYTE *)(*(_DWORD *)(a1 + 264) + 1));
  }
  return result;
}
