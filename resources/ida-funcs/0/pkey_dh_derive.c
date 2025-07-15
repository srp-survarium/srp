int __usercall pkey_dh_derive@<eax>(int a1@<ebx>, evp_pkey_ctx_st *ctx, unsigned __int8 *key, unsigned int *keylen)
{
  evp_pkey_st *pkey; // ecx
  evp_pkey_st *peerkey; // eax
  int result; // eax

  pkey = ctx->pkey;
  if ( pkey && (peerkey = ctx->peerkey) != 0 )
  {
    result = DH_compute_key(key, *((const bignum_st **)peerkey->pkey.ptr + 5), pkey->pkey.dh);
    if ( result >= 0 )
    {
      *keylen = result;
      return 1;
    }
  }
  else
  {
    ERR_put_error(a1, 5u, 112, 108, ".\\crypto\\dh\\dh_pmeth.c", 209);
    return 0;
  }
  return result;
}
