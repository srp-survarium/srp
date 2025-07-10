int __usercall SSL_CTX_add_session@<eax>(unsigned int a1@<edi>, ssl_ctx_st *ctx, ssl_session_st *c)
{
  int v3; // ebp
  ssl_session_st *v4; // eax
  ssl_session_st *v5; // ebx
  int v6; // esi
  ssl_session_st *session_cache_tail; // esi
  ssl_session_st *v8; // ebx
  void (__cdecl *remove_session_cb)(ssl_ctx_st *, ssl_session_st *); // eax
  int v10; // esi

  v3 = 1;
  CRYPTO_add_lock(&c->references, 1, 14, ".\\ssl\\ssl_sess.c", 596);
  CRYPTO_lock(a1, 9, 12, ".\\ssl\\ssl_sess.c", 599);
  v4 = (ssl_session_st *)lh_insert((lhash_st *)ctx->sessions, c);
  v5 = v4;
  if ( v4 )
  {
    if ( v4 == c )
    {
LABEL_5:
      SSL_SESSION_free((unsigned int)ctx, v5);
      v3 = 0;
      goto LABEL_14;
    }
    SSL_SESSION_list_remove(ctx, v4);
    SSL_SESSION_free((unsigned int)ctx, v5);
    v5 = 0;
  }
  SSL_SESSION_list_add(ctx, c);
  if ( v5 )
    goto LABEL_5;
  if ( SSL_CTX_ctrl(ctx, 43, 0, 0) > 0 )
  {
    v6 = SSL_CTX_ctrl(ctx, 43, 0, 0);
    if ( SSL_CTX_ctrl(ctx, 20, 0, 0) > v6 )
    {
      do
      {
        session_cache_tail = ctx->session_cache_tail;
        if ( !session_cache_tail
          || !session_cache_tail->session_id_length
          || lh_retrieve((lhash_st *)ctx->sessions, ctx->session_cache_tail) != (void **)session_cache_tail )
        {
          break;
        }
        v8 = (ssl_session_st *)lh_delete((lhash_st *)ctx->sessions, session_cache_tail);
        SSL_SESSION_list_remove(ctx, session_cache_tail);
        v8->not_resumable = 1;
        remove_session_cb = ctx->remove_session_cb;
        if ( remove_session_cb )
          remove_session_cb(ctx, v8);
        SSL_SESSION_free((unsigned int)ctx, v8);
        ++ctx->stats.sess_cache_full;
        v10 = SSL_CTX_ctrl(ctx, 43, 0, 0);
      }
      while ( SSL_CTX_ctrl(ctx, 20, 0, 0) > v10 );
    }
  }
LABEL_14:
  CRYPTO_lock((unsigned int)ctx, 10, 12, ".\\ssl\\ssl_sess.c", 649);
  return v3;
}
