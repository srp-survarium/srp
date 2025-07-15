// positive sp value has been detected, the output may be wrong!
int __cdecl ssl2_accept(ssl_st *s)
{
  void (__cdecl *v1)(const ssl_st *, int, int); // ebx
  void *v2; // esp
  int client_hello; // edi
  void (__cdecl *info_callback)(const ssl_st *, int, int); // eax
  int state; // eax
  int v8; // eax
  int v9; // edx
  int verify_mode; // eax
  ssl_ctx_st *ctx; // eax
  bio_st *wbio; // [esp-10h] [ebp-24h]
  int v13; // [esp+10h] [ebp-4h] BYREF
  int buf; // [esp+18h] [ebp+4h]

  _time64(0);
  v1 = 0;
  v2 = alloca(8);
  RAND_add(&v13, 4, 0.0);
  ERR_clear_error();
  client_hello = (int)SetLastError;
  SetLastError(0);
  info_callback = s->info_callback;
  if ( info_callback || (info_callback = s->ctx->info_callback) != 0 )
    v1 = info_callback;
  ++s->in_handshake;
  if ( (SSL_state(s) & 0x3000) == 0 || (SSL_state(s) & 0x4000) != 0 )
    SSL_clear(s);
  if ( !s->cert )
  {
    ERR_put_error(0x14u, 122, 179, ".\\ssl\\s2_srvr.c", 169);
    return -1;
  }
  SetLastError(0);
  while ( 1 )
  {
    state = s->state;
    buf = state;
    if ( state <= 0x2000 )
      break;
    if ( state > 0x4000 )
    {
      if ( state != 24576 )
        goto LABEL_52;
    }
    else if ( state != 0x4000 )
    {
      switch ( state )
      {
        case 8195:
          goto $LN35_6;
        case 8208:
        case 8209:
        case 8210:
          s->shutdown = 0;
          client_hello = get_client_hello(s);
          if ( client_hello <= 0 )
            goto end_16;
          s->init_num = 0;
          s->state = 8224;
          goto LABEL_49;
        case 8224:
        case 8225:
          client_hello = server_hello(s);
          if ( client_hello <= 0 )
            goto end_16;
          v8 = s->hit != 0 ? 8320 : 8240;
          s->init_num = 0;
          s->state = v8;
          goto LABEL_49;
        case 8240:
        case 8241:
          client_hello = get_client_master_key(s);
          if ( client_hello <= 0 )
            goto end_16;
          s->init_num = 0;
          s->state = 8320;
          goto LABEL_49;
        case 8256:
        case 8257:
          client_hello = server_verify(s);
          if ( client_hello <= 0 )
            goto end_16;
          v9 = s->hit != 0 ? 8258 : 8272;
          s->init_num = 0;
          s->state = v9;
          goto LABEL_49;
        case 8258:
          if ( BIO_ctrl(s->wbio, 3, 0, 0) <= 0 )
            goto LABEL_31;
          wbio = s->wbio;
          s->rwstate = 2;
          if ( BIO_ctrl(wbio, 11, 0, 0) <= 0 )
            goto LABEL_53;
          s->rwstate = 1;
LABEL_31:
          s->wbio = BIO_pop(s->wbio);
          s->state = 8272;
          break;
        case 8272:
        case 8273:
          client_hello = get_client_finished(s);
          if ( client_hello <= 0 )
            goto end_16;
          s->init_num = 0;
          s->state = 8304;
          goto LABEL_49;
        case 8288:
        case 8289:
          client_hello = server_finish(s);
          if ( client_hello <= 0 )
            goto end_16;
          s->init_num = 0;
          s->state = 3;
          goto LABEL_49;
        case 8304:
        case 8305:
        case 8306:
        case 8307:
          verify_mode = s->verify_mode;
          if ( (verify_mode & 1) == 0 || s->session->peer && (verify_mode & 4) != 0 )
            goto LABEL_39;
          client_hello = request_certificate(s);
          if ( client_hello <= 0 )
            goto end_16;
          s->init_num = 0;
LABEL_39:
          s->state = 8288;
          break;
        case 8320:
          if ( !ssl2_enc_init(s, 0) )
            goto LABEL_53;
          s->s2->clear_text = 0;
          s->state = 8256;
          goto LABEL_49;
        default:
          goto LABEL_52;
      }
      goto LABEL_49;
    }
$LN35_6:
    s->server = 1;
    if ( v1 )
      v1(s, 16, 1);
    client_hello = (int)s->init_buf;
    s->version = 2;
    s->type = 0x2000;
    if ( !client_hello )
    {
      client_hello = (int)BUF_MEM_new();
      if ( !client_hello )
        goto LABEL_53;
    }
    if ( !BUF_MEM_grow((buf_mem_st *)client_hello, 0x3FFFu) )
      goto LABEL_53;
    ctx = s->ctx;
    s->init_buf = (buf_mem_st *)client_hello;
    s->init_num = 0;
    ++ctx->stats.sess_accept;
    s->handshake_func = ssl2_accept;
    s->state = 8208;
LABEL_49:
    if ( v1 )
    {
      client_hello = s->state;
      if ( client_hello != buf )
      {
        s->state = buf;
        v1(s, 8193, 1);
        s->state = client_hello;
      }
    }
  }
  if ( state == 0x2000 )
    goto $LN35_6;
  if ( state != 3 )
  {
LABEL_52:
    ERR_put_error(0x14u, 122, 255, ".\\ssl\\s2_srvr.c", 343);
LABEL_53:
    client_hello = -1;
    goto end_16;
  }
  BUF_MEM_free(s->init_buf);
  ssl_free_wbio_buffer(client_hello, s);
  s->init_buf = 0;
  s->init_num = 0;
  ssl_update_cache(s, 2);
  client_hello = 1;
  ++s->ctx->stats.sess_accept_good;
  if ( v1 )
    v1(s, 32, 1);
end_16:
  --s->in_handshake;
  if ( v1 )
    v1(s, 8194, client_hello);
  return client_hello;
}
