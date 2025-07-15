BOOL __usercall do_sigver_init@<eax>(
        env_md_ctx_st *ctx@<esi>,
        engine_st *type@<ecx>,
        evp_pkey_st *pkey@<edi>,
        evp_pkey_ctx_st **pctx,
        engine_st *e,
        int ver)
{
  evp_pkey_ctx_st *v7; // eax
  char *v8; // eax
  evp_pkey_ctx_st *v10; // eax
  int (__cdecl *verifyctx_init)(evp_pkey_ctx_st *, env_md_ctx_st *); // ecx
  int (__cdecl *signctx_init)(evp_pkey_ctx_st *, env_md_ctx_st *); // ecx
  int pnid; // [esp+8h] [ebp-4h] BYREF

  if ( !ctx->pctx )
  {
    v7 = EVP_PKEY_CTX_new((int)pkey, pkey, e);
    ctx->pctx = v7;
    if ( !v7 )
      return 0;
  }
  if ( !type )
  {
    if ( EVP_PKEY_get_default_digest_nid(pkey, &pnid) <= 0
      || (v8 = (char *)OBJ_nid2sn(0, pnid), (type = (engine_st *)EVP_get_digestbyname(v8)) == 0) )
    {
      ERR_put_error((int)type, 6u, 161, 158, ".\\crypto\\evp\\m_sigver.c", 84);
      return 0;
    }
  }
  v10 = ctx->pctx;
  if ( ver )
  {
    verifyctx_init = v10->pmeth->verifyctx_init;
    if ( verifyctx_init )
    {
      if ( verifyctx_init(v10, ctx) <= 0 )
        return 0;
      ctx->pctx->operation = 128;
    }
    else if ( EVP_PKEY_verify_init((int)type, ctx->pctx) <= 0 )
    {
      return 0;
    }
  }
  else
  {
    signctx_init = v10->pmeth->signctx_init;
    if ( signctx_init )
    {
      if ( signctx_init(v10, ctx) <= 0 )
        return 0;
      ctx->pctx->operation = 64;
    }
    else if ( EVP_PKEY_sign_init((int)type, ctx->pctx) <= 0 )
    {
      return 0;
    }
  }
  if ( EVP_PKEY_CTX_ctrl((int)type, ctx->pctx, -1, 248, 1, 0, type) <= 0 )
    return 0;
  if ( pctx )
    *pctx = ctx->pctx;
  return EVP_DigestInit_ex(type, ctx, (const env_md_st *)type, e) != 0;
}
