int __cdecl ec_GFp_simple_group_copy(ec_group_st *dest, const ec_group_st *src)
{
  if ( !BN_copy(&dest->field, &src->field) || !BN_copy(&dest->a, &src->a) || !BN_copy(&dest->b, &src->b) )
    return 0;
  dest->a_is_minus3 = src->a_is_minus3;
  return 1;
}
