int __cdecl EVP_CIPHER_block_size(const env_md_st *md)
{
  return md->pkey_type;
}
