// positive sp value has been detected, the output may be wrong!
int __usercall ssl23_connect@<eax>(int server_hello@<edi>, ssl_st *s)
{
  void (__cdecl *v2)(const ssl_st *, int, int); // ebx
  void *v3; // esp
  void (__cdecl *info_callback)(const ssl_st *, int, int); // eax
  int state; // eax
  int v6; // ebp
  bool v7; // zf
  buf_mem_st *v8; // eax
  ssl_ctx_st *ctx; // eax
  buf_mem_st *v11; // [esp+Ch] [ebp-8h]
  int v12; // [esp+10h] [ebp-4h] BYREF

  v2 = 0;
  _time64(0);
  v3 = alloca(8);
  RAND_add(server_hello, &v12, 4, 0.0);
  ERR_clear_error(0);
  SetLastError(0);
  info_callback = s->info_callback;
  if ( info_callback || (info_callback = s->ctx->info_callback) != 0 )
    v2 = info_callback;
  ++s->in_handshake;
  if ( (SSL_state(s) & 0x3000) == 0 || (SSL_state(s) & 0x4000) != 0 )
    SSL_clear((int)v2, s);
  while ( 1 )
  {
    state = s->state;
    v6 = state;
    if ( state > 4641 )
    {
      if ( state != 0x4000 )
      {
        v7 = state == 20480;
        goto LABEL_18;
      }
LABEL_19:
      if ( s->session )
      {
        ERR_put_error((int)v2, 0x14u, 117, 221, ".\\ssl\\s23_clnt.c", 174);
        goto LABEL_37;
      }
      s->server = 0;
      if ( v2 )
        v2(s, 16, 1);
      v7 = s->init_buf == 0;
      s->type = 4096;
      if ( v7 )
      {
        v8 = BUF_MEM_new((int)v2);
        server_hello = (int)v8;
        v11 = v8;
        if ( !v8 || !BUF_MEM_grow(v8, 0x4000u) )
          goto LABEL_37;
        s->init_buf = (buf_mem_st *)server_hello;
        v11 = 0;
      }
      if ( !ssl3_setup_buffers(s) )
        goto LABEL_37;
      ssl3_init_finished_mac(server_hello, s);
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
        v7 = state == 4096;
LABEL_18:
        if ( !v7 )
          goto LABEL_35;
      }
      goto LABEL_19;
    }
    if ( state < 4624 || state > 4625 )
    {
LABEL_35:
      ERR_put_error((int)v2, 0x14u, 117, 255, ".\\ssl\\s23_clnt.c", 228);
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
    v7 = s->debug == 0;
    s->init_num = 0;
    if ( !v7 )
      BIO_ctrl((int)v2, s->wbio, 11, 0, 0);
    if ( v2 )
    {
      server_hello = s->state;
      if ( server_hello != v6 )
      {
        s->state = v6;
        v2(s, 4097, 1);
        s->state = server_hello;
      }
    }
  }
  server_hello = ssl23_get_server_hello(s);
  if ( server_hello >= 0 )
    v2 = 0;
end_20:
  --s->in_handshake;
  if ( v11 )
    BUF_MEM_free(v11);
  if ( v2 )
    v2(s, 4098, server_hello);
  return server_hello;
}
