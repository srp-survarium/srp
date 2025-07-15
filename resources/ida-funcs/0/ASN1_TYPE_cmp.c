unsigned int __cdecl ASN1_TYPE_cmp(asn1_string_st *a, asn1_string_st *b)
{
  if ( !a || !b || a->length != b->length )
    return -1;
  if ( a->length == 5 )
    return 0;
  if ( a->length == 6 )
    return OBJ_cmp((const asn1_object_st *)a->type, (const asn1_object_st *)b->type);
  return ASN1_STRING_cmp((const asn1_string_st *)a->type, (const asn1_string_st *)b->type);
}
