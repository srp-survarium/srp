int __cdecl ssl3_client_hello(ssl_st *s)
{
  char *data; // ebx
  ssl_session_st *session; // eax
  unsigned __int8 *client_random; // esi
  int v5; // eax
  _BYTE *v6; // ebx
  unsigned __int8 *v7; // esi
  _BYTE *v8; // ebx
  int session_id_length; // eax
  unsigned __int8 *v10; // ebx
  stack_st_SSL_CIPHER *ciphers; // eax
  int v12; // eax
  unsigned __int8 *v13; // esi
  ssl_ctx_st *ctx; // edx
  int v15; // ebx
  char *v16; // esi
  int i; // edi
  unsigned __int8 *v18; // eax
  int v20; // [esp-4h] [ebp-1Ch]
  char *v21; // [esp+10h] [ebp-8h]
  _BYTE *v22; // [esp+14h] [ebp-4h]
  unsigned int sa; // [esp+1Ch] [ebp+4h]

  data = s->init_buf->data;
  v21 = data;
  if ( s->state == 4368 )
  {
    session = s->session;
    if ( (!session
       || session->ssl_version != s->version
       || !session->session_id_length && !session->tlsext_tick
       || session->not_resumable)
      && !ssl_get_new_session(s, 0) )
    {
      return -1;
    }
    client_random = s->s3->client_random;
    v5 = _time64(0);
    *client_random++ = HIBYTE(v5);
    *client_random++ = BYTE2(v5);
    *client_random = BYTE1(v5);
    client_random[1] = v5;
    if ( RAND_pseudo_bytes() <= 0 )
      return -1;
    v6 = data + 4;
    *v6 = BYTE1(s->version);
    v6[1] = s->version;
    v22 = v6;
    v6 += 2;
    v7 = s->s3->client_random;
    s->client_version = s->version;
    qmemcpy(v6, v7, 0x20u);
    v8 = v6 + 32;
    if ( s->new_session )
    {
      session_id_length = 0;
      sa = 0;
    }
    else
    {
      sa = s->session->session_id_length;
      session_id_length = s->session->session_id_length;
    }
    *v8 = session_id_length;
    v10 = v8 + 1;
    if ( session_id_length )
    {
      if ( session_id_length > 32 )
      {
        v20 = 656;
LABEL_28:
        ERR_put_error(0x14u, 131, 68, ".\\ssl\\s3_clnt.c", v20);
        return -1;
      }
      memcpy(v10, s->session->session_id, session_id_length);
      v10 += sa;
    }
    ciphers = SSL_get_ciphers(s);
    v12 = ssl_cipher_list_to_bytes(s, ciphers, v10 + 2, 0);
    if ( !v12 )
    {
      ERR_put_error(0x14u, 131, 181, ".\\ssl\\s3_clnt.c", 667);
      return -1;
    }
    *v10 = BYTE1(v12);
    v10[1] = v12;
    v13 = &v10[v12 + 2];
    if ( ((unsigned int)&loc_20000 & s->options) != 0 || (ctx = s->ctx, !ctx->comp_methods) )
      v15 = 0;
    else
      v15 = sk_num(&ctx->comp_methods->stack);
    *v13 = v15 + 1;
    v16 = (char *)(v13 + 1);
    for ( i = 0; i < v15; ++v16 )
      *v16 = *sk_value(&s->ctx->comp_methods->stack, i++);
    *v16 = 0;
    if ( ssl_prepare_clienthello_tlsext(s) <= 0 )
    {
      ERR_put_error(0x14u, 131, 226, ".\\ssl\\s3_clnt.c", 696);
      return -1;
    }
    v18 = ssl_add_clienthello_tlsext(s, (unsigned __int8 *)v16 + 1, (unsigned __int8 *)v21 + 0x4000);
    if ( !v18 )
    {
      v20 = 701;
      goto LABEL_28;
    }
    *v21 = 1;
    v21[1] = (unsigned int)(v18 - v22) >> 16;
    v21[2] = (unsigned __int16)((_WORD)v18 - (_WORD)v22) >> 8;
    v21[3] = (_BYTE)v18 - (_BYTE)v22;
    s->state = 4369;
    s->init_num = v18 - (unsigned __int8 *)v21;
    s->init_off = 0;
  }
  return ssl3_do_write(s, 22);
}
