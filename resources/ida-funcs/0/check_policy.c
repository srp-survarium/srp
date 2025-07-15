int __usercall check_policy@<eax>(int a1@<ebx>, x509_store_ctx_st *ctx)
{
  int v2; // eax
  int v4; // edi
  x509_st *v5; // eax
  int (__cdecl *verify_cb)(int, x509_store_ctx_st *); // edx
  int (__cdecl *v7)(int, x509_store_ctx_st *); // ecx
  int (__cdecl *v8)(int, x509_store_ctx_st *); // eax

  if ( !ctx->parent )
  {
    v2 = X509_policy_check(&ctx->tree, &ctx->explicit_policy, ctx->chain, ctx->param->policies);
    switch ( v2 )
    {
      case 0:
        ERR_put_error(a1, 0xBu, 145, 65, ".\\crypto\\x509\\x509_vfy.c", 1493);
        return 0;
      case -1:
        v4 = 1;
        if ( sk_num(&ctx->chain->stack) > 1 )
        {
          while ( 1 )
          {
            v5 = (x509_st *)sk_value(&ctx->chain->stack, v4);
            if ( (v5->ex_flags & 0x800) != 0 )
            {
              verify_cb = ctx->verify_cb;
              ctx->current_cert = v5;
              ctx->error = 42;
              if ( !verify_cb(0, ctx) )
                break;
            }
            if ( ++v4 >= sk_num(&ctx->chain->stack) )
              return 1;
          }
          return 0;
        }
        break;
      case -2:
        v7 = ctx->verify_cb;
        ctx->current_cert = 0;
        ctx->error = 43;
        return v7(0, ctx);
      default:
        if ( (ctx->param->flags & 0x800) != 0 )
        {
          v8 = ctx->verify_cb;
          ctx->current_cert = 0;
          ctx->error = 0;
          if ( !v8(2, ctx) )
            return 0;
        }
        break;
    }
  }
  return 1;
}
