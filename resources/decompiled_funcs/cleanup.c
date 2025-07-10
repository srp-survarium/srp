void __cdecl cleanup(x509_object_st *a)
{
  if ( a->type == 1 )
  {
    X509_free(a->data.x509);
    CRYPTO_free(a);
  }
  else
  {
    if ( a->type == 2 )
      X509_CRL_free(a->data.crl);
    CRYPTO_free(a);
  }
}
