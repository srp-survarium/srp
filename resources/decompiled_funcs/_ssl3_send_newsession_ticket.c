int __cdecl ssl3_send_newsession_ticket(ssl_st *s)
{
  ssl_ctx_st *initial_ctx; // edi
  int v2; // eax
  int v3; // ebp
  unsigned __int8 *v4; // ebx
  int (__cdecl *tlsext_ticket_key_cb)(ssl_st *, unsigned __int8 *, unsigned __int8 *, evp_cipher_ctx_st *, hmac_ctx_st *, int); // eax
  const evp_cipher_st *v7; // eax
  const env_md_st *v8; // eax
  ssl_session_st *v9; // ecx
  ssl_session_st *v10; // ecx
  ssl_session_st *v11; // ecx
  unsigned __int8 *v12; // eax
  unsigned int v13; // edi
  X509_name_st *issuer_name; // eax
  X509_name_st *v15; // eax
  buf_mem_st *init_buf; // ecx
  ssl_session_st *session; // [esp-8h] [ebp-1A4h]
  unsigned __int8 *pp; // [esp+10h] [ebp-18Ch] BYREF
  int outl; // [esp+14h] [ebp-188h] BYREF
  unsigned int len; // [esp+18h] [ebp-184h] BYREF
  evp_cipher_ctx_st ctx; // [esp+1Ch] [ebp-180h] BYREF
  hmac_ctx_st v22; // [esp+A8h] [ebp-F4h] BYREF
  int v23; // [esp+178h] [ebp-24h] BYREF
  int v24; // [esp+17Ch] [ebp-20h]
  int v25; // [esp+180h] [ebp-1Ch]
  int v26; // [esp+184h] [ebp-18h]
  unsigned __int8 buf[16]; // [esp+188h] [ebp-14h] BYREF

  if ( s->state == 8688 )
  {
    initial_ctx = s->initial_ctx;
    v2 = i2d_SSL_SESSION(s->session, 0);
    v3 = v2;
    if ( v2 > 65280 )
      return -1;
    if ( !BUF_MEM_grow(s->init_buf, v2 + 138) )
      return -1;
    v4 = (unsigned __int8 *)CRYPTO_malloc(v3, ".\\ssl\\s3_srvr.c", 3102);
    if ( !v4 )
      return -1;
    session = s->session;
    pp = v4;
    i2d_SSL_SESSION(session, &pp);
    pp = (unsigned __int8 *)s->init_buf->data;
    *pp = 4;
    pp += 4;
    EVP_CIPHER_CTX_init(&ctx);
    HMAC_CTX_init(&v22);
    tlsext_ticket_key_cb = initial_ctx->tlsext_ticket_key_cb;
    if ( tlsext_ticket_key_cb )
    {
      if ( tlsext_ticket_key_cb(s, (unsigned __int8 *)&v23, buf, &ctx, &v22, 1) < 0 )
      {
        CRYPTO_free(v4);
        return -1;
      }
    }
    else
    {
      RAND_pseudo_bytes();
      v7 = EVP_aes_128_cbc();
      EVP_EncryptInit_ex(&ctx, v7, 0, initial_ctx->tlsext_tick_aes_key, buf);
      v8 = EVP_sha256();
      HMAC_Init_ex((unsigned int)initial_ctx, &v22, initial_ctx->tlsext_tick_hmac_key, 0x10u, v8, 0);
      v23 = *(_DWORD *)initial_ctx->tlsext_tick_key_name;
      v24 = *(_DWORD *)&initial_ctx->tlsext_tick_key_name[4];
      v25 = *(_DWORD *)&initial_ctx->tlsext_tick_key_name[8];
      v26 = *(_DWORD *)&initial_ctx->tlsext_tick_key_name[12];
    }
    *pp = HIBYTE(s->session->tlsext_tick_lifetime_hint);
    v9 = s->session;
    *++pp = BYTE2(v9->tlsext_tick_lifetime_hint);
    v10 = s->session;
    *++pp = BYTE1(v10->tlsext_tick_lifetime_hint);
    v11 = s->session;
    *++pp = v11->tlsext_tick_lifetime_hint;
    v12 = pp + 3;
    pp = v12;
    *(_DWORD *)v12 = v23;
    v13 = (unsigned int)v12;
    *((_DWORD *)pp + 1) = v24;
    *((_DWORD *)pp + 2) = v25;
    *((_DWORD *)pp + 3) = v26;
    pp += 16;
    issuer_name = X509_get_issuer_name((x509_st *)&ctx);
    memcpy(pp, buf, (unsigned int)issuer_name);
    v15 = X509_get_issuer_name((x509_st *)&ctx);
    pp = &pp[(_DWORD)v15];
    EVP_EncryptUpdate(&ctx, pp, &outl, v4, v3);
    pp += outl;
    EVP_EncryptFinal(&ctx, pp, &outl);
    pp += outl;
    EVP_CIPHER_CTX_cleanup(v13, &ctx);
    HMAC_Update(&v22);
    HMAC_Final(&v22, pp, &len);
    HMAC_CTX_cleanup(v13, &v22);
    init_buf = s->init_buf;
    pp += len;
    outl = pp - (unsigned __int8 *)init_buf->data;
    pp = (unsigned __int8 *)(init_buf->data + 1);
    *pp = (unsigned int)(outl - 4) >> 16;
    pp[1] = (unsigned __int16)(outl - 4) >> 8;
    pp[2] = outl - 4;
    pp += 7;
    *pp = (unsigned __int16)(outl - 10) >> 8;
    pp[1] = outl - 10;
    pp += 2;
    s->init_num = outl;
    s->state = 8689;
    s->init_off = 0;
    CRYPTO_free(v4);
  }
  return ssl3_do_write(s, 22);
}
