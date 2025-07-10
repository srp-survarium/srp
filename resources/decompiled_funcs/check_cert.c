int __thiscall check_cert(x509_store_ctx_st *ctx)
{
  X509_crl_st *v2; // ebx
  x509_st *v3; // ebp
  int (__cdecl *get_crl)(x509_store_ctx_st *, X509_crl_st **, x509_st *); // eax
  int crl_delta; // eax
  int (__cdecl *check_crl)(x509_store_ctx_st *, X509_crl_st *); // ecx
  int v7; // edi
  int v8; // eax
  bool v9; // zf
  int (__cdecl *verify_cb)(int, x509_store_ctx_st *); // ecx
  int result; // eax
  stack_st_X509 *chain; // [esp-8h] [ebp-20h]
  int error_depth; // [esp-4h] [ebp-1Ch]
  X509_crl_st *v14; // [esp-4h] [ebp-1Ch]
  X509_crl_st *pcrl; // [esp+10h] [ebp-8h] BYREF
  X509_crl_st *pdcrl; // [esp+14h] [ebp-4h] BYREF

  error_depth = ctx->error_depth;
  v2 = 0;
  chain = ctx->chain;
  pcrl = 0;
  pdcrl = 0;
  v3 = (x509_st *)sk_value(&chain->stack, error_depth);
  ctx->current_cert = v3;
  ctx->current_issuer = 0;
  ctx->current_crl_score = 0;
  ctx->current_reasons = 0;
  while ( 1 )
  {
    get_crl = ctx->get_crl;
    if ( get_crl )
    {
      crl_delta = get_crl(ctx, &pcrl, v3);
    }
    else
    {
      crl_delta = get_crl_delta(ctx, &pcrl, &pdcrl, v3);
      v2 = pdcrl;
    }
    if ( !crl_delta )
      break;
    check_crl = ctx->check_crl;
    v14 = pcrl;
    ctx->current_crl = pcrl;
    v7 = check_crl(ctx, v14);
    if ( !v7 )
      goto err_3;
    if ( !v2 )
      goto LABEL_11;
    v7 = ctx->check_crl(ctx, v2);
    if ( !v7 )
      goto err_3;
    v8 = ctx->cert_crl(ctx, v2, v3);
    v7 = v8;
    if ( !v8 )
      goto err_3;
    if ( v8 != 2 )
    {
LABEL_11:
      v7 = ctx->cert_crl(ctx, pcrl, v3);
      if ( !v7 )
        goto err_3;
    }
    X509_CRL_free(pcrl);
    X509_CRL_free(v2);
    v2 = 0;
    v9 = ctx->current_reasons == 32895;
    pcrl = 0;
    pdcrl = 0;
    if ( v9 )
      goto err_3;
  }
  verify_cb = ctx->verify_cb;
  ctx->error = 3;
  v7 = verify_cb(0, ctx);
err_3:
  X509_CRL_free(pcrl);
  X509_CRL_free(v2);
  result = v7;
  ctx->current_crl = 0;
  return result;
}
