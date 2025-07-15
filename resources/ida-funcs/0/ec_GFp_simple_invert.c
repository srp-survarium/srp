int __usercall ec_GFp_simple_invert@<eax>(int a1@<ebx>, const ec_group_st *group, ec_point_st *point)
{
  if ( EC_POINT_is_at_infinity(a1, group, point) || !point->Y.top )
    return 1;
  else
    return BN_usub(&point->Y, &group->field, &point->Y);
}
