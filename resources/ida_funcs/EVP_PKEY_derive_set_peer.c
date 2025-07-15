int __cdecl EVP_PKEY_derive_set_peer(evp_pkey_ctx_st *ctx, evp_pkey_st *peer)
{
  const evp_pkey_method_st *pmeth; // eax
  int (__cdecl *ctrl)(evp_pkey_ctx_st *, int, int, void *); // eax
  int operation; // ecx
  int result; // eax
  evp_pkey_st *pkey; // eax
  const evp_pkey_method_st *v7; // edx

  if ( !ctx
    || (pmeth = ctx->pmeth) == 0
    || !pmeth->derive && !pmeth->encrypt && !pmeth->decrypt
    || (ctrl = pmeth->ctrl) == 0 )
  {
    ERR_put_error(6u, 155, 150, ".\\crypto\\evp\\pmeth_fn.c", 291);
    return -2;
  }
  operation = ctx->operation;
  if ( operation != 1024 && operation != 256 && operation != 512 )
  {
    ERR_put_error(6u, 155, 151, ".\\crypto\\evp\\pmeth_fn.c", 297);
    return -1;
  }
  result = ctrl(ctx, 2, 0, peer);
  if ( result > 0 )
  {
    if ( result != 2 )
    {
      pkey = ctx->pkey;
      if ( !pkey )
      {
        ERR_put_error(6u, 155, 154, ".\\crypto\\evp\\pmeth_fn.c", 311);
        return -1;
      }
      if ( pkey->type != peer->type )
      {
        ERR_put_error(6u, 155, 101, ".\\crypto\\evp\\pmeth_fn.c", 318);
        return -1;
      }
      if ( !EVP_PKEY_missing_parameters(peer) && !EVP_PKEY_cmp_parameters(ctx->pkey, peer) )
      {
        ERR_put_error(6u, 155, 153, ".\\crypto\\evp\\pmeth_fn.c", 331);
        return -1;
      }
      if ( ctx->peerkey )
        EVP_PKEY_free(ctx->peerkey);
      v7 = ctx->pmeth;
      ctx->peerkey = peer;
      result = v7->ctrl(ctx, 2, 1, peer);
      if ( result <= 0 )
      {
        ctx->peerkey = 0;
        return result;
      }
      CRYPTO_add_lock(&peer->references, 1, 10, ".\\crypto\\evp\\pmeth_fn.c", 347);
    }
    return 1;
  }
  return result;
}
