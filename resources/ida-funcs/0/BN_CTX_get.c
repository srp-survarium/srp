bignum_pool_item *__usercall BN_CTX_get@<eax>(int a1@<ebx>, bignum_ctx *ctx)
{
  bignum_pool_item *v2; // eax
  bignum_pool_item *v3; // edi

  if ( ctx->err_stack || ctx->too_many )
    return 0;
  v2 = BN_POOL_get(&ctx->pool);
  v3 = v2;
  if ( v2 )
  {
    BN_set_word(a1, v2->vals, 0);
    ++ctx->used;
    return v3;
  }
  else
  {
    ctx->too_many = 1;
    ERR_put_error(a1, 3u, 116, 109, ".\\crypto\\bn\\bn_ctx.c", 298);
    return 0;
  }
}
