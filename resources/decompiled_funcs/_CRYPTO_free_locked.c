void __cdecl CRYPTO_free_locked(void *str)
{
  if ( free_debug_func )
    free_debug_func(str, 0);
  free_locked_func(str);
  if ( free_debug_func )
    free_debug_func(0, 1);
}
