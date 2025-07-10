void __cdecl X509_CERT_AUX_free(x509_cert_aux_st *a)
{
  ASN1_item_free((struct ASN1_VALUE_st *)a, &stru_83CC94);
}
