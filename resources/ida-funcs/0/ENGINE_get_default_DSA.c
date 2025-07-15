engine_st *__usercall ENGINE_get_default_DSA@<eax>(int a1@<ebx>)
{
  return engine_table_select(a1, (lhash_st **)&dsa_table, 1);
}
