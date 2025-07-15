engine_st *__usercall ENGINE_get_cipher_engine@<eax>(int a1@<ebx>, int nid)
{
  return engine_table_select(a1, (lhash_st **)&cipher_table, nid);
}
