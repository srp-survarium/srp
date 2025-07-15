int __usercall hmac_signctx@<eax>(
        int a1@<ebx>,
        evp_pkey_ctx_st *ctx,
        unsigned __int8 *sig,
        unsigned int *siglen,
        ui_string_st *mctx)
{
  char *data; // edi
  ui_string_st *object; // eax
  int v7; // eax
  unsigned int *v9; // esi

  data = (char *)ctx->data;
  object = X509_EXTENSION_get_object(mctx);
  v7 = EVP_MD_size(a1, (const env_md_st *)object);
  if ( v7 < 0 )
    return 0;
  v9 = siglen;
  *siglen = v7;
  if ( sig )
  {
    HMAC_Final((hmac_ctx_st *)(data + 20), sig, (unsigned int *)&ctx);
    *v9 = (unsigned int)ctx;
  }
  return 1;
}
