engine_st *__cdecl ENGINE_get_default_ECDSA()
{
  return engine_table_select((lhash_st **)&ecdsa_table, 1);
}
