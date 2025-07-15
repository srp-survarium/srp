int __usercall ASN1_TYPE_set_octetstring@<eax>(int a1@<ebx>, asn1_type_st *a, const __m128i *data, int len)
{
  asn1_string_st *v4; // esi

  v4 = ASN1_STRING_type_new(a1, 4);
  if ( !v4 || !ASN1_STRING_set(v4, data, len) )
    return 0;
  ASN1_TYPE_set(a, 4, (int)v4);
  return 1;
}
