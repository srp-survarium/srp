ec_key_st *__cdecl EC_KEY_dup(const ec_key_st *ec_key)
{
  ec_key_st *v1; // esi

  v1 = EC_KEY_new();
  if ( !v1 )
    return 0;
  if ( !EC_KEY_copy(v1, ec_key) )
  {
    EC_KEY_free(v1);
    return 0;
  }
  return v1;
}
