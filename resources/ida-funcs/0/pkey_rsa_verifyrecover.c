int __usercall pkey_rsa_verifyrecover@<eax>(
        int a1@<ebx>,
        evp_pkey_ctx_st *ctx,
        unsigned __int8 *rout,
        evp_pkey_ctx_st **routlen,
        const unsigned __int8 *sig,
        int siglen)
{
  evp_pkey_ctx_st *v6; // edi
  void *data; // esi
  const ssl_st *v8; // eax
  int v9; // ecx
  int v11; // eax
  evp_pkey_ctx_st *v12; // edi
  int v13; // eax
  void *v14; // eax
  unsigned __int8 *v15; // [esp-14h] [ebp-1Ch]
  const unsigned __int8 *v16; // [esp-Ch] [ebp-14h]
  int v17; // [esp-8h] [ebp-10h]
  char *ptr; // [esp-4h] [ebp-Ch]

  v6 = ctx;
  data = ctx->data;
  v8 = (const ssl_st *)*((_DWORD *)data + 5);
  if ( v8 )
  {
    v9 = *((_DWORD *)data + 4);
    if ( v9 == 5 )
    {
      if ( !setup_tbuf((RSA_PKEY_CTX *)data, ctx) )
        return -1;
      v11 = RSA_public_decrypt(siglen, sig, *((unsigned __int8 **)data + 7), v6->pkey->pkey.rsa);
      if ( v11 < 1 )
        return 0;
      v12 = (evp_pkey_ctx_st *)(v11 - 1);
      v13 = EVP_CIPHER_CTX_cipher(*((const ssl_st **)data + 5));
      if ( *((unsigned __int8 *)&v12->pmeth + *((_DWORD *)data + 7)) != RSA_X931_hash_id(v13) )
      {
        ERR_put_error(a1, 4u, 141, 100, ".\\crypto\\rsa\\rsa_pmeth.c", 231);
        return 0;
      }
      if ( v12 != (evp_pkey_ctx_st *)EVP_MD_size(a1, *((const env_md_st **)data + 5)) )
      {
        ERR_put_error(a1, 4u, 141, 143, ".\\crypto\\rsa\\rsa_pmeth.c", 237);
        return 0;
      }
      if ( rout )
        memcpy((int)rout, *((const __m128i **)data + 7), (unsigned int)v12);
    }
    else
    {
      if ( v9 != 1 )
        return -1;
      ptr = ctx->pkey->pkey.ptr;
      v17 = siglen;
      v16 = sig;
      v15 = rout;
      v14 = (void *)EVP_CIPHER_CTX_cipher(v8);
      if ( int_rsa_verify(a1, v14, 0, 0, v15, (unsigned int *)&ctx, v16, v17, (rsa_st *)ptr) <= 0 )
        return 0;
      v12 = ctx;
    }
  }
  else
  {
    v12 = (evp_pkey_ctx_st *)RSA_public_decrypt(siglen, sig, rout, ctx->pkey->pkey.rsa);
  }
  if ( (int)v12 < 0 )
    return (int)v12;
  *routlen = v12;
  return 1;
}
