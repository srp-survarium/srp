void __cdecl __noreturn Scaleform::Render::PNG::png_error_handler(png_struct_def *png_ptr, char *msg)
{
  unsigned int v2; // edi
  int error_ptr; // eax
  int v4; // esi

  v2 = strlen(msg);
  error_ptr = png_get_error_ptr(png_ptr);
  v4 = error_ptr;
  if ( v2 >= 0x64 )
  {
    strncpy_s(v2, (char *)(error_ptr + 32), 100, msg, 0x63u);
    *(_BYTE *)(v4 + 131) = 0;
  }
  else
  {
    strcpy_s(v2, (char *)(error_ptr + 32), 100, msg);
  }
  png_longjmp(png_ptr, 1);
}
