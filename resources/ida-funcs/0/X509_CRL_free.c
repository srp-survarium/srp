void __cdecl X509_CRL_free(X509_crl_st *a)
{
  ASN1_item_free((struct ASN1_VALUE_st *)a, &local_it_7);
}
