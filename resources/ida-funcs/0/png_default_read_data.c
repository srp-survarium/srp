void __usercall png_default_read_data(int a1@<ebx>, int a2@<edi>, int a3, unsigned __int8 *buffer, unsigned int count)
{
  if ( a3 )
  {
    if ( fread(a1, a2, buffer, 1u, count, *(_iobuf **)(a3 + 88)) != count )
      png_error(a3, (int)"Read Error");
  }
}
