int __cdecl check_policy(x509_store_ctx_st *ctx)
{
  int v1; // eax
  int v3; // edi
  x509_st *v4; // eax
  int (__cdecl *verify_cb)(int, x509_store_ctx_st *); // edx
  int (__cdecl *v6)(int, x509_store_ctx_st *); // ecx
  int (__cdecl *v7)(int, x509_store_ctx_st *); // eax

  if ( !ctx->parent )
  {
    v1 = X509_policy_check(&ctx->tree, &ctx->explicit_policy, ctx->chain, ctx->param->policies, ctx->param->flags);
    switch ( v1 )
    {
      case 0:
        ERR_put_error(0xBu, 145, 65, ".\\crypto\\x509\\x509_vfy.c", 1493);
        return 0;
      case -1:
        v3 = 1;
        if ( sk_num(&ctx->chain->stack) > 1 )
        {
          while ( 1 )
          {
            v4 = (x509_st *)sk_value(&ctx->chain->stack, v3);
            if ( (v4->ex_flags & 0x800) != 0 )
            {
              verify_cb = ctx->verify_cb;
              ctx->current_cert = v4;
              ctx->error = 42;
              if ( !verify_cb(0, ctx) )
                break;
            }
            if ( ++v3 >= sk_num(&ctx->chain->stack) )
              return 1;
          }
          return 0;
        }
        break;
      case -2:
        v6 = ctx->verify_cb;
        ctx->current_cert = 0;
        ctx->error = 43;
        return v6(0, ctx);
      default:
        if ( (ctx->param->flags & 0x800) != 0 )
        {
          v7 = ctx->verify_cb;
          ctx->current_cert = 0;
          ctx->error = 0;
          if ( !v7(2, ctx) )
            return 0;
        }
        break;
    }
  }
  return 1;
}
