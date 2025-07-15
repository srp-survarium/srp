X509_crl_st *__cdecl d2i_X509_CRL_bio(bio_st *bp, X509_crl_st **crl)
{
  const ASN1_ITEM_st *v2; // eax

  v2 = X509_CRL_it();
  return (X509_crl_st *)ASN1_item_d2i_bio(v2, bp, (struct ASN1_VALUE_st **)crl);
}
