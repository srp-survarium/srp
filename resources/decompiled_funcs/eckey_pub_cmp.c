unsigned int __cdecl eckey_pub_cmp(const evp_pkey_st *a, const evp_pkey_st *b)
{
  const ec_group_st *v2; // edi
  const ec_point_st *v3; // ebx
  const ec_point_st *v4; // eax
  int v5; // eax

  v2 = (const ec_group_st *)EVP_CIPHER_block_size((const env_md_st *)b->pkey.ptr);
  v3 = (const ec_point_st *)EC_KEY_get0_public_key((const engine_st *)a->pkey.ptr);
  v4 = (const ec_point_st *)EC_KEY_get0_public_key((const engine_st *)b->pkey.ptr);
  v5 = EC_POINT_cmp(v2, v3, v4, 0);
  if ( v5 )
    return v5 != 1 ? 0xFFFFFFFE : 0;
  else
    return 1;
}
