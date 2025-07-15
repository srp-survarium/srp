void __cdecl ec_GFp_simple_point_clear_finish(ec_point_st *point)
{
  BN_clear_free(&point->X);
  BN_clear_free(&point->Y);
  BN_clear_free(&point->Z);
  point->Z_is_one = 0;
}
