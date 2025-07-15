int __cdecl png_create_info_struct(int a1)
{
  int v1; // ecx
  int struct_2; // [esp+0h] [ebp-4h] BYREF

  struct_2 = v1;
  if ( !a1 )
    return 0;
  struct_2 = png_create_struct_2(2, *(_DWORD *)(a1 + 612), *(_DWORD *)(a1 + 608));
  if ( struct_2 )
    png_info_init_3(&struct_2, 236);
  return struct_2;
}
