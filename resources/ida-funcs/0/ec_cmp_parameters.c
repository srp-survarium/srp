BOOL __cdecl ec_cmp_parameters(const evp_pkey_st *a, const evp_pkey_st *b)
{
  const ec_group_st *v2; // esi
  const ec_group_st *v3; // eax

  v2 = (const ec_group_st *)EVP_CIPHER_block_size((const env_md_st *)a->pkey.ptr);
  v3 = (const ec_group_st *)EVP_CIPHER_block_size((const env_md_st *)b->pkey.ptr);
  return EC_GROUP_cmp(v2, v3, 0) == 0;
}
