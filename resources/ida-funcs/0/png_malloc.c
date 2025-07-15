int __cdecl png_malloc(int a1, unsigned int size)
{
  int v3; // [esp+0h] [ebp-4h]

  if ( !a1 || !size )
    return 0;
  if ( *(_DWORD *)(a1 + 612) )
    v3 = (*(int (__cdecl **)(int, unsigned int))(a1 + 612))(a1, size);
  else
    v3 = png_malloc_default(a1, size);
  if ( !v3 && (*(_DWORD *)(a1 + 112) & 0x100000) == 0 )
    png_error(a1, (int)"Out of Memory");
  return v3;
}
