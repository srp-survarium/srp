int __usercall BN_BLINDING_invert_ex@<eax>(
        int a1@<ebx>,
        bignum_pool_item *n,
        bignum_pool_item *r,
        bn_blinding_st *b,
        bignum_ctx *ctx)
{
  bignum_pool_item *Ai; // eax

  if ( r )
    return BN_mod_mul(n->vals, n, r, b->mod, ctx);
  Ai = (bignum_pool_item *)b->Ai;
  if ( Ai )
    return BN_mod_mul(n->vals, n, Ai, b->mod, ctx);
  ERR_put_error(a1, 3u, 101, 107, ".\\crypto\\bn\\bn_blind.c", 269);
  return 0;
}
