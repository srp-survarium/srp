engine_st *__cdecl ENGINE_get_cipher_engine(int nid)
{
  return engine_table_select((lhash_st **)&cipher_table, nid);
}
