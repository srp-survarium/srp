void __usercall pkey_hmac_cleanup(unsigned int a1@<edi>, evp_pkey_ctx_st *ctx)
{
  char *data; // esi
  int v3; // ecx

  data = (char *)ctx->data;
  HMAC_CTX_cleanup(a1, (hmac_ctx_st *)(data + 20));
  v3 = *((_DWORD *)data + 3);
  if ( v3 )
  {
    if ( *((_DWORD *)data + 1) )
      OPENSSL_cleanse(v3, *((_DWORD *)data + 1));
    CRYPTO_free(*((void **)data + 3));
    *((_DWORD *)data + 3) = 0;
  }
  CRYPTO_free(data);
}
