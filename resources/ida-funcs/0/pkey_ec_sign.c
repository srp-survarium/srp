int __cdecl pkey_ec_sign(
        evp_pkey_ctx_st *ctx,
        unsigned __int8 *sig,
        unsigned int *siglen,
        const unsigned __int8 *tbs,
        unsigned int tbslen)
{
  unsigned __int8 *v5; // ebx
  const ssl_st **data; // edi
  ec_key_st *ec; // esi
  unsigned int v8; // eax
  int result; // eax
  unsigned int v10; // eax
  unsigned int *v11; // ebp
  int v12; // eax

  v5 = sig;
  data = (const ssl_st **)ctx->data;
  ec = ctx->pkey->pkey.ec;
  if ( sig )
  {
    v10 = ECDSA_size(ec);
    v11 = siglen;
    if ( *siglen >= v10 )
    {
      if ( data[1] )
        v12 = EVP_CIPHER_CTX_cipher(data[1]);
      else
        v12 = 64;
      result = ECDSA_sign(v12, tbs, tbslen, v5, (unsigned int *)&ctx, ec);
      if ( result > 0 )
      {
        *v11 = (unsigned int)ctx;
        return 1;
      }
    }
    else
    {
      ERR_put_error(0x10u, 218, 100, ".\\crypto\\ec\\ec_pmeth.c", 134);
      return 0;
    }
  }
  else
  {
    v8 = ECDSA_size(ec);
    *siglen = v8;
    return 1;
  }
  return result;
}
