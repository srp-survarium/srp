int __cdecl ec_GFp_simple_field_mul(
        const ec_group_st *group,
        bignum_st *r,
        bignum_pool_item *a,
        bignum_pool_item *b,
        bignum_ctx *ctx)
{
  return BN_mod_mul(r, a, b, &group->field, ctx);
}
