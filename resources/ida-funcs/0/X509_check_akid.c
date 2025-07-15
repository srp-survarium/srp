int __cdecl X509_check_akid(x509_st *issuer, AUTHORITY_KEYID_st *akid)
{
  const asn1_string_st *v3; // eax
  stack_st_GENERAL_NAME *v4; // edi
  int v5; // esi
  char *v6; // eax
  X509_name_st *v7; // esi
  X509_name_st *issuer_name; // eax
  asn1_string_st *serial; // [esp-8h] [ebp-Ch]

  if ( !akid )
    return 0;
  if ( akid->keyid && issuer->skid && ASN1_OCTET_STRING_cmp(akid->keyid, issuer->skid) )
    return 30;
  if ( akid->serial )
  {
    serial = akid->serial;
    v3 = EVP_CIPHER_CTX_block_size(issuer);
    if ( ASN1_INTEGER_cmp(v3, serial) )
      return 31;
  }
  v4 = akid->issuer;
  if ( !v4 )
    return 0;
  v5 = 0;
  if ( sk_num(&akid->issuer->stack) <= 0 )
    return 0;
  while ( 1 )
  {
    v6 = sk_value(&v4->stack, v5);
    if ( *(_DWORD *)v6 == 4 )
      break;
    if ( ++v5 >= sk_num(&v4->stack) )
      return 0;
  }
  v7 = (X509_name_st *)*((_DWORD *)v6 + 1);
  if ( v7 && (issuer_name = X509_get_issuer_name(issuer), X509_NAME_cmp(v7, issuer_name)) )
    return 31;
  else
    return 0;
}
