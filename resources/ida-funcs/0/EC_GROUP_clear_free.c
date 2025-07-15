void __cdecl EC_GROUP_clear_free(ec_group_st *group)
{
  void (__cdecl *group_clear_finish)(ec_group_st *); // ecx
  void (__cdecl *group_finish)(ec_group_st *); // eax
  unsigned __int8 *seed; // eax

  if ( group )
  {
    group_clear_finish = group->meth->group_clear_finish;
    if ( group_clear_finish )
    {
      group_clear_finish(group);
    }
    else
    {
      group_finish = group->meth->group_finish;
      if ( group_finish )
        group_finish(group);
    }
    EC_EX_DATA_clear_free_all_data(&group->extra_data);
    if ( group->generator )
      EC_POINT_clear_free(group->generator);
    BN_clear_free(&group->order);
    BN_clear_free(&group->cofactor);
    seed = group->seed;
    if ( seed )
    {
      OPENSSL_cleanse(seed, group->seed_len);
      CRYPTO_free(group->seed);
    }
    OPENSSL_cleanse(group, 172);
    CRYPTO_free(group);
  }
}
