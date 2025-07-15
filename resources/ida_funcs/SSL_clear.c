int __cdecl SSL_clear(ssl_st *s)
{
  int result; // eax
  const ssl_method_st *method; // edx
  int v3; // ecx
  int version; // eax
  buf_mem_st *init_buf; // eax
  const ssl_method_st *v6; // eax
  const ssl_method_st *v7; // eax

  if ( !s->method )
  {
    ERR_put_error(0x14u, 164, 188, ".\\ssl\\ssl_lib.c", 187);
    return 0;
  }
  if ( ssl_clear_bad_session(s) )
  {
    SSL_SESSION_free(s->session);
    s->session = 0;
  }
  s->error = 0;
  s->hit = 0;
  s->shutdown = 0;
  if ( s->new_session )
  {
    ERR_put_error(0x14u, 164, 68, ".\\ssl\\ssl_lib.c", 209);
    return 0;
  }
  method = s->method;
  v3 = (s->server != 0 ? 0x2000 : 4096) | 0x4000;
  s->type = 0;
  s->state = v3;
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
  ssl_clear_cipher_ctx(s);
  if ( s->read_hash )
    EVP_MD_CTX_destroy(0, s->read_hash);
  s->read_hash = 0;
  if ( s->write_hash )
    EVP_MD_CTX_destroy(0, s->write_hash);
  s->write_hash = 0;
  s->first_packet = 0;
  if ( s->in_handshake || s->session || (v6 = s->method, v6 == s->ctx->method) )
  {
    s->method->ssl_clear(s);
    return 1;
  }
  v6->ssl_free(s);
  v7 = s->ctx->method;
  s->method = v7;
  result = v7->ssl_new(s);
  if ( result )
    return 1;
  return result;
}
