int __usercall x509_cb@<eax>(int a1@<edi>, int a2@<ebx>, int operation, struct ASN1_VALUE_st **pval)
{
  int v4; // esi
  void *v6; // esi

  v4 = (int)*pval;
  if ( operation == 1 )
  {
    *(_DWORD *)(v4 + 12) = 0;
    *(_DWORD *)(v4 + 20) = 0;
    *(_DWORD *)(v4 + 40) = 0;
    *(_DWORD *)(v4 + 32) = -1;
    *(_DWORD *)(v4 + 56) = 0;
    *(_DWORD *)(v4 + 60) = 0;
    *(_DWORD *)(v4 + 100) = 0;
    *(_DWORD *)(v4 + 68) = 0;
    CRYPTO_new_ex_data(0, a2);
    return 1;
  }
  if ( operation == 3 )
  {
    CRYPTO_free_ex_data(a1, a2);
    X509_CERT_AUX_free(*(x509_cert_aux_st **)(v4 + 100));
    ASN1_OCTET_STRING_free(*(asn1_string_st **)(v4 + 56));
    AUTHORITY_KEYID_free(*(AUTHORITY_KEYID_st **)(v4 + 60));
    CRL_DIST_POINTS_free(*(stack_st_DIST_POINT **)(v4 + 68));
    policy_cache_free(*(X509_POLICY_CACHE_st **)(v4 + 64));
    GENERAL_NAMES_free(*(stack_st_GENERAL_NAME **)(v4 + 72));
    NAME_CONSTRAINTS_free(*(NAME_CONSTRAINTS_st **)(v4 + 76));
    v6 = *(void **)(v4 + 20);
    if ( v6 )
    {
      CRYPTO_free(v6);
      return 1;
    }
    return 1;
  }
  if ( operation != 5 )
    return 1;
  if ( *(_DWORD *)(v4 + 20) )
    CRYPTO_free(*(void **)(v4 + 20));
  *(_DWORD *)(v4 + 20) = X509_NAME_oneline(*(X509_name_st **)(*(_DWORD *)v4 + 20), 0, 0);
  return 1;
}
