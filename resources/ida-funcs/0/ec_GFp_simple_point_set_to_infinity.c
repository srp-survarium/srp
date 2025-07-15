int __cdecl ec_GFp_simple_point_set_to_infinity(const ec_group_st *group, ec_point_st *point)
{
  point->Z_is_one = 0;
  BN_set_word(&point->Z, 0);
  return 1;
}
