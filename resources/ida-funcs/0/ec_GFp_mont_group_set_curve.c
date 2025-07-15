int __cdecl ec_GFp_mont_group_set_curve(
        ec_group_st *group,
        const bignum_st *p,
        const bignum_st *a,
        const bignum_st *b,
        bignum_ctx *ctx)
{
  bn_mont_ctx_st *field_data1; // eax
  bignum_ctx *v6; // ebx
  bn_mont_ctx_st *v8; // edi
  bignum_st *v9; // ebp
  bignum_pool_item *v10; // eax
  bignum_st *field_data2; // [esp-Ch] [ebp-20h]
  bignum_ctx *v12; // [esp+Ch] [ebp-8h]
  int v13; // [esp+10h] [ebp-4h]

  field_data1 = (bn_mont_ctx_st *)group->field_data1;
  v12 = 0;
  v13 = 0;
  if ( field_data1 )
  {
    BN_MONT_CTX_free(field_data1);
    group->field_data1 = 0;
  }
  if ( group->field_data2 )
  {
    BN_free((bignum_st *)group->field_data2);
    group->field_data2 = 0;
  }
  v6 = ctx;
  if ( !ctx )
  {
    v12 = BN_CTX_new(0);
    v6 = v12;
    if ( !v12 )
      return 0;
  }
  v8 = BN_MONT_CTX_new();
  if ( v8 )
  {
    if ( BN_MONT_CTX_set((int)v6, v8, p, v6) )
    {
      v9 = BN_new((int)v6);
      if ( v9 )
      {
        v10 = (bignum_pool_item *)BN_value_one();
        if ( BN_mod_mul_montgomery(v9, v10, (bignum_pool_item *)&v8->RR, v8, v6) )
        {
          group->field_data1 = v8;
          v8 = 0;
          group->field_data2 = v9;
          v13 = ec_GFp_simple_group_set_curve(group, p, a, b, v6);
          if ( !v13 )
          {
            BN_MONT_CTX_free((bn_mont_ctx_st *)group->field_data1);
            field_data2 = (bignum_st *)group->field_data2;
            group->field_data1 = 0;
            BN_free(field_data2);
            group->field_data2 = 0;
          }
        }
      }
    }
    else
    {
      ERR_put_error((int)v6, 0x10u, 189, 3, ".\\crypto\\ec\\ecp_mont.c", 226);
    }
  }
  if ( v12 )
    BN_CTX_free(v12);
  if ( v8 )
    BN_MONT_CTX_free(v8);
  return v13;
}
