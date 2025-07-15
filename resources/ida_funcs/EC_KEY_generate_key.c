int __cdecl EC_KEY_generate_key(bignum_ctx *eckey)
{
  ec_point_st *tail; // ebx
  bignum_st *used; // edi
  bignum_st *v4; // ebp
  bignum_ctx *v5; // eax
  int v7; // [esp+Ch] [ebp-4h]
  bignum_ctx *ctx; // [esp+14h] [ebp+4h]

  tail = 0;
  used = 0;
  v7 = 0;
  if ( eckey && eckey->pool.current )
  {
    v4 = BN_new();
    if ( !v4 )
      return v7;
    v5 = BN_CTX_new();
    ctx = v5;
    if ( v5 )
    {
      used = (bignum_st *)eckey->pool.used;
      if ( used )
        goto LABEL_8;
      used = BN_new();
      if ( used )
      {
        v5 = ctx;
LABEL_8:
        if ( EC_GROUP_get_order((const ec_group_st *)eckey->pool.current, v4, v5) )
        {
          while ( BN_rand_range(used, v4) )
          {
            if ( used->top )
            {
              tail = (ec_point_st *)eckey->pool.tail;
              if ( tail || (tail = EC_POINT_new((const ec_group_st *)eckey->pool.current)) != 0 )
              {
                if ( EC_POINT_mul((const ec_group_st *)eckey->pool.current, tail, used, 0, 0, ctx) )
                {
                  eckey->pool.used = (unsigned int)used;
                  eckey->pool.tail = (bignum_pool_item *)tail;
                  v7 = 1;
                }
              }
              break;
            }
          }
        }
      }
    }
    BN_free(v4);
    if ( tail && !eckey->pool.tail )
      EC_POINT_free(tail);
    if ( used && !eckey->pool.used )
      BN_free(used);
    if ( ctx )
      BN_CTX_free(ctx);
    return v7;
  }
  ERR_put_error(0x10u, 179, 67, ".\\crypto\\ec\\ec_key.c", 242);
  return 0;
}
