int __cdecl EC_GROUP_cmp(bignum_st *a, bignum_st *b, bignum_ctx *ctx)
{
  int dmax; // ecx
  int v7; // eax
  bignum_ctx *v8; // esi
  bignum_pool_item *v9; // edi
  bignum_ctx *v10; // [esp-8h] [ebp-28h]
  bignum_ctx *v11; // [esp+Ch] [ebp-14h]
  bignum_pool_item *cofactor; // [esp+10h] [ebp-10h]
  bignum_pool_item *v13; // [esp+14h] [ebp-Ch]
  int v14; // [esp+18h] [ebp-8h]
  bignum_pool_item *v15; // [esp+1Ch] [ebp-4h]
  bignum_pool_item *ba; // [esp+24h] [ebp+4h]
  bignum_pool_item *aa; // [esp+28h] [ebp+8h]

  v14 = 0;
  v11 = 0;
  if ( *a->d != *b->d )
    return 1;
  dmax = a[2].dmax;
  if ( dmax )
  {
    v7 = b[2].dmax;
    if ( v7 )
    {
      if ( dmax == v7 )
        return 0;
    }
  }
  v8 = ctx;
  if ( !ctx )
  {
    v8 = BN_CTX_new();
    v11 = v8;
    if ( !v8 )
      return -1;
  }
  BN_CTX_start(v8);
  aa = BN_CTX_get(v8);
  cofactor = BN_CTX_get(v8);
  v15 = BN_CTX_get(v8);
  ba = BN_CTX_get(v8);
  v13 = BN_CTX_get(v8);
  v9 = BN_CTX_get(v8);
  v10 = v8;
  if ( !v9 )
  {
LABEL_27:
    BN_CTX_end(v10);
    if ( v11 )
      BN_CTX_free(v8);
    return -1;
  }
  if ( !(*((int (__cdecl **)(bignum_st *, bignum_pool_item *, bignum_pool_item *, bignum_pool_item *, bignum_ctx *))a->d
         + 6))(
          a,
          aa,
          cofactor,
          v15,
          v8)
    || !(*((int (__cdecl **)(bignum_st *, bignum_pool_item *, bignum_pool_item *, bignum_pool_item *, bignum_ctx *))b->d
         + 6))(
          b,
          ba,
          v13,
          v9,
          v8)
    || BN_cmp(aa->vals, ba->vals)
    || BN_cmp(cofactor->vals, v13->vals)
    || BN_cmp(v15->vals, v9->vals)
    || EC_POINT_cmp((const ec_group_st *)a, (const ec_point_st *)a->top, (const ec_point_st *)b->top, v8) )
  {
    goto LABEL_22;
  }
  if ( !EC_GROUP_get_order((const ec_group_st *)a, aa->vals)
    || !EC_GROUP_get_order((const ec_group_st *)b, ba->vals)
    || !EC_GROUP_get_cofactor((const ec_group_st *)a, cofactor->vals)
    || !EC_GROUP_get_cofactor((const ec_group_st *)b, v13->vals) )
  {
    v10 = v8;
    goto LABEL_27;
  }
  if ( BN_cmp(aa->vals, ba->vals) || BN_cmp(cofactor->vals, v13->vals) )
LABEL_22:
    v14 = 1;
  BN_CTX_end(v8);
  if ( v11 )
    BN_CTX_free(v8);
  return v14;
}
