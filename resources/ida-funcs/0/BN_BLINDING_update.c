int __usercall BN_BLINDING_update@<eax>(int a1@<ebx>, bn_blinding_st *b, bignum_ctx *ctx)
{
  bignum_pool_item *A; // eax
  int v4; // ebp
  bn_blinding_st *param; // eax
  int result; // eax

  A = (bignum_pool_item *)b->A;
  v4 = 0;
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
        v4 = 1;
        goto err_113;
      }
      if ( !BN_mod_mul(A->vals, A, A, b->mod, ctx) )
        goto err_113;
      param = (bn_blinding_st *)BN_mod_mul(b->Ai, (bignum_pool_item *)b->Ai, (bignum_pool_item *)b->Ai, b->mod, ctx);
    }
    if ( !param )
      goto err_113;
    goto LABEL_13;
  }
  ERR_put_error(a1, 3u, 103, 107, ".\\crypto\\bn\\bn_blind.c", 192);
err_113:
  result = v4;
  if ( b->counter == 32 )
    b->counter = 0;
  return result;
}
