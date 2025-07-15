BOOL __cdecl ec_GF2m_simple_dbl(const ec_group_st *group, ec_point_st *r, const ec_point_st *a, bignum_ctx *ctx)
{
  return ec_GF2m_simple_add(group, r, a, a, ctx);
}
