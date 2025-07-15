void __usercall SSL_SESSION_list_add(ssl_ctx_st *ctx@<ecx>, ssl_session_st *s@<esi>)
{
  ssl_session_st *session_cache_head; // ecx
  ssl_session_st **p_session_cache_head; // eax

  if ( s->next && s->prev )
    SSL_SESSION_list_remove(ctx, s);
  session_cache_head = ctx->session_cache_head;
  p_session_cache_head = &ctx->session_cache_head;
  if ( session_cache_head )
  {
    s->next = session_cache_head;
    session_cache_head->prev = s;
    s->prev = (ssl_session_st *)p_session_cache_head;
    *p_session_cache_head = s;
  }
  else
  {
    *p_session_cache_head = s;
    ctx->session_cache_tail = s;
    s->prev = (ssl_session_st *)p_session_cache_head;
    s->next = (ssl_session_st *)&ctx->session_cache_tail;
  }
}
