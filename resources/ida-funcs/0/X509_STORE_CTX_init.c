int __cdecl X509_STORE_CTX_init(x509_store_ctx_st *ctx, x509_store_st *store, x509_st *x509, stack_st_X509 *chain)
{
  stack_st_X509_CRL *(__cdecl *lookup_crls)(x509_store_ctx_st *, X509_name_st *); // edi
  X509_VERIFY_PARAM_st *v5; // eax
  int v7; // eax
  const X509_VERIFY_PARAM_st *v8; // eax
  int (__cdecl *check_issued)(x509_store_ctx_st *, x509_st *, x509_st *); // eax
  int (__cdecl *get_issuer)(x509_st **, x509_store_ctx_st *, x509_st *); // eax
  int (__cdecl *verify_cb)(int, x509_store_ctx_st *); // eax
  int (__cdecl *verify)(x509_store_ctx_st *); // eax
  int (__cdecl *check_revocation)(x509_store_ctx_st *); // eax
  int (__cdecl *get_crl)(x509_store_ctx_st *, X509_crl_st **, x509_st *); // eax
  int (__cdecl *check_crl)(x509_store_ctx_st *, X509_crl_st *); // eax
  int (__cdecl *cert_crl)(x509_store_ctx_st *, X509_crl_st *, x509_st *); // eax
  stack_st_X509 *(__cdecl *lookup_certs)(x509_store_ctx_st *, X509_name_st *); // eax

  lookup_crls = (stack_st_X509_CRL *(__cdecl *)(x509_store_ctx_st *, X509_name_st *))store;
  ctx->ctx = store;
  ctx->current_method = 0;
  ctx->cert = x509;
  ctx->untrusted = chain;
  ctx->crls = 0;
  ctx->last_untrusted = 0;
  ctx->other_ctx = 0;
  ctx->valid = 0;
  ctx->chain = 0;
  ctx->error = 0;
  ctx->explicit_policy = 0;
  ctx->error_depth = 0;
  ctx->current_cert = 0;
  ctx->current_issuer = 0;
  ctx->current_crl = 0;
  ctx->current_crl_score = 0;
  ctx->current_reasons = 0;
  ctx->tree = 0;
  ctx->parent = 0;
  v5 = X509_VERIFY_PARAM_new();
  ctx->param = v5;
  if ( !v5 )
  {
    ERR_put_error(0, 0xBu, 143, 65, ".\\crypto\\x509\\x509_vfy.c", 2029);
    return 0;
  }
  if ( store )
  {
    v7 = X509_VERIFY_PARAM_inherit(v5, store->param);
    ctx->verify_cb = store->verify_cb;
    ctx->cleanup = store->cleanup;
    if ( !v7 )
    {
LABEL_7:
      ERR_put_error(0, 0xBu, 143, 65, ".\\crypto\\x509\\x509_vfy.c", 2057);
      return 0;
    }
  }
  else
  {
    v5->inh_flags |= 0x11u;
    ctx->cleanup = 0;
  }
  v8 = X509_VERIFY_PARAM_lookup("default");
  if ( !X509_VERIFY_PARAM_inherit(ctx->param, v8) )
    goto LABEL_7;
  if ( store && (check_issued = store->check_issued) != 0 )
    ctx->check_issued = check_issued;
  else
    ctx->check_issued = ::check_issued;
  if ( store && (get_issuer = store->get_issuer) != 0 )
    ctx->get_issuer = get_issuer;
  else
    ctx->get_issuer = X509_STORE_CTX_get1_issuer;
  if ( store && (verify_cb = store->verify_cb) != 0 )
    ctx->verify_cb = verify_cb;
  else
    ctx->verify_cb = (int (__cdecl *)(int, x509_store_ctx_st *))null_callback;
  if ( store && (verify = store->verify) != 0 )
    ctx->verify = verify;
  else
    ctx->verify = internal_verify;
  if ( store && (check_revocation = store->check_revocation) != 0 )
    ctx->check_revocation = check_revocation;
  else
    ctx->check_revocation = ::check_revocation;
  if ( store && (get_crl = store->get_crl) != 0 )
    ctx->get_crl = get_crl;
  else
    ctx->get_crl = 0;
  if ( store && (check_crl = store->check_crl) != 0 )
    ctx->check_crl = check_crl;
  else
    ctx->check_crl = ::check_crl;
  if ( store && (cert_crl = store->cert_crl) != 0 )
    ctx->cert_crl = cert_crl;
  else
    ctx->cert_crl = ::cert_crl;
  if ( store && (lookup_certs = store->lookup_certs) != 0 )
    ctx->lookup_certs = lookup_certs;
  else
    ctx->lookup_certs = (stack_st_X509 *(__cdecl *)(x509_store_ctx_st *, X509_name_st *))X509_STORE_get1_certs;
  if ( store && (lookup_crls = store->lookup_crls) != 0 )
    ctx->lookup_crls = lookup_crls;
  else
    ctx->lookup_crls = (stack_st_X509_CRL *(__cdecl *)(x509_store_ctx_st *, X509_name_st *))X509_STORE_get1_crls;
  ctx->check_policy = (int (__cdecl *)(x509_store_ctx_st *))check_policy;
  if ( CRYPTO_new_ex_data((int)lookup_crls, 0) )
    return 1;
  CRYPTO_free(ctx);
  ERR_put_error(0, 0xBu, 143, 65, ".\\crypto\\x509\\x509_vfy.c", 2122);
  return 0;
}
