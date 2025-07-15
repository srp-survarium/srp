void __cdecl pkey_rsa_cleanup(evp_pkey_ctx_st *ctx)
{
  void *data; // esi

  data = ctx->data;
  if ( data )
  {
    if ( *((_DWORD *)data + 1) )
      BN_free(*((bignum_st **)data + 1));
    if ( *((_DWORD *)data + 7) )
      CRYPTO_free(*((void **)data + 7));
    CRYPTO_free(data);
  }
}
