int __cdecl EVP_MD_block_size(const env_md_st *md)
{
  return md->block_size;
}
