int __cdecl EVP_DigestInit_ex(env_md_ctx_st *ctx, const env_md_st *type, engine_st *impl)
{
  engine_st *engine; // eax
  const env_md_st *v4; // edi
  engine_st *digest_engine; // ebx
  const env_md_st *digest; // eax
  const env_md_st *v8; // eax
  bool v9; // zf
  void *v10; // eax
  evp_pkey_ctx_st *pctx; // eax
  int v12; // eax

  EVP_MD_CTX_clear_flags(ctx, 2);
  engine = ctx->engine;
  v4 = type;
  if ( !engine || !ctx->digest || type && type->type != ctx->digest->type )
  {
    if ( type )
    {
      if ( engine )
        ENGINE_finish((unsigned int)type, ctx->engine);
      digest_engine = impl;
      if ( impl )
      {
        if ( !ENGINE_init((unsigned int)type, impl) )
        {
          ERR_put_error(6u, 128, 134, ".\\crypto\\evp\\digest.c", 163);
          return 0;
        }
      }
      else
      {
        digest_engine = ENGINE_get_digest_engine(type->type);
      }
      if ( digest_engine )
      {
        digest = ENGINE_get_digest(digest_engine, type->type);
        if ( !digest )
        {
          ERR_put_error(6u, 128, 134, ".\\crypto\\evp\\digest.c", 177);
          ENGINE_finish((unsigned int)type, digest_engine);
          return 0;
        }
        v4 = digest;
        ctx->engine = digest_engine;
      }
      else
      {
        ctx->engine = 0;
      }
    }
    else if ( !ctx->digest )
    {
      ERR_put_error(6u, 128, 139, ".\\crypto\\evp\\digest.c", 194);
      return 0;
    }
    v8 = ctx->digest;
    if ( ctx->digest != v4 )
    {
      if ( v8 && v8->ctx_size )
        CRYPTO_free(ctx->md_data);
      v9 = (ctx->flags & 0x100) == 0;
      ctx->digest = v4;
      if ( v9 )
      {
        if ( v4->ctx_size )
        {
          ctx->update = v4->update;
          v10 = CRYPTO_malloc(v4->ctx_size, ".\\crypto\\evp\\digest.c", 206);
          ctx->md_data = v10;
          if ( !v10 )
          {
            ERR_put_error(6u, 128, 65, ".\\crypto\\evp\\digest.c", 210);
            return 0;
          }
        }
      }
    }
  }
  pctx = ctx->pctx;
  if ( pctx )
  {
    v12 = EVP_PKEY_CTX_ctrl(pctx, -1, 248, 7, 0, ctx);
    if ( v12 <= 0 && v12 != -2 )
      return 0;
  }
  if ( (ctx->flags & 0x100) != 0 )
    return 1;
  else
    return ctx->digest->init(ctx);
}
