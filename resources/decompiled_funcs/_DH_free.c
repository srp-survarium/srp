void __usercall DH_free(unsigned int a1@<edi>, dh_st *r)
{
  int (__cdecl *finish)(dh_st *); // eax

  if ( r && CRYPTO_add_lock(&r->references, -1, 26, ".\\crypto\\dh\\dh_lib.c", 178) <= 0 )
  {
    finish = r->meth->finish;
    if ( finish )
      finish(r);
    if ( r->engine )
      ENGINE_finish(a1, r->engine);
    CRYPTO_free_ex_data(a1);
    if ( r->p )
      BN_clear_free(r->p);
    if ( r->g )
      BN_clear_free(r->g);
    if ( r->q )
      BN_clear_free(r->q);
    if ( r->j )
      BN_clear_free(r->j);
    if ( r->seed )
      CRYPTO_free(r->seed);
    if ( r->counter )
      BN_clear_free(r->counter);
    if ( r->pub_key )
      BN_clear_free(r->pub_key);
    if ( r->priv_key )
      BN_clear_free(r->priv_key);
    CRYPTO_free(r);
  }
}
