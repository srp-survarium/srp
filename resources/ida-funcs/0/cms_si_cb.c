int __usercall cms_si_cb@<eax>(int a1@<edi>, int operation, struct ASN1_VALUE_st **pval)
{
  int v3; // esi
  x509_st *v4; // esi

  if ( operation != 3 )
    return 1;
  v3 = (int)*pval;
  if ( *((_DWORD *)*pval + 8) )
    EVP_PKEY_free(a1, *((evp_pkey_st **)*pval + 8));
  v4 = *(x509_st **)(v3 + 28);
  if ( v4 )
    X509_free(v4);
  return 1;
}
