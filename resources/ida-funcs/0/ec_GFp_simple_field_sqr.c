int __usercall ec_GFp_simple_field_sqr@<eax>(
        int a1@<ebx>,
        const ec_group_st *group,
        bignum_pool_item *r,
        bignum_pool_item *a,
        bignum_ctx *ctx)
{
  return BN_mod_sqr(a1, r, a, &group->field, ctx);
}
