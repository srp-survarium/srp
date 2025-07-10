bignum_ctx *__cdecl BN_CTX_new()
{
  bignum_ctx *result; // eax

  result = (bignum_ctx *)CRYPTO_malloc(44, ".\\crypto\\bn\\bn_ctx.c", 216);
  if ( result )
  {
    result->pool.tail = 0;
    result->pool.current = 0;
    result->pool.head = 0;
    result->pool.size = 0;
    result->pool.used = 0;
    result->stack.indexes = 0;
    result->stack.size = 0;
    result->stack.depth = 0;
    result->used = 0;
    result->err_stack = 0;
    result->too_many = 0;
  }
  else
  {
    ERR_put_error(3u, 106, 65, ".\\crypto\\bn\\bn_ctx.c", 219);
    return 0;
  }
  return result;
}
