asn1_string_st *__usercall ASN1_STRING_dup@<eax>(int a1@<ebx>, const asn1_string_st *str)
{
  asn1_string_st *v3; // eax
  asn1_string_st *v4; // esi

  if ( !str )
    return 0;
  v3 = ASN1_STRING_new(a1);
  v4 = v3;
  if ( !v3 )
    return 0;
  if ( !ASN1_STRING_copy(v3, str) )
  {
    ASN1_STRING_free(v4);
    return 0;
  }
  return v4;
}
