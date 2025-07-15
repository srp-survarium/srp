int __cdecl err_state_LHASH_HASH(const env_md_st *md)
{
  return 13 * EVP_CIPHER_block_size(md);
}
