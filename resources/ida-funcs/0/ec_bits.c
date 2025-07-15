int __usercall ec_bits@<eax>(int a1@<ebx>, const evp_pkey_st *pkey)
{
  bignum_st *v2; // esi
  const ec_group_st *v4; // eax
  int v5; // edi

  v2 = BN_new(a1);
  if ( v2
    && (v4 = (const ec_group_st *)EVP_CIPHER_block_size((const env_md_st *)pkey->pkey.ptr), EC_GROUP_get_order(v4, v2)) )
  {
    v5 = BN_num_bits(v2);
    BN_free(v2);
    return v5;
  }
  else
  {
    ERR_clear_error(a1);
    return 0;
  }
}
