engine_st *__cdecl ENGINE_get_pkey_meth_engine(int nid)
{
  return engine_table_select(&pkey_meth_table, nid);
}
