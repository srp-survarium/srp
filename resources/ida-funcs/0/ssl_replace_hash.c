env_md_ctx_st *__usercall ssl_replace_hash@<eax>(
        int a1@<edi>,
        engine_st *a2@<ebx>,
        env_md_ctx_st **hash,
        const env_md_st *md)
{
  env_md_ctx_st *result; // eax

  if ( *hash )
    EVP_MD_CTX_destroy(a1, (int)a2, *hash);
  *hash = 0;
  result = EVP_MD_CTX_create();
  *hash = result;
  if ( md )
  {
    EVP_DigestInit_ex(a2, result, md, 0);
    return *hash;
  }
  return result;
}
