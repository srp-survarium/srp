int __cdecl png_set_tRNS_to_alpha(int a1)
{
  int result; // eax

  *(_DWORD *)(a1 + 116) |= 0x2001000u;
  result = a1;
  *(_DWORD *)(a1 + 112) &= ~0x40u;
  return result;
}
