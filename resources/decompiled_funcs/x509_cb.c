int __usercall x509_cb@<eax>(unsigned int a1@<edi>, int operation, struct ASN1_VALUE_st **pval)
{
  int v3; // esi
  void *v5; // esi

  v3 = (int)*pval;
  if ( operation == 1 )
  {
    *(_DWORD *)(v3 + 12) = 0;
    *(_DWORD *)(v3 + 20) = 0;
    *(_DWORD *)(v3 + 40) = 0;
    *(_DWORD *)(v3 + 32) = -1;
    *(_DWORD *)(v3 + 56) = 0;
    *(_DWORD *)(v3 + 60) = 0;
    *(_DWORD *)(v3 + 100) = 0;
    *(_DWORD *)(v3 + 68) = 0;
    CRYPTO_new_ex_data(0);
    return 1;
  }
  if ( operation == 3 )
  {
    CRYPTO_free_ex_data(a1);
    X509_CERT_AUX_free(*(x509_cert_aux_st **)(v3 + 100));
    ASN1_OCTET_STRING_free(*(asn1_string_st **)(v3 + 56));
    AUTHORITY_KEYID_free(*(AUTHORITY_KEYID_st **)(v3 + 60));
    CRL_DIST_POINTS_free(*(stack_st_DIST_POINT **)(v3 + 68));
    policy_cache_free(*(X509_POLICY_CACHE_st **)(v3 + 64));
    GENERAL_NAMES_free(*(stack_st_GENERAL_NAME **)(v3 + 72));
    NAME_CONSTRAINTS_free(*(NAME_CONSTRAINTS_st **)(v3 + 76));
    v5 = *(void **)(v3 + 20);
    if ( v5 )
    {
      CRYPTO_free(v5);
      return 1;
    }
    return 1;
  }
  if ( operation != 5 )
    return 1;
  if ( *(_DWORD *)(v3 + 20) )
    CRYPTO_free(*(void **)(v3 + 20));
  *(_DWORD *)(v3 + 20) = X509_NAME_oneline(*(X509_name_st **)(*(_DWORD *)v3 + 20), 0, 0);
  return 1;
}
