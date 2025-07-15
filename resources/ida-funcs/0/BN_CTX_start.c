void __usercall BN_CTX_start(int a1@<ebx>, bignum_ctx *ctx)
{
  int err_stack; // eax

  err_stack = ctx->err_stack;
  if ( err_stack || ctx->too_many )
  {
    ctx->err_stack = err_stack + 1;
  }
  else if ( !BN_STACK_push(&ctx->stack, ctx->used) )
  {
    ERR_put_error(a1, 3u, 129, 109, ".\\crypto\\bn\\bn_ctx.c", 264);
    ++ctx->err_stack;
  }
}
