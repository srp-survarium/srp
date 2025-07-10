BOOL __cdecl ec_GFp_nist_field_mul(
        const ec_group_st *group,
        bignum_pool_item *r,
        bignum_pool_item *a,
        bignum_pool_item *b,
        bignum_ctx *ctx)
{
  BOOL v5; // esi
  bignum_ctx *v6; // ebp
  bignum_ctx *v7; // esi

  v5 = 0;
  v6 = 0;
  if ( !group || !r || !a || !b )
  {
    ERR_put_error(0x10u, 200, 67, ".\\crypto\\ec\\ecp_nist.c", 169);
    return v5;
  }
  v7 = ctx;
  if ( ctx || (v7 = BN_CTX_new(), (v6 = v7) != 0) )
  {
    v5 = BN_mul(r, a, b, v7) && group->field_mod_func((bignum_st *)r, (const bignum_st *)r, &group->field, v7);
    if ( v6 )
    {
      BN_CTX_free(v6);
      return v5;
    }
    return v5;
  }
  return 0;
}
