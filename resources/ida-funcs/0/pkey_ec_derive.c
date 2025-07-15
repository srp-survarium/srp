int __usercall pkey_ec_derive@<eax>(int a1@<ebx>, evp_pkey_ctx_st *ctx, unsigned __int8 *key, unsigned int *keylen)
{
  evp_pkey_st *pkey; // ecx
  evp_pkey_st *peerkey; // eax
  const ec_group_st *v6; // eax
  int result; // eax
  const ec_point_st *v8; // eax

  pkey = ctx->pkey;
  if ( pkey && (peerkey = ctx->peerkey) != 0 )
  {
    if ( key )
    {
      v8 = (const ec_point_st *)EC_KEY_get0_public_key((const engine_st *)peerkey->pkey.ptr);
      result = (int)ECDH_compute_key(key, *keylen, v8, ctx->pkey->pkey.ec, 0);
      if ( result >= 0 )
      {
        *keylen = result;
        return 1;
      }
    }
    else
    {
      v6 = (const ec_group_st *)EVP_CIPHER_block_size((const env_md_st *)pkey->pkey.ptr);
      *keylen = (EC_GROUP_get_degree(v6) + 7) / 8;
      return 1;
    }
  }
  else
  {
    ERR_put_error(a1, 0x10u, 217, 140, ".\\crypto\\ec\\ec_pmeth.c", 177);
    return 0;
  }
  return result;
}
