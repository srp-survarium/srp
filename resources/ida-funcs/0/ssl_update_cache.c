void __cdecl ssl_update_cache(ssl_st *s, int mode)
{
  ssl_session_st *session; // ebp
  ssl_ctx_st *initial_ctx; // eax
  int session_cache_mode; // ebx
  int v5; // edi
  int sess_connect_good; // eax
  int v7; // eax

  session = s->session;
  if ( session->session_id_length )
  {
    initial_ctx = s->initial_ctx;
    session_cache_mode = initial_ctx->session_cache_mode;
    v5 = mode & session_cache_mode;
    if ( (mode & session_cache_mode) != 0
      && !s->hit
      && ((session_cache_mode & 0x200) != 0 || SSL_CTX_add_session(v5, initial_ctx, session)) )
    {
      if ( s->initial_ctx->new_session_cb )
      {
        CRYPTO_add_lock(&s->session->references, 1, 14, ".\\ssl\\ssl_lib.c", 2217);
        if ( !s->initial_ctx->new_session_cb(s, s->session) )
          SSL_SESSION_free(v5, s->session);
      }
    }
    if ( (session_cache_mode & 0x80u) == 0 && v5 == mode )
    {
      if ( (mode & 1) != 0 )
        sess_connect_good = s->initial_ctx->stats.sess_connect_good;
      else
        sess_connect_good = s->initial_ctx->stats.sess_accept_good;
      if ( (_BYTE)sess_connect_good == 0xFF )
      {
        v7 = _time64(0);
        SSL_CTX_flush_sessions(v5, s->initial_ctx, v7);
      }
    }
  }
}
