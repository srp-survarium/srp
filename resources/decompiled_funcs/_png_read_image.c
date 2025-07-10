void __cdecl png_read_image(int a1, unsigned __int8 **a2)
{
  int v2; // [esp+0h] [ebp-14h]
  int i; // [esp+4h] [ebp-10h]
  unsigned __int8 **v4; // [esp+8h] [ebp-Ch]
  unsigned int j; // [esp+Ch] [ebp-8h]
  unsigned int v6; // [esp+10h] [ebp-4h]

  if ( a1 )
  {
    if ( (*(_DWORD *)(a1 + 112) & 0x40) != 0 )
    {
      if ( *(_BYTE *)(a1 + 312) && (*(_DWORD *)(a1 + 116) & 2) == 0 )
      {
        png_warning(a1, "Interlace handling should be turned on when using png_read_image");
        *(_DWORD *)(a1 + 236) = *(_DWORD *)(a1 + 232);
      }
      v2 = png_set_interlace_handling(a1);
    }
    else
    {
      v2 = png_set_interlace_handling(a1);
      png_start_read_image(a1);
    }
    v6 = *(_DWORD *)(a1 + 232);
    for ( i = 0; i < v2; ++i )
    {
      v4 = a2;
      for ( j = 0; j < v6; ++j )
        png_read_row(a1, *v4++, 0);
    }
  }
}
