evp_pkey_ctx_st *__usercall int_ctx_new@<eax>(int id@<ecx>, evp_pkey_st *pkey@<edx>, int a3@<edi>, engine_st *e)
{
  int pkey_id; // esi
  const evp_pkey_asn1_method_st *ameth; // eax
  void *pkey_meth; // eax
  int v10; // edi
  evp_pkey_ctx_st *v11; // esi
  int (__cdecl *v12)(evp_pkey_ctx_st *); // edi

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
    if ( !ENGINE_init(a3, e) )
    {
      ERR_put_error((int)pkey, 6u, 157, 38, ".\\crypto\\evp\\pmeth_lib.c", 144);
      return 0;
    }
  }
  else
  {
    e = ENGINE_get_pkey_meth_engine(pkey_id);
  }
  if ( e )
    pkey_meth = ENGINE_get_pkey_meth((int)pkey, e, pkey_id);
  else
    pkey_meth = (void *)EVP_PKEY_meth_find(a3, pkey_id);
  v10 = (int)pkey_meth;
  if ( !pkey_meth )
  {
    ERR_put_error((int)pkey, 6u, 157, 156, ".\\crypto\\evp\\pmeth_lib.c", 163);
    return 0;
  }
  v11 = (evp_pkey_ctx_st *)CRYPTO_malloc(40, ".\\crypto\\evp\\pmeth_lib.c", 167);
  if ( !v11 )
  {
    if ( e )
      ENGINE_finish(v10, e);
    ERR_put_error((int)pkey, 6u, 157, 65, ".\\crypto\\evp\\pmeth_lib.c", 174);
    return 0;
  }
  v11->engine = e;
  v11->pmeth = (const evp_pkey_method_st *)v10;
  v11->operation = 0;
  v11->pkey = pkey;
  v11->peerkey = 0;
  v11->pkey_gencb = 0;
  if ( pkey )
    CRYPTO_add_lock(&pkey->references, 1, 10, ".\\crypto\\evp\\pmeth_lib.c", 184);
  v11->data = 0;
  v12 = *(int (__cdecl **)(evp_pkey_ctx_st *))(v10 + 8);
  if ( !v12 || v12(v11) > 0 )
    return v11;
  EVP_PKEY_CTX_free((int)v12, v11);
  return 0;
}
