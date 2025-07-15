int __cdecl png_start_read_image(int a1)
{
  int result; // eax

  if ( a1 )
    return png_read_start_row(a1);
  return result;
}
