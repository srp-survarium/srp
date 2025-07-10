env_md_ctx_st *__cdecl EVP_MD_CTX_create()
{
  env_md_ctx_st *result; // eax

  result = (env_md_ctx_st *)CRYPTO_malloc(24, ".\\crypto\\evp\\digest.c", 127);
  if ( result )
  {
    result->digest = 0;
    result->engine = 0;
    result->flags = 0;
    result->md_data = 0;
    result->pctx = 0;
    result->update = 0;
  }
  return result;
}
