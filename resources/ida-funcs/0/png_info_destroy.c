void __cdecl png_info_destroy(int a1, int a2)
{
  png_free_data(a1, a2, 0x7FFF, -1);
  if ( *(_DWORD *)(a1 + 584) )
  {
    png_free(a1, *(void **)(a1 + 588));
    *(_DWORD *)(a1 + 588) = 0;
    *(_DWORD *)(a1 + 584) = 0;
  }
  png_info_init_3((void **)&a2, 0xECu);
}
