int __usercall SSL_clear@<eax>(int a1@<ebx>, ssl_st *s)
{
  int result; // eax
  const ssl_method_st *method; // edx
  int v4; // ecx
  int version; // eax
  buf_mem_st *init_buf; // eax
  const ssl_method_st *v7; // eax
  const ssl_method_st *v8; // eax

  if ( !s->method )
  {
    ERR_put_error(a1, 0x14u, 164, 188, ".\\ssl\\ssl_lib.c", 187);
    return 0;
  }
  if ( ssl_clear_bad_session(s) )
  {
    SSL_SESSION_free(0, s->session);
    s->session = 0;
  }
  s->error = 0;
  s->hit = 0;
  s->shutdown = 0;
  if ( s->new_session )
  {
    ERR_put_error(a1, 0x14u, 164, 68, ".\\ssl\\ssl_lib.c", 209);
    return 0;
  }
  method = s->method;
  v4 = (s->server != 0 ? 0x2000 : 4096) | 0x4000;
  s->type = 0;
  s->state = v4;
  version = method->version;
  s->version = method->version;
  s->client_version = version;
  init_buf = s->init_buf;
  s->rwstate = 1;
  s->rstate = 240;
  if ( init_buf )
  {
    BUF_MEM_free(init_buf);
    s->init_buf = 0;
  }
  ssl_clear_cipher_ctx(a1, s);
  if ( s->read_hash )
    EVP_MD_CTX_destroy(0, a1, s->read_hash);
  s->read_hash = 0;
  if ( s->write_hash )
    EVP_MD_CTX_destroy(0, a1, s->write_hash);
  s->write_hash = 0;
  s->first_packet = 0;
  if ( s->in_handshake || s->session || (v7 = s->method, v7 == s->ctx->method) )
  {
    s->method->ssl_clear(s);
    return 1;
  }
  v7->ssl_free(s);
  v8 = s->ctx->method;
  s->method = v8;
  result = v8->ssl_new(s);
  if ( result )
    return 1;
  return result;
}
