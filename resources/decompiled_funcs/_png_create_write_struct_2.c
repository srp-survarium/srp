_DWORD *__cdecl png_create_write_struct_2(char *a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v8; // eax
  _DWORD *pointer; // [esp+0h] [ebp-8h]
  BOOL v10; // [esp+4h] [ebp-4h]

  pointer = (_DWORD *)png_create_struct_2(1, a6, a5);
  if ( !pointer )
    return 0;
  pointer[160] = 0x7FFFFFFF;
  pointer[161] = 0x7FFFFFFF;
  v8 = png_set_longjmp_fn((int)pointer, (int)longjmp, 64);
  if ( _setjmp3(v8, 0) )
    ExitProcess(0);
  png_set_mem_fn(pointer, a5, a6, a7);
  png_set_error_fn(pointer, a2, a3, a4);
  v10 = png_user_version_check((int)pointer, a1) == 0;
  pointer[45] = 0x2000;
  if ( !v10 )
  {
    pointer[44] = png_malloc_warn((int)pointer, pointer[45]);
    v10 = pointer[44] == 0;
  }
  if ( v10 )
  {
    png_free((int)pointer, (void *)pointer[44]);
    pointer[44] = 0;
    png_destroy_struct_2(pointer, a7, a5);
    return 0;
  }
  else
  {
    png_set_write_fn(pointer, 0, 0, 0);
    sub_3624D0(pointer);
    return pointer;
  }
}
