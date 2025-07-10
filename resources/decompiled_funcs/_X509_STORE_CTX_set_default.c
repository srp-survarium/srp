const X509_VERIFY_PARAM_st *__cdecl X509_STORE_CTX_set_default(x509_store_ctx_st *ctx, const char *name)
{
  const X509_VERIFY_PARAM_st *result; // eax

  result = X509_VERIFY_PARAM_lookup(name);
  if ( result )
    return (const X509_VERIFY_PARAM_st *)X509_VERIFY_PARAM_inherit(ctx->param, result);
  return result;
}
