int __cdecl X509_CRL_digest(X509_crl_st *data, const env_md_st *type, unsigned __int8 *md, unsigned int *len)
{
  const ASN1_ITEM_st *v4; // eax

  v4 = X509_CRL_it();
  return ASN1_item_digest(v4, type, data, md, len);
}
