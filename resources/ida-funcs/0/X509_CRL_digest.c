int __usercall X509_CRL_digest@<eax>(
        int a1@<edi>,
        X509_crl_st *data,
        const env_md_st *type,
        unsigned __int8 *md,
        unsigned int *len)
{
  const ASN1_ITEM_st *v5; // eax

  v5 = X509_CRL_it();
  return ASN1_item_digest(a1, v5, type, (struct ASN1_VALUE_st *)data, md, len);
}
