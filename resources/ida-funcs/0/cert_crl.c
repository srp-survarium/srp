int __cdecl cert_crl(x509_store_ctx_st *ctx, x509_revoked_st *crl, x509_st *x)
{
  X509_crl_st *v3; // edi
  int (__cdecl *verify_cb)(int, x509_store_ctx_st *); // ecx
  int (__cdecl *v6)(int, x509_store_ctx_st *); // edx

  v3 = (X509_crl_st *)crl;
  if ( (crl->reason & 0x200) != 0 )
  {
    if ( (ctx->param->flags & 0x10) != 0 )
      return 1;
    verify_cb = ctx->verify_cb;
    ctx->error = 36;
    if ( !verify_cb(0, ctx) )
      return 0;
  }
  if ( X509_CRL_get0_by_cert(v3, &crl, x) )
  {
    if ( crl->reason == 8 )
      return 2;
    v6 = ctx->verify_cb;
    ctx->error = 23;
    if ( !v6(0, ctx) )
      return 0;
  }
  return 1;
}
