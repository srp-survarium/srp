void __cdecl png_info_init_3(void **a1, unsigned int a2)
{
  void *pointer; // [esp+0h] [ebp-4h]

  pointer = *a1;
  if ( *a1 )
  {
    if ( a2 < 0xEC )
      png_destroy_struct(pointer);
    memset((int)pointer, 0, 236);
  }
}
