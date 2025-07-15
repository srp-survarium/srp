bignum_pool_item *__cdecl ec_GF2m_simple_field_sqr(
        const ec_group_st *group,
        bignum_st *r,
        const bignum_st *a,
        bignum_ctx *ctx)
{
  return BN_GF2m_mod_sqr_arr(r, a, group->poly, ctx);
}
