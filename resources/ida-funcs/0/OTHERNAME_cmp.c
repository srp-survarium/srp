int __cdecl OTHERNAME_cmp(otherName_st *a, otherName_st *b)
{
  int result; // eax

  if ( !a || !b )
    return -1;
  result = OBJ_cmp(a->type_id, b->type_id);
  if ( !result )
    return ASN1_TYPE_cmp((asn1_string_st *)a->value, (asn1_string_st *)b->value);
  return result;
}
