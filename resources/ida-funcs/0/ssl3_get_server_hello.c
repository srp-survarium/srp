int __cdecl ssl3_get_server_hello(ssl_st *s)
{
  ssl_st *v1; // ebx
  int result; // eax
  ssl3_state_st *s3; // eax
  ssl3_state_st *v4; // ecx
  unsigned __int8 *init_msg; // esi
  int version; // eax
  int v7; // edi
  ssl_st *client_random; // edi
  unsigned int version_low; // esi
  ssl_session_st *session; // eax
  int v11; // eax
  ssl_session_st *v12; // ebp
  unsigned int v13; // eax
  unsigned __int8 *session_id; // esi
  unsigned int sid_ctx_length; // eax
  unsigned __int8 *sid_ctx; // esi
  ssl_session_st *v17; // eax
  const ssl_method_st *method; // ecx
  int v19; // esi
  stack_st_SSL_CIPHER *ciphers_by_id; // eax
  ssl_session_st *v21; // eax
  const ssl_cipher_st *cipher; // ecx
  int v23; // eax
  bool v24; // zf
  int v25; // [esp-10h] [ebp-2Ch]
  int desc; // [esp+4h] [ebp-18h] BYREF
  unsigned int v27; // [esp+8h] [ebp-14h]
  int v28; // [esp+Ch] [ebp-10h] BYREF
  unsigned __int8 *d; // [esp+10h] [ebp-Ch]
  int n; // [esp+14h] [ebp-8h]
  int v31; // [esp+18h] [ebp-4h] BYREF

  v1 = s;
  result = s->method->ssl_get_message(s, 4384, 4385, -1, 20000, &v31);
  n = result;
  if ( v31 )
  {
    if ( EVP_CIPHER_CTX_cipher(v1) == 65279 || EVP_CIPHER_CTX_cipher(v1) == 256 )
    {
      s3 = v1->s3;
      if ( s3->tmp.message_type == 3 )
      {
        if ( !v1->d1->send_cookie )
        {
          s3->tmp.reuse_message = 1;
          return 1;
        }
        v25 = 756;
        goto LABEL_9;
      }
    }
    v4 = v1->s3;
    if ( v4->tmp.message_type != 2 )
    {
      v25 = 765;
LABEL_9:
      desc = 10;
      ERR_put_error((int)v1, 0x14u, 146, 114, ".\\ssl\\s3_clnt.c", v25);
      goto f_err;
    }
    init_msg = (unsigned __int8 *)v1->init_msg;
    version = v1->version;
    s = (ssl_st *)init_msg;
    v7 = *init_msg;
    d = init_msg;
    if ( v7 != version >> 8 || init_msg[1] != (_BYTE)version )
    {
      ERR_put_error((int)v1, 0x14u, 146, 266, ".\\ssl\\s3_clnt.c", 773);
      v1->version = v1->version & 0xFF00 | BYTE1(s->version);
      desc = 70;
      goto f_err;
    }
    s = (ssl_st *)(init_msg + 2);
    qmemcpy(v4->server_random, init_msg + 2, sizeof(v4->server_random));
    client_random = (ssl_st *)v4->client_random;
    s = (ssl_st *)((char *)s + 32);
    version_low = LOBYTE(s->version);
    v27 = version_low;
    s = (ssl_st *)((char *)s + 1);
    if ( version_low > 0x20 )
    {
      desc = 47;
      ERR_put_error((int)v1, 0x14u, 146, 300, ".\\ssl\\s3_clnt.c", 791);
      goto f_err;
    }
    if ( v1->version >= 769 )
    {
      if ( v1->tls_session_secret_cb )
      {
        session = v1->session;
        v28 = 0;
        session->master_key_length = 48;
        if ( v1->tls_session_secret_cb(
               v1,
               v1->session->master_key,
               &v1->session->master_key_length,
               0,
               (ssl_cipher_st **)&v28,
               v1->tls_session_secret_cb_arg) )
        {
          v11 = v28;
          if ( !v28 )
            v11 = (int)v1->method->get_cipher_by_char((const unsigned __int8 *)s + version_low);
          v1->session->cipher = (const ssl_cipher_st *)v11;
        }
      }
    }
    if ( version_low )
    {
      v12 = v1->session;
      if ( version_low == v12->session_id_length )
      {
        client_random = s;
        v13 = version_low;
        session_id = v12->session_id;
        if ( v13 < 4 )
        {
LABEL_26:
          if ( !v13
            || *session_id == LOBYTE(client_random->version)
            && (v13 <= 1
             || session_id[1] == BYTE1(client_random->version)
             && (v13 <= 2 || session_id[2] == BYTE2(client_random->version))) )
          {
            sid_ctx_length = v1->sid_ctx_length;
            if ( sid_ctx_length == v12->sid_ctx_length )
            {
              sid_ctx = v1->sid_ctx;
              client_random = (ssl_st *)v12->sid_ctx;
              if ( sid_ctx_length < 4 )
              {
LABEL_36:
                if ( !sid_ctx_length
                  || *sid_ctx == LOBYTE(client_random->version)
                  && (sid_ctx_length <= 1
                   || sid_ctx[1] == BYTE1(client_random->version)
                   && (sid_ctx_length <= 2 || sid_ctx[2] == BYTE2(client_random->version))) )
                {
                  version_low = v27;
                  v1->hit = 1;
LABEL_49:
                  method = v1->method;
                  s = (ssl_st *)((char *)s + version_low);
                  v19 = (int)method->get_cipher_by_char((const unsigned __int8 *)s);
                  if ( v19 )
                  {
                    s = (ssl_st *)((char *)s + v1->method->put_cipher_by_char(0, 0));
                    ciphers_by_id = ssl_get_ciphers_by_id(v1);
                    if ( sk_find((int)client_random, &ciphers_by_id->stack, (char *)v19) >= 0 )
                    {
                      v21 = v1->session;
                      cipher = v21->cipher;
                      if ( cipher )
                        v21->cipher_id = cipher->id;
                      if ( !v1->hit || v1->session->cipher_id == *(_DWORD *)(v19 + 8) )
                      {
                        v1->s3->tmp.new_cipher = (const ssl_cipher_st *)v19;
                        if ( ssl3_digest_cached_records(v1) )
                        {
                          v23 = LOBYTE(s->version);
                          v24 = v1->hit == 0;
                          s = (ssl_st *)((char *)s + 1);
                          if ( v24 || v23 == v1->session->compress_meth )
                          {
                            if ( v23 )
                            {
                              if ( ((unsigned int)&loc_20000 & v1->options) != 0 )
                              {
                                desc = 47;
                                ERR_put_error((int)v1, 0x14u, 146, 343, ".\\ssl\\s3_clnt.c", 915);
                                goto f_err;
                              }
                              v23 = (int)ssl3_comp_find(v1->ctx->comp_methods, v23);
                              if ( !v23 )
                              {
                                desc = 47;
                                ERR_put_error((int)v1, 0x14u, 146, 257, ".\\ssl\\s3_clnt.c", 924);
                                goto f_err;
                              }
                            }
                            v1->s3->tmp.new_compression = (const ssl_comp_st *)v23;
                            if ( v1->version >= 768 )
                            {
                              if ( !ssl_parse_serverhello_tlsext(v1, (unsigned __int16 **)&s, d, n, &desc) )
                              {
                                ERR_put_error((int)v1, 0x14u, 146, 227, ".\\ssl\\s3_clnt.c", 940);
                                goto f_err;
                              }
                              if ( ssl_check_serverhello_tlsext(v1) <= 0 )
                              {
                                ERR_put_error((int)v1, 0x14u, 146, 275, ".\\ssl\\s3_clnt.c", 945);
                                return -1;
                              }
                            }
                            if ( s == (ssl_st *)&d[n] )
                              return 1;
                            desc = 50;
                            ERR_put_error((int)v1, 0x14u, 146, 115, ".\\ssl\\s3_clnt.c", 955);
                            goto f_err;
                          }
                          desc = 47;
                          ERR_put_error((int)v1, 0x14u, 146, 344, ".\\ssl\\s3_clnt.c", 907);
                        }
                      }
                      else
                      {
                        desc = 47;
                        ERR_put_error((int)v1, 0x14u, 146, 197, ".\\ssl\\s3_clnt.c", 876);
                      }
                    }
                    else
                    {
                      desc = 47;
                      ERR_put_error((int)v1, 0x14u, 146, 261, ".\\ssl\\s3_clnt.c", 858);
                    }
                  }
                  else
                  {
                    desc = 47;
                    ERR_put_error((int)v1, 0x14u, 146, 248, ".\\ssl\\s3_clnt.c", 847);
                  }
f_err:
                  ssl3_send_alert(v1, 2, desc);
                  return -1;
                }
              }
              else
              {
                while ( client_random->version == *(_DWORD *)sid_ctx )
                {
                  sid_ctx_length -= 4;
                  sid_ctx += 4;
                  client_random = (ssl_st *)((char *)client_random + 4);
                  if ( sid_ctx_length < 4 )
                    goto LABEL_36;
                }
              }
            }
            desc = 47;
            ERR_put_error((int)v1, 0x14u, 146, 272, ".\\ssl\\s3_clnt.c", 820);
            goto f_err;
          }
        }
        else
        {
          while ( client_random->version == *(_DWORD *)session_id )
          {
            v13 -= 4;
            session_id += 4;
            client_random = (ssl_st *)((char *)client_random + 4);
            if ( v13 < 4 )
              goto LABEL_26;
          }
        }
        version_low = v27;
      }
    }
    v17 = v1->session;
    v1->hit = 0;
    if ( v17->session_id_length && !ssl_get_new_session(v1, 0) )
    {
      desc = 80;
      goto f_err;
    }
    v1->session->session_id_length = version_low;
    memcpy((int)v1->session->session_id, (const __m128i *)s, version_low);
    goto LABEL_49;
  }
  return result;
}
