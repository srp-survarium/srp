void __cdecl EC_GROUP_free(ec_group_st *group)
{
  void (__cdecl *group_finish)(ec_group_st *); // eax
  ec_point_st *generator; // edi
  void (__cdecl *point_finish)(ec_point_st *); // eax

  if ( group )
  {
    group_finish = group->meth->group_finish;
    if ( group_finish )
      group_finish(group);
    EC_EX_DATA_free_all_data(&group->extra_data);
    generator = group->generator;
    if ( generator )
    {
      point_finish = generator->meth->point_finish;
      if ( point_finish )
        point_finish(group->generator);
      CRYPTO_free((void *)generator);
    }
    BN_free(&group->order);
    BN_free(&group->cofactor);
    if ( group->seed )
      CRYPTO_free(group->seed);
    CRYPTO_free(group);
  }
}
