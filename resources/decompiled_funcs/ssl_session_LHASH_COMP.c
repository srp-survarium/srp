int __cdecl ssl_session_LHASH_COMP(const void *arg1, const ssl_session_st *arg2)
{
  return ssl_session_cmp(arg2);
}
