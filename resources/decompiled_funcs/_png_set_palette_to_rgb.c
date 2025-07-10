int __cdecl png_set_palette_to_rgb(int a1)
{
  int result; // eax

  if ( a1 )
  {
    *(_DWORD *)(a1 + 116) |= 0x2001000u;
    result = a1;
    *(_DWORD *)(a1 + 112) &= ~0x40u;
  }
  return result;
}
