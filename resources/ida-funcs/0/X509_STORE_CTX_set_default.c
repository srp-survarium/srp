const X509_VERIFY_PARAM_st *__cdecl X509_STORE_CTX_set_default(X509_VERIFY_PARAM_st *ctx, char *name)
{
  const X509_VERIFY_PARAM_st *result; // eax

  result = X509_VERIFY_PARAM_lookup(name);
  if ( result )
    return (const X509_VERIFY_PARAM_st *)X509_VERIFY_PARAM_inherit((X509_VERIFY_PARAM_st *)ctx->flags, result);
  return result;
}
