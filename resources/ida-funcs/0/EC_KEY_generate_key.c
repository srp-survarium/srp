int __cdecl EC_KEY_generate_key(bignum_ctx *eckey)
{
  bignum_pool_item *tail; // ebx
  bignum_st *used; // edi
  bignum_st *v4; // ebp
  int v6; // [esp+Ch] [ebp-4h]
  bignum_ctx *ctx; // [esp+14h] [ebp+4h]

  tail = 0;
  used = 0;
  v6 = 0;
  if ( eckey && eckey->pool.current )
  {
    v4 = BN_new(0);
    if ( v4 )
    {
      ctx = BN_CTX_new();
      if ( ctx )
      {
        used = (bignum_st *)eckey->pool.used;
        if ( used || (used = BN_new(0)) != 0 )
        {
          if ( EC_GROUP_get_order((const ec_group_st *)eckey->pool.current, v4) )
          {
            while ( BN_rand_range(used, v4) )
            {
              if ( used->top )
              {
                tail = eckey->pool.tail;
                if ( tail || (tail = (bignum_pool_item *)EC_POINT_new((const ec_group_st *)eckey->pool.current)) != 0 )
                {
                  if ( EC_POINT_mul((const ec_group_st *)eckey->pool.current, (ec_point_st *)tail, used, 0, 0, ctx) )
                  {
                    eckey->pool.used = (unsigned int)used;
                    eckey->pool.tail = tail;
                    v6 = 1;
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
        EC_POINT_free((ec_point_st *)tail);
      if ( used && !eckey->pool.used )
        BN_free(used);
      if ( ctx )
        BN_CTX_free(ctx);
    }
    return v6;
  }
  else
  {
    ERR_put_error(0, 0x10u, 179, 67, ".\\crypto\\ec\\ec_key.c", 242);
    return 0;
  }
}
