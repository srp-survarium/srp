int __cdecl check_crl(x509_store_ctx_st *ctx, X509_crl_st *crl)
{
  int error_depth; // esi
  int v3; // eax
  x509_st *current_issuer; // ebx
  int (__cdecl *verify_cb)(int, x509_store_ctx_st *); // ecx
  int v6; // esi
  int (__cdecl *v7)(int, x509_store_ctx_st *); // edx
  int (__cdecl *v8)(int, x509_store_ctx_st *); // eax
  int (__cdecl *v9)(int, x509_store_ctx_st *); // ecx
  int (__cdecl *v10)(int, x509_store_ctx_st *); // edx
  X509_VERIFY_PARAM_st *param; // eax
  __int64 *p_check_time; // esi
  int v13; // eax
  int (__cdecl *v14)(int, x509_store_ctx_st *); // edx
  int (__cdecl *v15)(int, x509_store_ctx_st *); // eax
  asn1_string_st *nextUpdate; // eax
  int v17; // eax
  int (__cdecl *v18)(int, x509_store_ctx_st *); // edx
  int (__cdecl *v20)(int, x509_store_ctx_st *); // eax
  int (__cdecl *v21)(int, x509_store_ctx_st *); // ecx
  int v22; // eax
  int (__cdecl *v23)(int, x509_store_ctx_st *); // edx
  evp_pkey_st *x; // [esp+Ch] [ebp-4h]

  error_depth = ctx->error_depth;
  x = 0;
  v3 = sk_num(&ctx->chain->stack) - 1;
  if ( ctx->current_issuer )
  {
    current_issuer = ctx->current_issuer;
  }
  else if ( error_depth >= v3 )
  {
    current_issuer = (x509_st *)sk_value(&ctx->chain->stack, v3);
    if ( !ctx->check_issued(ctx, current_issuer, current_issuer) )
    {
      verify_cb = ctx->verify_cb;
      ctx->error = 33;
      v6 = verify_cb(0, ctx);
      if ( !v6 )
        goto err_4;
    }
  }
  else
  {
    current_issuer = (x509_st *)sk_value(&ctx->chain->stack, error_depth + 1);
  }
  if ( !current_issuer )
    goto LABEL_41;
  if ( !crl->base_crl_number )
  {
    if ( (current_issuer->ex_flags & 2) != 0 && (current_issuer->ex_kusage & 2) == 0 )
    {
      v7 = ctx->verify_cb;
      ctx->error = 35;
      v6 = v7(0, ctx);
      if ( !v6 )
        goto err_4;
    }
    if ( SLOBYTE(ctx->current_crl_score) >= 0 )
    {
      v8 = ctx->verify_cb;
      ctx->error = 44;
      v6 = v8(0, ctx);
      if ( !v6 )
        goto err_4;
    }
    if ( (ctx->current_crl_score & 8) == 0 && check_crl_path(ctx, ctx->current_issuer, (int)current_issuer) <= 0 )
    {
      v9 = ctx->verify_cb;
      ctx->error = 54;
      v6 = v9(0, ctx);
      if ( !v6 )
        goto err_4;
    }
    if ( (crl->idp_flags & 2) != 0 )
    {
      v10 = ctx->verify_cb;
      ctx->error = 41;
      v6 = v10(0, ctx);
      if ( !v6 )
        goto err_4;
    }
  }
  if ( (ctx->current_crl_score & 0x40) == 0 )
  {
    param = ctx->param;
    ctx->current_crl = crl;
    if ( (param->flags & 2) != 0 )
      p_check_time = &param->check_time;
    else
      p_check_time = 0;
    v13 = X509_cmp_time(crl->crl->lastUpdate, p_check_time);
    if ( v13 )
    {
      if ( v13 > 0 )
      {
        v15 = ctx->verify_cb;
        ctx->error = 11;
        if ( !v15(0, ctx) )
          goto LABEL_31;
      }
    }
    else
    {
      v14 = ctx->verify_cb;
      ctx->error = 15;
      if ( !v14(0, ctx) )
        goto LABEL_31;
    }
    nextUpdate = crl->crl->nextUpdate;
    if ( nextUpdate )
    {
      v17 = X509_cmp_time(nextUpdate, p_check_time);
      if ( v17 )
      {
        if ( v17 < 0 && (ctx->current_crl_score & 2) == 0 )
        {
          v20 = ctx->verify_cb;
          ctx->error = 12;
          if ( !v20(0, ctx) )
            goto LABEL_31;
        }
      }
      else
      {
        v18 = ctx->verify_cb;
        ctx->error = 16;
        if ( !v18(0, ctx) )
        {
LABEL_31:
          EVP_PKEY_free(0);
          return 0;
        }
      }
    }
    ctx->current_crl = 0;
  }
  x = X509_get_pubkey(current_issuer);
  if ( x )
  {
    if ( X509_CRL_verify(crl) > 0 )
    {
LABEL_41:
      v6 = 1;
      goto err_4;
    }
    v23 = ctx->verify_cb;
    ctx->error = 8;
    v22 = v23(0, ctx);
  }
  else
  {
    v21 = ctx->verify_cb;
    ctx->error = 6;
    v22 = v21(0, ctx);
  }
  v6 = v22;
  if ( v22 )
    goto LABEL_41;
err_4:
  EVP_PKEY_free(x);
  return v6;
}
