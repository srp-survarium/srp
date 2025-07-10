int __usercall remove_session_lock@<eax>(ssl_ctx_st *ctx@<ecx>, ssl_session_st *c@<esi>, int lck)
{
  int v3; // ebp
  ssl_session_st *v5; // ebx
  void (__cdecl *remove_session_cb)(ssl_ctx_st *, ssl_session_st *); // eax

  v3 = 0;
  if ( !c || !c->session_id_length )
    return 0;
  if ( lck )
    CRYPTO_lock((unsigned int)ctx, 9, 12, ".\\ssl\\ssl_sess.c", 665);
  v5 = (ssl_session_st *)lh_retrieve((lhash_st *)ctx->sessions, c);
  if ( v5 == c )
  {
    v3 = 1;
    v5 = (ssl_session_st *)lh_delete((lhash_st *)ctx->sessions, c);
    SSL_SESSION_list_remove(ctx, c);
  }
  if ( lck )
    CRYPTO_lock((unsigned int)ctx, 10, 12, ".\\ssl\\ssl_sess.c", 673);
  if ( v3 )
  {
    v5->not_resumable = 1;
    remove_session_cb = ctx->remove_session_cb;
    if ( remove_session_cb )
      remove_session_cb(ctx, v5);
    SSL_SESSION_free((unsigned int)ctx, v5);
  }
  return v3;
}
