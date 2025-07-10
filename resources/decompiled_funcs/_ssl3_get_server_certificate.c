int __cdecl ssl3_get_server_certificate(ssl_st *s)
{
  ssl_st *v1; // ebx
  int result; // eax
  int v3; // esi
  ssl3_state_st *s3; // eax
  int message_type; // ecx
  int v6; // esi
  unsigned __int8 *init_msg; // edi
  stack_st_X509 *v8; // eax
  unsigned int v9; // ebp
  ssl_st *v10; // edi
  unsigned int v11; // ecx
  int v12; // esi
  ssl_st *v13; // edi
  char *v14; // eax
  int v15; // eax
  int v16; // esi
  sess_cert_st *v17; // esi
  ssl_session_st *session; // ecx
  x509_st *v19; // edi
  evp_pkey_st *pubkey; // ebp
  const ssl_cipher_st *new_cipher; // eax
  int v22; // eax
  int v23; // ebp
  x509_st *x509; // eax
  cert_pkey_st *v25; // ebp
  ssl_session_st *v26; // ecx
  __int16 v27; // [esp-10h] [ebp-34h]
  int v28; // [esp-8h] [ebp-2Ch]
  x509_st *a; // [esp+Ch] [ebp-18h]
  int aa; // [esp+Ch] [ebp-18h]
  stack_st *st; // [esp+10h] [ebp-14h]
  evp_pkey_st *x; // [esp+14h] [ebp-10h]
  int v33; // [esp+18h] [ebp-Ch]
  int v34; // [esp+1Ch] [ebp-8h] BYREF
  unsigned int v35; // [esp+20h] [ebp-4h]

  v1 = s;
  v33 = -1;
  a = 0;
  st = 0;
  x = 0;
  result = s->method->ssl_get_message(s, 4400, 4401, -1, s->max_cert_list, &v34);
  v3 = result;
  if ( v34 )
  {
    s3 = v1->s3;
    message_type = s3->tmp.message_type;
    if ( message_type != 12 && ((s3->tmp.new_cipher->algorithm_auth & 0x20) == 0 || message_type != 14) )
    {
      if ( message_type != 11 )
      {
        v6 = 10;
        ERR_put_error(0x14u, 144, 114, ".\\ssl\\s3_clnt.c", 998);
LABEL_36:
        ssl3_send_alert(v1, 2, v6);
        goto err_217;
      }
      init_msg = (unsigned __int8 *)v1->init_msg;
      v8 = (stack_st_X509 *)sk_new_null();
      st = &v8->stack;
      if ( !v8 )
      {
        ERR_put_error(0x14u, 144, 65, ".\\ssl\\s3_clnt.c", 1005);
        goto err_217;
      }
      v9 = init_msg[2] | ((init_msg[1] | (*init_msg << 8)) << 8);
      v10 = (ssl_st *)(init_msg + 3);
      if ( v9 + 3 != v3 )
      {
        v6 = 50;
        ERR_put_error(0x14u, 144, 159, ".\\ssl\\s3_clnt.c", 1013);
        goto LABEL_36;
      }
      v11 = 0;
      if ( v9 )
      {
        while ( 1 )
        {
          v12 = BYTE2(v10->version) | ((BYTE1(v10->version) | (LOBYTE(v10->version) << 8)) << 8);
          v13 = (ssl_st *)((char *)&v10->version + 3);
          v35 = v12 + v11 + 3;
          if ( v35 > v9 )
          {
            v6 = 50;
            ERR_put_error(0x14u, 144, 135, ".\\ssl\\s3_clnt.c", 1022);
            goto LABEL_36;
          }
          s = v13;
          v14 = (char *)d2i_X509(0, (const unsigned __int8 **)&s, v12);
          a = (x509_st *)v14;
          if ( !v14 )
          {
            v6 = 42;
            ERR_put_error(0x14u, 144, 13, ".\\ssl\\s3_clnt.c", 1031);
            goto LABEL_36;
          }
          if ( s != (ssl_st *)((char *)v13 + v12) )
          {
            v6 = 50;
            ERR_put_error(0x14u, 144, 135, ".\\ssl\\s3_clnt.c", 1037);
            goto LABEL_36;
          }
          if ( !sk_push(st, v14) )
            break;
          v11 = v35;
          v10 = s;
          a = 0;
          if ( v35 >= v9 )
          {
            v8 = (stack_st_X509 *)st;
            goto LABEL_19;
          }
        }
        ERR_put_error(0x14u, 144, 65, ".\\ssl\\s3_clnt.c", 1042);
        goto err_217;
      }
LABEL_19:
      v15 = ssl_verify_cert_chain(v1, v8);
      if ( v1->verify_mode && v15 <= 0 )
      {
        v16 = ssl_verify_alarm_type(v1->verify_result);
        ERR_put_error(0x14u, 144, 134, ".\\ssl\\s3_clnt.c", 1059);
        ssl3_send_alert(v1, 2, v16);
err_217:
        EVP_PKEY_free(x);
        X509_free(a);
        sk_pop_free(st, (void (__cdecl *)(void *))X509_free);
        return v33;
      }
      ERR_clear_error();
      v17 = ssl_sess_cert_new();
      if ( !v17 )
        goto err_217;
      session = v1->session;
      if ( session->sess_cert )
        ssl_sess_cert_free(session->sess_cert);
      v1->session->sess_cert = v17;
      v17->cert_chain = (stack_st_X509 *)st;
      v19 = (x509_st *)sk_value(st, 0);
      st = 0;
      pubkey = X509_get_pubkey(v19);
      new_cipher = v1->s3->tmp.new_cipher;
      x = pubkey;
      if ( (new_cipher->algorithm_mkey & 0x10) != 0 && (new_cipher->algorithm_auth & 0x20) != 0 )
      {
        aa = 0;
      }
      else
      {
        aa = 1;
        if ( !pubkey || EVP_PKEY_missing_parameters(pubkey) )
        {
          v28 = 1096;
          a = 0;
          v27 = 239;
          goto LABEL_35;
        }
      }
      v22 = ssl_cert_type(v19, pubkey);
      v23 = v22;
      if ( aa )
      {
        if ( v22 < 0 )
        {
          v28 = 1106;
          a = 0;
          v27 = 247;
LABEL_35:
          v6 = 2;
          ERR_put_error(0x14u, 144, v27, ".\\ssl\\s3_clnt.c", v28);
          goto LABEL_36;
        }
        v17->peer_cert_type = v22;
        CRYPTO_add_lock(&v19->references, 1, 3, ".\\ssl\\s3_clnt.c", 1113);
        x509 = v17->peer_pkeys[v23].x509;
        v25 = &v17->peer_pkeys[v23];
        if ( x509 )
          X509_free(x509);
        v25->x509 = v19;
        v17->peer_key = v25;
        v26 = v1->session;
        if ( v26->peer )
          X509_free(v26->peer);
        CRYPTO_add_lock(&v19->references, 1, 3, ".\\ssl\\s3_clnt.c", 1123);
        v1->session->peer = v19;
      }
      else
      {
        v17->peer_cert_type = v22;
        v17->peer_key = 0;
        if ( v1->session->peer )
          X509_free(v1->session->peer);
        v1->session->peer = 0;
      }
      v1->session->verify_result = v1->verify_result;
      a = 0;
      v33 = 1;
      goto err_217;
    }
    s3->tmp.reuse_message = 1;
    return 1;
  }
  return result;
}
