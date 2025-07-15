int __cdecl png_malloc_warn(int a1, unsigned int size)
{
  int result; // eax
  int v3; // [esp+0h] [ebp-8h]

  if ( !a1 )
    return 0;
  v3 = *(_DWORD *)(a1 + 112);
  *(_DWORD *)(a1 + 112) = v3 | 0x100000;
  result = png_malloc(a1, size);
  *(_DWORD *)(a1 + 112) = v3;
  return result;
}
