int __cdecl ri_cb(int operation, struct ASN1_VALUE_st **pval)
{
  if ( operation == 3 )
    X509_free(*((x509_st **)*pval + 4));
  return 1;
}
