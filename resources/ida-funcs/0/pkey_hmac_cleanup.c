void __usercall pkey_hmac_cleanup(int a1@<edi>, int a2@<ebx>, evp_pkey_ctx_st *ctx)
{
  char *data; // esi
  int v4; // ecx

  data = (char *)ctx->data;
  HMAC_CTX_cleanup(a1, a2, (hmac_ctx_st *)(data + 20));
  v4 = *((_DWORD *)data + 3);
  if ( v4 )
  {
    if ( *((_DWORD *)data + 1) )
      OPENSSL_cleanse(v4, *((_DWORD *)data + 1));
    CRYPTO_free(*((void **)data + 3));
    *((_DWORD *)data + 3) = 0;
  }
  CRYPTO_free(data);
}
