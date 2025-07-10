// positive sp value has been detected, the output may be wrong!
int __cdecl ssl2_connect(ssl_st *s)
{
  buf_mem_st *init_buf; // ebp
  void *v2; // esp
  void (__cdecl *info_callback)(const ssl_st *, int, int); // eax
  int state; // eax
  int server_hello; // edi
  int v7; // eax
  ssl_ctx_st *ctx; // eax
  int v9; // edi
  void (__cdecl *v11)(const ssl_st *, int, int); // [esp+10h] [ebp-8h]
  int v12; // [esp+14h] [ebp-4h] BYREF
  int buf; // [esp+1Ch] [ebp+4h]

  _time64(0);
  init_buf = 0;
  v2 = alloca(8);
  RAND_add(&v12, 4, 0.0);
  ERR_clear_error();
  SetLastError(0);
  info_callback = s->info_callback;
  if ( info_callback || (info_callback = s->ctx->info_callback) != 0 )
    v11 = info_callback;
  ++s->in_handshake;
  if ( (SSL_state(s) & 0x3000) == 0 || (SSL_state(s) & 0x4000) != 0 )
    SSL_clear(s);
  while ( 1 )
  {
    state = s->state;
    buf = state;
    if ( state <= 4096 )
      break;
    if ( state > 0x4000 )
    {
      if ( state != 20480 )
        goto LABEL_45;
    }
    else if ( state != 0x4000 )
    {
      switch ( state )
      {
        case 4099:
          goto $LN31_9;
        case 4112:
        case 4113:
          s->shutdown = 0;
          server_hello = client_hello(s);
          if ( server_hello <= 0 )
            goto end_14;
          s->init_num = 0;
          s->state = 4128;
          break;
        case 4128:
        case 4129:
          server_hello = get_server_hello(s);
          if ( server_hello <= 0 )
            goto end_14;
          v7 = s->hit != 0 ? 4224 : 4144;
          s->init_num = 0;
          s->state = v7;
          break;
        case 4144:
        case 4145:
          server_hello = client_master_key(s);
          if ( server_hello <= 0 )
            goto end_14;
          s->init_num = 0;
          s->state = 4224;
          break;
        case 4160:
        case 4161:
          server_hello = client_finished(s);
          if ( server_hello <= 0 )
            goto end_14;
          s->init_num = 0;
          s->state = 4192;
          break;
        case 4176:
        case 4177:
        case 4178:
        case 4179:
        case 4240:
          server_hello = client_certificate(s);
          if ( server_hello <= 0 )
            goto end_14;
          s->init_num = 0;
          s->state = 4208;
          break;
        case 4192:
        case 4193:
          server_hello = get_server_verify(s);
          if ( server_hello <= 0 )
            goto end_14;
          s->init_num = 0;
          s->state = 4208;
          break;
        case 4208:
        case 4209:
          server_hello = get_server_finished(s);
          if ( server_hello > 0 )
            goto LABEL_42;
          goto end_14;
        case 4224:
          if ( !ssl2_enc_init(s, 1) )
            goto LABEL_48;
          s->s2->clear_text = 0;
          s->state = 4160;
          break;
        default:
          goto LABEL_45;
      }
      goto LABEL_42;
    }
$LN31_9:
    s->server = 0;
    if ( v11 )
      v11(s, 16, 1);
    init_buf = s->init_buf;
    s->version = 2;
    s->type = 4096;
    if ( !init_buf )
    {
      init_buf = BUF_MEM_new();
      if ( !init_buf )
        goto LABEL_48;
    }
    if ( !BUF_MEM_grow(init_buf, 0x3FFFu) )
    {
      if ( init_buf == s->init_buf )
        init_buf = 0;
LABEL_48:
      server_hello = -1;
      goto end_14;
    }
    ctx = s->ctx;
    s->init_buf = init_buf;
    init_buf = 0;
    s->init_num = 0;
    s->state = 4112;
    ++ctx->stats.sess_connect;
    s->handshake_func = ssl2_connect;
LABEL_42:
    if ( v11 )
    {
      v9 = s->state;
      if ( v9 != buf )
      {
        s->state = buf;
        v11(s, 4097, 1);
        s->state = v9;
      }
    }
  }
  if ( state == 4096 )
    goto $LN31_9;
  if ( state != 3 )
  {
LABEL_45:
    ERR_put_error(0x14u, 123, 255, ".\\ssl\\s2_clnt.c", 310);
    return -1;
  }
  if ( s->init_buf )
  {
    BUF_MEM_free(s->init_buf);
    s->init_buf = 0;
  }
  server_hello = 1;
  s->init_num = 0;
  ssl_update_cache(s, 1);
  if ( s->hit )
    ++s->ctx->stats.sess_hit;
  ++s->ctx->stats.sess_connect_good;
  if ( v11 )
    v11(s, 32, 1);
end_14:
  --s->in_handshake;
  if ( init_buf )
    BUF_MEM_free(init_buf);
  if ( v11 )
    v11(s, 4098, server_hello);
  return server_hello;
}
