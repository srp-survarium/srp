int __cdecl ec_GF2m_simple_point_init(ec_point_st *point)
{
  BN_init(&point->X);
  BN_init(&point->Y);
  BN_init(&point->Z);
  return 1;
}
