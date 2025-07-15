int __cdecl ASN1_STRING_copy(asn1_string_st *dst, const asn1_string_st *str)
{
  int result; // eax

  if ( !str )
    return 0;
  dst->type = str->type;
  result = ASN1_STRING_set(dst, (char *)str->data, str->length);
  if ( result )
  {
    dst->flags = str->flags;
    return 1;
  }
  return result;
}
