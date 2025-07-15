void *__cdecl CRYPTO_realloc(void *str, int num, char *file, int line)
{
  void *result; // eax
  void *v6; // [esp+8h] [ebp+4h]

  if ( !str )
    return CRYPTO_malloc(num, file, line);
  if ( num <= 0 )
    return 0;
  if ( realloc_debug_func )
    realloc_debug_func(str, 0, num, file, line, 0);
  result = realloc_ex_func(str, num, file, line);
  v6 = result;
  if ( realloc_debug_func )
  {
    realloc_debug_func(str, result, num, file, line, 1);
    return v6;
  }
  return result;
}
