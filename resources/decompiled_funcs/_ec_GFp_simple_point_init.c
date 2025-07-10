int __cdecl ec_GFp_simple_point_init(ec_point_st *point)
{
  BN_init(&point->X);
  BN_init(&point->Y);
  BN_init(&point->Z);
  point->Z_is_one = 0;
  return 1;
}
