int __usercall remove_session_lock@<eax>(ssl_ctx_st *ctx@<ecx>, ssl_session_st *c@<esi>, int a3@<ebx>, int lck)
{
  int v4; // ebp
  ssl_session_st *v6; // ebx
  void (__cdecl *remove_session_cb)(ssl_ctx_st *, ssl_session_st *); // eax

  v4 = 0;
  if ( !c || !c->session_id_length )
    return 0;
  if ( lck )
    CRYPTO_lock((int)ctx, a3, 9, 12, ".\\ssl\\ssl_sess.c", 665);
  v6 = (ssl_session_st *)lh_retrieve((lhash_st *)ctx->sessions, c);
  if ( v6 == c )
  {
    v4 = 1;
    v6 = (ssl_session_st *)lh_delete((lhash_st *)ctx->sessions, c);
    SSL_SESSION_list_remove(ctx, c);
  }
  if ( lck )
    CRYPTO_lock((int)ctx, (int)v6, 10, 12, ".\\ssl\\ssl_sess.c", 673);
  if ( v4 )
  {
    v6->not_resumable = 1;
    remove_session_cb = ctx->remove_session_cb;
    if ( remove_session_cb )
      remove_session_cb(ctx, v6);
    SSL_SESSION_free((int)ctx, (int)v6, v6);
  }
  return v4;
}
