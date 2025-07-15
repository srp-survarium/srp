evp_pkey_ctx_st *__cdecl EVP_PKEY_CTX_dup(evp_pkey_ctx_st *pctx)
{
  evp_pkey_ctx_st *v2; // eax
  evp_pkey_ctx_st *v3; // edi
  evp_pkey_st *pkey; // eax
  evp_pkey_st *peerkey; // eax

  if ( !pctx->pmeth || !pctx->pmeth->copy )
    return 0;
  if ( pctx->engine && !ENGINE_init(pctx->engine) )
  {
    ERR_put_error(6u, 156, 38, ".\\crypto\\evp\\pmeth_lib.c", 263);
    return 0;
  }
  v2 = (evp_pkey_ctx_st *)CRYPTO_malloc(40, ".\\crypto\\evp\\pmeth_lib.c", 267);
  v3 = v2;
  if ( v2 )
  {
    v2->pmeth = pctx->pmeth;
    v2->engine = pctx->engine;
    pkey = pctx->pkey;
    if ( pkey )
      CRYPTO_add_lock(&pkey->references, 1, 10, ".\\crypto\\evp\\pmeth_lib.c", 277);
    v3->pkey = pctx->pkey;
    peerkey = pctx->peerkey;
    if ( peerkey )
      CRYPTO_add_lock(&peerkey->references, 1, 10, ".\\crypto\\evp\\pmeth_lib.c", 282);
    v3->peerkey = pctx->peerkey;
    v3->data = 0;
    v3->app_data = 0;
    v3->operation = pctx->operation;
    if ( pctx->pmeth->copy(v3, pctx) > 0 )
      return v3;
    EVP_PKEY_CTX_free(v3);
  }
  return 0;
}
