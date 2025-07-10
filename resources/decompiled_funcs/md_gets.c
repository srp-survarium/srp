int __usercall md_gets@<eax>(unsigned int a1@<edi>, bio_st *bp, char *buf, int size)
{
  env_md_ctx_st *ptr; // eax

  ptr = (env_md_ctx_st *)bp->ptr;
  if ( size < ptr->digest->md_size )
    return 0;
  if ( EVP_DigestFinal_ex(a1, ptr, (unsigned __int8 *)buf, (unsigned int *)&bp) > 0 )
    return (int)bp;
  return -1;
}
