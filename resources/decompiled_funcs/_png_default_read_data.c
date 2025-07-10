void __cdecl png_default_read_data(int a1, char *buffer, unsigned int count)
{
  if ( a1 )
  {
    if ( fread(buffer, 1u, count, *(_iobuf **)(a1 + 88)) != count )
      png_error(a1, (int)"Read Error");
  }
}
