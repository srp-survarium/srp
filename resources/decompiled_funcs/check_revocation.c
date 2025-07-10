int __cdecl check_revocation(x509_store_ctx_st *ctx)
{
  unsigned int flags; // eax
  int v3; // edi
  int v4; // esi

  flags = ctx->param->flags;
  if ( (flags & 4) == 0 )
    return 1;
  if ( (flags & 8) != 0 )
  {
    v3 = sk_num(&ctx->chain->stack) - 1;
  }
  else
  {
    if ( ctx->parent )
      return 1;
    v3 = 0;
  }
  v4 = 0;
  if ( v3 < 0 )
    return 1;
  while ( 1 )
  {
    ctx->error_depth = v4;
    if ( !check_cert(ctx) )
      break;
    if ( ++v4 > v3 )
      return 1;
  }
  return 0;
}
