int __usercall probable_prime_dh@<eax>(
        bignum_st *rnd@<edi>,
        const bignum_st *rem@<ebx>,
        int bits,
        const bignum_st *add,
        bignum_ctx *ctx)
{
  bignum_pool_item *v5; // esi
  const unsigned __int16 *i; // esi
  int v9; // [esp+8h] [ebp-4h]

  v9 = 0;
  BN_CTX_start(ctx);
  v5 = BN_CTX_get(ctx);
  if ( v5 && BN_rand(rnd, bits, 0, 1) && BN_div(0, v5->vals, rnd, add, ctx) && BN_sub(rnd, rnd, v5->vals) )
  {
    if ( rem ? BN_add(rnd, rnd, rem) : BN_add_word(rnd, 1u) )
    {
      while ( 2 )
      {
        for ( i = &primes[1]; ; ++i )
        {
          if ( (int)i >= (int)"%lu:%s:%s:%d:%s\n" )
          {
            v9 = 1;
            goto err_191;
          }
          if ( BN_mod_word(rnd, *i) <= 1 )
            break;
        }
        if ( BN_add(rnd, rnd, add) )
          continue;
        break;
      }
    }
  }
err_191:
  BN_CTX_end(ctx);
  return v9;
}
