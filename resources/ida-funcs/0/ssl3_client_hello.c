int __usercall ssl3_client_hello@<eax>(int a1@<edi>, ssl_st *s)
{
  char *data; // ebx
  ssl_session_st *session; // eax
  unsigned __int8 *client_random; // esi
  int v6; // eax
  _BYTE *v7; // ebx
  unsigned __int8 *v8; // esi
  _BYTE *v9; // ebx
  int session_id_length; // eax
  _BYTE *v11; // ebx
  stack_st_SSL_CIPHER *ciphers; // eax
  int v13; // eax
  _BYTE *v14; // esi
  ssl_ctx_st *ctx; // edx
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
    v6 = _time64(0);
    *client_random++ = HIBYTE(v6);
    *client_random++ = BYTE2(v6);
    *client_random = BYTE1(v6);
    client_random[1] = v6;
    if ( RAND_pseudo_bytes(a1) <= 0 )
      return -1;
    v7 = data + 4;
    *v7 = BYTE1(s->version);
    v7[1] = s->version;
    v22 = v7;
    v7 += 2;
    v8 = s->s3->client_random;
    s->client_version = s->version;
    qmemcpy(v7, v8, 0x20u);
    v9 = v7 + 32;
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
    *v9 = session_id_length;
    v11 = v9 + 1;
    if ( session_id_length )
    {
      if ( session_id_length > 32 )
      {
        v20 = 656;
LABEL_28:
        ERR_put_error((int)v11, 0x14u, 131, 68, ".\\ssl\\s3_clnt.c", v20);
        return -1;
      }
      memcpy((int)v11, (const __m128i *)s->session->session_id, session_id_length);
      v11 += sa;
    }
    ciphers = SSL_get_ciphers(s);
    v13 = ssl_cipher_list_to_bytes(s, ciphers, v11 + 2, 0);
    if ( !v13 )
    {
      ERR_put_error((int)v11, 0x14u, 131, 181, ".\\ssl\\s3_clnt.c", 667);
      return -1;
    }
    *v11 = BYTE1(v13);
    v11[1] = v13;
    v14 = &v11[v13 + 2];
    if ( ((unsigned int)&loc_20000 & s->options) != 0 || (ctx = s->ctx, !ctx->comp_methods) )
      v11 = 0;
    else
      v11 = (_BYTE *)sk_num(&ctx->comp_methods->stack);
    *v14 = (_BYTE)v11 + 1;
    v16 = v14 + 1;
    for ( i = 0; i < (int)v11; ++v16 )
      *v16 = *sk_value(&s->ctx->comp_methods->stack, i++);
    *v16 = 0;
    if ( ssl_prepare_clienthello_tlsext(s) <= 0 )
    {
      ERR_put_error((int)v11, 0x14u, 131, 226, ".\\ssl\\s3_clnt.c", 696);
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
