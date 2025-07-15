// positive sp value has been detected, the output may be wrong!
int __cdecl ssl23_accept(ssl_st *s)
{
  void (__cdecl *v1)(const ssl_st *, int, int); // ebx
  void *v2; // esp
  void (__cdecl *info_callback)(const ssl_st *, int, int); // eax
  int state; // eax
  int v5; // ebp
  int v6; // eax
  bool v7; // zf
  buf_mem_st *v8; // eax
  buf_mem_st *v9; // edi
  ssl_ctx_st *ctx; // eax
  int v11; // edi
  int client_hello; // edi
  int v14; // [esp+Ch] [ebp-4h] BYREF

  _time64(0);
  v1 = 0;
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
    if ( state <= 8721 )
      break;
    if ( state == 0x4000 )
      goto LABEL_14;
    v7 = state == 24576;
LABEL_13:
    if ( !v7 )
    {
      ERR_put_error(0x14u, 115, 255, ".\\ssl\\s23_srvr.c", 209);
LABEL_26:
      client_hello = -1;
      goto end_21;
    }
LABEL_14:
    s->server = 1;
    if ( v1 )
      v1(s, 16, 1);
    v7 = s->init_buf == 0;
    s->type = 0x2000;
    if ( v7 )
    {
      v8 = BUF_MEM_new();
      v9 = v8;
      if ( !v8 || !BUF_MEM_grow(v8, 0x4000u) )
        goto LABEL_26;
      s->init_buf = v9;
    }
    ssl3_init_finished_mac(s);
    ctx = s->ctx;
    s->state = 8720;
    ++ctx->stats.sess_accept;
    s->init_num = 0;
    if ( v1 )
    {
      v11 = s->state;
      if ( v11 != v5 )
      {
        s->state = v5;
        v1(s, 8193, 1);
        s->state = v11;
      }
    }
  }
  if ( state < 8720 )
  {
    v6 = state - 0x2000;
    if ( !v6 )
      goto LABEL_14;
    v7 = v6 == 3;
    goto LABEL_13;
  }
  s->shutdown = 0;
  client_hello = ssl23_get_client_hello(s);
  if ( client_hello >= 0 )
    v1 = 0;
end_21:
  --s->in_handshake;
  if ( v1 )
    v1(s, 8194, client_hello);
  return client_hello;
}
