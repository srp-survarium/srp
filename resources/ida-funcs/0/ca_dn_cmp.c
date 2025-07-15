unsigned int __cdecl ca_dn_cmp(X509_name_st **a, X509_name_st **b)
{
  return X509_NAME_cmp(*a, *b);
}
