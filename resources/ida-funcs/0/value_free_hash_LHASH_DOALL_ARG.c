void __cdecl value_free_hash_LHASH_DOALL_ARG(void *a1, lhash_st *a2)
{
  if ( *((_DWORD *)a1 + 1) )
    lh_delete(a2, a1);
}
