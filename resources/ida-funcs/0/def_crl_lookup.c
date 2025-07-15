int __usercall def_crl_lookup@<eax>(
        unsigned int a1@<edi>,
        X509_crl_st *crl,
        x509_revoked_st **ret,
        asn1_string_st *serial,
        X509_name_st *issuer)
{
  X509_crl_info_st *v5; // ecx
  int v6; // ebx
  x509_revoked_st *v8; // edi
  asn1_string_st *data; // [esp+8h] [ebp-18h] BYREF

  v5 = crl->crl;
  data = serial;
  if ( !sk_is_sorted(&v5->revoked->stack) )
  {
    CRYPTO_lock(a1, 9, 6, ".\\crypto\\asn1\\x_crl.c", 455);
    sk_sort(&crl->crl->revoked->stack);
    CRYPTO_lock(a1, 10, 6, ".\\crypto\\asn1\\x_crl.c", 457);
  }
  v6 = sk_find(&crl->crl->revoked->stack, (char *)&data);
  if ( v6 < 0 )
    return 0;
  for ( ; v6 < sk_num(&crl->crl->revoked->stack); ++v6 )
  {
    v8 = (x509_revoked_st *)sk_value(&crl->crl->revoked->stack, v6);
    if ( ASN1_INTEGER_cmp(v8->serialNumber, serial) )
      break;
    if ( crl_revoked_issuer_match(crl, issuer, v8) )
    {
      if ( ret )
        *ret = v8;
      return (v8->reason == 8) + 1;
    }
  }
  return 0;
}
