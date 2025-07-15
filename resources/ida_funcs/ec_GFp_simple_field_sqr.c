int __cdecl ec_GFp_simple_field_sqr(const ec_group_st *group, bignum_st *r, const bignum_st *a, bignum_ctx *ctx)
{
  return BN_mod_sqr(r, a, &group->field, ctx);
}
