bio_st *__cdecl cms_EnvelopedData_init_bio(CMS_ContentInfo_st *cms)
{
  CMS_EncryptedContentInfo_st *flags; // ebp
  int v3; // esi
  bio_st *result; // eax
  unsigned __int8 *data; // edi
  CMS_RecipientInfo_st *v6; // eax
  evp_pkey_ctx_st *v7; // eax
  unsigned __int8 *key; // eax
  int v9; // [esp+Ch] [ebp-4h]
  bio_st *cmsa; // [esp+14h] [ebp+4h]

  flags = (CMS_EncryptedContentInfo_st *)cms->d.data->flags;
  v3 = 0;
  v9 = 0;
  result = cms_EncryptedContent_init_bio(flags);
  cmsa = result;
  if ( result && flags->cipher )
  {
    data = cms->d.data->data;
    if ( sk_num((const stack_st *)data) <= 0 )
    {
LABEL_10:
      v9 = 1;
    }
    else
    {
      while ( 1 )
      {
        v6 = (CMS_RecipientInfo_st *)sk_value((const stack_st *)data, v3);
        if ( v6->type )
        {
          if ( v6->type != 2 )
          {
            ERR_put_error(0x2Eu, 125, 154, ".\\crypto\\cms\\cms_env.c", 834);
            goto err_146;
          }
          v7 = (evp_pkey_ctx_st *)cms_RecipientInfo_kekri_encrypt(v6, cms);
        }
        else
        {
          v7 = cms_RecipientInfo_ktri_encrypt(cms, v6);
        }
        if ( (int)v7 <= 0 )
          break;
        if ( ++v3 >= sk_num((const stack_st *)data) )
          goto LABEL_10;
      }
      ERR_put_error(0x2Eu, 125, 116, ".\\crypto\\cms\\cms_env.c", 841);
    }
err_146:
    key = flags->key;
    flags->cipher = 0;
    if ( key )
    {
      OPENSSL_cleanse(key, flags->keylen);
      CRYPTO_free(flags->key);
      flags->key = 0;
      flags->keylen = 0;
    }
    if ( v9 )
    {
      return cmsa;
    }
    else
    {
      BIO_free((unsigned int)data, cmsa);
      return 0;
    }
  }
  return result;
}
