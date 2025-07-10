void __cdecl X509_OBJECT_free_contents(x509_object_st *a)
{
  if ( a->type == 1 )
  {
    X509_free(a->data.x509);
  }
  else if ( a->type == 2 )
  {
    X509_CRL_free(a->data.crl);
  }
}
