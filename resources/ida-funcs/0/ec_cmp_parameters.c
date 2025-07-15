BOOL __cdecl ec_cmp_parameters(const evp_pkey_st *a, const evp_pkey_st *b)
{
  bignum_st *v2; // esi
  bignum_st *v3; // eax

  v2 = (bignum_st *)EVP_CIPHER_block_size((const env_md_st *)a->pkey.ptr);
  v3 = (bignum_st *)EVP_CIPHER_block_size((const env_md_st *)b->pkey.ptr);
  return EC_GROUP_cmp(v2, v3, 0) == 0;
}
