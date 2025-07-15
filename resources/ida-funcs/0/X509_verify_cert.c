int __cdecl X509_verify_cert(x509_store_ctx_st *ctx)
{
  X509_VERIFY_PARAM_st *param; // ebx
  int result; // eax
  stack_st_X509 *v4; // eax
  int v5; // ebp
  x509_st *v6; // edi
  x509_st *issuer; // eax
  int v8; // ebx
  x509_st *v9; // edi
  int v10; // eax
  void *v11; // eax
  stack_st_X509 *chain; // ecx
  int j; // ebx
  x509_st *v14; // ebx
  bool v15; // sf
  bool v16; // of
  int (__cdecl *verify)(x509_store_ctx_st *); // eax
  int v18; // eax
  void *p; // [esp+Ch] [ebp-1Ch] BYREF
  stack_st_X509 *sk; // [esp+10h] [ebp-18h]
  void *data; // [esp+14h] [ebp-14h]
  int v22; // [esp+18h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-Ch]
  int (__cdecl *verify_cb)(int, x509_store_ctx_st *); // [esp+20h] [ebp-8h]
  X509_VERIFY_PARAM_st *v25; // [esp+24h] [ebp-4h]
  x509_store_ctx_st *ctxa; // [esp+2Ch] [ebp+4h]
  x509_store_ctx_st *ctxb; // [esp+2Ch] [ebp+4h]

  param = ctx->param;
  data = 0;
  v22 = 0;
  v25 = param;
  ctxa = 0;
  sk = 0;
  if ( !ctx->cert )
  {
    ERR_put_error(0xBu, 127, 105, ".\\crypto\\x509\\x509_vfy.c", 165);
    return -1;
  }
  verify_cb = ctx->verify_cb;
  if ( !ctx->chain )
  {
    v4 = (stack_st_X509 *)sk_new_null();
    ctx->chain = v4;
    if ( !v4 || !sk_push(&v4->stack, ctx->cert) )
    {
      ERR_put_error(0xBu, 127, 65, ".\\crypto\\x509\\x509_vfy.c", 178);
      goto end_1;
    }
    CRYPTO_add_lock(&ctx->cert->references, 1, 3, ".\\crypto\\x509\\x509_vfy.c", 181);
    ctx->last_untrusted = 1;
  }
  if ( !ctx->untrusted || (sk = (stack_st_X509 *)sk_dup(&ctx->untrusted->stack)) != 0 )
  {
    v5 = sk_num(&ctx->chain->stack);
    v6 = (x509_st *)sk_value(&ctx->chain->stack, v5 - 1);
    for ( i = param->depth; i >= v5; ++v5 )
    {
      X509_get_issuer_name(v6);
      if ( ctx->check_issued(ctx, v6, v6) )
        break;
      if ( !ctx->untrusted )
        break;
      issuer = find_issuer(sk, ctx, v6);
      p = issuer;
      if ( !issuer )
        break;
      if ( !sk_push(&ctx->chain->stack, issuer) )
      {
        ERR_put_error(0xBu, 127, 65, ".\\crypto\\x509\\x509_vfy.c", 219);
        goto end_1;
      }
      CRYPTO_add_lock((int *)p + 4, 1, 3, ".\\crypto\\x509\\x509_vfy.c", 222);
      sk_delete_ptr(&sk->stack, p);
      ++ctx->last_untrusted;
      v6 = (x509_st *)p;
    }
    v8 = sk_num(&ctx->chain->stack) - 1;
    v9 = (x509_st *)sk_value(&ctx->chain->stack, v8);
    X509_get_subject_name(v9);
    if ( ctx->check_issued(ctx, v9, v9) )
    {
      if ( sk_num(&ctx->chain->stack) == 1 )
      {
        v10 = ctx->get_issuer((x509_st **)&p, ctx, v9);
        ctxb = (x509_store_ctx_st *)v10;
        if ( v10 > 0 )
        {
          if ( !X509_cmp(v9, (const x509_st *)p) )
          {
            X509_free(v9);
            v9 = (x509_st *)p;
            sk_set(&ctx->chain->stack, v8, p);
            ctx->last_untrusted = 0;
            goto LABEL_30;
          }
          v10 = (int)ctxb;
        }
        ctx->error = 18;
        ctx->current_cert = v9;
        ctx->error_depth = v8;
        if ( v10 == 1 )
          X509_free((x509_st *)p);
        v22 = 1;
        ctxa = (x509_store_ctx_st *)verify_cb(0, ctx);
        if ( !ctxa )
          goto end_1;
      }
      else
      {
        v11 = sk_pop(&ctx->chain->stack);
        chain = ctx->chain;
        --ctx->last_untrusted;
        data = v11;
        v9 = (x509_st *)sk_value(&chain->stack, --v5 - 1);
      }
    }
LABEL_30:
    for ( j = i; j >= v5; ++v5 )
    {
      X509_get_issuer_name(v9);
      if ( ctx->check_issued(ctx, v9, v9) )
        break;
      result = ctx->get_issuer((x509_st **)&p, ctx, v9);
      if ( result < 0 )
        return result;
      if ( !result )
        break;
      v9 = (x509_st *)p;
      if ( !sk_push(&ctx->chain->stack, p) )
      {
        X509_free((x509_st *)p);
        ERR_put_error(0xBu, 127, 65, ".\\crypto\\x509\\x509_vfy.c", 306);
        return 0;
      }
    }
    X509_get_issuer_name(v9);
    if ( ctx->check_issued(ctx, v9, v9) )
      goto LABEL_65;
    v14 = (x509_st *)data;
    if ( data && ctx->check_issued(ctx, v9, (x509_st *)data) )
    {
      sk_push(&ctx->chain->stack, v14);
      ctx->last_untrusted = ++v5;
      ctx->current_cert = v14;
      ctx->error = 19;
      data = 0;
    }
    else
    {
      v16 = __OFSUB__(ctx->last_untrusted, v5);
      v15 = ctx->last_untrusted - v5 < 0;
      ctx->current_cert = v9;
      ctx->error = (((v15 ^ v16) - 1) & 0x12) + 2;
    }
    ctx->error_depth = v5 - 1;
    v22 = 1;
    ctxa = (x509_store_ctx_st *)verify_cb(0, ctx);
    if ( ctxa )
    {
LABEL_65:
      ctxa = (x509_store_ctx_st *)check_chain_extensions(ctx, (unsigned int)v9);
      if ( ctxa )
      {
        ctxa = (x509_store_ctx_st *)check_name_constraints(ctx);
        if ( ctxa )
        {
          if ( v25->trust > 0 )
            ctxa = (x509_store_ctx_st *)check_trust(ctx);
          if ( ctxa )
          {
            X509_get_pubkey_parameters(0, ctx->chain);
            ctxa = (x509_store_ctx_st *)ctx->check_revocation(ctx);
            if ( ctxa )
            {
              verify = ctx->verify;
              v18 = verify ? verify(ctx) : internal_verify(ctx);
              ctxa = (x509_store_ctx_st *)v18;
              if ( v18 )
              {
                if ( !v22 && SLOBYTE(ctx->param->flags) < 0 )
                  ctxa = (x509_store_ctx_st *)ctx->check_policy(ctx);
                if ( ctxa )
                  goto LABEL_57;
              }
            }
          }
        }
      }
    }
    goto end_1;
  }
  ERR_put_error(0xBu, 127, 65, ".\\crypto\\x509\\x509_vfy.c", 189);
end_1:
  X509_get_pubkey_parameters(0, ctx->chain);
LABEL_57:
  if ( sk )
    sk_free(&sk->stack);
  if ( data )
    X509_free((x509_st *)data);
  return (int)ctxa;
}
