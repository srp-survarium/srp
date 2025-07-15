ec_point_st *__cdecl EC_POINT_dup(const ec_point_st *a, const ec_group_st *group)
{
  ec_point_st *v3; // eax
  ec_point_st *v4; // esi
  void (__cdecl *point_finish)(ec_point_st *); // eax

  if ( !a )
    return 0;
  v3 = EC_POINT_new(group);
  v4 = v3;
  if ( !v3 )
    return 0;
  if ( !EC_POINT_copy(v3, a) )
  {
    point_finish = v4->meth->point_finish;
    if ( point_finish )
      point_finish(v4);
    CRYPTO_free((void *)v4);
    return 0;
  }
  return v4;
}
