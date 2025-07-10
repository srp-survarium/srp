ec_group_st *__cdecl EC_GROUP_dup(const ec_group_st *a)
{
  ec_group_st *v2; // eax
  ec_group_st *v3; // esi

  if ( !a )
    return 0;
  v2 = EC_GROUP_new(a->meth);
  v3 = v2;
  if ( !v2 )
    return 0;
  if ( !EC_GROUP_copy(v2, a) )
  {
    EC_GROUP_free(v3);
    return 0;
  }
  return v3;
}
