int __usercall client_certificate@<eax>(ssl_st *s@<esi>)
{
  unsigned __int8 *data; // edi
  int v2; // eax
  int init_num; // ecx
  int v5; // eax
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // ecx
  cert_st *cert; // eax
  cert_pkey_st *key; // eax
  ssl_ctx_st *v9; // eax
  x509_st *v10; // ecx
  evp_pkey_st *v11; // edx
  int (__cdecl *client_cert_cb)(ssl_st *, x509_st **, evp_pkey_st **); // eax
  int v13; // ebp
  cert_st *v14; // ecx
  unsigned __int8 *v15; // eax
  unsigned __int8 *out; // [esp+8h] [ebp-2Ch] BYREF
  evp_pkey_st *pkey; // [esp+Ch] [ebp-28h] BYREF
  unsigned int siglen; // [esp+10h] [ebp-24h] BYREF
  unsigned __int8 *sigret; // [esp+14h] [ebp-20h] BYREF
  x509_st *a; // [esp+18h] [ebp-1Ch] BYREF
  env_md_ctx_st ctx; // [esp+1Ch] [ebp-18h] BYREF

  data = (unsigned __int8 *)s->init_buf->data;
  if ( s->state == 4176 )
  {
    v2 = ssl2_read(s, &data[s->init_num], 34 - s->init_num);
    init_num = s->init_num;
    if ( v2 < 18 - init_num )
      return ssl2_part_read(s, 0x64u, v2);
    v5 = init_num + v2;
    msg_callback = s->msg_callback;
    s->init_num = v5;
    if ( msg_callback )
      msg_callback(0, s->version, 0, data, v5, s, s->msg_callback_arg);
    if ( data[1] != 1 )
    {
      ssl2_return_error(s, 6);
      ERR_put_error(0x14u, 100, 102, ".\\ssl\\s2_clnt.c", 775);
      return -1;
    }
    cert = s->cert;
    if ( cert && (key = cert->key, key->x509) && key->privatekey )
      s->state = 4178;
    else
      s->state = 4240;
  }
  if ( s->state != 4240 )
    goto LABEL_27;
  v9 = s->ctx;
  v10 = 0;
  v11 = 0;
  a = 0;
  pkey = 0;
  client_cert_cb = v9->client_cert_cb;
  v13 = 0;
  if ( client_cert_cb )
  {
    v13 = client_cert_cb(s, &a, &pkey);
    if ( v13 < 0 )
    {
      s->rwstate = 4;
      return -1;
    }
    v10 = a;
    v11 = pkey;
  }
  s->rwstate = 1;
  if ( v13 == 1 )
  {
    if ( v11 )
    {
      if ( v10 )
      {
        s->state = 4178;
        if ( !SSL_use_certificate(s, v10) || !SSL_use_PrivateKey(s, pkey) )
          v13 = 0;
        X509_free(a);
        EVP_PKEY_free(pkey);
        goto LABEL_25;
      }
    }
    else
    {
      if ( !v10 )
      {
LABEL_36:
        ERR_put_error(0x14u, 100, 106, ".\\ssl\\s2_clnt.c", 831);
        goto LABEL_26;
      }
      X509_free(v10);
      v11 = pkey;
    }
    if ( v11 )
      EVP_PKEY_free(v11);
    goto LABEL_36;
  }
LABEL_25:
  if ( !v13 )
  {
LABEL_26:
    out = data;
    s->state = 4177;
    *data = 0;
    *++out = 0;
    out[1] = 2;
    out += 2;
    s->init_off = 0;
    s->init_num = 3;
  }
LABEL_27:
  if ( s->state == 4178 )
  {
    out = data;
    EVP_MD_CTX_init(&ctx);
    EVP_DigestInit_ex(&ctx, s->ctx->rsa_md5, 0);
    EVP_DigestUpdate(&ctx);
    EVP_DigestUpdate(&ctx);
    if ( i2d_X509(s->session->sess_cert->peer_key->x509, &out) > 0 )
      EVP_DigestUpdate(&ctx);
    out = data;
    sigret = data + 6;
    *data = 8;
    *++out = 1;
    ++out;
    siglen = i2d_X509(s->cert->key->x509, &sigret);
    *out = BYTE1(siglen);
    out[1] = siglen;
    v14 = s->cert;
    out += 2;
    EVP_SignFinal(&ctx, sigret, &siglen, v14->key->privatekey);
    EVP_MD_CTX_cleanup((unsigned int)data, &ctx);
    *out = BYTE1(siglen);
    out[1] = siglen;
    out += 2;
    sigret += siglen;
    v15 = (unsigned __int8 *)(sigret - data);
    s->state = 4179;
    s->init_num = (int)v15;
    s->init_off = 0;
  }
  return ssl2_do_write(s);
}
