int __usercall md_free@<eax>(int a1@<edi>, int a2@<ebx>, bio_st *a)
{
  if ( !a )
    return 0;
  EVP_MD_CTX_destroy(a1, a2, (env_md_ctx_st *)a->ptr);
  a->ptr = 0;
  a->init = 0;
  a->flags = 0;
  return 1;
}
