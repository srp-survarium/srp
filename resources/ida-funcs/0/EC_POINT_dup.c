ec_point_st *__usercall EC_POINT_dup@<eax>(int a1@<ebx>, const ec_point_st *a, const ec_group_st *group)
{
  ec_point_st *v4; // eax
  ec_point_st *v5; // esi
  void (__cdecl *point_finish)(ec_point_st *); // eax

  if ( !a )
    return 0;
  v4 = EC_POINT_new(a1, group);
  v5 = v4;
  if ( !v4 )
    return 0;
  if ( !EC_POINT_copy(a1, v4, a) )
  {
    point_finish = v5->meth->point_finish;
    if ( point_finish )
      point_finish(v5);
    CRYPTO_free((void *)v5);
    return 0;
  }
  return v5;
}
