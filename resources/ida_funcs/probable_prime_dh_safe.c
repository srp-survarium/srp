int __usercall probable_prime_dh_safe@<eax>(
        bignum_ctx *ctx@<ebx>,
        bignum_st *p,
        int bits,
        const bignum_st *padd,
        const bignum_st *rem)
{
  bignum_pool_item *v5; // esi
  bignum_pool_item *v6; // edi
  bignum_pool_item *v7; // ebp
  int v8; // eax
  const unsigned __int16 *i; // esi
  bignum_ctx *v11; // [esp+0h] [ebp-14h]

  BN_CTX_start(v11);
  v5 = BN_CTX_get(ctx);
  v6 = BN_CTX_get(ctx);
  v7 = BN_CTX_get(ctx);
  if ( !v7
    || !BN_rshift1(v7->vals, padd)
    || !BN_rand(v6->vals, bits - 1, 0, 1)
    || !BN_div(0, v5->vals, v6->vals, v7->vals, ctx)
    || !BN_sub(v6->vals, v6->vals, v5->vals) )
  {
    goto LABEL_20;
  }
  if ( rem )
  {
    if ( !BN_rshift1(v5->vals, rem) )
      goto LABEL_20;
    v8 = BN_add(v6->vals, v6->vals, v5->vals);
  }
  else
  {
    v8 = BN_add_word(v6->vals, 1u);
  }
  if ( v8 && BN_lshift1(p, v6->vals) && BN_add_word(p, 1u) )
  {
    do
    {
      for ( i = &primes[1]; ; ++i )
      {
        if ( (int)i >= (int)"%lu:%s:%s:%d:%s\n" )
        {
          BN_CTX_end(ctx);
          return 1;
        }
        if ( !BN_mod_word(p, *i) || !BN_mod_word(v6->vals, *i) )
          break;
      }
    }
    while ( BN_add(p, p, padd) && BN_add(v6->vals, v6->vals, v7->vals) );
  }
LABEL_20:
  BN_CTX_end(ctx);
  return 0;
}
