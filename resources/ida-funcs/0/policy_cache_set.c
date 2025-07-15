const X509_POLICY_CACHE_st *__cdecl policy_cache_set(x509_st *x)
{
  if ( !x->policy_cache )
  {
    CRYPTO_lock((unsigned int)x, 9, 3, ".\\crypto\\x509v3\\pcy_cache.c", 251);
    policy_cache_new(x);
    CRYPTO_lock((unsigned int)x, 10, 3, ".\\crypto\\x509v3\\pcy_cache.c", 253);
  }
  return x->policy_cache;
}
