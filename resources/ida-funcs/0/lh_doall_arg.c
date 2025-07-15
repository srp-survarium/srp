void __cdecl lh_doall_arg(lhash_st *lh, void (__cdecl *func)(void *, void *), void *arg)
{
  doall_util_fn(1, lh, 0, func, arg);
}
