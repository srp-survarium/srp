asn1_string_st *__cdecl a2i_IPADDRESS(char *ipasc)
{
  int v1; // eax
  int v2; // edi
  asn1_string_st *v3; // esi
  unsigned __int8 v6[16]; // [esp+8h] [ebp-14h] BYREF

  strchr(ipasc, 0x3Au);
  if ( v1 )
  {
    if ( ipv6_from_asc(ipasc) )
    {
      v2 = 16;
      goto LABEL_6;
    }
    return 0;
  }
  if ( !ipv4_from_asc(v6, ipasc) )
    return 0;
  v2 = 4;
LABEL_6:
  v3 = ASN1_OCTET_STRING_new();
  if ( !v3 )
    return 0;
  if ( !ASN1_OCTET_STRING_set(v3, v6, v2) )
  {
    ASN1_OCTET_STRING_free(v3);
    return 0;
  }
  return v3;
}
