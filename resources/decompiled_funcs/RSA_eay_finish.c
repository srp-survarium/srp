int __cdecl RSA_eay_finish(rsa_st *rsa)
{
  bn_mont_ctx_st *method_mod_q; // esi

  if ( rsa->_method_mod_n )
    BN_MONT_CTX_free(rsa->_method_mod_n);
  if ( rsa->_method_mod_p )
    BN_MONT_CTX_free(rsa->_method_mod_p);
  method_mod_q = rsa->_method_mod_q;
  if ( method_mod_q )
    BN_MONT_CTX_free(method_mod_q);
  return 1;
}
