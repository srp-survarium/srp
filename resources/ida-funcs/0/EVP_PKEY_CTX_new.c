evp_pkey_ctx_st *__usercall EVP_PKEY_CTX_new@<eax>(int a1@<edi>, evp_pkey_st *pkey, engine_st *e)
{
  const evp_pkey_asn1_method_st *ameth; // eax
  int pkey_id; // esi
  void *pkey_meth; // eax
  int v8; // edi
  evp_pkey_ctx_st *v9; // esi
  int (__cdecl *v10)(evp_pkey_ctx_st *); // edi

  if ( !pkey )
    return 0;
  ameth = pkey->ameth;
  if ( !ameth )
    return 0;
  pkey_id = ameth->pkey_id;
  if ( pkey->engine )
    e = pkey->engine;
  if ( e )
  {
    if ( !ENGINE_init(a1, e) )
    {
      ERR_put_error((int)e, 6u, 157, 38, ".\\crypto\\evp\\pmeth_lib.c", 144);
      return 0;
    }
  }
  else
  {
    e = ENGINE_get_pkey_meth_engine(pkey_id);
  }
  if ( e )
    pkey_meth = ENGINE_get_pkey_meth((int)e, e, pkey_id);
  else
    pkey_meth = (void *)EVP_PKEY_meth_find(a1, pkey_id);
  v8 = (int)pkey_meth;
  if ( !pkey_meth )
  {
    ERR_put_error((int)e, 6u, 157, 156, ".\\crypto\\evp\\pmeth_lib.c", 163);
    return 0;
  }
  v9 = (evp_pkey_ctx_st *)CRYPTO_malloc(40, ".\\crypto\\evp\\pmeth_lib.c", 167);
  if ( !v9 )
  {
    if ( e )
      ENGINE_finish(v8, e);
    ERR_put_error((int)e, 6u, 157, 65, ".\\crypto\\evp\\pmeth_lib.c", 174);
    return 0;
  }
  v9->pkey = pkey;
  v9->engine = e;
  v9->pmeth = (const evp_pkey_method_st *)v8;
  v9->operation = 0;
  v9->peerkey = 0;
  v9->pkey_gencb = 0;
  CRYPTO_add_lock(&pkey->references, 1, 10, ".\\crypto\\evp\\pmeth_lib.c", 184);
  v9->data = 0;
  v10 = *(int (__cdecl **)(evp_pkey_ctx_st *))(v8 + 8);
  if ( !v10 || v10(v9) > 0 )
    return v9;
  EVP_PKEY_CTX_free((int)v10, v9);
  return 0;
}
