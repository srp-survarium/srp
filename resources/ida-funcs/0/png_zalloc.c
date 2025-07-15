int __cdecl png_zalloc(int a1, unsigned int a2, unsigned int a3)
{
  int result; // eax
  int v4; // [esp+0h] [ebp-10h]

  v4 = *(_DWORD *)(a1 + 112);
  if ( !a1 )
    return 0;
  if ( a2 <= 0xFFFFFFFF / a3 )
  {
    *(_DWORD *)(a1 + 112) |= (unsigned int)&loc_100000;
    result = png_malloc(a1, a3 * a2);
    *(_DWORD *)(a1 + 112) = v4;
  }
  else
  {
    png_warning(a1, "Potential overflow in png_zalloc()");
    return 0;
  }
  return result;
}
