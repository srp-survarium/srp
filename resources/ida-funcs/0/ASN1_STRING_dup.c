asn1_string_st *__cdecl ASN1_STRING_dup(const asn1_string_st *str)
{
  asn1_string_st *v2; // eax
  asn1_string_st *v3; // esi

  if ( !str )
    return 0;
  v2 = ASN1_STRING_new();
  v3 = v2;
  if ( !v2 )
    return 0;
  if ( !ASN1_STRING_copy(v2, str) )
  {
    ASN1_STRING_free(v3);
    return 0;
  }
  return v3;
}
