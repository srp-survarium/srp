bio_st *__cdecl PKCS7_dataInit(pkcs7_st *p7, bio_st *bio)
{
  pkcs7_st *v2; // edi
  int v3; // esi
  const engine_st *v4; // ebx
  const stack_st *v5; // ebp
  int v6; // eax
  char *ptr; // eax
  pkcs7_st *v8; // esi
  char *v9; // eax
  stack_st *v10; // edx
  int v11; // eax
  asn1_object_st **v12; // ecx
  char *v14; // eax
  stack_st *v15; // edx
  int v16; // eax
  asn1_object_st **v17; // ecx
  char *v18; // eax
  asn1_string_st *octet_string; // eax
  char *v20; // eax
  bio_method_st *v21; // eax
  bio_st *v22; // eax
  bio_st *v23; // esi
  bio_st *v24; // ebp
  unsigned int v25; // eax
  asn1_object_st *v26; // eax
  asn1_object_st **v27; // esi
  asn1_type_st *v28; // eax
  stack_st *v29; // ebp
  int v30; // ebx
  char *v31; // eax
  bio_method_st *v32; // eax
  bio_st *v33; // eax
  bio_method_st *v34; // eax
  bio_st *v35; // eax
  asn1_object_st *type; // [esp-4h] [ebp-68h]
  int v37; // [esp-4h] [ebp-68h]
  bio_st *pbio; // [esp+10h] [ebp-54h] BYREF
  bio_st *v39; // [esp+14h] [ebp-50h]
  X509_algor_st *alg; // [esp+18h] [ebp-4Ch] BYREF
  bio_st *bioa; // [esp+1Ch] [ebp-48h]
  int keylen; // [esp+20h] [ebp-44h]
  asn1_object_st **v43; // [esp+24h] [ebp-40h]
  stack_st *st; // [esp+28h] [ebp-3Ch]
  asn1_string_st *v45; // [esp+2Ch] [ebp-38h]
  unsigned __int8 buf[16]; // [esp+30h] [ebp-34h] BYREF
  unsigned __int8 key[32]; // [esp+40h] [ebp-24h] BYREF

  v2 = p7;
  v3 = 0;
  type = p7->type;
  keylen = (int)p7;
  v39 = bio;
  pbio = 0;
  bioa = 0;
  alg = 0;
  v4 = 0;
  v5 = 0;
  st = 0;
  v43 = 0;
  v45 = 0;
  v6 = OBJ_obj2nid(type);
  p7->state = 0;
  switch ( v6 )
  {
    case 21:
      goto $LN54_0;
    case 22:
      ptr = p7->d.ptr;
      v5 = (const stack_st *)*((_DWORD *)ptr + 1);
      v8 = (pkcs7_st *)*((_DWORD *)ptr + 5);
      goto LABEL_10;
    case 23:
      v14 = p7->d.ptr;
      v15 = (stack_st *)*((_DWORD *)v14 + 1);
      v16 = *((_DWORD *)v14 + 2);
      v4 = *(const engine_st **)(v16 + 12);
      v17 = *(asn1_object_st ***)(v16 + 4);
      st = v15;
      v43 = v17;
      if ( v4 )
        goto $LN54_0;
      v37 = 296;
      goto LABEL_5;
    case 24:
      v9 = p7->d.ptr;
      v10 = (stack_st *)*((_DWORD *)v9 + 6);
      v5 = (const stack_st *)*((_DWORD *)v9 + 1);
      v11 = *((_DWORD *)v9 + 5);
      v4 = *(const engine_st **)(v11 + 12);
      v12 = *(asn1_object_st ***)(v11 + 4);
      st = v10;
      v43 = v12;
      if ( v4 )
        goto $LN54_0;
      v37 = 285;
LABEL_5:
      ERR_put_error(0x21u, 105, 116, ".\\crypto\\pkcs7\\pk7_doit.c", v37);
      return 0;
    case 25:
      v18 = p7->d.ptr;
      v8 = (pkcs7_st *)*((_DWORD *)v18 + 2);
      alg = (X509_algor_st *)*((_DWORD *)v18 + 1);
LABEL_10:
      octet_string = PKCS7_get_octet_string(v8);
      v3 = 0;
      v45 = octet_string;
$LN54_0:
      if ( sk_num(v5) <= 0 )
        goto LABEL_15;
      break;
    default:
      ERR_put_error(0x21u, 105, 112, ".\\crypto\\pkcs7\\pk7_doit.c", 307);
      return 0;
  }
  do
  {
    v20 = sk_value(v5, v3);
    if ( !PKCS7_bio_add_digest(&pbio, (X509_algor_st *)v20) )
      goto LABEL_21;
    ++v3;
  }
  while ( v3 < sk_num(v5) );
  v2 = (pkcs7_st *)keylen;
LABEL_15:
  if ( !alg )
  {
LABEL_18:
    if ( v4 )
    {
      v21 = BIO_f_cipher();
      v22 = BIO_new(v21);
      bioa = v22;
      if ( !v22 )
      {
        ERR_put_error(0x21u, 105, 32, ".\\crypto\\pkcs7\\pk7_doit.c", 327);
        goto LABEL_21;
      }
      BIO_ctrl(v22, 129, 0, &alg);
      keylen = (int)EC_KEY_get0_public_key(v4);
      v24 = EC_KEY_get0_private_key((const ssl_st *)v4);
      v25 = EVP_CIPHER_type((const evp_cipher_st *)v4);
      v26 = OBJ_nid2obj(v25);
      v27 = v43;
      *v43 = v26;
      if ( (int)v24 > 0 && RAND_pseudo_bytes() <= 0 )
        goto LABEL_21;
      if ( EVP_CipherInit_ex((evp_cipher_ctx_st *)alg, (const evp_cipher_st *)v4, 0, 0, 0, 1) <= 0
        || EVP_CIPHER_CTX_rand_key((evp_cipher_ctx_st *)alg, key) <= 0
        || EVP_CipherInit_ex((evp_cipher_ctx_st *)alg, 0, 0, key, buf, 1) <= 0 )
      {
        goto LABEL_21;
      }
      if ( (int)v24 > 0 )
      {
        if ( !v27[1] )
        {
          v28 = ASN1_TYPE_new();
          v27[1] = (asn1_object_st *)v28;
          if ( !v28 )
            goto LABEL_21;
        }
        if ( EVP_CIPHER_param_to_asn1((evp_cipher_ctx_st *)alg) < 0 )
          goto LABEL_21;
      }
      v29 = st;
      v30 = 0;
      if ( sk_num(st) > 0 )
      {
        do
        {
          v31 = sk_value(v29, v30);
          if ( (int)pkcs7_encode_rinfo((pkcs7_recip_info_st *)v31, key, keylen) <= 0 )
            goto LABEL_21;
        }
        while ( ++v30 < sk_num(v29) );
      }
      OPENSSL_cleanse(key, keylen);
      v23 = pbio;
      if ( pbio )
      {
        BIO_push(pbio, bioa);
      }
      else
      {
        pbio = bioa;
        v23 = bioa;
      }
      bioa = 0;
    }
    else
    {
      v23 = pbio;
    }
    if ( v39 )
    {
LABEL_54:
      if ( !v23 )
        return v39;
      BIO_push(v23, v39);
      return v23;
    }
    if ( OBJ_obj2nid(v2->type) == 22 && PKCS7_ctrl(v2, 2, 0, 0) )
    {
      v32 = BIO_s_null();
      v33 = BIO_new(v32);
    }
    else
    {
      if ( !v45 || v45->length <= 0 )
      {
LABEL_52:
        v34 = BIO_s_mem();
        v35 = BIO_new(v34);
        v39 = v35;
        if ( !v35 )
          goto err_121;
        BIO_ctrl(v35, 130, 0, 0);
        goto LABEL_54;
      }
      v33 = BIO_new_mem_buf(v45->data, v45->length);
    }
    v39 = v33;
    if ( v33 )
      goto LABEL_54;
    goto LABEL_52;
  }
  if ( PKCS7_bio_add_digest(&pbio, alg) )
  {
    v2 = (pkcs7_st *)keylen;
    goto LABEL_18;
  }
LABEL_21:
  v23 = pbio;
err_121:
  if ( v23 )
    BIO_free_all(v23);
  if ( bioa )
    BIO_free_all(bioa);
  return 0;
}
