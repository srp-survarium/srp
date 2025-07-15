int __usercall def_crl_lookup@<eax>(
        int a1@<edi>,
        int a2@<ebx>,
        X509_crl_st *crl,
        x509_revoked_st **ret,
        asn1_string_st *serial,
        X509_name_st *issuer)
{
  X509_crl_info_st *v6; // ecx
  int v7; // ebx
  x509_revoked_st *v9; // edi
  asn1_string_st *v10; // [esp+8h] [ebp-18h] BYREF

  v6 = crl->crl;
  v10 = serial;
  if ( !sk_is_sorted(&v6->revoked->stack) )
  {
    CRYPTO_lock(a1, a2, 9, 6, ".\\crypto\\asn1\\x_crl.c", 455);
    sk_sort(a1, &crl->crl->revoked->stack);
    CRYPTO_lock(a1, a2, 10, 6, ".\\crypto\\asn1\\x_crl.c", 457);
  }
  v7 = sk_find(a1, &crl->crl->revoked->stack, (char *)&v10);
  if ( v7 < 0 )
    return 0;
  for ( ; v7 < sk_num(&crl->crl->revoked->stack); ++v7 )
  {
    v9 = (x509_revoked_st *)sk_value(&crl->crl->revoked->stack, v7);
    if ( ASN1_INTEGER_cmp(v9->serialNumber, serial) )
      break;
    if ( crl_revoked_issuer_match(crl, issuer, v9) )
    {
      if ( ret )
        *ret = v9;
      return (v9->reason == 8) + 1;
    }
  }
  return 0;
}
