int __usercall ec_GFp_mont_field_mul@<eax>(
        int a1@<ebx>,
        const ec_group_st *group,
        bignum_st *r,
        bignum_pool_item *a,
        bignum_pool_item *b,
        bignum_ctx *ctx)
{
  bn_mont_ctx_st *field_data1; // eax

  field_data1 = (bn_mont_ctx_st *)group->field_data1;
  if ( field_data1 )
    return BN_mod_mul_montgomery(r, a, b, field_data1, ctx);
  ERR_put_error(a1, 0x10u, 131, 111, ".\\crypto\\ec\\ecp_mont.c", 261);
  return 0;
}
