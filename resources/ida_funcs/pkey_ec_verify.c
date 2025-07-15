int __cdecl pkey_ec_verify(
        evp_pkey_ctx_st *ctx,
        unsigned __int8 *sig,
        unsigned int siglen,
        const unsigned __int8 *tbs,
        unsigned int tbslen)
{
  const ssl_st **data; // ecx
  char *ptr; // esi
  int v7; // eax

  data = (const ssl_st **)ctx->data;
  ptr = ctx->pkey->pkey.ptr;
  if ( data[1] )
    v7 = EVP_CIPHER_CTX_cipher(data[1]);
  else
    v7 = 64;
  return ECDSA_verify(v7, tbs, tbslen, sig, siglen, (ec_key_st *)ptr);
}
