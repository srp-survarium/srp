void __cdecl BN_CTX_end(bignum_ctx *ctx)
{
  int err_stack; // eax
  unsigned int used; // edx
  unsigned int v3; // edi

  err_stack = ctx->err_stack;
  if ( err_stack )
  {
    ctx->err_stack = err_stack - 1;
  }
  else
  {
    --ctx->stack.depth;
    used = ctx->used;
    v3 = ctx->stack.indexes[ctx->stack.depth];
    if ( v3 < used )
      BN_POOL_release(&ctx->pool, used - v3);
    ctx->used = v3;
    ctx->too_many = 0;
  }
}
