bignum_st *__cdecl EC_GROUP_get_order(const ec_group_st *group, bignum_st *order)
{
  bignum_st *result; // eax

  result = BN_copy(order, &group->order);
  if ( result )
    return (bignum_st *)(order->top != 0);
  return result;
}
