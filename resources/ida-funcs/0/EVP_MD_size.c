int __usercall EVP_MD_size@<eax>(int a1@<ebx>, const env_md_st *md)
{
  if ( md )
    return md->md_size;
  ERR_put_error(a1, 6u, 162, 159, ".\\crypto\\evp\\evp_lib.c", 266);
  return -1;
}
