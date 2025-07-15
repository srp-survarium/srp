x509_st *__cdecl d2i_X509_bio(bio_st *bp, x509_st **x509)
{
  const ASN1_ITEM_st *v2; // eax

  v2 = X509_it();
  return (x509_st *)ASN1_item_d2i_bio(v2, bp, (struct ASN1_VALUE_st **)x509);
}
