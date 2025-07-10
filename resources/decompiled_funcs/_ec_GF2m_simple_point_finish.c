void __cdecl ec_GF2m_simple_point_finish(ec_point_st *point)
{
  BN_free(&point->X);
  BN_free(&point->Y);
  BN_free(&point->Z);
}
