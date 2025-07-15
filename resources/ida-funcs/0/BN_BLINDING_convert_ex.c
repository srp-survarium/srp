int __cdecl BN_BLINDING_convert_ex(bignum_pool_item *n, bignum_st *r, bn_blinding_st *b, bignum_ctx *ctx)
{
  int v4; // ebx
  int result; // eax

  v4 = 1;
  if ( !b->A || !b->Ai )
  {
    ERR_put_error(1, 3u, 100, 107, ".\\crypto\\bn\\bn_blind.c", 232);
    return 0;
  }
  if ( b->counter == -1 )
  {
    b->counter = 0;
  }
  else
  {
    result = BN_BLINDING_update(1, b, ctx);
    if ( !result )
      return result;
  }
  if ( r && !BN_copy(r, b->Ai) )
    v4 = 0;
  if ( !BN_mod_mul(n->vals, n, (bignum_pool_item *)b->A, b->mod, ctx) )
    return 0;
  return v4;
}
