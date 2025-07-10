int __cdecl app_info_LHASH_HASH(const env_md_st *arg)
{
  unsigned int v1; // eax

  v1 = EVP_CIPHER_block_size(arg);
  return 17851 * v1 + 7 * (v1 >> 14) + 251 * (v1 >> 4);
}
