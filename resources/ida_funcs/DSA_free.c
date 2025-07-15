void __usercall DSA_free(unsigned int a1@<edi>, dsa_st *r)
{
  int (__cdecl *finish)(dsa_st *); // eax

  if ( r && CRYPTO_add_lock(&r->references, -1, 8, ".\\crypto\\dsa\\dsa_lib.c", 188) <= 0 )
  {
    finish = r->meth->finish;
    if ( finish )
      finish(r);
    if ( r->engine )
      ENGINE_finish(a1, r->engine);
    CRYPTO_free_ex_data(a1);
    if ( r->p )
      BN_clear_free(r->p);
    if ( r->q )
      BN_clear_free(r->q);
    if ( r->g )
      BN_clear_free(r->g);
    if ( r->pub_key )
      BN_clear_free(r->pub_key);
    if ( r->priv_key )
      BN_clear_free(r->priv_key);
    if ( r->kinv )
      BN_clear_free(r->kinv);
    if ( r->r )
      BN_clear_free(r->r);
    CRYPTO_free(r);
  }
}
