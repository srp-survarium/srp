int __cdecl SSL_CTX_remove_session(ssl_ctx_st *ctx, ssl_session_st *c)
{
  return remove_session_lock(ctx, c, 1);
}
