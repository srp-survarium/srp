int __cdecl ec_GF2m_simple_is_on_curve(const ec_group_st *group, const ec_point_st *point, bignum_ctx *ctx)
{
  bignum_ctx *v4; // edi
  bignum_pool_item *v5; // esi
  bignum_st *p_X; // ebp
  int (__cdecl *field_mul)(const ec_group_st *, bignum_st *, const bignum_st *, const bignum_st *, bignum_ctx *); // [esp+8h] [ebp-18h]
  bignum_ctx *v8; // [esp+Ch] [ebp-14h]
  int v9; // [esp+10h] [ebp-10h]
  bignum_pool_item *b; // [esp+18h] [ebp-8h]
  int (__cdecl *field_sqr)(const ec_group_st *, bignum_st *, const bignum_st *, bignum_ctx *); // [esp+1Ch] [ebp-4h]

  v9 = -1;
  v8 = 0;
  if ( EC_POINT_is_at_infinity(group, point) )
    return 1;
  field_mul = group->meth->field_mul;
  field_sqr = group->meth->field_sqr;
  if ( !point->Z_is_one )
    return -1;
  v4 = ctx;
  if ( !ctx )
  {
    v8 = BN_CTX_new();
    v4 = v8;
    if ( !v8 )
      return -1;
  }
  BN_CTX_start(v4);
  b = BN_CTX_get(v4);
  v5 = BN_CTX_get(v4);
  if ( v5 )
  {
    p_X = &point->X;
    if ( BN_GF2m_add(v5->vals, &point->X, &group->a) )
    {
      if ( field_mul(group, v5->vals, v5->vals, p_X, v4)
        && BN_GF2m_add(v5->vals, v5->vals, &point->Y)
        && field_mul(group, v5->vals, v5->vals, p_X, v4)
        && BN_GF2m_add(v5->vals, v5->vals, &group->b)
        && field_sqr(group, b->vals, &point->Y, v4)
        && BN_GF2m_add(v5->vals, v5->vals, b->vals) )
      {
        v9 = v5->vals[0].top == 0;
      }
    }
  }
  if ( v4 )
    BN_CTX_end(v4);
  if ( v8 )
    BN_CTX_free(v8);
  return v9;
}
