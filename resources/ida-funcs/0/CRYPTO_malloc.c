void *__cdecl CRYPTO_malloc(int num, char *file, int line)
{
  void *v4; // ebp

  if ( num <= 0 )
    return 0;
  allow_customize = 0;
  if ( malloc_debug_func )
  {
    allow_customize_debug = 0;
    malloc_debug_func(0, num, file, line, 0);
  }
  v4 = malloc_ex_func(num, file, line);
  if ( malloc_debug_func )
    malloc_debug_func(v4, num, file, line, 1);
  return v4;
}
