void __cdecl X509_INFO_free(X509_info_st *x)
{
  if ( x && CRYPTO_add_lock(&x->references, -1, 4, ".\\crypto\\asn1\\x_info.c", 93) <= 0 )
  {
    if ( x->x509 )
      X509_free(x->x509);
    if ( x->crl )
      X509_CRL_free(x->crl);
    if ( x->x_pkey )
      X509_PKEY_free(x->x_pkey);
    if ( x->enc_data )
      CRYPTO_free(x->enc_data);
    CRYPTO_free(x);
  }
}
