int __cdecl md_new(bio_st *bi)
{
  env_md_ctx_st *v1; // eax

  v1 = EVP_MD_CTX_create();
  if ( !v1 )
    return 0;
  bi->ptr = v1;
  bi->init = 0;
  bi->flags = 0;
  return 1;
}
