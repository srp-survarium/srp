void __cdecl png_set_hIST(int a1, int a2, int a3)
{
  int i; // [esp+4h] [ebp-4h]

  if ( a1 && a2 )
  {
    if ( *(_WORD *)(a2 + 20) && *(unsigned __int16 *)(a2 + 20) <= 0x100u )
    {
      png_free_data(a1, a2, 8, 0);
      *(_DWORD *)(a1 + 512) = png_malloc_warn(a1, 0x200u);
      if ( *(_DWORD *)(a1 + 512) )
      {
        for ( i = 0; i < *(unsigned __int16 *)(a2 + 20); ++i )
          *(_WORD *)(*(_DWORD *)(a1 + 512) + 2 * i) = *(_WORD *)(a3 + 2 * i);
        *(_DWORD *)(a2 + 124) = *(_DWORD *)(a1 + 512);
        *(_DWORD *)(a2 + 8) |= 0x40u;
        *(_DWORD *)(a2 + 184) |= 8u;
      }
      else
      {
        png_warning(a1, "Insufficient memory for hIST chunk data");
      }
    }
    else
    {
      png_warning(a1, "Invalid palette size, hIST allocation skipped");
    }
  }
}
