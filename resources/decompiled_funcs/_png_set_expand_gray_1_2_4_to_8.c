int __cdecl png_set_expand_gray_1_2_4_to_8(int a1)
{
  int result; // eax

  if ( a1 )
  {
    *(_DWORD *)(a1 + 116) |= 0x1000u;
    result = a1;
    *(_DWORD *)(a1 + 112) &= ~0x40u;
  }
  return result;
}
