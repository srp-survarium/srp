evp_pkey_ctx_st *__usercall EVP_PKEY_CTX_dup@<eax>(int a1@<ebx>, int a2@<edi>, evp_pkey_ctx_st *pctx)
{
  evp_pkey_ctx_st *v4; // eax
  evp_pkey_ctx_st *v5; // edi
  evp_pkey_st *pkey; // eax
  evp_pkey_st *peerkey; // eax

  if ( !pctx->pmeth || !pctx->pmeth->copy )
    return 0;
  if ( pctx->engine && !ENGINE_init(a2, pctx->engine) )
  {
    ERR_put_error(a1, 6u, 156, 38, ".\\crypto\\evp\\pmeth_lib.c", 263);
    return 0;
  }
  v4 = (evp_pkey_ctx_st *)CRYPTO_malloc(40, ".\\crypto\\evp\\pmeth_lib.c", 267);
  v5 = v4;
  if ( v4 )
  {
    v4->pmeth = pctx->pmeth;
    v4->engine = pctx->engine;
    pkey = pctx->pkey;
    if ( pkey )
      CRYPTO_add_lock(&pkey->references, 1, 10, ".\\crypto\\evp\\pmeth_lib.c", 277);
    v5->pkey = pctx->pkey;
    peerkey = pctx->peerkey;
    if ( peerkey )
      CRYPTO_add_lock(&peerkey->references, 1, 10, ".\\crypto\\evp\\pmeth_lib.c", 282);
    v5->peerkey = pctx->peerkey;
    v5->data = 0;
    v5->app_data = 0;
    v5->operation = pctx->operation;
    if ( pctx->pmeth->copy(v5, pctx) > 0 )
      return v5;
    EVP_PKEY_CTX_free((int)v5, v5);
  }
  return 0;
}
