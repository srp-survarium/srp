stack_st_X509_INFO *__cdecl PEM_X509_INFO_read_bio(
        bio_st *bp,
        stack_st_X509_INFO *sk,
        int (__cdecl *cb)(char *, int, int, void *),
        void *u)
{
  X509_info_st *v4; // edi
  char *v5; // ebp
  private_key_st *v6; // eax
  evp_pkey_st **p_crl; // esi
  char *v8; // edx
  char *v9; // eax
  private_key_st *v10; // eax
  private_key_st *v11; // eax
  stack_st *v12; // edi
  int i; // esi
  char *v14; // eax
  stack_st *v15; // esi
  char *name; // [esp+10h] [ebp-50h] BYREF
  char *header; // [esp+14h] [ebp-4Ch] BYREF
  stack_st *st; // [esp+18h] [ebp-48h]
  unsigned __int8 *data; // [esp+1Ch] [ebp-44h] BYREF
  int (__cdecl *v21)(evp_pkey_st **, unsigned __int8 **, int); // [esp+20h] [ebp-40h]
  int len; // [esp+24h] [ebp-3Ch] BYREF
  int v23; // [esp+28h] [ebp-38h]
  int v24; // [esp+2Ch] [ebp-34h]
  int v25; // [esp+30h] [ebp-30h]
  bio_st *v26; // [esp+34h] [ebp-2Ch]
  unsigned __int8 *v27; // [esp+38h] [ebp-28h] BYREF
  void *ua; // [esp+3Ch] [ebp-24h]
  stack_st_X509_INFO *v29; // [esp+40h] [ebp-20h]
  int (__cdecl *callback)(char *, int, int, void *); // [esp+44h] [ebp-1Ch]
  evp_cipher_info_st cipher; // [esp+48h] [ebp-18h] BYREF

  v26 = bp;
  v29 = sk;
  callback = cb;
  ua = u;
  name = 0;
  header = 0;
  data = 0;
  v25 = 0;
  v21 = 0;
  if ( sk )
  {
    st = &sk->stack;
  }
  else
  {
    st = sk_new_null();
    if ( !st )
    {
      ERR_put_error(0, 9u, 116, 65, ".\\crypto\\pem\\pem_info.c", 108);
      goto LABEL_47;
    }
  }
  v4 = X509_INFO_new(0);
  if ( !v4 )
    goto LABEL_47;
  v24 = 0;
  v23 = 0;
  if ( PEM_read_bio(v26, &name, &header, &data, &len) )
  {
    while ( 1 )
    {
      v5 = name;
      if ( !strcmp(name, "CERTIFICATE") || !strcmp(name, "X509 CERTIFICATE") )
        break;
      if ( !strcmp(name, "TRUSTED CERTIFICATE") )
      {
        v21 = (int (__cdecl *)(evp_pkey_st **, unsigned __int8 **, int))d2i_X509_AUX;
        if ( !v4->x509 )
          goto LABEL_27;
LABEL_11:
        if ( !sk_push(st, (char *)v4) )
          goto err_254;
        v4 = X509_INFO_new(0);
        if ( !v4 )
          goto LABEL_47;
      }
      else
      {
        if ( !strcmp(name, "X509 CRL") )
        {
          v21 = (int (__cdecl *)(evp_pkey_st **, unsigned __int8 **, int))d2i_X509_CRL;
          if ( v4->crl )
            goto LABEL_11;
          p_crl = (evp_pkey_st **)&v4->crl;
        }
        else
        {
          if ( !strcmp(name, "RSA PRIVATE KEY") )
          {
            if ( v4->x_pkey )
              goto LABEL_11;
            v4->enc_data = 0;
            v4->enc_len = 0;
            v10 = X509_PKEY_new();
            v4->x_pkey = v10;
            p_crl = &v10->dec_pkey;
            v23 = 6;
            v8 = header + 1;
            v9 = &header[strlen(header) + 1];
          }
          else if ( !strcmp(name, "DSA PRIVATE KEY") )
          {
            v21 = (int (__cdecl *)(evp_pkey_st **, unsigned __int8 **, int))d2i_DSAPrivateKey;
            if ( v4->x_pkey )
              goto LABEL_11;
            v4->enc_data = 0;
            v4->enc_len = 0;
            v6 = X509_PKEY_new();
            v4->x_pkey = v6;
            p_crl = &v6->dec_pkey;
            v23 = 116;
            v8 = header + 1;
            v9 = &header[strlen(header) + 1];
          }
          else
          {
            if ( strcmp(name, "EC PRIVATE KEY") )
            {
              v21 = 0;
              goto LABEL_55;
            }
            v21 = (int (__cdecl *)(evp_pkey_st **, unsigned __int8 **, int))d2i_ECPrivateKey;
            if ( v4->x_pkey )
              goto LABEL_11;
            v4->enc_data = 0;
            v4->enc_len = 0;
            v11 = X509_PKEY_new();
            v4->x_pkey = v11;
            p_crl = &v11->dec_pkey;
            v23 = 408;
            v8 = header + 1;
            v9 = &header[strlen(header) + 1];
          }
          if ( v9 - v8 > 10 )
            v24 = 1;
          v5 = name;
        }
LABEL_33:
        if ( v21 )
        {
          if ( v24 )
          {
            if ( !PEM_get_EVP_CIPHER_INFO(0, header, &v4->enc_cipher) )
              goto err_254;
            v4->enc_data = (char *)data;
            v4->enc_len = len;
            data = 0;
          }
          else
          {
            if ( !PEM_get_EVP_CIPHER_INFO(0, header, &cipher)
              || !PEM_do_header(0, &cipher, (__m128i *)data, &len, callback, (__m128i *)ua) )
            {
              goto err_254;
            }
            v27 = data;
            if ( v23 )
            {
              if ( !d2i_PrivateKey(
                      (pkcs8_priv_key_info_st *)v4,
                      0,
                      (void *)v23,
                      p_crl,
                      &v27,
                      (const unsigned __int8 **)len) )
              {
                ERR_put_error(0, 9u, 116, 13, ".\\crypto\\pem\\pem_info.c", 252);
                goto err_254;
              }
            }
            else if ( !v21(p_crl, &v27, len) )
            {
              ERR_put_error(0, 9u, 116, 13, ".\\crypto\\pem\\pem_info.c", 258);
              goto err_254;
            }
          }
          v5 = name;
        }
LABEL_55:
        if ( v5 )
          CRYPTO_free(v5);
        if ( header )
          CRYPTO_free(header);
        if ( data )
          CRYPTO_free(data);
        name = 0;
        header = 0;
        data = 0;
        v24 = 0;
        v23 = 0;
        if ( !PEM_read_bio(v26, &name, &header, &data, &len) )
          goto LABEL_62;
      }
    }
    v21 = (int (__cdecl *)(evp_pkey_st **, unsigned __int8 **, int))d2i_X509;
    if ( v4->x509 )
      goto LABEL_11;
LABEL_27:
    p_crl = (evp_pkey_st **)v4;
    goto LABEL_33;
  }
LABEL_62:
  if ( (ERR_peek_last_error() & 0xFFF) == 0x6C )
  {
    ERR_clear_error(0);
    if ( v4->x509 || v4->crl || v4->x_pkey || v4->enc_data )
    {
      if ( !sk_push(st, (char *)v4) )
        goto err_254;
      v4 = 0;
    }
    v25 = 1;
  }
err_254:
  if ( v4 )
    X509_INFO_free(v4);
  if ( v25 )
  {
    v15 = st;
    goto LABEL_71;
  }
LABEL_47:
  v12 = st;
  for ( i = 0; i < sk_num(v12); ++i )
  {
    v14 = sk_value(v12, i);
    X509_INFO_free((X509_info_st *)v14);
  }
  if ( v12 != (stack_st *)v29 )
    sk_free(v12);
  v15 = 0;
LABEL_71:
  if ( name )
    CRYPTO_free(name);
  if ( header )
    CRYPTO_free(header);
  if ( data )
    CRYPTO_free(data);
  return (stack_st_X509_INFO *)v15;
}
