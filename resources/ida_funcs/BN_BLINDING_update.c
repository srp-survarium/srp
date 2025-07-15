int __cdecl BN_BLINDING_update(bn_blinding_st *b, bignum_ctx *ctx)
{
  bignum_st *A; // eax
  int v3; // ebp
  bn_blinding_st *param; // eax
  int result; // eax

  A = b->A;
  v3 = 0;
  if ( b->A && b->Ai )
  {
    if ( b->counter == -1 )
      b->counter = 0;
    if ( ++b->counter == 32 && b->e && (b->flags & 2) == 0 )
    {
      param = BN_BLINDING_create_param(b, 0, 0, ctx, 0, 0);
    }
    else
    {
      if ( (b->flags & 1) != 0 )
      {
LABEL_13:
        v3 = 1;
        goto err_111;
      }
      if ( !BN_mod_mul(A, A, A, b->mod, ctx) )
        goto err_111;
      param = (bn_blinding_st *)BN_mod_mul(b->Ai, b->Ai, b->Ai, b->mod, ctx);
    }
    if ( !param )
      goto err_111;
    goto LABEL_13;
  }
  ERR_put_error(3u, 103, 107, ".\\crypto\\bn\\bn_blind.c", 192);
err_111:
  result = v3;
  if ( b->counter == 32 )
    b->counter = 0;
  return result;
}
