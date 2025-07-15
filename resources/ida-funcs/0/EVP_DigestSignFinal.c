BOOL __cdecl EVP_DigestSignFinal(env_md_ctx_st *ctx, unsigned __int8 *sigret, unsigned int *siglen)
{
  evp_pkey_ctx_st *pctx; // eax
  BOOL v4; // ebp
  int v5; // eax
  int v6; // eax
  signed int v8; // eax
  int v9; // [esp+10h] [ebp-64h]
  unsigned int tbslen; // [esp+14h] [ebp-60h] BYREF
  env_md_ctx_st ctxa; // [esp+18h] [ebp-5Ch] BYREF
  unsigned __int8 tbs[64]; // [esp+30h] [ebp-44h] BYREF

  pctx = ctx->pctx;
  v4 = pctx->pmeth->signctx != 0;
  if ( sigret )
  {
    EVP_MD_CTX_init(&ctxa);
    if ( !EVP_MD_CTX_copy_ex((int)sigret, &ctxa, ctx) )
      return 0;
    if ( v4 )
      v5 = ctxa.pctx->pmeth->signctx(ctxa.pctx, sigret, siglen, &ctxa);
    else
      v5 = EVP_DigestFinal_ex((int)siglen, (int)sigret, &ctxa, tbs, &tbslen);
    v9 = v5;
    EVP_MD_CTX_cleanup((int)siglen, (int)sigret, &ctxa);
    if ( v4 || !v9 )
      return v9;
    v6 = EVP_PKEY_sign((int)sigret, ctx->pctx, sigret, siglen, tbs, tbslen);
    return v6 > 0;
  }
  if ( pctx->pmeth->signctx )
  {
    v6 = pctx->pmeth->signctx(pctx, 0, siglen, ctx);
    return v6 > 0;
  }
  v8 = EVP_MD_size(0, ctx->digest);
  return v8 >= 0 && EVP_PKEY_sign(0, ctx->pctx, 0, siglen, 0, v8) > 0;
}
