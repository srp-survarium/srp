int __cdecl ec_GF2m_simple_point_copy(ec_point_st *dest, const ec_point_st *src)
{
  if ( !BN_copy(&dest->X, &src->X) || !BN_copy(&dest->Y, &src->Y) || !BN_copy(&dest->Z, &src->Z) )
    return 0;
  dest->Z_is_one = src->Z_is_one;
  return 1;
}
