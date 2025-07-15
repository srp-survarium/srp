int __cdecl EVP_MD_size(const env_md_st *md)
{
  if ( md )
    return md->md_size;
  ERR_put_error(6u, 162, 159, ".\\crypto\\evp\\evp_lib.c", 266);
  return -1;
}
