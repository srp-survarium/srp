int __cdecl OTHERNAME_cmp(otherName_st *a, otherName_st *b)
{
  int result; // eax

  if ( !a || !b )
    return -1;
  result = OBJ_cmp(a->type_id, b->type_id);
  if ( !result )
    return ASN1_TYPE_cmp(a->value, b->value);
  return result;
}
