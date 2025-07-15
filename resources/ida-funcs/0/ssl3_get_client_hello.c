int __cdecl ssl3_get_client_hello(ssl_st *s)
{
  ssl_st *v1; // ebp
  bool v2; // zf
  const ssl_method_st *method; // eax
  int result; // eax
  ssl_st *v5; // eax
  int version_low; // edx
  int v7; // ecx
  unsigned __int8 *v8; // ebx
  int version; // eax
  int v10; // ecx
  int v11; // ecx
  unsigned __int8 *v12; // eax
  int prev_session; // eax
  char *v14; // eax
  int v15; // ecx
  unsigned int v16; // edi
  int (__cdecl *app_verify_cookie_cb)(ssl_st *, unsigned __int8 *, unsigned int); // eax
  dtls1_state_st *d1; // ecx
  unsigned int cookie_len; // eax
  unsigned __int8 *cookie; // edx
  unsigned __int8 *rcvd_cookie; // esi
  int v22; // esi
  ssl_st *v23; // eax
  unsigned __int8 *v24; // ebx
  ssl_st *v25; // eax
  unsigned int id; // edi
  int v27; // esi
  int v28; // edi
  ssl_st *v29; // eax
  int v30; // ecx
  int v31; // eax
  unsigned __int8 *server_random; // ecx
  ssl_session_st *session; // eax
  stack_st_SSL_CIPHER *v34; // edx
  ssl_session_st *v35; // ecx
  ssl_cipher_st *v36; // eax
  stack_st_SSL_CIPHER *ciphers; // eax
  stack_st *v38; // eax
  ssl_session_st *v39; // ecx
  unsigned int compress_meth; // ebx
  int v41; // esi
  int v42; // eax
  unsigned __int8 *v43; // ebx
  int v44; // esi
  char *v45; // edx
  int v46; // ecx
  int v47; // eax
  int v48; // esi
  unsigned int v49; // eax
  ssl_session_st *v50; // edx
  stack_st_SSL_CIPHER *v51; // eax
  unsigned __int8 *v52; // eax
  ssl_session_st *v53; // edx
  unsigned __int8 *v54; // ebx
  const stack_st *p_stack; // edi
  unsigned __int8 *v56; // eax
  int v57; // [esp-Ch] [ebp-34h]
  int desc; // [esp+8h] [ebp-20h] BYREF
  stack_st_SSL_CIPHER *skp; // [esp+Ch] [ebp-1Ch] BYREF
  char *v60; // [esp+10h] [ebp-18h]
  int v61; // [esp+14h] [ebp-14h]
  ssl_st *i; // [esp+18h] [ebp-10h]
  int n; // [esp+1Ch] [ebp-Ch] BYREF
  unsigned __int8 *d; // [esp+20h] [ebp-8h]
  int v65; // [esp+24h] [ebp-4h] BYREF

  v1 = s;
  v2 = s->state == 8464;
  v61 = -1;
  v60 = 0;
  skp = 0;
  if ( v2 )
    s->state = 8465;
  method = v1->method;
  v1->first_packet = 1;
  result = method->ssl_get_message(v1, 8465, 8466, 1, 0x4000, &v65);
  n = result;
  if ( v65 )
  {
    s = (ssl_st *)v1->init_msg;
    v5 = s;
    v1->first_packet = 0;
    version_low = LOBYTE(v5->version);
    v7 = BYTE1(v5->version);
    v8 = (unsigned __int8 *)v5;
    s = (ssl_st *)((char *)&v5->version + 2);
    version = v1->version;
    v10 = (version_low << 8) | v7;
    d = v8;
    v1->client_version = v10;
    if ( version == 65279 )
    {
      if ( v10 <= 65279 )
      {
LABEL_6:
        if ( (SSL_ctrl(v1, 32, 0, 0) & 0x2000) != 0 && !*((_BYTE *)&s->handshake_func + LOBYTE(s->handshake_func) + 1) )
          return 1;
        qmemcpy(v1->s3->client_random, s, sizeof(v1->s3->client_random));
        s = (ssl_st *)((char *)s + 32);
        v11 = LOBYTE(s->version);
        v12 = (unsigned __int8 *)&s->version + 1;
        v2 = v1->new_session == 0;
        i = (ssl_st *)v11;
        s = (ssl_st *)((char *)s + 1);
        v1->hit = 0;
        if ( v2 || ((unsigned int)&_sbh_sizeHeaderList & v1->options) == 0 )
        {
          prev_session = ssl_get_prev_session(v1, v12, v11, &v8[n]);
          if ( prev_session == 1 )
          {
            v1->hit = 1;
            goto LABEL_19;
          }
          if ( prev_session == -1 )
            goto err_224;
        }
        if ( !ssl_get_new_session(v1, 1) )
          goto err_224;
LABEL_19:
        v14 = (char *)s + (_DWORD)i;
        v15 = v1->version;
        s = (ssl_st *)((char *)s + (_DWORD)i);
        if ( v15 != 65279 && v15 != 256 )
          goto LABEL_40;
        v16 = (unsigned __int8)*v14;
        s = (ssl_st *)(v14 + 1);
        if ( (SSL_ctrl(v1, 32, 0, 0) & 0x2000) == 0 || !v16 )
        {
LABEL_39:
          v14 = (char *)s + v16;
          s = (ssl_st *)((char *)s + v16);
LABEL_40:
          v22 = ((unsigned __int8)*v14 << 8) | (unsigned __int8)v14[1];
          v23 = (ssl_st *)(v14 + 2);
          s = v23;
          if ( !v22 && i )
          {
            desc = 47;
            ERR_put_error(0x14u, 138, 183, ".\\ssl\\s3_srvr.c", 964);
            goto LABEL_133;
          }
          v24 = &d[n];
          if ( (char *)v23 + v22 >= (char *)&d[n] )
          {
            desc = 50;
            ERR_put_error(0x14u, 138, 159, ".\\ssl\\s3_srvr.c", 971);
            goto LABEL_133;
          }
          if ( v22 <= 0 )
          {
LABEL_48:
            v25 = (ssl_st *)((char *)v23 + v22);
            v2 = v1->hit == 0;
            s = v25;
            if ( !v2 && v22 > 0 )
            {
              id = v1->session->cipher->id;
              v27 = 0;
              if ( sk_num(&skp->stack) <= 0 )
              {
LABEL_53:
                desc = 47;
                ERR_put_error(0x14u, 138, 215, ".\\ssl\\s3_srvr.c", 1027);
                goto LABEL_133;
              }
              while ( *((_DWORD *)sk_value(&skp->stack, v27) + 2) != id )
              {
                if ( ++v27 >= sk_num(&skp->stack) )
                  goto LABEL_53;
              }
              v25 = s;
            }
            v28 = LOBYTE(v25->version);
            v29 = (ssl_st *)((char *)&v25->version + 1);
            s = v29;
            if ( (char *)v29 + v28 > (char *)v24 )
            {
              desc = 50;
              ERR_put_error(0x14u, 138, 159, ".\\ssl\\s3_srvr.c", 1038);
              goto LABEL_133;
            }
            v30 = 0;
            for ( i = v29; v30 < v28; ++v30 )
            {
              if ( !*((_BYTE *)&v29->version + v30) )
                break;
            }
            s = (ssl_st *)((char *)v29 + v28);
            if ( v30 >= v28 )
            {
              desc = 50;
              ERR_put_error(0x14u, 138, 187, ".\\ssl\\s3_srvr.c", 1052);
              goto LABEL_133;
            }
            if ( v1->version >= 768 && !ssl_parse_clienthello_tlsext(v1, (unsigned __int8 **)&s, d, n, &desc) )
            {
              ERR_put_error(0x14u, 138, 227, ".\\ssl\\s3_srvr.c", 1063);
              goto LABEL_133;
            }
            if ( ssl_check_clienthello_tlsext(v1) <= 0 )
            {
              ERR_put_error(0x14u, 138, 226, ".\\ssl\\s3_srvr.c", 1068);
              goto err_224;
            }
            v31 = _time64(0);
            server_random = v1->s3->server_random;
            *server_random++ = HIBYTE(v31);
            *server_random++ = BYTE2(v31);
            *server_random = BYTE1(v31);
            server_random[1] = v31;
            if ( RAND_pseudo_bytes() <= 0 )
            {
              desc = 80;
              ssl3_send_alert(v1, 2, 80);
              goto err_224;
            }
            if ( !v1->hit && v1->version >= 769 )
            {
              if ( v1->tls_session_secret_cb )
              {
                session = v1->session;
                n = 0;
                session->master_key_length = 48;
                if ( v1->tls_session_secret_cb(
                       v1,
                       v1->session->master_key,
                       &v1->session->master_key_length,
                       skp,
                       (ssl_cipher_st **)&n,
                       v1->tls_session_secret_cb_arg) )
                {
                  v34 = skp;
                  v35 = v1->session;
                  v1->hit = 1;
                  v35->ciphers = v34;
                  v1->session->verify_result = 0;
                  v36 = (ssl_cipher_st *)n;
                  skp = 0;
                  if ( !n )
                  {
                    ciphers = SSL_get_ciphers(v1);
                    v36 = ssl3_choose_cipher(v1, v1->session->ciphers, ciphers);
                    n = (int)v36;
                    if ( !v36 )
                    {
                      desc = 40;
                      ERR_put_error(0x14u, 138, 193, ".\\ssl\\s3_srvr.c", 1108);
                      goto LABEL_133;
                    }
                  }
                  v1->session->cipher = v36;
                  if ( v1->cipher_list )
                    sk_free(&v1->cipher_list->stack);
                  if ( v1->cipher_list_by_id )
                    sk_free(&v1->cipher_list_by_id->stack);
                  v38 = sk_dup(&v1->session->ciphers->stack);
                  v39 = v1->session;
                  v1->cipher_list = (stack_st_SSL_CIPHER *)v38;
                  v1->cipher_list_by_id = (stack_st_SSL_CIPHER *)sk_dup(&v39->ciphers->stack);
                }
              }
            }
            v1->s3->tmp.new_compression = 0;
            compress_meth = v1->session->compress_meth;
            if ( compress_meth )
            {
              if ( ((unsigned int)&loc_20000 & v1->options) != 0 )
              {
                desc = 80;
                ERR_put_error(0x14u, 138, 340, ".\\ssl\\s3_srvr.c", 1140);
                goto LABEL_133;
              }
              v41 = 0;
              if ( sk_num(&v1->ctx->comp_methods->stack) > 0 )
              {
                while ( 1 )
                {
                  v60 = sk_value(&v1->ctx->comp_methods->stack, v41);
                  if ( compress_meth == *(_DWORD *)v60 )
                    break;
                  if ( ++v41 >= sk_num(&v1->ctx->comp_methods->stack) )
                    goto LABEL_89;
                }
                v1->s3->tmp.new_compression = (const ssl_comp_st *)v60;
              }
LABEL_89:
              if ( !v1->s3->tmp.new_compression )
              {
                desc = 80;
                ERR_put_error(0x14u, 138, 341, ".\\ssl\\s3_srvr.c", 1156);
                goto LABEL_133;
              }
              v42 = 0;
              if ( v28 <= 0 )
                goto LABEL_96;
              while ( *((unsigned __int8 *)&i->version + v42) != compress_meth )
              {
                if ( ++v42 >= v28 )
                  goto LABEL_96;
              }
              if ( v42 >= v28 )
              {
LABEL_96:
                desc = 47;
                ERR_put_error(0x14u, 138, 342, ".\\ssl\\s3_srvr.c", 1168);
                goto LABEL_133;
              }
            }
            else if ( v1->hit )
            {
              v60 = 0;
            }
            else if ( ((unsigned int)&loc_20000 & v1->options) == 0 && v1->ctx->comp_methods )
            {
              v43 = (unsigned __int8 *)sk_num(&v1->ctx->comp_methods->stack);
              v44 = 0;
              d = v43;
              if ( (int)v43 <= 0 )
              {
LABEL_107:
                v60 = 0;
              }
              else
              {
                while ( 1 )
                {
                  v45 = sk_value(&v1->ctx->comp_methods->stack, v44);
                  v46 = *(_DWORD *)v45;
                  v47 = 0;
                  v60 = v45;
                  if ( v28 > 0 )
                    break;
LABEL_106:
                  if ( ++v44 >= (int)v43 )
                    goto LABEL_107;
                }
                while ( v46 != *((unsigned __int8 *)&i->version + v47) )
                {
                  if ( ++v47 >= v28 )
                  {
                    v43 = d;
                    goto LABEL_106;
                  }
                }
                v1->s3->tmp.new_compression = (const ssl_comp_st *)v45;
              }
            }
            v48 = 0;
            if ( !v1->hit )
            {
              if ( v60 )
                v49 = *(_DWORD *)v60;
              else
                v49 = 0;
              v1->session->compress_meth = v49;
              v50 = v1->session;
              if ( v50->ciphers )
                sk_free(&v50->ciphers->stack);
              v1->session->ciphers = skp;
              if ( !skp )
              {
                desc = 47;
                ERR_put_error(0x14u, 138, 182, ".\\ssl\\s3_srvr.c", 1226);
                goto LABEL_133;
              }
              skp = 0;
              v51 = SSL_get_ciphers(v1);
              v52 = (unsigned __int8 *)ssl3_choose_cipher(v1, v1->session->ciphers, v51);
              if ( !v52 )
              {
                desc = 40;
                ERR_put_error(0x14u, 138, 193, ".\\ssl\\s3_srvr.c", 1236);
                goto LABEL_133;
              }
LABEL_129:
              v1->s3->tmp.new_cipher = (const ssl_cipher_st *)v52;
              goto LABEL_132;
            }
            v53 = v1->session;
            v54 = 0;
            v2 = (v1->options & 0x40000000) == 0;
            d = 0;
            if ( !v2 )
            {
              p_stack = &v53->ciphers->stack;
              if ( sk_num(p_stack) > 0 )
              {
                do
                {
                  v56 = (unsigned __int8 *)sk_value(p_stack, v48);
                  if ( (v56[20] & 0x20) != 0 )
                    v54 = v56;
                  if ( (v56[32] & 2) != 0 )
                    d = v56;
                  ++v48;
                }
                while ( v48 < sk_num(p_stack) );
                if ( v54 )
                {
                  v1->s3->tmp.new_cipher = (const ssl_cipher_st *)v54;
                  goto LABEL_132;
                }
                v52 = d;
                if ( d )
                  goto LABEL_129;
              }
              v53 = v1->session;
            }
            v1->s3->tmp.new_cipher = v53->cipher;
LABEL_132:
            if ( ssl3_digest_cached_records(v1) )
            {
              if ( v61 < 0 )
                v61 = 1;
              goto err_224;
            }
            goto LABEL_133;
          }
          if ( ssl_bytes_to_cipher_list(v1, (unsigned __int8 *)v23, v22, &skp) )
          {
            v23 = s;
            goto LABEL_48;
          }
err_224:
          if ( skp )
            sk_free(&skp->stack);
          return v61;
        }
        memcpy(v1->d1->rcvd_cookie, (unsigned __int8 *)s, v16);
        app_verify_cookie_cb = v1->ctx->app_verify_cookie_cb;
        if ( app_verify_cookie_cb )
        {
          if ( !app_verify_cookie_cb(v1, v1->d1->rcvd_cookie, v16) )
          {
            desc = 40;
            v57 = 939;
LABEL_22:
            ERR_put_error(0x14u, 138, 308, ".\\ssl\\s3_srvr.c", v57);
LABEL_133:
            ssl3_send_alert(v1, 2, desc);
            goto err_224;
          }
          goto LABEL_38;
        }
        d1 = v1->d1;
        cookie_len = d1->cookie_len;
        cookie = d1->cookie;
        rcvd_cookie = d1->rcvd_cookie;
        if ( cookie_len < 4 )
        {
LABEL_31:
          if ( !cookie_len
            || *cookie == *rcvd_cookie
            && (cookie_len <= 1 || cookie[1] == rcvd_cookie[1] && (cookie_len <= 2 || cookie[2] == rcvd_cookie[2])) )
          {
LABEL_38:
            v61 = 2;
            goto LABEL_39;
          }
        }
        else
        {
          while ( *(_DWORD *)rcvd_cookie == *(_DWORD *)cookie )
          {
            cookie_len -= 4;
            cookie += 4;
            rcvd_cookie += 4;
            if ( cookie_len < 4 )
              goto LABEL_31;
          }
        }
        desc = 40;
        v57 = 949;
        goto LABEL_22;
      }
    }
    else if ( v10 >= version )
    {
      goto LABEL_6;
    }
    ERR_put_error(0x14u, 138, 267, ".\\ssl\\s3_srvr.c", 844);
    if ( (v1->client_version & 0xFFFFFF00) == 0x300 )
      v1->version = v1->client_version;
    desc = 70;
    ssl3_send_alert(v1, 2, 70);
    goto err_224;
  }
  return result;
}
