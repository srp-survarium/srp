bignum_st *__cdecl EC_GROUP_get_cofactor(const ec_group_st *group, bignum_st *cofactor)
{
  bignum_st *result; // eax

  result = BN_copy(cofactor, &group->cofactor);
  if ( result )
    return (bignum_st *)(group->cofactor.top != 0);
  return result;
}
