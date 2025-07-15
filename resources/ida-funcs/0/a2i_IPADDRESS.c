asn1_string_st *__usercall a2i_IPADDRESS@<eax>(int a1@<ebx>, char *ipasc)
{
  int v2; // eax
  int v3; // edi
  asn1_string_st *v4; // esi
  unsigned __int8 d[16]; // [esp+8h] [ebp-14h] BYREF

  strchr(ipasc, 0x3Au);
  if ( v2 )
  {
    if ( ipv6_from_asc((int)d, a1, ipasc) )
    {
      v3 = 16;
      goto LABEL_6;
    }
    return 0;
  }
  if ( !ipv4_from_asc(d, a1, ipasc) )
    return 0;
  v3 = 4;
LABEL_6:
  v4 = ASN1_OCTET_STRING_new();
  if ( !v4 )
    return 0;
  if ( !ASN1_OCTET_STRING_set(v4, d, v3) )
  {
    ASN1_OCTET_STRING_free(v4);
    return 0;
  }
  return v4;
}
