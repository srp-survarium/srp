int __cdecl png_destroy_gamma_table(int a1)
{
  int result; // eax
  int v2; // [esp+0h] [ebp-18h]
  int k; // [esp+4h] [ebp-14h]
  int v4; // [esp+8h] [ebp-10h]
  int j; // [esp+Ch] [ebp-Ch]
  int v6; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  png_free(a1, *(void **)(a1 + 384));
  *(_DWORD *)(a1 + 384) = 0;
  if ( *(_DWORD *)(a1 + 388) )
  {
    v6 = 1 << (8 - *(_BYTE *)(a1 + 372));
    for ( i = 0; i < v6; ++i )
      png_free(a1, *(void **)(*(_DWORD *)(a1 + 388) + 4 * i));
    png_free(a1, *(void **)(a1 + 388));
    *(_DWORD *)(a1 + 388) = 0;
  }
  png_free(a1, *(void **)(a1 + 392));
  *(_DWORD *)(a1 + 392) = 0;
  result = png_free(a1, *(void **)(a1 + 396));
  *(_DWORD *)(a1 + 396) = 0;
  if ( *(_DWORD *)(a1 + 400) )
  {
    v4 = 1 << (8 - *(_BYTE *)(a1 + 372));
    for ( j = 0; j < v4; ++j )
      png_free(a1, *(void **)(*(_DWORD *)(a1 + 400) + 4 * j));
    result = png_free(a1, *(void **)(a1 + 400));
    *(_DWORD *)(a1 + 400) = 0;
  }
  if ( *(_DWORD *)(a1 + 404) )
  {
    v2 = 1 << (8 - *(_BYTE *)(a1 + 372));
    for ( k = 0; k < v2; ++k )
      png_free(a1, *(void **)(*(_DWORD *)(a1 + 404) + 4 * k));
    result = png_free(a1, *(void **)(a1 + 404));
    *(_DWORD *)(a1 + 404) = 0;
  }
  return result;
}
