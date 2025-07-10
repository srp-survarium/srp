evp_pkey_ctx_st *__fastcall int_ctx_new(int id, evp_pkey_st *pkey, engine_st *e)
{
  int pkey_id; // esi
  const evp_pkey_asn1_method_st *ameth; // eax
  engine_st *pkey_meth; // eax
  const evp_pkey_method_st *v9; // edi
  evp_pkey_ctx_st *v10; // esi
  int (__cdecl *init)(evp_pkey_ctx_st *); // edi

  pkey_id = id;
  if ( id == -1 )
  {
    if ( !pkey )
      return 0;
    ameth = pkey->ameth;
    if ( !ameth )
      return 0;
    pkey_id = ameth->pkey_id;
  }
  if ( pkey && pkey->engine )
    e = pkey->engine;
  if ( e )
  {
    if ( !ENGINE_init(e) )
    {
      ERR_put_error(6u, 157, 38, ".\\crypto\\evp\\pmeth_lib.c", 144);
      return 0;
    }
  }
  else
  {
    e = ENGINE_get_pkey_meth_engine(pkey_id);
  }
  if ( e )
    pkey_meth = ENGINE_get_pkey_meth((evp_pkey_method_st *)e, pkey_id);
  else
    pkey_meth = (engine_st *)EVP_PKEY_meth_find(pkey_id);
  v9 = (const evp_pkey_method_st *)pkey_meth;
  if ( !pkey_meth )
  {
    ERR_put_error(6u, 157, 156, ".\\crypto\\evp\\pmeth_lib.c", 163);
    return 0;
  }
  v10 = (evp_pkey_ctx_st *)CRYPTO_malloc(40, ".\\crypto\\evp\\pmeth_lib.c", 167);
  if ( !v10 )
  {
    if ( e )
      ENGINE_finish(e);
    ERR_put_error(6u, 157, 65, ".\\crypto\\evp\\pmeth_lib.c", 174);
    return 0;
  }
  v10->engine = e;
  v10->pmeth = v9;
  v10->operation = 0;
  v10->pkey = pkey;
  v10->peerkey = 0;
  v10->pkey_gencb = 0;
  if ( pkey )
    CRYPTO_add_lock(&pkey->references, 1, 10, ".\\crypto\\evp\\pmeth_lib.c", 184);
  v10->data = 0;
  init = v9->init;
  if ( !init || init(v10) > 0 )
    return v10;
  EVP_PKEY_CTX_free(v10);
  return 0;
}
