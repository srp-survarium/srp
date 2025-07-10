int __cdecl BN_BLINDING_invert_ex(bignum_st *n, const bignum_st *r, bn_blinding_st *b, bignum_ctx *ctx)
{
  bignum_st *Ai; // eax

  if ( r )
    return BN_mod_mul(n, n, r, b->mod, ctx);
  Ai = b->Ai;
  if ( Ai )
    return BN_mod_mul(n, n, Ai, b->mod, ctx);
  ERR_put_error(3u, 101, 107, ".\\crypto\\bn\\bn_blind.c", 269);
  return 0;
}
