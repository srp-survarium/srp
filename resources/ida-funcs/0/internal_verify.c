int __cdecl internal_verify(x509_store_ctx_st *ctx)
{
  int (__cdecl *verify_cb)(int, x509_store_ctx_st *); // edi
  int v3; // ebp
  x509_st *v4; // ebx
  x509_st *v5; // edi
  int result; // eax
  evp_pkey_st *pubkey; // eax
  stack_st_X509 *v8; // [esp-Ch] [ebp-24h]
  stack_st_X509 *v9; // [esp-8h] [ebp-20h]
  stack_st_X509 *chain; // [esp-4h] [ebp-1Ch]
  int v11; // [esp+10h] [ebp-8h]
  evp_pkey_st *x; // [esp+14h] [ebp-4h]
  x509_store_ctx_st *ctxa; // [esp+1Ch] [ebp+4h]

  verify_cb = ctx->verify_cb;
  chain = ctx->chain;
  ctxa = (x509_store_ctx_st *)verify_cb;
  v3 = sk_num(&chain->stack) - 1;
  v8 = ctx->chain;
  ctx->error_depth = v3;
  v11 = v3;
  v4 = (x509_st *)sk_value(&v8->stack, v3);
  if ( ctx->check_issued(ctx, v4, v4) )
  {
    v5 = v4;
  }
  else
  {
    if ( v3 <= 0 )
    {
      ctx->error = 21;
      ctx->current_cert = v4;
      return verify_cb(0, ctx);
    }
    --v3;
    v9 = ctx->chain;
    v11 = v3;
    ctx->error_depth = v3;
    v5 = (x509_st *)sk_value(&v9->stack, v3);
  }
  if ( v3 >= 0 )
  {
    while ( 1 )
    {
      ctx->error_depth = v3;
      if ( !v5->valid && (v5 != v4 || (ctx->param->flags & 0x4000) != 0) )
      {
        pubkey = X509_get_pubkey(v4);
        x = pubkey;
        if ( pubkey )
        {
          if ( X509_verify(v5, pubkey) <= 0 )
          {
            ctx->error = 7;
            ctx->current_cert = v5;
            if ( !((int (__cdecl *)(_DWORD, x509_store_ctx_st *))ctxa)(0, ctx) )
            {
              EVP_PKEY_free(x);
              return 0;
            }
            v3 = v11;
          }
        }
        else
        {
          ctx->error = 6;
          ctx->current_cert = v4;
          result = ((int (__cdecl *)(_DWORD, x509_store_ctx_st *))ctxa)(0, ctx);
          if ( !result )
            return result;
        }
        EVP_PKEY_free(x);
      }
      v5->valid = 1;
      result = check_cert_time(ctx, v5);
      if ( !result )
        return result;
      ctx->current_issuer = v4;
      ctx->current_cert = v5;
      result = ((int (__cdecl *)(int, x509_store_ctx_st *))ctxa)(1, ctx);
      if ( !result )
        return result;
      v11 = --v3;
      if ( v3 < 0 )
        return 1;
      v4 = v5;
      v5 = (x509_st *)sk_value(&ctx->chain->stack, v3);
    }
  }
  return 1;
}
