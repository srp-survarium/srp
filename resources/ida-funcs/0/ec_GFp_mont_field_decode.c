int __usercall ec_GFp_mont_field_decode@<eax>(
        int a1@<ebx>,
        const ec_group_st *group,
        bignum_st *r,
        const bignum_st *a,
        bignum_ctx *ctx)
{
  bn_mont_ctx_st *field_data1; // eax

  field_data1 = (bn_mont_ctx_st *)group->field_data1;
  if ( field_data1 )
    return BN_from_montgomery(r, a, field_data1, ctx);
  ERR_put_error(a1, 0x10u, 133, 111, ".\\crypto\\ec\\ecp_mont.c", 297);
  return 0;
}
