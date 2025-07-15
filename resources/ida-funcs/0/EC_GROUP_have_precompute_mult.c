int __cdecl EC_GROUP_have_precompute_mult(const ec_group_st *group)
{
  int (*have_precompute_mult)(void); // eax

  if ( !group->meth->mul )
    return ec_wNAF_have_precompute_mult(group);
  have_precompute_mult = (int (*)(void))group->meth->have_precompute_mult;
  if ( have_precompute_mult )
    return have_precompute_mult();
  else
    return 0;
}
