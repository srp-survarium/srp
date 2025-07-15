BOOL __usercall ec_GFp_nist_field_mul@<eax>(
        bignum_pool_item *a1@<ebx>,
        const ec_group_st *group,
        bignum_pool_item *r,
        bignum_pool_item *a,
        bignum_pool_item *b,
        bignum_ctx *ctx)
{
  BOOL v6; // esi
  bignum_ctx *v7; // ebp
  bignum_ctx *v8; // esi

  v6 = 0;
  v7 = 0;
  if ( !group || !r || !a || (a1 = b) == 0 )
  {
    ERR_put_error((int)a1, 0x10u, 200, 67, ".\\crypto\\ec\\ecp_nist.c", 169);
    return v6;
  }
  v8 = ctx;
  if ( ctx || (v8 = BN_CTX_new((int)b), (v7 = v8) != 0) )
  {
    v6 = BN_mul(r, a, b, v8) && group->field_mod_func((bignum_st *)r, (const bignum_st *)r, &group->field, v8);
    if ( v7 )
    {
      BN_CTX_free(v7);
      return v6;
    }
    return v6;
  }
  return 0;
}
