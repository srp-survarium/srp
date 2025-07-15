int __cdecl ssl3_get_client_certificate(ssl_st *s)
{
  ssl_st *v1; // ebx
  int result; // eax
  int v3; // esi
  ssl3_state_st *s3; // eax
  int message_type; // ecx
  int verify_mode; // ecx
  stack_st_X509 *v7; // ebp
  unsigned int v8; // edi
  ssl_st *v9; // eax
  unsigned int v10; // ecx
  const unsigned __int8 *v11; // esi
  ssl_st *v12; // eax
  unsigned int v13; // ebp
  char *v14; // eax
  int v15; // eax
  int v16; // esi
  ssl_session_st *session; // ecx
  stack_st **sess_cert; // eax
  stack_st *st; // [esp+Ch] [ebp-14h]
  x509_st *a; // [esp+10h] [ebp-10h]
  int v21; // [esp+18h] [ebp-8h] BYREF
  ssl_st *v22; // [esp+1Ch] [ebp-4h]

  v1 = s;
  a = 0;
  st = 0;
  result = s->method->ssl_get_message(s, 8576, 8577, -1, s->max_cert_list, &v21);
  v3 = result;
  if ( !v21 )
    return result;
  s3 = v1->s3;
  message_type = s3->tmp.message_type;
  if ( message_type == 16 )
  {
    verify_mode = v1->verify_mode;
    if ( (verify_mode & 1) == 0 || (verify_mode & 2) == 0 )
    {
      if ( v1->version <= 768 || !s3->tmp.cert_request )
      {
        s3->tmp.reuse_message = 1;
        return 1;
      }
      ERR_put_error((int)v1, 0x14u, 137, 233, ".\\ssl\\s3_srvr.c", 2916);
      ssl3_send_alert(v1, 2, 10);
      goto err_230;
    }
    ERR_put_error((int)v1, 0x14u, 137, 199, ".\\ssl\\s3_srvr.c", 2909);
    goto LABEL_6;
  }
  if ( message_type != 11 )
  {
    ERR_put_error((int)v1, 0x14u, 137, 262, ".\\ssl\\s3_srvr.c", 2927);
    ssl3_send_alert(v1, 2, 10);
    goto err_230;
  }
  s = (ssl_st *)v1->init_msg;
  v7 = (stack_st_X509 *)sk_new_null();
  st = &v7->stack;
  if ( !v7 )
  {
    ERR_put_error((int)v1, 0x14u, 137, 65, ".\\ssl\\s3_srvr.c", 2934);
    goto LABEL_34;
  }
  v8 = BYTE2(s->version) | (((LOBYTE(s->version) << 8) | BYTE1(s->version)) << 8);
  v9 = (ssl_st *)((char *)&s->version + 3);
  s = (ssl_st *)((char *)s + 3);
  if ( v8 + 3 != v3 )
  {
    ERR_put_error((int)v1, 0x14u, 137, 159, ".\\ssl\\s3_srvr.c", 2942);
    ssl3_send_alert(v1, 2, 50);
    goto err_230;
  }
  v10 = 0;
  if ( v8 )
  {
    while ( 1 )
    {
      v11 = (const unsigned __int8 *)(BYTE2(v9->version) | (((LOBYTE(v9->version) << 8) | BYTE1(v9->version)) << 8));
      v12 = (ssl_st *)((char *)&v9->version + 3);
      v13 = (unsigned int)&v11[v10 + 3];
      s = v12;
      if ( v13 > v8 )
      {
        ERR_put_error((int)v1, 0x14u, 137, 135, ".\\ssl\\s3_srvr.c", 2951);
LABEL_30:
        ssl3_send_alert(v1, 2, 50);
        goto err_230;
      }
      v22 = v12;
      v14 = (char *)d2i_X509(0, (unsigned __int8 **)&s, v11);
      a = (x509_st *)v14;
      if ( !v14 )
        break;
      if ( s != (ssl_st *)((char *)v22 + (_DWORD)v11) )
      {
        ERR_put_error((int)v1, 0x14u, 137, 135, ".\\ssl\\s3_srvr.c", 2965);
        goto LABEL_30;
      }
      if ( !sk_push(st, v14) )
      {
        ERR_put_error((int)v1, 0x14u, 137, 65, ".\\ssl\\s3_srvr.c", 2970);
        goto err_230;
      }
      v10 = v13;
      a = 0;
      if ( v13 >= v8 )
      {
        v7 = (stack_st_X509 *)st;
        goto LABEL_19;
      }
      v9 = s;
    }
    ERR_put_error((int)v1, 0x14u, 137, 13, ".\\ssl\\s3_srvr.c", 2959);
    goto err_230;
  }
LABEL_19:
  if ( sk_num(&v7->stack) > 0 )
  {
    if ( ssl_verify_cert_chain(v1, v7) <= 0 )
    {
      v16 = ssl_verify_alarm_type(v1->verify_result);
      ERR_put_error((int)v1, 0x14u, 137, 178, ".\\ssl\\s3_srvr.c", 3001);
      ssl3_send_alert(v1, 2, v16);
      goto err_230;
    }
  }
  else
  {
    if ( v1->version == 768 )
    {
      ERR_put_error((int)v1, 0x14u, 137, 176, ".\\ssl\\s3_srvr.c", 2983);
      ssl3_send_alert(v1, 2, 40);
err_230:
      if ( a )
        X509_free(a);
      goto LABEL_34;
    }
    v15 = v1->verify_mode;
    if ( (v15 & 1) != 0 && (v15 & 2) != 0 )
    {
      ERR_put_error((int)v1, 0x14u, 137, 199, ".\\ssl\\s3_srvr.c", 2990);
LABEL_6:
      ssl3_send_alert(v1, 2, 40);
      goto err_230;
    }
  }
  session = v1->session;
  if ( session->peer )
    X509_free(session->peer);
  v1->session->peer = (x509_st *)sk_shift(&v7->stack);
  v1->session->verify_result = v1->verify_result;
  if ( !v1->session->sess_cert )
  {
    v1->session->sess_cert = ssl_sess_cert_new();
    if ( !v1->session->sess_cert )
    {
      ERR_put_error((int)v1, 0x14u, 137, 65, ".\\ssl\\s3_srvr.c", 3018);
LABEL_34:
      if ( st )
        sk_pop_free(st, (void (__cdecl *)(void *))X509_free);
      return -1;
    }
  }
  sess_cert = (stack_st **)v1->session->sess_cert;
  if ( *sess_cert )
    sk_pop_free(*sess_cert, (void (__cdecl *)(void *))X509_free);
  v1->session->sess_cert->cert_chain = v7;
  return 1;
}
