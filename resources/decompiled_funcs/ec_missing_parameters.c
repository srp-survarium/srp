BOOL __cdecl ec_missing_parameters(const evp_pkey_st *pkey)
{
  return EVP_CIPHER_block_size((const env_md_st *)pkey->pkey.ptr) == 0;
}
