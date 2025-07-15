int __cdecl ec_GF2m_simple_field_mul(
        const ec_group_st *group,
        bignum_st *r,
        const bignum_st *a,
        const bignum_st *b,
        bignum_ctx *ctx)
{
  return BN_GF2m_mod_mul_arr(r, a, b, group->poly, ctx);
}
