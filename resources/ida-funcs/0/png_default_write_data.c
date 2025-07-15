void __usercall png_default_write_data(int a1@<ebx>, int a2@<edi>, int a3, const __m128i *buffer, unsigned int count)
{
  if ( a3 )
  {
    if ( fwrite(a1, a2, buffer, 1u, count, *(_iobuf **)(a3 + 88)) != count )
      png_error(a3, (int)"Write Error");
  }
}
