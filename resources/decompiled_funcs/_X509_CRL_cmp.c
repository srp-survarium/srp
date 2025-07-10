unsigned int __cdecl X509_CRL_cmp(const X509_crl_st *a, const X509_crl_st *b)
{
  return X509_NAME_cmp(a->crl->issuer, b->crl->issuer);
}
