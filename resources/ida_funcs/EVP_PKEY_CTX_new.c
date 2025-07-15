evp_pkey_ctx_st *__cdecl EVP_PKEY_CTX_new(evp_pkey_st *pkey, engine_st *e)
{
  const evp_pkey_asn1_method_st *ameth; // eax
  int pkey_id; // esi
  engine_st *pkey_meth; // eax
  const evp_pkey_method_st *v7; // edi
  evp_pkey_ctx_st *v8; // esi
  int (__cdecl *init)(evp_pkey_ctx_st *); // edi

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
  v7 = (const evp_pkey_method_st *)pkey_meth;
  if ( !pkey_meth )
  {
    ERR_put_error(6u, 157, 156, ".\\crypto\\evp\\pmeth_lib.c", 163);
    return 0;
  }
  v8 = (evp_pkey_ctx_st *)CRYPTO_malloc(40, ".\\crypto\\evp\\pmeth_lib.c", 167);
  if ( !v8 )
  {
    if ( e )
      ENGINE_finish(e);
    ERR_put_error(6u, 157, 65, ".\\crypto\\evp\\pmeth_lib.c", 174);
    return 0;
  }
  v8->pkey = pkey;
  v8->engine = e;
  v8->pmeth = v7;
  v8->operation = 0;
  v8->peerkey = 0;
  v8->pkey_gencb = 0;
  CRYPTO_add_lock(&pkey->references, 1, 10, ".\\crypto\\evp\\pmeth_lib.c", 184);
  v8->data = 0;
  init = v7->init;
  if ( !init || init(v8) > 0 )
    return v8;
  EVP_PKEY_CTX_free(v8);
  return 0;
}
