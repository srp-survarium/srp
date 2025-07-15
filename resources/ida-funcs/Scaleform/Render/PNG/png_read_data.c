void __cdecl Scaleform::Render::PNG::png_read_data(png_struct_def *png_ptr, unsigned __int8 *data, unsigned int length)
{
  int io_ptr; // eax
  int v4; // eax

  io_ptr = png_get_io_ptr(png_ptr);
  v4 = (*(int (__thiscall **)(int, unsigned __int8 *, unsigned int))(*(_DWORD *)io_ptr + 40))(io_ptr, data, length);
  if ( v4 < 0 || v4 != length )
    png_error(png_ptr, "Read Error.");
}
