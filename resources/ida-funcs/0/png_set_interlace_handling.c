int __cdecl png_set_interlace_handling(int a1)
{
  if ( !a1 || !*(_BYTE *)(a1 + 312) )
    return 1;
  *(_DWORD *)(a1 + 116) |= 2u;
  return 7;
}
