engine_st *__cdecl ENGINE_get_default_RSA()
{
  return engine_table_select((lhash_st **)&rsa_table, 1);
}
