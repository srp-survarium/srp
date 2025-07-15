int __cdecl png_set_longjmp_fn(int a1, int a2, int a3)
{
  if ( !a1 || a3 != 64 )
    return 0;
  *(_DWORD *)(a1 + 64) = a2;
  return a1;
}
