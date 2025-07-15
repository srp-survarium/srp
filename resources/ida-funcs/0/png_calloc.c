int __cdecl png_calloc(int a1, unsigned int size)
{
  int v3; // [esp+0h] [ebp-4h]

  v3 = png_malloc(a1, size);
  if ( v3 )
    memset(v3, 0, size);
  return v3;
}
