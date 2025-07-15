int __cdecl png_set_strip_16(int a1)
{
  int result; // eax

  if ( a1 )
  {
    result = a1;
    *(_DWORD *)(a1 + 116) |= 0x400u;
  }
  return result;
}
