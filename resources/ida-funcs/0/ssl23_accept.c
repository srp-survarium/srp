// positive sp value has been detected, the output may be wrong!
int __usercall ssl23_accept@<eax>(buf_mem_st *a1@<edi>, ssl_st *s)
{
  void (__cdecl *v2)(const ssl_st *, int, int); // ebx
  void *v3; // esp
  void (__cdecl *info_callback)(const ssl_st *, int, int); // eax
  int state; // eax
  int v6; // ebp
  int v7; // eax
  bool v8; // zf
  buf_mem_st *v9; // eax
  ssl_ctx_st *ctx; // eax
  int client_hello; // edi
  int v13; // [esp+Ch] [ebp-4h] BYREF

  _time64(0);
  v2 = 0;
  v3 = alloca(8);
  RAND_add((int)a1, &v13, 4, 0.0);
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
    if ( state <= 8721 )
      break;
    if ( state == 0x4000 )
      goto LABEL_14;
    v8 = state == 24576;
LABEL_13:
    if ( !v8 )
    {
      ERR_put_error((int)v2, 0x14u, 115, 255, ".\\ssl\\s23_srvr.c", 209);
LABEL_26:
      client_hello = -1;
      goto end_21;
    }
LABEL_14:
    s->server = 1;
    if ( v2 )
      v2(s, 16, 1);
    v8 = s->init_buf == 0;
    s->type = 0x2000;
    if ( v8 )
    {
      v9 = BUF_MEM_new((int)v2);
      a1 = v9;
      if ( !v9 || !BUF_MEM_grow(v9, 0x4000u) )
        goto LABEL_26;
      s->init_buf = a1;
    }
    ssl3_init_finished_mac((int)a1, s);
    ctx = s->ctx;
    s->state = 8720;
    ++ctx->stats.sess_accept;
    s->init_num = 0;
    if ( v2 )
    {
      a1 = (buf_mem_st *)s->state;
      if ( a1 != (buf_mem_st *)v6 )
      {
        s->state = v6;
        v2(s, 8193, 1);
        s->state = (int)a1;
      }
    }
  }
  if ( state < 8720 )
  {
    v7 = state - 0x2000;
    if ( !v7 )
      goto LABEL_14;
    v8 = v7 == 3;
    goto LABEL_13;
  }
  s->shutdown = 0;
  client_hello = ssl23_get_client_hello(s);
  if ( client_hello >= 0 )
    v2 = 0;
end_21:
  --s->in_handshake;
  if ( v2 )
    v2(s, 8194, client_hello);
  return client_hello;
}
