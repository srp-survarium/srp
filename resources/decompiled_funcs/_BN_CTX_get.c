bignum_pool_item *__cdecl BN_CTX_get(bignum_ctx *ctx)
{
  bignum_pool_item *v1; // eax
  bignum_pool_item *v2; // edi

  if ( ctx->err_stack || ctx->too_many )
    return 0;
  v1 = BN_POOL_get(&ctx->pool);
  v2 = v1;
  if ( v1 )
  {
    BN_set_word(v1->vals, 0);
    ++ctx->used;
    return v2;
  }
  else
  {
    ctx->too_many = 1;
    ERR_put_error(3u, 116, 109, ".\\crypto\\bn\\bn_ctx.c", 298);
    return 0;
  }
}
