BOOL __cdecl ec_GFp_simple_is_at_infinity(const ec_group_st *group, const ec_point_st *point)
{
  return point->Z.top == 0;
}
