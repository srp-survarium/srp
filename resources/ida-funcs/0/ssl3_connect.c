// positive sp value has been detected, the output may be wrong!
int __usercall ssl3_connect@<eax>(int a1@<ebx>, ssl_st *s)
{
  void (__cdecl *info_callback)(const ssl_st *, int, int); // edi
  void *v3; // esp
  ssl_ctx_st *ctx; // ecx
  int state; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  bool v9; // zf
  bio_st *v10; // edx
  ssl3_state_st *v11; // eax
  int server_hello; // edi
  bio_st *bbio; // eax
  bio_st *wbio; // ecx
  int v15; // eax
  int v16; // ecx
  const ssl_cipher_st *new_cipher; // eax
  ssl3_state_st *s3; // eax
  ssl3_state_st *v19; // eax
  ssl3_state_st *v20; // eax
  ssl3_state_st *v21; // ecx
  ssl_session_st *session; // edx
  const ssl_comp_st *new_compression; // eax
  ssl3_state_st *v24; // eax
  ssl3_state_st *v25; // eax
  ssl_ctx_st *v26; // eax
  buf_mem_st *v27; // eax
  ssl_ctx_st *v28; // eax
  int v29; // edi
  ssl_ctx_st *v30; // eax
  void (__cdecl *v32)(const ssl_st *, int, int); // [esp+Ch] [ebp-10h]
  int v33; // [esp+10h] [ebp-Ch]
  buf_mem_st *v34; // [esp+14h] [ebp-8h]
  int v35; // [esp+18h] [ebp-4h] BYREF

  v32 = 0;
  v33 = _time64(0);
  info_callback = 0;
  v3 = alloca(8);
  RAND_add(0, &v35, 4, 0.0);
  ERR_clear_error(a1);
  SetLastError(0);
  if ( s->info_callback )
  {
    info_callback = s->info_callback;
    v32 = info_callback;
  }
  else
  {
    ctx = s->ctx;
    if ( ctx->info_callback )
    {
      info_callback = ctx->info_callback;
      v32 = info_callback;
    }
  }
  ++s->in_handshake;
  if ( (SSL_state(s) & 0x3000) == 0 || (SSL_state(s) & 0x4000) != 0 )
    SSL_clear(a1, s);
  while ( 1 )
  {
    state = s->state;
    v6 = state;
    if ( state > 4352 )
    {
      if ( state > 12292 )
      {
        if ( state != 0x4000 )
        {
          v9 = state == 20480;
          goto LABEL_71;
        }
LABEL_72:
        s->server = 0;
        if ( info_callback )
          info_callback(s, 16, 1);
        if ( (s->version & 0xFF00) != 0x300 )
        {
          ERR_put_error(v6, 0x14u, 132, 68, ".\\ssl\\s3_clnt.c", 224);
          goto LABEL_101;
        }
        s->type = 4096;
        if ( !s->init_buf )
        {
          v27 = BUF_MEM_new(v6);
          info_callback = (void (__cdecl *)(const ssl_st *, int, int))v27;
          v34 = v27;
          if ( !v27 || !BUF_MEM_grow(v27, 0x4000u) )
            goto LABEL_101;
          s->init_buf = (buf_mem_st *)info_callback;
          v34 = 0;
        }
        if ( !ssl3_setup_buffers(s) || !ssl_init_wbio_buffer(v6, s, 0) )
          goto LABEL_101;
        ssl3_init_finished_mac((int)info_callback, s);
        v28 = s->ctx;
        s->state = 4368;
        ++v28->stats.sess_connect;
      }
      else
      {
        if ( state == 12292 )
        {
          v26 = s->ctx;
          s->new_session = 1;
          s->state = 4096;
          ++v26->stats.sess_connect_renegotiate;
          goto LABEL_72;
        }
        switch ( state )
        {
          case 4368:
          case 4369:
            s->shutdown = 0;
            server_hello = ssl3_client_hello((int)info_callback, s);
            if ( server_hello <= 0 )
              goto end_17;
            bbio = s->bbio;
            wbio = s->wbio;
            s->state = 4384;
            s->init_num = 0;
            if ( bbio != wbio )
              s->wbio = BIO_push(v6, bbio, wbio);
            goto LABEL_83;
          case 4384:
          case 4385:
            server_hello = ssl3_get_server_hello(s);
            if ( server_hello <= 0 )
              goto end_17;
            s->state = s->hit != 0 ? 4560 : 4400;
            break;
          case 4400:
          case 4401:
            v15 = ssl3_check_finished(s);
            server_hello = v15;
            if ( v15 <= 0 )
              goto end_17;
            if ( v15 == 2 )
            {
              v16 = s->tlsext_ticket_expected != 0 ? 4576 : 4560;
              s->hit = 1;
              s->state = v16;
            }
            else
            {
              new_cipher = s->s3->tmp.new_cipher;
              if ( (new_cipher->algorithm_auth & 4) != 0 || (new_cipher->algorithm_mkey & 0x100) != 0 )
              {
                v33 = 1;
                s->state = 4416;
              }
              else
              {
                server_hello = ssl3_get_server_certificate((char *)server_hello, s);
                if ( server_hello <= 0 )
                  goto end_17;
                s->state = s->tlsext_status_expected != 0 ? 4592 : 4416;
              }
            }
            break;
          case 4416:
          case 4417:
            server_hello = ssl3_get_key_exchange(s);
            if ( server_hello <= 0 )
              goto end_17;
            s->state = 4432;
            s->init_num = 0;
            if ( ssl3_check_cert_and_algorithm(s) )
              goto LABEL_83;
            goto LABEL_101;
          case 4432:
          case 4433:
            server_hello = ssl3_get_certificate_request(s);
            if ( server_hello <= 0 )
              goto end_17;
            s->state = 4448;
            break;
          case 4448:
          case 4449:
            server_hello = ssl3_get_server_done(state, s);
            if ( server_hello <= 0 )
              goto end_17;
            s->state = s->s3->tmp.cert_req != 0 ? 4464 : 4480;
            break;
          case 4464:
          case 4465:
          case 4466:
          case 4467:
            server_hello = ssl3_send_client_certificate(state, s);
            if ( server_hello <= 0 )
              goto end_17;
            s->state = 4480;
            break;
          case 4480:
          case 4481:
            server_hello = ssl3_send_client_key_exchange(state, s);
            if ( server_hello <= 0 )
              goto end_17;
            s3 = s->s3;
            if ( s3->tmp.cert_req == 1 )
            {
              s->state = 4496;
            }
            else
            {
              s->state = 4512;
              s3->change_cipher_spec = 0;
            }
            v19 = s->s3;
            if ( (v19->flags & 0x10) != 0 )
            {
              s->state = 4512;
              v19->change_cipher_spec = 0;
            }
            break;
          case 4496:
          case 4497:
            server_hello = ssl3_send_client_verify(s);
            if ( server_hello <= 0 )
              goto end_17;
            v20 = s->s3;
            s->state = 4512;
            s->init_num = 0;
            v20->change_cipher_spec = 0;
            goto LABEL_83;
          case 4512:
          case 4513:
            server_hello = ssl3_send_change_cipher_spec(s, 4512, 4513);
            if ( server_hello <= 0 )
              goto end_17;
            v21 = s->s3;
            session = s->session;
            s->state = 4528;
            s->init_num = 0;
            session->cipher = v21->tmp.new_cipher;
            new_compression = s->s3->tmp.new_compression;
            if ( new_compression )
              s->session->compress_meth = new_compression->id;
            else
              s->session->compress_meth = 0;
            if ( s->method->ssl3_enc->setup_key_block(s) && s->method->ssl3_enc->change_cipher_state(s, 18) )
              goto LABEL_83;
            goto LABEL_101;
          case 4528:
          case 4529:
            server_hello = ssl3_send_finished(
                             s,
                             4528,
                             4529,
                             s->method->ssl3_enc->client_finished_label,
                             s->method->ssl3_enc->client_finished_label_len);
            if ( server_hello <= 0 )
              goto end_17;
            v24 = s->s3;
            s->state = 4352;
            v24->flags &= ~4u;
            if ( s->hit )
            {
              s->s3->tmp.next_state = 3;
              v25 = s->s3;
              if ( (v25->flags & 2) != 0 )
              {
                s->state = 3;
                v25->flags |= 4u;
                s->s3->delay_buf_pop_ret = 0;
              }
            }
            else if ( s->tlsext_ticket_expected )
            {
              s->s3->tmp.next_state = 4576;
            }
            else
            {
              s->s3->tmp.next_state = 4560;
            }
            break;
          case 4560:
          case 4561:
            server_hello = ssl3_get_finished(s, 4560, 4561);
            if ( server_hello <= 0 )
              goto end_17;
            s->state = s->hit != 0 ? 4512 : 3;
            break;
          case 4576:
          case 4577:
            server_hello = ssl3_get_new_session_ticket((engine_st *)state, s);
            if ( server_hello <= 0 )
              goto end_17;
            s->state = 4560;
            break;
          case 4592:
          case 4593:
            server_hello = ssl3_get_cert_status(state, s);
            if ( server_hello <= 0 )
              goto end_17;
            s->state = 4416;
            break;
          default:
            goto LABEL_99;
        }
      }
      s->init_num = 0;
      goto LABEL_83;
    }
    if ( state != 4352 )
      break;
    v10 = s->wbio;
    s->rwstate = 2;
    if ( BIO_ctrl(state, v10, 11, 0, 0) <= 0 )
      goto LABEL_101;
    v11 = s->s3;
    s->rwstate = 1;
    s->state = v11->tmp.next_state;
LABEL_83:
    if ( !s->s3->tmp.reuse_message && !v33 )
    {
      if ( s->debug )
      {
        server_hello = BIO_ctrl(v6, s->wbio, 11, 0, 0);
        if ( server_hello <= 0 )
          goto end_17;
      }
      if ( v32 )
      {
        v29 = s->state;
        if ( v29 != v6 )
        {
          s->state = v6;
          v32(s, 4097, 1);
          s->state = v29;
        }
      }
    }
    info_callback = v32;
    v33 = 0;
  }
  v7 = state - 3;
  if ( v7 )
  {
    v8 = v7 - 4093;
    if ( v8 )
    {
      v9 = v8 == 3;
LABEL_71:
      if ( !v9 )
      {
LABEL_99:
        ERR_put_error(v6, 0x14u, 132, 255, ".\\ssl\\s3_clnt.c", 565);
LABEL_101:
        server_hello = -1;
        goto end_17;
      }
    }
    goto LABEL_72;
  }
  ssl3_cleanup_key_block(s);
  if ( s->init_buf )
  {
    BUF_MEM_free(s->init_buf);
    s->init_buf = 0;
  }
  if ( (s->s3->flags & 4) == 0 )
    ssl_free_wbio_buffer((int)info_callback, v6, s);
  s->init_num = 0;
  s->new_session = 0;
  ssl_update_cache(s, 1);
  if ( s->hit )
    ++s->ctx->stats.sess_hit;
  v30 = s->ctx;
  server_hello = 1;
  s->handshake_func = ssl3_connect;
  ++v30->stats.sess_connect_good;
  if ( v32 )
    v32(s, 32, 1);
end_17:
  --s->in_handshake;
  if ( v34 )
    BUF_MEM_free(v34);
  if ( v32 )
    v32(s, 4098, server_hello);
  return server_hello;
}
