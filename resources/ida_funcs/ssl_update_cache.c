void __cdecl ssl_update_cache(ssl_st *s, int mode)
{
  ssl_session_st *session; // ebp
  ssl_ctx_st *initial_ctx; // eax
  int session_cache_mode; // ebx
  int sess_connect_good; // eax
  int v6; // eax

  session = s->session;
  if ( session->session_id_length )
  {
    initial_ctx = s->initial_ctx;
    session_cache_mode = initial_ctx->session_cache_mode;
    if ( (mode & session_cache_mode) != 0
      && !s->hit
      && ((session_cache_mode & 0x200) != 0 || SSL_CTX_add_session(initial_ctx, session)) )
    {
      if ( s->initial_ctx->new_session_cb )
      {
        CRYPTO_add_lock(&s->session->references, 1, 14, ".\\ssl\\ssl_lib.c", 2217);
        if ( !s->initial_ctx->new_session_cb(s, s->session) )
          SSL_SESSION_free(s->session);
      }
    }
    if ( (session_cache_mode & 0x80u) == 0 && (mode & session_cache_mode) == mode )
    {
      if ( (mode & 1) != 0 )
        sess_connect_good = s->initial_ctx->stats.sess_connect_good;
      else
        sess_connect_good = s->initial_ctx->stats.sess_accept_good;
      if ( (_BYTE)sess_connect_good == 0xFF )
      {
        v6 = _time64(0);
        SSL_CTX_flush_sessions(s->initial_ctx, v6);
      }
    }
  }
}
