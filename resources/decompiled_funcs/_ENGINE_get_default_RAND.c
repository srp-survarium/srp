engine_st *__cdecl ENGINE_get_default_RAND()
{
  return engine_table_select((lhash_st **)&rand_table, 1);
}
