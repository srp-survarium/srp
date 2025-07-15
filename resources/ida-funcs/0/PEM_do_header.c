int __usercall PEM_do_header@<eax>(
        int a1@<ebx>,
        evp_cipher_info_st *cipher,
        __m128i *data,
        int *plen,
        int (__cdecl *callback)(char *, int, int, void *),
        __m128i *u)
{
  int v6; // ebp
  bool v7; // zf
  int v8; // eax
  const env_md_st *v10; // eax
  unsigned __int8 *v11; // edi
  int v12; // esi
  int v13; // eax
  int v14; // [esp-14h] [ebp-4DCh]
  int outl; // [esp+Ch] [ebp-4BCh] BYREF
  int v16; // [esp+10h] [ebp-4B8h] BYREF
  int *v17; // [esp+14h] [ebp-4B4h]
  evp_cipher_ctx_st ctx; // [esp+18h] [ebp-4B0h] BYREF
  unsigned __int8 key[32]; // [esp+A4h] [ebp-424h] BYREF
  unsigned __int8 dataa[1024]; // [esp+C4h] [ebp-404h] BYREF

  v6 = *plen;
  v7 = cipher->cipher == 0;
  v17 = plen;
  if ( !v7 )
  {
    if ( callback )
      v8 = callback((char *)dataa, 1024, 0, u);
    else
      v8 = PEM_def_callback((char *)dataa, 1024, 0, u);
    if ( v8 <= 0 )
    {
      ERR_put_error(a1, 9u, 106, 104, ".\\crypto\\pem\\pem_lib.c", 454);
      return 0;
    }
    v14 = v8;
    v10 = EVP_md5();
    EVP_BytesToKey(cipher->cipher, v10, cipher->iv, dataa, v14, 1u, key, 0);
    outl = v6;
    EVP_CIPHER_CTX_init(&ctx);
    EVP_DecryptInit_ex(&ctx, cipher->cipher, 0, key, (const __m128i *)cipher->iv);
    EVP_DecryptUpdate(&ctx, (unsigned __int8 *)data, &v16, data, v6);
    v11 = &data->m128i_u8[v16];
    v12 = EVP_DecryptFinal_ex((int)cipher->iv, &ctx, &data->m128i_u8[v16], &outl);
    EVP_CIPHER_CTX_cleanup((int)v11, (int)cipher->iv, &ctx);
    OPENSSL_cleanse(dataa, 1024);
    OPENSSL_cleanse(key, 32);
    v13 = v16 + outl;
    outl += v16;
    if ( !v12 )
    {
      ERR_put_error(a1, 9u, 106, 101, ".\\crypto\\pem\\pem_lib.c", 476);
      return 0;
    }
    *v17 = v13;
  }
  return 1;
}
