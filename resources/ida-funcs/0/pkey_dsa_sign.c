int __cdecl pkey_dsa_sign(
        evp_pkey_ctx_st *ctx,
        unsigned __int8 *sig,
        unsigned int *siglen,
        unsigned __int8 *tbs,
        int tbslen)
{
  const ssl_st **data; // ecx
  char *ptr; // esi
  int v7; // eax
  int result; // eax

  data = (const ssl_st **)ctx->data;
  ptr = ctx->pkey->pkey.ptr;
  if ( data[5] )
    v7 = EVP_CIPHER_CTX_cipher(data[5]);
  else
    v7 = 64;
  result = DSA_sign(v7, tbs, tbslen, sig, (unsigned int *)&ctx, (dsa_st *)ptr);
  if ( result > 0 )
  {
    *siglen = (unsigned int)ctx;
    return 1;
  }
  return result;
}
