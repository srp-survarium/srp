void *__cdecl png_malloc_default(int a1, unsigned int size)
{
  if ( a1 && size )
    return malloc(size);
  else
    return 0;
}
