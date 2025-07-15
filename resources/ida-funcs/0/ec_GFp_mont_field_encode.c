int __cdecl ec_GFp_mont_field_encode(const ec_group_st *group, bignum_st *r, bignum_pool_item *a, bignum_ctx *ctx)
{
  if ( group->field_data1 )
    return BN_mod_mul_montgomery(
             r,
             a,
             (bignum_pool_item *)((char *)group->field_data1 + 4),
             (bn_mont_ctx_st *)group->field_data1,
             ctx);
  ERR_put_error(0x10u, 134, 111, ".\\crypto\\ec\\ecp_mont.c", 285);
  return 0;
}
