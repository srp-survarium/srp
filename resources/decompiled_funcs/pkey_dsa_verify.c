int __cdecl pkey_dsa_verify(
        evp_pkey_ctx_st *ctx,
        unsigned __int8 *sig,
        unsigned __int8 *siglen,
        const unsigned __int8 *tbs,
        unsigned int tbslen)
{
  const ssl_st **data; // ecx
  char *ptr; // esi
  int v7; // eax

  data = (const ssl_st **)ctx->data;
  ptr = ctx->pkey->pkey.ptr;
  if ( data[5] )
    v7 = EVP_CIPHER_CTX_cipher(data[5]);
  else
    v7 = 64;
  return DSA_verify(v7, tbs, tbslen, sig, siglen, (dsa_st *)ptr);
}
