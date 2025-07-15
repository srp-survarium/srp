int __cdecl ec_GF2m_simple_cmp(const ec_group_st *group, const ec_point_st *a, const ec_point_st *b, bignum_ctx *ctx)
{
  int result; // eax
  bignum_ctx *v5; // esi
  bignum_pool_item *v6; // ebp
  bignum_pool_item *v7; // edi
  int v8; // [esp+8h] [ebp-10h]
  bignum_pool_item *x; // [esp+Ch] [ebp-Ch]
  bignum_pool_item *y; // [esp+10h] [ebp-8h]
  bignum_ctx *v11; // [esp+14h] [ebp-4h]

  v11 = 0;
  v8 = -1;
  if ( EC_POINT_is_at_infinity((int)group, group, a) )
    return EC_POINT_is_at_infinity((int)group, group, b) == 0;
  if ( EC_POINT_is_at_infinity((int)group, group, b) )
    return 1;
  if ( a->Z_is_one && b->Z_is_one )
  {
    if ( BN_cmp(&a->X, &b->X) )
      return 1;
    result = BN_cmp(&a->Y, &b->Y);
    if ( result )
      return 1;
  }
  else
  {
    v5 = ctx;
    if ( ctx || (v11 = BN_CTX_new((int)group), (v5 = v11) != 0) )
    {
      BN_CTX_start((int)group, v5);
      v6 = BN_CTX_get((int)group, v5);
      y = BN_CTX_get((int)group, v5);
      x = BN_CTX_get((int)group, v5);
      v7 = BN_CTX_get((int)group, v5);
      if ( v7 )
      {
        if ( EC_POINT_get_affine_coordinates_GF2m((int)group, group, a, v6->vals, y->vals, v5) )
        {
          if ( EC_POINT_get_affine_coordinates_GF2m((int)group, group, b, x->vals, v7->vals, v5) )
          {
            if ( BN_cmp(v6->vals, x->vals) || (v8 = 0, BN_cmp(y->vals, v7->vals)) )
              v8 = 1;
          }
        }
      }
      if ( v5 )
        BN_CTX_end(v5);
      if ( v11 )
        BN_CTX_free(v11);
      return v8;
    }
    else
    {
      return -1;
    }
  }
  return result;
}
