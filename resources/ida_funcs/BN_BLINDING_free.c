void __cdecl BN_BLINDING_free(bn_blinding_st *r)
{
  if ( r )
  {
    if ( r->A )
      BN_free(r->A);
    if ( r->Ai )
      BN_free(r->Ai);
    if ( r->e )
      BN_free(r->e);
    if ( r->mod )
      BN_free(r->mod);
    CRYPTO_free(r);
  }
}
