unsigned int __cdecl ASN1_TYPE_cmp(asn1_type_st *a, asn1_type_st *b)
{
  if ( !a || !b || a->type != b->type )
    return -1;
  if ( a->type == 5 )
    return 0;
  if ( a->type == 6 )
    return OBJ_cmp(a->value.object, b->value.object);
  return ASN1_STRING_cmp(a->value.asn1_string, b->value.asn1_string);
}
