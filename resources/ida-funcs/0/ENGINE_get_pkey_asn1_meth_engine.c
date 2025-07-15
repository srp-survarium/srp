engine_st *__cdecl ENGINE_get_pkey_asn1_meth_engine(int nid)
{
  return engine_table_select(&pkey_asn1_meth_table, nid);
}
