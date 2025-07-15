int __usercall client_certificate@<eax>(ssl_st *s@<esi>, int a2@<ebx>)
{
  unsigned __int8 *data; // edi
  int v3; // eax
  int init_num; // ecx
  int v6; // eax
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // ecx
  cert_st *cert; // eax
  cert_pkey_st *key; // eax
  engine_st *v10; // ebx
  ssl_ctx_st *v11; // eax
  x509_st *v12; // ecx
  evp_pkey_st *v13; // edx
  int (__cdecl *client_cert_cb)(ssl_st *, x509_st **, evp_pkey_st **); // eax
  int v15; // ebp
  cert_st *v16; // ecx
  unsigned __int8 *v17; // eax
  unsigned __int8 *out; // [esp+8h] [ebp-2Ch] BYREF
  evp_pkey_st *pkey; // [esp+Ch] [ebp-28h] BYREF
  unsigned int siglen; // [esp+10h] [ebp-24h] BYREF
  unsigned __int8 *sigret; // [esp+14h] [ebp-20h] BYREF
  x509_st *a; // [esp+18h] [ebp-1Ch] BYREF
  env_md_ctx_st ctx; // [esp+1Ch] [ebp-18h] BYREF

  data = (unsigned __int8 *)s->init_buf->data;
  if ( s->state == 4176 )
  {
    v3 = ssl2_read(s, &data[s->init_num], 34 - s->init_num);
    init_num = s->init_num;
    if ( v3 < 18 - init_num )
      return ssl2_part_read(s, 100, v3);
    v6 = init_num + v3;
    msg_callback = s->msg_callback;
    s->init_num = v6;
    if ( msg_callback )
      msg_callback(0, s->version, 0, data, v6, s, s->msg_callback_arg);
    if ( data[1] != 1 )
    {
      ssl2_return_error(s, 6);
      ERR_put_error(a2, 0x14u, 100, 102, ".\\ssl\\s2_clnt.c", 775);
      return -1;
    }
    cert = s->cert;
    if ( cert && (key = cert->key, key->x509) && key->privatekey )
      s->state = 4178;
    else
      s->state = 4240;
  }
  v10 = (engine_st *)(s->init_num - 2);
  if ( s->state != 4240 )
    goto LABEL_27;
  v11 = s->ctx;
  v12 = 0;
  v13 = 0;
  a = 0;
  pkey = 0;
  client_cert_cb = v11->client_cert_cb;
  v15 = 0;
  if ( client_cert_cb )
  {
    v15 = client_cert_cb(s, &a, &pkey);
    if ( v15 < 0 )
    {
      s->rwstate = 4;
      return -1;
    }
    v12 = a;
    v13 = pkey;
  }
  s->rwstate = 1;
  if ( v15 == 1 )
  {
    if ( v13 )
    {
      if ( v12 )
      {
        s->state = 4178;
        if ( !SSL_use_certificate(s, v12) || !SSL_use_PrivateKey(s, pkey) )
          v15 = 0;
        X509_free(a);
        EVP_PKEY_free((int)data, pkey);
        goto LABEL_25;
      }
    }
    else
    {
      if ( !v12 )
      {
LABEL_36:
        ERR_put_error((int)v10, 0x14u, 100, 106, ".\\ssl\\s2_clnt.c", 831);
        goto LABEL_26;
      }
      X509_free(v12);
      v13 = pkey;
    }
    if ( v13 )
      EVP_PKEY_free((int)data, v13);
    goto LABEL_36;
  }
LABEL_25:
  if ( !v15 )
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
    EVP_DigestInit_ex(v10, &ctx, s->ctx->rsa_md5, 0);
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
    v16 = s->cert;
    out += 2;
    EVP_SignFinal(&ctx, sigret, &siglen, v16->key->privatekey);
    EVP_MD_CTX_cleanup((int)data, 2, &ctx);
    *out = BYTE1(siglen);
    out[1] = siglen;
    out += 2;
    sigret += siglen;
    v17 = (unsigned __int8 *)(sigret - data);
    s->state = 4179;
    s->init_num = (int)v17;
    s->init_off = 0;
  }
  return ssl2_do_write(s);
}
