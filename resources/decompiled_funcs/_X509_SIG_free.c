void __cdecl X509_SIG_free(X509_sig_st *a)
{
  ASN1_item_free((struct ASN1_VALUE_st *)a, &local_it_65);
}
