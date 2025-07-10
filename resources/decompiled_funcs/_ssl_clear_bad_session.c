int __cdecl ssl_clear_bad_session(ssl_st *s)
{
  if ( !s->session || (s->shutdown & 1) != 0 || (SSL_state(s) & 0x3000) != 0 || (SSL_state(s) & 0x4000) != 0 )
    return 0;
  remove_session_lock(s->ctx, s->session, 1);
  return 1;
}
