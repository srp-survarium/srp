// positive sp value has been detected, the output may be wrong!
int __cdecl ssl23_connect(ssl_st *s)
{
  void (__cdecl *v1)(const ssl_st *, int, int); // ebx
  void *v2; // esp
  void (__cdecl *info_callback)(const ssl_st *, int, int); // eax
  int state; // eax
  int v5; // ebp
  bool v6; // zf
  int server_hello; // edi
  buf_mem_st *v8; // eax
  buf_mem_st *v9; // edi
  ssl_ctx_st *ctx; // eax
  int v11; // edi
  buf_mem_st *v13; // [esp+Ch] [ebp-8h]
  int v14; // [esp+10h] [ebp-4h] BYREF

  v1 = 0;
  _time64(0);
  v2 = alloca(8);
  RAND_add(&v14, 4, 0.0);
  ERR_clear_error();
  SetLastError(0);
  info_callback = s->info_callback;
  if ( info_callback || (info_callback = s->ctx->info_callback) != 0 )
    v1 = info_callback;
  ++s->in_handshake;
  if ( (SSL_state(s) & 0x3000) == 0 || (SSL_state(s) & 0x4000) != 0 )
    SSL_clear(s);
  while ( 1 )
  {
    state = s->state;
    v5 = state;
    if ( state > 4641 )
    {
      if ( state != 0x4000 )
      {
        v6 = state == 20480;
        goto LABEL_18;
      }
LABEL_19:
      if ( s->session )
      {
        ERR_put_error(0x14u, 117, 221, ".\\ssl\\s23_clnt.c", 174);
        goto LABEL_37;
      }
      s->server = 0;
      if ( v1 )
        v1(s, 16, 1);
      v6 = s->init_buf == 0;
      s->type = 4096;
      if ( v6 )
      {
        v8 = BUF_MEM_new();
        v9 = v8;
        v13 = v8;
        if ( !v8 || !BUF_MEM_grow(v8, 0x4000u) )
          goto LABEL_37;
        s->init_buf = v9;
        v13 = 0;
      }
      if ( !ssl3_setup_buffers(s) )
        goto LABEL_37;
      ssl3_init_finished_mac(s);
      ctx = s->ctx;
      s->state = 4624;
      ++ctx->stats.sess_connect;
      goto LABEL_28;
    }
    if ( state >= 4640 )
      break;
    if ( state <= 4099 )
    {
      if ( state != 4099 )
      {
        v6 = state == 4096;
LABEL_18:
        if ( !v6 )
          goto LABEL_35;
      }
      goto LABEL_19;
    }
    if ( state < 4624 || state > 4625 )
    {
LABEL_35:
      ERR_put_error(0x14u, 117, 255, ".\\ssl\\s23_clnt.c", 228);
LABEL_37:
      server_hello = -1;
      goto end_20;
    }
    s->shutdown = 0;
    server_hello = ssl23_client_hello(s);
    if ( server_hello <= 0 )
      goto end_20;
    s->state = 4640;
LABEL_28:
    v6 = s->debug == 0;
    s->init_num = 0;
    if ( !v6 )
      BIO_ctrl(s->wbio, 11, 0, 0);
    if ( v1 )
    {
      v11 = s->state;
      if ( v11 != v5 )
      {
        s->state = v5;
        v1(s, 4097, 1);
        s->state = v11;
      }
    }
  }
  server_hello = ssl23_get_server_hello(s);
  if ( server_hello >= 0 )
    v1 = 0;
end_20:
  --s->in_handshake;
  if ( v13 )
    BUF_MEM_free(v13);
  if ( v1 )
    v1(s, 4098, server_hello);
  return server_hello;
}
