void __cdecl policy_cache_free(X509_POLICY_CACHE_st *cache)
{
  stack_st_X509_POLICY_DATA *data; // eax

  if ( cache )
  {
    if ( cache->anyPolicy )
      policy_data_free(cache->anyPolicy);
    data = cache->data;
    if ( data )
      sk_pop_free(&data->stack, (void (__cdecl *)(void *))policy_data_free);
    CRYPTO_free(cache);
  }
}
