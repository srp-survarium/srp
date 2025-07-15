engine_st *__usercall ENGINE_get_default_ECDH@<eax>(int a1@<ebx>)
{
  return engine_table_select(a1, (lhash_st **)&ecdh_table, 1);
}
