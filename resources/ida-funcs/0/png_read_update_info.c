int __cdecl png_read_update_info(int a1, int a2)
{
  int result; // eax

  if ( a1 )
  {
    png_read_start_row(a1);
    return png_read_transform_info(a1, a2);
  }
  return result;
}
