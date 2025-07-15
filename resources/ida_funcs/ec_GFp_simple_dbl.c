int __cdecl ec_GFp_simple_dbl(const ec_group_st *group, ec_point_st *r, const ec_point_st *a, bignum_ctx *ctx)
{
  bignum_ctx *v5; // esi
  bignum_pool_item *v6; // edi
  bignum_pool_item *v7; // ebp
  int v8; // eax
  int v10; // eax
  int v11; // edi
  const bignum_st *m; // [esp+Ch] [ebp-24h]
  int (__cdecl *field_sqr)(const ec_group_st *, bignum_st *, const bignum_st *, bignum_ctx *); // [esp+10h] [ebp-20h]
  bignum_pool_item *ra; // [esp+14h] [ebp-1Ch]
  int (__cdecl *field_mul)(const ec_group_st *, bignum_st *, const bignum_st *, const bignum_st *, bignum_ctx *); // [esp+18h] [ebp-18h]
  bignum_pool_item *b; // [esp+1Ch] [ebp-14h]
  const bignum_st *aa; // [esp+20h] [ebp-10h]
  bignum_ctx *v18; // [esp+28h] [ebp-8h]

  v18 = 0;
  if ( EC_POINT_is_at_infinity(group, a) )
  {
    BN_set_word(&r->Z, 0);
    r->Z_is_one = 0;
    return 1;
  }
  v5 = ctx;
  field_mul = group->meth->field_mul;
  field_sqr = group->meth->field_sqr;
  m = &group->field;
  if ( !ctx )
  {
    v18 = BN_CTX_new();
    v5 = v18;
    if ( !v18 )
      return 0;
  }
  BN_CTX_start(v5);
  v6 = BN_CTX_get(v5);
  v7 = BN_CTX_get(v5);
  ra = BN_CTX_get(v5);
  b = BN_CTX_get(v5);
  if ( b )
  {
    if ( a->Z_is_one )
    {
      aa = &a->X;
      if ( field_sqr(group, v6->vals, &a->X, v5)
        && BN_mod_lshift1_quick(v7->vals, v6->vals, m)
        && BN_mod_add_quick(v6->vals, v6->vals, v7->vals, m) )
      {
        v8 = BN_mod_add_quick(v7->vals, v6->vals, &group->a, m);
LABEL_26:
        if ( v8 )
        {
          if ( a->Z_is_one ? BN_copy(v6->vals, &a->Y) : (bignum_st *)field_mul(group, v6->vals, &a->Y, &a->Z, v5) )
          {
            if ( BN_mod_lshift1_quick(&r->Z, v6->vals, m) )
            {
              r->Z_is_one = 0;
              if ( field_sqr(group, b->vals, &a->Y, v5) )
              {
                if ( field_mul(group, ra->vals, aa, b->vals, v5) )
                {
                  if ( BN_mod_lshift_quick(ra->vals, ra->vals, 2, m) )
                  {
                    if ( BN_mod_lshift1_quick(v6->vals, ra->vals, m) )
                    {
                      if ( field_sqr(group, &r->X, v7->vals, v5) )
                      {
                        if ( BN_mod_sub_quick(&r->X, &r->X, v6->vals, m) )
                        {
                          if ( field_sqr(group, v6->vals, b->vals, v5) )
                          {
                            if ( BN_mod_lshift_quick(b->vals, v6->vals, 3, m) )
                            {
                              if ( BN_mod_sub_quick(v6->vals, ra->vals, &r->X, m) )
                              {
                                if ( field_mul(group, v6->vals, v7->vals, v6->vals, v5) )
                                {
                                  v10 = BN_mod_sub_quick(&r->Y, v6->vals, b->vals, m);
                                  v11 = 1;
                                  if ( v10 )
                                    goto err_203;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if ( group->a_is_minus3 )
    {
      if ( field_sqr(group, v7->vals, &a->Z, v5) )
      {
        aa = &a->X;
        if ( BN_mod_add_quick(v6->vals, &a->X, v7->vals, m) )
        {
          if ( BN_mod_sub_quick(ra->vals, aa, v7->vals, m)
            && field_mul(group, v7->vals, v6->vals, ra->vals, v5)
            && BN_mod_lshift1_quick(v6->vals, v7->vals, m) )
          {
            v8 = BN_mod_add_quick(v7->vals, v6->vals, v7->vals, m);
            goto LABEL_26;
          }
        }
      }
    }
    else
    {
      aa = &a->X;
      if ( field_sqr(group, v6->vals, &a->X, v5)
        && BN_mod_lshift1_quick(v7->vals, v6->vals, m)
        && BN_mod_add_quick(v6->vals, v6->vals, v7->vals, m)
        && field_sqr(group, v7->vals, &a->Z, v5)
        && field_sqr(group, v7->vals, v7->vals, v5)
        && field_mul(group, v7->vals, v7->vals, &group->a, v5) )
      {
        v8 = BN_mod_add_quick(v7->vals, v7->vals, v6->vals, m);
        goto LABEL_26;
      }
    }
  }
  v11 = 0;
err_203:
  BN_CTX_end(v5);
  if ( v18 )
    BN_CTX_free(v18);
  return v11;
}
