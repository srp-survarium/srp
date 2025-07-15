int __cdecl X509_CRL_verify(X509_crl_st *crl)
{
  int (*crl_verify)(void); // eax

  crl_verify = (int (*)(void))crl->meth->crl_verify;
  if ( crl_verify )
    return crl_verify();
  else
    return 0;
}
