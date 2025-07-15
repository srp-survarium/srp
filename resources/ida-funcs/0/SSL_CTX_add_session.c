int __usercall SSL_CTX_add_session@<eax>(int a1@<edi>, int a2@<ebx>, ssl_ctx_st *ctx, lhash_node_st *c)
{
  int v4; // ebp
  ssl_session_st *v5; // eax
  ssl_session_st *v6; // ebx
  int v7; // esi
  ssl_session_st *session_cache_tail; // esi
  void (__cdecl *remove_session_cb)(ssl_ctx_st *, ssl_session_st *); // eax
  int v10; // esi

  v4 = 1;
  CRYPTO_add_lock((int *)&c[13].hash, 1, 14, ".\\ssl\\ssl_sess.c", 596);
  CRYPTO_lock(a1, a2, 9, 12, ".\\ssl\\ssl_sess.c", 599);
  v5 = (ssl_session_st *)lh_insert((lhash_st *)ctx->sessions, c);
  v6 = v5;
  if ( v5 )
  {
    if ( v5 == (ssl_session_st *)c )
    {
LABEL_5:
      SSL_SESSION_free((int)ctx, (int)v6, v6);
      v4 = 0;
      goto LABEL_14;
    }
    SSL_SESSION_list_remove(ctx, v5);
    SSL_SESSION_free((int)ctx, (int)v6, v6);
    v6 = 0;
  }
  SSL_SESSION_list_add(ctx, (ssl_session_st *)c);
  if ( v6 )
    goto LABEL_5;
  if ( SSL_CTX_ctrl(ctx, 43, 0, 0) > 0 )
  {
    v7 = SSL_CTX_ctrl(ctx, 43, 0, 0);
    if ( SSL_CTX_ctrl(ctx, 20, 0, 0) > v7 )
    {
      do
      {
        session_cache_tail = ctx->session_cache_tail;
        if ( !session_cache_tail
          || !session_cache_tail->session_id_length
          || lh_retrieve((lhash_st *)ctx->sessions, ctx->session_cache_tail) != (void ***)session_cache_tail )
        {
          break;
        }
        v6 = (ssl_session_st *)lh_delete((lhash_st *)ctx->sessions, session_cache_tail);
        SSL_SESSION_list_remove(ctx, session_cache_tail);
        v6->not_resumable = 1;
        remove_session_cb = ctx->remove_session_cb;
        if ( remove_session_cb )
          remove_session_cb(ctx, v6);
        SSL_SESSION_free((int)ctx, (int)v6, v6);
        ++ctx->stats.sess_cache_full;
        v10 = SSL_CTX_ctrl(ctx, 43, 0, 0);
      }
      while ( SSL_CTX_ctrl(ctx, 20, 0, 0) > v10 );
    }
  }
LABEL_14:
  CRYPTO_lock((int)ctx, (int)v6, 10, 12, ".\\ssl\\ssl_sess.c", 649);
  return v4;
}
