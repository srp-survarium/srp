char *__cdecl png_create_read_struct_2(char *a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v8; // eax
  char *pointer; // [esp+4h] [ebp-8h]
  BOOL v10; // [esp+8h] [ebp-4h]

  pointer = (char *)png_create_struct_2(1, a6, a5);
  if ( !pointer )
    return 0;
  *((_DWORD *)pointer + 160) = 0x7FFFFFFF;
  *((_DWORD *)pointer + 161) = 0x7FFFFFFF;
  *((_DWORD *)pointer + 162) = 0;
  *((_DWORD *)pointer + 163) = 0;
  v8 = png_set_longjmp_fn((int)pointer, (int)longjmp, 64);
  if ( _setjmp3(v8, 0) )
    ExitProcess(0);
  png_set_mem_fn(pointer, a5, a6, a7);
  png_set_error_fn(pointer, a2, a3, a4);
  v10 = png_user_version_check((int)pointer, a1) == 0;
  if ( !v10 )
  {
    *((_DWORD *)pointer + 45) = 0x2000;
    *((_DWORD *)pointer + 44) = png_malloc_warn((int)pointer, *((_DWORD *)pointer + 45));
    v10 = *((_DWORD *)pointer + 44) == 0;
  }
  *((_DWORD *)pointer + 38) = png_zalloc;
  *((_DWORD *)pointer + 39) = png_zfree;
  *((_DWORD *)pointer + 40) = pointer;
  if ( !v10 )
  {
    switch ( inflateInit_((z_stream_s *)(pointer + 120), "1.2.7", 56) )
    {
      case -6:
        png_warning((int)pointer, "zlib version error");
        v10 = 1;
        break;
      case -4:
        png_warning((int)pointer, "zlib memory error");
        v10 = 1;
        break;
      case -2:
        png_warning((int)pointer, "zlib stream error");
        v10 = 1;
        break;
      case 0:
        break;
      default:
        png_warning((int)pointer, "Unknown zlib error");
        v10 = 1;
        break;
    }
  }
  if ( v10 )
  {
    png_free((int)pointer, *((void **)pointer + 44));
    *((_DWORD *)pointer + 44) = 0;
    png_destroy_struct_2(pointer, a7, a5);
    return 0;
  }
  else
  {
    *((_DWORD *)pointer + 33) = *((_DWORD *)pointer + 44);
    *((_DWORD *)pointer + 34) = *((_DWORD *)pointer + 45);
    png_set_read_fn(pointer, 0, 0);
    return pointer;
  }
}
