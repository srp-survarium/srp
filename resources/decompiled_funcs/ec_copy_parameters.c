int __cdecl ec_copy_parameters(evp_pkey_st *to, const evp_pkey_st *from)
{
  const ec_group_st *v2; // eax
  ec_group_st *v3; // esi

  v2 = (const ec_group_st *)EVP_CIPHER_block_size((const env_md_st *)from->pkey.ptr);
  v3 = EC_GROUP_dup(v2);
  if ( !v3 || !EC_KEY_set_group(to->pkey.ec, v3) )
    return 0;
  EC_GROUP_free(v3);
  return 1;
}
