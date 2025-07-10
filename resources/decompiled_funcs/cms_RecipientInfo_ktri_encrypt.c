evp_pkey_ctx_st *__cdecl cms_RecipientInfo_ktri_encrypt(CMS_ContentInfo_st *cms, CMS_RecipientInfo_st *ri)
{
  CMS_RecipientInfo_st *v2; // ebp
  unsigned __int8 *v3; // edi
  evp_pkey_ctx_st *result; // eax
  int flags; // ebx
  evp_pkey_ctx_st *v6; // esi
  int v7; // [esp+8h] [ebp-8h]
  CMS_KeyTransRecipientInfo_st *ktri; // [esp+Ch] [ebp-4h]

  v2 = ri;
  v3 = 0;
  v7 = 0;
  if ( ri->type )
  {
    ERR_put_error(0x2Eu, 141, 124, ".\\crypto\\cms\\cms_env.c", 315);
    return 0;
  }
  else
  {
    flags = cms->d.data->flags;
    ktri = ri->d.ktri;
    result = EVP_PKEY_CTX_new(ktri->pkey, 0);
    v6 = result;
    if ( result )
    {
      if ( EVP_PKEY_encrypt_init(result) > 0 )
      {
        if ( EVP_PKEY_CTX_ctrl(v6, -1, 256, 9, 0, v2) > 0 )
        {
          if ( EVP_PKEY_encrypt(
                 v6,
                 0,
                 (unsigned int *)&ri,
                 *(const unsigned __int8 **)(flags + 16),
                 *(_DWORD *)(flags + 20)) > 0 )
          {
            v3 = (unsigned __int8 *)CRYPTO_malloc((int)ri, ".\\crypto\\cms\\cms_env.c", 338);
            if ( v3 )
            {
              if ( EVP_PKEY_encrypt(
                     v6,
                     v3,
                     (unsigned int *)&ri,
                     *(const unsigned __int8 **)(flags + 16),
                     *(_DWORD *)(flags + 20)) > 0 )
              {
                ASN1_STRING_set0(ktri->encryptedKey, v3, (int)ri);
                v3 = 0;
                v7 = 1;
              }
            }
            else
            {
              ERR_put_error(0x2Eu, 141, 65, ".\\crypto\\cms\\cms_env.c", 343);
            }
          }
        }
        else
        {
          ERR_put_error(0x2Eu, 141, 110, ".\\crypto\\cms\\cms_env.c", 331);
        }
      }
      EVP_PKEY_CTX_free(v6);
      if ( v3 )
        CRYPTO_free(v3);
      return (evp_pkey_ctx_st *)v7;
    }
  }
  return result;
}
