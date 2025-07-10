int __cdecl X509_STORE_add_cert(x509_store_st *ctx, x509_st *x)
{
  int v2; // ebx
  x509_object_st *v4; // eax
  x509_object_st *v5; // esi

  v2 = 1;
  if ( !x )
    return 0;
  v4 = (x509_object_st *)CRYPTO_malloc(8, ".\\crypto\\x509\\x509_lu.c", 340);
  v5 = v4;
  if ( v4 )
  {
    v4->type = 1;
    v4->data.ptr = (char *)x;
    CRYPTO_lock((unsigned int)x, 9, 11, ".\\crypto\\x509\\x509_lu.c", 349);
    X509_OBJECT_up_ref_count(v5);
    if ( X509_OBJECT_retrieve_match(ctx->objs, v5) )
    {
      X509_OBJECT_free_contents(v5);
      CRYPTO_free(v5);
      ERR_put_error(0xBu, 124, 101, ".\\crypto\\x509\\x509_lu.c", 357);
      v2 = 0;
    }
    else
    {
      sk_push(&ctx->objs->stack, (char *)v5);
    }
    CRYPTO_lock((unsigned int)ctx, 10, 11, ".\\crypto\\x509\\x509_lu.c", 362);
    return v2;
  }
  else
  {
    ERR_put_error(0xBu, 124, 65, ".\\crypto\\x509\\x509_lu.c", 343);
    return 0;
  }
}
