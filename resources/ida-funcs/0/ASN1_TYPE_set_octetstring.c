int __cdecl ASN1_TYPE_set_octetstring(asn1_type_st *a, unsigned __int8 *data, int len)
{
  asn1_string_st *v3; // esi

  v3 = ASN1_STRING_type_new(4);
  if ( !v3 || !ASN1_STRING_set(v3, (char *)data, len) )
    return 0;
  ASN1_TYPE_set(a, 4, v3);
  return 1;
}
