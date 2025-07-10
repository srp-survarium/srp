BOOL __cdecl ec_GFp_nist_field_sqr(const ec_group_st *group, bignum_st *r, const bignum_st *a, bignum_ctx *ctx)
{
  BOOL v4; // esi
  bignum_ctx *v5; // ebx
  bignum_ctx *v6; // esi

  v4 = 0;
  v5 = 0;
  if ( !group || !r || !a )
  {
    ERR_put_error(0x10u, 201, 134, ".\\crypto\\ec\\ecp_nist.c", 195);
    return v4;
  }
  v6 = ctx;
  if ( ctx || (v6 = BN_CTX_new(), (v5 = v6) != 0) )
  {
    v4 = BN_sqr(r, a, v6) && group->field_mod_func(r, r, &group->field, v6);
    if ( v5 )
    {
      BN_CTX_free(v5);
      return v4;
    }
    return v4;
  }
  return 0;
}
