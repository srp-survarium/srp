int __cdecl enc_new(bio_st *bi)
{
  char *v1; // esi
  int result; // eax

  v1 = (char *)CRYPTO_malloc(4324, ".\\crypto\\evp\\bio_enc.c", 112);
  if ( !v1 )
    return 0;
  EVP_CIPHER_CTX_init((evp_cipher_ctx_st *)(v1 + 20));
  *(_DWORD *)v1 = 0;
  *((_DWORD *)v1 + 1) = 0;
  *((_DWORD *)v1 + 3) = 0;
  result = 1;
  *((_DWORD *)v1 + 2) = 1;
  *((_DWORD *)v1 + 4) = 1;
  bi->init = 0;
  bi->flags = 0;
  bi->ptr = v1;
  return result;
}
