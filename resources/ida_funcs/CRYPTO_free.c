void __cdecl CRYPTO_free(void *str)
{
  if ( free_debug_func )
    free_debug_func(str, 0);
  free_func(str);
  if ( free_debug_func )
    free_debug_func(0, 1);
}
