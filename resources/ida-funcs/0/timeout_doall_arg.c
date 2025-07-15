void __usercall timeout_doall_arg(ssl_session_st *s@<esi>, timeout_param_st *p@<ecx>, int a3@<edi>)
{
  int time; // eax
  ssl_ctx_st *ctx; // ebx
  void (__cdecl *remove_session_cb)(ssl_ctx_st *, ssl_session_st *); // eax

  time = p->time;
  if ( !time || time > s->timeout + s->time )
  {
    lh_delete((lhash_st *)p->cache, s);
    SSL_SESSION_list_remove(p->ctx, s);
    s->not_resumable = 1;
    ctx = p->ctx;
    remove_session_cb = ctx->remove_session_cb;
    if ( remove_session_cb )
      remove_session_cb(ctx, s);
    SSL_SESSION_free(a3, (int)ctx, s);
  }
}
