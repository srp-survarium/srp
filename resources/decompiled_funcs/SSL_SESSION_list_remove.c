void __usercall SSL_SESSION_list_remove(ssl_ctx_st *ctx@<edi>, ssl_session_st *s)
{
  ssl_session_st *next; // edx
  ssl_session_st *prev; // ecx
  ssl_session_st *p_session_cache_tail; // esi
  ssl_session_st *p_session_cache_head; // esi

  next = s->next;
  if ( next )
  {
    prev = s->prev;
    if ( prev )
    {
      p_session_cache_tail = (ssl_session_st *)&ctx->session_cache_tail;
      if ( next == (ssl_session_st *)&ctx->session_cache_tail )
      {
        if ( prev == (ssl_session_st *)&ctx->session_cache_head )
        {
          ctx->session_cache_head = 0;
          p_session_cache_tail->ssl_version = 0;
        }
        else
        {
          p_session_cache_tail->ssl_version = (int)prev;
          s->prev->next = p_session_cache_tail;
        }
      }
      else
      {
        p_session_cache_head = (ssl_session_st *)&ctx->session_cache_head;
        if ( prev == (ssl_session_st *)&ctx->session_cache_head )
        {
          p_session_cache_head->ssl_version = (int)next;
          s->next->prev = p_session_cache_head;
        }
        else
        {
          next->prev = prev;
          s->prev->next = s->next;
        }
      }
      s->next = 0;
      s->prev = 0;
    }
  }
}
