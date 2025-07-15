const X509_POLICY_CACHE_st *__usercall policy_cache_set@<eax>(int a1@<ebx>, stack_st_X509_EXTENSION *x)
{
  if ( !x[3].stack.data )
  {
    CRYPTO_lock((int)x, a1, 9, 3, ".\\crypto\\x509v3\\pcy_cache.c", 251);
    policy_cache_new(x);
    CRYPTO_lock((int)x, a1, 10, 3, ".\\crypto\\x509v3\\pcy_cache.c", 253);
  }
  return (const X509_POLICY_CACHE_st *)x[3].stack.data;
}
