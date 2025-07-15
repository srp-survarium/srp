int __usercall ssl3_get_server_certificate@<eax>(char *init_msg@<edi>, ssl_st *s)
{
  ssl_st *v2; // ebx
  int result; // eax
  int v4; // esi
  ssl3_state_st *s3; // eax
  int message_type; // ecx
  int v7; // esi
  stack_st_X509 *v8; // eax
  unsigned int v9; // ebp
  unsigned int v10; // ecx
  const unsigned __int8 *v11; // esi
  char *v12; // eax
  int v13; // eax
  int v14; // esi
  sess_cert_st *v15; // esi
  ssl_session_st *session; // ecx
  evp_pkey_st *pubkey; // ebp
  const ssl_cipher_st *new_cipher; // eax
  int v19; // eax
  int v20; // ebp
  x509_st *x509; // eax
  cert_pkey_st *v22; // ebp
  ssl_session_st *v23; // ecx
  __int16 v24; // [esp-10h] [ebp-34h]
  int v25; // [esp-8h] [ebp-2Ch]
  x509_st *a; // [esp+Ch] [ebp-18h]
  int aa; // [esp+Ch] [ebp-18h]
  stack_st *st; // [esp+10h] [ebp-14h]
  evp_pkey_st *x; // [esp+14h] [ebp-10h]
  int v30; // [esp+18h] [ebp-Ch]
  int v31; // [esp+1Ch] [ebp-8h] BYREF
  unsigned int v32; // [esp+20h] [ebp-4h]

  v2 = s;
  v30 = -1;
  a = 0;
  st = 0;
  x = 0;
  result = s->method->ssl_get_message(s, 4400, 4401, -1, s->max_cert_list, &v31);
  v4 = result;
  if ( v31 )
  {
    s3 = v2->s3;
    message_type = s3->tmp.message_type;
    if ( message_type != 12 && ((s3->tmp.new_cipher->algorithm_auth & 0x20) == 0 || message_type != 14) )
    {
      if ( message_type != 11 )
      {
        v7 = 10;
        ERR_put_error((int)v2, 0x14u, 144, 114, ".\\ssl\\s3_clnt.c", 998);
LABEL_36:
        ssl3_send_alert(v2, 2, v7);
        goto err_219;
      }
      init_msg = (char *)v2->init_msg;
      v8 = (stack_st_X509 *)sk_new_null();
      st = &v8->stack;
      if ( !v8 )
      {
        ERR_put_error((int)v2, 0x14u, 144, 65, ".\\ssl\\s3_clnt.c", 1005);
        goto err_219;
      }
      v9 = (unsigned __int8)init_msg[2] | (((unsigned __int8)init_msg[1] | ((unsigned __int8)*init_msg << 8)) << 8);
      init_msg += 3;
      if ( v9 + 3 != v4 )
      {
        v7 = 50;
        ERR_put_error((int)v2, 0x14u, 144, 159, ".\\ssl\\s3_clnt.c", 1013);
        goto LABEL_36;
      }
      v10 = 0;
      if ( v9 )
      {
        while ( 1 )
        {
          v11 = (const unsigned __int8 *)((unsigned __int8)init_msg[2]
                                        | (((unsigned __int8)init_msg[1] | ((unsigned __int8)*init_msg << 8)) << 8));
          init_msg += 3;
          v32 = (unsigned int)&v11[v10 + 3];
          if ( v32 > v9 )
          {
            v7 = 50;
            ERR_put_error((int)v2, 0x14u, 144, 135, ".\\ssl\\s3_clnt.c", 1022);
            goto LABEL_36;
          }
          s = (ssl_st *)init_msg;
          v12 = (char *)d2i_X509(0, (unsigned __int8 **)&s, v11);
          a = (x509_st *)v12;
          if ( !v12 )
          {
            v7 = 42;
            ERR_put_error((int)v2, 0x14u, 144, 13, ".\\ssl\\s3_clnt.c", 1031);
            goto LABEL_36;
          }
          if ( s != (ssl_st *)&v11[(_DWORD)init_msg] )
          {
            v7 = 50;
            ERR_put_error((int)v2, 0x14u, 144, 135, ".\\ssl\\s3_clnt.c", 1037);
            goto LABEL_36;
          }
          if ( !sk_push(st, v12) )
            break;
          v10 = v32;
          init_msg = (char *)s;
          a = 0;
          if ( v32 >= v9 )
          {
            v8 = (stack_st_X509 *)st;
            goto LABEL_19;
          }
        }
        ERR_put_error((int)v2, 0x14u, 144, 65, ".\\ssl\\s3_clnt.c", 1042);
        goto err_219;
      }
LABEL_19:
      v13 = ssl_verify_cert_chain(v2, v8);
      if ( v2->verify_mode && v13 <= 0 )
      {
        v14 = ssl_verify_alarm_type(v2->verify_result);
        ERR_put_error((int)v2, 0x14u, 144, 134, ".\\ssl\\s3_clnt.c", 1059);
        ssl3_send_alert(v2, 2, v14);
err_219:
        EVP_PKEY_free((int)init_msg, x);
        X509_free(a);
        sk_pop_free(st, (void (__cdecl *)(void *))X509_free);
        return v30;
      }
      ERR_clear_error((int)v2);
      v15 = ssl_sess_cert_new();
      if ( !v15 )
        goto err_219;
      session = v2->session;
      if ( session->sess_cert )
        ssl_sess_cert_free(session->sess_cert);
      v2->session->sess_cert = v15;
      v15->cert_chain = (stack_st_X509 *)st;
      init_msg = sk_value(st, 0);
      st = 0;
      pubkey = X509_get_pubkey((x509_st *)init_msg);
      new_cipher = v2->s3->tmp.new_cipher;
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
          v25 = 1096;
          a = 0;
          v24 = 239;
          goto LABEL_35;
        }
      }
      v19 = ssl_cert_type((x509_st *)init_msg, pubkey);
      v20 = v19;
      if ( aa )
      {
        if ( v19 < 0 )
        {
          v25 = 1106;
          a = 0;
          v24 = 247;
LABEL_35:
          v7 = 2;
          ERR_put_error((int)v2, 0x14u, 144, v24, ".\\ssl\\s3_clnt.c", v25);
          goto LABEL_36;
        }
        v15->peer_cert_type = v19;
        CRYPTO_add_lock((int *)init_msg + 4, 1, 3, ".\\ssl\\s3_clnt.c", 1113);
        x509 = v15->peer_pkeys[v20].x509;
        v22 = &v15->peer_pkeys[v20];
        if ( x509 )
          X509_free(x509);
        v22->x509 = (x509_st *)init_msg;
        v15->peer_key = v22;
        v23 = v2->session;
        if ( v23->peer )
          X509_free(v23->peer);
        CRYPTO_add_lock((int *)init_msg + 4, 1, 3, ".\\ssl\\s3_clnt.c", 1123);
        v2->session->peer = (x509_st *)init_msg;
      }
      else
      {
        v15->peer_cert_type = v19;
        v15->peer_key = 0;
        if ( v2->session->peer )
          X509_free(v2->session->peer);
        v2->session->peer = 0;
      }
      v2->session->verify_result = v2->verify_result;
      a = 0;
      v30 = 1;
      goto err_219;
    }
    s3->tmp.reuse_message = 1;
    return 1;
  }
  return result;
}
