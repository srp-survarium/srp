evp_pkey_ctx_st *__usercall cms_RecipientInfo_ktri_encrypt@<eax>(
        int a1@<ebx>,
        CMS_ContentInfo_st *cms,
        CMS_RecipientInfo_st *ri)
{
  CMS_RecipientInfo_st *v3; // ebp
  unsigned __int8 *v4; // edi
  evp_pkey_ctx_st *result; // eax
  int flags; // ebx
  evp_pkey_ctx_st *v7; // esi
  int v8; // [esp+8h] [ebp-8h]
  CMS_KeyTransRecipientInfo_st *ktri; // [esp+Ch] [ebp-4h]

  v3 = ri;
  v4 = 0;
  v8 = 0;
  if ( ri->type )
  {
    ERR_put_error(a1, 0x2Eu, 141, 124, ".\\crypto\\cms\\cms_env.c", 315);
    return 0;
  }
  else
  {
    flags = cms->d.data->flags;
    ktri = ri->d.ktri;
    result = EVP_PKEY_CTX_new(0, ktri->pkey, 0);
    v7 = result;
    if ( result )
    {
      if ( EVP_PKEY_encrypt_init(result) > 0 )
      {
        if ( EVP_PKEY_CTX_ctrl(flags, v7, -1, 256, 9, 0, v3) > 0 )
        {
          if ( EVP_PKEY_encrypt(
                 v7,
                 0,
                 (unsigned int *)&ri,
                 *(const unsigned __int8 **)(flags + 16),
                 *(_DWORD *)(flags + 20)) > 0 )
          {
            v4 = (unsigned __int8 *)CRYPTO_malloc((int)ri, ".\\crypto\\cms\\cms_env.c", 338);
            if ( v4 )
            {
              if ( EVP_PKEY_encrypt(
                     v7,
                     v4,
                     (unsigned int *)&ri,
                     *(const unsigned __int8 **)(flags + 16),
                     *(_DWORD *)(flags + 20)) > 0 )
              {
                ASN1_STRING_set0(ktri->encryptedKey, v4, (int)ri);
                v4 = 0;
                v8 = 1;
              }
            }
            else
            {
              ERR_put_error(flags, 0x2Eu, 141, 65, ".\\crypto\\cms\\cms_env.c", 343);
            }
          }
        }
        else
        {
          ERR_put_error(flags, 0x2Eu, 141, 110, ".\\crypto\\cms\\cms_env.c", 331);
        }
      }
      EVP_PKEY_CTX_free((int)v4, v7);
      if ( v4 )
        CRYPTO_free(v4);
      return (evp_pkey_ctx_st *)v8;
    }
  }
  return result;
}
