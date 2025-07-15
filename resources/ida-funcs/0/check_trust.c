int __usercall check_trust@<eax>(x509_store_ctx_st *ctx@<esi>)
{
  int (__cdecl *verify_cb)(int, x509_store_ctx_st *); // ebp
  int v2; // edi
  char *v3; // ebx
  int result; // eax

  verify_cb = ctx->verify_cb;
  v2 = sk_num(&ctx->chain->stack) - 1;
  v3 = sk_value(&ctx->chain->stack, v2);
  result = X509_check_trust((x509_st *)v3, ctx->param->trust, 0);
  if ( result != 1 )
  {
    ctx->error_depth = v2;
    ctx->current_cert = (x509_st *)v3;
    ctx->error = (result == 2) + 27;
    return verify_cb(0, ctx);
  }
  return result;
}
