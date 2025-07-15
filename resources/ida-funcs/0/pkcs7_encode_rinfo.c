evp_pkey_ctx_st *__cdecl pkcs7_encode_rinfo(pkcs7_recip_info_st *ri, unsigned __int8 *key, unsigned int keylen)
{
  pkcs7_recip_info_st *v3; // ebp
  unsigned __int8 *v4; // esi
  evp_pkey_st *pubkey; // eax
  evp_pkey_st *v6; // ebx
  evp_pkey_ctx_st *result; // eax
  evp_pkey_ctx_st *v8; // edi
  int v9; // [esp+Ch] [ebp-4h]

  v3 = ri;
  v4 = 0;
  v9 = 0;
  pubkey = X509_get_pubkey(ri->cert);
  v6 = pubkey;
  if ( !pubkey )
    return 0;
  result = EVP_PKEY_CTX_new(pubkey, 0);
  v8 = result;
  if ( result )
  {
    if ( EVP_PKEY_encrypt_init(result) > 0 )
    {
      if ( EVP_PKEY_CTX_ctrl(v8, -1, 256, 3, 0, v3) > 0 )
      {
        if ( EVP_PKEY_encrypt(v8, 0, (unsigned int *)&ri, key, keylen) > 0 )
        {
          v4 = (unsigned __int8 *)CRYPTO_malloc((int)ri, ".\\crypto\\pkcs7\\pk7_doit.c", 172);
          if ( v4 )
          {
            if ( EVP_PKEY_encrypt(v8, v4, (unsigned int *)&ri, key, keylen) > 0 )
            {
              ASN1_STRING_set0(v3->enc_key, v4, (int)ri);
              v4 = 0;
              v9 = 1;
            }
          }
          else
          {
            ERR_put_error(0x21u, 132, 65, ".\\crypto\\pkcs7\\pk7_doit.c", 176);
          }
        }
      }
      else
      {
        ERR_put_error(0x21u, 132, 152, ".\\crypto\\pkcs7\\pk7_doit.c", 165);
      }
    }
    EVP_PKEY_free(v6);
    EVP_PKEY_CTX_free(v8);
    if ( v4 )
      CRYPTO_free(v4);
    return (evp_pkey_ctx_st *)v9;
  }
  return result;
}
