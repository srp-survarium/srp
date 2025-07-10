int __cdecl png_get_IHDR(
        _DWORD *a1,
        int a2,
        _DWORD *a3,
        _DWORD *a4,
        _DWORD *a5,
        _DWORD *a6,
        _DWORD *a7,
        _DWORD *a8,
        _DWORD *a9)
{
  if ( !a1 || !a2 || !a3 || !a4 || !a5 || !a6 )
    return 0;
  *a3 = *(_DWORD *)a2;
  *a4 = *(_DWORD *)(a2 + 4);
  *a5 = *(unsigned __int8 *)(a2 + 24);
  *a6 = *(unsigned __int8 *)(a2 + 25);
  if ( a8 )
    *a8 = *(unsigned __int8 *)(a2 + 26);
  if ( a9 )
    *a9 = *(unsigned __int8 *)(a2 + 27);
  if ( a7 )
    *a7 = *(unsigned __int8 *)(a2 + 28);
  png_check_IHDR(
    a1,
    *(_DWORD *)a2,
    *(_DWORD *)(a2 + 4),
    *(unsigned __int8 *)(a2 + 24),
    *(unsigned __int8 *)(a2 + 25),
    *(unsigned __int8 *)(a2 + 28),
    *(unsigned __int8 *)(a2 + 26),
    *(unsigned __int8 *)(a2 + 27));
  return 1;
}
