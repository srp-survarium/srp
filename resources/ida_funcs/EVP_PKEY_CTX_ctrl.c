int __cdecl EVP_PKEY_CTX_ctrl(evp_pkey_ctx_st *ctx, int keytype, int optype, int cmd, int p1, void *p2)
{
  const evp_pkey_method_st *pmeth; // eax
  int (__cdecl *ctrl)(evp_pkey_ctx_st *, int, int, void *); // esi
  int operation; // eax
  int v10; // esi

  if ( ctx && (pmeth = ctx->pmeth) != 0 && (ctrl = pmeth->ctrl) != 0 )
  {
    if ( keytype != -1 && pmeth->pkey_id != keytype )
      return -1;
    operation = ctx->operation;
    if ( !operation )
    {
      ERR_put_error(6u, 137, 149, ".\\crypto\\evp\\pmeth_lib.c", 345);
      return -1;
    }
    if ( optype == -1 || (operation & optype) != 0 )
    {
      v10 = ctrl(ctx, cmd, p1, p2);
      if ( v10 == -2 )
        ERR_put_error(6u, 137, 147, ".\\crypto\\evp\\pmeth_lib.c", 358);
      return v10;
    }
    else
    {
      ERR_put_error(6u, 137, 148, ".\\crypto\\evp\\pmeth_lib.c", 351);
      return -1;
    }
  }
  else
  {
    ERR_put_error(6u, 137, 147, ".\\crypto\\evp\\pmeth_lib.c", 337);
    return -2;
  }
}
