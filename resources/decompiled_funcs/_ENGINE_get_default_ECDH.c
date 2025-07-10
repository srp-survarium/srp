engine_st *__cdecl ENGINE_get_default_ECDH()
{
  return engine_table_select((lhash_st **)&ecdh_table, 1);
}
