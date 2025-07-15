int __usercall cms_RecipientInfo_kekri_encrypt@<eax>(CMS_RecipientInfo_st *ri@<edx>, CMS_ContentInfo_st *cms)
{
  CMS_KeyTransRecipientInfo_st *ktri; // ebx
  x509_st *recip; // eax
  int v4; // ebp
  int flags; // edi
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // esi
  int v9; // eax
  aes_key_st key; // [esp+Ch] [ebp-F4h] BYREF

  ktri = ri->d.ktri;
  recip = ktri->recip;
  v4 = 0;
  flags = cms->d.data->flags;
  if ( !recip )
  {
    ERR_put_error(0x2Eu, 136, 130, ".\\crypto\\cms\\cms_env.c", 656);
    return 0;
  }
  if ( !AES_set_encrypt_key(recip, 8 * (int)ktri->pkey, &key) )
  {
    v7 = (unsigned __int8 *)CRYPTO_malloc(*(_DWORD *)(flags + 20) + 8, ".\\crypto\\cms\\cms_env.c", 667);
    v8 = v7;
    if ( v7 )
    {
      v9 = AES_wrap_key(&key, 0, v7, *(const unsigned __int8 **)(flags + 16), *(_DWORD *)(flags + 20));
      if ( v9 > 0 )
      {
        ASN1_STRING_set0(ktri->encryptedKey, v8, v9);
        v4 = 1;
        goto LABEL_9;
      }
      ERR_put_error(0x2Eu, 136, 159, ".\\crypto\\cms\\cms_env.c", 680);
    }
    else
    {
      ERR_put_error(0x2Eu, 136, 65, ".\\crypto\\cms\\cms_env.c", 672);
    }
    if ( v8 )
      CRYPTO_free(v8);
    goto LABEL_9;
  }
  ERR_put_error(0x2Eu, 136, 115, ".\\crypto\\cms\\cms_env.c", 663);
LABEL_9:
  OPENSSL_cleanse(&key, 244);
  return v4;
}
