engine_st *__cdecl ENGINE_get_digest_engine(int nid)
{
  return engine_table_select((lhash_st **)&digest_table, nid);
}
