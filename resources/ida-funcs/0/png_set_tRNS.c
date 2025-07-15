void __cdecl png_set_tRNS(int a1, int a2, unsigned __int8 *src, int count, unsigned __int8 *a5)
{
  int v5; // [esp+0h] [ebp-4h]

  if ( a1 && a2 )
  {
    if ( src )
    {
      png_free_data(a1, a2, 0x2000, 0);
      *(_DWORD *)(a2 + 76) = png_malloc(a1, 0x100u);
      *(_DWORD *)(a1 + 420) = *(_DWORD *)(a2 + 76);
      if ( count > 0 && count <= 256 )
        memcpy(*(unsigned __int8 **)(a2 + 76), src, count);
    }
    if ( a5 )
    {
      v5 = 1 << *(_BYTE *)(a2 + 24);
      if ( !*(_BYTE *)(a2 + 25) && *((unsigned __int16 *)a5 + 4) > v5
        || *(_BYTE *)(a2 + 25) == 2
        && (*((unsigned __int16 *)a5 + 1) > v5
         || *((unsigned __int16 *)a5 + 2) > v5
         || *((unsigned __int16 *)a5 + 3) > v5) )
      {
        png_warning(a1, "tRNS chunk has out-of-range samples for bit_depth");
      }
      memcpy((unsigned __int8 *)(a2 + 80), a5, 0xAu);
      if ( !count )
        count = 1;
    }
    *(_WORD *)(a2 + 22) = count;
    if ( count )
    {
      *(_DWORD *)(a2 + 8) |= 0x10u;
      *(_DWORD *)(a2 + 184) |= 0x2000u;
    }
  }
}
