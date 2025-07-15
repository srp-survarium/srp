void __cdecl engine_table_doall(
        lhash_st *table,
        void (__cdecl *cb)(int, stack_st_ENGINE *, engine_st *, void *),
        void *arg)
{
  _DWORD arga[2]; // [esp+0h] [ebp-8h] BYREF

  arga[0] = cb;
  arga[1] = arg;
  lh_doall_arg(table, (void (__cdecl *)(void *, void *))int_cb_LHASH_DOALL_ARG, arga);
}
