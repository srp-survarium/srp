int __usercall EC_GROUP_set_generator@<eax>(
        int a1@<ebx>,
        ec_group_st *group,
        const ec_point_st *generator,
        const bignum_st *order,
        const bignum_st *cofactor)
{
  int result; // eax
  ec_point_st *v6; // eax
  bignum_st *p_cofactor; // esi

  if ( !generator )
  {
    ERR_put_error(a1, 0x10u, 111, 67, ".\\crypto\\ec\\ec_lib.c", 288);
    return 0;
  }
  if ( !group->generator )
  {
    v6 = EC_POINT_new(a1, group);
    group->generator = v6;
    if ( !v6 )
      return 0;
  }
  if ( !EC_POINT_copy(a1, group->generator, generator) )
    return 0;
  if ( !order )
  {
    BN_set_word(a1, &group->order, 0);
LABEL_10:
    p_cofactor = &group->cofactor;
    if ( cofactor )
    {
      if ( !BN_copy(p_cofactor, cofactor) )
        return 0;
    }
    else
    {
      BN_set_word(a1, p_cofactor, 0);
    }
    return 1;
  }
  result = (int)BN_copy(&group->order, order);
  if ( result )
    goto LABEL_10;
  return result;
}
