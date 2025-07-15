int __cdecl X509_verify_cert(x509_store_ctx_st *ctx)
{
  x509_st *param; // ebx
  int result; // eax
  stack_st_X509 *v4; // eax
  int v5; // ebp
  x509_st *v6; // edi
  x509_st *issuer; // eax
  x509_st *v8; // edi
  int v9; // eax
  char *v10; // eax
  stack_st_X509 *chain; // ecx
  bool v12; // sf
  bool v13; // of
  int (__cdecl *verify)(x509_store_ctx_st *); // eax
  int v15; // eax
  void *p; // [esp+Ch] [ebp-1Ch] BYREF
  stack_st *st; // [esp+10h] [ebp-18h]
  void *data; // [esp+14h] [ebp-14h]
  int v19; // [esp+18h] [ebp-10h]
  x509_st *i; // [esp+1Ch] [ebp-Ch]
  int (__cdecl *verify_cb)(int, x509_store_ctx_st *); // [esp+20h] [ebp-8h]
  x509_st *v22; // [esp+24h] [ebp-4h]
  x509_store_ctx_st *ctxa; // [esp+2Ch] [ebp+4h]
  x509_store_ctx_st *ctxb; // [esp+2Ch] [ebp+4h]

  param = (x509_st *)ctx->param;
  data = 0;
  v19 = 0;
  v22 = param;
  ctxa = 0;
  st = 0;
  if ( !ctx->cert )
  {
    ERR_put_error((int)param, 0xBu, 127, 105, ".\\crypto\\x509\\x509_vfy.c", 165);
    return -1;
  }
  verify_cb = ctx->verify_cb;
  if ( !ctx->chain )
  {
    v4 = (stack_st_X509 *)sk_new_null();
    ctx->chain = v4;
    if ( !v4 || !sk_push(&v4->stack, (char *)ctx->cert) )
    {
      ERR_put_error((int)param, 0xBu, 127, 65, ".\\crypto\\x509\\x509_vfy.c", 178);
      goto end_1;
    }
    CRYPTO_add_lock(&ctx->cert->references, 1, 3, ".\\crypto\\x509\\x509_vfy.c", 181);
    ctx->last_untrusted = 1;
  }
  if ( !ctx->untrusted || (st = sk_dup(&ctx->untrusted->stack)) != 0 )
  {
    v5 = sk_num(&ctx->chain->stack);
    v6 = (x509_st *)sk_value(&ctx->chain->stack, v5 - 1);
    for ( i = (x509_st *)param->ex_pathlen; (int)i >= v5; ++v5 )
    {
      X509_get_issuer_name(v6);
      if ( ctx->check_issued(ctx, v6, v6) )
        break;
      if ( !ctx->untrusted )
        break;
      param = (x509_st *)st;
      issuer = find_issuer((stack_st_X509 *)st, ctx, v6);
      p = issuer;
      if ( !issuer )
        break;
      if ( !sk_push(&ctx->chain->stack, (char *)issuer) )
      {
        ERR_put_error((int)st, 0xBu, 127, 65, ".\\crypto\\x509\\x509_vfy.c", 219);
        goto end_1;
      }
      CRYPTO_add_lock((int *)p + 4, 1, 3, ".\\crypto\\x509\\x509_vfy.c", 222);
      sk_delete_ptr(st, (char *)p);
      ++ctx->last_untrusted;
      v6 = (x509_st *)p;
    }
    param = (x509_st *)(sk_num(&ctx->chain->stack) - 1);
    v8 = (x509_st *)sk_value(&ctx->chain->stack, (int)param);
    X509_get_subject_name(v8);
    if ( ctx->check_issued(ctx, v8, v8) )
    {
      if ( sk_num(&ctx->chain->stack) == 1 )
      {
        v9 = ctx->get_issuer((x509_st **)&p, ctx, v8);
        ctxb = (x509_store_ctx_st *)v9;
        if ( v9 > 0 )
        {
          if ( !X509_cmp((int)v8, v8, (x509_st *)p) )
          {
            X509_free(v8);
            v8 = (x509_st *)p;
            sk_set(&ctx->chain->stack, (int)param, p);
            ctx->last_untrusted = 0;
            goto LABEL_30;
          }
          v9 = (int)ctxb;
        }
        ctx->error = 18;
        ctx->current_cert = v8;
        ctx->error_depth = (int)param;
        if ( v9 == 1 )
          X509_free((x509_st *)p);
        v19 = 1;
        ctxa = (x509_store_ctx_st *)verify_cb(0, ctx);
        if ( !ctxa )
          goto end_1;
      }
      else
      {
        v10 = sk_pop(&ctx->chain->stack);
        chain = ctx->chain;
        --ctx->last_untrusted;
        data = v10;
        v8 = (x509_st *)sk_value(&chain->stack, --v5 - 1);
      }
    }
LABEL_30:
    for ( param = i; (int)param >= v5; ++v5 )
    {
      X509_get_issuer_name(v8);
      if ( ctx->check_issued(ctx, v8, v8) )
        break;
      result = ctx->get_issuer((x509_st **)&p, ctx, v8);
      if ( result < 0 )
        return result;
      if ( !result )
        break;
      v8 = (x509_st *)p;
      if ( !sk_push(&ctx->chain->stack, (char *)p) )
      {
        X509_free((x509_st *)p);
        ERR_put_error((int)param, 0xBu, 127, 65, ".\\crypto\\x509\\x509_vfy.c", 306);
        return 0;
      }
    }
    X509_get_issuer_name(v8);
    if ( ctx->check_issued(ctx, v8, v8) )
      goto LABEL_65;
    param = (x509_st *)data;
    if ( data && ctx->check_issued(ctx, v8, (x509_st *)data) )
    {
      sk_push(&ctx->chain->stack, (char *)param);
      ctx->last_untrusted = ++v5;
      ctx->current_cert = param;
      ctx->error = 19;
      data = 0;
    }
    else
    {
      v13 = __OFSUB__(ctx->last_untrusted, v5);
      v12 = ctx->last_untrusted - v5 < 0;
      ctx->current_cert = v8;
      ctx->error = (((v12 ^ v13) - 1) & 0x12) + 2;
    }
    ctx->error_depth = v5 - 1;
    v19 = 1;
    ctxa = (x509_store_ctx_st *)verify_cb(0, ctx);
    if ( ctxa )
    {
LABEL_65:
      ctxa = (x509_store_ctx_st *)check_chain_extensions(ctx, (int)v8);
      if ( ctxa )
      {
        ctxa = (x509_store_ctx_st *)check_name_constraints(ctx);
        if ( ctxa )
        {
          if ( v22->ex_data.dummy > 0 )
            ctxa = (x509_store_ctx_st *)check_trust(ctx);
          if ( ctxa )
          {
            X509_get_pubkey_parameters((int)param, 0, ctx->chain);
            ctxa = (x509_store_ctx_st *)ctx->check_revocation(ctx);
            if ( ctxa )
            {
              verify = ctx->verify;
              v15 = verify ? verify(ctx) : internal_verify(ctx);
              ctxa = (x509_store_ctx_st *)v15;
              if ( v15 )
              {
                if ( !v19 && SLOBYTE(ctx->param->flags) < 0 )
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
  ERR_put_error((int)param, 0xBu, 127, 65, ".\\crypto\\x509\\x509_vfy.c", 189);
end_1:
  X509_get_pubkey_parameters((int)param, 0, ctx->chain);
LABEL_57:
  if ( st )
    sk_free(st);
  if ( data )
    X509_free((x509_st *)data);
  return (int)ctxa;
}
