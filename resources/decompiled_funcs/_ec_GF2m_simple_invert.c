int __cdecl ec_GF2m_simple_invert(const ec_group_st *group, ec_point_st *point, bignum_ctx *ctx)
{
  int result; // eax

  if ( EC_POINT_is_at_infinity(group, point) || !point->Y.top )
    return 1;
  result = EC_POINT_make_affine(group, point, ctx);
  if ( result )
    return BN_GF2m_add(&point->Y, &point->X, &point->Y);
  return result;
}
