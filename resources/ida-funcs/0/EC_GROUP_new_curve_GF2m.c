ec_group_st *__cdecl EC_GROUP_new_curve_GF2m()
{
  const ec_method_st *v0; // eax
  ec_group_st *v1; // esi

  v0 = EC_GF2m_simple_method();
  v1 = EC_GROUP_new(v0);
  if ( !v1 )
    return 0;
  if ( !EC_GROUP_set_curve_GF2m(v1) )
  {
    EC_GROUP_clear_free(v1);
    return 0;
  }
  return v1;
}
