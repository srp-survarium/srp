bio_st *__cdecl cms_EncryptedContent_init_bio(CMS_EncryptedContentInfo_st *ec)
{
  X509_algor_st *contentEncryptionAlgorithm; // ebp
  BOOL v2; // ecx
  unsigned __int8 *v3; // edi
  bio_method_st *v4; // eax
  bio_st *v5; // eax
  bio_st *v6; // ebx
  const evp_cipher_st *cipher; // eax
  unsigned int v9; // eax
  const char *v10; // eax
  const evp_cipher_st *v11; // eax
  unsigned int v12; // eax
  unsigned __int8 *v13; // eax
  unsigned int keylen; // ebx
  asn1_type_st *v15; // eax
  unsigned __int8 *key; // eax
  int v17; // [esp-4h] [ebp-3Ch]
  evp_cipher_ctx_st *parg; // [esp+10h] [ebp-28h] BYREF
  unsigned __int8 *iv; // [esp+14h] [ebp-24h]
  int v20; // [esp+18h] [ebp-20h]
  int v21; // [esp+1Ch] [ebp-1Ch]
  bio_st *v22; // [esp+20h] [ebp-18h]
  unsigned __int8 buf; // [esp+24h] [ebp-14h] BYREF

  contentEncryptionAlgorithm = ec->contentEncryptionAlgorithm;
  v2 = ec->cipher != 0;
  iv = 0;
  v21 = 0;
  v20 = 0;
  v3 = (unsigned __int8 *)v2;
  v4 = BIO_f_cipher();
  v5 = BIO_new(v4);
  v6 = v5;
  v22 = v5;
  if ( !v5 )
  {
    ERR_put_error(0x2Eu, 120, 65, ".\\crypto\\cms\\cms_enc.c", 87);
    return 0;
  }
  BIO_ctrl(v5, 129, 0, &parg);
  if ( v3 )
  {
    cipher = ec->cipher;
    if ( ec->key )
      ec->cipher = 0;
  }
  else
  {
    v9 = OBJ_obj2nid(contentEncryptionAlgorithm->algorithm);
    v10 = OBJ_nid2sn(v9);
    cipher = EVP_get_cipherbyname(v10);
    if ( !cipher )
    {
      ERR_put_error(0x2Eu, 120, 148, ".\\crypto\\cms\\cms_enc.c", 109);
      goto err_190;
    }
  }
  if ( EVP_CipherInit_ex(parg, cipher, 0, 0, 0, (int)v3) <= 0 )
  {
    ERR_put_error(0x2Eu, 120, 101, ".\\crypto\\cms\\cms_enc.c", 117);
    goto err_190;
  }
  if ( !v3 )
  {
    if ( EVP_CIPHER_asn1_to_param(parg) <= 0 )
    {
      ERR_put_error(0x2Eu, 120, 102, ".\\crypto\\cms\\cms_enc.c", 137);
      goto err_190;
    }
    goto LABEL_24;
  }
  v11 = (const evp_cipher_st *)EVP_CIPHER_CTX_cipher((const ssl_st *)parg);
  v12 = EVP_CIPHER_type(v11);
  contentEncryptionAlgorithm->algorithm = OBJ_nid2obj(v12);
  if ( (int)X509_get_issuer_name((x509_st *)parg) > 0 )
  {
    if ( RAND_pseudo_bytes() <= 0 )
      goto err_190;
    iv = &buf;
  }
  if ( ec->key )
  {
LABEL_24:
    keylen = ec->keylen;
    if ( keylen != EVP_CIPHER_CTX_key_length(parg) && EVP_CIPHER_CTX_set_key_length(parg, keylen) <= 0 )
    {
      ERR_put_error(0x2Eu, 120, 118, ".\\crypto\\cms\\cms_enc.c", 164);
      v6 = v22;
      goto err_190;
    }
    v6 = v22;
    goto LABEL_28;
  }
  if ( !ec->keylen )
    ec->keylen = EVP_CIPHER_CTX_key_length(parg);
  v13 = (unsigned __int8 *)CRYPTO_malloc(ec->keylen, ".\\crypto\\cms\\cms_enc.c", 147);
  ec->key = v13;
  if ( !v13 )
  {
    ERR_put_error(0x2Eu, 120, 65, ".\\crypto\\cms\\cms_enc.c", 151);
    goto err_190;
  }
  if ( EVP_CIPHER_CTX_rand_key(parg, v13) <= 0 )
    goto err_190;
  v20 = 1;
LABEL_28:
  v17 = (int)v3;
  v3 = iv;
  if ( EVP_CipherInit_ex(parg, 0, 0, ec->key, iv, v17) <= 0 )
  {
    ERR_put_error(0x2Eu, 120, 101, ".\\crypto\\cms\\cms_enc.c", 172);
    goto err_190;
  }
  if ( !v3 )
    goto LABEL_35;
  v15 = ASN1_TYPE_new();
  contentEncryptionAlgorithm->parameter = v15;
  if ( !v15 )
  {
    ERR_put_error(0x2Eu, 120, 65, ".\\crypto\\cms\\cms_enc.c", 182);
    goto err_190;
  }
  if ( EVP_CIPHER_param_to_asn1(parg) <= 0 )
    ERR_put_error(0x2Eu, 120, 102, ".\\crypto\\cms\\cms_enc.c", 188);
  else
LABEL_35:
    v21 = 1;
err_190:
  key = ec->key;
  if ( key && !v20 )
  {
    OPENSSL_cleanse(key, ec->keylen);
    CRYPTO_free(ec->key);
    ec->key = 0;
  }
  if ( v21 )
    return v6;
  BIO_free((unsigned int)v3, v6);
  return 0;
}
