int __cdecl png_get_gAMA_fixed(int a1, int a2, _DWORD *a3)
{
  if ( !a1 || !a2 || (*(_DWORD *)(a2 + 8) & 1) == 0 || !a3 )
    return 0;
  *a3 = *(_DWORD *)(a2 + 40);
  return 1;
}
