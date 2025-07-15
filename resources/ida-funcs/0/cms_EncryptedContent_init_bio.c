bio_st *__usercall cms_EncryptedContent_init_bio@<eax>(int a1@<ebx>, CMS_EncryptedContentInfo_st *ec)
{
  X509_algor_st *contentEncryptionAlgorithm; // ebp
  BOOL v3; // ecx
  const __m128i *v4; // edi
  bio_method_st *v5; // eax
  bio_st *v6; // eax
  bio_st *v7; // ebx
  const evp_cipher_st *cipher; // eax
  void *v10; // eax
  char *v11; // eax
  const evp_cipher_st *v12; // eax
  unsigned int v13; // eax
  unsigned __int8 *v14; // eax
  unsigned int keylen; // ebx
  asn1_type_st *v16; // eax
  unsigned __int8 *key; // eax
  int v18; // [esp-4h] [ebp-3Ch]
  evp_cipher_ctx_st *parg; // [esp+10h] [ebp-28h] BYREF
  const __m128i *v20; // [esp+14h] [ebp-24h]
  int v21; // [esp+18h] [ebp-20h]
  int v22; // [esp+1Ch] [ebp-1Ch]
  bio_st *v23; // [esp+20h] [ebp-18h]
  char v24; // [esp+24h] [ebp-14h] BYREF

  contentEncryptionAlgorithm = ec->contentEncryptionAlgorithm;
  v3 = ec->cipher != 0;
  v20 = 0;
  v22 = 0;
  v21 = 0;
  v4 = (const __m128i *)v3;
  v5 = BIO_f_cipher();
  v6 = BIO_new(a1, v5);
  v7 = v6;
  v23 = v6;
  if ( !v6 )
  {
    ERR_put_error(0, 0x2Eu, 120, 65, ".\\crypto\\cms\\cms_enc.c", 87);
    return 0;
  }
  BIO_ctrl((int)v6, v6, 129, 0, &parg);
  if ( v4 )
  {
    cipher = ec->cipher;
    if ( ec->key )
      ec->cipher = 0;
  }
  else
  {
    v10 = OBJ_obj2nid(contentEncryptionAlgorithm->algorithm);
    v11 = (char *)OBJ_nid2sn((int)v7, (unsigned int)v10);
    cipher = EVP_get_cipherbyname(v11);
    if ( !cipher )
    {
      ERR_put_error((int)v7, 0x2Eu, 120, 148, ".\\crypto\\cms\\cms_enc.c", 109);
      goto err_192;
    }
  }
  if ( EVP_CipherInit_ex(parg, cipher, 0, 0, 0, (int)v4) <= 0 )
  {
    ERR_put_error((int)v7, 0x2Eu, 120, 101, ".\\crypto\\cms\\cms_enc.c", 117);
    goto err_192;
  }
  if ( !v4 )
  {
    if ( EVP_CIPHER_asn1_to_param(parg) <= 0 )
    {
      ERR_put_error((int)v7, 0x2Eu, 120, 102, ".\\crypto\\cms\\cms_enc.c", 137);
      goto err_192;
    }
    goto LABEL_24;
  }
  v12 = (const evp_cipher_st *)EVP_CIPHER_CTX_cipher((const ssl_st *)parg);
  v13 = EVP_CIPHER_type((int)v7, v12);
  contentEncryptionAlgorithm->algorithm = OBJ_nid2obj((int)v7, v13);
  if ( (int)X509_get_issuer_name((x509_st *)parg) > 0 )
  {
    if ( RAND_pseudo_bytes((int)v4) <= 0 )
      goto err_192;
    v20 = (const __m128i *)&v24;
  }
  if ( ec->key )
  {
LABEL_24:
    keylen = ec->keylen;
    if ( keylen != EVP_CIPHER_CTX_key_length(parg) && EVP_CIPHER_CTX_set_key_length(keylen, parg, keylen) <= 0 )
    {
      ERR_put_error(keylen, 0x2Eu, 120, 118, ".\\crypto\\cms\\cms_enc.c", 164);
      v7 = v23;
      goto err_192;
    }
    v7 = v23;
    goto LABEL_28;
  }
  if ( !ec->keylen )
    ec->keylen = EVP_CIPHER_CTX_key_length(parg);
  v14 = (unsigned __int8 *)CRYPTO_malloc(ec->keylen, ".\\crypto\\cms\\cms_enc.c", 147);
  ec->key = v14;
  if ( !v14 )
  {
    ERR_put_error((int)v7, 0x2Eu, 120, 65, ".\\crypto\\cms\\cms_enc.c", 151);
    goto err_192;
  }
  if ( EVP_CIPHER_CTX_rand_key((int)v7, (int)v4, parg, v14) <= 0 )
    goto err_192;
  v21 = 1;
LABEL_28:
  v18 = (int)v4;
  v4 = v20;
  if ( EVP_CipherInit_ex(parg, 0, 0, ec->key, v20, v18) <= 0 )
  {
    ERR_put_error((int)v7, 0x2Eu, 120, 101, ".\\crypto\\cms\\cms_enc.c", 172);
    goto err_192;
  }
  if ( !v4 )
    goto LABEL_35;
  v16 = ASN1_TYPE_new();
  contentEncryptionAlgorithm->parameter = v16;
  if ( !v16 )
  {
    ERR_put_error((int)v7, 0x2Eu, 120, 65, ".\\crypto\\cms\\cms_enc.c", 182);
    goto err_192;
  }
  if ( EVP_CIPHER_param_to_asn1(parg) <= 0 )
    ERR_put_error((int)v7, 0x2Eu, 120, 102, ".\\crypto\\cms\\cms_enc.c", 188);
  else
LABEL_35:
    v22 = 1;
err_192:
  key = ec->key;
  if ( key && !v21 )
  {
    OPENSSL_cleanse(key, ec->keylen);
    CRYPTO_free(ec->key);
    ec->key = 0;
  }
  if ( v22 )
    return v7;
  BIO_free((int)v4, (int)v7, v7);
  return 0;
}
