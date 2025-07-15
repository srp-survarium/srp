engine_st *__cdecl ENGINE_get_default_DH()
{
  return engine_table_select((lhash_st **)&dh_table, 1);
}
