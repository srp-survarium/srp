unsigned __int8 *__cdecl CRYPTO_realloc_clean(__m128i *str, unsigned int old_len, int num, char *file, int line)
{
  void *v6; // esi

  if ( !str )
    return (unsigned __int8 *)CRYPTO_malloc(num, file, line);
  if ( num <= 0 )
    return 0;
  if ( realloc_debug_func )
    realloc_debug_func(str, 0, num, file, line, 0);
  v6 = malloc_ex_func(num, file, line);
  if ( v6 )
  {
    memcpy((int)v6, str, old_len);
    OPENSSL_cleanse(str, old_len);
    free_func(str);
  }
  if ( realloc_debug_func )
    realloc_debug_func(str, v6, num, file, line, 1);
  return (unsigned __int8 *)v6;
}
