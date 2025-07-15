void __cdecl value_free_hash_LHASH_DOALL_ARG(void *arg1, lhash_st *arg2)
{
  if ( *((_DWORD *)arg1 + 1) )
    lh_delete(arg2, arg1);
}
