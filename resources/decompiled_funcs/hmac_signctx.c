int __cdecl hmac_signctx(evp_pkey_ctx_st *ctx, unsigned __int8 *sig, unsigned int *siglen, env_md_ctx_st *mctx)
{
  char *data; // edi
  ui_string_st *object; // eax
  int v6; // eax
  unsigned int *v8; // esi

  data = (char *)ctx->data;
  object = X509_EXTENSION_get_object((ui_string_st *)mctx);
  v6 = EVP_MD_size((const env_md_st *)object);
  if ( v6 < 0 )
    return 0;
  v8 = siglen;
  *siglen = v6;
  if ( sig )
  {
    HMAC_Final((hmac_ctx_st *)(data + 20), sig, (unsigned int *)&ctx);
    *v8 = (unsigned int)ctx;
  }
  return 1;
}
