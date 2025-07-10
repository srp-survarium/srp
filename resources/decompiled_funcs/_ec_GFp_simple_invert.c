int __cdecl ec_GFp_simple_invert(const ec_group_st *group, ec_point_st *point)
{
  if ( EC_POINT_is_at_infinity(group, point) || !point->Y.top )
    return 1;
  else
    return BN_usub(&point->Y, &group->field, &point->Y);
}
