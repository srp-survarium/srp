int __cdecl ec_bits(const evp_pkey_st *pkey)
{
  bignum_st *v1; // esi
  const ec_group_st *v3; // eax
  int v4; // edi

  v1 = BN_new();
  if ( v1
    && (v3 = (const ec_group_st *)EVP_CIPHER_block_size((const env_md_st *)pkey->pkey.ptr), EC_GROUP_get_order(
                                                                                              v3,
                                                                                              v1,
                                                                                              0)) )
  {
    v4 = BN_num_bits(v1);
    BN_free(v1);
    return v4;
  }
  else
  {
    ERR_clear_error();
    return 0;
  }
}
