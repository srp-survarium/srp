int __usercall get_server_hello@<eax>(ssl_st *s@<esi>)
{
  char *data; // ebx
  int v2; // eax
  int v4; // ecx
  unsigned int v5; // ebp
  int init_num; // eax
  unsigned int v7; // edi
  int v8; // eax
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  unsigned __int8 *v10; // edi
  ssl2_state_st *s2; // eax
  ssl2_state_st *v12; // eax
  unsigned __int8 *v13; // edi
  int csl; // eax
  stack_st_SSL_CIPHER *v15; // eax
  stack_st_SSL_CIPHER *v16; // ebx
  stack_st_SSL_CIPHER *ciphers; // ebp
  const stack_st *p_stack; // edi
  int i; // ebx
  char *v20; // eax
  ssl_session_st *session; // eax
  ssl_session_st *v22; // eax
  sess_cert_st *sess_cert; // ecx
  ssl2_state_st *v24; // eax
  unsigned __int8 *v25; // [esp+4h] [ebp-4h]

  data = s->init_buf->data;
  if ( s->state != 4128 )
    goto LABEL_12;
  v2 = ssl2_read(s, &data[s->init_num], 11 - s->init_num);
  if ( v2 < 11 - s->init_num )
    return ssl2_part_read(s, 0x6Du, v2);
  s->init_num = 11;
  if ( *data == 4 )
  {
    s->hit = data[1] != 0;
    s->s2->tmp.cert_type = (unsigned __int8)data[2];
    v4 = (unsigned __int8)data[4] | ((unsigned __int8)data[3] << 8);
    if ( v4 < s->version )
      s->version = v4;
    s->s2->tmp.cert_length = (unsigned __int8)data[6] | ((unsigned __int8)data[5] << 8);
    s->s2->tmp.csl = (unsigned __int8)data[8] | ((unsigned __int8)data[7] << 8);
    s->s2->tmp.conn_id_length = (unsigned __int8)data[10] | ((unsigned __int8)data[9] << 8);
    s->state = 4129;
LABEL_12:
    v5 = s->s2->tmp.cert_length + s->s2->tmp.csl + s->s2->tmp.conn_id_length + 11;
    if ( v5 > 0x3FFF )
    {
      ERR_put_error(0x14u, 109, 296, ".\\ssl\\s2_clnt.c", 382);
      return -1;
    }
    init_num = s->init_num;
    v7 = v5 - init_num;
    v8 = ssl2_read(s, &data[init_num], v5 - init_num);
    if ( v8 != v7 )
      return ssl2_part_read(s, 0x6Du, v8);
    msg_callback = s->msg_callback;
    if ( msg_callback )
      msg_callback(0, s->version, 0, data, v5, s, s->msg_callback_arg);
    v10 = (unsigned __int8 *)(data + 11);
    if ( s->hit )
    {
      s2 = s->s2;
      if ( s2->tmp.cert_length )
      {
        ERR_put_error(0x14u, 109, 216, ".\\ssl\\s2_clnt.c", 398);
        return -1;
      }
      if ( s2->tmp.cert_type && (s->options & 0x10) == 0 )
      {
        ERR_put_error(0x14u, 109, 217, ".\\ssl\\s2_clnt.c", 406);
        return -1;
      }
      if ( s2->tmp.csl )
      {
        ERR_put_error(0x14u, 109, 218, ".\\ssl\\s2_clnt.c", 412);
        return -1;
      }
    }
    else
    {
      if ( s->session->session_id_length && !ssl_get_new_session(s, 0) )
      {
        ssl2_return_error(s, 0);
        return -1;
      }
      if ( ssl2_set_certificate(s, s->s2->tmp.cert_type, s->s2->tmp.cert_length, (unsigned __int8 *)data + 11) <= 0 )
      {
        ssl2_return_error(s, 4);
        return -1;
      }
      v12 = s->s2;
      v13 = &v10[v12->tmp.cert_length];
      csl = v12->tmp.csl;
      if ( !csl )
      {
        ssl2_return_error(s, 1);
        ERR_put_error(0x14u, 109, 184, ".\\ssl\\s2_clnt.c", 450);
        return -1;
      }
      v15 = ssl_bytes_to_cipher_list(s, v13, csl, &s->session->ciphers);
      v16 = v15;
      v25 = &v13[s->s2->tmp.csl];
      if ( !v15 )
      {
        ssl2_return_error(s, 0);
        ERR_put_error(0x14u, 109, 65, ".\\ssl\\s2_clnt.c", 465);
        return -1;
      }
      sk_set_cmp_func(&v15->stack, (int (__cdecl *)(const void *, const void *))ssl_cipher_ptr_id_cmp);
      ciphers = SSL_get_ciphers(s);
      sk_set_cmp_func(&ciphers->stack, (int (__cdecl *)(const void *, const void *))ssl_cipher_ptr_id_cmp);
      if ( ((unsigned int)Scaleform::GFx::AS2::CreateShadow & s->options) != 0 )
      {
        p_stack = &v16->stack;
      }
      else
      {
        p_stack = &ciphers->stack;
        ciphers = v16;
      }
      for ( i = 0; i < sk_num(p_stack); ++i )
      {
        v20 = sk_value(p_stack, i);
        if ( sk_find(&ciphers->stack, v20) >= 0 )
          break;
      }
      if ( i >= sk_num(p_stack) )
      {
        ssl2_return_error(s, 1);
        ERR_put_error(0x14u, 109, 185, ".\\ssl\\s2_clnt.c", 505);
        return -1;
      }
      s->session->cipher = (const ssl_cipher_st *)sk_value(p_stack, i);
      session = s->session;
      if ( session->peer )
      {
        ssl2_return_error(s, 0);
        ERR_put_error(0x14u, 109, 68, ".\\ssl\\s2_clnt.c", 514);
        return -1;
      }
      session->peer = session->sess_cert->peer_key->x509;
      CRYPTO_add_lock(&s->session->peer->references, 1, 3, ".\\ssl\\s2_clnt.c", 520);
      v10 = v25;
    }
    v22 = s->session;
    sess_cert = v22->sess_cert;
    if ( sess_cert && v22->peer == sess_cert->peer_key->x509 )
    {
      s->s2->conn_id_length = s->s2->tmp.conn_id_length;
      v24 = s->s2;
      if ( v24->conn_id_length <= 0x10 )
      {
        memcpy(v24->conn_id, v10, v24->tmp.conn_id_length);
        return 1;
      }
      else
      {
        ssl2_return_error(s, 0);
        ERR_put_error(0x14u, 109, 299, ".\\ssl\\s2_clnt.c", 536);
        return -1;
      }
    }
    ssl2_return_error(s, 0);
    ERR_put_error(0x14u, 109, 68, ".\\ssl\\s2_clnt.c", 528);
    return -1;
  }
  if ( *data )
  {
    ssl2_return_error(s, 0);
    ERR_put_error(0x14u, 109, 212, ".\\ssl\\s2_clnt.c", 355);
  }
  else
  {
    ERR_put_error(0x14u, 109, 200, ".\\ssl\\s2_clnt.c", 359);
  }
  return -1;
}
