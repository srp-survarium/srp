void __usercall RSA_free(unsigned int a1@<edi>, rsa_st *r)
{
  int (__cdecl *finish)(rsa_st *); // eax

  if ( r && CRYPTO_add_lock(&r->references, -1, 9, ".\\crypto\\rsa\\rsa_lib.c", 214) <= 0 )
  {
    finish = r->meth->finish;
    if ( finish )
      finish(r);
    if ( r->engine )
      ENGINE_finish(a1, r->engine);
    CRYPTO_free_ex_data(a1);
    if ( r->n )
      BN_clear_free(r->n);
    if ( r->e )
      BN_clear_free(r->e);
    if ( r->d )
      BN_clear_free(r->d);
    if ( r->p )
      BN_clear_free(r->p);
    if ( r->q )
      BN_clear_free(r->q);
    if ( r->dmp1 )
      BN_clear_free(r->dmp1);
    if ( r->dmq1 )
      BN_clear_free(r->dmq1);
    if ( r->iqmp )
      BN_clear_free(r->iqmp);
    if ( r->blinding )
      BN_BLINDING_free(r->blinding);
    if ( r->mt_blinding )
      BN_BLINDING_free(r->mt_blinding);
    if ( r->bignum_data )
      CRYPTO_free_locked(r->bignum_data);
    CRYPTO_free(r);
  }
}
