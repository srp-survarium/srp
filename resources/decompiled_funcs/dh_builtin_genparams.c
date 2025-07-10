int __cdecl dh_builtin_genparams(dh_st *ret, int prime_len, int generator, bn_gencb_st *cb)
{
  bignum_ctx *v4; // eax
  bignum_ctx *v5; // esi
  bignum_pool_item *v6; // ebp
  bignum_pool_item *v7; // eax
  bignum_st *v8; // edi
  bignum_st *v9; // eax
  bignum_st *v10; // eax
  int v11; // edi

  v4 = BN_CTX_new();
  v5 = v4;
  if ( !v4 )
    goto LABEL_10;
  BN_CTX_start(v4);
  v6 = BN_CTX_get(v5);
  v7 = BN_CTX_get(v5);
  v8 = (bignum_st *)v7;
  if ( !v6 )
    goto LABEL_10;
  if ( !v7 )
    goto LABEL_10;
  if ( !ret->p )
  {
    v9 = BN_new();
    ret->p = v9;
    if ( !v9 )
      goto LABEL_10;
  }
  if ( !ret->g )
  {
    v10 = BN_new();
    ret->g = v10;
    if ( !v10 )
      goto LABEL_10;
  }
  if ( generator <= 1 )
  {
    ERR_put_error(5u, 106, 101, ".\\crypto\\dh\\dh_gen.c", 122);
    goto LABEL_10;
  }
  if ( generator == 2 )
  {
    if ( !BN_set_word(v6->vals, 0x18u) || !BN_set_word(v8, 0xBu) )
      goto LABEL_10;
  }
  else if ( generator == 5 )
  {
    if ( !BN_set_word(v6->vals, 0xAu) || !BN_set_word(v8, 3u) )
      goto LABEL_10;
  }
  else if ( !BN_set_word(v6->vals, 2u) || !BN_set_word(v8, 1u) )
  {
    goto LABEL_10;
  }
  if ( !BN_generate_prime_ex(ret->p, prime_len, 1, v6->vals, v8, cb)
    || !BN_GENCB_call(cb, 3, 0)
    || !BN_set_word(ret->g, generator) )
  {
LABEL_10:
    ERR_put_error(5u, 106, 3, ".\\crypto\\dh\\dh_gen.c", 165);
    v11 = 0;
    goto LABEL_11;
  }
  v11 = 1;
LABEL_11:
  if ( v5 )
  {
    BN_CTX_end(v5);
    BN_CTX_free(v5);
  }
  return v11;
}
