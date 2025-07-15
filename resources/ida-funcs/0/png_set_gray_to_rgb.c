int __cdecl png_set_gray_to_rgb(int a1)
{
  int result; // eax

  if ( a1 )
  {
    png_set_expand_gray_1_2_4_to_8(a1);
    *(_DWORD *)(a1 + 116) |= 0x4000u;
    result = a1;
    *(_DWORD *)(a1 + 112) &= ~0x40u;
  }
  return result;
}
