void __cdecl EVP_PKEY_free(evp_pkey_st *x)
{
  const evp_pkey_asn1_method_st *ameth; // eax
  void (__cdecl *pkey_free)(evp_pkey_st *); // eax
  stack_st_X509_ATTRIBUTE *attributes; // eax

  if ( x && CRYPTO_add_lock(&x->references, -1, 10, ".\\crypto\\evp\\p_lib.c", 393) <= 0 )
  {
    ameth = x->ameth;
    if ( ameth )
    {
      pkey_free = ameth->pkey_free;
      if ( pkey_free )
      {
        pkey_free(x);
        x->pkey.ptr = 0;
      }
    }
    if ( x->engine )
    {
      ENGINE_finish(x->engine);
      x->engine = 0;
    }
    attributes = x->attributes;
    if ( attributes )
      sk_pop_free(&attributes->stack, (void (__cdecl *)(void *))X509_ATTRIBUTE_free);
    CRYPTO_free(x);
  }
}
