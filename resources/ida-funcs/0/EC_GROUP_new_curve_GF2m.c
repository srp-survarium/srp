ec_group_st *__usercall EC_GROUP_new_curve_GF2m@<eax>(int a1@<ebx>)
{
  const ec_method_st *v1; // eax
  ec_group_st *v2; // esi

  v1 = EC_GF2m_simple_method();
  v2 = EC_GROUP_new(v1);
  if ( !v2 )
    return 0;
  if ( !EC_GROUP_set_curve_GF2m(a1, v2) )
  {
    EC_GROUP_clear_free(v2);
    return 0;
  }
  return v2;
}
