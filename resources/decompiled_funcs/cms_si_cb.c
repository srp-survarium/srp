int __cdecl cms_si_cb(int operation, struct ASN1_VALUE_st **pval)
{
  int v2; // esi
  x509_st *v3; // esi

  if ( operation != 3 )
    return 1;
  v2 = (int)*pval;
  if ( *((_DWORD *)*pval + 8) )
    EVP_PKEY_free(*((evp_pkey_st **)*pval + 8));
  v3 = *(x509_st **)(v2 + 28);
  if ( v3 )
    X509_free(v3);
  return 1;
}
