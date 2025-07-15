engine_st *__usercall ENGINE_get_digest_engine@<eax>(int a1@<ebx>, int nid)
{
  return engine_table_select(a1, (lhash_st **)&digest_table, nid);
}
