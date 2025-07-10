int __cdecl ASN1_TYPE_get(asn1_type_st *a)
{
  if ( a->value.boolean || a->type == 5 )
    return a->type;
  else
    return 0;
}
