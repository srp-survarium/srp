evp_pkey_ctx_st *__usercall pkcs7_encode_rinfo@<eax>(
        int a1@<edi>,
        pkcs7_recip_info_st *ri,
        unsigned __int8 *key,
        unsigned int keylen)
{
  pkcs7_recip_info_st *v4; // ebp
  unsigned __int8 *v5; // esi
  evp_pkey_st *pubkey; // eax
  evp_pkey_st *v7; // ebx
  evp_pkey_ctx_st *result; // eax
  evp_pkey_ctx_st *v9; // edi
  int v10; // [esp+Ch] [ebp-4h]

  v4 = ri;
  v5 = 0;
  v10 = 0;
  pubkey = X509_get_pubkey(ri->cert);
  v7 = pubkey;
  if ( !pubkey )
    return 0;
  result = EVP_PKEY_CTX_new(a1, pubkey, 0);
  v9 = result;
  if ( result )
  {
    if ( EVP_PKEY_encrypt_init(result) > 0 )
    {
      if ( EVP_PKEY_CTX_ctrl((int)v7, v9, -1, 256, 3, 0, v4) > 0 )
      {
        if ( EVP_PKEY_encrypt(v9, 0, (unsigned int *)&ri, key, keylen) > 0 )
        {
          v5 = (unsigned __int8 *)CRYPTO_malloc((int)ri, ".\\crypto\\pkcs7\\pk7_doit.c", 172);
          if ( v5 )
          {
            if ( EVP_PKEY_encrypt(v9, v5, (unsigned int *)&ri, key, keylen) > 0 )
            {
              ASN1_STRING_set0(v4->enc_key, v5, (int)ri);
              v5 = 0;
              v10 = 1;
            }
          }
          else
          {
            ERR_put_error((int)v7, 0x21u, 132, 65, ".\\crypto\\pkcs7\\pk7_doit.c", 176);
          }
        }
      }
      else
      {
        ERR_put_error((int)v7, 0x21u, 132, 152, ".\\crypto\\pkcs7\\pk7_doit.c", 165);
      }
    }
    EVP_PKEY_free((int)v9, v7);
    EVP_PKEY_CTX_free((int)v9, v9);
    if ( v5 )
      CRYPTO_free(v5);
    return (evp_pkey_ctx_st *)v10;
  }
  return result;
}
