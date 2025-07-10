engine_st *__cdecl ENGINE_get_default_DSA()
{
  return engine_table_select((lhash_st **)&dsa_table, 1);
}
