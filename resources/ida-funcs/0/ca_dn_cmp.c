unsigned int __cdecl ca_dn_cmp(X509_name_st **a1, X509_name_st **a2)
{
  return X509_NAME_cmp(*a1, *a2);
}
