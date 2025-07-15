int __cdecl pkey_rsa_verifyrecover(
        evp_pkey_ctx_st *ctx,
        unsigned __int8 *rout,
        unsigned int *routlen,
        unsigned __int8 *sig,
        unsigned int siglen)
{
  evp_pkey_ctx_st *v5; // edi
  void *data; // esi
  const ssl_st *v7; // eax
  int v8; // ecx
  int v10; // eax
  evp_pkey_ctx_st *v11; // edi
  int v12; // eax
  unsigned int v13; // eax
  unsigned __int8 *v14; // [esp-14h] [ebp-1Ch]
  unsigned __int8 *v15; // [esp-Ch] [ebp-14h]
  int v16; // [esp-8h] [ebp-10h]
  char *ptr; // [esp-4h] [ebp-Ch]

  v5 = ctx;
  data = ctx->data;
  v7 = (const ssl_st *)*((_DWORD *)data + 5);
  if ( v7 )
  {
    v8 = *((_DWORD *)data + 4);
    if ( v8 == 5 )
    {
      if ( !setup_tbuf((RSA_PKEY_CTX *)data, ctx) )
        return -1;
      v10 = RSA_public_decrypt(siglen, sig, *((unsigned __int8 **)data + 7), v5->pkey->pkey.rsa);
      if ( v10 < 1 )
        return 0;
      v11 = (evp_pkey_ctx_st *)(v10 - 1);
      v12 = EVP_CIPHER_CTX_cipher(*((const ssl_st **)data + 5));
      if ( *((unsigned __int8 *)&v11->pmeth + *((_DWORD *)data + 7)) != RSA_X931_hash_id(v12) )
      {
        ERR_put_error(4u, 141, 100, ".\\crypto\\rsa\\rsa_pmeth.c", 231);
        return 0;
      }
      if ( v11 != (evp_pkey_ctx_st *)EVP_MD_size(*((const env_md_st **)data + 5)) )
      {
        ERR_put_error(4u, 141, 143, ".\\crypto\\rsa\\rsa_pmeth.c", 237);
        return 0;
      }
      if ( rout )
        memcpy(rout, *((unsigned __int8 **)data + 7), (unsigned int)v11);
    }
    else
    {
      if ( v8 != 1 )
        return -1;
      ptr = ctx->pkey->pkey.ptr;
      v16 = siglen;
      v15 = sig;
      v14 = rout;
      v13 = EVP_CIPHER_CTX_cipher(v7);
      if ( int_rsa_verify(v13, 0, 0, v14, (unsigned int *)&ctx, v15, v16, (rsa_st *)ptr) <= 0 )
        return 0;
      v11 = ctx;
    }
  }
  else
  {
    v11 = (evp_pkey_ctx_st *)RSA_public_decrypt(siglen, sig, rout, ctx->pkey->pkey.rsa);
  }
  if ( (int)v11 < 0 )
    return (int)v11;
  *routlen = (unsigned int)v11;
  return 1;
}
