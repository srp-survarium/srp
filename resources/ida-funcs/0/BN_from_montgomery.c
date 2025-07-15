int __cdecl BN_from_montgomery(bignum_st *ret, const bignum_st *a, bn_mont_ctx_st *mont, bignum_ctx *ctx)
{
  int v4; // ebx
  bignum_pool_item *v5; // esi

  v4 = 0;
  BN_CTX_start(ctx);
  v5 = BN_CTX_get(ctx);
  if ( v5 && BN_copy(v5->vals, a) )
    v4 = BN_from_montgomery_word(ret, v5->vals, mont);
  BN_CTX_end(ctx);
  return v4;
}
