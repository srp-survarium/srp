void __cdecl png_info_init_3(unsigned __int8 **a1, unsigned int a2)
{
  unsigned __int8 *dst; // [esp+0h] [ebp-4h]

  dst = *a1;
  if ( *a1 )
  {
    if ( a2 < 0xEC )
      png_destroy_struct(dst);
    memset((int)dst, 0, 0xECu);
  }
}
