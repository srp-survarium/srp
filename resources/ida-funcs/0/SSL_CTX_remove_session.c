int __usercall SSL_CTX_remove_session@<eax>(int a1@<ebx>, ssl_ctx_st *ctx, ssl_session_st *c)
{
  return remove_session_lock(ctx, c, a1, 1);
}
