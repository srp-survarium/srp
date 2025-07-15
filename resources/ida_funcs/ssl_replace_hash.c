env_md_ctx_st *__usercall ssl_replace_hash@<eax>(unsigned int a1@<edi>, env_md_ctx_st **hash, const env_md_st *md)
{
  env_md_ctx_st *result; // eax

  if ( *hash )
    EVP_MD_CTX_destroy(a1, *hash);
  *hash = 0;
  result = EVP_MD_CTX_create();
  *hash = result;
  if ( md )
  {
    EVP_DigestInit_ex(result, md, 0);
    return *hash;
  }
  return result;
}
