void __usercall SSL_CTX_flush_sessions(int a1@<edi>, int a2@<ebx>, ssl_ctx_st *s, int t)
{
  unsigned int down_load; // esi
  _DWORD arg[2]; // [esp+0h] [ebp-Ch] BYREF
  lhash_st *lh; // [esp+8h] [ebp-4h]

  arg[0] = s;
  lh = (lhash_st *)s->sessions;
  if ( lh )
  {
    arg[1] = t;
    CRYPTO_lock(a1, a2, 9, 12, ".\\ssl\\ssl_sess.c", 930);
    down_load = lh->down_load;
    lh->down_load = 0;
    lh_doall_arg(lh, (void (__cdecl *)(void *, void *))timeout_LHASH_DOALL_ARG, arg);
    lh->down_load = down_load;
    CRYPTO_lock(a1, a2, 10, 12, ".\\ssl\\ssl_sess.c", 936);
  }
}
