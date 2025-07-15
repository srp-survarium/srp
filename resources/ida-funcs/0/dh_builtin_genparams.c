int __usercall dh_builtin_genparams@<eax>(dh_st *a1@<ebx>, dh_st *ret, int prime_len, int generator, bn_gencb_st *cb)
{
  bignum_ctx *v5; // eax
  bignum_ctx *v6; // esi
  bignum_pool_item *v7; // ebp
  bignum_pool_item *v8; // eax
  bignum_st *v9; // edi
  bignum_st *v10; // eax
  bignum_st *v11; // eax
  int v12; // edi

  v5 = BN_CTX_new((int)a1);
  v6 = v5;
  if ( !v5 )
    goto LABEL_10;
  BN_CTX_start((int)a1, v5);
  v7 = BN_CTX_get((int)a1, v6);
  v8 = BN_CTX_get((int)a1, v6);
  v9 = (bignum_st *)v8;
  if ( !v7 )
    goto LABEL_10;
  if ( !v8 )
    goto LABEL_10;
  a1 = ret;
  if ( !ret->p )
  {
    v10 = BN_new((int)ret);
    ret->p = v10;
    if ( !v10 )
      goto LABEL_10;
  }
  if ( !ret->g )
  {
    v11 = BN_new((int)ret);
    ret->g = v11;
    if ( !v11 )
      goto LABEL_10;
  }
  a1 = (dh_st *)generator;
  if ( generator <= 1 )
  {
    ERR_put_error(generator, 5u, 106, 101, ".\\crypto\\dh\\dh_gen.c", 122);
    goto LABEL_10;
  }
  if ( generator == 2 )
  {
    if ( !BN_set_word(2, v7->vals, 0x18u) || !BN_set_word(2, v9, 0xBu) )
      goto LABEL_10;
  }
  else if ( generator == 5 )
  {
    if ( !BN_set_word(5, v7->vals, 0xAu) || !BN_set_word(5, v9, 3u) )
      goto LABEL_10;
  }
  else if ( !BN_set_word(generator, v7->vals, 2u) || !BN_set_word(generator, v9, 1u) )
  {
    goto LABEL_10;
  }
  if ( !BN_generate_prime_ex(ret->p, prime_len, 1, v7->vals, v9, cb)
    || !BN_GENCB_call(cb, 3, 0)
    || !BN_set_word(generator, ret->g, generator) )
  {
LABEL_10:
    ERR_put_error((int)a1, 5u, 106, 3, ".\\crypto\\dh\\dh_gen.c", 165);
    v12 = 0;
    goto LABEL_11;
  }
  v12 = 1;
LABEL_11:
  if ( v6 )
  {
    BN_CTX_end(v6);
    BN_CTX_free(v6);
  }
  return v12;
}
