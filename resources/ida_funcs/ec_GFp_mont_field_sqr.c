int __cdecl ec_GFp_mont_field_sqr(const ec_group_st *group, bignum_st *r, bignum_pool_item *a, bignum_ctx *ctx)
{
  bn_mont_ctx_st *field_data1; // eax

  field_data1 = (bn_mont_ctx_st *)group->field_data1;
  if ( field_data1 )
    return BN_mod_mul_montgomery(r, a, a, field_data1, ctx);
  ERR_put_error(0x10u, 132, 111, ".\\crypto\\ec\\ecp_mont.c", 273);
  return 0;
}
