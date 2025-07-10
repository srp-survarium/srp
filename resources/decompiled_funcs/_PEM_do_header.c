int __cdecl PEM_do_header(
        evp_cipher_info_st *cipher,
        unsigned __int8 *data,
        int *plen,
        int (__cdecl *callback)(char *, int, int, void *),
        void *u)
{
  int v5; // ebp
  bool v6; // zf
  int v7; // eax
  const env_md_st *v9; // eax
  unsigned __int8 *v10; // edi
  int v11; // esi
  int v12; // eax
  int v13; // [esp-14h] [ebp-4DCh]
  int inl; // [esp+Ch] [ebp-4BCh] BYREF
  int outl; // [esp+10h] [ebp-4B8h] BYREF
  int *v16; // [esp+14h] [ebp-4B4h]
  evp_cipher_ctx_st ctx; // [esp+18h] [ebp-4B0h] BYREF
  unsigned __int8 v18[32]; // [esp+A4h] [ebp-424h] BYREF
  char buf[1024]; // [esp+C4h] [ebp-404h] BYREF

  v5 = *plen;
  v6 = cipher->cipher == 0;
  v16 = plen;
  if ( !v6 )
  {
    if ( callback )
      v7 = callback(buf, 1024, 0, u);
    else
      v7 = PEM_def_callback(buf, 1024, 0, (char *)u);
    if ( v7 <= 0 )
    {
      ERR_put_error(9u, 106, 104, ".\\crypto\\pem\\pem_lib.c", 454);
      return 0;
    }
    v13 = v7;
    v9 = EVP_md5();
    EVP_BytesToKey(cipher->cipher, v9, cipher->iv, (const unsigned __int8 *)buf, v13, 1, v18, 0);
    inl = v5;
    EVP_CIPHER_CTX_init(&ctx);
    EVP_DecryptInit_ex(&ctx, cipher->cipher, 0, v18, cipher->iv);
    EVP_DecryptUpdate(&ctx, data, &outl, data, v5);
    v10 = &data[outl];
    v11 = EVP_DecryptFinal_ex(&ctx, &data[outl], &inl);
    EVP_CIPHER_CTX_cleanup((unsigned int)v10, &ctx);
    OPENSSL_cleanse(buf, 1024);
    OPENSSL_cleanse(v18, 32);
    v12 = outl + inl;
    inl += outl;
    if ( !v11 )
    {
      ERR_put_error(9u, 106, 101, ".\\crypto\\pem\\pem_lib.c", 476);
      return 0;
    }
    *v16 = v12;
  }
  return 1;
}
